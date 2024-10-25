#include "selection.h"
#include <iostream>
#include <cstdlib>

void preencherVetor(Ordenacao &ord, int tamanho, int modo) {
    ord.vetor.resize(tamanho);
    if (modo == 1) {  // descendente
        for (int i = 0; i < tamanho; i++) {
            ord.vetor[i] = tamanho - i;
        }
    } else {  // aleatório
        for (int i = 0; i < tamanho; i++) {
            ord.vetor[i] = rand() % tamanho;
        }
    }
}

// funcao de troca
void trocar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// implementacao do selection
void selectionSort(Ordenacao &ord) {
    int n = ord.vetor.size();
    auto start = high_resolution_clock::now(); // inicia o contador

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            ord.comparacoes++;  // conta a comparacao
            if (ord.vetor[j] < ord.vetor[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            trocar(ord.vetor[i], ord.vetor[minIndex]);
            ord.trocas++;  // conta aa troca
        }
    }

    auto end = high_resolution_clock::now(); // finaliza o contador 
    duration<double> diff = end - start;
    ord.tempoExecucao = diff.count(); // calcula  tempo de exec
}

// funcao para exibir o vetor
void exibirVetor(const Ordenacao &ord) {
    for (int i = 0; i < ord.vetor.size(); i++) {
        cout << ord.vetor[i] << " ";
    }
    cout << endl;
}