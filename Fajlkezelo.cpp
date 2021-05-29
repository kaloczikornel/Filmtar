//
// Created by Kálóczi Kornél on 2021.05.27..
//
#include "Fajlkezelo.h"



void Fajlkezelo::fajlbair (Filmtar& tarolo){
    remove(eleresi_ut.c_str());
    os.open(eleresi_ut.c_str());
    os << tarolo.dbszam() << ';';
    for (size_t i = 0; i < tarolo.dbszam(); i++)
        tarolo[i]->fajlba_ir(os);
    os.close();


}

void Fajlkezelo::fajlbolOlvas (Filmtar& tarolo) {
    is.open(eleresi_ut.c_str());
    if (!is)
        cerr << "Nincs ilyen fájl!";
    int db;
    is >> db;
    is.ignore(1);
    for(int i = 0; i < db; i++){
        string tipus;
        getline(is, tipus, ';');
        string cim;
        getline(is, cim, ';');
        int tomb[2];
        for (int i = 0; i < 2; i++){
            is >> tomb[i];
            is.ignore(1);
        }
        if(tipus == "Csaladi" ){
            int korhatar;
            is >> korhatar;
            is.ignore(1);
            tarolo.felvesz(new Csaladi(cim,tomb[0],tomb[1],korhatar));
        }
        else if(tipus == "Dokumentum"){
            string leiras;
            getline(is, leiras, ';');
            tarolo.felvesz(new Dokumentum(cim,tomb[0],tomb[1],leiras));
        }
        else if(tipus == "Vigjatek"){
            string fajta;
            getline(is, fajta, ';');
            tarolo.felvesz(new Vigjatek(cim,tomb[0],tomb[1],fajta));
        }
        else if(tipus == "Fantasy"){
            int sci;
            is >> sci;
            is.ignore(1);
            bool scifi;
            if(sci == 0)
                scifi = false;
            else
                scifi = true;
            tarolo.felvesz(new Fantasy(cim,tomb[0],tomb[1],scifi));
        }
        else
            throw invalid_argument("Nem jo egy elem neve!");
    }
    is.close();

}

