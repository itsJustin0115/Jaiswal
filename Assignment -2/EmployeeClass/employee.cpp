#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
  string name;
  int idNumber;
  string department;
  string position;

public:

  Employee()
  {
    name = "";
    idNumber = 0;
    department = "";
    position = "";
  }
  Employee(string enteredName, int ID)
  {
    name = enteredName;
    idNumber = ID;
    department = "";
    position = "";
  }
  Employee(string enteredName,
           int ID,
           string enteredDepartment,
           string enteredPosition )
  {
    name = enteredName;
    idNumber = ID;
    department = enteredDepartment;
    position = enteredPosition;
  }

  void setName(string userName)
  {
    name = userName;
  }
  void setID (int userID)
  {
    idNumber = userID;
  }
  void setDepartment(string departmentName)
  {
    department = departmentName;
  }
  void setPosition (string positionName)
  {
    position = positionName;
  }


  string getName()
  {
    return this->name;
  }

  int getID()
  {
    return this->idNumber;
  }

  string getDepartment()
  {
    return this->department;
  }

  string getPosition()
  {
    return this->position;
  }

  string stringify()
  {
    string stringReturn = this->name;
    stringReturn += ", ";
    stringReturn += to_string(this->idNumber);
    stringReturn += ", ";
    stringReturn += this->department;
    stringReturn += ", ";
    stringReturn += this ->position;
    return stringReturn;

  }


};

int main()
{
    Employee susan("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee mark("Mark Jones", 39119, "IT", "Programmer");
    Employee joy("Joy Rogers", 81774, "Manufacturing", "Engineer");

    cout << susan.stringify() << endl;
    cout << mark.stringify() << endl;
    cout << joy.stringify() << endl;

    return 0;
}
