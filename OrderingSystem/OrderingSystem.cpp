
#include <iostream>
#include "adminLanding.h"
#include "adminLogin.h"
#include <stdio.h>
#include "screenChange.h"

int main()
{
    bool loggedIn = login();
    if (loggedIn) {
        clearScreen();
        adminLanding();
   }
   

}

