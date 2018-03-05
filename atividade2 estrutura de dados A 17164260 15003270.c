//CAROLINE GERBAUDO NAKAZATO    RA: 17164260
//STEPHANIE LEONG DE OLIVEIRA   RA: 15003270
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

enum menu
{
	cadAluno = 1, excluiAluno, buscaRA,buscaNome, imprimir, sair};

typedef struct {
	int ra;
	char nome[50];
	double nota;
}taluno;

typedef struct taluno aluno;

typedef struct {
	aluno *alunos;
	int prox;
}taluno;


int existeAluno(int ra, int tamanho, aluno *alunos);
void buscarAluno(int ra, int tamanho, aluno *alunos);
void buscarAlunoPorNome(char *nome, int tamanho, aluno *alunos);

int main(void) {
	aluno *alunos[100];
	int opcao, i, qtd, raAtual, qtdTotal=0;
	do{
		printf("Digite:\n");
		printf("%d) Cadastrar Aluno.\n", cadAluno);
		printf("%d) Excluir Aluno.\n", excluiAluno);
		printf("%d) Buscar por RA.\n", buscaRA);
		printf("%d) Buscar por Nome.\n", buscaNome);
		printf("%d) Imprime todos os alunos.\n", imprimir);
		printf("%d) Sair.\n", sair);
                scanf("%d", &opcao);

		switch (opcao)
		{
		case cadAluno:
			printf("Digite quantos alunos serao cadastrados:\n");
			scanf("%d", &qtd);
			//alunos = (aluno *)malloc(qtd * sizeof(aluno));
			for (i = 0; i < qtd; i++) {
				printf("Digite o ra do aluno:\n");
			        scanf("%d", &raAtual);
				if(existeAluno(raAtual, qtdTotal, alunos)==0){
					alunos[i].ra = raAtual;		
					printf("Digite o nome do aluno:\n");
					scanf("%s", alunos[i].nome);
					printf("Digite o nota do aluno:\n");
					scanf("%fl", &alunos[i].nota);
					printf("Aluno cadastrado com sucesso!\n");	
					qtdTotal++;
				}else{
				printf("Ja existe um aluno com esse RA!\n");	
				i--;	
				}
			

			}
			break;
		case excluiAluno:
			printf("Digite o ra do aluno:\n");
			scanf("%d", &raAtual);
			if(existeAluno(raAtual, qtd, aluno *alunos)==1){
				
			}else{
				printf("Aluno nao esta cadastrado!\n");		
			}
			break;
		case buscaRA:
			printf("Digite o ra do aluno:\n");
			scanf("%d", &raAtual);
			if(existeAluno(raAtual, qtd, aluno *alunos)==1){
				buscarAluno(int ra, int tamanho, aluno *alunos)
			}else{
				printf("Aluno nao esta cadastrado!\n");		
			}
			
			break;
		case buscaNome:
			break;
		case sair:
			break;
		default:
			printf("Opcao Invalida!\n");
			break;
		}
	}while (opcao != sair);


system("pause");
return 0;
}

int existeAluno(int ra, int tamanho, aluno *alunos) {
	int j;
	for (j = 0; j < tamanho; j++) {
		if (alunos[j].ra == ra) {
			return 1; //true
		}
	}
	return 0; //false

}

void buscarAluno(int ra, int tamanho, aluno *alunos) {
	int j;
	for (j = 0; j < tamanho; j++) {
		if (alunos[j].ra == ra) {
			printf("RA: %d	NOME: %s NOTA: %.2fl\n", ra, alunos[j].nome, alunos[j].nota);
		}
	}
}

void buscarAlunoPorNome(char *nome, int tamanho, aluno *alunos){
	int j;
	for (j = 0; j < tamanho; j++) {
		if (strcmp(alunos[j].nome, nome)==0) {
			printf("RA: %d	NOME: %s NOTA: %.2fl\n", alunos[j].ra, nome, alunos[j].nota);

		}
	}
}

