#ifndef Przeszkoda_hpp
#define Przeszkoda_hpp

/*!
 * \file
 * \brief Definicja klasy Przeszkoda
 *
 * Plik zawiera definicję klasy Przeszkoda
 */

#include <stdio.h>
#include "ObiektGraficzny.hpp"

/*!
 * \brief Modeluje pojęcie Przeszkody
 * zawierajacej cztery wierzcholki
 */
class Przeszkoda: public ObiektGraficzny{
public:
    /*!
     * \brief Zapis wspolrzednych przeszkody do strumienia
     */
    void ZapisWspolrzednychDoStrumienia(ostream& StrmWy,Przeszkoda &Prz);
    /*!
     * \brief Zapis wspolrzednych przeszkody do pliku
     */
    bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku,Przeszkoda &Prz);
    /*!
     * \brief Translacja przeszkody
     */
    void Translatuj(Wektor2D const &WekTranslacji,Przeszkoda &Prz,const char *sNazwaPliku);
};

#endif
