#include <iostream>
#include "Coin.h"
using namespace std;

int main()
{
    const int FLIPCOUNTER = 20;

    unsigned int headCounter = 0;
    unsigned int tailCounter = 0;
    for(unsigned int flips = 0; flips < FLIPCOUNTER; flips++)
    {
      Coin coin1;
      cout << "Flip " << (flips + 1)<< ": ";
      coin1.toss();

      cout << coin1.getSideUp() << endl;
      if(coin1.getSideUp() == "tails")
      {
        tailCounter++;
      }
      else
      {
        headCounter++;
      }
    }

    cout << "\nHeads: " << headCounter;
    cout << "\nTails: " << tailCounter;

    return 0;
}
