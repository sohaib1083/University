#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>


int main() {
    char command[100];

    printf("Enter the shell command: ");
    fgets(command, 100, stdin);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } 
    else if (pid == 0) 
    {
        
        int status = execl("/bin/sh", "sh", "-c", command, NULL);
        
    } 
    else 
    {
        wait(NULL);

    }

    return 0;
}

