#include <iostream>

typedef struct {
    int Chave;
} ItemDaLista; /* function para criar o info*/

typedef struct {
    ItemDaLista* array;
    int tamanho;
    int capacidade;
} Lista; /* function para criar a lista*/

Lista* AlocarListaMemoria(int);/*Metodo abstrato para alocar memoria do array*/
void InserirElemento(ItemDaLista , Lista* );/*metodo abstrato para inserir o elemento em um posição da lista*/
void ExibirElementos(Lista*);/*metodo para exibir os elementos*/
void Liberar(Lista*);/* metodo pra liberar da memoria*/
