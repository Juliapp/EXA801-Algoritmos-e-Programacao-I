/***************************
Autor: Juliana Arag�o Pinto
Componente Curricular: Algoritmos I
Concluido em: 14/10/2017
Declaro que este c�digo foi elaborado por mim de forma individual e n�o cont�m nenhum
trecho de c�digo de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e p�ginas ou documentos eletr�nicos da Internet. Qualquer trecho de c�digo
de outra autoria que n�o a minha est� destacado com uma cita��o para o autor e a fonte
do c�digo, e estou ciente que estes trechos n�o ser�o considerados para fins de avalia��o.
******************************/
//testando o compilador de celular

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

 /*
Bibliotecas usadas: 
Imput output (entrada e sa�da de dados)
String (manipula��o de strings)
Stdlib (aloca��o de mem�ria)
Locale (biblioteca para incluir os caracteres da l�ngua portuguesa)
*/

int main (){
	
	//Declara��o para a apari��o dos caracteres da l�ngua portuguesa no c�digo
	
	setlocale(LC_ALL, "");
	
	//Declara��o das vari�veis parte 1 (cadastro)
	
	char bairro[30], crianca[30];
	int menu = 0, dia = 0, mes = 0, ano = 0, anoCrianca = 0, mesCrianca = 0, diaCrianca = 0, sexo = 0, microcefalia = 0, problemacardiaco = 0, diabetes = 0, plano = 0, cadastradas = 0;
	float peso;
	
	// Declara��o das vari�veis parte 2.
	
	/*A parte 2 se refere a um complemento da parte 1, visando o processo para gerar o relat�rio final, 
	e tamb�m as atribui��es de valores iniciais para algumas vari�veis */
	
	int recorrente = 0, feminino = 0, masculino = 0, microcefaliapositivo = 0, cardiacopositivo = 0, diabetespositivo = 0, planonegativo = 0, retorno = 0, respincorreta = 0;
	
	/*As vari�veis abaixo ir�o fazer parte da coleta de dados referente as porcentagens mostradas no relat�rio*/
	
	float percentfem, percentmasc, percentMP, percentCP, percentDP, percentPN;
	
	
	
	//Inicio do programa
	
	/* Primeiramente o usu�rio ter� que registrar o nome do bairro e a data que est� sendo realizada
	a pesquisa. Com essa esp�cie de "pr� cadastro" o usu�rio n�o precisar� registrar o bairro e data
	a cada novo cadastro feito */
	
	
	printf("Digite o nome do bairro em que ser� realizada esta pesquisa:\n\n");
	scanf("%[^\n]s", &bairro);
	system("cls");
	fflush(stdin);
	//A string � contabilizada at� o usu�rio apertar enter, dando a possibilidade de registro de um nome composto.

	
	printf("Digite a data atual no formato dd/mm/aaaa\n\n");
	scanf("%d/%d/%d", &dia, &mes, &ano);
	system("cls");
	fflush(stdin);
	//O dia, m�s e ano s�o separadas pela barra "/"
	
	
	// Inicio do menu.

	do{
		
		respincorreta = 0;
			
		do{
			menu = 0;
				
			if (respincorreta == 0){
				/*A vari�vel respincorreta contabiliza a vez que voc� deu uma etrada incorreta para exibir a mensagem de erro. 
				A mesma vari�vel aparece diversas vezes ao longo do c�digo.*/
				
				system("cls");
				printf("\t\t\t\tMenu inicial.\n\n");
				printf("Digite a op��o que desejar:\n\n\n\n\n");
				printf("[1] - Cadastrar uma nova crian�a.\n");
				printf("[2] - Gerar um relat�rio geral.\n");
				printf("[0] - Fechar o programa.\n\n");
				scanf("%d", &menu);
				respincorreta = respincorreta + 1;
			}
			
			else if (respincorreta != 0){
				system("cls");
				printf("\t\t\t\tMenu inicial.\n\nDigite a op��o que desejar:\n\n\n");
				printf("Resposta incorreta. Digite novamente.\n\n");
				printf("[1] - Cadastro.\n");
				printf("[2] - Gerar um relat�rio geral.\n");
				printf("[0] - Fechar o programa.\n\n");
				scanf("%d", &menu); 
				respincorreta = respincorreta +1;
			}
				
		}while(menu != 1 && menu != 2 && menu != 0);
		
	/*A estrutura do programa foi toda realizada no formato acima. O usu�rio digita
	o valor 1 ou 2, e o programa retorna para a parte escolhida. Caso o valor que o usu�rio
	colocar for diferente de 1 ou 2, o programa automaticamente informa que a resposta � 
	invalida e gera um loop com o comando "goto" de volta a pergunta.*/
	
	/*No cadastro a estrutura se mant�m a mesma, divergindo que na hora em que o usuario fizer
	sua escolha, os dados necess�rios ser�o armazenados para gerar o relat�rio final.*/
			
			
			switch (menu){
					
				case 1:
							
					system("cls");
					
					fflush(stdin);
					printf("Digite o nome da crian�a: \n\n");
					scanf("%[^\n]s", &crianca);
									
					// A vari�vel para o nome da crian�a foi criada para o programa se tornar mais interativo com o usu�rio. 
		
					system("cls");
							
					printf("Qual a data de nascimento de nascimento de %s? Use o formato dd/mm/aaaa \n\n", crianca);
					scanf("%d/%d/%d", &diaCrianca, &mesCrianca, &anoCrianca);
			
						if (ano == anoCrianca){
							recorrente = recorrente +1;	
						}
						
						//Esse "if" checa se o ano da crian�a foi o mesmo do ano recorrente, e adiciona 1 caso seja.
																		
					system("cls");
					
						printf("Qual o peso de %s em quilogramas?\n", crianca);
						printf("(Separe as casas decimais utilizando ponto)\n\n");
						scanf("%f", &peso);
						
						//A vari�vel peso � pedida no problema, por�m n�o � utilizada em mais nenhum lugar do c�digo.

					respincorreta = 0;
					fflush(stdin);
					
					//O buffer do teclado � limpo aqui, pois a vari�vel float apresentou alguns erros nos testes.
					
					do{							
						system("cls");
						sexo = 0;
						//A cada ciclo, as vari�veis para a entrada da quest�o s�o zeradas.		
						
						if (respincorreta == 0){
							printf("Qual o sexo de %s?\n\n\n\n\n", crianca);
							printf("[1] - Feminino.\n");
							printf("[2] - Masculino.\n\n");
							scanf("%d", &sexo);
						}
								
						else if (respincorreta != 0){
							printf("Qual o sexo de %s?\n\n\n", crianca);
							printf("Responta incorreta. Digite novamente.\n\n");
							printf("[1] - Feminino.\n");
							printf("[2] - Masculino.\n\n");
							scanf("%d", &sexo);
						}
									 
							if (sexo == 1){
							feminino = feminino + 1;
							}
								else if (sexo == 2){
								masculino = masculino + 1;
							}
								else{
								respincorreta = respincorreta + 1;
							}
							
							//Nessa parte do c�digo � contabilizada o sexo das crian�as: feminino ou masculino.
								
					}while(sexo != 1 && sexo != 2);
					
					
					
					respincorreta = 0;
					microcefalia = 0;
					
					do{
						system("cls");
									
						if (respincorreta == 0){
							printf("%s possui microcefalia?\n\n\n\n\n", crianca);
							printf("[1] - Sim.\n");
							printf("[2] - N�o.\n\n");
							scanf("%d", &microcefalia);
						}
								
						else if (respincorreta != 0){
							printf("%s possui microcefalia?\n\n\n", crianca);
							printf("Responta incorreta. Digite novamente.\n\n");
							printf("[1] - Sim.\n");
							printf("[2] - N�o.\n\n");
							scanf("%d", &microcefalia);
						}
						
							
							if (microcefalia == 1){
								microcefaliapositivo = microcefaliapositivo + 1;
								}
							else if (microcefalia != 1 && microcefalia != 2){
								respincorreta = respincorreta + 1;
								}
								
								
							//� contabilizado as crian�as que tem microcefalia.
							
					}while(microcefalia != 1 && microcefalia != 2);
							
					respincorreta = 0;
					problemacardiaco = 0;					
						
					do{
						system("cls");
						fflush(stdin);
									
						if (respincorreta == 0){
							printf("%s possui problema card�aco?\n\n\n\n\n", crianca);			
							printf("[1] - Sim.\n");
							printf("[2] - N�o.\n\n");
							scanf("%d", &problemacardiaco);}
								
						else if (respincorreta != 0){
							printf("%s possui problema card�aco?\n\n\n", crianca);
							printf("Responta incorreta. Digite novamente.\n\n");
							printf("[1] - Sim.\n");
							printf("[2] - N�o.\n\n");
							scanf("%d", &problemacardiaco);}
							
							if (problemacardiaco == 1){
								cardiacopositivo = cardiacopositivo + 1;
							}
							else if (problemacardiaco != 1 && problemacardiaco != 2){
								respincorreta = respincorreta + 1;
							}
							
							//Contabiliza��o das crian�as que tem problema card�aco
								
					}while(problemacardiaco != 1 && problemacardiaco != 2);
							
					respincorreta = 0;
					diabetes = 0;
						
					do{
						system("cls");
								
						if (respincorreta == 0){
							printf("%s possui diabetes?\n\n\n\n\n", crianca);
							printf("[1] - Sim.\n");
							printf("[2] - N�o.\n\n");
							scanf("%d", &diabetes);
						}
								
						else if (respincorreta != 0){
							printf("%s possui diabetes?\n\n\n", crianca);
							printf("Responta incorreta. Digite novamente.\n\n");
							printf("[1] - Sim.\n");
							printf("[2] - N�o.\n\n");
							scanf("%d", &diabetes);
						}
							
							if (diabetes == 1){
								diabetespositivo = diabetespositivo + 1;
							}
							else if (diabetes != 1 && diabetes != 2){
								respincorreta = respincorreta + 1;
							}
									
									
							//Contabiliza��o das crian�as com diabetes.
							
					}while(diabetes != 1 && diabetes != 2);
							
					respincorreta = 0;
					plano = 0;
							
					do{
						system("cls");
									
						if (respincorreta == 0){
							printf("%s possui plano de sa�de?\n\n\n\n\n", crianca);
							printf("[1] - Sim.\n");
							printf("[2] - N�o.\n\n");
							scanf("%d", &plano);
						}
									
						else if (respincorreta != 0){
							printf("%s possui plano de sa�de?\n\n\n", crianca);
							printf("Responta incorreta. Digite novamente.\n\n");
							printf("[1] - Sim.\n");
							printf("[2] - N�o.\n\n");
							scanf("%d", &plano);
						}
								
							if (plano == 2){
								planonegativo = planonegativo + 1;
							}
							else if (planonegativo != 1 && planonegativo != 2){
								respincorreta = respincorreta + 1;
							}
									
							//Contabiliza��o das crian�as sem plano de sa�de.
							
					}while(plano != 1 && plano != 2);
								
								
					system("cls");
								
					printf("\n\n\n\n\n\n\n\n\n\nCadastro realizado com sucesso.\n\n");
					cadastradas = cadastradas + 1;
					
					//Finaliza��o com a contabilidade do n�mero de cadastros.
								
				system("pause");
				
				//O sistema pausa e o usu�rio tem que apertar qualquer tecla para continuar.
				
				break;
				
															
					case 2:
						
						//Relat�rio gerado pelos cadastros
						
						fflush(stdin);
							
						system("cls");
						
						//Calculos percentuais:
							
						percentfem = feminino * (100 / cadastradas);
						percentmasc = masculino * (100 / cadastradas);
						percentMP = microcefaliapositivo * (100 / cadastradas);
						percentCP = cardiacopositivo * (100 / cadastradas);
						percentDP = diabetespositivo * (100 / cadastradas);
						percentPN = planonegativo * (100 / cadastradas);
						
						//Amostra de dados:
									
						printf("Relat�rio do dia %2d/%2d/%4d realizado no bairro %s \n\n\n\n", dia, mes, ano, bairro);
		
						printf("Total de crian�as cadastradas: %d \n\n", cadastradas);
	
						printf("Total de crian�as nascidas no ano recorrente: %d \n\n", recorrente);
								
						printf("Percentual de crian�as do sexo feminino: %.2f %% \n", percentfem);
		
						printf("(%d de %d crian�as) \n\n", feminino, cadastradas);
									
						printf("Percentual de crian�as do sexo masculino: %.2f %% \n", percentmasc);
								
						printf("(%d de %d crian�as) \n\n", masculino, cadastradas);
									
						printf("Percentual de crian�as com microcefalia: %.2f %% \n", percentMP);
									
						printf("(%d de %d crian�as) \n\n", microcefaliapositivo, cadastradas);
									
						printf("Percentual de crian�as com problema card�aco: %.2f %% \n", percentCP);
									
						printf("(%d de %d crian�as) \n\n", cardiacopositivo, cadastradas);
									
						printf("Percentual de crian�as com diabetes: %.2f %%\n", percentDP);
									
						printf("(%d de %d crian�as) \n\n", diabetespositivo, cadastradas);
									
						printf("Percentual de crian�as sem plano de sa�de: %.2f %%\n", percentPN);
									
						printf("(%d de %d crian�as) \n\n\n\n\n", planonegativo, cadastradas);
						
					system("pause");					
					
					//O sistema pausa e o usu�rio tem que apertar qualquer tecla para continuar.
								
					break;				
						
			}
			
			
	// O programa vai funcionar at� que o usu�rio de a entrada 0 no menu.
		
	}while(menu != 0);
			
			

}

