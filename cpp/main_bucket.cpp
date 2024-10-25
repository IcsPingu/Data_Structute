#include <iostream>
#include "Bucket.h"
#include <cstdlib>

int main() {
    Ordenacao ord;
    int tamanho, modo;

    // escolher os numeros de itens a serem ordenados
    cout << "Escolha a quantidade de elementos (10, 100, 1000, 10000): ";
    cin >> tamanho;

    // escolher o modo
    cout << "Escolha o modo de preenchimento (1 = descendente, 2 = aleatório): ";
    cin >> modo;

    preencherVetor(ord, tamanho, modo);

    // exibe o vetor antes da ordenação
    cout << "Vetor antes da ordenação: " << endl;
    exibirVetor(ord);

    // inicia o bucket 
    iniciarBucketSort(ord);

    // exibe o vetor apos a ordenacao
    cout << "Vetor após a ordenação: " << endl;
    exibirVetor(ord);

    // exibe o resultado
    cout << "Tempo de execução: " << ord.tempoExecucao << " segundos" << endl;
    cout << "Comparações: " << ord.comparacoes << endl;
    cout << "Trocas: " << ord.trocas << " (não aplicável para Bucket Sort)" << endl;

    return 0;
}