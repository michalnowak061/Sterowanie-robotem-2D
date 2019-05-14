#ifndef Scena_hpp
#define Scena_hpp

/*!
 * \file
 * \brief Definicja klasy Scena
 *
 * Plik zawiera definicję klasy Scena
 */

#include <stdio.h>
#include <unistd.h>
#include "Robot.hpp"
#include "Przeszkoda.hpp"
#include "Modul.hpp"

/*!
 * \brief Modeluje pojęcie Sceny zawierajacej
 * elementy rysunku takie jak: Robot,Sciezka,Przeszkoda
 */
class Scena{
    /*!
     * \brief Roboty na scenie
     */
    Robot _Robot1;
    Robot _Robot2;
    Robot _Robot3;
    /*!
     * \brief Przeszkody na scenie
     */
    Przeszkoda _Przeszkoda1;
    Przeszkoda _Przeszkoda2;
    Przeszkoda _Przeszkoda3;
public:
    /*!
     * \brief Wstawienie robota do pola Robot _Robot
     */
    void WstawRobotyNaScene(Robot &Rob1,Robot &Rob2,Robot &Rob3){_Robot1=Rob1,_Robot2=Rob2,_Robot3=Rob3;}
    /*!
     * \brief Zdjecie robota ze sceny
     */
    Robot ZdejmijRobota1ZeSceny(){return _Robot1;}
    /*!
     * \brief Zdjecie robota ze sceny
     */
    Robot ZdejmijRobota2ZeSceny(){return _Robot2;}
    /*!
     * \brief Zdjecie robota ze sceny
     */
    Robot ZdejmijRobota3ZeSceny(){return _Robot3;}
    /*!
     * \brief Wstawienie przeszkody pierwszej do pola Przeszkoda _Przeszkoda1
     */
    void WstawPrzeszkodyNaScene(Przeszkoda &Prz1,Przeszkoda &Prz2,Przeszkoda &Prz3){
        _Przeszkoda1=Prz1,_Przeszkoda2=Prz2,_Przeszkoda3=Prz3;}
    /*!
     * \brief Obrot robota o zadany kat
     */
    void ObrocRobota(double const &Kat,int i);
    /*!
     * \brief Ruch na wprost o zadana dlugosc
     */
    int WykonajRuchNaWprost(double &Odleglosc,int i);
    /*!
     * \brief Translacja wszystkich obiektow znajdujacy sie na scenie o zadany wektor
     */
    void TranslatujRysunek(Wektor2D const &WekTranslacji);
    /*!
     * \brief Zmiana dlugosci elementarnego kroku robota
     */
    void ZmienDlugoscKroku(double const &Dl){_Robot1.WstawDlugosc(Dl);}
};

#endif
