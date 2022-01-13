#include <iostream>
#include <fstream>
#include "studentList.h"

using namespace std;

void ShowMenu();            

int main ()
{
  StudentList s1;            // creates an object of type StudentList

  char userChoice;           // stores the letter the user enters in for the menu 
  char inputFile [31];      
  char exportFile [31];      

  ShowMenu();
  cout << ">";
  cin >> userChoice;

  while ((userChoice != 'q') && (userChoice != 'Q'))
  {
    if ((userChoice == 'i') || (userChoice == 'I'))
    {  // import students from a file
      cin.ignore(20, '\n');
      cout << "Enter filename: ";
      cin >> inputFile;
      if (s1.ImportFile(inputFile) == false)
      {
        cout << "Invalid file. No data imported \n";
      }    
    }
    else if ((userChoice == 's') || (userChoice == 'S'))
    {  // show student list
       s1.ShowList();
    }
    else if ((userChoice == 'e') || (userChoice == 'E'))
    {  // export a grade report (to a file)
      cin.ignore(20, '\n');
      cout << "Enter filename: ";
      cin >> exportFile;
      if (s1.CreateReportFile(exportFile) == false)
      {
        cout << "Invalid file. No data imported \n";
      }
    }
    else if ((userChoice == 'm') || (userChoice == 'M'))
    {  // show the menu
      ShowMenu();
    }
    else if ((userChoice == 'o') || (userChoice == 'O'))
    {  // sort the student list alphabetically 
      s1.Sort();
    }
    else if ((userChoice != 'q') && (userChoice != 'Q'))
    {  // if the user enters in any other character
      cout << "Invalide menu choice. Try again.";
    }
    cout << "\n>";
    cin >> userChoice;
  }

  cout << "\nGoodbye!\n";

  return 0;
}

void ShowMenu() 
{
  cout << "                *** Student List menu *** \n"; // 9 spaces before *
  cout << "        I       Import students from a file \n"; // 7 spaces after I
  cout << "        S       Show students list (brief) \n";
  cout << "        E       Export a grade report (to file) \n";
  cout << "        M       Show this Menu \n";
  cout << "        Q       Quit Program \n";
  cout << "        O       Sort student list \n";
}
