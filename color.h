#pragma once
enum cores {
    Default,
    Vermelho,
    AzulEscuro = 4,
    Amarelo = 220,
    Branco = 15,
    Vinho = 88,
    AzulClaro = 111,
    Verde = 40,
    Roxo = 219
};

void ajustaCor(const char * texto, cores corTexto, cores corFundo);

void ajustaCor(char texto, cores corTexto, cores corFundo);

void ajustaCor(int texto, cores corTexto, cores corFundo);

void ajustaCor(float texto, cores corTexto, cores corFundo);

void resetaCor();
