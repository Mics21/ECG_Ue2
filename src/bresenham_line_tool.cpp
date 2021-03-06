#include "bresenham_line_tool.h"
#include <algorithm>
#include <math.h>

// Initialize the tool and store a reference of a canvas_store
bresenham_line_tool::bresenham_line_tool(canvas_store& canvas): abstract_tool(canvas)
{
	// This tool draws lines!
	shape = TS_LINE;
}




// Draw a line from (x0, y0) to (x1, y1)
void bresenham_line_tool::draw(int x0, int y0, int x1, int y1)
{
	/************
	Task 3.1.2.    Implement the Bresenham algorithm to raster a line from (x0, y0)
	               to (x1, y1). To set a pixel use "canvas.set_pixel(x, y)" where
				   "x" and "y" is the desired pixel position. This method 
				   handles border violations. Establish the standard case in the
				   first step. If you need to swap the value of two variables you
				   can use the method "std::swap(a, b)".
	Aufgabe 3.1.2. Implementieren Sie den Bresenham-Algorithmus um eine Linie von
	               (x0, y0) nach (x1, y1) zu rastern. Verwenden Sie
				   "canvas.set_pixel(x, y)" um einen Pixel zu setzen, wobei
				   "x" und "y" den gewünschten Pixelpositionen entsprechen.
				   Diese Methode behandelt auch Randverletzungen. Stellen Sie zunaechst
				   den Standardfall her. Falls Sie den Wert zweier Variablen vertauschen
				   muessen koennen Sie dafür die Methode "std::swap(a, b)" verwenden.
   *************/

	int x,y;
	int dx,dy,dx1,dy1;
	int px,py;
	int xe,ye;
	int i;
	
	dx = x1 - x0;
	dy = y1 - y0;

	dx1 = abs(dx);
	dy1 = abs(dy);

	px = 2*dy1 - dx1;
	py = 2*dx1 - dy1;

	if(dy1 <= dx1){
		if(dx >= 0){
			x = x0;
			y = y0;
			xe = x1;
		} else {
			x = x1;
			y = y1;
			xe = x0;
		}
		canvas.set_pixel(x,y);
	  
		for(i = 0; x < xe;i++){
			x += 1;
			if(px < 0){
				px = px + 2*dy1;
			} else {
				if((dx < 0 && dy < 0) || (dx > 0 && dy > 0)){
					y += 1;
				} else {
					y -= 1;
				}
				px = px + 2*(dy1 - dx1);
			}
			canvas.set_pixel(x,y);
		}
	} else {
		if(dy >= 0){
		   x = x0;
		   y = y0;
		   ye = y1;
		} else {
		   x = x1;
		   y = y1;
		   ye = y0;
		}
		canvas.set_pixel(x,y);

		for(i = 0;y < ye;i++){
		   y += 1;
		   if(py <= 0){
				py = py + 2*dx1;
			} else {
				if((dx < 0 && dy < 0) || (dx > 0 && dy > 0)){
					x += 1;
				} else {
					x -= 1;
				}
				py = py + 2*(dx1 - dy1);
			}
		   canvas.set_pixel(x,y);
		}
	}
}




// Put debug output into the stream "stream" to be displayed in the
// main window
void bresenham_line_tool::set_text(stringstream& stream)
{
	stream<<"Tool: Bresenham-Line (click and drag mouse to draw)";
}