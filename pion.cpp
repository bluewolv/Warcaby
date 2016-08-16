#include "pion.h"
#include "funkcje.h"

pion::pion()
{
}

pion::pion( string kolor, int x_taba, int y_taba )
{
	kolor_piona = kolor;
		
	x_tab = x_taba;
	y_tab = y_taba;	
}

pion::~pion()
{
	tablica[x_tab][y_tab]->wsk_do_piona = NULL;
}
