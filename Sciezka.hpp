#ifndef Sciezka_hpp
#define Sciezka_hpp

/*!
 * \file
 * \brief Definicja klasy Scena
 *
 * Plik zawiera definicję klasy Scena
 */

#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <vector>
#include "ObiektGraficzny.hpp"

/*!
 * \brief Modeluje pojęcie Sciezki zawierajacej
 * dwa wierzcholki
 */
class Sciezka{
    vector<Wektor2D> _Wierzcholki;
public:
    /*!
     * \brief Uzyskuje dostep do elementow pola vector<Wektor2D> _Wierzcholki
     */
    Wektor2D operator[](int i) const {return _Wierzcholki[i];}
    /*!
     * \brief Uzyskuje dostep do elementow pola vector<Wektor2D> _Wierzcholki
     * i pozwala na jego modyfikacje
     */
    Wektor2D &operator[](int i) {return _Wierzcholki[i];}
    /*!
     * \brief Oblicz i wstaw wierzcholek na koniec tablicy
     */
    void WstawWierzcholek(Wektor2D &W){_Wierzcholki.push_back(W);}
    /*!
     * \brief Wyczysc zawartosc kontenera i zwolnij pamiec
     */
    void WyczyscZawartoscSciezki(Sciezka &Sciez){_Wierzcholki.clear();}
    /*!
     * \brief Zwroc ilosc wierzcholkow sciezki
     */
    size_t ZwrocIloscWierzcholkow(){return _Wierzcholki.size();}
    /*!
     * \brief Zapisz wspolrzedne do strumienia
     */
    void ZapisWspolrzednychDoStrumienia(ostream& StrmWy,Sciezka &Sciez);
    /*!
     * \brief Zapisz wspolrzedne do pliku
     */
    bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku,Sciezka &Sciez);
};

#endif
