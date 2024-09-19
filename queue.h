#include <iostream>  
#include <string>    

#define MAXTAM 1000  

using namespace std;

// Definição da estrutura Pilha
typedef struct {
    char Item[MAXTAM];  // Array para armazenar os itens da pilha (caracteres)
    int Topo;           // Índice que indica o topo da pilha
} Pilha;

// Declarações das funções
void FPVazia(Pilha *P);  
int Vazia(Pilha *P);     
int Cheia(Pilha *P);     
void Empilha(char x, Pilha *P);  
char Desempilha(Pilha *P);       
char Topo(Pilha *P);             
bool VerificaPalindromo(string cadeia);  // Verifica se uma string é um palíndromo


