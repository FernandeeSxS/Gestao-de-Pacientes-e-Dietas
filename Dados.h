
/**
 * @file Dados.h
 * @author Pedro Ribeiro, Ricardo Fernandes, Carolina Branco (a27960@alunos.ipca.pt a279861@alunos.ipca.pt a27983@alunos.ipca.pt)
 * @brief
 * @version 0.1
 * @date 2023-12-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#define N 30
#define M 40
#define L 50
#define E 5 //se alterarem o n�mero de pacientes basta mudar este valor para a nova quantidade

#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>
#pragma warning (disable: 4996)

 //Cria��o das structs necess�rias

 // Defini��o de um enumerado chamado Refeicao para representar tipos de refei��es
typedef enum { PEQUENO_ALMOCO, ALMOCO, JANTAR } Refeicao; // 0 - PEQUENO_ALMOCO ; 1 - ALMOCO ; 2 - JANTAR

typedef struct Dieta {
	int numpaciente;  /**< N�mero de paciente*/
	char datainicio[N]; /**< Data de in�cio da dieta*/
	char datafim[N]; /**< Data fim da dieta*/
	// Achamos mais produtivo p�r em vez de uma vari�vel para a data apenas por uma data inicio e uma data fim 
	Refeicao tp; /**< Tipo da refei��o (Pequeno-almo�o;Almo�o;Jantar)*/
	char alimento[M]; /**< Alimento ingerido pelo paciente*/
	int calorias; /**< Calorias ingeridas pelo paciente*/

}Dieta;

typedef struct Paciente {
	int numpaciente; /**< N�mero de paciente*/
	char nome[N]; /**< Nome do paciente*/
	int telefone; /**< N�mero do telefone do paciente*/
}Paciente;

typedef struct PlanoNutri {
	int numpaciente; /**< N�mero de paciente*/
	char datainicio[N]; /**< Data de in�cio do plano nutricional*/
	char datafim[N]; /**< Data de fim do plano nutricional*/
	// Achamos mais produtivo p�r em vez de uma vari�vel para a data apenas por uma data inicio e uma data fim 
	Refeicao tp; /**< Tipo da refei��o (Pequeno-almo�o;Almo�o;Jantar)*/
	int caloriasMin; /**< N�mero m�nimo de calorias que o paciente deve consumir*/
	int caloriasMax; /**< N�mero m�ximo de calorias que o paciente deve consumir*/
}PlanoNutri;

typedef struct NaoCumpPaciente {
	int numpaciente; /**< N�mero do paicente*/
	char nome[N]; /**< Nome do paciente*/
	int telefone; /**< N�mero de telefone do paciente*/
}NaoCumpPaciente;

typedef struct MediaPaciente {
	int numpaciente; /**< N�mero de paciente*/
	double mediapequenoalmoco; /**< M�dia de calorias consumidas durante o pequeno-almo�o durante um per�odo espec�fico de tempo*/
	double mediaalmoco; /**< M�dia de calorias consumidas durante o almo�o durante um per�odo espec�fico de tempo*/
	double mediajantar; /**< M�dia de calorias consumidas durante o jantar durante um per�odo espec�fico de tempo*/
}MediaPaciente;