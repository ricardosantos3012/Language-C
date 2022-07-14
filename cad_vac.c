#include <stdio.h>
#include <locale.h>
#include <string.h>

void usuario();

int main () {
    //Inicia a biblioteca locale.h	
	setlocale(LC_ALL, "Portuguese");
	//Declara��o das vari�veis do programa
	int opcao,i, j, quant, result;
	char bcpf[15];
	//Declara��o da struct cadastro
	struct cadastro {
	int codigo;
	char nome[100];
	char numcpf[15];
	char vacina[50];
	char data[10];
	int numlote;
	int quant; 
	};
	//Declara��o da vari�vel de struct
	struct cadastro ficha[1000];
	//Estrutura Do-While que executa o menu do programa
	do {
		printf("Menu\n");
	    printf("1 - Cadastrar vacina\n");
	    printf("2 - Listar aplica��es\n");
	    printf("3 - Consultar por CPF\n");
	    printf("4 - Sair\n");
	    printf("Informe a op��o desejada: ");
	    fflush(stdin);
		scanf("%d", &opcao);
	    system("cls");
		//Estrutura case que verifica a op��o escolhida pelo usu�rio
		switch(opcao) {
            case 1: //Case que executa o cadastro de pacientes
				printf("Quantos cadastros deseja realizar: ");
				scanf("%d",&quant);
				system("cls");
				//Estrutura for que insere os dados na struct
				for(i=1; i<=quant; i++) {
					ficha[i].codigo=i;
	        	    printf("C�digo do paciente: %d\n",ficha[i].codigo);
					printf("Nome: ");
					fflush(stdin);
	        		gets(ficha[i].nome);
				    printf("CPF: ");
				    fflush(stdin);
	        	    gets(ficha[i].numcpf);
					fflush(stdin);
					printf("Vacina: ");
	        	    gets(ficha[i].vacina);
	        	    printf("Data: ");
	        	    fflush(stdin);
	        	    gets(ficha[i].data);
	        	    printf("Lote: ");
	        	    scanf("%d",&ficha[i].numlote);
	        	    system("cls");
			    }
			    //Mensagem que informa ao usu�ri oque todos os cadastros foram realizados
			    printf("--Todos os cadastros realizados com sucesso.--\n");
				system("pause");
	        	system("cls");
			break;
			case 2: //Case que exibe na tela relat�rio de todos os pacientes cadastrados
				printf("Relat�rio de pacientes cadastrados.\n");
				//Estrutura for que navega pelo vetor da struct para exibir todos os cadastros
				for(i=1; i<=quant; i++){
					printf("C�digo: %d\n",ficha[i].codigo);
					printf("Nome %s\n",ficha[i].nome);
					printf("CPF: %s\n",ficha[i].numcpf);
					printf("Vacina: %s\n",ficha[i].vacina);
					printf("Data: %s\n",ficha[i].data);
					printf("Lote: %d\n",ficha[i].numlote);
					printf("-------------------------------------\n");
				}
				system("pause");
				system("cls");
			break;
			case 3: //Case que faz a busca de um determinado cadastro usando o n�mero de CPF
				//Estrutura Do-While que pergunta ao usu�rio se ele deseja efetuar novo cadastro
				do {
				    printf("Busca por CPF.\n");
				    printf("Digite o CPF que deseja buscar: ");
				    fflush(stdin);
				    gets(bcpf);
				    //Estrutura for que navega pela struct buscando o n�mero de CPF digitado
					for(i=1; i<=quant; i++) {
		                //Estrutura if que verifica se o CPF digitado corresponde com o CPF do cadastro
						if(strcmp(bcpf,ficha[i].numcpf)==0){
		                    printf("C�digo: %d\n",ficha[i].codigo);
			                printf("Nome %s\n",ficha[i].nome);
			                printf("CPF: %s\n",ficha[i].numcpf);
			                printf("Vacina: %s\n",ficha[i].vacina);
			                printf("Data: %s\n",ficha[i].data);
			                printf("Lote: %d\n",ficha[i].numlote);
			                break;
                        }
	                }
						//Estrutura if que informa o usu�rio caso o CPF n�o seja encontrado
						if(strcmp(bcpf,ficha[i].numcpf)!=0){
							    printf("N�mero de CPF inv�lido.\n");
						}	
					//Pergunta ao usu�rio se deseja efetuar novo cadastro
					printf("\nDeseja realizar nova pesquisa?\n");
				    printf("1 - sim\n2 - n�o\n");
					scanf("%d",&opcao);
					system("cls");    
				}while (opcao !=2);   
				system("cls");
			break;
	    }
	} while(opcao !=4);
	//Informa ao usu�rio que o programa ser� encerrado
	printf("O Programa ser� encerrado.\n");
	system("pause");
	
	return 0;
}

