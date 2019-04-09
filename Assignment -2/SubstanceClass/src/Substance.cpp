#include "Substance.h"

Substance::Substance(int substanceTemp)
{
  temperature = substanceTemp;
}

//Set&Get
void Substance::setTemp(int substanceTemp)
{
  temperature = substanceTemp;
}

int Substance::getTemp()
{
  return this->temperature;
}

//Bool Functions
bool Substance::isEthylFreezing()
{
  if(this->temperature <= ethylFreezing)
  {
    return true;
  }
  return false;
}

bool Substance::isEthylBoiling()
{
  if(this->temperature >= ethylBoiling)
  {
    return true;
  }
  return false;
}

bool Substance::isOxygenFreezing()
{
  if(this->temperature <= oxygenFreezing)
  {
    return true;
  }
  return false;
}

bool Substance::isOxygenBoiling()
{
  if(this->temperature >= oxygenBoiling)
  {
    return true;
  }
  return false;
}

bool Substance::isWaterFreezing()
{
  if(this->temperature <= waterFreezing)
  {
    return true;
  }
  return false;
}

bool Substance::isWaterBoiling()
{
  if(this->temperature >= waterBoiling)
  {
    return true;
  }
  return false;
}















