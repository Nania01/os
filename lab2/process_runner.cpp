#include "process_runner.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
    #include <sys/wait.h>
#endif

bool run_process(const char* command, bool wait_for_completion, int* exit_code) {
#ifdef _WIN32
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    char* cmd = strdup(command); 
    
    if (!CreateProcessA(NULL, cmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        free(cmd);
        return false;
    }
    free(cmd);

    if (wait_for_completion) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        if (exit_code != nullptr) {
            DWORD code;
            GetExitCodeProcess(pi.hProcess, &code);
            *exit_code = code;
        }
    }
    
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return true;

#else
    pid_t pid = fork();
    
    if (pid < 0) return false;
    
    if (pid == 0) {
        execl("/bin/sh", "sh", "-c", command, nullptr);
        exit(127);
    } else {
        if (wait_for_completion) {
            int status;
            waitpid(pid, &status, 0);
            if (exit_code != nullptr) {
                if (WIFEXITED(status)) {
                    *exit_code = WEXITSTATUS(status);
                } else {
                    *exit_code = -1;
                }
            }
        }
        return true;
    }
#endif
}