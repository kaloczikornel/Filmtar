//
// Created by Kálóczi Kornél on 2021.05.27..
//

#ifndef FILM_HPP_INCLUDED
#define FILM_HPP_INCLUDED
#include <string>
#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <fstream>
//#include "memtrace.h"

using namespace std;

class Film{
    string cim;
    int hossz;
    int kiadev;
public:
    Film(string cim, int hossz, int kiadev): cim(cim), hossz(hossz), kiadev(kiadev) {}

    string getCim() {return cim;}

    int getHossz() {return hossz;}

    int getKiadev() {return kiadev;}

    virtual ostream& print(ostream& os) = 0;

    virtual void fajlba_ir(ofstream& os) = 0;

    virtual ~Film() {}


};


#endif // FILM_HPP_INCLUDED
