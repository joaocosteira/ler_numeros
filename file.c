#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */


int getLastNumber(char* l){ //l é a linha recebida
    int numero;
    char delim[] = " "; //separar por espaços
    char res[50]; //cada palavra lida tem de ter no maximo 50 caracteres

    
    char *ptr = strtok(l, delim); //buscar primeira palavra da linha

    while(ptr != NULL){ //Enquando a linha nao termina
        strcpy(res,ptr); //guardo a palavra atual da linha
	    ptr = strtok(NULL, delim);   //procurar a proxima palavra, é tipo num while fazer i++
  
    }

    //no fim, devolvo o numero caso o encontre, caso contrario devolvo -1
    if((numero = atoi(res)) != 0)
        return numero;
    else
        return -1 ;
}



int main(){

    int numeros[10]; //pode guardar 10 numeros no maximo
    int indexn = 0; //index do array numeros
    char c; //cada letra da linha

    //index e onde guardamos cada linha lida -> está definido pra linha de 1024 caracteres, podes meter + pequeno
    int i=0; 
    char aux[1024];

    int res; //onde guarda cada numero lido temporariamente

    int fd = open("input.txt", O_RDONLY); //abre o ficheiro	
    
    //Termina a execução caso nao haja o ficheiro				      
	if (fd==-1){
		perror("Can't open file");
		close(fd);
		return 1;
	}
    //se correu bem abrir o ficheiro -> printf ou write
    else{
        printf("Abriu o ficheiro com sucesso\n");
    }
    //vou ler caracter a caracter
	while(read(fd,&c,1)>0){
            aux[i++]=c; //vou guardando os caracteres da linha
            if(c=='\n'){    //quando chegar ao fim da linha
                aux[i]='\0'; //Fim de linha
                res=getLastNumber(aux); //vou procurar o numero na linha
                //caso o numero é valido, guardo num array
                if(res!= -1)
                    numeros[indexn++]=res;
                i=0; //reset da linha
            }

    }
    close(fd); //IMPORTANTE: Fechar o ficheiro

    for(int j=0; j<indexn;j++) //imprimir os numeros
        printf("%d\n",numeros[j]);

	return 0;
}