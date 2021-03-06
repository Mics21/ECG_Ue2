#include "dda_line_tool.h"
#include <algorithm>
#include <iostream>


// Initialize the tool and store a reference of a canvas_store
dda_line_tool::dda_line_tool(canvas_store& canvas): abstract_tool(canvas)
{
	shape = TS_LINE;
}




// Draw a line from (x0, y0) to (x1, y1)
void dda_line_tool::draw(int x0, int y0, int x1, int y1)
{
	/************
	Task 3.1.1.    Implement the DDA algorithm to raster a line from (x0, y0)
	               to (x1, y1). To set a pixel use "canvas.set_pixel(x, y)" where
				   "x" and "y" is the desired pixel position. This method 
				   handles border violations. Establish the standard case in the
				   first step. If you need to swap the value of two variables you
				   can use the method "std::swap(a, b)".
	Aufgabe 3.1.1. Implementieren Sie den DDA-Algorithmus um eine Linie von
	               (x0, y0) nach (x1, y1) zu rastern. Verwenden Sie
				   "canvas.set_pixel(x, y)" um einen Pixel zu setzen, wobei
				   "x" und "y" den gew�nschten Pixelpositionen entsprechen.
				   Diese Methode behandelt auch Randverletzungen. Stellen Sie zunaechst
				   den Standardfall her. Falls Sie den Wert zweier Variablen vertauschen
				   muessen koennen Sie daf�r die Methode "std::swap(a, b)" verwenden.
   *************/

	/*** 	R�ckf�hrung auf den Standardfall	***/


	//Sonderfall: senkrechte Linie --> schlie�t (delta y/>0<) aus 
	if(x0 == x1){
		for(int yi = y0; yi <= y1; yi++){ 
			canvas.set_pixel(x0, yi);
		}
		return;
	}
	//Steigung m
	float m = (float) (y1-y0)/(x1-x0);


	float y;

	  
	if(m <= 1 && m >= -1){ //Winkel zwischen -45 und 45 Grad
		if(x0 > x1){ // falsche Pfeilrichtung
			// p <--> q
			swap(x0, x1);
			swap(y0, y1);

			if(y0 > y1){ //zwischen -45 und 0 Grad   
				// y <--> -y
				y0 = -y0;
				y1 = -y1;
				y = y0;
				m = (float) (y1-y0)/(x1-x0);		// Neuberechnung des Anstiegs notwendig!!!!!
				for(int xi = x0; xi <= x1; xi++){ 
					int yi = floor(y + 0.5);
					canvas.set_pixel(xi, -yi);
					y = y + m;
				}
			}else{
				//Standardfall
				y = y0;
				for(int xi = x0; xi <= x1; xi++){ 
					int yi = floor(y + 0.5);
					canvas.set_pixel(xi, yi); 
					y = y + m;
				}
			}
		}else{ //richtige Pfeilrichtung
			if(y0 < y1){ //zwischen -45 und 0 Grad	
				// y <--> -y
				y0 = -y0;
				y1 = -y1;
				y = y0;
				m = (float) (y1-y0)/(x1-x0);		// Neuberechnung des Anstiegs notwendig!!!!!
				for(int xi = x0; xi <= x1; xi++){ 
					int yi = floor(y + 0.5);
					canvas.set_pixel(xi, -yi); 
					y = y + m;
				}
			}else{
				y = y0;
				for(int xi = x0; xi <= x1; xi++){ 
					int yi = floor(y + 0.5);
					canvas.set_pixel(xi, yi); 
					y = y + m;	
				}
			}
		}
	}else{ // Winkel gr��er als 45 und kleiner als -45 Grad
		if(x0 > x1){ // falsche Pfeilrichtung
			// p <--> q
			swap(x0, x1);
			swap(y0, y1);

			if(y0 < y1){ 
				// x <--> y
				swap(x0, y0);
				swap(x1, y1);
				y = y0;
				m = (float) (y1-y0)/(x1-x0);		// Neuberechnung des Anstiegs notwendig!!!!!
				for(int xi = x0; xi <= x1; xi++){ 
					int yi = floor(y + 0.5);
					canvas.set_pixel(yi, xi); 
					y = y + m;
				}
			}else{ 
				// x <--> -y
				y0 = -y0;
				y1 = -y1;
				swap(x0, y0);
				swap(x1, y1);
				y = y0;
				m = (float) (y1-y0)/(x1-x0);		// Neuberechnung des Anstiegs notwendig!!!!!
				for(int xi = x0; xi <= x1; xi++){ 
					int yi = floor(y + 0.5);
					canvas.set_pixel(yi, -xi); 
					y = y + m;
				}


			}
		}else{ // richtige Pfeilrichtung
			if(y0 < y1){ // Pfeil zeigt nach rechts oben > / <
				// x <--> y
				swap(x0, y0);
				swap(x1, y1);
				y = y0;
				m = (float) (y1-y0)/(x1-x0);		// Neuberechnung des Anstiegs notwendig!!!!!
				for(int xi = x0; xi <= x1; xi++){ 
					int yi = floor(y + 0.5);
					canvas.set_pixel(yi, xi); //gerundetes yi
					y = y + m;
				}
			}else{
				// x <--> -y
				y0 = -y0;
				y1 = -y1;
				swap(x0, y0);
				swap(x1, y1);
				y = y0;
				m = (float) (y1-y0)/(x1-x0);		// Neuberechnung des Anstiegs notwendig!!!!!
				for(int xi = x0; xi <= x1; xi++){ 
					int yi = floor(y + 0.5);
					canvas.set_pixel(yi, -xi);
					y = y + m;
				}
			}
		}
	}
}



// Put debug output into the stream "stream" to be displayed in the
// main window
void dda_line_tool::set_text(stringstream& stream)
{
	stream<<"Tool: DDA-Line (click and drag mouse to draw)";
}