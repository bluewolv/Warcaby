#ifndef PION
#define PION

#include <windows.h>
#include <string>

#include "funkcje.h"

using namespace std;

class pion
{
	string kolor_piona;
	bool krol = false;
		
	int x_tab = 0;
	int y_tab = 0;
		
	public:
		void rysowanie( HDC& kontekst_okna_pion )
		{
			HBITMAP bitmapa_piona = bit_pion( kolor_piona, krol );
			
			HDC hdc_bitmapy = CreateCompatibleDC ( kontekst_okna_pion );
			SelectObject(hdc_bitmapy,bitmapa_piona);
			BitBlt (kontekst_okna_pion, tablica[x_tab][y_tab]->get_x_bitmapy(), tablica[x_tab][y_tab]->get_y_bitmapy(), 42, 65, hdc_bitmapy, 0, 0, SRCCOPY);
			DeleteDC( hdc_bitmapy );
		}
		
		void zaznaczenie_pion(HDC& kontekst_okna_pion)
		{
			HBITMAP bitmapa_piona = zaznaczenie();
			HDC hdc_bitmapy = CreateCompatibleDC ( kontekst_okna_pion );
			SelectObject(hdc_bitmapy,bitmapa_piona);
			BitBlt (kontekst_okna_pion, ( tablica[x_tab][y_tab]->get_x_bitmapy() - 5 ), ( tablica[x_tab][y_tab]->get_y_bitmapy() - 5 ), 52, 72, hdc_bitmapy, 0, 0, SRCCOPY);
			DeleteDC( hdc_bitmapy );
			DeleteDC( kontekst_okna_pion );
		}
		
		string get_kolor()
		{
			return kolor_piona;
		}

		bool mozliwe_ruchy( int x_nowy, int y_nowy )
		{
			if ( (x_nowy+y_nowy)%2 != 0 )
			{
				if ( krol == true )
				{
					if ( y_nowy == (y_tab+1) || y_nowy == (y_tab-1) )
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else if ( kolor_piona == "bialy")
				{
					if ( y_nowy == (y_tab+1) )
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else if ( kolor_piona == "czarny")
				{
					if ( y_nowy == (y_tab-1))
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}

			return false;
		}
		
		bool zbijanie( int x_nowy, int y_nowy )
		{
			if ( (x_nowy+y_nowy)%2 != 0 )
			{
				if ( krol == true )
				{
					if ( y_nowy == y_tab+2 && x_nowy == x_tab+2 )
					{
						if ( (tablica[x_tab+1][y_tab+1]->wsk_do_piona) != NULL )
						{
							if ( (tablica[x_tab+1][y_tab+1]->wsk_do_piona->kolor_piona) != this->kolor_piona)
							{
								return true;	
							}
							else
							{
								return false;
							}
						}
					}
					else if ( y_nowy == y_tab+2 && x_nowy == x_tab-2 )
					{
						if ( (tablica[x_tab-1][y_tab+1]->wsk_do_piona) != NULL )
						{
							if ( (tablica[x_tab-1][y_tab+1]->wsk_do_piona->kolor_piona) != this->kolor_piona )
							{
								return true;	
							}
							else
							{
								return false;
							}
						}
					}
					if ( y_nowy == y_tab-2 && x_nowy == x_tab+2 )
					{
						if ( (tablica[x_tab+1][y_tab-1]->wsk_do_piona) != NULL )
						{
							if ( (tablica[x_tab+1][y_tab-1]->wsk_do_piona->kolor_piona) != this->kolor_piona )
							{
								return true;	
							}
							else
							{
								return false;
							}
						}
					}
					else if ( y_nowy == y_tab-2 && x_nowy == x_tab-2 )
					{
						if ( (tablica[x_tab-1][y_tab-1]->wsk_do_piona) != NULL )
						{
							if ( (tablica[x_tab-1][y_tab-1]->wsk_do_piona->kolor_piona) != this->kolor_piona )
							{
								return true;	
							}
							else
							{
								return false;
							}
						}
					}
				}
				else if ( kolor_piona == "bialy")
				{
					if ( y_nowy == y_tab+2 && x_nowy == x_tab+2 )
					{
						if ( (tablica[x_tab+1][y_tab+1]->wsk_do_piona) != NULL )
						{
							if ( (tablica[x_tab+1][y_tab+1]->wsk_do_piona->kolor_piona) == "czarny")
							{
								return true;	
							}
							else
							{
								return false;
							}
						}
					}
					else if ( y_nowy == y_tab+2 && x_nowy == x_tab-2 )
					{
						if ( (tablica[x_tab-1][y_tab+1]->wsk_do_piona) != NULL )
						{
							if ( (tablica[x_tab-1][y_tab+1]->wsk_do_piona->kolor_piona) == "czarny")
							{
								return true;	
							}
							else
							{
								return false;
							}
						}
					}
					
					return false;
				}
				else if ( kolor_piona == "czarny")
				{
					if ( y_nowy == y_tab-2 && x_nowy == x_tab+2 )
					{
						if ( (tablica[x_tab+1][y_tab-1]->wsk_do_piona) != NULL )
						{
							if ( (tablica[x_tab+1][y_tab-1]->wsk_do_piona->kolor_piona) == "bialy")
							{
								return true;	
							}
							else
							{
								return false;
							}
						}
					}
					else if ( y_nowy == y_tab-2 && x_nowy == x_tab-2 )
					{
						if ( (tablica[x_tab-1][y_tab-1]->wsk_do_piona) != NULL )
						{
							if ( (tablica[x_tab-1][y_tab-1]->wsk_do_piona->kolor_piona) == "bialy")
							{
								return true;	
							}
							else
							{
								return false;
							}
						}
					}
					
					return false;
				}
			}
			return false;
		}
		
		void zmiana_nr_tablicy( int x_nowy, int y_nowy)
		{
			x_tab=x_nowy;
			y_tab=y_nowy;
		}
		
		void zmiana_krol()
		{
			if ( kolor_piona == "bialy" )
			{
				if ( y_tab == 9 )
				{
					krol = true;
				}
			}
			else if ( kolor_piona == "czarny" )
			{
				if ( y_tab == 0 )
				{
					krol = true;
				}
			}
		}
		
		pion( string, int, int );
		pion();
		~pion();
};

#endif


