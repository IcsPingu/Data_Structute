#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <algorithm>  
#include <random>  
#include <cstdlib>

using namespace std;
using namespace std::chrono;

// struct para criar o vetor de ordenacao
struct Ordenacao {
    vector<int> vetor;
    long comparacoes = 0;
    long trocas = 0;
    double tempoExecucao = 0.0;
};

void preencherVetor(Ordenacao &ord, int tamanho, int modo);
void trocar(int &a, int &b);
int particionar(Ordenacao &ord, int low, int high);
void quickSort(Ordenacao &ord, int low, int high);
void iniciarQuickSort(Ordenacao &ord);
void exibirVetor(const Ordenacao &ord);