#include "Quick.h"
#include <iostream>
#include <cstdlib>

// funcao para preencher o vetor aleatorio - descendente
void preencherVetor(Ordenacao &ord, int tamanho, int modo) {
    ord.vetor.resize(tamanho);
    if (modo == 1) {  // descendente
        for (int i = 0; i < tamanho; i++) {
            ord.vetor[i] = tamanho - i;
        }
    } else {  // aleatorio
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

// implementacaoo do quick 
int particionar(Ordenacao &ord, int low, int high) {
    int pivot = ord.vetor[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        ord.comparacoes++;  // conta a comparacao
        if (ord.vetor[j] <= pivot) {
            i++;
            trocar(ord.vetor[i], ord.vetor[j]);
            ord.trocas++;  // conta  troca
        }
    }
    trocar(ord.vetor[i + 1], ord.vetor[high]);
    ord.trocas++;  // conta  troca
    return i + 1;
}

void quickSort(Ordenacao &ord, int low, int high) {
    if (low < high) {
        int pi = particionar(ord, low, high);

        quickSort(ord, low, pi - 1);  // ordena a parte da esquerda
        quickSort(ord, pi + 1, high);  // ordena a parte da direita
    }
}

// funcao para iniciar o quick e  calcula o tempo de exec
void iniciarQuickSort(Ordenacao &ord) {
    auto start = high_resolution_clock::now(); // inicia o contador 

    quickSort(ord, 0, ord.vetor.size() - 1);

    auto end = high_resolution_clock::now(); // finaliza  contador
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