//
// Created by Kálóczi Kornél on 2021.05.27..
//

#ifndef CSALADI_HPP_INCLUDED
#define CSALADI_HPP_INCLUDED
#include "Film.hpp"

class Csaladi: public Film{
    int korhatar;
public:
    Csaladi(string cim, int hossz, int kiadev, int korhatar): Film(cim,hossz,kiadev), korhatar(korhatar) {}

    virtual ostream& print(ostream& os){
        if (korhatar == 0)
            return os <<"Csaladi" << endl
                      <<"Cim: " << getCim() << endl
                      <<"Hossz: " << getHossz() << endl
                      <<"Kiadas eve: " << getKiadev() << endl
                      <<"Korhatar: " << "-" << endl;
        return os  <<"Csaladi" <<endl
                   <<"Cim: " << getCim() << endl
                   <<"Hossz: " << getHossz() << endl
                   <<"Kiadas eve: " << getKiadev() << endl
                   <<"Korhatar: " << korhatar << endl;
    }

    virtual void fajlba_ir(ofstream& os){
        os << "Csaladi;" << getCim() << ';' << getHossz() << ';' << getKiadev() << ';' << korhatar << ';';
    }

};


#endif // CSALADI_HPP_INCLUDED
