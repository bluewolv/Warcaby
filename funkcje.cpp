#include "pole.h"
#include "pion.h"


using namespace std;


//sk≥adniki pola

int wspolrzedne_bitmapy_x( int x_od_tablicy )
{
	map <int, int> mapa_x ;
	
	for ( int licznik = 0, k = 13; licznik < 8; ++licznik, k+=72 )
	{
		mapa_x[licznik] = k;	
	}
	
	return mapa_x[x_od_tablicy];
}

int wspolrzedne_bitmapy_y( int y_od_tablicy )
{
	map <int, int> mapa_y ;
	
	for ( int licznik = 0, k = 5; licznik < 10; ++licznik, k+=72 )
	{
		mapa_y[licznik] = k;	
	}
	
	return mapa_y[y_od_tablicy];
}

int wspolrzedne_pola_left ( int x_od_tablicy )
{
	map <int, int> mapa_x ;
	
	for ( int licznik = 0, k = 4 ; licznik < 8; ++licznik, k+=72 )
	{
		mapa_x[licznik] = k;
	}
	
	return mapa_x[x_od_tablicy];
}

int wspolrzedne_pola_right ( int x_od_tablicy )
{
	map <int, int> mapa_x ;
	
	for ( int licznik = 0, k = 77 ; licznik < 8; ++licznik, k+=72 )
	{
		mapa_x[licznik] = k;
	}
	
	return mapa_x[x_od_tablicy];
}

int wspolrzedne_pola_top ( int y_od_tablicy )
{
	map <int, int> mapa_y ;
	
	for ( int licznik = 0, k = 25 ; licznik < 10; ++licznik, k+=72 )
	{
		mapa_y[licznik] = k;
	}
	
	return mapa_y[y_od_tablicy];
}

int wspolrzedne_pola_bottom ( int y_od_tablicy )
{
	map <int, int> mapa_y ;
	
	for ( int licznik = 0, k = 99 ; licznik < 10; ++licznik, k+=72 )
	{
		mapa_y[licznik] = k;
	}
	
	return mapa_y[y_od_tablicy];
}

int mniejsza( int a, int b)
{
	if ( a > b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

int wieksza ( int a, int b)
{
	if ( a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}


//wczytywanie bitmap

HBITMAP bitmapa ( void )
{
	
	HANDLE obraz = NULL;
	obraz = LoadImage( NULL, "szachownica.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
	
	if ( obraz == NULL)
	{	
		//MessageBox(NULL, "Bitmapa NIE wczytana!","Potwierdü",MB_ICONEXCLAMATION|MB_OK);
		return NULL;
	}
	else
	{	
		//MessageBox(NULL, "Bitmapa wczytana!","Potwierdü",MB_ICONEXCLAMATION|MB_OK);	
		return (HBITMAP)obraz;
	}
	
}

HBITMAP bit_pion ( string kolor, bool krol )
{
	HBITMAP obraz;
	
	if ( krol == true )
	{
		if ( kolor == "bialy" )
		{
			obraz =(HBITMAP) LoadImage( NULL, "krol_bialy.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
	
			if ( obraz == NULL)
			{	
				//MessageBox(NULL, "Bitmapa NIE wczytana!","Potwierdü",MB_ICONEXCLAMATION|MB_OK);
				return NULL;
			}
			else
			{	
				//MessageBox(NULL, "Bitmapa wczytana!","Potwierdü",MB_ICONEXCLAMATION|MB_OK);	
				return obraz;
			}
		}
		else if ( kolor == "czarny" )
		{
			obraz =(HBITMAP) LoadImage( NULL, "krol_czarny.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
	
			if ( obraz == NULL)
			{	
				//MessageBox(NULL, "Bitmapa NIE wczytana!","Potwierdü",MB_ICONEXCLAMATION|MB_OK);
				return NULL;
			}
			else
			{	
				//MessageBox(NULL, "Bitmapa wczytana!","Potwierdü",MB_ICONEXCLAMATION|MB_OK);	
				return obraz;
			}
		}
	}
	else if ( kolor == "bialy")
	{
		obraz =(HBITMAP) LoadImage( NULL, "pion_bialy.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
	
		if ( obraz == NULL)
		{	
			//MessageBox(NULL, "Bitmapa NIE wczytana!","Potwierdü",MB_ICONEXCLAMATION|MB_OK);
			return NULL;
		}
		else
		{	
			//MessageBox(NULL, "Bitmapa wczytana!","Potwierdü",MB_ICONEXCLAMATION|MB_OK);	
			return obraz;
		}
	}
	
	else if ( kolor == "czarny" )
	{
			obraz = (HBITMAP)LoadImage( NULL, "pion_czarny.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
	
		if ( obraz == NULL)
		{	
			//MessageBox(NULL, "Bitmapa NIE wczytana!","Potwierdü",MB_ICONEXCLAMATION|MB_OK);
			return NULL;
		}
		else
		{	
			//MessageBox(NULL, "Bitmapa wczytana!","Potwierdü",MB_ICONEXCLAMATION|MB_OK);	
			return obraz;
		}
	}
	
	else if ( kolor == "puste" )
	{
			obraz = (HBITMAP)LoadImage( NULL, "pion_brak.bmp", IMAGE_BITMAP, 0, 0, LR_LOADTRANSPARENT|LR_LOADFROMFILE );
	
		if ( obraz == NULL)
		{	
			//MessageBox(NULL, "Bitmapa NIE wczytana!","Potwierdü",MB_ICONEXCLAMATION|MB_OK);
			return NULL;
		}
		else
		{	
			//MessageBox(NULL, "Bitmapa wczytana!","Potwierdü",MB_ICONEXCLAMATION|MB_OK);	
			return obraz;
		}
	}
} 

HBITMAP zaznaczenie()
{
	return (HBITMAP)LoadImage( NULL, "zaznaczenie.bmp", IMAGE_BITMAP,0,0,LR_LOADTRANSPARENT|LR_LOADFROMFILE );
}

//tablica

pole* tablica[8][10];

void inicjalizacja_tablicy()
{
	for ( int licznik = 0; licznik < 8; ++licznik )
	{
		for ( int licznik2 = 0; licznik2 < 10; ++licznik2 )
		{
			tablica[licznik][licznik2] = new pole(licznik, licznik2, wspolrzedne_bitmapy_x( licznik ), wspolrzedne_bitmapy_y( licznik2 ) , wspolrzedne_pola_left(licznik), wspolrzedne_pola_right(licznik), wspolrzedne_pola_top(licznik2), wspolrzedne_pola_bottom(licznik2) );
		}
	}
	
}

void rysowanie_tablicy( HDC& kontekst_okna )
{
	for ( int licznik = 0; licznik < 8; ++licznik )
	{
		for ( int licznik2 = 0; licznik2 < 10; ++licznik2 )
		{
			if	( tablica[licznik][licznik2]->wsk_do_piona != NULL )
			{
				tablica[licznik][licznik2]->wsk_do_piona->rysowanie( kontekst_okna );
			}
		}
	}
	
	DeleteDC( kontekst_okna );
}

void inicjalizacja_pionow()
{
	string kolor_tymcz = "bialy";
	
	for ( int licznik = 0; licznik < 3; licznik+=2 )
	{
		for ( int licznik2 = 1; licznik2 < 8; licznik2+=2 )
		{
			tablica[licznik2][licznik]->wsk_do_piona = new pion (kolor_tymcz, licznik2, licznik);
		}
	}
	
	for ( int licznik = 0; licznik < 7; licznik+=2 )
	{
		tablica[licznik][1]->wsk_do_piona = new pion( kolor_tymcz, licznik, 1 );
	}
	
	kolor_tymcz = "czarny";
	
	for ( int licznik = 7; licznik < 10; licznik+=2 )
	{
		for ( int licznik2 = 0; licznik2 < 7; licznik2+=2 )
		{
			tablica[licznik2][licznik]->wsk_do_piona = new pion (kolor_tymcz, licznik2, licznik);
		}
	}
	
	for ( int licznik = 1; licznik < 8; licznik+=2 )
	{
		tablica[licznik][8]->wsk_do_piona = new pion( kolor_tymcz, licznik, 8 );
	}
}

void destruktor_pole()
{
	for ( int licznik = 0; licznik<8; ++licznik )
	{
		for ( int licznik2 = 0; licznik2<10; ++licznik2 )
		{
			delete (tablica[licznik][licznik2]->wsk_do_piona);
		}
	}

	for ( int licznik = 0; licznik<8; ++licznik )
	{
		for ( int licznik2 = 0; licznik2<10; ++licznik2 )
		{
			delete (tablica[licznik][licznik2]);
		}
	}
}

void czy_zostaly_piony( HWND& hwnd, string poprzedni_kolor)
{
	int licznik_biale = 0;
	int licznik_czarne = 0;
	for ( int licznik = 0; licznik < 8; ++licznik)
	{
		for ( int licznik2 = 0; licznik2<10; ++licznik2)
		{
			if ( tablica[licznik][licznik2]->wsk_do_piona != NULL )
			{
				if ( tablica[licznik][licznik2]->wsk_do_piona->get_kolor() == "bialy" )
				{
					licznik_biale++;
				}
				else if ( tablica[licznik][licznik2]->wsk_do_piona->get_kolor() == "czarny" )
				{
					licznik_czarne++;
				}
			}
		}
	}
	
	if ( licznik_biale == 0 || licznik_czarne == 0 )
	{
		restart(hwnd, poprzedni_kolor);
	}
}

void restart( HWND& hwnd, string poprzedni_kolor )
{
		string a1 = "WYGRAL: ";
		a1+=poprzedni_kolor;
		a1+="\r\n";
		a1+="Czy rozpoczπÊ od nowa?";
		int wiadomosc = MessageBox( hwnd, a1.c_str(), "Koniec Gry", MB_YESNO );
		
		if ( wiadomosc == 7 )
		{
			SendMessage( hwnd, WM_DESTROY, 0, 0);
		}
		else if ( wiadomosc == 6 )
		{
			destruktor_pole();
			
			inicjalizacja_tablicy();
			inicjalizacja_pionow();
			
			UpdateWindow(hwnd);
		}
}

//mysz

int pozycja_wzgledna_x( HWND& hwnd )
{
	RECT pozycja_okna;
	POINT kursor;
	GetWindowRect( hwnd , &pozycja_okna );
	GetCursorPos ( &kursor );
	
	return (kursor.x - pozycja_okna.left);
}

int pozycja_wzgledna_y( HWND& hwnd )
{
	RECT pozycja_okna;
	POINT kursor;
	GetWindowRect( hwnd , &pozycja_okna );
	GetCursorPos ( &kursor );
	
	return (kursor.y - pozycja_okna.top);	
}

pole* sprawdzanie_nr_pola( int szukane_x, int szukane_y )
{
	for	( int licznik = 0; licznik < 8; ++licznik )
	{
		for ( int licznik2 = 0; licznik < 10; ++licznik2 )
		{
			if ( (tablica[licznik][licznik2]->sprawdzanie_pola(szukane_x, szukane_y)) == true )
			{
				return (tablica[licznik][licznik2]);
			}
		}
	}
	
	return NULL;
}
