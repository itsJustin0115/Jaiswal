#include "Coin.h"

Coin::Coin()
{
  int result = (rand()%2);
  if(result == 1)
  {
    sideUp = "tails";
  }
  else if(result == 0)
  {
    sideUp = "heads";
  }

}

void Coin::toss()
{
  int result = (rand()%2);
  if(result == 1)
  {
    sideUp = "tails";
  }
  else if(result == 0)
  {
    sideUp = "heads";
  }
}

void Coin::setSideUp(string newSide)
{
  sideUp = newSide;
}


string Coin::getSideUp()
{
  return sideUp;
}
