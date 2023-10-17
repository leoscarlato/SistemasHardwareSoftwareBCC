/* POSIX headers */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* Standard C */
#include <stdio.h>

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
    char arq1[100]; // nomes do arquivo, recebido via scanf
    char buf[1];    // local usado para guardar os dados lidos de arq1

    // Solicita ao usuário o nome do arquivo
    scanf("%s", arq1);

    // Abre o arquivo
    int fd1 = open(arq1, O_RDONLY);
    
    if (fd1 == -1) { // Checa se o arquivo foi aberto com sucesso
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Lê e imprime todo o arquivo
    ssize_t bytesLidos;
    while ((bytesLidos = read(fd1, buf, 1)) > 0) {
        printf("%c", buf[0]);
    }

    // Fecha o arquivo
    close(fd1);

    return 0;
}
