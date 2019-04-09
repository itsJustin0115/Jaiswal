//Justin Galang
//This Program Encrypts or Decrypts a given file.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Gets valid file name
//parameter: filename name of file
//parameter: input file stream name
void validateFile(string &filename, ifstream &file);

//encrypts a file
//parameter: filename name of file
//parameter: input file stream name
void fileEncrypt (string &filename, ifstream &file);

//decrypts a file
//parameter: filename name of file
//parameter: input file stream name
void fileDecrypt (string &filename, ifstream &file);

//validates and retrieves the choice of a user
//parameter: user input to select choice
void getChoice (string &choice);

//validates and creates a 3 letter pin
//parameter: place to put selection
//parameter: the phrase that prompts the selection
void getPIN (string &pin, string phrase);

//Turns any string into all uppercase
//parameter: string to turn into upper case
void stringUpper (string &str);



int main()
{

  cout << "-This Program will Encrypt or Decrypt a given file.- \n\n";
  string fileName;
  ifstream secretFile;
  validateFile(fileName, secretFile);

  string choice;
  getChoice(choice);

  if(toupper(choice.front()) == 'E' )
  {
    fileEncrypt(fileName, secretFile);
  }
  else if (toupper(choice.front()) == 'D' )
  {
    fileDecrypt(fileName, secretFile);
  }
  else if (toupper(choice.front()) == 'Q' )
  {
    cout << "Program has been TERMINATED...";
  }

  return 0;
}

void getChoice(string &choice)
{

  bool validChoice = false;

  while(!validChoice)
  {

    cout << "Press:" << endl
         << "(E) to encrypt this file" << endl
         << "(D) to decrypt this file"<< endl
         << "(Q) to quit" << endl << " -------> ";
    cin >> choice;
    if(toupper(choice.front()) == 'E' ||
       toupper(choice.front()) == 'D' ||
       toupper(choice.front()) == 'Q' )
    {
      validChoice = true;
    }
    else
    {
      cout << "This choice is not valid." <<endl;
    }

  }

}

void validateFile(string &filename, ifstream &file)
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
     cout << "Valid File" << endl;
     file.close();
     valid_name = true;
    }

  }
}


void stringUpper (string &str)
{
  for(size_t i = 0; i < str.length(); i++ )
  {
    str.at(i) = toupper(str.at(i));
  }
}



void getPIN (string &pin, string phrase)
{
  bool validPIN = false;

  while(!validPIN)
  {
    cout << phrase;
    cin >> pin;
    stringUpper(pin);

    if( pin.length() > 3 )
    {
      cout << "This PIN is too long." << "\n\n";
    }
    else if ( pin.length() < 3 )
    {
      cout << "This PIN is too short." << "\n\n";
    }
    else
    {
      if( isalpha(pin.at(0)) &&
          isalpha(pin.at(1)) &&
          isalpha(pin.at(2)) )
      {
        validPIN = true;
      }
      else
      {
        cout << "PIN must be letters only." << endl;
      }
    }
  }



}

void fileEncrypt (string &filename, ifstream &file)
{

  string pin;
  string phrase = "Enter A 3 Letter PIN: ";
  getPIN(pin, phrase);
  int shift1 = (pin.at(0) - 64);
  int shift2 = (pin.at(1) - 64);
  int shift3 = (pin.at(2) - 64);

  file.open(filename);

  string outputName = "E_" + filename;
  ofstream encryptedFile(outputName);

  string line;
  while(getline(file, line))
  {
    for(size_t i = 0; i < (line.length()); i += 3)
    {
      if(i < line.length() )
      {
        encryptedFile << static_cast<char>((line.at(i) + shift1));
        if( (i + 1) < line.length())
        {
          encryptedFile << static_cast<char>((line.at(i + 1) + shift2));
          if((i + 2) < line.length() )
          {
            encryptedFile << static_cast<char>((line.at(i + 2) + shift3));
          }
        }
      }
    }
    encryptedFile << endl;
  }

  cout << "\n" << filename << " has been Encrypted with code: " << pin;
  file.close();
}

void fileDecrypt (string &filename, ifstream &file)
{

  string pin;
  string phrase = "\nEnter The 3 Letter PIN: ";
  getPIN(pin, phrase);
  int shift1 = (pin.at(0) - 64);
  int shift2 = (pin.at(1) - 64);
  int shift3 = (pin.at(2) - 64);

  file.open(filename);
  string outputName = "D_" + filename;
  ofstream decryptedFile(outputName);

  string line;
  while(getline(file, line))
  {
    for(size_t i = 0; i < (line.length()); i += 3)
    {
      if(i < line.length() )
      {
        decryptedFile << static_cast<char>((line.at(i) - shift1));
        if( (i + 1) < line.length())
        {
          decryptedFile << static_cast<char>((line.at(i + 1) - shift2));
          if((i + 2) < line.length() )
          {
            decryptedFile << static_cast<char>((line.at(i + 2) - shift3));
          }
        }
      }
    }
    decryptedFile << endl;
  }

  cout << "\n" << filename << " has been Decrypted with code: " << pin;
  file.close();
}





