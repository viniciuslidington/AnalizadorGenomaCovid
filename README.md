# Análise de Genoma do Coronavírus

## Descrição

Este projeto implementa um programa em C++ para analisar o genoma do coronavírus, identificando repetições de segmentos de 6 bases nitrogenadas (A, T, C, G). O objetivo é contar quantas vezes cada segmento aparece no genoma inteiro, considerando blocos consecutivos de 6 caracteres.

## Estrutura do Projeto

* **`main.cpp`** : Implementação principal do programa.
* **`genoma.txt`** : Arquivo de entrada contendo a sequência do genoma do coronavírus.
* **`saida.txt`** : Arquivo de saída contendo os segmentos de 6 bases e sua frequência.
* **`README.md`** : Este arquivo, explicando o funcionamento do projeto.

## Algoritmo Utilizado

* O programa lê o arquivo de entrada linha por linha.
* Cada linha contém 60 caracteres e é dividida em blocos de 6 caracteres.
* Os blocos são armazenados em uma tabela hash implementada com encadeamento externo.
* A função de espalhamento usa o método de Horner.
* O resultado é salvo em um arquivo de saída, listando cada segmento e sua contagem.

## Como Executar

1. **Compilar o código** :

```bash
   g++ main.cpp -o analise_genoma
```

1. **Executar o programa** :

```bash
   ./analise_genoma
```

1. **Verificar o arquivo de saída** :

```bash
   cat saida.txt
```

## Exemplo de Entrada e Saída

### Entrada (`genoma.txt`):

```
ATTAAAGGTTTATACCTTCCCAGGTAACAAACCAACCAACTTTCGATCTCTTGTAGATCT
CAGGTAACAAACCAACCAACTTTCGATCTCTTGTAGATCTGTTTGCCTGTTTTACAGGTA
```

### Saída (`saida.txt`):

```
ATTAAA 3
AGGTTT 2
TTTATA 1
...
```

## Considerações Finais

* A última linha do arquivo de entrada pode ser ignorada se tiver menos de 60 caracteres.
* O tamanho da tabela hash foi definido como um número primo (`10007`) para minimizar colisões.
* A saída é gerada automaticamente após a execução do programa.

Caso tenha dúvidas, sinta-se à vontade para contribuir ou modificar o código! 🚀
