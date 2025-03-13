/**
 * @file Gerepacientes.c
 * @author Pedro Ribeiro, Ricardo Fernandes, Carolina Branco (a27960@alunos.ipca.pt a279861@alunos.ipca.pt a27983@alunos.ipca.pt)
 * @brief
 * @version 0.1
 * @date 2023-12-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "Dados.h"
#pragma warning (disable: 4996)



#pragma region T�PICO 1. a.

 /**
  * @brief Exporta os dados dos pacientes para um ficheiro.
  *
  * Esta fun��o exporta os dados dos pacientes para um ficheiro no formato CSV ou TXT.
  *
  * @param nomeFicheiro � o nome do ficheiro para exportar os dados.
  * @param pacientes � o array de structs Paciente que contem os dados dos pacientes.
  * @param maximoPacientes � o n�mero m�ximo de pacientes no array.
  * @return Retorna true se a exporta��o for bem sucedida, caso contr�rio, retorna false.
  */

bool ExportaDadosPacientes(char nomeFicheiro[], Paciente pacientes[], int maximoPacientes) {
	FILE* fp;
	fp = fopen(nomeFicheiro, "w");  //Abre o ficheiro para escrita, usado o caracter "w" para apagar o que estiver escrito e escrever depois o pedido
	if (fp == NULL) return 0; //Caso n�o seja poss�vel abrir o ficheiro retorna false
	for (int i = 0; i < maximoPacientes; i++) {
		// O ciclo for itera sobre o array pacientes e vai escrevendo o mesmo no ficheiro, no formato CSV.
		fprintf(fp, "%d;%s;%d\n", pacientes[i].numpaciente, pacientes[i].nome, pacientes[i].telefone);
	}
	fclose(fp);
	return true;
	//Fecha o ficheiro e devolve true
}

#pragma endregion

/*
#pragma region T�PICO 1. a. (extra)

/**
 * @brief L� os dados dos pacientes de um ficheiro.
 *
 * Esta fun��o l� os dados dos pacientes de um ficheiro no formato CSV.
 *
 * @param nomeFicheiro � o nome do ficheiro para ler os dados dos pacientes.
 * @param pacientes � o array de structs Paciente para armazenar os dados lidos.
 * @param maximoPacientes � o n�mero m�ximo de pacientes no array.
 * @return Retorna true se a leitura for bem sucedida, caso contr�rio, retorna false.
 *

bool LeDadosPacientes(char nomeFicheiro[], Paciente pacientes[], int maximoPacientes) {
	FILE* fp;
	fp = fopen(nomeFicheiro, "r");
	if (fp == NULL) return false;
	int i = 0;
	while (i < maximoPacientes) {
		fscanf(fp, "%d;%[^;];%d", &pacientes[i].numpaciente, pacientes[i].nome, &pacientes[i].telefone);
		i++;
		if (feof(fp))break;
	}
	fclose(fp);
	return true;
}

#pragma endregion
*/

#pragma region T�PICO 6

/**
 * @brief Gera uma tabela de refei��es com informa��es sobre dietas e planos nutricionais.
 *
 * Esta fun��o imprime uma tabela que contem informa��es sobre as refei��es, incluindo dados do paciente,
 * tipo de refei��o, datas de in�cio e t�rmino, calorias m�nimas e m�ximas do plano nutricional, e consumo de calorias.
 *
 * @param pacientes � o array de structs Paciente que contem os dados dos pacientes.
 * @param dietas � o array de structs Dieta que contem os dados das dietas.
 * @param planos � o array de structs PlanoNutri que contem os dados dos planos nutricionais.
 * @param maxPacientes � o n�mero m�ximo de pacientes no array.
 * @param maxDietas � o n�mero m�ximo de dietas no array.
 * @param maxPlanos � o n�mero m�ximo de planos nutricionais no array.
 */

void GerarTabelaRefeicoes(Paciente pacientes[], Dieta dietas[], PlanoNutri planos[], int maxPacientes, int maxDietas, int maxPlanos) {
	printf("%s\t %-10s\t %-20s %-10s\t %-15s\t %-15s\t %-15s\t %-15s\n\n",
		"NP", "Paciente", "Tipo Refei��o", "Data In�cio", "Data Fim", "Calorias M�nimo", "Calorias M�ximo", "Consumo");

	for (int i = 0; i < maxDietas; i++) {

		char aux[N];
		if (planos[i].tp == 0) {
			strcpy(aux, "peq. almo�o");
		}
		if (planos[i].tp == 1) {
			strcpy(aux, "almo�o");
		}
		if (planos[i].tp == 2) {
			strcpy(aux, "jantar");
		}

		//Cria��o de um vari�vel e coloca��o tempor�ria da string correspondente a cada indice para ser imprimido na consola o valor em string

		printf("%04d\t %-10s\t %-20s %-10s\t %-15s\t %-15d\t %-15d\t %-15d\n",
			dietas[i].numpaciente,
			pacientes[dietas[i].numpaciente - 1].nome,
			aux,
			planos[i].datainicio,
			planos[i].datafim,
			planos[dietas[i].numpaciente - 1].caloriasMin,
			planos[dietas[i].numpaciente - 1].caloriasMax,
			dietas[i].calorias);
	}
}

#pragma endregion