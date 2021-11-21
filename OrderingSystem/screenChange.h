#pragma once

#include <iostream>

using namespace std;

void clearScreen()
{
    cout << "\x1B[2J\x1B[H";
}

void makeLine() {
	for (int i = 0; i < 45; i++)
	{
		cout << "-";
	}
}