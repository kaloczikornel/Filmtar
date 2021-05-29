#include <iostream>
#include <stdlib.h>
#include <string>
//#include "gtest_lite.h"
//#include "memtrace.h"
#include "Film.hpp"
#include "Filmtar.h"
#include "Fajlkezelo.h"
#include "Csaladi.hpp"
#include "Fantasy.hpp"
#include "Vigjatek.hpp"
#include "Dokumentum.hpp"






using namespace std;


void menu_kiir(){
    cout << "Menu" << endl
         << "1. Kereses" << endl
         << "2. Listaz" << endl
         << "3. Listaz szuressel" << endl
         << "4. Uj film felvetele" << endl
         << "5. Film torlese" << endl
         << "6. Minden torlese" << endl
         << "9. Kilepes" << endl;
}

int main()
{
    Fajlkezelo fajl("teszt1.txt");
    Filmtar f2;
    fajl.fajlbolOlvas(f2);


    int szam = 0;
    int szuroszam;
    int szuresiSzam;
    string szuresiString;
    do {
        if (szam == 0 || szam == 7){
            system("CLS");
            menu_kiir();
        }
        cin >> szam;
        cin.ignore(1);
        if (szam == 1){
            system("CLS");
            cout <<"Ird be a cimet:";
            string cim;
            getline(cin,cim);
            f2.keres(cim)->print(cout);
            cout << "---------------------" << endl
                 << "7. Vissza" << endl
                 << "9. Kilep" << endl;
        }
        else if (szam == 2){
            system("CLS");
            f2.listaz();
            cout << "7. Vissza" << endl
                 << "9. Kilep" << endl;
        }
        else if (szam == 3){
            system("CLS");
            cout <<"Mi szerint szeretnel szurni?" << endl
                 <<"1. Kiadasi ev" << endl
                 <<"2. Cim" <<endl;
            cin >> szuroszam;
            cin.ignore(1);
            if (szuroszam == 1){
                system("CLS");
                cout <<"Ird be az evet:";
                cin >> szuresiSzam;
                f2.szurveListaz(szuresiSzam,ev_eq);
                cout << "7. Vissza" << endl
                     << "9. Kilep" << endl;
            }
            else if(szuroszam == 2){
                system("CLS");
                cout <<"Ird be a cimet:";
                string cim;
                getline(cin,cim);
                f2.szurveListaz(cim,benne_van);
                cout << "7. Vissza" << endl
                     << "9. Kilep" << endl;
            }
        }
        else if (szam == 4){
            system("CLS");
            string fajta, cim;
            int hossz, kiadev;
            cout << "Milyen fajta filmet szeretnel hozzaadni? (Csaladi, Dokumentum, Fantasy, Vigjatek)" << endl;
            cin >> fajta;
            cin.ignore(1);
            cout << "Cim: ";
            getline(cin,cim);
            cout << "Hossz(percben): ";
            cin >> hossz;
            cout << "Kiadas eve:";
            cin >> kiadev;
            cin.ignore(1);
            if (fajta == "Csaladi"){
                int korhatar;
                cout << "Korhatar: ";
                cin >> korhatar;
                f2.felvesz(new Csaladi(cim,hossz,kiadev,korhatar));
            }
            else if (fajta == "Dokumentum"){
                string leiras;
                cout << "Leiras: ";
                getline(cin, leiras);
                f2.felvesz(new Dokumentum(cim, hossz, kiadev, leiras));
            }
            else if(fajta == "Fantasy"){
                bool scifi_e;
                string sci_s;
                cout << "Sci-fi? ";
                cin >> sci_s;
                scifi_e = (sci_s == "igen");
                f2.felvesz(new Fantasy(cim,hossz,kiadev,scifi_e));
            }
            else if(fajta == "Vigjatek"){
                string tipus;
                cout << "Milyen tipusu? ";
                getline(cin, tipus);
                f2.felvesz(new Vigjatek(cim, hossz, kiadev,tipus));
            }
            cout << "Kesz!" << endl;
            cout << "---------------------" << endl
                 << "7. Vissza" << endl
                 << "9. Kilep" << endl;
        }
        else if (szam == 5){
            system("CLS");
            cout << "Ird be a torlendo cim nevet!" << endl;
            string torlendo_cim;
            getline(cin,torlendo_cim);
            system("CLS");
            cout <<"Biztosan torlod ezt a filmet?" << endl;
            f2.keres(torlendo_cim)->print(cout);
            cout << "igen/nem: ";
            string valasz;
            cin >> valasz;
            if (valasz == "igen"){
                f2.torol(f2.keres(torlendo_cim));
                cout << "Torolve!" << endl;
            }
            else
                cout << "Torles felbe szakitva!" << endl;
            cout << "---------------------" << endl
                 << "7. Vissza" << endl
                 << "9. Kilep" << endl;
        }
        else if (szam == 6){
            system("CLS");
            cout << "Biztosan torol minden filmet a listarol?" << endl;
            string valasz;
            cin >> valasz;
            if (valasz == "igen"){
                f2.egesztorles();
                cout << "Sikeres torles!" << endl;
            }
            else
                cout << "Torles felbeszakitva!" << endl;
            cout << "---------------------" << endl
                 << "7. Vissza" << endl
                 << "9. Kilep" << endl;

        }
    } while (szam != 9);

    fajl.fajlbair(f2);


#ifdef CPORTA

    TEST(Teszt1, Tarolo){
        Filmtar f;
        EXPECT_EQ((size_t)0,f.dbszam()) <<"Nem Ã¼res!";

        f.felvesz(new Csaladi ("Coco", 109, 2017, 0));
        f.felvesz(new Csaladi("Toy Story 4", 100, 2019, 6));
        f.felvesz(new Csaladi("Dolittle",101,2020,12));
        EXPECT_EQ((size_t)3,f.dbszam()) <<"Nem jÃ³ a foglalas";
        EXPECT_STREQ("Coco",f.keres("Coco")->getCim().c_str()) <<"Keres hiba!";

        f.egesztorles();
        EXPECT_EQ((size_t)0,f.dbszam()) <<"Torles rossz!";

        f.felvesz(new Vigjatek("Bloff",104, 2001, "Guy Ritchie"));
        f.felvesz(new Csaladi("Dolittle",101,2020,12));
        f.felvesz(new Vigjatek("Itt a vege",107, 2013, "Seth Rogen"));
        EXPECT_EQ((size_t)3,f.dbszam()) <<"Nem jÃ³ a foglalas";
        f.torol(f.keres("Bloff"));
        EXPECT_EQ((size_t)2,f.dbszam()) <<"Nem jÃ³ a foglalas";
        f.torol(f.keres("Dolittle"));
        f.torol(f.keres("Itt a vege"));
        EXPECT_ANY_THROW(f.bennevan(f.keres("Bloff"))) <<"Nem torol!";

    } ENDM

    TEST(Teszt2, Filmek){
        Csaladi cs("Coco", 109, 2017, 0);
        EXPECT_STREQ("Coco",cs.getCim().c_str()) <<"Nem jÃ³ a nÃ©v!";
        EXPECT_EQ(109,cs.getHossz()) <<"Nem jÃ³ a hossz";
        EXPECT_EQ(2017,cs.getKiadev()) <<"Nem jÃ³ a kiadev";

        Dokumentum d("Vad MagyarorszÃ¡g",52,2011,"A film nÃ©gy Ã©vszakot Ã¡tÃ­velÅ‘en mutatja be MagyarorszÃ¡g Ã©s a KÃ¡rpÃ¡t-medence vadvilÃ¡gÃ¡t, Kulka JÃ¡nos narrÃ¡ciÃ³ja mellett.");
        EXPECT_STREQ("Vad MagyarorszÃ¡g",d.getCim().c_str()) <<"Nem jÃ³ a nÃ©v!";
        EXPECT_EQ(52,d.getHossz()) <<"Nem jÃ³ a hossz";
        EXPECT_EQ(2011,d.getKiadev()) <<"Nem jÃ³ a kiadev";

        Fantasy f("Csillagok kÃ¶zÃ¶tt", 169, 2014,true);
        EXPECT_STREQ("Csillagok kÃ¶zÃ¶tt",f.getCim().c_str()) <<"Nem jÃ³ a nÃ©v!";
        EXPECT_EQ(169,f.getHossz()) <<"Nem jÃ³ a hossz";
        EXPECT_EQ(2014,f.getKiadev()) <<"Nem jÃ³ a kiadev";

        Vigjatek v("Bloff",104, 2001, "Guy Ritchie");
        EXPECT_STREQ("Bloff",v.getCim().c_str()) <<"Nem jÃ³ a nÃ©v!";
        EXPECT_EQ(104,v.getHossz()) <<"Nem jÃ³ a hossz";
        EXPECT_EQ(2001,v.getKiadev()) <<"Nem jÃ³ a kiadev";

    } ENDM
#endif // CPORTA
    return 0;
}
