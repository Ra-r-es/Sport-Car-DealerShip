//
// Created by Rares on 19/05/2024.
//

#ifndef PROIECT_MASINI_SPORT_SUPERSPORT_H
#define PROIECT_MASINI_SPORT_SUPERSPORT_H
#include "MasiniSport.h"

class SUPERSPORT :public MasiniSport{
protected:
    double viteza_maxima;
public:
    SUPERSPORT();
    SUPERSPORT(string, string, int, double, int, double);
    SUPERSPORT(const SUPERSPORT &) = default;
    ~SUPERSPORT()override;
    void afisare_detalii() override;
    double get_viteza_max()const;
    void set_viteza_max(double);
    void afisare(ostream& out)const override;
    void citire(istream& in)override;
    SUPERSPORT& operator=(const SUPERSPORT&);
    friend istream& operator>>(istream& in, SUPERSPORT&);
    friend ostream& operator<<(ostream& out,const SUPERSPORT&);
};


#endif //PROIECT_MASINI_SPORT_SUPERSPORT_H
