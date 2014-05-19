#include "recursive_fill_tool.h"

// Initialize the tool and store a reference of a canvas_store
recursive_fill_tool::recursive_fill_tool(canvas_store& canvas): abstract_tool(canvas)
{
	// This tool has no shape and is not draggable
	shape = TS_NONE;
	is_draggable = false;
}

// Vector for max recursion depth
vector<int> depth;


// Function to get maximum recursion depth
int recursive_fill_tool::maxrec(){
	int size = depth.size();
	int max = 0;
	for(int i = 0; i < size; i++){
		if(depth.back() > max) max = depth.back();
			depth.pop_back();
	}
		return max;
	
}



// Fill the shape that contains the point (x, y)
void recursive_fill_tool::draw(int x, int y)
{
	/************
	Task 3.2.1.    Implement the recursive fill algorithm by checking the
				   state of the neighbouring pixels (via "canvas.get_pixel(x, y)"
				   where "x" and "y" defines the position to check) and recursively
				   call "draw" if the pixel is not set. A pixel can be set with
				   "canvas.set_pixel(x, y)".
				   This method will make the application crash if the area which shall 
				   be filled is too big.
	Aufgabe 3.2.1. Implementieren Sie den rekursiven Füllalgorithmus, indem Sie den
				   Zustand der Nachbarpixel überprüfen (mittels "canvas.get_pixel(x, y)"
				   wobei "x" und "y" die Position des zu überprüfenden Pixels definieren)
				   und rufen Sie rekursiv die "draw"-Methode auf, wenn die Pixel nicht 
				   gesetzt sind. Ein Pixel kann durch "canvas.set_pixel(x, y)" gesetzt
				   werden.
	*************/
	int z = 0;
	depth.push_back(z);

	if(canvas.get_pixel(x, y)){
		return;
		
	}else{
		canvas.set_pixel(x, y);
	}
	draw(x - 1, y, z);
	draw(x + 1, y, z);
	draw(x, y - 1, z);
	draw(x, y + 1, z);

	cout << "Maximale Tiefe der Rekursion: " << maxrec() << endl;
 
}


// Fill the shape that contains the point (x, y)
void recursive_fill_tool::draw(int x, int y, int z)
{	
	z++;
	depth.push_back(z);
	if(canvas.get_pixel(x, y)){
		return;
	}else{
		canvas.set_pixel(x, y);
	}
	draw(x - 1, y, z);
	draw(x + 1, y, z);
	draw(x, y - 1, z);
	draw(x, y + 1, z);
 
}



// Put debug output into the stream "stream" to be displayed in the
// main window
void recursive_fill_tool::set_text(stringstream& stream)
{
	stream<<"Tool: Recursive Fill (click to fill)";
}