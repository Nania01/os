#ifndef PROCESS_RUNNER_H
#define PROCESS_RUNNER_H

bool run_process(const char* command, bool wait_for_completion, int* exit_code);

#endif