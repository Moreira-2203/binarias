#include <stdio.h>
#define MAX 15   // tamanho máximo do vetor que representa a árvore

// Estrutura da árvore binária representada por vetor
typedef struct {
    int dados[MAX];
    int tamanho;
} ArvoreBinaria;

// Função para inicializar a árvore
void inicializar(ArvoreBinaria *arvore) {
    arvore->tamanho = 0;
    for(int i = 0; i < MAX; i++) {
        arvore->dados[i] = -1;  // -1 indica posição vazia
    }
}

// Inserir elemento na árvore (seguindo regra de heap)
void inserir(ArvoreBinaria *arvore, int valor) {
    if(arvore->tamanho < MAX) {
        arvore->dados[arvore->tamanho] = valor;
        arvore->tamanho++;
    } else {
        printf("Árvore cheia!\n");
    }
}

// Percurso em pré-ordem (raiz, esquerda, direita)
void preOrdem(ArvoreBinaria *arvore, int indice) {
    if(indice >= arvore->tamanho || arvore->dados[indice] == -1) return;
    printf("%d ", arvore->dados[indice]); // visita raiz
    preOrdem(arvore, 2*indice + 1);      // visita filho esquerdo
    preOrdem(arvore, 2*indice + 2);      // visita filho direito
}

// Percurso em ordem (esquerda, raiz, direita)
void emOrdem(ArvoreBinaria *arvore, int indice) {
    if(indice >= arvore->tamanho || arvore->dados[indice] == -1) return;
    emOrdem(arvore, 2*indice + 1);
    printf("%d ", arvore->dados[indice]);
    emOrdem(arvore, 2*indice + 2);
}

// Percurso em pós-ordem (esquerda, direita, raiz)
void posOrdem(ArvoreBinaria *arvore, int indice) {
    if(indice >= arvore->tamanho || arvore->dados[indice] == -1) return;
    posOrdem(arvore, 2*indice + 1);
    posOrdem(arvore, 2*indice + 2);
    printf("%d ", arvore->dados[indice]);
}

int main() {
    ArvoreBinaria arvore;
    inicializar(&arvore);

    // Inserindo valores
    inserir(&arvore, 10);  // raiz
    inserir(&arvore, 5);   // filho esquerdo
    inserir(&arvore, 15);  // filho direito
    inserir(&arvore, 3);   // filho esquerdo de 5
    inserir(&arvore, 7);   // filho direito de 5

    printf("Percurso em pré-ordem: ");
    preOrdem(&arvore, 0);
    printf("\n");

    printf("Percurso em ordem: ");
    emOrdem(&arvore, 0);
    printf("\n");

    printf("Percurso em pós-ordem: ");
    posOrdem(&arvore, 0);
    printf("\n");

    return 0;
}
