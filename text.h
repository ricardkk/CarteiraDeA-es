#pragma once
#include "stock.h"
#include "color.h"
void desenhaLinha(char ch,int tam, cores corTexto, cores corFundo);


void minusculoParaMaiusculo(char v[]);

void exibeTextoAlinhado(const char * texto, cores corTexto, cores corFundo, int width);

void exibeTextoAlinhado(int texto, cores corTexto, cores corFundo, int width);

void exibeTextoAlinhado(float texto, cores corTexto, cores corFundo, int width);

float resumoDaCarteira(const empresa * vetorDeEmpresas, int tam);

void rentabilidadeDaCarteira(int aporte, int rendimentoAnual, float totalInvestido, float * investido, float * rendimento, float * acumulado, int * grafico, cores corTexto, cores corFundo);

