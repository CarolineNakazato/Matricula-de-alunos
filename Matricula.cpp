
//CAROLINE GERBAUDO NAKAZATO    RA: 17164260
//STEPHANIE LEONG DE OLIVEIRA   RA: 15003270

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

enum menu
{
	cadAluno = 1, excluiAluno, buscaRA, buscaNome, imprimir, sair
};

struct taluno {
	int ra;
	char nome[50];
	double nota;
}; //arrumar quando for linux

typedef struct taluno aluno; // arrumar quando for linux

void exibeMenu();
int existeAluno(int ra, int tamanho, aluno *alunos);
int existeAlunoPorNome(char *nome, int tamanho, aluno *alunos);
void buscarAluno(int ra, int tamanho, aluno *alunos);
void buscarAlunoPorNome(char *nome, int tamanho, aluno *alunos);
int removeAlunoPorRA(aluno *alunos,int tamanho, int ra);

int main(void) {
	aluno alunos[100];
	int opcao, i, qtd, raAtual, qtdTotal = 0, ocorre=0, parada=0;
	char nomeAtual[50];
	printf("\e[H\e[2J");// Esse comando limpa a tela do Terminal
        do {
	    	
                exibeMenu();
		scanf("%d", &opcao);
                printf("\e[H\e[2J");
                switch (opcao)
		{
		case cadAluno:
			printf("Digite quantos alunos serao cadastrados:\n");
			scanf("%d", &qtd);
			//alunos = (aluno *)malloc(qtd * sizeof(aluno));
                        if(qtdTotal != 0){
                            parada = qtd + qtdTotal;
                            for(i=qtdTotal;i<parada;i++){
                                printf("Digite o ra do aluno:\n");
				scanf("%d", &raAtual);
				if (existeAluno(raAtual, qtdTotal, alunos) == 0) {
					alunos[i].ra = raAtual;
					printf("Digite o nome do aluno:\n");
					scanf("%s", alunos[i].nome);
					printf("Digite o nota do aluno:\n");
					scanf("%lf", &alunos[i].nota);
					printf("Aluno cadastrado com sucesso!\n");
					qtdTotal++;
				}
				else {
					printf("Ja existe um aluno com esse RA!\n");
					i--;
				}
                            }
                        }
                        else{
                            for (i = 0; i < qtd; i++) {
				printf("Digite o ra do aluno:\n");
				scanf("%d", &raAtual);
				if (existeAluno(raAtual, qtdTotal, alunos) == 0) {
					alunos[i].ra = raAtual;
					printf("Digite o nome do aluno:\n");
					scanf("%s", alunos[i].nome);
					printf("Digite o nota do aluno:\n");
					scanf("%lf", &alunos[i].nota);
					printf("Aluno cadastrado com sucesso!\n");
					qtdTotal++;
				}
				else {
					printf("Ja existe um aluno com esse RA!\n");
					i--;
				}


			}
                        }
			qtd=0;
			printf("\e[H\e[2J");
			break;
		case excluiAluno:
			printf("Digite o ra do aluno:\n");
			scanf("%d", &raAtual);
			if (existeAluno(raAtual, qtdTotal, alunos) == 1) {
                            if(removeAlunoPorRA(alunos,qtdTotal, raAtual) == 1){
                                printf("Aluno com RA: %d foi Removido com Sucesso!\n", raAtual);
                                qtdTotal--;
                            }
                            else{
                                printf("Aluno ainda nao Removido!\n");
                            }
			}
			else {
				printf("Aluno nao esta cadastrado!\n");
			}
			
			break;
		case buscaRA:
			printf("Digite o ra do aluno:\n");
			scanf("%d", &raAtual);
			if (existeAluno(raAtual, qtdTotal, alunos) == 1) {
				buscarAluno(raAtual, qtd, alunos);
			}
			else {
				printf("Aluno nao esta cadastrado!\n");
			}

			break;
		case buscaNome:
			printf("Digite o nome do aluno:\n");
			scanf("%s", nomeAtual);
			if (existeAlunoPorNome(nomeAtual, qtdTotal, alunos) == 1) {
				buscarAlunoPorNome(nomeAtual, qtdTotal, alunos);
			}
			else {
				printf("Aluno nao esta cadastrado!\n");
			}
			break;
		case imprimir:
		    printf("\n\n");	
                    for (i = 0; i < qtdTotal; i++) {
				printf("RA: %d	NOME: %s NOTA: %.2lf\n", alunos[i].ra, alunos[i].nome, alunos[i].nota);
			}
			printf("\n\n");
			break;
		case sair:
			break;
		default:
			printf("Opcao Invalida!\n");
			break;
		}
	} while (opcao != sair);


	return 0;
}

void exibeMenu(){
    printf("Digite:\n");
    printf("%d) Cadastrar Aluno.\n", cadAluno);
    printf("%d) Excluir Aluno.\n", excluiAluno);
    printf("%d) Buscar por RA.\n", buscaRA);
    printf("%d) Buscar por Nome.\n", buscaNome);
    printf("%d) Imprime todos os alunos.\n", imprimir);
    printf("%d) Sair.\n", sair);
    printf("Opcao: ");
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
int existeAlunoPorNome(char *nome, int tamanho, aluno *alunos) {
	int j;
	for (j = 0; j < tamanho; j++) {
		if (strcmp(alunos[j].nome, nome)==0) {
			return 1; //true
		}
	}
	return 0; //false

}

void buscarAluno(int ra, int tamanho, aluno *alunos) {
	int j;
	for (j = 0; j < tamanho; j++) {
		if (alunos[j].ra == ra) {
			printf("RA: %d	NOME: %s NOTA: %.2lf\n", ra, alunos[j].nome, alunos[j].nota);
		}
	}
}

void buscarAlunoPorNome(char *nome, int tamanho, aluno *alunos) {
	int j;
	for (j = 0; j < tamanho; j++) {
		if (strcmp(alunos[j].nome, nome) == 0) {
			printf("RA: %d	NOME: %s NOTA: %.2lf\n", alunos[j].ra, nome, alunos[j].nota);

		}
	}
}

int removeAlunoPorRA(aluno *alunos, int tamanho,int ra){
    int j, i;
    printf("Remover Aluno\n");
    for (j = 0; j < tamanho; j++) {
        if (alunos[j].ra == ra) {
            if(j == tamanho-1){
                return 1;
            }
            for(i=j;i<tamanho;i++){
                alunos[i] = alunos[i+1];
            }
            return 1; //true
        }
    }
    return 0;
    
}
