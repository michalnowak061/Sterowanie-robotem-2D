#include "Modul.hpp"

Wektor2D operator*(Wektor2D &Wek,Macierz2x2 &Mac){
    
    Wektor2D Wynik;
    
    Wynik[0]=Mac.Wez(0,1)*Wek[1]+Mac.Wez(0,0)*Wek[0];
    Wynik[1]=Mac.Wez(1,1)*Wek[1]+Mac.Wez(1,0)*Wek[0];
    
    return Wynik;
}

