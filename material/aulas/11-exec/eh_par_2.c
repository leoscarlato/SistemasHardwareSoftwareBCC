#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

    while(1){

        int num;
        printf("Digite um número: ");
        scanf("%d", &num);

        char num_str[50];
        sprintf(num_str, "%d", num);

        pid_t pid = fork();

        if (pid == 0){ // processo filho
            char *cmd[] = {"./eh_par", num_str, NULL};
            execvp("./eh_par", cmd);
            perror("execvp");
            exit(1);
        }
        else if (pid > 0){
            int status;
            wait(&status);

            if (WIFEXITED(status)){
                int resultado = WEXITSTATUS(status);

                if (resultado == 1){
                    printf("%d é par\n", num);
                } else if(resultado == 0){
                    printf("%d não é par\n", num);
                } else if(resultado == 255){
                    printf("Encerrando o programa\n");
                    break;
                }
            }
        } else {
            perror("fork");
            exit(1);
        }
    }

    return 0;

}