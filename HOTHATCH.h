//
// Created by Rares on 19/05/2024.
//

#ifndef PROIECT_MASINI_SPORT_HOTHATCH_H
#define PROIECT_MASINI_SPORT_HOTHATCH_H
#include "MasiniSport.h"

class HOTHATCH :public MasiniSport{
protected:
    int economie_consum;//numarul reprezinta cati litri se economisesc per suta de km
public:
    HOTHATCH();
    HOTHATCH(string, string, int, double, int, int);
    ~HOTHATCH()override;
    int get_economie_consum()const;
    void set_economie_consum(int);
    void afisare_detalii()override;
    void afisare(ostream& out)const override;
    void citire(istream& in)override;
    HOTHATCH& operator=(const HOTHATCH&);
    friend istream& operator>>(istream& in, HOTHATCH&);
    friend ostream& operator<<(ostream& out,const HOTHATCH&);
};


#endif //PROIECT_MASINI_SPORT_HOTHATCH_H
