#ifndef POLE
#define POLE

#include <map>

using namespace std;

class pion;

class pole
{
	friend class pion;
	
	int x_tablicy = 0;
	int y_tablicy = 0;
	int x_bitmapy = 0;
	int y_bitmapy = 0;
		
	int pole_klikniecia_left = 0;
	int pole_klikniecia_right = 0;
	int pole_klikniecia_top = 0;
	int pole_klikniecia_bot = 0;

	public:
		
	pion* wsk_do_piona = NULL;
	
	int get_x_bitmapy(){ return x_bitmapy;};
	int get_y_bitmapy(){ return y_bitmapy;};
	int get_x(){ return x_tablicy;};
	int get_y(){ return y_tablicy;};
	
	bool sprawdzanie_pola( int x, int y )
	{
		if ( ( x > this->pole_klikniecia_left ) && ( x < this->pole_klikniecia_right ) && ( y > this->pole_klikniecia_top ) && ( y < this->pole_klikniecia_bot ) )
		{
			return true;
		}
		return false;
	}
	
				
	pole( int, int, int, int, int, int, int, int );
	pole();
	
	~pole()
	{
	}
};


#endif
