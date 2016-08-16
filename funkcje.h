#ifndef DEKLARACJE
#define DEKLARACJE

#include <windows.h>
#include <string>
#include <sstream>
#include "pole.h"


using namespace std;

//funkcje:
int wspolrzedne_bitmapy_x( int );
int wspolrzedne_bitmapy_y( int );
int wspolrzedne_pola_left ( int );
int wspolrzedne_pola_right ( int );
int wspolrzedne_pola_top ( int );
int wspolrzedne_pola_bottom ( int );
int wieksza ( int, int );
int mniejsza ( int, int );

void restart( HWND&, string );


//bitmapa:
HBITMAP bitmapa ( void );
HBITMAP bit_pion ( string, bool );
HBITMAP zaznaczenie();

//pole:

//pion:

//class pion;

//tablica:
extern pole* tablica[][10];
void inicjalizacja_tablicy();
void rysowanie_tablicy( HDC& );
void inicjalizacja_pionow();
void destruktor_pole();
void czy_zostaly_piony( HWND&, string);

//mysz:
int pozycja_wzgledna_x( HWND& );
int pozycja_wzgledna_y( HWND& );
pole* sprawdzanie_nr_pola( int, int );

#endif
