#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH

/*!
 * \file
 * \brief Definicja klasy Macierz2x2
 *
 * Plik zawiera definicję klasy Macierz2x2
 */

#include <iostream>
#include <math.h>

using namespace std;

/*!
 * \brief Modeluje pojęcie Macierzy2x2
 * niezbednej do wykonania operacji roatcji prostokata
 * o zadany kat
 */
class Macierz2x2 {
    /*!
     * \brief Zawartosc Macierzy2x2
     *
     * Pole zawiera liczby wyliczone przez funkcje
     * Wstaw_Kat_Oblicz(double K)
     */
    double _Tab2x2[2][2];
  public:
    /*!
     * \brief Uzyskuje dostep do pola
     */
    double Wez(int i,int j) {return _Tab2x2[i][j];}
    /*!
     * \brief Wstawia wpisany przez uzytkownika kat i wylicza wartosci odpowiednich 
     * funkcji trygonometrycznych
     */
    void Wstaw_Kat_Oblicz(double K);
    /*!
     * \brief Wypisuje zawartosc macierzy na wyjscie standardowe
     */
    friend ostream& operator << (ostream &Strm, const Macierz2x2 &Mac); 
};

#endif
