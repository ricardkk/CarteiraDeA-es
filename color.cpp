#include <iostream>
#include "color.h"
#include <iomanip>
using namespace std;


void ajustaCor(const char * texto, cores corTexto, cores corFundo) {
	cout << "\033[38;5;" << corTexto << "m" << "\033[48;5;" << corFundo << "m" << texto << "\033[0m";
}


void ajustaCor(char texto, cores corTexto, cores corFundo) {
	cout << "\033[38;5;" << corTexto << "m" << "\033[48;5;" << corFundo << "m" << texto << "\033[0m";
}

void ajustaCor(int texto, cores corTexto, cores corFundo) {
	cout << "\033[38;5;" << corTexto << "m" << "\033[48;5;" << corFundo << "m" << texto << "\033[0m";
}

void ajustaCor(float texto, cores corTexto, cores corFundo) {
	cout << "\033[38;5;" << corTexto << "m" << "\033[48;5;" << corFundo << "m" << texto << "\033[0m";
}


