# INNAR 
#Edmilson Benjamin Caetano
#Feito com Murade Bin Lobo
aula pratica
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
} No;

typedef struct Pilha {
    No** array;
    int tamanho;
    int capacidade;
} Pilha;

No* criarNo(int dado, No* esquerda, No* direita) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->esquerda = esquerda;
    novoNo->direita = direita;
    return novoNo;
}

Pilha* criarPilha(int capacidade) {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->array = (No**)malloc(capacidade * sizeof(No*));
    pilha->tamanho = 0;
    pilha->capacidade = capacidade;
    return pilha;
}

void empilhar(Pilha* pilha, No* no) {
    if (pilha->tamanho >= pilha->capacidade) {
        printf("Pilha cheia\n");
        return;
    }
    pilha->array[pilha->tamanho++] = no;
}

No* desempilhar(Pilha* pilha) {
    if (pilha->tamanho <= 0) {
        printf("Pilha vazia\n");
        return NULL;
    }
    return pilha->array[--pilha->tamanho];
}

int pilhaVazia(Pilha* pilha) {
    return pilha->tamanho == 0;
}

void mostrarCaminho(Pilha* pilha) {
    for (int i = 0; i < pilha->tamanho; ++i) {
        printf("%d ", pilha->array[i]->dado);
    }
    printf("\n");
}

void buscaProfundidadeComCaminhoRec(No* no, int valor, Pilha* caminho, int* numCaminhos) {
    if (no == NULL) {
        return;
    }

    empilhar(caminho, no);

    if (no->dado == valor) {
        (*numCaminhos)++;
        printf("Caminho %d: ", *numCaminhos);
        mostrarCaminho(caminho);
    } else {
        buscaProfundidadeComCaminhoRec(no->esquerda, valor, caminho, numCaminhos);
        buscaProfundidadeComCaminhoRec(no->direita, valor, caminho, numCaminhos);
    }

    desempilhar(caminho);
}

void buscaProfundidadeComCaminho(No* raiz, int valor, int* numCaminhos) {
    Pilha* caminho = criarPilha(100);
    buscaProfundidadeComCaminhoRec(raiz, valor, caminho, numCaminhos);
}

int main() {
    No* no20 = criarNo(20, NULL, NULL);
    No* no19 = criarNo(19, NULL, NULL);
    No* no18 = criarNo(18, NULL, NULL);
    No* no17 = criarNo(17, NULL, NULL);
    No* no16 = criarNo(16, NULL, NULL);
    No* no15 = criarNo(15, NULL, NULL);
    No* no14 = criarNo(14, NULL, NULL);
    No* no13 = criarNo(13, no19, no20);
    No* no12 = criarNo(12, no17, no18);
    No* no11 = criarNo(11, no15, no16);
    No* no10 = criarNo(10, no13, no14);
    No* no9 = criarNo(9, no11, no12);
    No* no8 = criarNo(8, no9, no10);
    No* no7 = criarNo(7, NULL, NULL);
    No* no6 = criarNo(6, NULL, NULL);
    No* no5 = criarNo(5, NULL, NULL);
    No* no4 = criarNo(4, no7, no8);
    No* no3 = criarNo(3, no5, no6);
    No* no2 = criarNo(2, no3, no4);
    No* no1 = criarNo(1, no2, NULL);
    
    int numCaminhos = 0;
    buscaProfundidadeComCaminho(no1, 10, &numCaminhos);

    // Liberar memória (desalocar os nós e a pilha)

    return 0;
}
