#include "cliente.h"
#include <stdio.h>
#include "gestor.h"
int main(void) {
	setlocale(LC_ALL, "PORTUGUESE");
	int opcao=0;
	do {
		printf("\nMENU INICIAL\n");
		printf("\nESCOLHA O SEU TIPO DE CONTA\n");
		printf("\n1-Gestor\n2-Cliente\n3-SAIR DO PROGRAMA\n");
		while (getchar() != '\n');
		
		if (scanf("%i", &opcao) == 1) {
			system("cls");
			switch (opcao) {
			case 1:
				menugestor();
				break;
			case 2:
				menucliente();
				break;
			case 3:
				return 0;
			//default:
				system("cls");
				printf("\nEscreveu um n�mero inv�lido\nCarregue  numa tecla para voltar ao Men�\n");
				system("pause");
				system("cls");
				break;
			}
		}
		else  {
			system("cls");
			printf("\nERRO de Leitura\nCarregue  numa tecla para voltar ao men�\n ");
			system("pause");
		
		}
	} while (opcao != 3);
	return 0;
}
		void listarMeios(VeiculoEletrico * inicio);
		
	




