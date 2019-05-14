#include "ZbiorWierzcholkow.hpp"

/*!
 * \file
 * \brief Definicja metody klasy ZbiorWierzcholkow
 *
 * Zawiera definicję metod klasy ZbiorWierzcholkow.
 */

//-------------------------------------------------------------------

/*!
 * Zapisuje wspolrzedne wierzcholkow do strumienia
 */
void ZbiorWierzcholkow::ZapisWspolrzednychDoStrumienia(ostream& StrmWy)
{
    for(int i=0; i<(int)ZwrocIloscWierzcholkow();++i){// <- zapisz tyle razy ile jest wierzcholkow
    StrmWy   << setw(16) << fixed << setprecision(10) << _Wierzcholki[i][0]
             << setw(16) << fixed << setprecision(10) << _Wierzcholki[i][1] << endl;
    }
    StrmWy   << setw(16) << fixed << setprecision(10) << _Wierzcholki[0][0]
             << setw(16) << fixed << setprecision(10) << _Wierzcholki[0][1] << endl;
}
//-------------------------------------------------------------------

/*!
 * Zapisuje wspolrzedne wierzcholkow do pliku .dat
 *
 * \return False jesli operacja zapisu sie nie powiodla lub true
 * jesli sie powiodla
 */
bool ZbiorWierzcholkow::ZapisWspolrzednychDoPliku(const char *sNazwaPliku)
{
    ofstream  StrmPlikowy;
    
    StrmPlikowy.open(sNazwaPliku);
    if (!StrmPlikowy.is_open())  {
        cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
        << ":(  nie powiodla sie." << endl;
        return false;
    }
    
    ZapisWspolrzednychDoStrumienia(StrmPlikowy);
    
    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}
//-------------------------------------------------------------------
