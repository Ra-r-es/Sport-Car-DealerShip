//
// Created by Rares on 19/05/2024.
//

#include "SUPERSPORT.h"

SUPERSPORT::SUPERSPORT() {

}

SUPERSPORT::SUPERSPORT(string marca, string model, int anFabricatie, double pret, int putere, double viteza):MasiniSport(marca, model, anFabricatie, pret, putere) {
    viteza_maxima = viteza;
}

SUPERSPORT::~SUPERSPORT() {

}

double SUPERSPORT::get_viteza_max() const {
    return viteza_maxima;
}

void SUPERSPORT::set_viteza_max(double viteza) {
    viteza_maxima = viteza;
}

SUPERSPORT &SUPERSPORT::operator=(const SUPERSPORT &m) {
    this->marca = m.marca;
    this->model = m.model;
    this->anFabricatie = m.anFabricatie;
    this-> pret = m.pret;
    this->putere = m.putere;
    this->viteza_maxima = m.viteza_maxima;
    return *this;
}

istream &operator>>(istream &in, SUPERSPORT &m) {
    m.citire(in);
    return in;
}

ostream &operator<<(ostream &out,const SUPERSPORT &m) {
    m.afisare(out);
    return out;
}

void SUPERSPORT::afisare_detalii() {
    MasiniSport::afisare_detalii();
    cout << "Viteza maxima: " << viteza_maxima << endl;
}

void SUPERSPORT::afisare(ostream &out) const{
    MasiniSport::afisare(out);
    out << "Viteza maxima: " << viteza_maxima << endl;
}

void SUPERSPORT::citire(istream &in) {
    MasiniSport::citire(in);
    cout << "Viteza maxima: ";
    in >> viteza_maxima;
}
