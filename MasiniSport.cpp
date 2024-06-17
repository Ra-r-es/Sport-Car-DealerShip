//
// Created by Rares on 18/05/2024.
//

#include "MasiniSport.h"

MasiniSport::MasiniSport() {

}

MasiniSport::MasiniSport(string marca, string model, int anFabricatie, double pret, int putere) {
    this->marca = marca;
    this->model = model;
    this->anFabricatie = anFabricatie;
    this-> pret = pret;
    this->putere = putere;
}

MasiniSport::~MasiniSport() {

}

string MasiniSport::get_marca() const {
    return marca;
}

string MasiniSport::get_model() const {
    return model;
}

int MasiniSport::get_an() const {
    return anFabricatie;
}

int MasiniSport::get_pret() const {
    return pret;
}

void MasiniSport::set_marca(const string marca) {
    this->marca = marca;
}

void MasiniSport::set_model(const string model) {
    this->model = model;
}

void MasiniSport::set_an(const int anFabricatie) {
    this->anFabricatie = anFabricatie;
}

int MasiniSport::get_putere() const {
    return putere;
}

void MasiniSport::set_pret(const double pret) {
    this->pret = pret;
}

void MasiniSport::set_putere(const int putere) {
    this->putere = putere;
}

void MasiniSport::afisare_detalii() {
    cout << "Numele masinii: " << marca << " " << model << endl;
    cout << "Anul: " << anFabricatie << endl;
    cout << "Pretul: " << pret << endl;
    cout << "Puterea: " << putere << " cp" << endl;
}

istream &operator>>(istream &in, MasiniSport &m) {
    m.citire(in);
    return in;
}

ostream &operator<<(ostream &out,const MasiniSport &m) {
    m.afisare(out);
    return out;
}

MasiniSport &MasiniSport::operator=(const MasiniSport &m) {
    model = m.model;
    marca = m.marca;
    pret = m.pret;
    anFabricatie = m.anFabricatie;
    putere = m.putere;
    return *this;
}

void MasiniSport::afisare(ostream &out) const{
    out << "Numele masinii: " << marca << " " << model << endl;
    out << "Anul: " << anFabricatie << endl;
    out << "Pretul: " << pret << endl;
    out << "Puterea: " << putere << " cp" << endl;
}

void MasiniSport::citire(istream &in) {
    cout << "Marca masini este: ";
    in >> marca;
    cout << "Modelul este: ";
    in >> model;
    cout << "In ce an a fost fabricata: ";
    in >> anFabricatie;
    cout << "Pretul este: ";
    in >> pret;
    cout <<"Cati cai are motorul: ";
    in >> putere;
}



