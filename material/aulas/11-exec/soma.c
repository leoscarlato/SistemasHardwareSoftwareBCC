#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    if (argc < 2){
        printf("Tem que ter pelo menos 2 argumentos");
        return 1;
    }

    int soma = 0;

    for (int i = 0; i < argc; i++){
        char *arg = argv[i];
        double num = atof(arg);
        soma += num;
    }

    printf("A soma dos argumentos é: %d", soma);

    return 0;

}