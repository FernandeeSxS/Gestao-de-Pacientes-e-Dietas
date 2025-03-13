/**
 * @file Main.c
 * @author Pedro Ribeiro, Ricardo Fernandes, Carolina Branco (a27960@alunos.ipca.pt a279861@alunos.ipca.pt a27983@alunos.ipca.pt)
 * @brief
 * @version 0.1
 * @date 2023-12-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "Dados.h"
#include "Funcoes.h"
#pragma warning (disable: 4996)

int main() {

	setlocale(LC_ALL, "Portuguese"); //linha de código para a inclusão de caractéres específicos da lingua portuguesa com letras com acentuação

#pragma region dar valor aos arrays das structs

	Paciente pacientes[] = {
		{001, "António", 912326549},
		{002, "Maria", 916226549},
		{003, "João", 912456549},
		{004, "Laura", 974930298},
		{005, "Alberto", 989898989}
	};
	Paciente testepac[E];

	Dieta dietas[] = {
		{001,"01 - 01 - 2023", "27 - 05 - 2023",0,"torrada",40},
		{002,"01 - 01 - 2023", "20 - 06 - 2023",1,"bife e batatas",650},
		{003, "21 - 03 - 2023", "21 - 12 - 2023",2,"salmao",90},
		{004, "1 - 03 - 2023", "31 - 12 - 2023",0,"pão",110},
		{005, "01 - 01 - 2023", "20 - 06 - 2023", 2, "picanha", 300}
	};
	Dieta testedi[E];

	PlanoNutri nutri[] = {
		{001, "01 - 01 - 2023", "27 - 01 - 2023" , 0, 300, 400},
		{001, "01 - 01 - 2023", "20 - 01 - 2023" , 2, 500, 600},
		{003, "21 - 03 - 2023", "21 - 12 - 2023" , 1, 500, 600},
		{005, "23 - 03 - 2023", "12 - 07 - 2023" , 0, 300 , 500},
		{004, "14 - 03 - 2022", "19 - 04 - 2023" , 1, 700, 800}
	};
	PlanoNutri testepla[E];


	NaoCumpPaciente nCump[E];


	MediaPaciente mediaPc[E];

#pragma endregion


#pragma region TÓPICO 1. a. (main)

	if (ExportaDadosPacientes("Pacientes.csv", pacientes, E)) { // Se a função funcionar...
		printf("Dados dos pacientes exportados com sucesso...\n\n");
	}
	else {
		printf("Erro ao exportar os dados dos pacientes...\n\n");
	}

#pragma endregion

#pragma region TÓPICO 1. b. (main)

	if (ExportaDadosDieta("Dietas.csv", dietas, E)) { // Se a função funcionar...
		printf("Dados das dietas exportados com sucesso...\n\n");
	}
	else {
		printf("Erro ao exportar os dados das dietas...\n\n");
	}

#pragma endregion

#pragma region TÓPICO 1. c. (main)

	if (ExportaDadosPlanoNutri("PlanoNutricional.csv", nutri, E)) { // Se a função funcionar...
		printf("Dados dos planos nutricionais exportados com sucesso...\n\n");
	}
	else {
		printf("Erro ao exportar os dados dos planos nutricionais...\n\n");
	}

#pragma endregion

#pragma region TÓPICO 2

	int pacientesUltrapassam = NumPacientesUltrapassamCal(nutri, dietas, E);
	printf("Número de pacientes que ultrapassaram o limite de calorias: %d\n\n", pacientesUltrapassam);

#pragma endregion

#pragma region TÓPICO 3

	IdentificaForaIntervalo(nutri, dietas, pacientes, nCump, E);
	OrdenaPacientesForaIntervalo(nCump, E);

	// Exibir resultados
	printf("Pacientes fora do intervalo ordenados:\n");
	for (int i = 0; i < E; i++) {
		if (nCump[i].numpaciente < -1) { //em caso do array ter espaços ocupados com lixo
			break;
		}
		else {
			printf("%d - %s, %d\n", nCump[i].numpaciente, nCump[i].nome, nCump[i].telefone);
		}
	}
	printf("\n");

#pragma endregion

#pragma region TÓPICO 4

	ListaPlanoNutricional(nutri, E, 1, 0, "10-05-2023", "12-05-2023");

#pragma endregion 

#pragma region TÓPICO 5

	CalcularMediasRefeicoes(dietas, mediaPc, E, E, "10-05-2023", "12-05-2023");

	for (int i = 0; i < E; i++) {

		printf("Paciente %d:\n", mediaPc[i].numpaciente);
		if (mediaPc[i].mediapequenoalmoco != 0) printf("Média Pequeno Almoço: %.2f\n", mediaPc[i].mediapequenoalmoco); //mostrar a media apensas se esta for diferente de 0 ou seja se houverem dados suficientees para a calcular
		if (mediaPc[i].mediaalmoco != 0) printf("Média Almoço: %.2f\n", mediaPc[i].mediaalmoco);
		if (mediaPc[i].mediajantar != 0) printf("Média Jantar: %.2f\n\n", mediaPc[i].mediajantar);

	}

#pragma endregion

#pragma region TÓPICO 6

	GerarTabelaRefeicoes(pacientes, dietas, nutri, 3, 3, 3);

#pragma endregion

}