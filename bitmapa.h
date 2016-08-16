#ifndef BITMAPA
#define BITMAPA

#include "1deklaracje.h"
#include <windows.h>
#include <string>

using namespace std;

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



HBITMAP bit_pion ( string kolor )
{
	HANDLE obraz = NULL;
	
	if ( kolor == "bialy")
	{
		obraz = LoadImage( NULL, "pion_bialy.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
	
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
	
	else if ( kolor == "czarny" )
	{
			obraz = LoadImage( NULL, "pion_czarny.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
	
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
	
	else if ( kolor == "puste" )
	{
			obraz = LoadImage( NULL, "pion_brak.bmp", IMAGE_BITMAP, 0, 0, LR_LOADTRANSPARENT&&LR_LOADFROMFILE );
	
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
} 

#endif
