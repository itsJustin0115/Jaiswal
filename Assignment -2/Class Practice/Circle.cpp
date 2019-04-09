#include <iostream>

using namespace std;


class Circle
{
private:

  double radius;
  static constexpr double PI  = 3.145;

public:

  Circle()
  {
    radius = 0;
  }

  Circle(double r)
  {
    radius = r;
  }

  double setRadius(double r)
  {
    radius = r;
  }

  double getRadius()
  {
    return this -> radius;
  }

  double getArea()
  {
    double area = PI *
                  this -> radius *
                  this -> radius;

    return area;
  }



};
int main()
{
  Circle circle1;
  Circle circle2(4.5);

  Circle circles1[5];
  Circle circles2[5] = { Circle(12),
                        Circle(7),
                        Circle(9),
                        Circle(14),
                        Circle(18) };

  unsigned int counter = 1;
  for (Circle index : circles2)
  {
    cout << "Circle " << counter << ": " ;
    cout << index.getArea();
    cout << endl;
    counter++;
  }

  return 0;
}
