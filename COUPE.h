//
// Created by Rares on 19/05/2024.
//

#ifndef PROIECT_MASINI_SPORT_COUPE_H
#define PROIECT_MASINI_SPORT_COUPE_H
#include "MasiniSport.h"

class COUPE :public MasiniSport{
protected:
    static const int numar_usi = 2;
public:
    using MasiniSport::MasiniSport; // Folosim constructorii din clasa de baza
    ~COUPE() override;
    void afisare_detalii() override;
    void afisare(ostream& out)const override; //functie afisare
    void citire(istream& in)override;// functie citire
    static int get_numar_usi() ;
    COUPE& operator=(const COUPE&);
    friend istream& operator>>(istream& in, COUPE&);
    friend ostream& operator<<(ostream& out,const COUPE&);
};




#endif //PROIECT_MASINI_SPORT_COUPE_H
