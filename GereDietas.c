/**
 * @file GereDietas.c
 * @author Pedro Ribeiro, Ricardo Fernandes, Carolina Branco (a27960@alunos.ipca.pt a279861@alunos.ipca.pt a27983@alunos.ipca.pt)
 * @brief
 * @version 0.1
 * @date 2023-12-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma warning (disable: 4996)
#include "Dados.h"

#pragma region T�PICO 1. b.

 /**
  * @brief Exporta os dados das dietas para um ficheiro CSV ou TXT.
  *
  * Esta fun��o recebe um nome de um ficheiro e um array de structs Dieta,
  * e exporta os dados das dietas para o ficheiro.
  *
  * @param fileName � o nome do ficheiro que vai ser feita a exporta��o.
  * @param dietas � o array de structs Dieta contendo os dados a serem exportados.
  * @param maximodietas N�mero m�ximo de dietas no array.
  * @return Retorna true se a exporta��o for bem sucedida, false caso contr�rio.
  */

bool ExportaDadosDieta(char fileName[], Dieta dietas[], int maximodietas) {
	FILE* fp;
	fp = fopen(fileName, "w"); //Abre o ficheiro para escrita, usado o caracter "w" para apagar o que estiver escrito e escrever depois o pedido
	if (fp == NULL) return false; //Caso n�o seja poss�vel abrir o ficheiro retorna false
	for (int i = 0; i < maximodietas; i++) {
		// O ciclo for itera sobre o array dietas e vai escrevendo o mesmo no ficheiro, no formato CSV.
		fprintf(fp, "%d;%s;%s;%d;%s;%d cal\n", dietas[i].numpaciente, dietas[i].datainicio, dietas[i].datafim, dietas[i].tp, dietas[i].alimento, dietas[i].calorias);

	}
	fclose(fp);
	return true;
	//Fecha o ficheiro e devolve true
}

#pragma endregion

/*
#pragma region T�PICO 1. b. (extra)
/**
 * @brief L� os dados das dietas de um ficheiro CSV ou TXT.
 *
 * Esta fun��o recebe um nome de ficheiro e l� os dados das dietas do ficheiro no formato CSV ou TXT.
 * Os dados lidos s�o armazenados num array de structs Dieta.
 *
 * @param fileName � o nome do ficheiro para leitura.
 * @param dietas � o array de structs Dieta para armazenar os dados lidos.
 * @param maximodietas � o n�mero m�ximo de dietas no array.
 * @return Retorna true se a leitura for bem sucedida, false caso contr�rio.
 *

bool LeDadosDieta(char fileName[], Dieta dietas[], int maximodietas) {
	FILE* fp;
	fp = fopen(fileName, "r");//Abre o ficheiro para leitura
	if (fp == NULL) return false;
	int i = 0;
	while (i < maximodietas) {
		// Uso de um ciclo para iterar pelo o array, podendo assim ler os dados do arquivo e armazenar no array de dietas
		fscanf(fp, "%d;%[^;];%[^;];%d;%[^;];%d", &dietas[i].numpaciente, dietas[i].datainicio, dietas[i].datafim, &dietas[i].tp, dietas[i].alimento, &dietas[i].calorias);
		i++;
		if (feof(fp)) break; //Condi��o de paragem
	}
	fclose(fp);
	return true;
}
#pragma endregion
*/

#pragma region T�PICO 1. c.

/**
 * @brief Exporta os dados do plano nutricional para um ficheiro CSV ou TXT.
 *
 * Esta fun��o recebe um nome de ficheiro e exporta os dados do plano nutricional
 * para o ficheiro no formato CSV ou TXT.
 *
 * @param fileName � o nome do ficheiro para exporta��o.
 * @param plano � o array de structs PlanoNutri contendo os dados a serem exportados.
 * @param maximodietas � o n�mero m�ximo de planos nutricionais no array.
 * @return Retorna true se a exporta��o for bem sucedida, false caso contr�rio.
 */

 //Esta fun��o tem a mesma estrutura que a realizada no ponto 1- b)

bool ExportaDadosPlanoNutri(char fileName[], PlanoNutri plano[], int maximodietas) {
	FILE* fp;
	fp = fopen(fileName, "w");
	if (fp == NULL) return false;
	for (int i = 0; i < maximodietas; i++) {
		fprintf(fp, "%d;%s;%s;%d;%d cal;%d cal\n", plano[i].numpaciente, plano[i].datainicio, plano[i].datafim, plano[i].tp, plano[i].caloriasMin, plano[i].caloriasMax);
	}
	fclose(fp);
	return true;
}

#pragma endregion

/*
#pragma region TOPICO 1. c. (extra)

/**
 * @brief L� os dados dos planos nutricionais de um ficheiro e armazena-os num array de estruturas PlanoNutri.
 *
 * Esta fun��o recebe um nome de ficheiro e l� os dados das dietas do ficheiro no formato CSV ou TXT.
 * Os dados lidos s�o armazenados num array de structs PlanoNutri.
 *
 * @param fileName � o nome do ficheiro a ser lido.
 * @param plano � o array de estruturas PlanoNutri para armazenar os dados lidos.
 * @param maximodietas � o n�mero m�ximo de dietas a serem lidas do arquivo.
 * @return Retorna true se a leitura for bem sucedida, false caso contr�rio.
 *

bool LeDadosPlanosNutri(char fileName[], PlanoNutri plano[], int maximodietas) {
	FILE* fp;
	fp = fopen(fileName, "r");//Abre o ficheiro para leitura
	if (fp == NULL) return false;
	int i = 0;
	while (i < maximodietas) {
		// Uso de um ciclo para iterar pelo o array, podendo assim ler os dados do ficheiro e armazenar no array de dietas
		fscanf(fp, "%d;%[^;];%[^;];%d;%d;%d\n", &plano[i].numpaciente, plano[i].datainicio, plano[i].datafim, &plano[i].tp, &plano[i].caloriasMin, &plano[i].caloriasMax);
		i++;
		if (feof(fp)) break; //Condi��o de paragem
	}
	fclose(fp);
	return true;
}

#pragma endregion
*/

#pragma region T�PICO 2

/**
 * @brief Conta o n�mero de pacientes cujo consumo de calorias ultrapassa o limite definido no plano nutricional.
 *
 * Esta fun��o percorre os arrays de planos nutricionais e dietas e conta quantos pacientes ultrapassaram
 * o limite de calorias definido no plano nutricional para a respectiva refei��o.
 *
 * @param plano � o array de structs PlanoNutri contendo os dados dos planos nutricionais.
 * @param dietas � o array de structs Dieta contendo os dados das dietas.
 * @param maximopacientes � o n�mero m�ximo de pacientes nos arrays.
 * @return Retorna o n�mero de pacientes cujo consumo de calorias ultrapassa o limite definido no plano nutricional.
 */

int NumPacientesUltrapassamCal(PlanoNutri plano[], Dieta dietas[], int maximopacientes) {
	int contador = 0;
	for (int i = 0; i < maximopacientes; i++) {  // Itera sobre o array de pacientes
		if (dietas[i].calorias > plano[i].caloriasMax) {
			contador++; // Se o consumo de calorias na dieta atual excede o limite definido no plano � somado 1 unidade � vari�vel contador 

		}
	}
	return contador;
	// Retorna o n�mero total de pacientes cujo consumo de calorias ultrapassa o limite
}

#pragma endregion

#pragma region T�PICO 3

/**
 * @brief Identifica os pacientes cujo consumo de calorias est� fora do intervalo definido no plano nutricional.
 *
 * Esta fun��o percorre os arrays de planos nutricionais, dietas e dados dos pacientes,
 * identificando os pacientes cujo consumo de calorias est� fora do intervalo definido
 * pelo plano nutricional. Os pacientes identificados s�o armazenados na struct NaoCumpPaciente.
 *
 * @param plano � o array de structs PlanoNutri contendo os dados dos planos nutricionais.
 * @param dietas � o array de structs Dieta contendo os dados das dietas.
 * @param dados � o array de structs Paciente contendo os dados dos pacientes.
 * @param dadospacientes � o array de structs NaoCumpPaciente que armazenar� os dados dos pacientes que n�o cumprem.
 * @param maxpaciente � o n�mero m�ximo de pacientes nos arrays.
 */

void IdentificaForaIntervalo(PlanoNutri plano[], Dieta dietas[], Paciente dados[], NaoCumpPaciente dadospacientes[], int maxpaciente) {
	int num = 0;

	for (int i = 0; i < maxpaciente; i++) {
		// Verifica se o consumo de calorias est� fora do intervalo definido no plano
		if (dietas[i].calorias > plano[i].caloriasMax || dietas[i].calorias < plano[i].caloriasMin) {
			// Armazena os dados dos pacientes que n�o cumprem as condi��es
			dadospacientes[num].numpaciente = dados[i].numpaciente;
			strcpy(dadospacientes[num].nome, dados[i].nome);
			dadospacientes[num].telefone = dados[i].telefone;
			num++;
		}
	}
}

/**
 * @brief Ordena os pacientes fora do intervalo com base no n�mero do paciente.
 *
 * Esta fun��o ordena o array de pacientes fora do intervalo
 * na struct NaoCumpPaciente com base no n�mero do paciente em ordem decrescente.
 *
 * @param dadospacientes � o array de structs NaoCumpPaciente a ser ordenado.
 * @param maxpaciente � o n�mero m�ximo de pacientes no array.
 */

void OrdenaPacientesForaIntervalo(NaoCumpPaciente dadospacientes[], int maxpaciente) {
	for (int i = 0; i < maxpaciente - 1; i++) {
		for (int j = i + 1; j < maxpaciente; j++) {
			if (dadospacientes[i].numpaciente < dadospacientes[j].numpaciente) {  // Compara os n�meros dos pacientes para determinar a ordem
				NaoCumpPaciente temp = dadospacientes[i];
				dadospacientes[i] = dadospacientes[j];
				dadospacientes[j] = temp;
				// Troca os elementos se estiverem fora de ordem
			}
		}
	}
}

#pragma endregion 

#pragma region T�PICO 4

/**
 * @brief Lista o plano nutricional para um paciente numa refei��o espec�fica durante um determinado per�odo.
 *
 * Esta fun��o imprime na tela o plano nutricional para um paciente numa refei��o espec�fica durante um per�odo definido.
 *
 * @param planos � o array de structs PlanoNutri que contem os dados dos planos nutricionais.
 * @param maxplanos � o n�mero m�ximo de planos nutricionais no array.
 * @param numpaciente � o n�mero do paciente para o qual o plano nutricional ser� listado.
 * @param refeicao � o indice da refei��o (0 para 'peq. almo�o', 1 para 'almo�o', 2 para 'jantar').
 * @param dataInicio � a data de in�cio do per�odo desejado no formato "DD/MM/AAAA".
 * @param dataFim � a data de t�rmino do per�odo desejado no formato "DD/MM/AAAA".
 */

void ListaPlanoNutricional(PlanoNutri planos[], int maxplanos, int numpaciente, int refeicao, char dataInicio[], char dataFim[]) {

	char aux[N];
	if (refeicao == 0) {
		strcpy(aux, "peq. almo�o");
	}
	if (refeicao == 1) {
		strcpy(aux, "almo�o");
	}
	if (refeicao == 2) {
		strcpy(aux, "jantar");
	}

	//Cria��o de um vari�vel e coloca��o da "string" correspondente a cada indice para ser imprimido na consola o valor em "string"

	printf("Plano Nutricional para o Paciente %d na Refeicao '%s' no periodo de %s a %s:\n\n", numpaciente, aux, dataInicio, dataFim);

	for (int i = 0; i < maxplanos; i++) {
		if (planos[i].numpaciente == numpaciente && planos[i].tp == refeicao && strcmp(planos[i].datainicio, dataInicio) <= 0 && strcmp(planos[i].datafim, dataFim) >= 0) {
			printf("Paciente de n�mero: %d\n", planos[i].numpaciente);
			printf("O plano dura de %s a %s\n", planos[i].datainicio, planos[i].datafim);
			printf("Na refei��o %s deve ingerir:\n", aux);
			printf("Calorias M�nimas: %d\n", planos[i].caloriasMin);
			printf("Calorias M�ximas: %d\n\n", planos[i].caloriasMax);
		}
	}
}

#pragma endregion

#pragma region T�PICO 5

/**
 * @brief Calcula as m�dias de calorias consumidas em diferentes refei��es para cada paciente.
 *
 * @param dietas Um array de estruturas Dieta contendo informa��es sobre as dietas.
 * @param dados Um array de estruturas MediaPaciente para armazenar os resultados das m�dias.
 * @param maxdietas O n�mero m�ximo de elementos no array de dietas.
 * @param maxpacientes O n�mero m�ximo de pacientes.
 * @param dataInicio A data de in�cio do per�odo desejado para o c�lculo das m�dias.
 * @param dataFim A data de fim do per�odo desejado para o c�lculo das m�dias.
 */

void CalcularMediasRefeicoes(Dieta dietas[], MediaPaciente dados[], int maxdietas, int maxpacientes, char dataInicio[], char dataFim[]) {

	for (int i = 0; i < maxpacientes; i++) {
		double auxcontadorPequenoAlmoco = 0.0;
		double auxcontadorAlmoco = 0.0;
		double auxcontadorJantar = 0.0;
		int numPequenoAlmoco = 0;
		int numAlmoco = 0;
		int numJantar = 0;

		for (int j = 0; j < maxdietas; j++) {
			if (strcmp(dietas[j].datainicio, dataInicio) <= 0 && strcmp(dietas[j].datafim, dataFim) >= 0 &&
				dietas[j].numpaciente == i + 1) {

				switch (dietas[j].tp) {
				case 0: // Pequeno Almo�o
					auxcontadorPequenoAlmoco += dietas[j].calorias;
					numPequenoAlmoco++;
					break;
				case 1: // Almo�o
					auxcontadorAlmoco += dietas[j].calorias;
					numAlmoco++;
					break;
				case 2: // Jantar
					auxcontadorJantar += dietas[j].calorias;
					numJantar++;
					break;
				}
			}
		}

		//Se a vari�vel auxiliar num (PequenoAlmoco,Almoco,Jantar) for maior que zero, armazena os dados na struct MediaPaciente. Caso contr�rio retorna 0
		dados[i].numpaciente = i + 1; //Pacientes s�o numerados a partir de 1
		dados[i].mediapequenoalmoco = (numPequenoAlmoco > 0) ? auxcontadorPequenoAlmoco / numPequenoAlmoco : 0;
		dados[i].mediaalmoco = (numAlmoco > 0) ? auxcontadorAlmoco / numAlmoco : 0;
		dados[i].mediajantar = (numJantar > 0) ? auxcontadorJantar / numJantar : 0;
	}
}

#pragma endregion
