#include "pole.h"
#include "funkcje.h"


pole::pole()
{	
}

pole::pole( int a, int b, int bit_x, int bit_y, int pole_left, int pole_right, int pole_top, int pole_bottom )
{
	x_tablicy = a;
	y_tablicy = b;
	x_bitmapy = bit_x;
	y_bitmapy = bit_y;
	pole_klikniecia_left = pole_left;
	pole_klikniecia_right = pole_right;
	pole_klikniecia_top = pole_top;
	pole_klikniecia_bot = pole_bottom;
}
