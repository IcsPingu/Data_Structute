#include <iostream>
#include "Array.h"

using namespace std;

Lista* AlocarListaMemoria(int numBlocos) {
    Lista* novaLista = (Lista*)malloc(sizeof(Lista));/* alocando espaço na memoria pro tipo lista*/
    if (novaLista == NULL) {/* verifica se foi alocado*/
        cout << "falha ao alocar memoria" << endl;
        return NULL;
    } /* implementação do metodo para liberar a memoria*/

    novaLista->array = (ItemDaLista*)malloc(numBlocos * sizeof(ItemDaLista));/* aloca o tamanho da 
    lista na memoria de acordo com o tamanho especificado pelo numblocos*/
    if (novaLista->array == NULL) {
        cout << "Falha ao alocar memoria " << endl;
        free(novaLista);/*Se não for possivel alocar ele vai liberar*/
        return NULL;
    }

    novaLista->tamanho = 0;
    novaLista->capacidade = numBlocos;
    /*DEfino o tamanho em um padrão default e a capacidade de acordo com o valor de numBlocos*/
    return novaLista;
}

void InserirElemento(ItemDaLista item, Lista* lista) {
    if (lista->tamanho >= lista->capacidade) { /*verifico se a lista ta cheia*/
        cout << "está cheio" << endl;
        return;
    }
    lista->array[lista->tamanho] = item;/* caso a lista não esteja cheia eu insiro o valor no item 
    e incrimento o  tamanho do array*/
    lista->tamanho++;
}

void ExibirElementos(Lista* lista) {
    for (int i = 0; i < lista->tamanho; i++) { /*For pra interar e cuspir cada item*/
        cout << "Elemento " << i + 1 << ": " << lista->array[i].Chave << endl; 
    }
}

void Liberar(Lista* lista) {
    free(lista->array); /*Libero a memoria*/
    free(lista);
}