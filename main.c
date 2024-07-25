#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>


typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} PilhaDinamica;

PilhaDinamica* criarPilhaDinamica() {
    PilhaDinamica *pilha = (PilhaDinamica*) malloc(sizeof(PilhaDinamica));
    if (pilha != NULL) {
        pilha->topo = NULL;
    }
    return pilha;
}

int pilhaVazia(PilhaDinamica *pilha) {
    return (pilha->topo == NULL);
}

void empilhar(PilhaDinamica *pilha, int dado) {
    No *novoNo = (No*) malloc(sizeof(No));
    if (novoNo != NULL) {
        novoNo->dado = dado;
        novoNo->prox = pilha->topo;
        pilha->topo = novoNo;
        printf("Elemento %d empilhado na pilha.\n", dado);
    } else {
        printf("Erro: Não foi possível alocar memória para o novo elemento.\n");
    }
}

int desempilhar(PilhaDinamica *pilha) {
    int elemento;

    if (pilhaVazia(pilha)) {
        printf("Erro: Pilha dinâmica vazia, não é possível desempilhar.\n");
        return -1; 
    } else {
        No *temp = pilha->topo;
        elemento = temp->dado;
        pilha->topo = temp->prox;
        free(temp);
        return elemento;
    }
}

void imprimirPilhaDinamica(PilhaDinamica *pilha) {
    printf("Pilha Dinâmica: ");
    if (pilhaVazia(pilha)) {
        printf("pilha vazia\n");
    } else {
        No *atual = pilha->topo;
        while (atual != NULL) {
            printf("%d ", atual->dado);
            atual = atual->prox;
        }
        printf("\n");
    }
}

int main() {
	setlocale(LC_ALL, "portuguese");
    PilhaDinamica *pilha = criarPilhaDinamica();
    int opcao, elemento;

    do {
        printf("\nOpções:\n");
        printf("1. Empilhar elemento\n");
        printf("2. Desempilhar elemento\n");
        printf("3. Imprimir pilha\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser empilhado: ");
                scanf("%d", &elemento);
                empilhar(pilha, elemento);
                break;
            case 2:
                elemento = desempilhar(pilha);
                if (elemento != -1) {
                    printf("Elemento desempilhado: %d\n", elemento);
                }
                break;
            case 3:
                imprimirPilhaDinamica(pilha);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

