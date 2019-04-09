#include <iostream>
#include <string>

using namespace std;

class DayOfYear
{
private:

  static const unsigned int DAYSOF_JAN = 31;
  static const unsigned int DAYSOF_FEB = DAYSOF_JAN + 28;
  static const unsigned int DAYSOF_MAR = DAYSOF_FEB + 31;
  static const unsigned int DAYSOF_APR = DAYSOF_MAR + 30;
  static const unsigned int DAYSOF_MAY = DAYSOF_APR + 31;
  static const unsigned int DAYSOF_JUN = DAYSOF_MAY + 30;
  static const unsigned int DAYSOF_JUL = DAYSOF_JUN + 31;
  static const unsigned int DAYSOF_AUG = DAYSOF_JUL + 31;
  static const unsigned int DAYSOF_SEP = DAYSOF_AUG + 30;
  static const unsigned int DAYSOF_OCT = DAYSOF_SEP + 31;
  static const unsigned int DAYSOF_NOV = DAYSOF_OCT + 30;
  static const unsigned int DAYSOF_DEC = DAYSOF_NOV + 31;
  int day;
  string month;

  string monthOf(unsigned int day)
  {

    if(day < DAYSOF_JAN )
      return "January";
    else if( day > DAYSOF_JAN && day < DAYSOF_FEB )
      return "February";
    else if( day > DAYSOF_FEB && day < DAYSOF_MAR )
      return "March";
    else if( day > DAYSOF_MAR && day < DAYSOF_APR )
      return "April";
    else if( day > DAYSOF_APR && day < DAYSOF_MAY )
      return "May";
    else if( day > DAYSOF_MAY && day < DAYSOF_JUN )
      return "June";
    else if( day > DAYSOF_JUN && day < DAYSOF_JUL )
      return "July";
    else if( day > DAYSOF_JUL && day < DAYSOF_AUG )
      return "August";
    else if( day > DAYSOF_AUG && day < DAYSOF_SEP )
      return "September";
    else if( day > DAYSOF_SEP && day < DAYSOF_OCT )
      return "October";
    else if( day > DAYSOF_OCT && day < DAYSOF_NOV )
      return "November";
    else if( day > DAYSOF_NOV && day < DAYSOF_DEC )
      return "December";

  }

public:

  DayOfYear(unsigned int enterDay )
  {
    if (monthOf(enterDay) == "January")
    {
      day = enterDay;
      month = "January";
    }
    else if( monthOf(enterDay) == "February" )
    {
      day = enterDay - DAYSOF_JAN;
      month = "February";
    }
    else if( monthOf(enterDay) == "March" )
    {
      day = enterDay - DAYSOF_FEB;
      month = "March";
    }
    else if( monthOf(enterDay) == "April" )
    {
      day = enterDay - DAYSOF_MAR;
      month = "April";
    }
    else if( monthOf(enterDay) == "May" )
    {
      day = enterDay - DAYSOF_APR;
      month = "May";
    }
    else if( monthOf(enterDay) == "June" )
    {
      day = enterDay - DAYSOF_MAY;
      month = "June";
    }
    else if( monthOf(enterDay) == "July" )
    {
      day = enterDay - DAYSOF_JUN;
      month =  "July";
    }
    else if( monthOf(enterDay) == "August" )
    {
      day = enterDay - DAYSOF_JUL;
      month =  "August";
    }
    else if( monthOf(enterDay) == "September" )
    {
      day = enterDay - DAYSOF_AUG;
      month = "September";
    }
    else if( monthOf(enterDay) == "October" )
    {
      day = enterDay - DAYSOF_SEP;
      month =  "October";
    }
    else if( monthOf(enterDay) == "November" )
    {
      day = enterDay - DAYSOF_OCT;
      month =  "November";
    }
    else if( monthOf(enterDay) == "December" )
    {
      day = enterDay - DAYSOF_NOV;
      month =  "December" ;
    }
  }

  void print()
  {
    cout << (this -> day) << " " << (this -> month) << endl;
  }


};


int main()
{
    DayOfYear test(45);
    DayOfYear day2();
    test.print();
    day2.print();
    return 0;
}
