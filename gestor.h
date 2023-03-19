#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#pragma once
typedef struct registo
{
	int codigo; // c�digo do meio de mobilidade el�trica
	char tipo[50];
	int bateria;
	float autonomia;
	char geocodigo[50];
	int aluguer;
	struct registo* seguinte; // endere�o de mem�ria para uma struct registo
} VeiculoEletrico;

typedef struct gestor {
	char nome[50];
	int codigoG;
	struct gestor* seguinte;
}gestores;

VeiculoEletrico* inserirMeio(VeiculoEletrico* inicio, int cod, char tipo[], int bat, float aut,char loc[],int alu);

int GuardarMeio(VeiculoEletrico* inicio);

void listarMeios(VeiculoEletrico* inicio);

void listarGestores(gestores* inicio);

int existeMeio(VeiculoEletrico* inicio, int cod);

VeiculoEletrico* removerMeio(VeiculoEletrico* inicio, int cod);

VeiculoEletrico* leituraveiculo();

gestores* inserirGestores(gestores* inicio, char nome, int codigoG);
int existeGestor(gestores* inicio, int codigoG);

void leituragestores(gestores* inicio);
int menugestor();