#ifndef ZbiorWierzcholkow_hpp
#define ZbiorWierzcholkow_hpp

/*!
 * \file
 * \brief Definicja klasy ZbiorWierzcholkow
 * Plik zawiera definicję klasy ZbiorWierzcholkow
 */

#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Wektor2D.hpp"

/*!
 * \brief Modeluje pojęcie ZbiorWierzcholkow
 * z wykorzystaniem szablonu vector
 */
class ZbiorWierzcholkow{
    /*!
     * \brief Dynamiczna tablica (kontener) zawierajacy wierzcholki
     */
    vector<Wektor2D> _Wierzcholki;
public:
    /*!
     * \brief Uzyskuje dostep do pola Wektor2D _Wierzcholki
     */
    Wektor2D operator[](int i) const {return _Wierzcholki[i];}
    /*!
     * \brief Uzyskuje dostep do pola Wektor2D _Wierzcholki
     * i pozwala na jego modyfikacje
     */
    Wektor2D &operator[](int i) {return _Wierzcholki[i];}
    /*!
     * \brief Wstawienie pojedynczego wierzcholka do pola Wektor2D _Wierzcholki
     */
    void WstawPoczatkowyWierzcholek(Wektor2D W){_Wierzcholki.push_back(W);}
    /*!
     * \brief Zwrocenie ilosci wierzcholkow z ktorych aktualnie sklada sie Sciezka
     */
    unsigned long ZwrocIloscWierzcholkow(){return _Wierzcholki.size();}
    /*!
     * \brief Zapis wspolrzednych wierzcholkow Sciezki do pliku
     */
    bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku);
    /*!
     * \brief Zapis wspolrzednych wierzcholkow Sciezki do strumienia
     */
    void ZapisWspolrzednychDoStrumienia(ostream& StrmWy);
};

#endif
