/***************************
Autor: Juliana Aragão Pinto
Componente Curricular: Algoritmos I
Concluido em: 14/10/2017
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
******************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

 /*
Bibliotecas usadas: 
Imput output (entrada e saída de dados)
String (manipulação de strings)
Stdlib (alocação de memória)
Locale (biblioteca para incluir os caracteres da língua portuguesa)
*/

int main (){
	
	//Declaração para a aparição dos caracteres da língua portuguesa no código
	
	setlocale(LC_ALL, "");
	
	//Declaração das variáveis parte 1 (cadastro)
	
	char bairro[30], crianca[30];
	int menu = 0, dia = 0, mes = 0, ano = 0, anoCrianca = 0, mesCrianca = 0, diaCrianca = 0, sexo = 0, microcefalia = 0, problemacardiaco = 0, diabetes = 0, plano = 0, cadastradas = 0;
	float peso;
	
	// Declaração das variáveis parte 2.
	
	/*A parte 2 se refere a um complemento da parte 1, visando o processo para gerar o relatório final, 
	e também as atribuições de valores iniciais para algumas variáveis */
	
	int recorrente = 0, feminino = 0, masculino = 0, microcefaliapositivo = 0, cardiacopositivo = 0, diabetespositivo = 0, planonegativo = 0, retorno = 0, respincorreta = 0;
	
	/*As variáveis abaixo irão fazer parte da coleta de dados referente as porcentagens mostradas no relatório*/
	
	float percentfem, percentmasc, percentMP, percentCP, percentDP, percentPN;
	
	
	
	//Inicio do programa
	
	/* Primeiramente o usuário terá que registrar o nome do bairro e a data que está sendo realizada
	a pesquisa. Com essa espécie de "pré cadastro" o usuário não precisará registrar o bairro e data
	a cada novo cadastro feito */
	
	
	printf("Digite o nome do bairro em que será realizada esta pesquisa:\n\n");
	scanf("%[^\n]s", &bairro);
	system("cls");
	fflush(stdin);
	//A string é contabilizada até o usuário apertar enter, dando a possibilidade de registro de um nome composto.

	
	printf("Digite a data atual no formato dd/mm/aaaa\n\n");
	scanf("%d/%d/%d", &dia, &mes, &ano);
	system("cls");
	fflush(stdin);
	//O dia, mês e ano são separadas pela barra "/"
	
	
	// Inicio do menu.

	do{
		
		respincorreta = 0;
			
		do{
			menu = 0;
				
			if (respincorreta == 0){
				/*A variável respincorreta contabiliza a vez que você deu uma etrada incorreta para exibir a mensagem de erro. 
				A mesma variável aparece diversas vezes ao longo do código.*/
				
				system("cls");
				printf("\t\t\t\tMenu inicial.\n\n");
				printf("Digite a opção que desejar:\n\n\n\n\n");
				printf("[1] - Cadastrar uma nova criança.\n");
				printf("[2] - Gerar um relatório geral.\n");
				printf("[0] - Fechar o programa.\n\n");
				scanf("%d", &menu);
				respincorreta = respincorreta + 1;
			}
			
			else if (respincorreta != 0){
				system("cls");
				printf("\t\t\t\tMenu inicial.\n\nDigite a opção que desejar:\n\n\n");
				printf("Resposta incorreta. Digite novamente.\n\n");
				printf("[1] - Cadastro.\n");
				printf("[2] - Gerar um relatório geral.\n");
				printf("[0] - Fechar o programa.\n\n");
				scanf("%d", &menu); 
				respincorreta = respincorreta +1;
			}
				
		}while(menu != 1 && menu != 2 && menu != 0);
		
	/*A estrutura do programa foi toda realizada no formato acima. O usuário digita
	o valor 1 ou 2, e o programa retorna para a parte escolhida. Caso o valor que o usuário
	colocar for diferente de 1 ou 2, o programa automaticamente informa que a resposta é 
	invalida e gera um loop com o comando "goto" de volta a pergunta.*/
	
	/*No cadastro a estrutura se mantém a mesma, divergindo que na hora em que o usuario fizer
	sua escolha, os dados necessários serão armazenados para gerar o relatório final.*/
			
			
			switch (menu){
					
				case 1:
							
					system("cls");
					
					fflush(stdin);
					printf("Digite o nome da criança: \n\n");
					scanf("%[^\n]s", &crianca);
									
					// A variável para o nome da criança foi criada para o programa se tornar mais interativo com o usuário. 
		
					system("cls");
							
					printf("Qual a data de nascimento de nascimento de %s? Use o formato dd/mm/aaaa \n\n", crianca);
					scanf("%d/%d/%d", &diaCrianca, &mesCrianca, &anoCrianca);
			
						if (ano == anoCrianca){
							recorrente = recorrente +1;	
						}
						
						//Esse "if" checa se o ano da criança foi o mesmo do ano recorrente, e adiciona 1 caso seja.
																		
					system("cls");
					
						printf("Qual o peso de %s em quilogramas?\n", crianca);
						printf("(Separe as casas decimais utilizando ponto)\n\n");
						scanf("%f", &peso);
						
						//A variável peso é pedida no problema, porém não é utilizada em mais nenhum lugar do código.

					respincorreta = 0;
					fflush(stdin);
					
					//O buffer do teclado é limpo aqui, pois a variável float apresentou alguns erros nos testes.
					
					do{							
						system("cls");
						sexo = 0;
						//A cada ciclo, as variáveis para a entrada da questão são zeradas.		
						
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
							
							//Nessa parte do código é contabilizada o sexo das crianças: feminino ou masculino.
								
					}while(sexo != 1 && sexo != 2);
					
					
					
					respincorreta = 0;
					microcefalia = 0;
					
					do{
						system("cls");
									
						if (respincorreta == 0){
							printf("%s possui microcefalia?\n\n\n\n\n", crianca);
							printf("[1] - Sim.\n");
							printf("[2] - Não.\n\n");
							scanf("%d", &microcefalia);
						}
								
						else if (respincorreta != 0){
							printf("%s possui microcefalia?\n\n\n", crianca);
							printf("Responta incorreta. Digite novamente.\n\n");
							printf("[1] - Sim.\n");
							printf("[2] - Não.\n\n");
							scanf("%d", &microcefalia);
						}
						
							
							if (microcefalia == 1){
								microcefaliapositivo = microcefaliapositivo + 1;
								}
							else if (microcefalia != 1 && microcefalia != 2){
								respincorreta = respincorreta + 1;
								}
								
								
							//É contabilizado as crianças que tem microcefalia.
							
					}while(microcefalia != 1 && microcefalia != 2);
							
					respincorreta = 0;
					problemacardiaco = 0;					
						
					do{
						system("cls");
						fflush(stdin);
									
						if (respincorreta == 0){
							printf("%s possui problema cardíaco?\n\n\n\n\n", crianca);			
							printf("[1] - Sim.\n");
							printf("[2] - Não.\n\n");
							scanf("%d", &problemacardiaco);}
								
						else if (respincorreta != 0){
							printf("%s possui problema cardíaco?\n\n\n", crianca);
							printf("Responta incorreta. Digite novamente.\n\n");
							printf("[1] - Sim.\n");
							printf("[2] - Não.\n\n");
							scanf("%d", &problemacardiaco);}
							
							if (problemacardiaco == 1){
								cardiacopositivo = cardiacopositivo + 1;
							}
							else if (problemacardiaco != 1 && problemacardiaco != 2){
								respincorreta = respincorreta + 1;
							}
							
							//Contabilização das crianças que tem problema cardíaco
								
					}while(problemacardiaco != 1 && problemacardiaco != 2);
							
					respincorreta = 0;
					diabetes = 0;
						
					do{
						system("cls");
								
						if (respincorreta == 0){
							printf("%s possui diabetes?\n\n\n\n\n", crianca);
							printf("[1] - Sim.\n");
							printf("[2] - Não.\n\n");
							scanf("%d", &diabetes);
						}
								
						else if (respincorreta != 0){
							printf("%s possui diabetes?\n\n\n", crianca);
							printf("Responta incorreta. Digite novamente.\n\n");
							printf("[1] - Sim.\n");
							printf("[2] - Não.\n\n");
							scanf("%d", &diabetes);
						}
							
							if (diabetes == 1){
								diabetespositivo = diabetespositivo + 1;
							}
							else if (diabetes != 1 && diabetes != 2){
								respincorreta = respincorreta + 1;
							}
									
									
							//Contabilização das crianças com diabetes.
							
					}while(diabetes != 1 && diabetes != 2);
							
					respincorreta = 0;
					plano = 0;
							
					do{
						system("cls");
									
						if (respincorreta == 0){
							printf("%s possui plano de saúde?\n\n\n\n\n", crianca);
							printf("[1] - Sim.\n");
							printf("[2] - Não.\n\n");
							scanf("%d", &plano);
						}
									
						else if (respincorreta != 0){
							printf("%s possui plano de saúde?\n\n\n", crianca);
							printf("Responta incorreta. Digite novamente.\n\n");
							printf("[1] - Sim.\n");
							printf("[2] - Não.\n\n");
							scanf("%d", &plano);
						}
								
							if (plano == 2){
								planonegativo = planonegativo + 1;
							}
							else if (planonegativo != 1 && planonegativo != 2){
								respincorreta = respincorreta + 1;
							}
									
							//Contabilização das crianças sem plano de saúde.
							
					}while(plano != 1 && plano != 2);
								
								
					system("cls");
								
					printf("\n\n\n\n\n\n\n\n\n\nCadastro realizado com sucesso.\n\n");
					cadastradas = cadastradas + 1;
					
					//Finalização com a contabilidade do número de cadastros.
								
				system("pause");
				
				//O sistema pausa e o usuário tem que apertar qualquer tecla para continuar.
				
				break;
				
															
					case 2:
						
						//Relatório gerado pelos cadastros
						
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
									
						printf("Relatório do dia %2d/%2d/%4d realizado no bairro %s \n\n\n\n", dia, mes, ano, bairro);
		
						printf("Total de crianças cadastradas: %d \n\n", cadastradas);
	
						printf("Total de crianças nascidas no ano recorrente: %d \n\n", recorrente);
								
						printf("Percentual de crianças do sexo feminino: %.2f %% \n", percentfem);
		
						printf("(%d de %d crianças) \n\n", feminino, cadastradas);
									
						printf("Percentual de crianças do sexo masculino: %.2f %% \n", percentmasc);
								
						printf("(%d de %d crianças) \n\n", masculino, cadastradas);
									
						printf("Percentual de crianças com microcefalia: %.2f %% \n", percentMP);
									
						printf("(%d de %d crianças) \n\n", microcefaliapositivo, cadastradas);
									
						printf("Percentual de crianças com problema cardíaco: %.2f %% \n", percentCP);
									
						printf("(%d de %d crianças) \n\n", cardiacopositivo, cadastradas);
									
						printf("Percentual de crianças com diabetes: %.2f %%\n", percentDP);
									
						printf("(%d de %d crianças) \n\n", diabetespositivo, cadastradas);
									
						printf("Percentual de crianças sem plano de saúde: %.2f %%\n", percentPN);
									
						printf("(%d de %d crianças) \n\n\n\n\n", planonegativo, cadastradas);
						
					system("pause");					
					
					//O sistema pausa e o usuário tem que apertar qualquer tecla para continuar.
								
					break;				
						
			}
			
			
	// O programa vai funcionar até que o usuário de a entrada 0 no menu.
		
	}while(menu != 0);
			
			

}

