#pragma once
#include <iostream>
using namespace std;

struct tipoData {
    int dia;
    int mes;
    int ano;
};

ostream &operator<<(ostream &os, const tipoData &d);

istream &operator>>(istream &in, tipoData &d);


