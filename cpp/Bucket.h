#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <algorithm>  
#include <random>  
#include <cstdlib>

using namespace std;
using namespace std::chrono;

// struct para armazenar o vetor de ordenacao
struct Ordenacao {
    vector<int> vetor;
    long comparacoes = 0;
    long trocas = 0;
    double tempoExecucao = 0.0;
};

void preencherVetor(Ordenacao &ord, int tamanho, int modo);
void exibirVetor(const Ordenacao &ord);
void bucketSort(Ordenacao &ord);
void iniciarBucketSort(Ordenacao &ord);