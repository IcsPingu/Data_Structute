#include "queue.h"  

int main() {
    Pilha P;         // Declara uma pilha (Pilha)
    FPVazia(&P);     // Inicializa a pilha para que ela fique vazia

    int option = 0;  // Variável para armazenar a opção do menu escolhida pelo usuário
    string input_string;  // Variável para armazenar a string inserida pelo usuário

    // Loop principal para exibir as opções do menu e realizar operações na pilha
    while (option != 4) {  
        cout << "\nMenu: \n";  // Exibe o menu
        cout << "1. Empilhar uma string\n";
        cout << "2. Desempilhar o caractere do topo\n";
        cout << "3. Mostrar o caractere no topo\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> option;  // Recebe a opção do usuário
        
        if (option == 1) {
            cout << "Digite uma cadeia de caracteres para empilhar: ";
            cin >> input_string;  // Recebe a string do usuário
            for (char ch : input_string) {
                Empilha(ch, &P);  // Empilha cada caractere da string na pilha
            }
            
            if (VerificaPalindromo(input_string)) {
              cout << "Verdadeiro: A cadeia é um palíndromo." << endl;
            } else {
              cout << "Falso: A cadeia não é um palíndromo." << endl;
            }
         
        } else if (option == 2) {
            if (!Vazia(&P)) {  // Verifica se a pilha não está vazia
                cout << "Caractere desempilhado: " << Desempilha(&P) << endl;  // Desempilha o caractere do topo e exibe
            } else {
                cout << "Pilha vazia!" << endl;  // Informa que a pilha está vazia
            }
        

        } else if (option == 3) {
            if (!Vazia(&P)) {  
                cout << "Caractere no topo: " << Topo(&P) << endl;  // Exibe o caractere no topo da pilha
            } else {
                cout << "Pilha vazia!" << endl;  
            }
        
        } else if (option == 4) {
            cout << "Saindo...\n";  // Mensagem de saída
        
        // Caso o usuário insira uma opção inválida
        } else {
            cout << "Opção inválida. Tente novamente.\n";  // Informa que a opção é inválida e pede para tentar novamente
        }
    }
    return 0;  
}

