#include "queue.h"  

// Função para inicializar a pilha vazia
void FPVazia(Pilha *P) {
    P->Topo = -1;  // Define o topo da pilha como -1, indicando que está vazia
}

// Função para verificar se a pilha está vazia
int Vazia(Pilha *P) {
    return (P->Topo == -1);  // Retorna 1 se o topo for -1, indicando que está vazia
}

// Função para verificar se a pilha está cheia
int Cheia(Pilha *P) {
    return (P->Topo == MAXTAM - 1);  // Retorna 1 se o topo for o último índice da pilha
}

// Função para empilhar um caractere na pilha
void Empilha(char x, Pilha *P) {
    if (Cheia(P)) {  // Verifica se a pilha está cheia
        cout << "Erro: Pilha cheia!" << endl;  
    } else {
        P->Topo++;  // Incrementa o topo da pilha
        P->Item[P->Topo] = x;  // Adiciona o caractere no topo da pilha
    }
}

// Função para desempilhar o caractere do topo da pilha
char Desempilha(Pilha *P) {
    if (Vazia(P)) {  // Verifica se a pilha está vazia
        cout << "Erro: Pilha vazia!" << endl; 
        return 0; 
    } else {
        char temp = P->Item[P->Topo];  // Armazena o caractere do topo
        P->Topo--;  // Decrementa o topo da pilha
        return temp; 
    }
}

// Função para retornar o caractere no topo da pilha sem removê-lo
char Topo(Pilha *P) {
    if (Vazia(P)) {  // Verifica se a pilha está vazia
        cout << "Erro: Pilha vazia!" << endl;  // Exibe uma mensagem de erro se a pilha estiver vazia
        return 0;  // Retorna 0 como valor de erro
    } else {
        return P->Item[P->Topo];  // Retorna o caractere no topo da pilha
    }
}

// Função para verificar se uma string é um palíndromo
bool VerificaPalindromo(string cadeia) {
    Pilha P;
    FPVazia(&P);  // Inicializa uma pilha vazia

    // Empilha todos os caracteres da string na pilha
    for (int i = 0; i < cadeia.length(); i++) {
        Empilha(cadeia[i], &P);
    }

    // Desempilha e compara os caracteres da string com os da pilha
    for (int i = 0; i < cadeia.length(); i++) {
        char topo = Desempilha(&P);  // Desempilha o caractere do topo
        if (cadeia[i] != topo) {  // Compara com o caractere correspondente da string original
            return false;  // Retorna falso se algum caractere não corresponder
        }
    }

    return true;  // Retorna verdadeiro se todos os caracteres corresponderem, indicando que é um palíndromo
}

