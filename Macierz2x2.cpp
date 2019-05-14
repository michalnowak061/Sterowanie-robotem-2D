#include "Macierz2x2.hpp"

/*!
 * \file
 * \brief Definicje metod klasy Macierz2x2
 *
 * Zawiera definicje metod klasy Macierz2x2.
 */
//-------------------------------------------------------------------

/*!
 * Wypisuje zawartosc obiektu klasy Macierz2x2 na wyjscie standardowe
 *
 * \return Zwraca zmienna Strm typu ostream
 */
ostream& operator << (ostream &Strm, const Macierz2x2 &Mac){
    
    for (int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            cout<<Mac._Tab2x2[i][j]<<' ';
            if(j==1) cout<<endl;
        }
    }
    
    return Strm;
}
//-------------------------------------------------------------------

/*!
 * Wstawia do Macierzy2x2 kat wpisany przez uzytkownika
 * oraz wylicza wspolrzedne po obrocie o dany kat
 */
void Macierz2x2::Wstaw_Kat_Oblicz(double K){
    
    double Rad=(K*2*M_PI)/360; // <- zamiana stopni na radiany
    
    _Tab2x2[0][0]=cos(Rad);
    _Tab2x2[0][1]=-sin(Rad);
    _Tab2x2[1][0]=sin(Rad);
    _Tab2x2[1][1]=cos(Rad);
}
//-------------------------------------------------------------------

