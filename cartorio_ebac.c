#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings

int registrar() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo,cpf); //Respons�vel por copiar os valores das stings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo // w = write
	fprintf(file, cpf); //Salva o valor da vari�vel // fprintf = escreve no arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //a = atualiza a informa��o
	fprintf(file,", ");
	fclose(file);
	
	printf ("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf ("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf ("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file); 
	
	system("pause"); //Pausa o sistema para o usu�rio ler
	
}

int consultar()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf); 
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" = read
	
	if (file == NULL)
	{
		printf("\nN�o foi poss�vel abrir o arquivo, n�o localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	fclose(file);
	system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	remove(cpf);
	
	if(file == NULL)
	{
		printf("\nO usu�rio n�o se encontra no sistema!\n\n");
		system("pause");
	}
	
	else
	{
		printf("\nO usu�rio foi deletado com sucesso!\n\n");	
		system("pause");
	}
}



int main()
{
	setlocale(LC_ALL, "portuguese");
	
	int opcao=0; //Definindo as vari�veis
	int x=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //"strcmp" = comparar valores da string
	
	if(comparacao == 0)
	{	
		system("cls");
		for (x=1;x=1;) //Opera��o de repeti��o
		{
		
			system ("cls"); //Respons�evel por limpar a tela
			
			setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
			
			printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
			printf("Escolha a op��o desejada no menu:\n\n");
			printf("\t1 - Registrar Nomes\n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar Nomes\n");
			printf("\t4 - Sair\n\n"); 
			printf("Op��o: "); //Fim do menu
			
			scanf("%d", &opcao); //Armazenando a escolha do usu�rio
			
			system("cls");
			
			switch(opcao) //In�cio da opera��o
			{
				case 1:
				registrar(); //Chama as fun��es
				break;
				
				case 2:
				consultar();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sitema!\n");
				return 0;
				break;
				
				default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
			} //Fim da opera��o
		}
	}
	else
		printf("\nSenha incorreta");
}
