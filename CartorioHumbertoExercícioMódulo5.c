#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pela criação de strings

int main()
{  
	int opcao=0; //Definindo a localização da variável "opção" na memória
	int laco=1;
		
	for(laco=1;laco=1;)
	{
		system("cls"); //Comando para sistema operacional limpar a tela.
	
		setlocale (LC_ALL, "Portuguese"); //Definindo lingua para serem usados acentos
		
		printf("### Cartório da EBAC ##\n\n"); //Início do Menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção:"); //Fim do menu
		
		scanf("%d", &opcao); // Função "scanf" salva numero inteiro (%d) no endereço (&) da variável (opcao)
		
		system("cls"); //Comando para sistema operacional limpar a tela.
				
		switch(opcao)
		{
			case 1: // Quando escolher a "opção 1" e pressionar "enter" ele vai para as opções de registro.
			registro(); // Qual função abrir após comando anterior.
			break; // Pausa na execução de funções para não continuar a para a próxima sem concluir esta.
				
			case 2: // Quando escolher a "opção 2" e pressionar "enter" ele vai para as opções de consulta.
			consulta();
			break;
				
			case 3: // Quando escolher a "opção 3" e pressionar "enter" ele vai para as opções de deletar.
			deletar();
			break;
					
			default: // Quando escolher uma opção que nao seja 1,2 e 3 ele dá esse erro.
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		}
	}
}

int registro()
{
//"char" Indica que os elementos do array são do tipo caractere. Usamos ele aqui pois vamos salvar informações.
	
	char arquivo[40]; // Criando array com nome "arquivo" que tem capacidade de armazenar até 40 caracteres.
	char cpf[40]; // Criando array com nome "cpf" que tem capacidade de armazenar até 40 caracteres.
	char nome[40]; // Criando array com nome "nome" que tem capacidade de armazenar até 40 caracteres.
	char sobrenome[40]; // Criando array com nome "sobrenome" que tem capacidade de armazenar até 40 caracteres.
	char cargo[40]; // Criando array com nome "cargo" que tem capacidade de armazenar até 40 caracteres.
	 
	printf("Digite o CPF a ser cadastrado:  ");
	scanf("%s", cpf); // Função "scanf" salva string (%s) na array "cpf"
	
	strcpy(arquivo, cpf); // Copia a string "arquivo" e "cpf" com a mesma info
	
	FILE *file; // O sistema vai procurar nas bibliotecas a estrutura "FILE" para criar um aquivo chamado "file"
	file = fopen(arquivo, "w"); // Cria "file" com nome "arquivo" na nossa pasta. "w" significa que o app vai "write" a informação
	fprintf(file,cpf); // Salvar no "file" a variável "cpf"
	fclose(file); // Após termino da ação ele fecha o arquivo *lembre-se que na linha 66 atribuimos o nome "arquivo" ao "file", mas não precisa usar o nome dele.
	
	file = fopen(arquivo, "a");	// Reabrindo arquivo para "a" atualizar a informação
	fprintf(file,","); // Imprimir uma virgula ao final da impressao do cpf
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:  ");
	scanf("%s", nome); // Função "scanf" salva string (%s) na array "nome"
	
	file = fopen(arquivo,"a"); // Reabrindo arquivo para "a" atualizar a informação
	fprintf(file, nome); // Salvar no "file" a variável "nome"
	fclose(file); // Após termino da ação ele fecha o arquivo
	
	file = fopen(arquivo,"a");	// Reabrindo arquivo para "a" atualizar a informação
	fprintf(file,","); // Imprimir uma virgula ao final da impressao do nome
	fclose(file); // Após termino da ação ele fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); // Função "scanf" salva string (%s) na array "sobrenome"
	
	file = fopen(arquivo,"a");// Reabrindo arquivo para "a" atualizar a informação
	fprintf(file, sobrenome); // Salvar no "file" a variável "sobrenome"
	fclose(file); // Após termino da ação ele fecha o arquivo
	
	file = fopen(arquivo, "a");	// Reabrindo arquivo para "a" atualizar a informação
	fprintf(file,","); // Imprimir uma virgula ao final da impressao do sobrenome
	fclose(file); // Após termino da ação ele fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo); // Função "scanf" salva string (%s) na array "cargo"
	
	file = fopen(arquivo,"a");// Reabrindo arquivo para "a" atualizar a informação
	fprintf(file,cargo); // Salvar no "file" a variável "cargo"
	fclose(file); // Após termino da ação ele fecha o arquivo
	
	file = fopen(arquivo, "a");	// Reabrindo arquivo para "a" atualizar a informação
	fprintf(file,","); // Imprimir uma virgula ao final da impressao do cpf
	fclose(file); // Após termino da ação ele fecha o arquivo
	
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
		printf("Cadastro não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:  ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause");
}
	
int deletar()
{
	char cpf[40];
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usuário não se encontra no sistema!\n");
		system("pause");
	}
	else
	{
		remove(cpf);
		printf("Usuário deletado com sucesso!\n");
		system("pause");
	}
	
}

