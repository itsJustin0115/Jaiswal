#include <iostream>

using namespace std;

//To know the car's make, model, color, license number, and the number of
//minutes that the car has been parked
class ParkedCar
{
  private:
    string make;
    string model;
    string color;
    string licensePlate;
    int minutes;

  public:
    ParkedCar(string make)
              /* = "Car",
              string model = " ",
              string color = " ",
              string licensePlate = " ",
              int minutes = 0)*/
             {
                make = make;
                model = model;
                color = color;
                licensePlate = licensePlate;
                minutes = minutes;
             }




    void print()
    {
      cout << this->make;
    }


};


//To know the number of minutes of parking time that has been purchased
class ParkingMeter
{
  unsigned int purchasedMinutes;
};

class ParkingTicket
{
  private:
    ParkedCar offender;
    double fine;

};

class PoliceOfficer
{
  string name;
  unsigned int badgeNumber;

};

int main()
{
    ParkedCar car("Ford");
    car.print();


    return 0;
}
