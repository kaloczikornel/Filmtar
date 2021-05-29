//
// Created by Kálóczi Kornél on 2021.05.27..
//

#ifndef FAJLKEZELO_H_INCLUDED
#define FAJLKEZELO_H_INCLUDED
#include <fstream>
#include "Filmtar.h"
#include "Film.hpp"
#include "Csaladi.hpp"
#include "Fantasy.hpp"
#include "Vigjatek.hpp"
#include "Dokumentum.hpp"
using namespace std;


class Fajlkezelo {
    ifstream is;
    ofstream os;
    string eleresi_ut;
public:

    Fajlkezelo(string eleresi_ut): eleresi_ut(eleresi_ut) {}

    void fajlbair (Filmtar& tarolo);

    void fajlbolOlvas (Filmtar& tarolo);

    ~Fajlkezelo() {
        is.close();
        os.close();
    }
};


#endif // FAJLKEZELO_H_INCLUDED
