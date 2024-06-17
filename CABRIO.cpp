//
// Created by Rares on 19/05/2024.
//

#include "CABRIO.h"


CABRIO::CABRIO(string marca, string model, int anFabricatie, double pret, int putere, string tip_acoperis):MasiniSport(marca, model, anFabricatie, pret, putere) {
    this-> tip_acoperis = tip_acoperis;
}

CABRIO::~CABRIO() {

}

string CABRIO::get_tip_acoperis() const {
    return tip_acoperis;
}

void CABRIO::set_tip_acoperis(string tip_acoperis) {
    this->tip_acoperis = tip_acoperis;
}

void CABRIO::afisare_detalii() {
    MasiniSport::afisare_detalii();
    cout << "Tipul de acoperis este: " << tip_acoperis << endl;
}

istream &operator>>(istream &in, CABRIO &m) {
    m.citire(in);
    return in;
}

ostream &operator<<(ostream &out,const CABRIO &m) {
    m.afisare(out);
    return out;
}

CABRIO &CABRIO::operator=(const CABRIO &m) {
    tip_acoperis = m.tip_acoperis;
    model = m.model;
    marca = m.marca;
    pret = m.pret;
    anFabricatie = m.anFabricatie;
    putere = m.putere;
    return *this;
}

CABRIO::CABRIO() {

}

void CABRIO::afisare(ostream &out) const{
    MasiniSport::afisare(out);
    out << "Tipul acoperisului este: " << tip_acoperis << endl;
}

void CABRIO::citire(istream &in) {
    MasiniSport::citire(in);
    cout << "Tipul de acoperis este: ";
    in >> tip_acoperis;
}
