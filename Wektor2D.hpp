#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

/*!
 * \file
 * \brief Definicja klasy Wektor2D
 * Plik zawiera definicję klasy Wektor2D
 */

#include <iostream>

using namespace std;

/*!
 * \brief Modeluje pojęcie Wektora 2D
 * zawierajacego dwie liczby
 * bedace jednoczesnie wspolrzednymi wierzcholka prostokata
 */
class Wektor2D {
    /*!
     * \brief Zawartosc Wektora2D
     *
     * Pole zawiera dwie liczby bedace wspolrzednymi
     * Wektora2D
     */
    double _Tab2D[2];
    /*!
     * \brief Pole statyczne zawierajace liczbe wszystkich stworzonych obiektow
     */
    static double LicznikStworzonych;
    /*!
     * \brief Pole statyczne zawierajace liczbe aktualnie istniejacych obiektow
     */
    static double LicznikAktualny;
    
public:
    /*!
     * \brief Uzyskuje dostep do pola
     */
    double operator[](int i) const {return _Tab2D[i];}
    /*!
     * \brief Uzyskuje dostep do pola i pozwala na jego modyfikacje
     */
    double &operator[](int i) {return _Tab2D[i];}
    /*!
     * \brief Dokonuje translacji o W_translacji
     */
    Wektor2D operator+(const Wektor2D &W_translacji);
    /*!
     * \brief Dokonuje translacji o W_translacji
     */
    Wektor2D operator-(const Wektor2D &W_translacji);
    /*!
     * \brief Wstawia poczatkowe wspolrzedne wektroa
     */
    void WstawPoczatkoweWspolrzedne(double i,double j);
    /*!
     * \brief Wpisuje wspolrzedne z wejscia standardowego
     */
    friend istream& operator >> (istream &Strm, Wektor2D &Wek);
    /*!
     * \brief Wypisuje wspolrzedne na wyjscie standardowe
     */
    friend ostream& operator << (ostream &Strm, const Wektor2D &Wek);
    /*!
     * \brief Uzyskuje dostęp do pola static int Licznik
     */
    static double WezLicznikStworzonych(){return LicznikStworzonych;}
    /*!
     * \brief Uzyskuje dostęp do pola static int Licznik
     */
    static double WezLicznikAktualny(){return LicznikAktualny;}
    /*!
     * \brief Konstruktor zwiekszajacy liczbe aktualnie istniejacych obiektow
     * i liczbe wszsystkich stworzonych obiektow
     */
    Wektor2D(){++LicznikStworzonych; ++LicznikAktualny;}
    /*!
     * \brief Konstruktor kopiujacy wywolywany podczas
     * kopiowania obiektow
     */
    Wektor2D(Wektor2D const &r)
        : Wektor2D(){
        _Tab2D[0] = r._Tab2D[0];
        _Tab2D[1] = r._Tab2D[1];
        }
    /*!
     * \brief Destruktor zmniejszajacy liczbe obiektow
     */
    ~Wektor2D(){--LicznikAktualny;}
    
    
    
    
};

#endif
