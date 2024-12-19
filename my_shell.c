#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

// Function to handle the command execution
void execute_command(char *command) {
    pid_t pid = fork();  // Create a child process

    if (pid == -1) {  // Error in fork
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {  // Child process
        // Execute the command using execve
        char *args[] = {command, NULL};
        if (execve(command, args, NULL) == -1) {
            perror(command);  // If execve fails, print the error
            exit(1);
        }
    } else {  // Parent process
        int status;
        waitpid(pid, &status, 0);  // Wait for child process to finish
    }
}

int main() {
    char command[MAX_CMD_LEN];
    
    while (1) {
        // Display the prompt
        printf("$ ");
        
        // Read a command from the user
        if (fgets(command, MAX_CMD_LEN, stdin) == NULL) {
            // Handle end of file (Ctrl+D)
            if (feof(stdin)) {
                printf("\n");
                exit(0);
            } else {
                perror("fgets failed");
                exit(1);
            }
        }

        // Remove the newline character from the command
        command[strcspn(command, "\n")] = '\0';
        
        if (command[0] != '\0') {  // Skip empty lines
            execute_command(command);  // Execute the command
        }
    }

    return 0;
}
