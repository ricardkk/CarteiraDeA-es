#pragma once
#include <iostream>
#include "stock.h"
#include "text.h"
#include "date.h"
#include "color.h"


using namespace std;

int main() {
	cores corTexto = Amarelo; cores corFundo = Amarelo;

	// vetor que conter� o n�mero de quadrados de cada linha do gr�fico
	int grafico[21];

	//recebendo a quantidaade de empresas e armazenando
	int qntEmpresas = entradaQuantidadeEmpresa(corTexto,corFundo);

	//vari�veis que ser�o usadas na tabela rentabilidade da carteira
	float aporteAnual, rendimentoAnual, investido[21], rendimento[21], acumulado[21];

	//criando o vetor din�mico de empresas
	empresa * vetorDeEmpresas = new empresa[qntEmpresas];
	//preenchendo o vetor
	entradaVetorEmpresas(vetorDeEmpresas, qntEmpresas, corTexto, corFundo);

	//criando os vetores din�micos de transa��es
	for (int i = 0; i < qntEmpresas; i++) {
		for (int j = 0; j < vetorDeEmpresas[i].transacoes; j++) {
			vetorDeEmpresas[i].vetorDeTransacao = new transacao[vetorDeEmpresas[i].transacoes];
		}
	}
	//preenchendo os vetores
	entradaVetorTransacoes(vetorDeEmpresas, qntEmpresas, corTexto, corFundo);
	//exibe o resumo da carteira e recebe o valor investido
	float totalInvestido = resumoDaCarteira(vetorDeEmpresas, qntEmpresas); cout << endl;

	system("pause");
	system("cls");

	//recebendo o valor do aporte anual e do rendimento estimado
	ajustaCor("Aporte anual(R$): ", corTexto, Default); cin >> aporteAnual;
	ajustaCor("Rendimento anual estimado(%): ", corTexto, Default); cin >> rendimentoAnual; cout << endl;


	rentabilidadeDaCarteira(aporteAnual, rendimentoAnual, totalInvestido, investido, rendimento, acumulado, grafico, corTexto, Default);


	// deleta os vetores din�micos 
	for (int i = 0; i < qntEmpresas; i++) {
		delete[] vetorDeEmpresas[i].vetorDeTransacao;
	}

	delete[] vetorDeEmpresas;
	
}