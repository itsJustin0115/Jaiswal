//Justin Galang
//This program Reads, Writes, and Modifies a given record of divisions


#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>
using namespace std;

struct Division
{
  string divisionName;
  int divisionID;
  double sales;
  unsigned int year;
};

//displays a given division
//parameter: a struct Division
void displayDivision(const Division &division );


//displays a whole record of divisions
//parameter: vector of divisions
void displayRecord( const vector<Division> divlist );


//Adds a division to the file
//parameter: vector of divisions
//parameter: name of the file
void addDivision( vector<Division> &list, string filename );

//Allows you to edit divisions on the record
//parameter: vector of divisions
//parameter: name of the file
void editDivision( vector<Division> &divlist, const string filename );

//retrieves name of file
//parameter: name of the file
void get_input_file(string &filename);

//retrieves user option
//parameter: user option
void mainMenu(string &option);

//Creates Vector of Divisions from a file
//parameter: vector name
//parameter: name of the file
void setup(vector<Division> &divlist, const string filename);

//Gets new name of division
//parameter: name variable
void getNewName(string &newName );


//Gets new ID of division
//parameter: ID variable
void getNewID(int &newID);


//Gets new Sales of division
//parameter: Sales variable
void getNewSales(double &newSales);


//Gets new name of division
//parameter: year variable
void getNewYear(unsigned int &newYear);

//puts information from file into a vector
//parameter: the string containing the contents in a line of the file
//parameter: where the contents separate
//parameter: vector that contains tokens after they've been separated
void split(const string &line, char delimiter, vector<string>& tokens);



const unsigned ID_WIDTH = 14;
const unsigned SALES_WIDTH = 11;
const unsigned YEAR_WIDTH = 12;


int main()
{
  cout << "-Division Editor- \n\n";
  string filename;
  fstream file;
  get_input_file(filename);

  vector<Division> divlist;
  setup(divlist, filename);

  //file.open( filename, ios::in | ios::out );

  string choice;
  mainMenu(choice);

  if(toupper(choice.front()) == 'S' )
  {
    displayRecord(divlist);
  }
  else if (toupper(choice.front()) == 'A' )
  {
    addDivision(divlist, filename);
  }
  else if (toupper(choice.front()) == 'E' )
  {
    editDivision(divlist, filename);
  }
  else if (toupper(choice.front()) == 'Q' )
  {
    cout << "Quitting Program... \n" ;
  }

  return 0;
}

void displayDivision(const Division &division )
{
  cout << division.divisionName << endl
       << "ID:" << left << setw(ID_WIDTH) << right << division.divisionID
       << endl
       << "Sales:" << left << setw(SALES_WIDTH) << right << division.sales
       << endl
       << "Year:" << left << setw(YEAR_WIDTH) << right << division.year;
}

void get_input_file(string &filename)
{

  bool valid_name = false;

  while(!valid_name)
  {
    cout << "\nType in a file name or type \"create\" to create a new file."
         << endl
         << "-> ";
    cin >> filename;

    fstream file;
    if (filename == "create" || filename == "Create")
    {
      /*
      CREATE NEW RECORD NAME FILE.
      -ASK NAME
      -CREATE NAME + (.TXT)
      -SET NAME + (.TXT) = FILENAME
      */
      //bool validName = false;
      string newFileName;
     // while(!validName)
      //{

        cout << "Name of new file: ";
        cin >> newFileName;
        newFileName += ".txt";

        ofstream file;
        file.open(newFileName);
        //ATTEMPTED TO DO 'ALREADY EXISTS VALIDATION
        /*if(file.good())
        {
          cout << "\nThis File Name Already Exists\n";
        }
        else
        {
          validName = true;
        }
        */
      //}

    }
    else
    {
      file.open(filename);

      if (file.fail())
      {
        cout << "Cannot Read File Name" << endl;
      }

      else
      {
       cout << "Opening..." << endl;
       file.close();
       valid_name = true;
      }


    }
  }
}

void mainMenu(string &option)
{


  bool validOption = false;

  while(!validOption)
  {

    cout << "Please Press: " << endl
         << "(S) to show all divisions on record" << endl
         << "(A) to add a division to the record" << endl
         << "(E) to edit a division on record" << endl
         << "(Q) to quit" << endl << " -------> ";
    cin >> option;
    if(toupper(option.front()) == 'S' ||
       toupper(option.front()) == 'A' ||
       toupper(option.front()) == 'E' ||
       toupper(option.front()) == 'Q')
    {
      validOption = true;
    }

    else
    {
      cout << "This option is not valid." <<endl;
    }

  }

}

void displayRecord(const vector<Division> divlist)
{
  unsigned int divIndex = 1;
  for(auto division : divlist)
  {
    cout << left << setw(15) << division.divisionName
         << right << "(" << divIndex << ")" << endl
         << "ID:" << left << setw(ID_WIDTH) << right << division.divisionID
         << endl
         << "Sales:" << left << setw(SALES_WIDTH) << right << division.sales
         << endl
         << "Year:" << left << setw(YEAR_WIDTH) << right << division.year
         << "\n\n-----------------\n\n";
    divIndex++;
  }

  cout << "Press Enter to Continue\n";
  cin.get();
  string choice;
  mainMenu(choice);

}

void addDivision( vector<Division> &divlist, string filename )
{
  cout << "Adding Division...";

  bool done = false;
  string newName;
  int newID;
  double newSales;
  unsigned int newYear;


  while(!done)
  {
    getNewName(newName);
    getNewID(newID);
    getNewSales(newSales);
    getNewYear(newYear);
    cout << endl;
    cout << newName << endl
         << "ID:" << left << setw(ID_WIDTH) << right << newID
         << endl
         << "Sales:" << left << setw(SALES_WIDTH) << right << newSales
         << endl
         << "Year:" << left << setw(YEAR_WIDTH) << right << newYear
         << "\n\n-----------------\n\n";



    bool entered = false;
    while(!entered)
    {
      string choice;
      cout << "Is This Correct? (Y/N)" << endl << " ---> ";
      cin >> choice;

      if(tolower(choice.at(0)) == 'y')
      {
        entered = true;
        done = true;
      }
      else if(tolower(choice.at(0)) == 'n')
      {
        cout << "\nRestarting\n";
        entered = true;
      }
      else
      {
        cout << "Choice Not Valid.";
      }
    }
  }
  fstream file;
  file.open(filename, fstream::app );
  file << newName << ','
       << newID << ','
       << newSales<< ','
       << newYear<< endl;
  file.close();

  cout << "ADDED DIVISION";

  divlist.push_back({newName, newID, newSales, newYear});

}

void editDivision( vector<Division> &divlist, const string filename )
{
  unsigned int selection;
  cout << "Select the index of the division you would like to edit.\n";
  cout << " -> ";
  cin >> selection;

  displayDivision(divlist.at(selection));

  /*cout << divlist.at(selection).divisionName << endl
         << "ID:" << left << setw(ID_WIDTH) << right
         << divlist.at(selection).divisionID
         << endl
         << "Sales:" << left << setw(SALES_WIDTH) << right
         << divlist.at(selection).sales
         << endl
         << "Year:" << left << setw(YEAR_WIDTH) << right
         << divlist.at(selection).year
         << "\n\n-----------------\n\n";*/





}

void setup(vector<Division> &divlist, const string filename)
{
  ifstream file;
  file.open(filename);
  string divisions;
  char delimeter = ',';

  while(getline(file, divisions))
  {
    vector<string> tokens;
    split(divisions, delimeter, tokens);
    divlist.push_back({tokens.at(0),
                      static_cast<int>(stoul(tokens.at(1))),
                      static_cast<double>(stoul(tokens.at(2))),
                      static_cast<unsigned int>(stoul(tokens.at(3)))});

  }
  file.close();

}

void getNewName(string &newName )
{
  bool done = false;
  while(!done)
  {
    cout << "\nEnter Division Name: ";
    cin.ignore();
    getline(cin, newName);

    if(newName.empty())
    {
      cout << "Name not valid.";
    }
    else
    {
      done = true;
    }
  }
}

void getNewID(int &newID)
{
  bool done = false;
  while(!done)
  {
    cout << "Enter Division ID: ";
    cin >> newID;


    if(!cin.good())
    {
       cin.clear();
       cin.ignore(INT_MAX, '\n');
       cout << "ID not valid. Please only use integer values. \n";

    }

    else if(newID < 0 )
    {
      cout << "ID cannot be negative. Re-Enter: \n";
    }
    else
    {
      done = true;
    }
  }
}

void getNewSales(double &newSales)
{
  bool done = false;
  while(!done)
  {
    cout << "Enter Division Sales; ";
    cin >> newSales;

    if(!cin.good())
    {
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      cout << "Sales not valid. Re-Enter: \n";
    }
    else
    {
      done = true;
    }
  }
}

void getNewYear(unsigned int &newYear)
{
  bool done = false;
  while(!done)
  {
    cout << "Enter Division Year: ";
    cin >> newYear;


    if(!(cin.good()) && newYear > 0)
    {
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      cout << "Year not valid. Re-Enter: \n";
    }
    else
    {
      done = true;
    }
  }
}

void split(const string& line, char delimiter, vector<string>& tokens)
{

  size_t token_start = 0;
  size_t delim_position = line.find(delimiter);

  while(delim_position != string::npos)
  {
    string token =
      line.substr(token_start, delim_position - token_start);
    tokens.push_back(token);
    delim_position++;
    token_start = delim_position;
    delim_position = line.find(delimiter, delim_position);
    if(delim_position == string::npos)
    {
      token = line.substr(token_start);
      tokens.push_back(token);
    }
  }
}
