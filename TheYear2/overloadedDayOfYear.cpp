#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <bits/stdc++.h>

using namespace std;

class DayOfYear
{
private:

  static const int DAYSOF_JAN = 31;
  static const int DAYSOF_FEB = DAYSOF_JAN + 28;
  static const int DAYSOF_MAR = DAYSOF_FEB + 31;
  static const int DAYSOF_APR = DAYSOF_MAR + 30;
  static const int DAYSOF_MAY = DAYSOF_APR + 31;
  static const int DAYSOF_JUN = DAYSOF_MAY + 30;
  static const int DAYSOF_JUL = DAYSOF_JUN + 31;
  static const int DAYSOF_AUG = DAYSOF_JUL + 31;
  static const int DAYSOF_SEP = DAYSOF_AUG + 30;
  static const int DAYSOF_OCT = DAYSOF_SEP + 31;
  static const int DAYSOF_NOV = DAYSOF_OCT + 30;
  static const int DAYSOF_DEC = DAYSOF_NOV + 31;
  int day;
  string month;

  string monthOf(int day)
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

  bool isValidMonth(string enteredMonth)
  {
    if(  enteredMonth == "January" ||
         enteredMonth == "February" ||
         enteredMonth == "March" ||
         enteredMonth == "April" ||
         enteredMonth == "May" ||
         enteredMonth == "June" ||
         enteredMonth == "July" ||
         enteredMonth == "August" ||
         enteredMonth == "September" ||
         enteredMonth == "October" ||
         enteredMonth == "November" ||
         enteredMonth == "December")
      {
        return true;
      }
      else
      {
        return false;
      }
  }

  DayOfYear(int enterDay)
  {
    if (monthOf(enterDay) == "January" && enterDay != 0)
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
    else
    {
      exit();
    }
  }

  DayOfYear(int enteredDay, string enteredMonth)
  {
    if(enteredDay > 31)
    {
      day = 0;
    }
    else
    {
      day = enteredDay;
    }


    if( !isValidMonth(enteredMonth) )
    {
      month = "null";
    }
    else
    {
      month = enteredMonth;
    }

  }


  void print()
  {
    cout << (this -> day) << " " << (this -> month) << endl;
  }

  const DayOfYear operator++( )
  {
    this -> day += 1;
    //Months with 31 days
    if((this -> month == "January" ||
        this -> month == "March" ||
        this -> month == "May" ||
        this -> month == "July" ||
        this -> month == "August" ||
        this -> month == "October" ||
        this -> month == "December") &&
        this -> day == 32 )
      {
         this -> day = 1;
         if(this -> month == "January")
         {
           this -> month = "February";
         }
         else if(this -> month == "March")
         {
           this -> month = "April";
         }
         else if(month == "May")
         {
           this -> month = "June";
         }
         else if(this -> month == "July")
         {
           this -> month = "August";
         }
         else if(this -> month == "August")
         {
           this -> month = "September";
         }
         else if(this -> month == "October")
         {
           this -> month = "November";
         }
         else if(this -> month == "December")
         {
           this -> month = "January";
         }
      }

    //Months with 30 days
    else if((this -> month == "April" ||
             this -> month == "June" ||
             this -> month == "September" ||
             this -> month == "November") &&
             this -> day == 31)
            {
               this -> day = 1;
               if(this -> month == "April")
               {
                 this -> month = "May";
               }
               else if(this -> month == "June")
               {
                 this -> month = "July";
               }
               else if(this -> month == "September")
               {
                 this -> month = "October";
               }
               else if(this -> month == "November")
               {
                 this -> month = "December";
               }
            }

    else if(this -> month == "February" && this -> day == 29)
            {
              this -> day = 1;
              this -> month = "March";
            }

    return DayOfYear( this -> day, this -> month);
  }

  const DayOfYear operator++( int )
  {
    DayOfYear temp (this -> day, this -> month);

    this -> day += 1;
    //Months with 31 days
    if((this -> month == "January" ||
        this -> month == "March" ||
        this -> month == "May" ||
        this -> month == "July" ||
        this -> month == "August" ||
        this -> month == "October" ||
        this -> month == "December") &&
        this -> day == 32 )
      {
         this -> day = 1;
         if(this -> month == "January")
         {
           this -> month = "February";
         }
         else if(this -> month == "March")
         {
           this -> month = "April";
         }
         else if(month == "May")
         {
           this -> month = "June";
         }
         else if(this -> month == "July")
         {
           this -> month = "August";
         }
         else if(this -> month == "August")
         {
           this -> month = "September";
         }
         else if(this -> month == "October")
         {
           this -> month = "November";
         }
         else if(this -> month == "December")
         {
           this -> month = "January";
         }
      }

    //Months with 30 days
    else if((this -> month == "April" ||
             this -> month == "June" ||
             this -> month == "September" ||
             this -> month == "November") &&
             this -> day == 31)
          {
             this -> day = 1;
             if(this -> month == "April")
             {
               this -> month = "May";
             }
             else if(this -> month == "June")
             {
               this -> month = "July";
             }
             else if(this -> month == "September")
             {
               this -> month = "October";
             }
             else if(this -> month == "November")
             {
               this -> month = "December";
             }
          }

    else if(this -> month == "February" && this -> day == 29)
            {
              this -> day = 1;
              this -> month = "March";
            }

    return temp;
  }

  const DayOfYear operator--( )
  {
    this -> day -= 1;
    if((this -> month == "May" ||
        this -> month == "July" ||
        this -> month == "October" ||
        this -> month == "December") &&
        this -> day == 0 )
      {
         this -> day = 30;

         if(month == "May")
         {
           this -> month = "April";
         }
         else if(this -> month == "July")
         {
           this -> month = "June";
         }
         else if(this -> month == "October")
         {
           this -> month = "September";
         }
         else if(this -> month == "December")
         {
           this -> month = "November";
         }
      }


    else if((this -> month == "January" ||
             this -> month == "February" ||
             this -> month == "April" ||
             this -> month == "June" ||
             this -> month == "August" ||
             this -> month == "September" ||
             this -> month == "November") &&
             this -> day == 0)
          {
             this -> day = 31;

             if(this -> month == "January")
             {
               this -> month = "December";
             }
             else if(this -> month == "February")
             {
               this -> month = "January";
             }
             else if(this -> month == "April")
             {
               this -> month = "March";
             }
             else if(this -> month == "June")
             {
               this -> month = "May";
             }
             else if(this -> month == "August")
             {
               this -> month = "July";
             }
             else if(this -> month == "September")
             {
               this -> month = "August";
             }
             else if(this -> month == "November")
             {
               this -> month = "October";
             }
          }

          else if(this -> month == "March" && this -> day == 0)
          {
            this -> day = 28;
            this -> month = "February";
          }

    return DayOfYear( this -> day, this -> month);
  }

  const DayOfYear operator--( int )
  {

    DayOfYear temp (this -> day, this -> month);

    this -> day -= 1;
    if((this -> month == "May" ||
        this -> month == "July" ||
        this -> month == "October" ||
        this -> month == "December") &&
        this -> day == 0 )
    {
       this -> day = 30;

       if(month == "May")
       {
         this -> month = "April";
       }
       else if(this -> month == "July")
       {
         this -> month = "June";
       }
       else if(this -> month == "October")
       {
         this -> month = "September";
       }
       else if(this -> month == "December")
       {
         this -> month = "November";
       }
    }


    else if((this -> month == "January" ||
             this -> month == "February" ||
             this -> month == "April" ||
             this -> month == "June" ||
             this -> month == "August" ||
             this -> month == "September" ||
             this -> month == "November") &&
             this -> day == 0)
    {
       this -> day = 31;

       if(this -> month == "January")
       {
         this -> month = "December";
       }
       else if(this -> month == "February")
       {
         this -> month = "January";
       }
       else if(this -> month == "April")
       {
         this -> month = "March";
       }
       else if(this -> month == "June")
       {
         this -> month = "May";
       }
       else if(this -> month == "August")
       {
         this -> month = "July";
       }
       else if(this -> month == "September")
       {
         this -> month = "August";
       }
       else if(this -> month == "November")
       {
         this -> month = "October";
       }
    }

    else if(this -> month == "March" && this -> day == 0)
    {
      this -> day = 28;
      this -> month = "February";
    }

    return temp;
  }


};




int main()
{
    DayOfYear day2(60);
    DayOfYear test2(31, "March");

    day2.print();
    test2.print();

    test2++;
    day2--;
    test2.print();
    day2.print();



    return 0;
}
