#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */


/*
    Funcao que lê sobre cada linha o ultimo numero
*/
int getLastNumber(char* l){ //l é a linha recebida

    int numero;
    char delim[] = " "; //separar por espaços
    char res[50];

    //Esta funcao guarda em ptr cada pedaços
    char *ptr = strtok(l, delim);
     while(ptr != NULL){ //quando termina a linha
       strcpy(res,ptr); //guardo o pedaço encontrado
		ptr = strtok(NULL, delim);   //procurar o proximo pedaço, é tipo num while fazer i++
  
    }

    //no fim, devolvo o numero caso o encontre, caso contrario devolvo -1
    if((numero = atoi(res)) != 0)
        return numero;
    else
    {
        return(-1);
    }
 
    return 0;
}



int main(){

    int numeros[10];
    int indexn = 0;

	int fd = open("input.txt", O_RDONLY); //abre o ficheiro

	int n; 	
    //se correu mal ao abrir o ficheiro					      
	if (fd==-1){
		perror("Can't open file");
		close(fd);
		return 1; /*EXIT_FAILURE*/
	}
    //se correu bem abrir o ficheiro
    else{
        printf("Abriu o ficheiro com sucesso\n");
    }
	char c;
    int i=0;
    char aux[1024];
    int res;
    //vou ler caracter a caracter
	while((n=read(fd,&c,1))>0){
            aux[i++]=c; //vou guardando os caracteres da linha

            if(c=='\n'){    //quando chegar ao fim da linha
                aux[i]='\0';
                res=getLastNumber(aux); //vou procurar o numero na linha
                //caso o numero é valido, guardo num array
                if(res!= -1)
                    numeros[indexn++]=res;
                i=0;
            }

    }
    //no array numeros, tenho todos os numeros lidos do ficheiro, aqui vou imprimir.
    for(int j=0; j<indexn;j++)
        printf("%d\n",numeros[j]);

	return 0;
}