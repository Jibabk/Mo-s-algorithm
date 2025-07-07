# Explicação do Código - Contagem de Elementos Distintos com Mo's Algorithm

Este código responde a várias consultas sobre quantos elementos distintos existem em um intervalo `[a, b]` de um array. Para isso, utiliza a técnica conhecida como **Mo's Algorithm**, otimizada com **compressão de coordenadas** para lidar com valores grandes eficientemente.

---

## Estrutura geral

### 1. Leitura dos dados

- Lê o tamanho do array `n` e o número de consultas `q`.
- Lê o array original de inteiros.
- Lê as consultas no formato `[a, b]` (convertendo para índices zero-based).

---

### 2. Compressão de coordenadas

- Como os valores do array podem ser muito grandes (até `10^9`), eles são comprimidos para valores menores e contínuos, mantendo a ordem relativa.
- Passos:
  - Cria uma cópia do array original chamada `temp`.
  - Ordena `temp` e remove valores duplicados.
  - Para cada valor do array original, encontra sua posição (índice) em `temp` usando `lower_bound`.
- Essa transformação permite usar um vetor simples `freq` para contar frequências, ao invés de usar mapas.

---

### 3. Mo's Algorithm

- Define o tamanho dos blocos como `block_size = sqrt(n)`.
- Ordena as consultas usando um critério que minimiza o número de movimentos do ponteiro de intervalo (ordem por bloco e alternância na ordenação dos `r`).
- Usa dois ponteiros `cur_l` e `cur_r` para controlar o intervalo atual.
- Para cada consulta, ajusta os ponteiros para o intervalo desejado:
  - Incrementa ou decrementa `cur_l` e `cur_r` adicionando ou removendo elementos do intervalo.
  - Atualiza um contador de quantos elementos únicos existem nesse intervalo.
- Salva o resultado para cada consulta na posição correta.

---

### 4. Funções auxiliares

- `add(idx)`: adiciona o elemento no índice `idx` ao intervalo atual, atualizando `freq` e o contador de elementos únicos (`unique_count`).
- `remove(idx)`: remove o elemento no índice `idx` do intervalo atual, atualizando `freq` e `unique_count`.

---

### 5. Saída

- Imprime o número de elementos distintos para cada consulta na ordem original.

---

## Complexidade

- Compressão: `O(n log n)` devido à ordenação e busca binária.
- Mo's Algorithm: aproximadamente `O((n + q) * sqrt(n))`, eficiente para `n, q` até `2 * 10^5`.

---

## Resumo

- O código resolve consultas de número de elementos distintos em subarrays usando uma técnica avançada (Mo's algorithm).
- A compressão de coordenadas permite manipular valores grandes como índices pequenos para eficiência.
- O algoritmo é otimizado para passar em problemas com limites restritos de tempo e memória.

---