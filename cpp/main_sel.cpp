//Alunos: João Gonçalves Matricula: 202311140017/ Thiago Ribeiro Matricula: 202311140009
#include <iostream>
#include "selection.h"
#include <cstdlib>

int main() {
    Ordenacao ord;
    int tamanho, modo;

    cout << "Escolha a quantidade de elementos (10, 100, 1000, 10000): ";
    cin >> tamanho;

    cout << "Escolha o modo de preenchimento (1 = descendente, 2 = aleatório): ";
    cin >> modo;

    preencherVetor(ord, tamanho, modo);

    cout << "Vetor antes da ordenação: " << endl;
    exibirVetor(ord);

    selectionSort(ord);

    cout << "Vetor após a ordenação: " << endl;
    exibirVetor(ord);

    
    cout << "Tempo de execução: " << ord.tempoExecucao << " segundos" << endl;
    cout << "Comparações: " << ord.comparacoes << endl;
    cout << "Trocas: " << ord.trocas << endl;

    return 0;
}
