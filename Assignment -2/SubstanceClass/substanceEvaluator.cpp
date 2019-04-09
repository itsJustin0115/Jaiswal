#include <iostream>
#include "Substance.h"

using namespace std;

int main()
{
    Substance substance1 = -306;

    cout << "The temperature of your substance is "
         << substance1.getTemp() << " degrees Fahrenheit." << endl;

    //substance freezes
    if(substance1.isOxygenFreezing())
    {
      cout << "Ethyl freezes at this temperature. \n";
      cout << "Oxygen freezes at this temperature.\n";
      cout << "Water freezes at this temperature. \n";
    }
    else if(substance1.isEthylFreezing())
    {
      cout << "Ethyl freezes at this temperature. \n";
      cout << "Water freezes at this temperature. \n";
    }
    else if(substance1.isWaterFreezing())
    {
      cout << "Water freezes at this temperature. \n";
    }

    //substance boiling
    else if(substance1.isWaterBoiling())
    {
      cout << "Ethyl boils at this temperature. \n";
      cout << "Oxygen boils at this temperature.\n";
      cout << "Water boils at this temperature. \n";
    }
    else if(substance1.isEthylBoiling())
    {
      cout << "Ethyl boils at this temperature.\n";
      cout << "Oxygen boils at this temperature. \n";
    }
    else if(substance1.isOxygenBoiling())
    {
      cout << "Oxygen is boiling at this temperature.\n";
    }
    return 0;
}
