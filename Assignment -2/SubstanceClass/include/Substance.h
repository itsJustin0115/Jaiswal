#ifndef SUBSTANCE_H
#define SUBSTANCE_H

class Substance
{

  private:
    int temperature;
    static const int ethylFreezing = -173;
    static const int ethylBoiling = 172;
    static const int oxygenFreezing = -362;
    static const int oxygenBoiling = -306;
    static const int waterFreezing = 32;
    static const int waterBoiling = 212;

  public:
    Substance(int substanceTemp = 0);
    //Set&Get
    void setTemp(int substanceTemp);
    int getTemp();
    //Bool Functions
    bool isEthylFreezing();
    bool isEthylBoiling();
    bool isOxygenFreezing();
    bool isOxygenBoiling();
    bool isWaterFreezing();
    bool isWaterBoiling();
};

#endif // SUBSTANCE_H
