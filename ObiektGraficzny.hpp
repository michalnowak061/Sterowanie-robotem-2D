#ifndef ObiektGraficzny_hpp
#define ObiektGraficzny_hpp

/*!
 * \file
 * \brief Definicja klasy ObiektGraficzny
 *
 * Plik zawiera definicję klasy ObiektGraficzny
 */

#include <stdio.h>
#include "ZbiorWierzcholkow.hpp"
#include "Macierz2x2.hpp"

/*!
 * \brief Modeluje pojęcie ObiektuGraficznego
 * reprezentujacego Robota,Przeszkode,Sciezke,
 */
class ObiektGraficzny{
    /*!
     * \brief Wierzcholki globalne zadane raz na poczatku
     */
    ZbiorWierzcholkow _WierzGlob;
    /*!
     * \brief Wierzcholki lokalne wyliczane na podstawie
     * wierzchlkow globalnych
     */
    ZbiorWierzcholkow _WierzLok;
    /*!
     * \brief Macierz rotacji obiektu
     */
    Macierz2x2 _MacRot;
    /*!
     * \brief Wektor translacji obiektu
     */
    Wektor2D _WekTranslacji;
    /*!
     * \brief Kat rotacji obiektu potrzebny do
     * obliczenia macierzy rotacji
     */
    double _KatRotacji;
public:
    /*!
     * \brief Uzyskuje dostep do pola ZbiorWierzcholkow _WierzLok
     */
    Wektor2D operator[](int i) const {return _WierzLok[i];}
    /*!
     * \brief Uzyskuje dostep do pola ZbiorWierzcholkow _WierzLok
     * i pozwala na jego modyfikacje
     */
    Wektor2D &operator[](int i) {return _WierzLok[i];}
    /*!
     * \brief Uzyskuje dostep do pola ZbiorWierzcholkow _WierzGlob;
     */
    Wektor2D operator()(int i) const {return _WierzGlob[i];}
    /*!
     * \brief Uzyskuje dostep do pola ZbiorWierzcholkow _WierzGlob
     * i pozwala na jego modyfikacje
     */
    Wektor2D &operator()(int i) {return _WierzGlob[i];}
    /*!
     * \brief Wstawienie wspolrzednych obiektu do pola ZbiorWierzcholkow _WierzGlob
     */
    void WstawWierz(ZbiorWierzcholkow &Zbior){_WierzGlob=Zbior;}
    /*!
     * \brief Tymczasowe podstawienie wierzcholkow globalnych do lokalnych 
     * w celu umozliwienia wyswietlnia konfiguracji poczatkowej
     */
    void ObliczWierzLok(){_WierzLok=_WierzGlob;}
    /*!
     * \brief Wstawia wpisany przez uzytkownika kat i wylicza wartosci odpowiednich
     * funkcji trygonometrycznych
     */
    Macierz2x2 ObliczMacierz(double const &Kat){_KatRotacji=_KatRotacji+Kat;
    _MacRot.Wstaw_Kat_Oblicz(_KatRotacji); return _MacRot;}
    /*!
     * \brief Wstawia wpisany przez wektor translacji do pola Wektor2D _WekTranslacji
     */
    Wektor2D WstawWekTranslacji(Wektor2D const &WekTrans){_WekTranslacji=WekTrans; return _WekTranslacji;}
    
    
    void WyzerujKat(ObiektGraficzny &Ob){_KatRotacji=0;}
};

#endif
