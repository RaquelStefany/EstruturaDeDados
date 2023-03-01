// Exerc01.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
using namespace std;

int main()
{
    double nota1 = 0, nota2 = 0, media = 0;
    string nome;

    cout << "Digite seu nome: ";
    cin >> nome;

    do {
        cout << "Digite a 1 nota: ";
        cin >> nota1;
    } while (nota1 < 0 || nota1 > 10);

    do {
        cout << "Digite a 2 nota: ";
        cin >> nota2;
    } while (nota2 < 0 || nota2 > 10);

    media = (nota1 + nota2) / 2;
    cout << "\nMedia: " << media << "\n";

    if (media >= 6) {
        cout << nome << " foi Aprovado\n";
    }
    else {
        cout << nome << " foi Reprovado\n";
    }
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
