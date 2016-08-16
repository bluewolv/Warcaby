#include "funkcje.h"
#include "pion.h"
#include <cmath>

using namespace std;

pole* wsk_kliknietego_pola = NULL;
pole* wsk_docelowy = NULL;
string poprzedni_kolor = "";

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	
	PAINTSTRUCT ps;
	HDC hdc;
	
	switch(Message) {
		case WM_LBUTTONDOWN:
			{
				int kursor_x = pozycja_wzgledna_x( hwnd );
				int kursor_y = pozycja_wzgledna_y( hwnd );
				//x i y elementu tablicy
				if ( wsk_kliknietego_pola == NULL )
				{
					wsk_kliknietego_pola = sprawdzanie_nr_pola( kursor_x, kursor_y);
					
					if ( wsk_kliknietego_pola->wsk_do_piona == NULL || wsk_kliknietego_pola->wsk_do_piona->get_kolor() == poprzedni_kolor)
					{
						wsk_kliknietego_pola = NULL;
					}
					else
					{
						HDC dc = GetDC(hwnd);
						wsk_kliknietego_pola->wsk_do_piona->zaznaczenie_pion( dc );
						
						InvalidateRect( hwnd, NULL, FALSE);
						SendMessage(hwnd, WM_PAINT, wParam, lParam);
					}
				}
				else
				{
					wsk_docelowy = sprawdzanie_nr_pola( kursor_x, kursor_y);
					
					if ( wsk_docelowy->wsk_do_piona != NULL )
					{
						wsk_kliknietego_pola = NULL;
						wsk_docelowy = NULL;
						InvalidateRect( hwnd, NULL, TRUE);
						SendMessage(hwnd, WM_PAINT, wParam, lParam);
					}
					else
					{
						bool znacznik;
						znacznik = wsk_kliknietego_pola->wsk_do_piona->zbijanie( wsk_docelowy->get_x(), wsk_docelowy->get_y() );
						
						if  ( znacznik == true )
						{
							int xint;
							int yint;
							xint = ( wsk_kliknietego_pola->get_x() + wsk_docelowy->get_x() ) /2 ;
							yint = ( wsk_kliknietego_pola->get_y() + wsk_docelowy->get_y() ) /2 ;;
														
							wsk_kliknietego_pola->wsk_do_piona->zmiana_nr_tablicy( wsk_docelowy->get_x(), wsk_docelowy->get_y() );
							poprzedni_kolor = wsk_kliknietego_pola->wsk_do_piona->get_kolor();
							swap( (wsk_kliknietego_pola->wsk_do_piona), (wsk_docelowy->wsk_do_piona));
							delete (tablica[xint][yint]->wsk_do_piona);
							
							wsk_docelowy->wsk_do_piona->zmiana_krol();
							
							wsk_kliknietego_pola = NULL;
							wsk_docelowy = NULL;
							
							InvalidateRect( hwnd, NULL, TRUE);
							SendMessage(hwnd, WM_PAINT, wParam, lParam);
							
							czy_zostaly_piony( hwnd, poprzedni_kolor);
						}
						else
						{
							znacznik = wsk_kliknietego_pola->wsk_do_piona->mozliwe_ruchy ( wsk_docelowy->get_x(), wsk_docelowy->get_y() );
							if ( znacznik == true )
							{
								wsk_kliknietego_pola->wsk_do_piona->zmiana_nr_tablicy( wsk_docelowy->get_x(), wsk_docelowy->get_y() );
								poprzedni_kolor = wsk_kliknietego_pola->wsk_do_piona->get_kolor();
								swap( (wsk_kliknietego_pola->wsk_do_piona), (wsk_docelowy->wsk_do_piona));
								
								wsk_docelowy->wsk_do_piona->zmiana_krol();
								
								wsk_kliknietego_pola = NULL;
								wsk_docelowy = NULL;
								
								InvalidateRect( hwnd, NULL, TRUE);
								SendMessage(hwnd, WM_PAINT, wParam, lParam);
							}
							else
							{
								wsk_kliknietego_pola = NULL;
								wsk_docelowy = NULL;
								InvalidateRect( hwnd, NULL, TRUE);
								SendMessage(hwnd, WM_PAINT, wParam, lParam);
							}
						}
					}
				}
							
				break;
			}
		
		case WM_PAINT:
			{
				hdc = BeginPaint( hwnd, &ps );

				rysowanie_tablicy( hdc );
				
				EndPaint( hwnd, &ps);
				break;
			}
		case WM_KEYUP:
			{
				if ( wParam == VK_ESCAPE )
				{
					restart( hwnd, poprzedni_kolor);
				}
				break;
			}
		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			destruktor_pole();
			PostQuitMessage(0);
			
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = CreatePatternBrush ( bitmapa() );
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(hInstance, "Warcaby.ico"); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(hInstance, "A"); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Warcaby",CS_DROPSHADOW|WS_VISIBLE|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		585, /* width */
		750, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	inicjalizacja_tablicy();
	inicjalizacja_pionow();
	
	ShowWindow(hwnd, nCmdShow);
  	UpdateWindow(hwnd);
	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
