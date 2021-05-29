//
// Created by Kálóczi Kornél on 2021.05.27..
//

#ifndef VIGJATEK_HPP_INCLUDED
#define VIGJATEK_HPP_INCLUDED
#include "Film.hpp"



class Vigjatek: public Film {
    string tipus;
public:
    Vigjatek(string cim, int hossz, int kiadev, string tipus): Film(cim,hossz,kiadev), tipus(tipus) {}

    virtual ostream& print(ostream& os){
        return os <<"Vigjatek" << endl
                  <<"Cim: " << getCim() << endl
                  <<"Hossz: " << getHossz() << endl
                  <<"Kiadas eve: " << getKiadev() << endl
                  <<"Tipus: " << tipus<< endl;
    }

    virtual void fajlba_ir(ofstream& os){
        os << "Vigjatek;" << getCim() << ';' << getHossz() << ';' << getKiadev() << ';' << tipus << ';';
    }
};


#endif // VIGJATEK_HPP_INCLUDED
