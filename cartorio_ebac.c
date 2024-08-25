#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h> //Biblioteca responsável por cuidar das strings

int registrar() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo,cpf); //Responsável por copiar os valores das stings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo // w = write
	fprintf(file, cpf); //Salva o valor da variável // fprintf = escreve no arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //a = atualiza a informação
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
	
	system("pause"); //Pausa o sistema para o usuário ler
	
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
		printf("\nNão foi possível abrir o arquivo, não localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	fclose(file);
	system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	remove(cpf);
	
	if(file == NULL)
	{
		printf("\nO usuário não se encontra no sistema!\n\n");
		system("pause");
	}
	
	else
	{
		printf("\nO usuário foi deletado com sucesso!\n\n");	
		system("pause");
	}
}



int main()
{
	setlocale(LC_ALL, "portuguese");
	
	int opcao=0; //Definindo as variáveis
	int x=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //"strcmp" = comparar valores da string
	
	if(comparacao == 0)
	{	
		system("cls");
		for (x=1;x=1;) //Operação de repetição
		{
		
			system ("cls"); //Responsáevel por limpar a tela
			
			setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
			
			printf("### Cartório da EBAC ###\n\n"); //Início do menu
			printf("Escolha a opção desejada no menu:\n\n");
			printf("\t1 - Registrar Nomes\n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar Nomes\n");
			printf("\t4 - Sair\n\n"); 
			printf("Opção: "); //Fim do menu
			
			scanf("%d", &opcao); //Armazenando a escolha do usuário
			
			system("cls");
			
			switch(opcao) //Início da operação
			{
				case 1:
				registrar(); //Chama as funções
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
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;
			} //Fim da operação
		}
	}
	else
		printf("\nSenha incorreta");
}
