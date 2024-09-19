#include <iostream>
#include "Array.h"

int main() {
    int numBlocos = 6; /*tamano do array e blocos de memoria*/
    Lista* minhaLista = AlocarListaMemoria(numBlocos);

    if (minhaLista != NULL) {
        for (int i = 0; i < numBlocos; i++) {
            ItemDaLista item;
            item.Chave = i + 1;
            InserirElemento(item, minhaLista); /*definindo cada item*/
        }

        
        ExibirElementos(minhaLista);/*exibindo os elements*/

        
        Liberar(minhaLista);/*liberando memoria depois do uso*/
    }

    return 0;
}