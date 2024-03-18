#pragma once
#include <iostream>
#include "stock.h"
#include "text.h"
#include "date.h"
#include "color.h"


using namespace std;

int main() {
	cores corTexto = Amarelo; cores corFundo = Amarelo;

	int qntEmpresas = entradaQuantidadeEmpresa(corTexto,corFundo);
	float aporteAnual, rendimentoAnual, investido[21], rendimento[21], acumulado[21];
	empresa * vetorDeEmpresas = new empresa[qntEmpresas];

	entradaVetorEmpresas(vetorDeEmpresas, qntEmpresas, corTexto, corFundo);
	entradaVetorTransacoes(vetorDeEmpresas, qntEmpresas, corTexto, corFundo);

	float totalInvestido = resumoDaCarteira(vetorDeEmpresas, qntEmpresas); cout << endl;

	system("pause");
	system("cls");

	ajustaCor("Aporte anual(R$): ", corTexto, Default); cin >> aporteAnual;
	ajustaCor("Rendimento anual estimado(%): ", corTexto, Default); cin >> rendimentoAnual; cout << endl;


	exibeTextoAlinhado(" Rentabilidade da Carteira ", Default, corFundo, 60); desenhaLinha(' ', 30, corTexto, corFundo);
	desenhaLinha('-', 90, corTexto, Default);
	ajustaCor(" Ano   Investido   Rendimento   Acumulado                                          Gráfico                              ", Default, corFundo); cout << endl;

	for (int i = 0; i < 21; i++) {
		if (i == 0) {
			investido[i] = totalInvestido;
			rendimento[i] = 0.00f;
			acumulado[i] = totalInvestido;
		}
		else {
			investido[i] = investido[i - 1] + aporteAnual;
			rendimento[i] = investido[i] * 0.15f;
			acumulado[i] = acumulado[i - 1] + aporteAnual + rendimento[i];
		}
		
		cout << left; exibeTextoAlinhado(i, Default, Amarelo, 3);
		cout << right;
		exibeTextoAlinhado(investido[i], Branco, Default, 12); 
		exibeTextoAlinhado(rendimento[i], Branco, Default, 11);
		exibeTextoAlinhado(acumulado[i], Branco, Default, 15);
		cout << endl;
		
	}







	

	for (int i = 0; i < qntEmpresas; i++) {
		delete[] vetorDeEmpresas[i].vetorDeTransacao;
	}

	delete[] vetorDeEmpresas;
	
}