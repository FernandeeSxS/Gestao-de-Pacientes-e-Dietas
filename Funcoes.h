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

 // Função para exportar dados dos pacientes para um ficheiro
bool ExportaDadosPacientes(char nomeFicheiro[], Paciente pacientes[], int maximoPacientes);
// Função para ler dados dos pacientes a partir de um ficheiro
//bool LeDadosPacientes(char nomeFicheiro[], Paciente pacientes[], int maximoPacientes);

// Função para exportar dados da dieta para um ficheiro
bool ExportaDadosDieta(char fileName[], Dieta dietas[], int maximodietas);
// Função para ler dados da dieta a partir de um ficheiro
//bool LeDadosDieta(char fileName[], Dieta dietas[], int maximodietas);

// Função para exportar dados do plano nutricional para um ficheiro
bool ExportaDadosPlanoNutri(char fileName[], PlanoNutri plano[], int maximodietas);

// Função para ler dados do plano nutricional de um ficheiro
//bool LeDadosPlanosNutri(char fileName[], PlanoNutri plano[], int maximodietas);

// Função para contar o número de pacientes cujo consumo de calorias ultrapassa o limite definido no plano nutricional
int NumPacientesUltrapassamCal(PlanoNutri plano[], Dieta dietas[], int maximopacientes);

// Função para identificar e armazenar pacientes cujo consumo de calorias está fora do intervalo definido no plano nutricional 
void IdentificaForaIntervalo(PlanoNutri plano[], Dieta dietas[], Paciente dados[], NaoCumpPaciente dadospacientes[], int maxpaciente);

//Ordena os pacientes cujo consumo de calorias está fora do intervalo definido no plano nutricional 
void OrdenaPacientesForaIntervalo(NaoCumpPaciente dadospacientes[], int maxpaciente);

// Função para listar o plano nutricional de um paciente para uma refeição específica em um determinado período
void ListaPlanoNutricional(PlanoNutri planos[], int maxplanos, int numpaciente, int refeicao, char dataInicio[], char dataFim[]);

// Função para calcular as médias de consumo de calorias por refeição para cada paciente em um determinado período
void CalcularMediasRefeicoes(Dieta dietas[], MediaPaciente dados[], int maxdietas, int maxpacientes, char dataInicio[], char dataFim[]);

// Função para gerar uma tabela de refeições, exibindo informações como paciente, tipo de refeição, datas e consumo de calorias
void GerarTabelaRefeicoes(Paciente pacientes[], Dieta dietas[], PlanoNutri planos[], int maxPacientes, int maxDietas, int maxPlanos);