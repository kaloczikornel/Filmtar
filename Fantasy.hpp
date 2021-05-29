//
// Created by Kálóczi Kornél on 2021.05.27..
//

#ifndef FANTASY_HPP_INCLUDED
#define FANTASY_HPP_INCLUDED
#include "Film.hpp"


class Fantasy: public Film {
    bool scifi_e;
public:
    Fantasy(string cim, int hossz, int kiadev, bool scifi_e): Film(cim,hossz,kiadev), scifi_e(scifi_e) {}

    virtual std::ostream& print(std::ostream& os){
        string str;
        if (scifi_e)
            str = "Igen";
        else
            str = "Nem";
        return os <<"Fantasy" << endl
                  <<"Cim: " << getCim() << endl
                  <<"Hossz: " << getHossz() << endl
                  <<"Kiadas eve: " << getKiadev() << endl
                  <<"Sci-fi: " << str<< endl;
    }

    virtual void fajlba_ir(ofstream& os){
        os << "Fantasy;" << getCim() << ';' << getHossz() << ';' << getKiadev() << ';' << scifi_e << ';';
    }
};


#endif // FANTASY_HPP_INCLUDED
