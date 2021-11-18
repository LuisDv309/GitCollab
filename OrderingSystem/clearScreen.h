#pragma once

void clearScreen()
{
    cout << "\x1B[2J\x1B[H";
}
