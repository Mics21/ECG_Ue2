#include "dda_line_tool.h"
#include <algorithm>


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
				   "x" und "y" den gewünschten Pixelpositionen entsprechen.
				   Diese Methode behandelt auch Randverletzungen. Stellen Sie zunaechst
				   den Standardfall her. Falls Sie den Wert zweier Variablen vertauschen
				   muessen koennen Sie dafür die Methode "std::swap(a, b)" verwenden.
   *************/

	/*** 	Rückführung auf den Standardfall	***/
	//int setStandardCase(int& x0, int& y0, int& x1, int& y1)	
	/* PSEUDO CODE

	if(Winkel <= 45°){
		if(x0 > x1){
			swap(q, p);
			if(y0 > y1){
				swap(y, -y);
			}else{
				//Standardfall
			}
		}else{
			if(y0 > y1){
				swap(y, -y);
			}else{
				//Standardfall
			}
		}
	}else{
		if(y0 > y1){
			swap(p, q);
			if(x0 < x1){
				swap(x, y);
			}else{
				swap(x, -y);
			}
		}else{
			if(x0 < x1){
				swap(x, y);
			}else{
				swap(x, -y);
			}
		}
	}

	*/


	//Steigung m
	float m = (float) abs((y1-y0)/(x1-x0));

	float y = y0;

	for(int xi = x0; xi <= x1; xi++){ 
		y += 0.5;
		//rundet y --> round()-Methode existiert nicht -.-
		//vllt schöner in einer externen round()-Methode
		int yi = (int) y;
		canvas.set_pixel(xi, /*round (s.o.)*/yi);
		y = y - 0.5 + m;
	}
	
}



// Put debug output into the stream "stream" to be displayed in the
// main window
void dda_line_tool::set_text(stringstream& stream)
{
	stream<<"Tool: DDA-Line (click and drag mouse to draw)";
}