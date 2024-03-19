#include <iostream>
#include "text.h"
#include "color.h"
using namespace std;

// função que desenha um caractere determinada quantidade de vezes
void desenhaLinha(char ch, int tam, cores corTexto, cores corFundo) {
	for (int i = 0; i <= tam; i++) {
		ajustaCor(ch, corTexto, corFundo);
	}
	cout << endl;
}

// função que lê uma cadeia de caracteres, verifica se é uma letra minúscula, e diminui 32 para achar seu equivalente maiúsculo na tabela ascii
void minusculoParaMaiusculo(char v[])
{
	for (int i = 0; v[i] != '\0'; i++) {
		if ((v[i] >= 'a') && (v[i] <= 'z')) {
			v[i] -= 32;
		}
		
	}
}

// funções para alinhar e colorir texto, contendo versões para vetor de char, inteiro e ponto flutuante
void exibeTextoAlinhado(const char * texto, cores corTexto, cores corFundo, int width) {
	cout << "\033[38;5;" << corTexto << "m" << "\033[48;5;" << corFundo << "m"; cout.width(width); cout << texto << "\033[0m";	
}

void exibeTextoAlinhado(int texto, cores corTexto, cores corFundo, int width) {

	cout << "\033[38;5;" << corTexto << "m" << "\033[48;5;" << corFundo << "m"; cout.width(width); cout << texto << "\033[0m";	
}

void exibeTextoAlinhado(float texto, cores corTexto, cores corFundo, int width) {
	cout << "\033[38;5;" << corTexto << "m" << "\033[48;5;" << corFundo << "m"; cout.width(width); cout << texto << "\033[0m";
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
	// pega a quantidade de ações e o preço delas para calcular o preço médio e o investido em casa empresa
	for (int i = 0; i < tam; i++) {
		int qnt = 0; float precoMedio,investido = 0;
		for (int j = 0; j < vetorDeEmpresas[i].transacoes; j++) {
			qnt += vetorDeEmpresas[i].vetorDeTransacao[j].quantidade;
			investido += vetorDeEmpresas[i].vetorDeTransacao[j].valor * vetorDeEmpresas[i].vetorDeTransacao[j].quantidade;
			
		}
		// soma do investido em todas as empresas
		totalInvestido += investido;
		// define as casas decimais para 2
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.precision(2);
		// calcula o preço médio dividindo o total investido na empresa pela quantidade de ações adquiridas
		precoMedio = (investido / qnt);

		// exibe os dados calculados
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

void rentabilidadeDaCarteira(int aporteAnual, int rendimentoAnual,float totalInvestido, float * investido, float * rendimento, float * acumulado, int * grafico, cores corTexto, cores corFundo)
{
	exibeTextoAlinhado(" Rentabilidade da Carteira ", Default, Amarelo, 60); desenhaLinha(' ', 50, corTexto, Amarelo);
	desenhaLinha('-', 110, corTexto, Default);
	ajustaCor(" Ano   Investido   Rendimento   Acumulado                                          Gráfico                     ", Default, Amarelo); cout << endl;


	// preenche os vetores investido, rendimento, acumulado e gráfico
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

		// Normaliza os elementos de acumulado e os transforma em alturas para o gráfico
		for (int i = 0; i < 21; i++) {
			int altura = int((acumulado[i] / acumulado[20]) * 21); // Calcula a altura
			if (altura == 0) {
				altura = 1;
			}
			grafico[i] = altura; // Adiciona a altura ao vetor
		}

	}
	// exibe cada linha utilizando os vetores preenchidos anteriormente 
	for (int i = 0; i < 21; i++) {
		cout << left; exibeTextoAlinhado(i, Default, Amarelo, 3);
		cout << right;
		exibeTextoAlinhado(investido[i], Branco, Default, 12);
		exibeTextoAlinhado(rendimento[i], Branco, Default, 11);
		exibeTextoAlinhado(acumulado[i], Branco, Default, 15);
		cout << "     ";

		// exibe espaços em brancos usando o número máximo de espaços que podem ser ocupados(21) - a quantidade de quadrados da linha	
		for (int j = 0; j < (21 - grafico[i]); ++j) {
			cout << "  ";
		}

		// imprime cada quadrado após os espaços em branco
		for (int k = 0; k < grafico[i]; ++k) {
			ajustaCor("\xFE ", corTexto, Default);
		}
		cout << endl;

	}
}