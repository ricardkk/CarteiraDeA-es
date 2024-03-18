#include <iostream>
#include "text.h"
#include "color.h"
#include <iomanip>
using namespace std;

void desenhaLinha(char ch, int tam, cores corTexto, cores corFundo) {
	for (int i = 0; i <= tam; i++) {
		ajustaCor(ch, corTexto, corFundo);
	}
	cout << endl;
}


void minusculoParaMaiusculo(char v[])
{
	for (int i = 0; v[i] != '\0'; i++) {
		if ((v[i] >= 'a') && (v[i] <= 'z')) {
			v[i] -= 32;
		}
		
	}
}

void exibeTextoAlinhado(const char * texto, cores corTexto, cores corFundo, int width) {
	

	cout << "\033[38;5;" << corTexto << "m" << "\033[48;5;" << corFundo << "m"; cout.width(width); cout << texto << "\033[0m";
	//cout.width(width);
	//ajustaCor(texto, corTexto, corFundo);
	
	
}

void exibeTextoAlinhado(int texto, cores corTexto, cores corFundo, int width) {

	cout << "\033[38;5;" << corTexto << "m" << "\033[48;5;" << corFundo << "m"; cout.width(width); cout << texto << "\033[0m";
	//cout.width(width); cout << texto;
	
}

void exibeTextoAlinhado(float texto, cores corTexto, cores corFundo, int width) {
	cout << "\033[38;5;" << corTexto << "m" << "\033[48;5;" << corFundo << "m"; cout.width(width); cout << texto << "\033[0m";
	//cout.width(width); cout << texto;
	

}

float resumoDaCarteira(const empresa * vetorDeEmpresas, int tam)
{
	exibeTextoAlinhado(" Resumo da carteira ", Default, Amarelo, 60); desenhaLinha(' ', 30, Amarelo, Amarelo);
	desenhaLinha('-', 90, Amarelo, Default);
	
	cout << left;
	exibeTextoAlinhado(" Empresa ", Default, Amarelo, 20);
	exibeTextoAlinhado(" Ticker ", Default, Amarelo, 10);
	cout << right;
	exibeTextoAlinhado(" Qnt. ", Default, Amarelo, 10);
	exibeTextoAlinhado(" Preço Médio ", Default, Amarelo, 20);
	exibeTextoAlinhado(" Investido ", Default, Amarelo, 20); desenhaLinha(' ', 10, Amarelo, Amarelo);

	float totalInvestido = 0;
	for (int i = 0; i < tam; i++) {
		int qnt = 0; float precoMedio,investido = 0;
		for (int j = 0; j < vetorDeEmpresas[i].transacoes; j++) {
			qnt += vetorDeEmpresas[i].vetorDeTransacao[j].quantidade;
			investido += vetorDeEmpresas[i].vetorDeTransacao[j].valor * vetorDeEmpresas[i].vetorDeTransacao[j].quantidade;
			
		}
		totalInvestido += investido;
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.precision(2);
		precoMedio = (investido / qnt);


		cout << left;
		exibeTextoAlinhado(vetorDeEmpresas[i].nome, Branco, Default, 21); 
		exibeTextoAlinhado(vetorDeEmpresas[i].ticker, Branco, Default, 8);
		cout << right;
		exibeTextoAlinhado(qnt, Branco, Default, 10);
		exibeTextoAlinhado(precoMedio, Branco, Default, 18);
		exibeTextoAlinhado(investido, Branco, Default, 21);
		cout << endl;


		
	}
	desenhaLinha('-', 90, Amarelo, Default);
	exibeTextoAlinhado("Total Investido: ", Default, Amarelo, 0); exibeTextoAlinhado(totalInvestido, Default, Amarelo, 74);

	return totalInvestido;
}


