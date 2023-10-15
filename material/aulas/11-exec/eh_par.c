#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    long num = atol(argv[1]); //argv[1] -> posição do numero que está sendo passado p verificar se é par ou n

    if (num < 0){
        return -1;
    } else if (num % 2 == 0){
        return 1;
    } else{
        return 0;
    }
}