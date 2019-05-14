#include "Robot.hpp"

/*!
 * \file
 * \brief Definicje metod klasy Robot
 *
 * Zawiera definicje metod klasy Robot.
 */
//-------------------------------------------------------------------

/*!
 * Wylicza kierunek ruchu robota, bedacy wektorem jednostkowym
 *
 * \return Zwraca zmienna _Kierunek typu Wektor2D
 */
Wektor2D Robot::WyliczKierunek(Robot &Rob){

    Wektor2D W1; //pomocniczy wektor srodek miedzy W3,W6
    
    W1=Rob[2]+Rob[5];
    W1[0]=W1[0]/2;
    W1[1]=W1[1]/2;
    
    _Kierunek[0]=(Rob[1][0]-W1[0])/5;
    _Kierunek[1]=(Rob[1][1]-W1[1])/5;
    
    return _Kierunek;
}
//-------------------------------------------------------------------

/*!
 * Wylicza srodek robota korzystajac ze wzoru
 * na srodek odcinka
 * \return Zwraca zmienna _Srodek typu Wektor2D
 */
Wektor2D Robot::ObliczSrodek(Robot &Rob){
    
    _Srodek[0]=(Rob[2][0]+Rob[5][0])/2;
    _Srodek[1]=(Rob[2][1]+Rob[5][1])/2;
    
    return _Srodek;
}
//-------------------------------------------------------------------
/*!
 * Wylicza srodek robota o wspolrzednych globalnych 
 * korzystajac ze wzoru na srodek odcinka
 * \return Zwraca zmienna _Srodek typu Wektor2D
 */
Wektor2D Robot::ObliczSrodekGlobalny(Robot &Rob){
    
    _Srodek[0]=(Rob(2)[0]+Rob(5)[0])/2;
    _Srodek[1]=(Rob(2)[1]+Rob(5)[1])/2;
    
    return _Srodek;
}

//--------------------------------------------------------------------
/*!
 * Wylicza promien okregu opisanego na robocie
 * korzystajac ze wzoru na dlugosc odcinka
 * \return Zwraca zmienna _Promien typu double
 */
double Robot::ObliczPromien(Robot &Rob){
    
    _Promien=sqrt(pow(_Srodek[0]-Rob[1][0],2)+pow(_Srodek[1]-Rob[1][1],2));
    
    return _Promien;
}
//-------------------------------------------------------------------

/*!
 * Sprawdza czy nie doszlo do kolizji robota z 
 * przeszkoda. Do kolizji doszlo kiedy srodek robota
 * znajduje sie w obszarze ograniczonym polem przeszkody,
 * ktorej kazdy z bokow poszerzony jest o dlugosc promienia robota
 * \return Zwraca zmienna true (doszlo do kolizji) lub false (nie doszlo
 * do kolizji) typu bool
 */
bool Robot::CzyKolizja(Robot &Rob,Przeszkoda &Prz1,Przeszkoda &Prz2,Przeszkoda &Prz3){
    Rob.ObliczSrodek(Rob);
    Rob.ObliczPromien(Rob);
    if(_Srodek[0]>Prz1[0][0]-_Promien && _Srodek[0]<Prz1[1][0]+_Promien
       && _Srodek[1]>Prz1[0][1]-_Promien && _Srodek[1]<Prz1[2][1]+_Promien){
        
        cout<<"NASTAPILA KOLIZJA ROBOTA Z PRZESZKODA !!"<<endl;
        return true;
    }
    if(_Srodek[0]>Prz2[0][0]-_Promien && _Srodek[0]<Prz2[1][0]+_Promien
       && _Srodek[1]>Prz2[0][1]-_Promien && _Srodek[1]<Prz2[2][1]+_Promien){
        
        cout<<"NASTAPILA KOLIZJA ROBOTA Z PRZESZKODA !!!"<<endl;
        return true;
    }
    if(_Srodek[0]>Prz3[0][0]-_Promien && _Srodek[0]<Prz3[1][0]+_Promien
       && _Srodek[1]>Prz3[0][1]-_Promien && _Srodek[1]<Prz3[2][1]+_Promien){
        
        cout<<"NASTAPILA KOLIZJA ROBOTA Z PRZESZKODA !!"<<endl;
        return true;
    }else return false;
}
//-------------------------------------------------------------------

/*!
 * Sprawdza czy nie doszlo do kolizji robota z
 * robotem. Do kolizji doszlo kiedy odleglosc srodkow robotow jest mniejsza
 * od sumy promieni robotow
 * \return Zwraca zmienna true (doszlo do kolizji) lub false (nie doszlo
 * do kolizji) typu bool
 */
bool Robot::CzyKolizjaZRobotem(Robot &Rob1,Robot &Rob2){
    
    double SumaPromienii=Rob1.ObliczPromien(Rob1)+Rob2.ObliczPromien(Rob2);
    
    Wektor2D Polozenie1,Polozenie2;
    Polozenie1=Rob1.ObliczSrodek(Rob1);
    Polozenie2=Rob2.ObliczSrodek(Rob2);
    
    double Odleglosc;
    Odleglosc=sqrt(pow(Polozenie1[0]-Polozenie2[0],2)+pow(Polozenie1[1]-Polozenie2[1],2));
    
    if(Odleglosc<=SumaPromienii){
        
        cout<<"NASTAPILA KOLIZJA ROBOTA Z ROBOTEM !!"<<endl;
        return true;
    }else return false;
}
//-------------------------------------------------------------------

/*!
 * Osobna metoda do zapisu wspolrzednych robota do strumienia, ze
 * wzgledu na niereguralny ksztalt robota
 */
void Robot::ZapisWspolrzednychDoStrumienia(ostream& StrmWy,Robot &Rob)
{
    
    StrmWy   << setw(16) << fixed << setprecision(10) << Rob[0][0]
             << setw(16) << fixed << setprecision(10) << Rob[0][1] << endl;
    StrmWy   << setw(16) << fixed << setprecision(10) << Rob[1][0]
             << setw(16) << fixed << setprecision(10) << Rob[1][1] << endl;
    StrmWy   << setw(16) << fixed << setprecision(10) << Rob[2][0]
             << setw(16) << fixed << setprecision(10) << Rob[2][1] << endl;
    StrmWy   << setw(16) << fixed << setprecision(10) << Rob[3][0]
             << setw(16) << fixed << setprecision(10) << Rob[3][1] << endl;
    StrmWy   << setw(16) << fixed << setprecision(10) << Rob[4][0]
             << setw(16) << fixed << setprecision(10) << Rob[4][1] << endl;
    StrmWy   << setw(16) << fixed << setprecision(10) << Rob[5][0]
             << setw(16) << fixed << setprecision(10) << Rob[5][1] << endl;
    
    // Jeszcze raz zapisujemy pierwszy punkt, aby gnuplot narysowal zamkniętą linię.
    StrmWy   << setw(16) << fixed << setprecision(10) << Rob[1][0]
             << setw(16) << fixed << setprecision(10) << Rob[1][1] << endl;
}
//-------------------------------------------------------------------

/*!
 * Osobna metoda do zapisu wspolrzednych robota do pliku, ze
 * wzgledu na niereguralny ksztalt robota
 */
bool Robot::ZapisWspolrzednychDoPliku(const char *sNazwaPliku,Robot &Rob)
{
    ofstream  StrmPlikowy;
    
    StrmPlikowy.open(sNazwaPliku);
    if (!StrmPlikowy.is_open())  {
        cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
        << ":(  nie powiodla sie." << endl;
        return false;
    }
    
    ZapisWspolrzednychDoStrumienia(StrmPlikowy,Rob);
    
    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}
//-------------------------------------------------------------------
/*!
 * Wykonuje obrot robota o zadany kat. Przenosi robota do punktu 0,0
 * aby obrocic go wzgledem poczatku ukladu wspolrzednych, a nastepnie
 * wraca do polozenia przed obrotem
 */
void Robot::ObrocRobota(double const &Kat,Robot &Rob,const char *sNazwaPlikuR){
    
    Macierz2x2 MacRotacji=Rob.ObliczMacierz(Kat);
    
    Wektor2D SrodekUkladu;
    SrodekUkladu[0]=0; SrodekUkladu[1]=0;
    
    Wektor2D WekTranslacji1,WekTranslacji2;
    WekTranslacji1=SrodekUkladu-Rob.ObliczSrodekGlobalny(Rob);
    WekTranslacji2=Rob.ObliczSrodek(Rob);
    
    //Przeniesienie do punktu 0,0
    Rob(0)=Rob(0)+WekTranslacji1;
    Rob(1)=Rob(1)+WekTranslacji1;
    Rob(2)=Rob(2)+WekTranslacji1;
    Rob(3)=Rob(3)+WekTranslacji1;
    Rob(4)=Rob(4)+WekTranslacji1;
    Rob(5)=Rob(5)+WekTranslacji1;
    
    Rob[0]=(Rob(0)*MacRotacji)+WekTranslacji2;
    Rob[1]=(Rob(1)*MacRotacji)+WekTranslacji2;
    Rob[2]=(Rob(2)*MacRotacji)+WekTranslacji2;
    Rob[3]=(Rob(3)*MacRotacji)+WekTranslacji2;
    Rob[4]=(Rob(4)*MacRotacji)+WekTranslacji2;
    Rob[5]=(Rob(5)*MacRotacji)+WekTranslacji2;
    
    //Powrot do poprzedniego punktu
    Rob(0)=Rob(0)-WekTranslacji1;
    Rob(1)=Rob(1)-WekTranslacji1;
    Rob(2)=Rob(2)-WekTranslacji1;
    Rob(3)=Rob(3)-WekTranslacji1;
    Rob(4)=Rob(4)-WekTranslacji1;
    Rob(5)=Rob(5)-WekTranslacji1;
    
    Rob.ZapisWspolrzednychDoPliku(sNazwaPlikuR,Rob);
}
//-------------------------------------------------------------------
/*!
 * Wykonuje ruch na wprost o wektor jednostkowy i zapisuje wierzcholek przed i po ruchu
 * do wspolrzednych sciezki
 */
void Robot::WykonajRuchNaWprost(Robot &Rob,const char *sNazwaPlikuR,const char *sNazwaPlikuS){
    
    double DlugoscKroku=Rob.WezDlugosc(); //dlugosc elementarnego kroku robota
    Wektor2D Kierunek=Rob.WyliczKierunek(Rob); //kierunek ruchu robota
    Wektor2D Srodek=Rob.ObliczSrodek(Rob); //srodek robota w chwili wykonywania funkcji
    
    _Sciezka.WstawWierzcholek(Srodek); // <- licz wierzcholek sciezki nr. 'n'
    
    Rob[0]=Rob[0]+Kierunek;
    Rob[1]=Rob[1]+Kierunek;
    Rob[2]=Rob[2]+Kierunek;
    Rob[3]=Rob[3]+Kierunek;
    Rob[4]=Rob[4]+Kierunek;
    Rob[5]=Rob[5]+Kierunek;
    
    _Sciezka.WstawWierzcholek(Srodek); // <- licz wierzcholek sciezki nr. 'n+1'
    
    _Sciezka.ZapisWspolrzednychDoPliku(sNazwaPlikuS,_Sciezka);
    Rob.ZapisWspolrzednychDoPliku(sNazwaPlikuR,Rob);
    
    usleep(1000000/DlugoscKroku);
}
//-------------------------------------------------------------------
/*!
 * Wykonuje ruch na wprost o wektor jednostkowy i zapisuje wierzcholek przed i po ruchu
 * do wspolrzednych sciezki
 */

void Robot::Translatuj(Wektor2D const &WekTranslacji,Robot &Rob,
                       const char *sNazwaPlikuR,const char *sNazwaPlikuS){
    
    Rob[0]=Rob[0]-WekTranslacji;
    Rob[1]=Rob[1]-WekTranslacji;
    Rob[2]=Rob[2]-WekTranslacji;
    Rob[3]=Rob[3]-WekTranslacji;
    Rob[4]=Rob[4]-WekTranslacji;
    Rob[5]=Rob[5]-WekTranslacji;
    
    for(int i=0; i<(int)_Sciezka.ZwrocIloscWierzcholkow(); ++i){
        _Sciezka[i]=_Sciezka[i]-WekTranslacji;
    }// <- przesun w przeciwnym kierunku WekTranslacji
    // wszystkie wierzcholki Sciezki
    
    _Sciezka.ZapisWspolrzednychDoPliku(sNazwaPlikuS,_Sciezka);
    Rob.ZapisWspolrzednychDoPliku(sNazwaPlikuR,Rob);    
}
//---------------------------------------------------------------------


