#include <stdio.h> //biblioteca de comunicacão com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocacões de texto por região
#include <string.h> // biblioteca responsável por cuida das string

int registro()//função responsável por cadastra os usuário no sistema
{
	//innicio criação de variáveis/string
	char arquivo[40];
    char cpf [40];	
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//fim criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);//refere-se a strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valore da string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file,",");//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadartrado:");
	scanf("%s",nome);//refere-se a strings
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file,nome);//salvo o valor da variavel 
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file,",");//salvo o valor da variavel
	fclose(file);//salvo o valor da variavel
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);//refere-se a strings
	
	file = fopen(arquivo, "a");	//cria o arquivo
	fprintf(file,sobrenome);//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file,",");//salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);//refere-se a strings
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file,cargo);//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	system("pause");

	}

  int consulta()
  {
  setlocale(LC_ALL,"portuguese");//definindo a liguagem
  
  char cpf[40];
  char conteudo[200];
  
  printf("Digite o CPF a ser consultado: ");
  scanf("%s",cpf);//refere-se a strings
  
  FILE *file; // cria o arquivo
  file = fopen(cpf,"r");// cria arquivo
  
  if(file == NULL)
  {
    printf("Não foi posivel abri o arquivo, não localisado!.\n");
  }
  
  while(fgets(conteudo, 200, file) !=NULL)
  {
  	printf("\nEssas são as informações do usúario:");
  	printf("%s",conteudo);
    printf("\n\n");
  }
  system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%S",cpf);
	
	remove(cpf);
    	
	FILE *file;// cria o arquivo
	file = fopen(cpf,"r");// cria o arquivo
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
	
}

int main()
{
	int opcao=0;//definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
	system("cls");//responsável por linpar a tela
		
	setlocale(LC_ALL,"portuguese");//definindo a liguagem
	
	printf("### Cartório da EBAC ###\n\n ");//inicio do menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registra nomes\n\n");
	printf("\t2 - Consultar nomes\n\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("opção:");//fim do menu
	
    scanf("%d", &opcao);//amarzenando a escolha do usuário 
    
    system("cls"); //responsável por linpar a tela
    
    
    switch(opcao)//inicio da seleção do menu
    {
    	case 1:
    	registro();//chamada de funções
    	break;
    		
        case 2:
        consulta();
        break;
        	
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por ultilizar o sistema!\n");
		return 0;
		
		default:
		printf("Essa opção não está disponivel!\n");
		system("pause");
		break;
		
	}//fim da seleção
	

}
}
