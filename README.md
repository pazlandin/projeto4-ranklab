# RankLab: Central de Ordenação Inteligente

Projeto 4 da disciplina **Algoritmos e Pensamento Computacional**: um programa em C que lê dez pontuações, preserva a sequência original, cria três cópias do vetor e ordena cada uma com **Bubble Sort**, **Selection Sort** e **Insertion Sort**, comparando os resultados.

## Integrantes

| Nome | RGM |
|---|---|
| _preencher_ | _preencher_ |

## Como compilar e executar

```bash
gcc projeto4_ranklab.c -o ranklab
./ranklab
```

No Windows: `gcc projeto4_ranklab.c -o ranklab.exe` e depois `ranklab.exe`.

O programa pede 10 pontuações entre 0 e 100 (separadas por espaço ou Enter). Valores fora desse intervalo são recusados e pedidos novamente.

### Exemplo de execução

```
========== RANKLAB ==========
Digite 10 pontuacoes entre 0 e 100:
78 95 62 88 74 91 55 83 69 100

Original:   78 95 62 88 74 91 55 83 69 100
Bubble:     55 62 69 74 78 83 88 91 95 100
Selection:  55 62 69 74 78 83 88 91 95 100
Insertion:  55 62 69 74 78 83 88 91 95 100

Resultados equivalentes: SIM
Menor: 55 | Maior: 100 | Mediana: 80.50
Comparacoes: Bubble 45 | Selection 45 | Insertion 29
==============================
```

## Organização do código

| Função | Responsabilidade |
|---|---|
| `exibirCabecalho()` | Mostra o título do sistema |
| `lerPontuacoes(v, n)` | Lê e valida as dez pontuações (0 a 100) |
| `copiarVetor(origem, destino, n)` | Cria cópias independentes do vetor original |
| `exibirVetor(v, n)` | Exibe os elementos de um vetor |
| `bubbleSort(v, n)` | Ordena e devolve o total de comparações |
| `selectionSort(v, n)` | Ordena e devolve o total de comparações |
| `insertionSort(v, n)` | Ordena e devolve o total de comparações |
| `vetoresIguais(a, b, n)` | Retorna 1 se os vetores forem iguais e 0 caso contrário |

O `main()` só coordena: declara os vetores, chama as funções na ordem, compara os resultados e calcula menor, maior e mediana. Não há variáveis globais; os vetores são passados por parâmetro.

## Como funciona cada método

**Bubble Sort.** Percorre o vetor comparando cada par de vizinhos e troca os dois quando estão fora de ordem. A cada passada, o maior valor restante "borbulha" até o fim, então a parte final já fica ordenada e a próxima passada vai uma posição a menos. Faz sempre `n(n-1)/2` comparações: 45 para 10 elementos.

**Selection Sort.** Para cada posição `i`, procura o menor elemento entre `i` e o fim do vetor e o coloca em `i` com uma única troca. Também faz sempre `n(n-1)/2` comparações (45), mas no máximo `n-1` trocas.

**Insertion Sort.** Trata o início do vetor como uma parte já ordenada. Pega o próximo elemento e o desloca para a esquerda até achar a posição certa, empurrando os maiores uma casa para a direita. Se o vetor já está quase ordenado, quase não há deslocamentos, por isso é o método mais eficiente nesses casos.

**Como as comparações foram contadas.** Em Bubble e Selection, conta-se cada execução do `if` do laço interno. No Insertion, conta-se cada vez que `v[j]` é comparado com o valor que está sendo inserido. O laço para quando encontra um valor menor ou igual, ou quando chega ao início do vetor. Por isso o resultado do teste 1 é 29, um a mais que o 28 do exemplo do enunciado, que adota outra forma de contar. O enunciado admite essa variação.

## Comparações nos testes obrigatórios

| Teste | Entrada | Bubble | Selection | Insertion |
|---|---|---|---|---|
| 1 - exemplo | 78, 95, 62, 88, 74, 91, 55, 83, 69, 100 | 45 | 45 | 29 |
| 2 - já ordenado | 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 | 45 | 45 | 9 |
| 3 - ordem inversa | 100, 90, 80, 70, 60, 50, 40, 30, 20, 10 | 45 | 45 | 45 |

**Análise.** Bubble e Selection fazem o mesmo número de comparações independentemente da entrada. O Insertion Sort se adapta aos dados: no vetor já ordenado faz só 9 comparações (uma por elemento) e, no pior caso (ordem inversa), chega às mesmas 45 dos outros métodos.

### Outros testes

| Teste | Entrada | Resultado esperado |
|---|---|---|
| 4 - repetidos | 70, 50, 70, 90, 50, 80, 90, 60, 80, 60 | 50, 50, 60, 60, 70, 70, 80, 80, 90, 90 |
| Validação | -5 e depois 75 | Recusa -5 e aceita 75 |

## Capturas de tela

As capturas estão na pasta [`capturas/`](capturas):

- `teste-principal.png`: teste 1 (exemplo)
- `ordem-inversa.png`: teste 3
- `valores-repetidos.png`: teste 4
