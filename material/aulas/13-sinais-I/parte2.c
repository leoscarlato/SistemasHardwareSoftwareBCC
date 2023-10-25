#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main() {
    pid_t filho;

    filho = fork();
    if (filho == 0) {
        printf("Meu PID: %d\n", getpid());
        while(1);
    }

    int status;
    int x = wait(&status);
    printf("PID: %d\n", x);


    printf("EXITED %d \n"
            "SIGNALED %d \n"
            "TERMSIG %d \n"
            "Error: %s\n",
            WIFEXITED(status),
            WIFSIGNALED(status),
            WTERMSIG(status),
            strsignal(WTERMSIG(status))
    );

    return 0;
}

// ctrl c -> mata o pai -> mata o filho
// kill -> mata o filho