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



#pragma region TÓPICO 1. a.

 /**
  * @brief Exporta os dados dos pacientes para um ficheiro.
  *
  * Esta função exporta os dados dos pacientes para um ficheiro no formato CSV ou TXT.
  *
  * @param nomeFicheiro é o nome do ficheiro para exportar os dados.
  * @param pacientes é o array de structs Paciente que contem os dados dos pacientes.
  * @param maximoPacientes é o número máximo de pacientes no array.
  * @return Retorna true se a exportação for bem sucedida, caso contrário, retorna false.
  */

bool ExportaDadosPacientes(char nomeFicheiro[], Paciente pacientes[], int maximoPacientes) {
	FILE* fp;
	fp = fopen(nomeFicheiro, "w");  //Abre o ficheiro para escrita, usado o caracter "w" para apagar o que estiver escrito e escrever depois o pedido
	if (fp == NULL) return 0; //Caso não seja possível abrir o ficheiro retorna false
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
#pragma region TÓPICO 1. a. (extra)

/**
 * @brief Lê os dados dos pacientes de um ficheiro.
 *
 * Esta função lê os dados dos pacientes de um ficheiro no formato CSV.
 *
 * @param nomeFicheiro é o nome do ficheiro para ler os dados dos pacientes.
 * @param pacientes é o array de structs Paciente para armazenar os dados lidos.
 * @param maximoPacientes é o número máximo de pacientes no array.
 * @return Retorna true se a leitura for bem sucedida, caso contrário, retorna false.
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

#pragma region TÓPICO 6

/**
 * @brief Gera uma tabela de refeições com informações sobre dietas e planos nutricionais.
 *
 * Esta função imprime uma tabela que contem informações sobre as refeições, incluindo dados do paciente,
 * tipo de refeição, datas de início e término, calorias mínimas e máximas do plano nutricional, e consumo de calorias.
 *
 * @param pacientes é o array de structs Paciente que contem os dados dos pacientes.
 * @param dietas é o array de structs Dieta que contem os dados das dietas.
 * @param planos é o array de structs PlanoNutri que contem os dados dos planos nutricionais.
 * @param maxPacientes é o número máximo de pacientes no array.
 * @param maxDietas é o número máximo de dietas no array.
 * @param maxPlanos é o número máximo de planos nutricionais no array.
 */

void GerarTabelaRefeicoes(Paciente pacientes[], Dieta dietas[], PlanoNutri planos[], int maxPacientes, int maxDietas, int maxPlanos) {
	printf("%s\t %-10s\t %-20s %-10s\t %-15s\t %-15s\t %-15s\t %-15s\n\n",
		"NP", "Paciente", "Tipo Refeição", "Data Início", "Data Fim", "Calorias Mínimo", "Calorias Máximo", "Consumo");

	for (int i = 0; i < maxDietas; i++) {

		char aux[N];
		if (planos[i].tp == 0) {
			strcpy(aux, "peq. almoço");
		}
		if (planos[i].tp == 1) {
			strcpy(aux, "almoço");
		}
		if (planos[i].tp == 2) {
			strcpy(aux, "jantar");
		}

		//Criação de um variável e colocação temporária da string correspondente a cada indice para ser imprimido na consola o valor em string

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