#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    for (int i = 0; i < 8; i++) {
        pid = fork();

        if (pid == 0) {
            // Processo filho
            printf("Eu sou um processo filho, pid=%d, ppid=%d, meu id do programa é %d\n", getpid(), getppid(), i + 1);
            exit(0); // Finaliza o processo filho
        }
        // O processo pai continua executando o loop
    }

    // O processo pai só imprime sua mensagem após criar todos os filhos
    printf("Eu sou o processo pai, pid=%d, meu id do programa é %d\n", getpid(), 0);

    // Espera todos os processos filhos terminarem
    for (int i = 0; i < 8; i++) {
        wait(NULL);
    }

    return 0;
}
