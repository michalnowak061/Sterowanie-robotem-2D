#include "Wektor2D.hpp"

/*!
 * \file
 * \brief Definicja metody klasy Wektor2D
 *
 * Zawiera definicję metod klasy Wektor2D.
 */

//-------------------------------------------------------------------
/*!
 * Wpisuje wspolrzedne z wejscia standardowego do obiektu
 * klasy Wektor2D
 *
 * \return Zwraca zmienna Strm typu ostream
 */
istream& operator >> (istream &Strm, Wektor2D &Wek){
    
    for (int i=0;i<2;++i){
        float x;
        cin>>x;
        Wek._Tab2D[i]=x;
    }
    
    return Strm;
}
//-------------------------------------------------------------------
/*!
 * Wypisuje zawartosc obiektu klasy Wektor2D na wyjscie standardowe
 *
 * \return Zwraca zmienna Strm typu ostream
 */
ostream& operator << (ostream &Strm, const Wektor2D &Wek){
    
    for ( double ElemTab : Wek._Tab2D){
        cout << ElemTab <<' ';
    }
    
    return Strm;
}
//-------------------------------------------------------------------
/*!
 * Wykonuje translacje Wektora2D o W_translacji poprzez
 * dodanie tych dwoch wektorow
 *
 * \return Zwraca Wektor2D ktory jest wynikiem dodawania
 */
Wektor2D Wektor2D::operator+(const Wektor2D &W_translacji){
    
    Wektor2D wynik;
    
    wynik[0]=_Tab2D[0]+W_translacji[0];
    wynik[1]=_Tab2D[1]+W_translacji[1];
    
    return wynik;
}
//-------------------------------------------------------------------
/*!
 * Wykonuje translacje Wektora2D o W_translacji poprzez
 * odjecie tych dwoch wektorow
 *
 * \return Zwraca Wektor2D ktory jest wynikiem odejmowania
 */
Wektor2D Wektor2D::operator-(const Wektor2D &W_translacji){
    
    Wektor2D wynik;
    
    wynik[0]=_Tab2D[0]-W_translacji[0];
    wynik[1]=_Tab2D[1]-W_translacji[1];
    
    return wynik;
}
//-------------------------------------------------------------------
/*!
 * Wstawia poczatkowe wspolrzedne wektora
 */
void Wektor2D::WstawPoczatkoweWspolrzedne(double i,double j){
    
    _Tab2D[0]=i;
    _Tab2D[1]=j;
}

//-------------------------------------------------------------------

double Wektor2D::LicznikStworzonych = 0; // <- nadanie poczatkowej wartosci polu statycznemu
double Wektor2D::LicznikAktualny = 0; // <- nadanie poczatkowej wartosci polu statycznemu




