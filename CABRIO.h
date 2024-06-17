//
// Created by Rares on 19/05/2024.
//

#ifndef PROIECT_MASINI_SPORT_CABRIO_H
#define PROIECT_MASINI_SPORT_CABRIO_H

#include "MasiniSport.h"
class CABRIO : public MasiniSport{
protected:
    string tip_acoperis; //soft-top, hard-top, folding-metal-roof, rigid-textile-roof
public:
    CABRIO();
    CABRIO(string, string, int, double, int, string);
    CABRIO(const CABRIO&) = default;
    ~CABRIO() override;
    string get_tip_acoperis()const;
    void set_tip_acoperis(string);
    void afisare_detalii()override;
    void afisare(ostream& out) const override ;
    void citire(istream& in) override;
    CABRIO& operator=(const CABRIO&);
    friend istream& operator>>(istream& in, CABRIO&);
    friend ostream& operator<<(ostream& out,const CABRIO&);
};


#endif //PROIECT_MASINI_SPORT_CABRIO_H
