#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
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
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
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

	// insere o elemento em ordem na lista
	NO* anterior = NULL;
	NO* atual = primeiro;

	// verificar se elemento atual é diferente de NULL e menor que o novo elemento digitado
	while (atual != NULL && atual->valor < novo->valor) {
		anterior = atual;
		atual = atual->prox;
	}

	// verifica se valor é duplicado ou não
	if (atual != NULL && atual->valor == novo->valor) {
		cout << "Esse numero ja existe na lista" << endl;
		free(novo);
	}
	else {
		// insere o elemento no inicio da lista
		if (anterior == NULL) {
			primeiro = novo;
		}
		// insere o elemento no anterior
		else {
			anterior->prox = novo;
		}
		novo->prox = atual;
	}
}

void buscarElemento()
{
	int valor;
	cout << "Digite o elemento a ser buscado: ";
	cin >> valor;

	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == valor)
		{
			break;
		}
		aux = aux->prox;
	}

	if (aux == NULL) {
		cout << "ELEMENTO NAO ENCONTRADO" << endl;
	}
	else {
		cout << "ENCONTRADO" << endl;
	}
}

void excluirElemento()
{
	int valor;
	cout << "Digite o elemento a ser excluido: ";
	cin >> valor;

	NO* anterior = NULL;
	NO* atual = primeiro;

	while (atual != NULL && atual->valor < valor) {
		anterior = atual;
		atual = atual->prox;
	}

	if (atual != NULL && atual->valor == valor) {
		/* verifica se o elemento a ser excluido é o primeiro da lista, e se sim define o
		segundo elemento como primeiro da lista */
		if (anterior == NULL) {
			primeiro = atual->prox;
		}
		/* caso não seja o primeiro, define o anterior como o sucessor do numero a ser excluido */
		else {
			anterior->prox = atual->prox;
		}
		free(atual);
		cout << "Elemento excluido" << endl;
	}
	else {
		cout << "Elemento nao encontrado" << endl;
	}
}