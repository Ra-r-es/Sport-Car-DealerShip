#include <iostream>
#include <vector>
#include "MasiniSport.h"
#include "CABRIO.h"
#include "COUPE.h"
#include "HOTHATCH.h"
#include "SUPERSPORT.h"
using namespace std;
template <typename T>
class Expozitie {
private:
    vector<T> masini;
    static int numarTotalMasini;

public:
    Expozitie() = default;
    ~Expozitie() = default;

    void adaugaMasina(const T& masina) {
        masini.push_back(masina);
        ++numarTotalMasini;
    }

    void afiseazaMasini() const {
        if (!masini.empty())
            for (int i = 0; i < masini.size(); ++i){
                cout << masini[i] << endl;
            }
    }

    static int getNumarTotalMasini() {
        return numarTotalMasini;
    }
    void operator-=(int index) {
        if (index >= 0 && index < masini.size()) {
            masini.erase(masini.begin() + index);
            --numarTotalMasini;
        } else {
            cout << "Index invalid!" << endl;
        }
    }
};

template <typename T>
int Expozitie<T>::numarTotalMasini = 0;
template <>
class Expozitie<SUPERSPORT> {
private:
    vector<SUPERSPORT*> masiniInStoc;
    vector<SUPERSPORT*> masiniVandute;
    static int numarTotalMasiniInStoc;
    static int numarMasiniVandute;

public:
    Expozitie() = default;
    ~Expozitie() {
        for (auto masina : masiniInStoc) {
            delete masina;
        }
        for (auto masina : masiniVandute) {
            delete masina;
        }
    }

    void adaugaMasina(const SUPERSPORT& masina) {
        masiniInStoc.push_back(new SUPERSPORT(masina));
        ++numarTotalMasiniInStoc;
    }

    void afiseazaMasiniInStoc() const {
        if (!masiniInStoc.empty())
            cout << "Masini SUPERSPORT in stoc:" << std::endl;
            for (const auto& masina : masiniInStoc) {
                masina->afisare_detalii();
                cout << std::endl;
            }
    }

    void afiseazaMasiniVandute() const {
        if (!masiniVandute.empty())
            cout << "Masini SUPERSPORT vandute:" << std::endl;
            for (const auto& masina : masiniVandute) {
                masina->afisare_detalii();
                cout << std::endl;
        }
    }

    static int getNumarTotalMasiniInStoc() {
        return numarTotalMasiniInStoc;
    }

    static int getNumarMasiniVandute() {
        return numarMasiniVandute;
    }

    void operator-=(const SUPERSPORT& masina) {
        for (auto it = masiniInStoc.begin(); it != masiniInStoc.end(); ++it) {
            if ((*it)->get_marca() == masina.get_marca() &&
                (*it)->get_model() == masina.get_model() &&
                (*it)->get_an() == masina.get_an()) {
                masiniVandute.push_back(*it);
                masiniInStoc.erase(it);
                --numarTotalMasiniInStoc;
                ++numarMasiniVandute;
                return;
            }
        }
    }
    void operator-=(int index) {
        if (index >= 0 && index < masiniInStoc.size()) {
            masiniVandute.push_back(masiniInStoc[index]);
            masiniInStoc.erase(masiniInStoc.begin() + index);
            --numarTotalMasiniInStoc;
            ++numarMasiniVandute;
        } else {
            cout << "Index invalid!" << endl;
        }
    }

};

int Expozitie<SUPERSPORT>::numarTotalMasiniInStoc = 0;
int Expozitie<SUPERSPORT>::numarMasiniVandute = 0;
void displayMesaj(){
    cout
            << "ADD" << " - citeste si adauga o noua la expozitie" << std::endl
            << "SELL" << " - sterge masina de pe pozitia introdusa" << std::endl
            << "DISPLAY" << " -afiseaza toate masinile din expozitie" << std::endl
            << "DETALII" << " - afiseaza numarul de masini in stoc si numarul de masini vandute" << std::endl
            << "STOP" << " - opreste programul" << std::endl
            << std::endl;
}
int main(){
    Expozitie<COUPE> c;
    Expozitie<HOTHATCH> h;
    Expozitie<CABRIO> cab;
    Expozitie<SUPERSPORT> s;
    Expozitie<MasiniSport> m;
    string comanda;
    displayMesaj();
    cin>>comanda;
    while(comanda!="STOP"){
        if (comanda == "ADD"){
            cout << "Introduceti ce tip de masina doriti: ";
            string tip;
            cin >> tip;
            if (tip == "COUPE"){
                COUPE coupe;
                cin >> coupe;
                c.adaugaMasina(coupe);
            }
            else if(tip == "CABRIO"){
                CABRIO cabrio;
                cin >> cabrio;
                if (cabrio.get_tip_acoperis() == "soft-top" || cabrio.get_tip_acoperis() ==  "hard-top" || cabrio.get_tip_acoperis() == "folding metal-roof"  || cabrio.get_tip_acoperis() == "rigid textile roof")
                    cab.adaugaMasina(cabrio);
                else{
                    cout << "Masina nu are un tip valid de acoperis, asa ca va deveni o simpla masina sport" << endl << endl;
                    MasiniSport *m1 = &cabrio;//upcasting
                    m.adaugaMasina(*m1);
                }
            }
            else if(tip == "SUPERSPORT"){
                SUPERSPORT *ss = new SUPERSPORT;
                cin >> *ss;
                if (ss->get_viteza_max() < 200){
                    COUPE *masina = dynamic_cast<COUPE*>(ss);
                    try {
                        COUPE *masina = dynamic_cast<COUPE*>(ss);//downcast
                        if (masina) {
                            c.adaugaMasina(*masina);
                        } else {
                            cout << "Nu se poate schimba tipul masini chiar daca este prea inceata." << endl;
                        }
                    } catch (const bad_cast& e) {
                        cout << "Nu se poate schimba tipul masini chiar daca este prea inceata." << endl;
                    }
                }
                else{
                    s.adaugaMasina(*ss);
                }
            }
            else if(tip == "HOTHATCH"){
                HOTHATCH hothatch;
                cin >> hothatch;
                h.adaugaMasina(hothatch);
            }
        }
        else if(comanda == "SELL"){
            cout << "Introduceti numarul masinii: ";
            int poz;
            cin >> poz;
            poz-=1;
            cout << "Introduceti tipul masinii: ";
            string tip3;
            cin >> tip3;
            if (tip3 == "COUPE")
                c-=poz;
            else if(tip3 == "HOTHATCH")
                h-=poz;
            else if(tip3 == "SUPERSPORT")
                s-=poz;
            else if(tip3 == "CABRIO")
                cab-=poz;
            else if(tip3 == "MASINASPORT")
                m-=poz;
        }
        else if(comanda == "DISPLAY"){
            m.afiseazaMasini();
            cout << endl;
            c.afiseazaMasini();
            cout <<endl;
            cab.afiseazaMasini();
            cout << endl;
            h.afiseazaMasini();
            cout << endl;
            s.afiseazaMasiniInStoc();
            cout << endl;
        }
        else if(comanda == "DETALII"){
            cout << endl;
            cout << "Sunt " << Expozitie<COUPE>::getNumarTotalMasini() +Expozitie<CABRIO>::getNumarTotalMasini()+Expozitie<HOTHATCH>::getNumarTotalMasini() + Expozitie<SUPERSPORT>::getNumarTotalMasiniInStoc() + Expozitie<MasiniSport>::getNumarTotalMasini() << " masini expuse" << endl;
            cout << "Au fost vandute " << s.getNumarMasiniVandute() << " masini super sport" << endl;
            cout << "Din toate masinile mai sunt " << s.getNumarTotalMasiniInStoc() << " masini supersport"<< endl << endl;
        }
        displayMesaj();
        cin>>comanda;
    }
    return 0;
}