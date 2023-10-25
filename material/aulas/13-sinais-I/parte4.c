#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>


int main() {
    pid_t filho;

    filho = fork();
    if (filho == 0) {
        printf("Meu PID: %d\n", getpid());
        while(1);
    }

    int status;

    sleep(10);
    int wait_return = waitpid(filho, &status, WNOHANG);
    printf("wait_return: %d\n", status);
    if (wait_return == 0){
        printf("Ainda nao terminou, vou chamar o kill");
        kill(filho, SIGKILL);
        wait(&status);
    } else {
        printf("O processo filho terminou");
    }




    return 0;
}

// ctrl c -> mata o pai -> mata o filho
// kill -> mata o filho