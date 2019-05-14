#include "Scena.hpp"

/*!
 * \file
 * \brief Definicje metod klasy Scena
 *
 * Zawiera definicje metod klasy Scena.
 */
//-------------------------------------------------------------------

/*!
 * Dokonuje rotacji robota o zadany przez uzytkownika
 * kat. Rotacja odbywa sie na wierzcholkach w globalnym 
 * ukladzie wspolrzednych, aby uniknac akumulacji bledow.
 * Po dokonaniu rotacji wracamy do lokalnego ukladu wspolrzednych
 */
void Scena::ObrocRobota(double const &Kat,int i){
    
    if(i==1){
        _Robot1.ObrocRobota(Kat,_Robot1,"robot1.dat");
    }
    if(i==2){
        _Robot2.ObrocRobota(Kat,_Robot2,"robot2.dat");
    }
    if(i==3){
        _Robot3.ObrocRobota(Kat,_Robot3,"robot3.dat");
    }
}
//-------------------------------------------------------------------

/*!
 * Wykonuje tranlacje robota o wektor jednostkowy. 
 * \return 1 jesli dojdzie do kolizji
 * \return 0 jesli nie dojdzie do kolizji
 */
int Scena::WykonajRuchNaWprost(double &Odleglosc,int i){
    
    if(i==1){
        _Robot1.WykonajRuchNaWprost(_Robot1,"robot1.dat","sciezka1.dat");
    
        if(_Robot1.CzyKolizja(_Robot1,_Przeszkoda1,_Przeszkoda2,_Przeszkoda3)==true) return 1;
        if(_Robot1.CzyKolizjaZRobotem(_Robot1,_Robot2)==true) return 1;
        if(_Robot1.CzyKolizjaZRobotem(_Robot1,_Robot3)==true) return 1;
    }
    if(i==2){
        _Robot2.WykonajRuchNaWprost(_Robot2,"robot2.dat","sciezka2.dat");
        
        if(_Robot2.CzyKolizja(_Robot2,_Przeszkoda1,_Przeszkoda2,_Przeszkoda3)==true) return 1;
        if(_Robot2.CzyKolizjaZRobotem(_Robot2,_Robot1)==true) return 1;
        if(_Robot2.CzyKolizjaZRobotem(_Robot2,_Robot3)==true) return 1;
    }
    if(i==3){
        _Robot3.WykonajRuchNaWprost(_Robot3,"robot3.dat","sciezka3.dat");
        
        if(_Robot3.CzyKolizja(_Robot3,_Przeszkoda1,_Przeszkoda2,_Przeszkoda3)==true) return 1;
        if(_Robot3.CzyKolizjaZRobotem(_Robot3,_Robot1)==true) return 1;
        if(_Robot3.CzyKolizjaZRobotem(_Robot3,_Robot2)==true) return 1;
    }
    
        return 0;
}
//-------------------------------------------------------------------

/*!
 * Wykonuje tranlacje wszystkich obiektow znajdujacych
 * sie na scenie. Wektor translacji zadany jest przez 
 * uzytkownika. Przesuniecie odbywa sie w przeciwnym
 * kierunku przez co mamy wrazenie ze obraz sie przesuwa
 */
void Scena::TranslatujRysunek(Wektor2D const &WekTranslacji){
    
    _Robot1.Translatuj(WekTranslacji,_Robot1,"robot1.dat","sciezka1.dat");
    _Robot2.Translatuj(WekTranslacji,_Robot2,"robot2.dat","sciezka2.dat");
    _Robot3.Translatuj(WekTranslacji,_Robot3,"robot3.dat","sciezka3.dat");
    
    _Przeszkoda1.Translatuj(WekTranslacji,_Przeszkoda1,"przeszkoda1.dat");
    _Przeszkoda2.Translatuj(WekTranslacji,_Przeszkoda2,"przeszkoda2.dat");
    _Przeszkoda3.Translatuj(WekTranslacji,_Przeszkoda3,"przeszkoda3.dat");
}
//-------------------------------------------------------------------
