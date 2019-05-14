#include "Sciezka.hpp"

/*!
 * \file
 * \brief Definicje metod klasy Sciezka
 *
 * Zawiera definicje metod klasy Sciezka.
 */
//-------------------------------------------------------------------

/*!
 * \brief Zapis wspolrzednych do strumienia w petli wykonujacej sie tyle 
 * razy z ilu wierzcholkow sklada sie sciezka
 */
void Sciezka::ZapisWspolrzednychDoStrumienia(ostream& StrmWy,Sciezka &Sciez)
{
    for(int i=0; i<(int)(ZwrocIloscWierzcholkow()); ++i){
    StrmWy   << setw(16) << fixed << setprecision(10) << Sciez[i][0]
             << setw(16) << fixed << setprecision(10) << Sciez[i][1] << endl;
    }// <- zapisz wszystkie wierzcholki
}
//-------------------------------------------------------------------

/*!
 * \brief Zapis wspolrzednych do pliku, w celu narysowania ich w Gnuplocie
 */
bool Sciezka::ZapisWspolrzednychDoPliku(const char *sNazwaPliku,Sciezka &Sciez)
{
    ofstream  StrmPlikowy;
    
    StrmPlikowy.open(sNazwaPliku);
    if (!StrmPlikowy.is_open())  {
        cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
        << ":(  nie powiodla sie." << endl;
        return false;
    }
    
    ZapisWspolrzednychDoStrumienia(StrmPlikowy,Sciez);
    
    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}
//-------------------------------------------------------------------

