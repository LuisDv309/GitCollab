//  Reusable functions
//
//  Created by Israel Black

#include <iostream>

using namespace std;

// clears console
void clearScreen()
{
    cout << "\x1B[2J\x1B[H";
}

// drays boundary lines
void makeLine() {
	for (int i = 0; i < 45; i++)
	{
		cout << "-";
	}
}