#include <iostream>
#include "clsLoginScreen.h"
using namespace std;

#include"clsDate.h"
#include"clsUtil.h"
int main()
{

    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }
  
    

    return 0;
}

