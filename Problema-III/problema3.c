/**************************************************************************************
Autor: Juliana Aragão Pinto
Componente Curricular: Algoritmos I
Concluido em: 30/12/2017
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct ind{
    char arq[100];
    int quantidade;
    struct ind *next;
}indice;
 
typedef struct cel{
    char palavra[30];
    struct ind *indices;
    struct cel *proximo;
}celula;
 
void lista_invertida(celula **inicio_lista);
void inserir_palavra(celula **inicio_lista, char auxiliar[], char argumento[]);
void buscar_palavra(celula *inicio_lista);
celula *criar_celula();

int main(){
	
    setlocale(LC_ALL, "Portuguese");
    
    int resp;
    celula *inicio_lista;
    inicio_lista = NULL;
   
    do{
    	system("cls");
    	printf("\n**********\tMENU\t**********\n\n");
        printf("[1]\tAdicionar índice\n");
        printf("[2]\tProcurar uma palavra\n");
        printf("[0]\tFechar o programa\n\n\n");
        scanf("%d", &resp);
		fflush(stdin);
		
        switch(resp){
            case 1:
            	system("cls");
                lista_invertida(&inicio_lista);
                break;
           
            case 2:
            	system("cls");
				buscar_palavra(inicio_lista);
                break;
       
            default:
                if(resp != 0)
                    printf("Resposta incorreta!\n\n");
                break;
        }
   
    }while(resp != 0);
            
	return 0;
}

void lista_invertida(celula **inicio_lista){
    setlocale(LC_ALL, "Portuguese");
   
    char arg[50], gettings[50], palavra[50];
    FILE *file;
    printf("\n**********\tINSERINDO UM NOVO ARQUIVO DE TEXTO NO ÍNDICE\t**********\n\n");
    printf("Digite o nome do diretório e do arquivo, certificando-se de trocar o \\ por \\\\ \n");
    printf("[Exemplo: C:\\\\Users\\\\User_name\\\\Documents\\\\Arquivo_de_texto.txt]\n\n\n");
    scanf("%[^\n]s", arg);
    fflush(stdin);

    
    file = fopen(arg, "r");
   
    if(file == NULL){
        printf("O arquivo não existe. Tente novamente.\n\n");
        system("pause");
    }
   
    else{
        while(!feof(file)){	
            fscanf(file, "%s", gettings);
            strcpy(palavra, strtok(gettings, " ,.:;?![]{}()/<>\n\t""''"));
			inserir_palavra(inicio_lista, palavra, arg);
        }
    }
    fclose(file);
}

void inserir_palavra(celula **inicio_lista, char auxiliar[], char argumento[]){
    setlocale(LC_ALL, "Portuguese");
    celula *referencia, *aux;
    indice *buscar_indice, *buscar;
    int i = 0;
    
    if((*inicio_lista) == NULL){
		(*inicio_lista) = criar_celula();
		strcpy((*inicio_lista)->palavra, auxiliar);
		strcpy((*inicio_lista)->indices->arq, argumento);
		return;
	}
	
   else{
   	
	   referencia = (*inicio_lista);
	   if(referencia->proximo == NULL)
   			aux = NULL;
	   else
			aux = referencia->proximo;
	   
	   do{
	   	
		   if(strcasecmp(referencia->palavra, auxiliar) == 0){
		   	  	buscar_indice = referencia->indices;
		   	  	
		   	  	if(buscar_indice->next == NULL)
		   	  		i = 1;
		   	  	else{
					buscar = buscar_indice->next;	 
				}
				
				do{
			        if(strcmp(buscar_indice->arq, argumento) == 0){                    
			            buscar_indice->quantidade++;
			            return;
			        }
					
					if(buscar == NULL)
						i = 1;
					else{
						buscar_indice = buscar_indice->next;
						buscar = buscar_indice->next;
					}			      			        
				}while(i == 0);
				
				buscar_indice->next = (indice *)calloc(1, sizeof(indice));
				buscar_indice = buscar_indice->next;
				strcpy(buscar_indice->arq, argumento);
				buscar_indice->quantidade = 1;
				buscar_indice->next = NULL;
				return;	
		   }		
		   
				if(aux == NULL)
					i = 1;
				else{
					referencia = referencia->proximo;
					aux = referencia->proximo;
				}
				
	   }while(i == 0);        
  
   
			referencia->proximo = criar_celula();
			referencia = referencia->proximo;
			strcpy(referencia->palavra, auxiliar);
			strcpy(referencia->indices->arq, argumento); 
			return;	
	}
}

void buscar_palavra(celula *inicio_lista){
	int i;
	indice *buscar_indice;
	celula *referencia;
	referencia = inicio_lista;
	char busca[30];
	
	if(inicio_lista == NULL){
		printf("Não há argumentos.\n");
	}
	else{
		
		fflush(stdin);	
		printf("Digite a palavra que deseja buscar:  \n\n");
		gets(busca);
		fflush(stdin);		
		i = 0;
		printf("\n\n\n");
		
		while(referencia != NULL || i != 0)	{
			if(strcasecmp(busca, referencia->palavra) == 0){
				buscar_indice = referencia->indices;
				
				while(buscar_indice != NULL){
					printf("%d vezes no arquivo %s\n", buscar_indice->quantidade, buscar_indice->arq);
					buscar_indice = buscar_indice->next;
				}
				i = 1;
				system("pause");
				return;
			}
			referencia = referencia->proximo;
		}
		if(i == 0)
			printf("Esta palavra não foi encontrada nos textos.\n\n");	
	}
	system("pause");
}

celula *criar_celula(){
    celula *p;
   
    p = (celula *)calloc(1, sizeof(celula));
    p->proximo = NULL;
    p->indices = (indice *)calloc(1, sizeof(indice));
    p->indices->quantidade = 1;
    p->indices->next = NULL;
   
    return p;
}
