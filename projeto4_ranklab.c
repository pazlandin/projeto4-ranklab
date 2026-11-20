/*
 * Projeto 4 - RankLab: Central de Ordenacao Inteligente
 * Algoritmos e Pensamento Computacional
 *
 * Le 10 pontuacoes (0 a 100), preserva o vetor original, cria tres copias
 * independentes e ordena cada uma com Bubble Sort, Selection Sort e
 * Insertion Sort, comparando os resultados e o numero de comparacoes.
 */
#include <stdio.h>

#define TAM 10

/* ---------- Prototipos ---------- */
void exibirCabecalho(void);
void lerPontuacoes(int v[], int n);
void copiarVetor(int origem[], int destino[], int n);
void exibirVetor(int v[], int n);
int bubbleSort(int v[], int n);
int selectionSort(int v[], int n);
int insertionSort(int v[], int n);
int vetoresIguais(int a[], int b[], int n);

/* ---------- Programa principal ---------- */
int main() {
    int pontuacoes[TAM];
    int bubble[TAM], selection[TAM], insertion[TAM];
    int compBubble, compSelection, compInsertion;
    int equivalentes;
    float mediana;

    exibirCabecalho();
    lerPontuacoes(pontuacoes, TAM);

    /* Copias independentes: o vetor original nunca e alterado */
    copiarVetor(pontuacoes, bubble, TAM);
    copiarVetor(pontuacoes, selection, TAM);
    copiarVetor(pontuacoes, insertion, TAM);

    compBubble = bubbleSort(bubble, TAM);
    compSelection = selectionSort(selection, TAM);
    compInsertion = insertionSort(insertion, TAM);

    printf("\nOriginal:   ");
    exibirVetor(pontuacoes, TAM);
    printf("Bubble:     ");
    exibirVetor(bubble, TAM);
    printf("Selection:  ");
    exibirVetor(selection, TAM);
    printf("Insertion:  ");
    exibirVetor(insertion, TAM);

    equivalentes = vetoresIguais(bubble, selection, TAM) &&
                   vetoresIguais(bubble, insertion, TAM);

    /* Calculos apos a ordenacao (usando o vetor do Bubble Sort) */
    mediana = (bubble[4] + bubble[5]) / 2.0f;

    printf("\nResultados equivalentes: %s\n", equivalentes ? "SIM" : "NAO");
    printf("Menor: %d | Maior: %d | Mediana: %.2f\n",
           bubble[0], bubble[TAM - 1], mediana);
    printf("Comparacoes: Bubble %d | Selection %d | Insertion %d\n",
           compBubble, compSelection, compInsertion);
    printf("==============================\n");

    return 0;
}

/* ---------- Funcoes ---------- */

/* Exibe o titulo do sistema */
void exibirCabecalho(void) {
    printf("========== RANKLAB ==========\n");
}

/* Le n pontuacoes, aceitando apenas valores entre 0 e 100 */
void lerPontuacoes(int v[], int n) {
    int i;

    printf("Digite %d pontuacoes entre 0 e 100:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        while (v[i] < 0 || v[i] > 100) {
            printf("Pontuacao invalida (%d)! Digite um valor entre 0 e 100: ", v[i]);
            scanf("%d", &v[i]);
        }
    }
}

/* Copia os n elementos de origem para destino */
void copiarVetor(int origem[], int destino[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

/* Mostra os elementos do vetor na mesma linha */
void exibirVetor(int v[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

/*
 * Bubble Sort: compara elementos vizinhos e troca quando estao fora de
 * ordem. A cada passada o maior valor restante "sobe" para o final.
 * Retorna a quantidade de comparacoes realizadas.
 */
int bubbleSort(int v[], int n) {
    int i, j, aux, comparacoes = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            comparacoes++;
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }

    return comparacoes;
}

/*
 * Selection Sort: para cada posicao, procura o menor elemento da parte
 * ainda nao ordenada e o coloca nessa posicao com uma unica troca.
 * Retorna a quantidade de comparacoes realizadas.
 */
int selectionSort(int v[], int n) {
    int i, j, indiceMenor, aux, comparacoes = 0;

    for (i = 0; i < n - 1; i++) {
        indiceMenor = i;
        for (j = i + 1; j < n; j++) {
            comparacoes++;
            if (v[j] < v[indiceMenor]) {
                indiceMenor = j;
            }
        }
        if (indiceMenor != i) {
            aux = v[i];
            v[i] = v[indiceMenor];
            v[indiceMenor] = aux;
        }
    }

    return comparacoes;
}

/*
 * Insertion Sort: pega um elemento por vez e o insere na posicao correta
 * da parte ja ordenada, deslocando os maiores uma casa para a direita.
 * Conta uma comparacao a cada vez que v[j] e comparado com o valor atual.
 * Retorna a quantidade de comparacoes realizadas.
 */
int insertionSort(int v[], int n) {
    int i, j, atual, comparacoes = 0;

    for (i = 1; i < n; i++) {
        atual = v[i];
        j = i - 1;

        while (j >= 0) {
            comparacoes++;
            if (v[j] > atual) {
                v[j + 1] = v[j];
                j--;
            } else {
                break;
            }
        }

        v[j + 1] = atual;
    }

    return comparacoes;
}

/* Retorna 1 se os dois vetores forem iguais e 0 caso contrario */
int vetoresIguais(int a[], int b[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }

    return 1;
}
