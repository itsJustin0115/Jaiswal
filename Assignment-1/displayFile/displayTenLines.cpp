//Justin Galang
//This code displays the first ten lines inside a .txt file

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


//Gets valid file name
//parameter: filename name of file
//parameter: input file stream name
void get_input_file(string &filename, ifstream &file);

int main()
{
    ifstream readFile;
    string fileName;

    get_input_file(fileName, readFile);

    string lineContent;
    unsigned int lineCounter = 0;
    do
    {
        getline(readFile, lineContent);
        cout << lineContent << endl;
        lineCounter++ ;

        if(readFile.eof())
        {
          cout << "~Entire File Has Been Displayed~" << endl;
          break;
        }

    } while(lineCounter != 10);

    readFile.close();
    return 0;
}

void get_input_file(string &filename, ifstream &file)
{
  bool valid_name = false;

  while(!valid_name)
  {
    cout << "Enter a data file name: ";
    cin >> filename;
    file.open(filename);

    if (file.fail())
    {
      cout << "Cannot Read File Name" << endl;
    }

    else
    {
     cout << "Opening..." << endl;
     valid_name = true;
    }

  }
}
