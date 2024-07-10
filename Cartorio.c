#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h>// Biblioteca de de aloca��o de espa�o de mem�ria
#include <locale.h>// Biblioteca de aloca��o de texto por regi�o
#include <string.h>// Biblioteca reponsavel por cuidar das strings

int registro() // Fun��o respons�vel por cadastrar os usuarios no sistema
{
	// inicio de cria��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final de cria��o de vari�veis/string
	printf("Digite o cpf a ser cadastrado:");// coletando informa��es do usuario
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo,cpf); // Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo,"w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
		
		
}

int consulta()
{
	setlocale (LC_ALL, "portuguese");
	 
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel localizar o cpf\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
		
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado:");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose (file);
	
	if(file == NULL)
	{
	   printf("O usu�rio n�o se encontra no sistema!.\n");
	   system ("pause");	
	}	
}



int main ()
{
  	int opcao=0; // Definindo vari�veis
  	int laco=1;
  	
  	for(laco=1;laco=1;)
   {
	  
	    system("cls");
	    
	    setlocale (LC_ALL, "portuguese"); // Definindo linguagem
	
	    printf("###Cart�rio da EBAC###\n\n"); // in�cio do menu
	    printf("Escolha a op��o desejada no menu\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); // fim do menu
	  
	    printf ("Op��o: ");

	
	    scanf("%d", &opcao); // armazenamento a escolha do usuario
	
	    system("cls"); // responsavel para limpar a tela
	    
	    
	    switch(opcao)
	    {
	    	case 1:
	        registro(); // chamada de fun��es
		    break;
		    
		    case 2:
		    consulta();
			break;
			
			case 3:
		    deletar();
			break;

			default:
			printf("Essa op��o est� indispon�vel!\n");
		    system("pause");
		    break;	
			// fim da sele��o	
		}
}
	
}
