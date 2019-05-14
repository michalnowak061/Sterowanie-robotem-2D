#include <iostream>
#include "ZbiorWierzcholkow.hpp"
#include "Wektor2D.hpp"
#include "Macierz2x2.hpp"
#include "ObiektGraficzny.hpp"
#include "lacze_do_gnuplota.hpp"
#include "Scena.hpp"
#include "Modul.hpp"
#include "Robot.hpp"
#include "Przeszkoda.hpp"
#include "Sciezka.hpp"

int main(void) {
    
//-------------------------------------------------------------
//  Utworzenie obiektow i wpisanie ich wspolrzednych
    
//-------------- ROBOTY -----------------------------
    
    Wektor2D W1,W2,W3,W4,W5,W6;
    W1.WstawPoczatkoweWspolrzedne(-50,60);
    W2.WstawPoczatkoweWspolrzedne(-45,60);
    W3.WstawPoczatkoweWspolrzedne(-50,65);
    W4.WstawPoczatkoweWspolrzedne(-55,65);
    W5.WstawPoczatkoweWspolrzedne(-55,55);
    W6.WstawPoczatkoweWspolrzedne(-50,55);
     
    ZbiorWierzcholkow Zb1;
    Zb1.WstawPoczatkowyWierzcholek(W1); 
    Zb1.WstawPoczatkowyWierzcholek(W2);
    Zb1.WstawPoczatkowyWierzcholek(W3);
    Zb1.WstawPoczatkowyWierzcholek(W4);
    Zb1.WstawPoczatkowyWierzcholek(W5);
    Zb1.WstawPoczatkowyWierzcholek(W6);
    
    Robot Rob1;
    Rob1.WstawWierz(Zb1);
    Rob1.ObliczWierzLok();
    
    Wektor2D W7,W8,W9,W10,W11,W12;
    W7.WstawPoczatkoweWspolrzedne(50,50);
    W8.WstawPoczatkoweWspolrzedne(55,50);
    W9.WstawPoczatkoweWspolrzedne(50,55);
    W10.WstawPoczatkoweWspolrzedne(45,55);
    W11.WstawPoczatkoweWspolrzedne(45,45);
    W12.WstawPoczatkoweWspolrzedne(50,45);
    
    ZbiorWierzcholkow Zb2;
    Zb2.WstawPoczatkowyWierzcholek(W7);
    Zb2.WstawPoczatkowyWierzcholek(W8);
    Zb2.WstawPoczatkowyWierzcholek(W9);
    Zb2.WstawPoczatkowyWierzcholek(W10);
    Zb2.WstawPoczatkowyWierzcholek(W11);
    Zb2.WstawPoczatkowyWierzcholek(W12);
    
    Robot Rob2;
    Rob2.WstawWierz(Zb2);
    Rob2.ObliczWierzLok();
    
    Wektor2D W13,W14,W15,W16,W17,W18;
    W13.WstawPoczatkoweWspolrzedne(50,-50);
    W14.WstawPoczatkoweWspolrzedne(55,-50);
    W15.WstawPoczatkoweWspolrzedne(50,-45);
    W16.WstawPoczatkoweWspolrzedne(45,-45);
    W17.WstawPoczatkoweWspolrzedne(45,-55);
    W18.WstawPoczatkoweWspolrzedne(50,-55);
    
    ZbiorWierzcholkow Zb3;
    Zb3.WstawPoczatkowyWierzcholek(W13);
    Zb3.WstawPoczatkowyWierzcholek(W14);
    Zb3.WstawPoczatkowyWierzcholek(W15);
    Zb3.WstawPoczatkowyWierzcholek(W16);
    Zb3.WstawPoczatkowyWierzcholek(W17);
    Zb3.WstawPoczatkowyWierzcholek(W18);
    
    Robot Rob3;
    Rob3.WstawWierz(Zb3);
    Rob3.ObliczWierzLok();
    
//-------------- PRZESZKODY -------------------------
    
    //Przeszkoda 1
    Wektor2D W19,W20,W21,W22;
    W19.WstawPoczatkoweWspolrzedne(20,20);
    W20.WstawPoczatkoweWspolrzedne(70,20);
    W21.WstawPoczatkoweWspolrzedne(70,30);
    W22.WstawPoczatkoweWspolrzedne(20,30);
    
    ZbiorWierzcholkow  Zb4;
    Zb4.WstawPoczatkowyWierzcholek(W19);
    Zb4.WstawPoczatkowyWierzcholek(W20);
    Zb4.WstawPoczatkowyWierzcholek(W21);
    Zb4.WstawPoczatkowyWierzcholek(W22);

    Przeszkoda Prz1;
    Prz1.WstawWierz(Zb4);
    Prz1.ObliczWierzLok();
    
    //Przeszkoda 2
    Wektor2D W23,W24,W25,W26;
    W23.WstawPoczatkoweWspolrzedne(-60,30);
    W24.WstawPoczatkoweWspolrzedne(-20,30);
    W25.WstawPoczatkoweWspolrzedne(-20,50);
    W26.WstawPoczatkoweWspolrzedne(-60,50);
    
    ZbiorWierzcholkow Zb5;
    Zb5.WstawPoczatkowyWierzcholek(W23);
    Zb5.WstawPoczatkowyWierzcholek(W24);
    Zb5.WstawPoczatkowyWierzcholek(W25);
    Zb5.WstawPoczatkowyWierzcholek(W26);
    
    Przeszkoda Prz2;
    Prz2.WstawWierz(Zb5);
    Prz2.ObliczWierzLok();
    
    //Przeszkoda 3
    Wektor2D W27,W28,W29,W30;
    W27.WstawPoczatkoweWspolrzedne(-75,-75);
    W28.WstawPoczatkoweWspolrzedne(-25,-75);
    W29.WstawPoczatkoweWspolrzedne(-25,-25);
    W30.WstawPoczatkoweWspolrzedne(-75,-25);
    
    ZbiorWierzcholkow Zb6;
    Zb6.WstawPoczatkowyWierzcholek(W27);
    Zb6.WstawPoczatkowyWierzcholek(W28);
    Zb6.WstawPoczatkowyWierzcholek(W29);
    Zb6.WstawPoczatkowyWierzcholek(W30);
    
    Przeszkoda Prz3;
    Prz3.WstawWierz(Zb6);
    Prz3.ObliczWierzLok();

//----------------- SCENA ----------------------------
    
    Scena Sc;
    
//---------------- SCIEZKA ---------------------------
    
    Sciezka Sciez1;
    Sciezka Sciez2;
    Sciezka Sciez3;
    
//----------------------------------------------------
//  Wstawienie obiektow na scene
    
    Sc.WstawRobotyNaScene(Rob1,Rob2,Rob3);
    Sc.WstawPrzeszkodyNaScene(Prz1,Prz2,Prz3);
//
//----------------------------------------------------
//  Konfiguracja polaczenia z programem GnuPlot
    
    PzG::LaczeDoGNUPlota  Lacze;
    
    //-------------------------------------------------------
    //  Wspolrzedne wierzcholkow beda zapisywane w pliku "*.dat"
    //
    Lacze.DodajNazwePliku("robot1.dat",PzG::RR_Ciagly,2);
    Lacze.DodajNazwePliku("robot2.dat",PzG::RR_Ciagly,2);
    Lacze.DodajNazwePliku("robot3.dat",PzG::RR_Ciagly,2);
    Lacze.DodajNazwePliku("sciezka1.dat",PzG::RR_Ciagly,1);
    Lacze.DodajNazwePliku("sciezka2.dat",PzG::RR_Ciagly,1);
    Lacze.DodajNazwePliku("sciezka3.dat",PzG::RR_Ciagly,1);
    Lacze.DodajNazwePliku("przeszkoda1.dat",PzG::RR_Ciagly,2);
    Lacze.DodajNazwePliku("przeszkoda2.dat",PzG::RR_Ciagly,2);
    Lacze.DodajNazwePliku("przeszkoda3.dat",PzG::RR_Ciagly,2);
    //
    //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
    //  znajduje się na wspólnej płaszczyźnie. Z tego powodu
    //  jako wspolrzedne punktow podajemy tylko x,y.
    //
    Lacze.ZmienTrybRys(PzG::TR_2D);
    //-------------------------------------------------------
    //  Wyswietlenie obiektow przy starcie programu
    //
    Rob1.ZapisWspolrzednychDoPliku("robot1.dat",Rob1);
    Rob2.ZapisWspolrzednychDoPliku("robot2.dat",Rob2);
    Rob3.ZapisWspolrzednychDoPliku("robot3.dat",Rob3);
    Prz1.ZapisWspolrzednychDoPliku("przeszkoda1.dat",Prz1);
    Prz2.ZapisWspolrzednychDoPliku("przeszkoda2.dat",Prz2);
    Prz3.ZapisWspolrzednychDoPliku("przeszkoda3.dat",Prz3);
    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
    //-------------------------------------------------------
    //  Pierwsze wyswietlenie menu
    //
    cout<<"Laczna ilosc stworzonych obiektow klasy Wektor2D: "
    <<Wektor2D::WezLicznikStworzonych()<<endl;
    cout<<"Ilosc istniejacych obiektow klasy Wektor2D: "
    <<Wektor2D::WezLicznikAktualny()<<endl<<endl;
    cout<<"Aktualnie wyselekcjonowanym robotem jest:"<<endl;
    cout<<"Robot "<<2<<".   Wspolrzedne: "
    <<"("<<Rob2.ObliczSrodek(Rob2)[0]<<","
    <<Rob2.ObliczSrodek(Rob2)[1]<<")"<<endl<<endl;
    cout<<"z - zmiana szybkosci ruchu robota"<<endl;
    cout<<"o - obrot robota o zadany kat"<<endl;
    cout<<"j - jazda na wprost"<<endl;
    cout<<"s - selekcja robota"<<endl<<endl;
    cout<<"t - zadaj translacje rysunku"<<endl;
    cout<<"p - powrot do pierwotnego ustawienia rysunku"<<endl<<endl;
    cout<<"w- wyswietl ponownie menu"<<endl<<endl;
    cout<<"k - zakoncz dzialanie programu"<<endl<<endl;
    //-------------------------------------------------------
    //  Interakcja z uzytkownikiem
    while(1){
        //zmienne i obiekty pomocnicze
        char Znak;
        double Odleglosc=0;
        double KatRotacji=0;
        double DlugoscKroku=0;
        int static NumerRobota=2;
        Wektor2D WspolrzedneRobota;
        //roboty do odczytania wspolrzednych
        Robot R1=Sc.ZdejmijRobota1ZeSceny();
        Robot R2=Sc.ZdejmijRobota2ZeSceny();
        Robot R3=Sc.ZdejmijRobota3ZeSceny();
        
        if(NumerRobota==1) WspolrzedneRobota=R1.ObliczSrodek(R1);
        if(NumerRobota==2) WspolrzedneRobota=R2.ObliczSrodek(R2);
        if(NumerRobota==3) WspolrzedneRobota=R3.ObliczSrodek(R3);

        //---------------------------------
        
        Wektor2D Przesuniecie; // calkowite przesuniecie wzgledem punktu 0,0
        Wektor2D WekTranslacji; // aktualne przesuniecie wzgledem punktu 0,0
    
        cout<<"Twoj wybor(w - wyswietl menu)> ";
        cin>>Znak;
        cout<<endl;
        if(Znak=='k') break;
        
        switch(Znak){
                //--------------------------------------------------
                //  zmiana szybkosci ruchu robota
                case 'z':
                cout<<"Aktualnie wyselekcjonowanym robotem jest:"<<endl;
                cout<<"Robot "<<NumerRobota<<".   Wspolrzedne: "<<"("<<WspolrzedneRobota[0]
                <<","<<WspolrzedneRobota[1]<<")"<<endl<<endl;
                cout<<"Podaj dlugosc kroku robota."
                    <<"Dlugosc kroku: ";
                cin>>DlugoscKroku;
                Sc.ZmienDlugoscKroku(DlugoscKroku);
                break;
                //---------------------------------------------------
                //  obrot robota
                case 'o':
                cout<<"Aktualnie wyselekcjonowanym robotem jest:"<<endl;
                cout<<"Robot "<<NumerRobota<<".   Wspolrzedne: "<<"("<<WspolrzedneRobota[0]
                <<","<<WspolrzedneRobota[1]<<")"<<endl<<endl;
                cout<<"Podaj kat obrotu robota. "<<endl
                    <<"Kat rotacji: ";
                cin>>KatRotacji;
                while(KatRotacji>0){// <- wykonaj petle tyle razy ile kat obrotu
                Sc.ObrocRobota(1,NumerRobota); // elementarny kat obrotu 1 stopien
                Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                --KatRotacji;
                }
                break;
                //----------------------------------------------------
                //  jazda na wprost
                case 'j':
                cout<<"Aktualnie wyselekcjonowanym robotem jest:"<<endl;
                cout<<"Robot "<<NumerRobota<<".   Wspolrzedne: "<<"("<<WspolrzedneRobota[0]
                <<","<<WspolrzedneRobota[1]<<")"<<endl<<endl;
                cout<<"Podaj dlugosc drogi ruchu robota na wprost. "<<endl
                    <<"Dlugosc drogi: ";
                cin>>Odleglosc;
                while(Odleglosc>0){// <- wykonaj petle tyle razy ile Odleglosc
                int i=Sc.WykonajRuchNaWprost(Odleglosc,NumerRobota); // <- podstaw pod i wartosc zwrocona
                                                         // przez funkcje
                Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                --Odleglosc;
                if(i==1) break; // <- przerwij ruch
                }
                break;
                //----------------------------------------------------
                //  selekcja robota
                case 's':
                cout<<"Aktualnie wyselekcjonowanym robotem jest:"<<endl;
                cout<<"Robot "<<NumerRobota<<".   Wspolrzedne: "<<"("<<WspolrzedneRobota[0]
                <<","<<WspolrzedneRobota[1]<<")"<<endl<<endl;
                cout<<"Wprowadz numer robota lub 0 > ";
                cin>>NumerRobota;
                if(NumerRobota==0) break;
                break;
                //-----------------------------------------------------
                //  zadaj translacje rysunku
                case 't':
                Przesuniecie=Przesuniecie+WekTranslacji; // <- oblicz calkowite przesuniecie
                cout<<"Aktualny całkowity wektor translacji"<<endl
                <<"wzgledem poczatkowego polozenia sceny: "<<Przesuniecie<<endl<<endl;
                cout<<"Wpisz wspolrzedne wektora lokalnej translacji rysunku sceny."<<endl
                <<"Podaj wartosci: x y > ";
                cin>>WekTranslacji;
                Sc.TranslatujRysunek(WekTranslacji);
                Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                break;
                //------------------------------------------------------
                //  powrot do pierwotnego ustawienia rysunku
                case 'p':
                Sc.WstawRobotyNaScene(Rob1,Rob2,Rob3);
                Sc.WstawPrzeszkodyNaScene(Prz1,Prz2,Prz3);
                Rob1.ZapisWspolrzednychDoPliku("robot1.dat",Rob1);
                Rob2.ZapisWspolrzednychDoPliku("robot2.dat",Rob2);
                Rob3.ZapisWspolrzednychDoPliku("robot3.dat",Rob3);
                Sciez1.ZapisWspolrzednychDoPliku("sciezka1.dat",Sciez1);
                Sciez2.ZapisWspolrzednychDoPliku("sciezka2.dat",Sciez2);
                Sciez3.ZapisWspolrzednychDoPliku("sciezka3.dat",Sciez3);
                Prz1.ZapisWspolrzednychDoPliku("przeszkoda1.dat",Prz1);
                Prz2.ZapisWspolrzednychDoPliku("przeszkoda2.dat",Prz2);
                Prz3.ZapisWspolrzednychDoPliku("przeszkoda3.dat",Prz3);
                Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                cout<<"Przywrocone zostalo poczatkowe ustawienie sceny."<<endl;
                break;
                //------------------------------------------------------
                //  wyswietl ponownie menu
                case 'w':
                cout<<"Laczna ilosc stworzonych obiektow klasy Wektor2D: "
                <<Wektor2D::WezLicznikStworzonych()<<endl;
                cout<<"Ilosc istniejacych obiektow klasy Wektor2D: "
                <<Wektor2D::WezLicznikAktualny()<<endl<<endl;
                cout<<"Aktualnie wyselekcjonowanym robotem jest:"<<endl;
                cout<<"Robot "<<NumerRobota<<".   Wspolrzedne: "<<"("<<WspolrzedneRobota[0]
                <<","<<WspolrzedneRobota[1]<<")"<<endl<<endl;
                cout<<"z - zmiana szybkosci ruchu robota"<<endl;
                cout<<"o - obrot robota o zadany kat"<<endl;
                cout<<"j - jazda na wprost"<<endl;
                cout<<"s - selekcja robota"<<endl<<endl;
                cout<<"t - zadaj translacje rysunku"<<endl;
                cout<<"p - powrot do pierwotnego ustawienia rysunku"<<endl<<endl;
                cout<<"w- wyswietl ponownie menu"<<endl<<endl;
                cout<<"k - zakoncz dzialanie programu"<<endl<<endl;
                break;
        }
    }
    //----------------------------------------------------------------------------------
    
    cout<<"Program 'Sterowanie robotem mobilnym' zakonczyl dzialanie"<<endl;
    
    return 0;
}
