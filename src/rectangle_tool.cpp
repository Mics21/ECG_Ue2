#include "rectangle_tool.h"
#include <algorithm>


// Initialize the tool and store a reference of a canvas_store
rectangle_tool::rectangle_tool(canvas_store& canvas): abstract_tool(canvas)
{
	shape = TS_BOX;
}



// Draw a box from (x0, y0) to (x1, y1)
void rectangle_tool::draw(int x0, int y0, int x1, int y1)
{
	/************
	Additional task: Implement the rasterization of a rectangle that
	                 ranges from (x0, y0) to (x1, y1).
    Zusatzaufgabe:   Implementieren Sie die Rasterisierung eines
	                 Rechtecks, das von (x0, y0) nach (x1, y1) geht.
	*************/
}



// Put debug output into the stream "stream" to be displayed in the
// main window
void rectangle_tool::set_text(stringstream& stream)
{
	stream<<"Tool: Rectangle (click and drag mouse to draw)";
}