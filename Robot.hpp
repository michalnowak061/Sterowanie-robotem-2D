#ifndef Robot_hpp
#define Robot_hpp

/*!
 * \file
 * \brief Definicja klasy Robot
 *
 * Plik zawiera definicję klasy Robot
 */

#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <unistd.h>
#include "ObiektGraficzny.hpp"
#include "Przeszkoda.hpp"
#include "Modul.hpp"
#include "Sciezka.hpp"

/*!
 * \brief Modeluje pojęcie Robota
 * skladajacego sie z szesciu wierzcholkow
 */
class Robot:public ObiektGraficzny{
    /*!
     * \brief Dlugosc elementarnego kroku robota
     */
    double _DlugoscKroku=50;
    /*!
     * \brief Dlugosc promienia okregu opisanego na robocie
     */
    double _Promien;
    /*!
     * \brief Kierunek robota (wektor jednostkowy, np. [1,0])
     */
    Wektor2D _Kierunek;
    /*!
     * \brief Srodek robota. Punkt przeciecia przekatnych
     */
    Wektor2D _Srodek;
    
    Sciezka _Sciezka;
public:
    /*!
     * \brief Wylicza kierunek robota
     */
    Wektor2D WyliczKierunek(Robot &Rob);
    /*!
     * \brief Wylicza srodek robota
     */
    Wektor2D ObliczSrodek(Robot &Rob);
    
    Wektor2D ObliczSrodekGlobalny(Robot &Rob);
    /*!
     * \brief Wylicza dlugosc promienia robota
     */
    double ObliczPromien(Robot &Rob);
    /*!
     * \brief Wstawia dlugosc kroku zadana przez uzytkownika do pola
     * double _DlugoscKroku
     */
    double WstawDlugosc(double const &Dl){_DlugoscKroku=Dl; return _DlugoscKroku;}
    /*!
     * \brief Uzyskuje dostep do pola double _DlugoscKroku
     */
    double WezDlugosc(){return _DlugoscKroku;}
    /*!
     * \brief Sprawdza czy nastapila kolizja robota z przeszkoda
     */
    bool CzyKolizja(Robot &Rob,Przeszkoda &Prz1,Przeszkoda &Prz2,Przeszkoda &Prz3);
    /*!
     * \brief Sprawdza czy nastapila kolizja robota z robotem
     */
    bool CzyKolizjaZRobotem(Robot &Rob1,Robot &Rob2);
    /*!
     * \brief Zapis wspolrzednych do strumienia
     */
    void ZapisWspolrzednychDoStrumienia(ostream& StrmWy,Robot &Rob);
    /*!
     * \brief Zapis wspolrzednych do pliku
     */
    bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku,Robot &Rob);
    /*!
     * \brief Obrot robota o zadany kat
     */
    void ObrocRobota(double const &Kat,Robot &Rob,const char *sNazwaPlikuR);
    /*!
     * \brief Ruch robota na zadana odleglosc
     */
    void WykonajRuchNaWprost(Robot &Rob,const char *sNazwaPlikuR,const char *sNazwaPlikuS);
    /*!
     * \brief Translacja robota o zadany wektor
     */
    void Translatuj(Wektor2D const &WekTranslacji,Robot &Rob,const char *sNazwaPlikuR,const char *sNazwaPlikuS);
};

#endif
