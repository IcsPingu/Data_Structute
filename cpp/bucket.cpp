#include <iostream>
#include "Bucket.h"


// funcao para preencher o vetor com valores aleatorio - descendente
void preencherVetor(Ordenacao &ord, int tamanho, int modo) {
    ord.vetor.resize(tamanho);
    if (modo == 1) {  // descendente
        for (int i = 0; i < tamanho; i++) {
            ord.vetor[i] = tamanho - i;
        }
    } else {  // aleatorio
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(0, tamanho - 1);
        for (int i = 0; i < tamanho; i++) {
            ord.vetor[i] = distribution(generator);
        }
    }
}

// funcao de exibir do vetor
void exibirVetor(const Ordenacao &ord) {
    for (int i = 0; i < ord.vetor.size(); i++) {
        cout << ord.vetor[i] << " ";
    }
    cout << endl;
}

// funcao para o bucket
void bucketSort(Ordenacao &ord) {
    int n = ord.vetor.size();
    if (n <= 0) return;

    // encontra o valor max no vetor para definir o intervalo de buckets
    int max_val = *max_element(ord.vetor.begin(), ord.vetor.end());

    // inicia os buckets
    vector<vector<int>> buckets(n);

    // distribui os itens nos buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (n * ord.vetor[i]) / (max_val + 1);  // calcula o bucket
        buckets[bucketIndex].push_back(ord.vetor[i]);
    }

    // ordena cada bucket e junta
    ord.vetor.clear();
    for (int i = 0; i < buckets.size(); i++) {
        // ordena o bucket 
        ord.comparacoes += buckets[i].size() * (buckets[i].size() - 1) / 2; 
        std::sort(buckets[i].begin(), buckets[i].end()); 

        for (int j = 0; j < buckets[i].size(); j++) {
            ord.vetor.push_back(buckets[i][j]);
        }
    }
}

// funcao para iniciar o bucket e calcular o tempo de exec
void iniciarBucketSort(Ordenacao &ord) {
    auto start = high_resolution_clock::now();  // inicia o contador

    bucketSort(ord);

    auto end = high_resolution_clock::now();  // finaliza o contador
    duration<double> diff = end - start;
    ord.tempoExecucao = diff.count();  // calcula o tempo de exec
}