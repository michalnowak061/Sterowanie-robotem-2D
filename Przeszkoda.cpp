#include "Przeszkoda.hpp"

/*!
 * Osobna metoda do zapisu wspolrzednych robota do strumienia, ze
 * wzgledu na niereguralny ksztalt robota
 */
void Przeszkoda::ZapisWspolrzednychDoStrumienia(ostream& StrmWy,Przeszkoda &Prz)
{
    
    StrmWy   << setw(16) << fixed << setprecision(10) << Prz[0][0]
             << setw(16) << fixed << setprecision(10) << Prz[0][1] << endl;
    StrmWy   << setw(16) << fixed << setprecision(10) << Prz[1][0]
             << setw(16) << fixed << setprecision(10) << Prz[1][1] << endl;
    StrmWy   << setw(16) << fixed << setprecision(10) << Prz[2][0]
             << setw(16) << fixed << setprecision(10) << Prz[2][1] << endl;
    StrmWy   << setw(16) << fixed << setprecision(10) << Prz[3][0]
             << setw(16) << fixed << setprecision(10) << Prz[3][1] << endl;
    
    // Jeszcze raz zapisujemy pierwszy punkt, aby gnuplot narysowal zamkniętą linię.
    StrmWy   << setw(16) << fixed << setprecision(10) << Prz[0][0]
             << setw(16) << fixed << setprecision(10) << Prz[0][1] << endl;
}
//-------------------------------------------------------------------

/*!
 * Osobna metoda do zapisu wspolrzednych robota do pliku, ze
 * wzgledu na niereguralny ksztalt robota
 */
bool Przeszkoda::ZapisWspolrzednychDoPliku(const char *sNazwaPliku,Przeszkoda &Prz)
{
    ofstream  StrmPlikowy;
    
    StrmPlikowy.open(sNazwaPliku);
    if (!StrmPlikowy.is_open())  {
        cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
        << ":(  nie powiodla sie." << endl;
        return false;
    }
    
    ZapisWspolrzednychDoStrumienia(StrmPlikowy,Prz);
    
    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}
//-------------------------------------------------------------------
/*!
 * Dokonuje translacji przeszkody o wektor przeciwny do wektora translacji,
 * w celu uzyskania efektu przesuniecia ekranu
 */
void Przeszkoda::Translatuj(Wektor2D const &WekTranslacji,Przeszkoda &Prz,const char *sNazwaPliku){
    
    Prz[0]=Prz[0]-WekTranslacji;
    Prz[1]=Prz[1]-WekTranslacji;
    Prz[2]=Prz[2]-WekTranslacji;
    Prz[3]=Prz[3]-WekTranslacji;
    
    Prz.ZapisWspolrzednychDoPliku(sNazwaPliku,Prz);
}

