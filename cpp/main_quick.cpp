#include <iostream>
#include "Quick.h"
#include <cstdlib>

int main() {
    Ordenacao ord;
    int tamanho, modo;

    // valor a ser ordenado
    cout << "Escolha a quantidade de elementos (10, 100, 1000, 10000): ";
    cin >> tamanho;

    // modo de preenchimento do vetor - descente - aleatorio
    cout << "Escolha o modo de preenchimento (1 = descendente, 2 = aleatório): ";
    cin >> modo;

    preencherVetor(ord, tamanho, modo);

    // exibe o vetor antes da ordenacao
    cout << "Vetor antes da ordenação: " << endl;
    exibirVetor(ord);

    // inicia o quick
    iniciarQuickSort(ord);

    // exibe o vetor depois da ordenacao
    cout << "Vetor depois da ordenação: " << endl;
    exibirVetor(ord);

    // exibe 
    cout << "tempo de execução: " << ord.tempoExecucao << " segundos" << endl;
    cout << "comparações: " << ord.comparacoes << endl;
    cout << "trocas: " << ord.trocas << endl;

    return 0;
}