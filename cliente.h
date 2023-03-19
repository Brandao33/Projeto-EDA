#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "gestor.h"


typedef struct cliente
{
	char nome[50];
	float saldo;
	float NIF;
	char morada[100];
	struct cliente* seguinte;
} clientes;

int Guardarcliente(clientes* inicio);
clientes* inserirCliente(clientes* inicio, char nome[], float saldo, float NIF, char morada[]);
void listarClientes(clientes* inicio);
void leituraclientes(clientes* inicio);
void editarclientes(clientes* inicio, char* nome, float saldo, float NIF, char* morada);
int existecliente(clientes* inicio, char* nome);
clientes* removercliente(clientes* inicio, char*nome);
int menucliente();