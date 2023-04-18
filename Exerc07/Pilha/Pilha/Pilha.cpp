#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
	NO* ant;
};

NO* topo = NULL;

// headers
void menu();
void inicializar();
void pop();
void push();
void exibirElementos();
//--------------------------

int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 5) {
		system("cls"); // somente no windows
		cout << "Menu Pilha";
		cout << endl << endl;
		cout << "1 - Inicializar Pilha \n";
		cout << "2 - Inserir elemento (Push) \n";
		cout << "3 - Remover elementos (Pop) \n";
		cout << "4 - Exibir elementos \n";
		cout << "5 - Sair \n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:push();
			break;
		case 3: pop();
			break;
		case 4: exibirElementos();
			break;
		case 5:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = topo;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	topo = NULL;
	cout << "Pilha inicializada \n";
}

void push()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;
	novo->ant = NULL;

	if (topo == NULL)
	{
		topo = novo;
	}
	else
	{
		novo->ant = topo;
		topo->prox = novo;
		topo = novo;
	}
}

void pop()
{
	if (topo == NULL) {
		cout << "A lista esta vazia" << endl;
	}
	else
	{
		NO* excluir = topo;
		topo = topo->ant;
		if (topo != NULL) {
			topo->prox = NULL;
		}
		free(excluir);

		cout << "Ultimo elemento excluido com sucesso" << endl;
	}
}

void exibirElementos()
{
	if (topo == NULL) {
		cout << "Pilha vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = topo;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->ant;
		}
	}
}