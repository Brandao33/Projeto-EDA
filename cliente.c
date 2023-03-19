#include "cliente.h"




int Guardarcliente(clientes* inicio)
{
	FILE* ficheiro;
	ficheiro = fopen("dadoscliente.txt", "w");
	if (ficheiro != NULL) {
		clientes* aux = inicio;
		while (aux != NULL) {
			fprintf(ficheiro, "%s;%.f;%f;%s\n", aux->nome, aux->saldo, aux->NIF, aux->morada);
			aux = aux->seguinte;
		}

		fclose(ficheiro);
	
	return(1);
}
	if (ficheiro == NULL)
		return (0);
	return 0;
}

clientes* inserirCliente(clientes* inicio, char nome[], float saldo, float NIF, char morada[])
{
	
	if (!existecliente(inicio,nome)) {

		clientes* novo = malloc(sizeof(clientes));
		if (novo != NULL)
		{
			strcpy(novo->nome, nome);
			novo->saldo = saldo;
			novo->NIF = NIF;
			strcpy(novo->morada, morada);
			novo->seguinte = inicio;
			return(novo);
		}
		if (inicio == NULL)
		{
			novo->seguinte = inicio;
			return novo;
		}
		else
		{
			clientes* atual = inicio;
			while (atual->seguinte != NULL)
			{
				atual = atual->seguinte;
			}
			novo->seguinte = atual->seguinte;
			atual->seguinte = novo;
		}
	}
	return inicio;
}
			
	

void listarClientes(clientes* inicio)
{
	clientes* Cliente = inicio;
	while (Cliente != NULL) {
		printf("%s;%f;%f;%s\n", Cliente->nome, Cliente->saldo, Cliente->NIF, Cliente->morada);
		Cliente = Cliente->seguinte;
	}
}

int existecliente(clientes* inicio, char*nome)
{
	while (inicio != NULL) {
		if (inicio->nome == nome)
			return 1;
		inicio = inicio->seguinte;
	}
	return 0;
}

clientes* removercliente(clientes* inicio, char* nome)
{
	return ;
}

void leituraclientes(clientes* inicio)
{
	char nome[50];
	float saldo, NIF;
	char morada[100];
	clientes* Cliente = NULL;
	FILE* ficheiro1;
	ficheiro1 = fopen("dadoscliente.txt", "r");
	if (ficheiro1 = NULL) printf("ERRO AO ABRIR O FICHEIRO");
	else {
		while  (fscanf(ficheiro1, " %s;%f;%f;%s\n", nome, &saldo, &NIF, morada) == 4) {
			Cliente = inserirCliente(Cliente, nome, saldo, NIF, morada);
			
		}fclose(ficheiro1);
	}return(Cliente);
}

void editarclientes(clientes* inicio, char nome, float saldo, float NIF, char* morada)
{
	float carregamento=0;
	char op;
	if (inicio != NULL) {
		printf("Nome do cliente:%s\n", nome);
		printf("Alterar o Nome? (S/N):");
		scanf("%c", &op);
		switch (op) {
		case 'S':
			printf("Insira o nome do cliente:\n");
			scanf("%s", nome);
			break;
		case 'N':
			break;
		}
		printf("Saldo atual:%.f", saldo);
		printf("Deseja carregar o saldo? (S/N):\n");
		scanf("%c", &op);
		switch (op) {
		case 's':
			printf("Qual a quantia que deseja carregar?\n");
			scanf("%.f", carregamento);
			saldo = saldo + carregamento;
		case 'N':
			break;
		}
		printf("Alterar o NIF? (S/N): ");
		fflush(stdin);
		scanf("%c", &op);
		switch (op)
		{
		default:
		case 'S':
			printf("Insira o NIF do cliente:\n");
			scanf("%f", NIF);
		case 'N':
			break;
		}
		printf("Morada atual:%s\n", morada);
		printf("Deseja alterar? (S/N):\n");
		scanf("%c", &op);
		switch (op) {
		case 'S':
			printf("Insira a nova morada:\n");
			fgets(morada, 50, stdin);
		case 'N':
			break;
		}
	}
}
int menucliente(){
	char nome[50];
	float saldo=0, NIF=0;
	char morada[100];
	clientes* clien = NULL;
	int op1 = 0;
do {
	printf("\nMENU DE CLIENTE\n");
	printf("\nESCOLHA A OPÇÂO QUE DESEJA:\n");
	printf("\n1-INSERIR NOVO CLIENTE\n2-LISTAR MEIOS DISPONIVEIS\n3-ALUGAR UM MEIO\n4-VOLTAR AO INICIO\n");
	while (getchar() != '\n');
	if (scanf(op1 == 1)); {
		switch (op1) {
		case 1:
			inserirCliente(clien,nome, saldo, NIF, morada);
			Guardarcliente(clien);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			return 0;
		}
	}
} while (op1 != 4);
}