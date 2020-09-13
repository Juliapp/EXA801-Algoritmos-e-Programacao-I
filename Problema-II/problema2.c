/*******************************************************************************
Autor: Juliana Arag�o Pinto
Componente Curricular: Algoritmos I
Concluido em: 28/11/2017
Declaro que este c�digo foi elaborado por mim de forma individual e n�o cont�m nenhum
trecho de c�digo de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e p�ginas ou documentos eletr�nicos da Internet. Qualquer trecho de c�digo
de outra autoria que n�o a minha est� destacado com uma cita��o para o autor e a fonte
do c�digo, e estou ciente que estes trechos n�o ser�o considerados para fins de avalia��o.
******************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*	Bibliotecas utilizadas:
stdio.h - Entrada e sa�da de dados
stdlib.h - Aloca��o de mem�ria e controle de processsos
locale.h - Biblioteca de caracteres com acentua��es
string.h - Manipula��o de strings.*/

/*	Primeiramente, defini 2 structs que se juntavam em uma terceira para facilitar a entrada
de dados. S2 (struct 2) faz o cadastro dos proponentes de cada atividade e diferencia se 
cada um � aluno ou professor. S1 (struct 1) Faz o cadastro de uma proposta, contendo nela 
o t�tulo da proposta, o dia em que ocorrer� (Dia 23/10 ou 24/10), o hor�rio da proposta,
seu tipo, a quantidade de proponentes, e dentro dela, ainda h� uma struct do tipo S2 que 
ser� um vetor conforme a quantidade de proponentes.	*/

typedef struct {
    char person[30];
    int Aluprof;
}S2;

typedef struct {
    char tit[30];
    int day;
    int time;
    int kind;
    int Qprop;
    S2 CAD2[5];
}S1;

/*A struct S1 � unida a struct CAD, e nela ser� definida qual o nome do curso e quantas 
propostas ser�o realizadas.*/

typedef struct {
    char nome[30];
    int Q;
    S1 CAD1[10];
}CAD;



/*Ainda antes da main, esta � a declara��o de todas as fun��es que ir�o ser utilizadas 
no c�digo. Elas ser�o explicadas uma a uma no decorrer dele*/

void cadastro(CAD *curso, int o, int *, int *, int *, int *, int *, int *, int *, int *);
void nome_cursos(CAD *curso, int i);
void quantidade_propostas(CAD *curso, int o);
void continuar(CAD *curso, int i, int j);
void checar_horario(CAD *curso, int i, int j);
void auxcheck(int a);
void atividade(CAD *curso, int i, int j);
void dia(CAD *curso, int i, int j);
void hora(CAD *curso, int i, int j);
void auxcheck2(CAD *curso, int i, int n, int h);
int check(CAD *curso, int i, int j, int c);
void tipo(CAD *curso, int i, int j, int *or1, int *or2, int *of1, int *of2, int *p1, int *p2, int *lab1, int *lab2);
void quantidade_proponentes(CAD *curso, int i, int j);
void proponentes(CAD *curso, int i, int j, int k);
void alunouprofe(CAD *curso, int i, int j, int k);
void arquivo_de_texto(CAD *curso, int o);
void arquivo_de_texto2(CAD *curso, int o, int or1, int or2, int of1, int of2, int p1, int p2, int lab1, int lab2);
void ordenacao_horario(CAD *curso, int o);
void ordenacao_curso(CAD *curso, int o);




int main (){
    setlocale(LC_ALL, "Portuguese");
    
    int o;	//A vari�vel 'o' cria um vetor de cadastros conforme o usu�rio digitar.

    
    int or1 = 0, or2 = 0, of1 = 0, of2 = 0, p1 = 0, p2 = 0, lab1 = 0, lab2 = 0; //Esses cotadores coletar os dados que s�o pedidos no problema
    
    
    
	printf("****Cadastro da Feira de Gradula��o****\n\n\n");
    printf("Digite a quantidade de cursos que ir�o ser cadastrados\n");
    scanf("%d", &o);
    fflush(stdin);
    CAD curso[o];	//vetor de structs de cadastro
	
	cadastro(curso, o, &or1, &or2, &of1, &of2, &p1, &p2, &lab1, &lab2);	//chamada para primeira fun��o para o cadastro

	ordenacao_curso(curso, o); //Ap�s o cadastro n�s temos duas ordena��o, a primeira por ordem alfabetica
	
	ordenacao_horario(curso, o); //E a segunda para os hor�rios das propostas
	
	arquivo_de_texto(curso, o); //Cria��o do arquivo de texto com toda a programa��o
	
	arquivo_de_texto2(curso, o, or1, or2, of1, of2, p1, p2, lab1, lab2); //Cria��o do arquivo de texto com relat�rio
	
	printf("\n\nOutro arquivo de texto com o nome ""Relat�rio final da feira de gradua��o da UEFS.txt"" foi criado para mostrar o relat�rio final.\n\n");
	
    return 0;
}

void cadastro(CAD *curso, int o, int *or1, int *or2, int *of1, int *of2, int *p1, int *p2, int *lab1, int *lab2){
	setlocale(LC_ALL, "Portuguese");
	
	/*As fun��es tem em comum a passagem por referencia do curso e a passagem por valor das 
	vari�veis de referencia para o local do espa�o da struct*/
	
	/*	Essa fun��o � respons�vel pelo cadastro de cada curso, iniciando pelo seu nome, e um
	la�o for para cada curso que desejar ser cadastrado, e perguntando qual a quantidade de 
	propostas o usu�rio quer cadastrar. Com esse valor � definido outro la�o for para as 
	propostas e mais outro para os proponentes e sua diferencia��o */
	
	/*Nessa fun��o, dentro de cada la�o, o cadastro foi dividido em uma fun��o para cada pergunta
	feita. */
    
    int i, j, k, resp; //contadores

	for(i = 0; i < o; i ++){
    	system("cls");
    	
    	do{
    		printf("[1] - Continuar cadastro\n");
			printf("[2] - Checar nome dos cursos cadastrados\n\n\n");
			scanf("%d", &resp);
		    fflush(stdin);			
			
			if(resp == 2)
				nome_cursos(curso, i);
			
			else if(resp != 1 && resp !=2){
				system("cls");
			    printf("Valor incorreto. Por favor, Digite novamente\n\n");
				system("pause");
			}
    		
    	}while(resp != 1 && resp != 2);
    	
    	system("cls");
		printf("Digite o nome do %d� curso\n\n\n", i+1);
	    gets(curso[i].nome); //Defini��o do nome do curso, para cada posi��o do vetor
	    fflush(stdin);
		
	    quantidade_propostas(curso, i); //Quantidade de propostas que cada curso vai ofertar
	    
	    for(j = 0; j < curso[i].Q; j++){
	    	
			continuar(curso, i, j);
			
			atividade(curso, i, j); //Nome da atividade 
				
			dia(curso, i, j); //data da atividade
			
			hora(curso, i, j); //hora da atividade
			
			tipo(curso, i, j, or1, or2, of1, of2, p1, p2, lab1, lab2); //tipo da atividade (com contadores)
			
			quantidade_proponentes(curso, i, j); //Quantidade de proponentes que cada proposta vai ter
			
			for(k = 0; k < curso[i].CAD1[j].Qprop; k++){
				proponentes(curso, i, j, k); //Nome do proponente
				
				alunouprofe(curso, i, j, k); // distin��o ente professor e aluno
			}
		}
	}
}
void nome_cursos(CAD *curso, int i){ //Esta fun��o printa o nome de todos os cursos que j� foram cadastrados
	int j;
	if(i == 0)
		printf("Nenum curso cadastrado");
	
	else if(i > 0)		
		for(j = 0; j < i; j++){
			puts(curso[j].nome);
		}
		
	system("pause");
}


void quantidade_propostas(CAD *curso, int i){
	setlocale(LC_ALL, "Portuguese");
	
	 do{
	    	system("cls");
		    printf("Quantas atividades o curso %s vai oferecer?\n", curso[i].nome);
		    printf("[M�ximo 10 atividades]\n\n\n");
		    scanf("%d", &curso[i].Q);
		    fflush(stdin);
		    
			if(curso[i].Q > 10 || curso[i].Q <= 0){
		    	system("cls");
			    printf("Valor incorreto. Por favor, insira um valor positivo acima de 0 e menor ou igual a 10\n\n");
				system("pause");
			}
			
	}while(curso[i].Q > 10 || curso[i].Q <= 0);
}

void continuar(CAD *curso, int i, int j){
	setlocale(LC_ALL, "Portuguese");
	int n;
		do{
				system("cls");
			    printf("[1] - Continuar cadastro\n");
			    printf("[2] - Checar horarios j� utilizados por esse curso\n\n\n");
			    scanf("%d", &n);
			    fflush(stdin);
			    
    			if(n == 2){
    				system("cls");
					checar_horario(curso, i, j);
			 		system("pause");
				}
				else if(n != 1 && n!= 2){
					system("cls");
					printf("\n\nEntrada inv�lida. Por favor, responda corretamete\n\n\n");
					system("pause");
				}
			    
		}while(n != 1 && n!= 2);

}


void checar_horario(CAD *curso, int i, int j){ 
	
	//Essa fun��o permite o usu�rio checar quais os hor�rios j� foram usados nas propostas daquele curso
	
	int n, h;
	setlocale(LC_ALL, "Portuguese");
	
	// Para a primeira proposta, ele informa que todos os hor�rios est�o livres
	if(j == 0){
	 	printf("Todos os hor�rios est�o disponiveis\n\n");
	}				    	
	
	//Ap�s a primeira, ele varre v�rias vezes o vetor procurando por cada hor�rio
	else if(j > 0){
		
		printf("Para o dia 23/10:\n\n");

		for(n = 0; n < j; n++){
			for(h = 0; h <= 12; h++){
				if(curso[i].CAD1[n].day == 1)
					auxcheck2(curso, i, n, h);
			}
		}
		
		printf("\n\n\nPara o dia 24/10:\n\n");

		for(n = 0; n < j; n++){
			for(h = 0; h <= 12; h++){
				if(curso[i].CAD1[n].day == 2)
					auxcheck2(curso, i, n, h);
			}
		}
	}

}

//Fun��o para varrer o vetor
void auxcheck2(CAD *curso, int i, int n, int h){
int a;

	if(curso[i].CAD1[n].time == h){
		a = h;
		auxcheck(a);
	}
	
}

//fun��o para imprimir os hor�rios j� cadastrados 
void auxcheck(int a){
	setlocale(LC_ALL, "Portuguese");
	
			   	if (a == 1)
					printf("De 8:00 �s 9:00\n");
					
				else if (a == 2)	
					printf("De 9:00 �s 10:00\n");
				
				else if (a == 3)
					printf("De 10:00 �s 11:00\n");
				
				else if (a == 4)	
					printf("De 11:00 �s 12:00\n");
					
				else if (a == 5)
					printf("De 12:00 �s 13:00\n");
					
				else if (a == 6)
					printf("De 13:00 �s 14:00\n");
				
				else if (a == 7)
					printf("De 14:00 �s 15:00\n");
					
				else if (a == 8)
					printf("De 15:00 �s 16:00\n");
					
				else if (a == 9)
					printf("De 16:00 �s 17:00\n");
					
				else if (a == 10)
					printf("De 17:00 �s 18:00\n");
					
				else if (a == 11)
					printf("De 18:00 �s 19:00\n");
					
				else if (a == 12)
					printf("De 19:00 �s 20:00\n");
}


void atividade(CAD *curso, int i, int j){
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	printf("Digite o t�tulo %d� atividade oferecida\n\n\n", j+1);
	gets(curso[i].CAD1[j].tit);
	fflush(stdin);
}

void dia(CAD *curso, int i, int j){
	setlocale(LC_ALL, "Portuguese");
	do{
		
		system("cls");
		printf("Selecione dia da atividade:\n\n\n");
		printf("[1] - Dia 23/10\n");
		printf("[2] - Dia 24/10\n");
		scanf("%d", &curso[i].CAD1[j].day);
		fflush(stdin);
		
		if(curso[i].CAD1[j].day != 1 && curso[i].CAD1[j].day != 2){
			system("cls");
			printf("Data inv�lida. Por favor, selecione uma das op��es\n\n\n\n");
			system("pause");
		}
	
	}while(curso[i].CAD1[j].day != 1 && curso[i].CAD1[j].day != 2);
}
	
void hora(CAD *curso, int i, int j){
	setlocale(LC_ALL, "Portuguese");
	int c, m;
		
	do{	
		system("cls");
		printf("Selecione o hor�rio da atividade:\n\n\n");
		printf("[1] - De 8:00 �s 9:00\n");
		printf("[2] - De 9:00 �s 10:00\n");
		printf("[3] - De 10:00 �s 11:00\n");
		printf("[4] - De 11:00 �s 12:00\n");
		printf("[5] - De 12:00 �s 13:00\n");
		printf("[6] - De 13:00 �s 14:00\n");
		printf("[7] - De 14:00 �s 15:00\n");
		printf("[8] - De 15:00 �s 16:00\n");
		printf("[9] - De 16:00 �s 17:00\n");
		printf("[10] - De 17:00 �s 18:00\n");
		printf("[11] - De 18:00 �s 19:00\n");
		printf("[12] - De 19:00 �s 20:00\n");
		scanf("%d", &c);
		fflush(stdin);
		
		m = check(curso, i, j, c);
		
		if (m == 0){
			curso[i].CAD1[j].time = c;
		}
		else if(m >= 1){
			system("cls");
			printf("O hor�rio que voc� selecionou j� esta sendo utilizando em outra atividade deste curso.\n\n");
			printf("Os hor�rios j� cadastrados s�o:\n")	;
			checar_horario(curso, i, j);
			printf("\n\nSelecione novamente\n\n\n");
			system("pause");
		}
		
	}while(curso[i].CAD1[j].time != c);
}

int check(CAD *curso, int i, int j, int c){
	
	int n;
	int x = 0;
	
	for(n = 0; n < j; n++){
		if(curso[i].CAD1[j].day == curso[i].CAD1[n].day && curso[i].CAD1[n].time == c)
		x++;
	}
	
	return x;
}

void tipo(CAD *curso, int i, int j, int *or1, int *or2, int *of1, int *of2, int *p1, int *p2, int *lab1, int *lab2){
	setlocale(LC_ALL, "Portuguese");
	do{
	   	system("cls");
		printf("Qual o tipo desta apresenta��o?\n\n\n");
		printf("[1] - Oral\n");
		printf("[2] - Oficina\n");
		printf("[3] - Poster\n");
		printf("[4] - Laborat�rio\n\n");
		scanf("%d", &curso[i].CAD1[j].kind);
		fflush(stdin);

		if(curso[i].CAD1[j].kind == 1){
			if(curso[i].CAD1[j].day == 1)
				(*or1)++;
			else
				(*or2)++;
		}
		else if(curso[i].CAD1[j].kind == 2){
			if(curso[i].CAD1[j].day == 1)
				(*of1)++;
			else
				(*of2)++;
		}
		else if(curso[i].CAD1[j].kind == 3){
			if(curso[i].CAD1[j].day == 1)
				(*p1)++;
			else
				(*p2)++;
		}
		else if(curso[i].CAD1[j].kind == 4){
			if(curso[i].CAD1[j].day == 1)
				(*lab1)++;
			else
				(*lab2)++;
		}		

		
		
	if(curso[i].CAD1[j].kind != 1 && curso[i].CAD1[j].kind != 2 && curso[i].CAD1[j].kind != 3 && curso[i].CAD1[j].kind != 4){
		system("cls");
		printf("Entrada inv�lida. Por favor, selecione uma das op��es\n\n\n\n");
		system("pause");
		}
		
	}while(curso[i].CAD1[j].kind != 1 && curso[i].CAD1[j].kind != 2 && curso[i].CAD1[j].kind != 3 && curso[i].CAD1[j].kind != 4 );
}

void quantidade_proponentes(CAD *curso, int i, int j){
	setlocale(LC_ALL, "Portuguese");
	
	do{
		system("cls");
		printf("Quantos proponentes essa atividade vai ter?\n");
	    printf("Voc� pode cadastrar no m�ximo 5 pessoas\n\n\n"); 
		scanf("%d", &curso[i].CAD1[j].Qprop);
		fflush(stdin);
		
	if(curso[i].CAD1[j].Qprop < 0 && curso[i].CAD1[j].Qprop > 5){
		system("cls");
		printf("Entrada inv�lida. Por favor, selecione uma das op��es\n\n\n\n");
		system("pause");
		}		
		
	}while(curso[i].CAD1[j].Qprop < 0 && curso[i].CAD1[j].Qprop > 6);
}
				    
void proponentes(CAD *curso, int i, int j, int k){
	setlocale(LC_ALL, "Portuguese");
	
	fflush(stdin);
	system("cls");
	printf("Qual o nome do(a) %d� proponente\n\n\n", k+1);
	gets(curso[i].CAD1[j].CAD2[k].person);
	fflush(stdin);					
				
}

void alunouprofe(CAD *curso, int i, int j, int k){
	setlocale(LC_ALL, "Portuguese");
	do{	
		system("cls");			
		printf("Esse proponente �:\n\n");
		printf("[1] - Estudante\n");
		printf("[2] - Professor\n\n");
		scanf("%d", &curso[i].CAD1[j].CAD2[k].Aluprof);
		fflush(stdin);
		
		if(curso[i].CAD1[j].CAD2[k].Aluprof != 1 && curso[i].CAD1[j].CAD2[k].Aluprof != 2){
			system("cls");
			printf("Entrada inv�lida. Por favor, selecione uma das op��es\n\n\n\n");
			system("pause");
		}
			
	}while(curso[i].CAD1[j].CAD2[k].Aluprof != 1 && curso[i].CAD1[j].CAD2[k].Aluprof != 2);
}

void arquivo_de_texto(CAD *curso, int o){
	setlocale(LC_ALL, "Portuguese");
	
	int i, j, k;
	char nome_arq[30];
	
	FILE *parquivo;
	
	system("cls");
	printf("Como deseja chamar seu arquivo de texto?\n\n");
	gets(nome_arq);
	fflush(stdin);
	
	strcat(nome_arq, ".txt");		//contatenando o nome do arquivo com o final .txt
	
	parquivo = fopen(nome_arq, "w");
	
	for(i = 0; i < o; i ++){
		
    	fprintf(parquivo, "%s\n", curso[i].nome);
    	
	    
	    for(j = 0; j < curso[i].Q; j++){
	    	   		
			fprintf(parquivo, "\t\t%s\n\n", curso[i].CAD1[j].tit);
			
			fprintf(parquivo, "\t\tData:");
			
			if(curso[i].CAD1[j].day == 1)
				fprintf(parquivo, "\t\t23/10\n");
			
			else if(curso[i].CAD1[j].day == 2)
				fprintf(parquivo, "\t\t24/10\n");
							
			fprintf(parquivo, "\t\tHor�rio:");
			
			if(curso[i].CAD1[j].time == 1)
				fprintf(parquivo, "\t8:00 - 9:00\n");
			
			else if(curso[i].CAD1[j].time == 2)
				fprintf(parquivo, "\t9:00 - 10:00\n");
			
			else if(curso[i].CAD1[j].time == 3)
				fprintf(parquivo, "\t10:00 - 11:00\n");
			
			else if(curso[i].CAD1[j].time == 4)
			   	fprintf(parquivo, "\t11:00 - 12:00\n");
			
			else if(curso[i].CAD1[j].time == 5)
				fprintf(parquivo, "\t12:00 - 13:00\n");
			
			else if(curso[i].CAD1[j].time == 6)
				fprintf(parquivo, "\t13:00 - 14:00\n");
			
			else if(curso[i].CAD1[j].time == 7)
				fprintf(parquivo, "\t14:00 - 15:00\n");
			
			else if(curso[i].CAD1[j].time == 8)
				fprintf(parquivo, "\t15:00 - 16:00\n");
			
			else if(curso[i].CAD1[j].time == 9)
			   	fprintf(parquivo, "\t16:00 - 17:00\n");
			
			else if(curso[i].CAD1[j].time == 10)
				fprintf(parquivo, "\t17:00 - 18:00\n");
			
			else if(curso[i].CAD1[j].time == 11)
				fprintf(parquivo, "\t18:00 - 19:00\n");
			
			else if(curso[i].CAD1[j].time == 12)
				fprintf(parquivo, "\t19:00 - 20:00\n");
			
			fprintf(parquivo, "\t\tTipo:");
			
			if(curso[i].CAD1[j].kind == 1)
				fprintf(parquivo, "\t\tOral\n");
			
			else if(curso[i].CAD1[j].kind == 2)
				fprintf(parquivo, "\t\tOficina\n");
			
			else if(curso[i].CAD1[j].kind == 3)
				fprintf(parquivo, "\t\tPoster\n");
			
			else if(curso[i].CAD1[j].kind == 4)
			   	fprintf(parquivo, "\t\tLaborat�rio\n");
			
			
			fprintf(parquivo, "\t\tProponente(s):");
			
			for(k = 0; k < curso[i].CAD1[j].Qprop; k++){
				fprintf(parquivo,"\n\t\t\t\t%s", curso[i].CAD1[j].CAD2[k].person);
				
				if(curso[i].CAD1[j].CAD2[k].Aluprof == 1)
				   	fprintf(parquivo, " (Aluno)");
			
				else if(curso[i].CAD1[j].CAD2[k].Aluprof == 2)
				  		fprintf(parquivo, " (Professor)");
				
				}
				
				fprintf(parquivo, "\n\t\t________________________________________\n");
			}
			fprintf(parquivo, "________________________________________________________\n");
		}
	
	
	
	fclose(parquivo);
		
	   	
	system("pause");
}

void arquivo_de_texto2(CAD *curso, int o,int or1, int or2, int of1, int of2, int p1, int p2, int lab1, int lab2){
	
	setlocale(LC_ALL, "Portuguese");
	
	int i, j, k, Maxr = 0, Minr = 0, c = 0;
	
	FILE *parquivo2;
	
	parquivo2 = fopen("Relat�rio final da feira de gradua��o da UEFS.txt", "w");
	fprintf(parquivo2, "Quantidade de atividades ordeadas por tipo\n\n\t\tDia 23/10\n");
	fprintf(parquivo2, "Oral: %d atividade(s).\n", or1);
	fprintf(parquivo2, "Oficina: %d atividade(s).\n", of1);
	fprintf(parquivo2, "Laborat�rio: %d atividade(s).\n", lab1);
	fprintf(parquivo2, "P�ster: %d atividade(s).\n", p1);
	
	fprintf(parquivo2, "\n\n\t\tDia 24/10\n");
	fprintf(parquivo2, "Oral: %d atividade(s).\n", or2);
	fprintf(parquivo2, "Oficina: %d atividade(s).\n", of2);
	fprintf(parquivo2, "Laborat�rio: %d atividade(s).\n", lab2);
	fprintf(parquivo2, "P�ster: %d atividade(s).\n\n\n\n", p2);
	
	
	
	for(i = 0; i < o; i++){
		
		if(curso[i].Q > curso[Maxr].Q)
			Maxr = i;
		else if(curso[i].Q < curso[Minr].Q)
			Minr = i;
		
	}
	
fprintf(parquivo2, "Cursos com maiores represetativas:\n\n");
	
	for(i = 0; i < o; i++){
		
		if(curso[i].Q == curso[Maxr].Q)
	   	fprintf(parquivo2, "%s\n", curso[i].nome);
		
	}	

fprintf(parquivo2, "\n\nCursos com menores represetativas:\n\n");		
	for(i = 0; i < o; i++){
		
		if(curso[i].Q == curso[Minr].Q)
	   	fprintf(parquivo2, "%s\n", curso[i].nome);
		
	}	
	
	fprintf(parquivo2, "\n\n\n\nPrograma��o feita s� por estudantes\n\n");
	
	
	for(i = 0; i < o; i++){
		for(j = 0; j < curso[i].Q; j++){
			
			c = 0;
			
			for(k = 0; k < curso[i].CAD1[j].Qprop; k++){
				if(curso[i].CAD1[j].CAD2[k].Aluprof == 1)
				c++;	
	   	   	}
			
			if(curso[i].CAD1[j].Qprop == c)	{
				
				fprintf(parquivo2, "%s\n", curso[i].nome);
					
				fprintf(parquivo2, "\t\t%s\n\n", curso[i].CAD1[j].tit);
				
				fprintf(parquivo2, "\t\tData:");
				
				if(curso[i].CAD1[j].day == 1)
					fprintf(parquivo2, "\t\t23/10\n");
				
				else if(curso[i].CAD1[j].day == 2)
					fprintf(parquivo2, "\t\t24/10\n");
								
				fprintf(parquivo2, "\t\tHor�rio:");
				
				if(curso[i].CAD1[j].time == 1)
					fprintf(parquivo2, "\t8:00 - 9:00\n");
				
				else if(curso[i].CAD1[j].time == 2)
					fprintf(parquivo2, "\t9:00 - 10:00\n");
				
				else if(curso[i].CAD1[j].time == 3)
					fprintf(parquivo2, "\t10:00 - 11:00\n");
				
				else if(curso[i].CAD1[j].time == 4)
				   	fprintf(parquivo2, "\t11:00 - 12:00\n");
				
				else if(curso[i].CAD1[j].time == 5)
					fprintf(parquivo2, "\t12:00 - 13:00\n");
				
				else if(curso[i].CAD1[j].time == 6)
					fprintf(parquivo2, "\t13:00 - 14:00\n");
				
				else if(curso[i].CAD1[j].time == 7)
					fprintf(parquivo2, "\t14:00 - 15:00\n");
				
				else if(curso[i].CAD1[j].time == 8)
					fprintf(parquivo2, "\t15:00 - 16:00\n");
				
				else if(curso[i].CAD1[j].time == 9)
				   	fprintf(parquivo2, "\t16:00 - 17:00\n");
				
				else if(curso[i].CAD1[j].time == 10)
					fprintf(parquivo2, "\t17:00 - 18:00\n");
				
				else if(curso[i].CAD1[j].time == 11)
					fprintf(parquivo2, "\t18:00 - 19:00\n");
				
				else if(curso[i].CAD1[j].time == 12)
					fprintf(parquivo2, "\t19:00 - 20:00\n");
				
				fprintf(parquivo2, "\t\tTipo:");
				
				if(curso[i].CAD1[j].kind == 1)
					fprintf(parquivo2, "\t\tOral\n");
				
				else if(curso[i].CAD1[j].kind == 2)
					fprintf(parquivo2, "\t\tOficina\n");
				
				else if(curso[i].CAD1[j].kind == 3)
					fprintf(parquivo2, "\t\tPoster\n");
				
				else if(curso[i].CAD1[j].kind == 4)
				   	fprintf(parquivo2, "\t\tLaborat�rio\n");
				
				
				fprintf(parquivo2, "\t\tProponente(s):");
				
				for(k = 0; k < curso[i].CAD1[j].Qprop; k++){
					fprintf(parquivo2,"\n\t\t\t\t%s", curso[i].CAD1[j].CAD2[k].person);
					
					if(curso[i].CAD1[j].CAD2[k].Aluprof == 1)
					   	fprintf(parquivo2, " (Aluno)");
				
					}
					
					fprintf(parquivo2, "\n\t\t________________________________________\n");
				}
				fprintf(parquivo2, "________________________________________________________\n");
				
			}
						
		}		
		

	fclose(parquivo2);
}


void ordenacao_horario(CAD *curso, int o){
	int i, j, j2;
	S1 aux;
	
	//Aux = Busca a menor posi��o para fazer a troca
	
	//Ordena��o das propostas do curso pelo hor�rio
	for(i = 0; i < o; i ++){
	    
	    //par�metro da primeira casa como refer�cia
	    for(j = 0; j < curso[i].Q; j++){
	    	
	    	for(j2 = 0; j2 < curso[i].Q; j2++){
    	   	
    	   	//este if procura o menor valor de dia e hor�rio, e troca as posi��es enquanto acha
    		   if(curso[i].CAD1[j2].day < curso[i].CAD1[j].day && curso[i].CAD1[j2].time < curso[i].CAD1[j].time){
		  	   		aux = curso[i].CAD1[j2];
		  	   		curso[i].CAD1[j2] = curso[i].CAD1[j];
		 	     	curso[i].CAD1[j] = aux;
			   	}						
	   	
			}
		   
		}
	}
	
}
void ordenacao_curso(CAD *curso, int o){
	int i, j;
	CAD aux;
	
	//Aux = Busca a menor posi��o para fazer a troca
	
	//Ordena��o dos cursos em ordem alfab�tica
	for(i = 0; i < o; i ++){
		for(j = 0; j < o; j ++){
			//Compara��o das duas strings
		   	if( strcmp(curso[j].nome, curso[i].nome) > 0){
		   		aux = curso[j];
		  		curso[j] = curso[i];
		  		curso[i] = aux;
			}
		}	   		
	}
	
}