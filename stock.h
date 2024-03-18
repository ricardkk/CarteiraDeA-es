#pragma once
#include "date.h"
#include "color.h"

struct transacao {
	tipoData dataDeTransacao;
	int quantidade;
	float valor;
};

struct empresa {
	char nome[20];
	char ticker[10];
	int transacoes;
	transacao * vetorDeTransacao;
};

int entradaQuantidadeEmpresa(cores corTexto,cores corFundo);

void entradaVetorEmpresas(empresa * vetorDeEmpresas, int qntEmpresas,cores corTexto, cores corFundo);

void entradaVetorTransacoes(empresa * vetorDeEmpresas, int qntEmpresas,cores corTexto, cores corFundo);
