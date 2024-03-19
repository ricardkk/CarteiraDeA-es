#include "stock.h"
#include "color.h"
#include "text.h"

// retorna a quantidade de empresas digitada pelo usu�rio
int entradaQuantidadeEmpresa(cores corTexto, cores corFundo) {
	int qntEmpresas;

	ajustaCor(" Carteira de A��es \n\n", Default, corFundo);
	ajustaCor("Quantidade de empresas:  ", corTexto, Default); cin >> qntEmpresas;
	desenhaLinha('-', 27, corTexto, Default);

	return qntEmpresas;
}

// preenche o vetor din�mico do tipo empresa
void entradaVetorEmpresas(empresa * vetorDeEmpresas, int qntEmpresas, cores corTexto, cores corFundo){
	for (int i = 0; i < qntEmpresas; i++) {
		ajustaCor("Empresa: ", corTexto, Default); cin >> vetorDeEmpresas[i].nome;
		ajustaCor("Ticker: ", corTexto, Default); cin >> vetorDeEmpresas[i].ticker;
		minusculoParaMaiusculo(vetorDeEmpresas[i].ticker);
		ajustaCor("Transa��es: ", corTexto, Default); cin >> vetorDeEmpresas[i].transacoes;
		desenhaLinha('-', 27, corTexto, Default);
		vetorDeEmpresas[i] = vetorDeEmpresas[i];
		vetorDeEmpresas[i].vetorDeTransacao = new transacao[vetorDeEmpresas[i].transacoes];
	}
}

// preenche os vetores de transa��o de cada empresa
void entradaVetorTransacoes(empresa * vetorDeEmpresas, int qntEmpresas, cores corTexto, cores corFundo) {
	exibeTextoAlinhado(" Transa��es realizadas \n\n", Default, corFundo, 0);
	for (int i = 0; i < qntEmpresas; i++) {
		ajustaCor(vetorDeEmpresas[i].nome, corTexto, Default); ajustaCor(" - ", corTexto, Default); ajustaCor(vetorDeEmpresas[i].ticker, Amarelo, Default); cout << "\n\n";

		for (int j = 0; j < vetorDeEmpresas[i].transacoes; j++) {
			ajustaCor("Data: ", corTexto, Default); cin >> vetorDeEmpresas[i].vetorDeTransacao[j].dataDeTransacao;
			ajustaCor("Quantidade: ", corTexto, Default); cin >> vetorDeEmpresas[i].vetorDeTransacao[j].quantidade;
			ajustaCor("Pre�o: ", corTexto, Default); cin >> vetorDeEmpresas[i].vetorDeTransacao[j].valor; cout << "\n\n";


		}
	}
}

