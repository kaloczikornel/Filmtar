//
// Created by Kálóczi Kornél on 2021.05.27..
//

#include "Filmtar.h"

//keresõ függvények

bool ev_eq(int a, int b) { return a == b; }

bool benne_van(string ez, string ebben){
    int a = ez.find("*");
    if( a != -1){
        ez.erase(a,a);
        return (ebben.find(ez) != string::npos);
    }
    else
        return(ebben == ez);
}

void Filmtar::felvesz (Film* ezt){
    Film** uj = new Film*[db + 1];
    for (size_t i = 0; i < db; i++)
        uj[i] = filmek[i];
    uj[db] = ezt;
    if (db != 0)
        delete[] filmek;
    filmek = uj;
    db++;
}



void Filmtar::listaz (ostream& os) {
    for (size_t i = 0; i < db; i++){
        filmek[i]->print(os);
        os << "---------------------" << endl;
    }
    if (db == 0)
        cout << "Ures a lista!" << endl;


}

void Filmtar::torol (Film* ezt){
    //ha nnincs benne hibat dob
    Film* itt = Filmtar::keres(ezt);
    if (db == 1)
        delete filmek[0];
    else{
        Film** uj = new Film*[db - 1];
        size_t j = 0;
        for (size_t i = 0; i < db; i++){
            if (filmek[i] != itt)
                uj[j++] = filmek[i];
            else
                delete filmek[i];
        }
        delete[] filmek;
        filmek = uj;
    }
    db--;
}

Film* Filmtar::keres (Film* ezt){
    for (size_t i = 0; i < db; i++)
        if(ezt == filmek[i])
            return filmek[i];
    throw invalid_argument("Nincs ilyen elem!");
}

Film* Filmtar::keres (string cim){
    for (size_t i = 0; i < db; i++)
        if(cim == filmek[i]->getCim())
            return filmek[i];
    throw invalid_argument("Nincs ilyen elem!");
}

void Filmtar::egesztorles (){
    if (db != 0){
        for (size_t i = 0; i < db; i++)
            delete filmek[i];
        delete[] filmek;
        db= 0;
        filmek = NULL;
    }

}

size_t Filmtar::dbszam (){
    return db;
}

void Filmtar::szurveListaz (int szuro, bool (*valamilyen)(int, int)) {
    int szaml = 0;
    for(size_t i = 0; i < db; i++)
        if(valamilyen(szuro,filmek[i]->getKiadev())){
            filmek[i]->print(cout);
            cout << "---------------------" << endl;
            szaml++;
        }
    if (szaml == 0)
        cout << "Nincs ilyen film!"<< endl;
}

void Filmtar::szurveListaz (string szuro, bool (*valamilyen)(string, string)){
    int szaml = 0;
    for(size_t i = 0; i < db; i++)
        if(valamilyen(szuro,filmek[i]->getCim())){
            filmek[i]->print(cout);
            cout << "---------------------" << endl;
            szaml++;
        }
    if (szaml == 0)
        cout << "Nincs ilyen film!"<< endl;
}

bool Filmtar::bennevan (Film* ez){
    for (size_t i = 0; i < db; i++)
        if(ez == filmek[i])
            return true;
    return false;
}
