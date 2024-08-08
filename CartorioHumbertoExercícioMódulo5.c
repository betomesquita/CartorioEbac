#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel pela cria��o de strings

int main()
{  
	int opcao=0; //Definindo a localiza��o da vari�vel "op��o" na mem�ria
	int laco=1;
		
	for(laco=1;laco=1;)
	{
		system("cls"); //Comando para sistema operacional limpar a tela.
	
		setlocale (LC_ALL, "Portuguese"); //Definindo lingua para serem usados acentos
		
		printf("### Cart�rio da EBAC ##\n\n"); //In�cio do Menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o:"); //Fim do menu
		
		scanf("%d", &opcao); // Fun��o "scanf" salva numero inteiro (%d) no endere�o (&) da vari�vel (opcao)
		
		system("cls"); //Comando para sistema operacional limpar a tela.
				
		switch(opcao)
		{
			case 1: // Quando escolher a "op��o 1" e pressionar "enter" ele vai para as op��es de registro.
			registro(); // Qual fun��o abrir ap�s comando anterior.
			break; // Pausa na execu��o de fun��es para n�o continuar a para a pr�xima sem concluir esta.
				
			case 2: // Quando escolher a "op��o 2" e pressionar "enter" ele vai para as op��es de consulta.
			consulta();
			break;
				
			case 3: // Quando escolher a "op��o 3" e pressionar "enter" ele vai para as op��es de deletar.
			deletar();
			break;
					
			default: // Quando escolher uma op��o que nao seja 1,2 e 3 ele d� esse erro.
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}
	}
}

int registro()
{
//"char" Indica que os elementos do array s�o do tipo caractere. Usamos ele aqui pois vamos salvar informa��es.
	
	char arquivo[40]; // Criando array com nome "arquivo" que tem capacidade de armazenar at� 40 caracteres.
	char cpf[40]; // Criando array com nome "cpf" que tem capacidade de armazenar at� 40 caracteres.
	char nome[40]; // Criando array com nome "nome" que tem capacidade de armazenar at� 40 caracteres.
	char sobrenome[40]; // Criando array com nome "sobrenome" que tem capacidade de armazenar at� 40 caracteres.
	char cargo[40]; // Criando array com nome "cargo" que tem capacidade de armazenar at� 40 caracteres.
	 
	printf("Digite o CPF a ser cadastrado:  ");
	scanf("%s", cpf); // Fun��o "scanf" salva string (%s) na array "cpf"
	
	strcpy(arquivo, cpf); // Copia a string "arquivo" e "cpf" com a mesma info
	
	FILE *file; // O sistema vai procurar nas bibliotecas a estrutura "FILE" para criar um aquivo chamado "file"
	file = fopen(arquivo, "w"); // Cria "file" com nome "arquivo" na nossa pasta. "w" significa que o app vai "write" a informa��o
	fprintf(file,cpf); // Salvar no "file" a vari�vel "cpf"
	fclose(file); // Ap�s termino da a��o ele fecha o arquivo *lembre-se que na linha 66 atribuimos o nome "arquivo" ao "file", mas n�o precisa usar o nome dele.
	
	file = fopen(arquivo, "a");	// Reabrindo arquivo para "a" atualizar a informa��o
	fprintf(file,","); // Imprimir uma virgula ao final da impressao do cpf
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:  ");
	scanf("%s", nome); // Fun��o "scanf" salva string (%s) na array "nome"
	
	file = fopen(arquivo,"a"); // Reabrindo arquivo para "a" atualizar a informa��o
	fprintf(file, nome); // Salvar no "file" a vari�vel "nome"
	fclose(file); // Ap�s termino da a��o ele fecha o arquivo
	
	file = fopen(arquivo,"a");	// Reabrindo arquivo para "a" atualizar a informa��o
	fprintf(file,","); // Imprimir uma virgula ao final da impressao do nome
	fclose(file); // Ap�s termino da a��o ele fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); // Fun��o "scanf" salva string (%s) na array "sobrenome"
	
	file = fopen(arquivo,"a");// Reabrindo arquivo para "a" atualizar a informa��o
	fprintf(file, sobrenome); // Salvar no "file" a vari�vel "sobrenome"
	fclose(file); // Ap�s termino da a��o ele fecha o arquivo
	
	file = fopen(arquivo, "a");	// Reabrindo arquivo para "a" atualizar a informa��o
	fprintf(file,","); // Imprimir uma virgula ao final da impressao do sobrenome
	fclose(file); // Ap�s termino da a��o ele fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo); // Fun��o "scanf" salva string (%s) na array "cargo"
	
	file = fopen(arquivo,"a");// Reabrindo arquivo para "a" atualizar a informa��o
	fprintf(file,cargo); // Salvar no "file" a vari�vel "cargo"
	fclose(file); // Ap�s termino da a��o ele fecha o arquivo
	
	file = fopen(arquivo, "a");	// Reabrindo arquivo para "a" atualizar a informa��o
	fprintf(file,","); // Imprimir uma virgula ao final da impressao do cpf
	fclose(file); // Ap�s termino da a��o ele fecha o arquivo
	
	system("pause");
}

int consulta()
{
	setlocale (LC_ALL, "Portuguese"); //Definindo lingua para serem usados acentos
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado:  ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Cadastro n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:  ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause");
}
	
int deletar()
{
	char cpf[40];
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	else
	{
		remove(cpf);
		printf("Usu�rio deletado com sucesso!\n");
		system("pause");
	}
	
}

