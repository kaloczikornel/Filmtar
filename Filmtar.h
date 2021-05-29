//
// Created by Kálóczi Kornél on 2021.05.27..
//

#ifndef FILMTAR_H_INCLUDED
#define FILMTAR_H_INCLUDED

#include "Film.hpp"


class Filmtar {
    size_t db;
    Film** filmek;
public:
    Filmtar (size_t db = 0):db(db), filmek(NULL) {}

    ~Filmtar () {
        if (filmek != NULL){
            for (size_t i = 0; i < db; i++)
                delete filmek[i];
            delete[] filmek;
        }
    }

    void felvesz (Film* ezt);

    void listaz (ostream& os = cout);

    void torol (Film* ezt);

    Film* keres (Film* ezt);

    Film* keres (string cim);

    void egesztorles ();

    size_t dbszam ();

    void szurveListaz (string szuro, bool (*valamilyen)(string, string));

    void szurveListaz (int szuro, bool (*valamilyen)(int, int));

    bool bennevan (Film* ez);

    Film const* operator[](size_t idx) const {
        return filmek[idx];
    }

    Film* operator[](size_t idx) {
        return filmek[idx];
    }

};

bool ev_eq(int a, int b);

bool benne_van(string ez, string ebben);


#endif // FILMTAR_H_INCLUDED
