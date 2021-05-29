//
// Created by Kálóczi Kornél on 2021.05.27..
//

#ifndef DOKUMENTUM_HPP_INCLUDED
#define DOKUMENTUM_HPP_INCLUDED
#include "Film.hpp"



class Dokumentum :public Film {
    string leiras;
public:
    Dokumentum(string cim, int hossz, int kiadev, string leiras): Film(cim,hossz,kiadev), leiras(leiras) {}

    virtual ostream& print(ostream& os) {
        return os <<"Dokumentum" << endl
                  <<"Cim: " << getCim() << endl
                  <<"Hossz: " << getHossz() << endl
                  <<"Kiadas eve: " << getKiadev() << endl
                  <<"Leiras: " << leiras<< endl;
    }

    virtual void fajlba_ir(ofstream& os){
        os << "Dokumentum;" << getCim() << ';' << getHossz() << ';' << getKiadev() << ';' << leiras << ';';
    }
};

#endif // DOKUMENTUM_HPP_INCLUDED
