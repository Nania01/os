#include <iostream>
#include "process_runner.h"

int main() {
    std::cout << "--- Test utility started ---" << std::endl;
    int exit_code = 0;

    #ifdef _WIN32
        const char* cmd = "ping 127.0.0.1 -n 3";
    #else
        const char* cmd = "ping -c 3 127.0.0.1";
    #endif

    std::cout << "Starting background process..." << std::endl;
    
    bool success = run_process(cmd, true, &exit_code);

    if (success) {
        std::cout << "Child process completed successfully!" << std::endl;
        std::cout << "Exit code: " << exit_code << std::endl;
    } else {
        std::cout << "Critical error: Failed to start process." << std::endl;
    }
    
    return 0;
}