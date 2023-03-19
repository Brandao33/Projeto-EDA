#include "gestor.h"
#include "cliente.h"


	VeiculoEletrico* inserirMeio(VeiculoEletrico * inicio, int cod, char tipo[], int bat, float aut,char loc[],int alu)
	{
		
		if (!existeMeio(inicio, cod))
		{
			VeiculoEletrico* novo = malloc(sizeof(VeiculoEletrico));
			if (novo != NULL)
			{
				novo->codigo = cod;
				strcpy(novo->tipo, tipo);
				novo->bateria = bat;
				novo->autonomia = aut;
				strcpy(novo->geocodigo, loc);
				novo->aluguer = alu;
				novo->seguinte = NULL;
				if (inicio == NULL)
				{
					novo->seguinte = inicio;
					return novo;
				}
				else
				{
					VeiculoEletrico* atual = inicio;
					while (atual->seguinte != NULL)
					{
						atual = atual->seguinte;
					}
					novo->seguinte = atual->seguinte;
					atual->seguinte = novo;
				}
			}
			
		}return inicio;
			}
		
	
  
  

	
	int existeMeio(VeiculoEletrico* inicio, int cod)
	{while(inicio!=NULL){if (inicio-> codigo ==cod)
		return (1);
	inicio = inicio->seguinte;
	}
	return (0);
}

	VeiculoEletrico* removerMeio(VeiculoEletrico* inicio, int cod)
	{
		VeiculoEletrico* anterior = NULL, * atual = inicio, * aux;
		if (atual == NULL) return(NULL);
		else if (atual->codigo == cod)
		{
			aux = atual->seguinte;
			free(atual);
			return(aux);
		}
		else
		{
			while ((atual != NULL) && (atual->codigo != cod))
			{
				anterior = atual;
				atual = atual->seguinte;
			}
			if (atual == NULL) return(inicio);
			else {
				anterior->seguinte = atual->seguinte;
				free(atual);
				return(inicio);

			}
		}
	}

	VeiculoEletrico* leituraveiculo()
	{
		VeiculoEletrico* meio = malloc(sizeof(VeiculoEletrico));
		setlocale(LC_ALL, "PORTUGUESE");
		FILE* ficheiro;
		ficheiro = fopen("dadosveiculo.txt", "r");
		if (ficheiro == NULL)
			printf("Erro ao abrir ficheiro.\n");
		else {
			int codigo = 0, bateria = 0, aluguer = 0;
			char tipo[50], geocodigo[50];
			float autonomia = 0;
			while (fscanf(ficheiro, "%d;%[^;]s;%d;%f;%[^;]s;%d\n", &codigo, tipo, &bateria, &autonomia, geocodigo, &aluguer) != EOF)
				inserirMeio(meio, codigo, tipo, bateria, autonomia, geocodigo, aluguer);

		}
		fclose(ficheiro);
		return(meio);
	}
				
	

	gestores* inserirGestores(gestores* inicio, char nome, int codigoG)
	{
		if (!existeGestor(inicio, codigoG))
		{
			gestores* novo = malloc(sizeof(gestores));
			if (novo != NULL)
			{
				strcpy(novo->nome, nome);
				novo->codigoG = codigoG;
				novo->seguinte = NULL;
				if (inicio == NULL)
				{
					novo->seguinte = inicio;
					return novo;
				}
				else
				{
					gestores* atual = inicio;
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
	}

	int existeGestor(gestores* inicio, int codigoG)
	
		{while (inicio != NULL) {
			if (inicio->codigoG == codigoG)
				return 1;
			inicio = inicio->seguinte;
		}
		return 0;
	}
		
	
	void leituragestores() {
		gestores* ges = malloc(sizeof(gestores));


		FILE* ficheiro2;
		ficheiro2 = fopen("dadosgestor.txt", "r");
		if (ficheiro2 == NULL) printf("ERRO AO ABRIR FICHEIRO");
		else {
			char nome[50];
			int codigoG;
			while (fscanf(ficheiro2, "%[^;]s;%d\n", nome, &codigoG)) {
				ges = inserirGestores(ges, nome, codigoG);
			}fclose(ficheiro2);
		}
		return(ges);
	}
	

	int menugestor()

	{
		clientes* clien=NULL;
		VeiculoEletrico* meio=NULL;
		int cod = 0, bat = 0, alu = 0;
		char loc[50], tipo[50], nome[50], morada[50];
		float aut = 0, saldo = 0, NIF = 0;
		
		
		int op2 = 0;
		do {
			char op;
			float carregamento = 0;
			printf("MENU DE GESTOR\n");
			printf("ESCOLHA A OPÇÂO QUE DESEJA:\n");
			printf("\n1-INSERIR MEIO\n2-LISTAR MEIOS\n3-REMOVER MEIO\n4-INSERIR CLIENTE\n5-REMOVER CLIENTE\n6-ALTERAR DADOS DE CLIENTE\n7-Listar clientes\n");
			while (getchar() != '\n');
			if (scanf("%d",&op2) == 1) {
				switch (op2) {
				case 1:
					printf("DIGITE O CÒDIGO DO MEIO\n");
					scanf("%d", &cod);
					//scanf("%*c");
					printf("QUAL O TIPO DE MEIO QUE DESEJA ADICIONAR?\n");
					scanf("%[^\n]s", tipo);
					printf("NIVEL DA BATERIA?\n");
					scanf("%d", &bat);
					printf("QUAL É A SUA AUTONOMIA?\n");
					scanf("%f", &aut);
					meio= inserirMeio(meio,cod,tipo,bat,aut,loc,alu);
					break;
				case 2:
					leituraveiculo(meio);
					listarMeios(meio);
					break;
				case 3:
					//leituraveiculo(meio);
					printf("INDIQUE O CÓDIGO DO MEIO A REMOVER\n");
					scanf("%d", &cod);
					removerMeio(meio, cod);
					break;
				case 4:
					
					//leituraclientes(clien);
					printf("DIGITE O NOME DO CLIENTE\n");
					scanf("%s", &nome);
					//scanf("%*c");
					printf("Deseja carregar o saldo?\n");
					scanf("%c", &op);
					switch (op) {
					case 's':
						printf("Qual a quantia que deseja carregar?\n");
						scanf("%.f", carregamento);
						saldo = saldo + carregamento;
					case 'N':
						break;
					}
					printf("QUAL É O SEU NIF?\n");
					scanf("%f", &NIF);
					printf("QUAL É A SUA MORADA?\n");
					scanf("%s", &morada);
					clien = inserirCliente(clien, nome, saldo, NIF, morada);
					break;
				case 5:
					//leituraclientes(clien);
					printf("INDIQUE O NOME DO CLIENTE A REMOVER\n");
					scanf("%s", &nome);
					clien = removercliente(clien, nome);
					break;
				case 6:
					//leituraclientes(clien);
					editarclientes(clien, nome, saldo, NIF, morada);
					break;
				case 7:
					leituraclientes(clien);
					listarClientes(clien);
					break;
				}
			}
		} while (op2 != 8);
		return 0;
	}
	
	int GuardarMeio(VeiculoEletrico* inicio)
	{
		FILE* ficheiro;
		ficheiro = fopen("dadosveiculo.txt", "w");
		if (ficheiro != NULL) {
			VeiculoEletrico* aux = inicio;
			while (aux != NULL) {
				fprintf(ficheiro, "%d %s %d %f %f %s %d\n", aux->codigo, aux->tipo, aux->bateria, aux->autonomia,
					aux->geocodigo, aux->aluguer);
				aux = aux->seguinte;
			}
			fclose(ficheiro);
			return(1);

			if (ficheiro == NULL)
				return (0);
		}
	}

	void listarMeios(VeiculoEletrico* inicio) {
		VeiculoEletrico* trotinetes = inicio;
		while (trotinetes != NULL) {
			printf("%f %s %d %f\n", trotinetes->codigo, trotinetes->tipo, trotinetes->bateria, trotinetes->autonomia);
			trotinetes = trotinetes->seguinte;
		}
	}

	void listarGestores(gestores* inicio) {

	}


