#ifndef MASINI_SPORT_H
#define MASINI_SPORT_H

#include <string>

// Clasa de baza pentru masinile sport
#include <string>
#include <iostream>

using namespace std;

class MasiniSport {
protected:
    string marca; //Audi,BMW...
    string model;//R8,E92,...
    int anFabricatie;//2007,2012..
    double pret;//10000
    int putere;//156..
public:
    MasiniSport();
    MasiniSport(string, string, int, double, int);
    MasiniSport(const MasiniSport &) = default;//constructorul de copiere default este suficient
    virtual ~MasiniSport();
    //getteri
    string get_marca() const;
    string get_model() const;
    int get_an() const;
    int get_pret() const;
    int get_putere() const;
    //setteri
    void set_marca(const string);
    void set_model(const string);
    void set_an(const int);
    void set_pret(const double);
    void set_putere(const int);
    //functii
    virtual void afisare_detalii();
    virtual void afisare(ostream& out)const;
    virtual void citire(istream& in);
    //supraincarcare operatori.
    MasiniSport& operator=(const MasiniSport&);
    friend istream& operator>>(istream& in, MasiniSport&);
    friend ostream& operator<<(ostream& out,const MasiniSport&);

};

#endif // MASINI_SPORT_H