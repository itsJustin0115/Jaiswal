#ifndef COIN_H
#define COIN_H
#include <cstdlib>
#include <string>
#include <iomanip>


using namespace std;

class Coin
{
private:
  string sideUp;
  void setSideUp(string newSide);

public:
  //int rand();
  Coin();
  void toss();
  string getSideUp();
};

#endif // COIN_H
