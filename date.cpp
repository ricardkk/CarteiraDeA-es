#include "date.h"

// fazem o tipo data poder ser lido com cin e exibido com cout, como um tipo básico
ostream &operator<<(ostream &os, const tipoData &d) {
    os << d.dia << "/" << d.mes << "/" << d.ano;
    return os;
}

istream &operator>>(istream &in, tipoData &d) {
    in >> d.dia;
    in.ignore(1);
    in >> d.mes;
    in.ignore(1);
    in >> d.ano;
    return in;
}