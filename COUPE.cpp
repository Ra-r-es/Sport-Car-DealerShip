//
// Created by Rares on 19/05/2024.
//

#include "COUPE.h"
#include "MasiniSport.h"

void COUPE::afisare_detalii() {
    cout << "Numele masinii: " << marca << " " << model << endl;
    cout << "Numar usi: " << numar_usi << endl;
    cout << "Anul: " << anFabricatie << endl;
    cout << "Pretul: " << pret << endl;
    cout << "Puterea: " << putere << " cp" << endl;
}

COUPE::~COUPE() {

}

int COUPE::get_numar_usi() {
    return numar_usi;
}

COUPE &COUPE::operator=(const COUPE &c) {
    model = c.model;
    marca = c.marca;
    pret = c.pret;
    anFabricatie = c.anFabricatie;
    putere = c.putere;
    return *this;
}

istream &operator>>(istream &in, COUPE &c) {
    c.citire(in);
    return in;
}

ostream &operator<<(ostream &out,const COUPE &m) {
    m.afisare(out);
    return out;
}

void COUPE::afisare(ostream &out) const{
    MasiniSport::afisare(out);
    out << "Numar usi: " << numar_usi << endl;
}

void COUPE::citire(istream &in) {
    MasiniSport::citire(in);
}
