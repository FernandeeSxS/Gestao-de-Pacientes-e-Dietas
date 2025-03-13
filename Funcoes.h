/**
 * @file Funcoes.h
 * @author Pedro Ribeiro, Ricardo Fernandes, Carolina Branco (a27960@alunos.ipca.pt a279861@alunos.ipca.pt a27983@alunos.ipca.pt)
 * @brief
 * @version 0.1
 * @date 2023-12-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#include "Dados.h"
#pragma warning (disable: 4996)

 // Fun��o para exportar dados dos pacientes para um ficheiro
bool ExportaDadosPacientes(char nomeFicheiro[], Paciente pacientes[], int maximoPacientes);
// Fun��o para ler dados dos pacientes a partir de um ficheiro
//bool LeDadosPacientes(char nomeFicheiro[], Paciente pacientes[], int maximoPacientes);

// Fun��o para exportar dados da dieta para um ficheiro
bool ExportaDadosDieta(char fileName[], Dieta dietas[], int maximodietas);
// Fun��o para ler dados da dieta a partir de um ficheiro
//bool LeDadosDieta(char fileName[], Dieta dietas[], int maximodietas);

// Fun��o para exportar dados do plano nutricional para um ficheiro
bool ExportaDadosPlanoNutri(char fileName[], PlanoNutri plano[], int maximodietas);

// Fun��o para ler dados do plano nutricional de um ficheiro
//bool LeDadosPlanosNutri(char fileName[], PlanoNutri plano[], int maximodietas);

// Fun��o para contar o n�mero de pacientes cujo consumo de calorias ultrapassa o limite definido no plano nutricional
int NumPacientesUltrapassamCal(PlanoNutri plano[], Dieta dietas[], int maximopacientes);

// Fun��o para identificar e armazenar pacientes cujo consumo de calorias est� fora do intervalo definido no plano nutricional 
void IdentificaForaIntervalo(PlanoNutri plano[], Dieta dietas[], Paciente dados[], NaoCumpPaciente dadospacientes[], int maxpaciente);

//Ordena os pacientes cujo consumo de calorias est� fora do intervalo definido no plano nutricional 
void OrdenaPacientesForaIntervalo(NaoCumpPaciente dadospacientes[], int maxpaciente);

// Fun��o para listar o plano nutricional de um paciente para uma refei��o espec�fica em um determinado per�odo
void ListaPlanoNutricional(PlanoNutri planos[], int maxplanos, int numpaciente, int refeicao, char dataInicio[], char dataFim[]);

// Fun��o para calcular as m�dias de consumo de calorias por refei��o para cada paciente em um determinado per�odo
void CalcularMediasRefeicoes(Dieta dietas[], MediaPaciente dados[], int maxdietas, int maxpacientes, char dataInicio[], char dataFim[]);

// Fun��o para gerar uma tabela de refei��es, exibindo informa��es como paciente, tipo de refei��o, datas e consumo de calorias
void GerarTabelaRefeicoes(Paciente pacientes[], Dieta dietas[], PlanoNutri planos[], int maxPacientes, int maxDietas, int maxPlanos);