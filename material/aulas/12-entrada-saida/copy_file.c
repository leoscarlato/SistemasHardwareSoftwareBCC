/* POSIX headers */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* Standard C */
#include <stdio.h>

int main(int argc, char *argv[]){
    char arq1[100];
    char arq2[100];
    char buf[1];

    printf("Nome do primeiro arquivo: ");
    scanf("%s", arq1);

    printf("Nome do segundo arquivo: ");
    scanf("%s", arq2);

    int fd1 = open(arq1, O_RDONLY);
    int fd2 = open(arq2, O_WRONLY | O_CREAT, 0700);

    ssize_t bytesLidos;
    while ((bytesLidos = read(fd1, buf, 1)) > 0){
        write(fd2, buf, 1);
    }

    close(fd1);
    close(fd2);

    return 0;


}