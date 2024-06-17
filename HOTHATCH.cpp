//
// Created by Rares on 19/05/2024.
//

#include "HOTHATCH.h"

HOTHATCH::HOTHATCH() {

}

HOTHATCH::HOTHATCH(string, string, int, double, int, int) {

}

HOTHATCH::~HOTHATCH() {

}

void HOTHATCH::afisare_detalii() {
    MasiniSport::afisare_detalii();
    cout << "Masina economiseste pe 100 de km: " << economie_consum << "l";
}

HOTHATCH &HOTHATCH::operator=(const HOTHATCH &m) {
    model = m.model;
    marca = m.marca;
    pret = m.pret;
    anFabricatie = m.anFabricatie;
    putere = m.putere;
    economie_consum = m.economie_consum;
    return *this;
}

istream &operator>>(istream &in, HOTHATCH &m) {
    m.citire(in);
    return in;
}

ostream &operator<<(ostream &out,const HOTHATCH &m) {
    m.afisare(out);
    return out;
}

int HOTHATCH::get_economie_consum() const {
    return economie_consum;
}

void HOTHATCH::set_economie_consum(int consum) {
    economie_consum = consum;
}

void HOTHATCH::afisare(ostream &out) const{
    MasiniSport::afisare(out);
    out << "Masina economiseste"  << economie_consum << "l per 100km" << endl;
}

void HOTHATCH::citire(istream &in) {
    MasiniSport::citire(in);
    cout << "Economie consum per 100km: ";
    in >> economie_consum;
}
