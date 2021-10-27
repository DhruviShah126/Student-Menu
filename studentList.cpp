#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include "studentList.h"

using namespace std;

StudentList::StudentList()               
{   
  size = 0;                        // initilizes an empty array
  students = new Student*[size];   // creates a dynamic array 
                                   // of pointers of type
                                   // Student
}

StudentList:: ~StudentList()        
{
  for (int i = 0; i < size; i++)
  {
    delete students[i];            // deletes all the objects of
                                   // the array that each element
                                   // of the array was pointing to
  } 
  delete [] students;              // deletes the array
}

bool StudentList::ImportFile(const char* filename)
{
  int numStudents = 0;
  int qz1 = 0;
  int qz2 = 0;
  int qz3 = 0;
  int qz4 = 0;
  int qz5 = 0;
  int tst1 = 0;
  int tst2 = 0;
  int exam = 0;
  int termP = 0;
  int midt = 0;                    // midterm
  int a = 0;                       // attendance 
  int p = 0;                       // project
  int temp = size;

  string nameLast, nameFirst, course;

  ifstream inFile;
  inFile.open(filename);           // try to open the file
  if (!inFile)
  {                                // if the file does not open, return false
    return false;
  }

  inFile >> numStudents;
  Grow(numStudents);               // grow the array based on the number of 
                                   // students there are
  inFile.ignore(1, '\n');          // ignore the new line character
  for (int i = 0; i < numStudents; i++)
  {                                // loop until the number of students
      getline(inFile, nameLast, ',');
                                   // read until the , and store in nameLast
                                   // which is the last name of the student
                                   // and throw the comma away
      inFile.ignore(1, ' ');       // ignore the space
      getline(inFile, nameFirst);  // read until new line character and store
                                   // in nameFirst which is the first name
                                   // of the student and throw new line 
                                   // character away
      getline(inFile, course, ' ');// read until the new line character and
                                   // store it in course
      if (course == "Math")
      {                            // if the student is a math student
        inFile >> qz1;             // read in the first integer and store
                                   // it in qz1 which is the first quiz grade
        inFile.ignore(1, ' ');     // ignore the space
        inFile >> qz2;             // read in the second integer and store
                                   // it in qz2 which is the second quiz grade
        inFile.ignore(1, ' ');     // ignore the space
        inFile >> qz3;             // read in the third integer and store
                                   // it in qz3 which is the third quiz grade
        inFile.ignore(1, ' ');     // ignore the space 
        inFile >> qz4;             // read in the fourth integer and store
                                   // it in qz4 which is the fourth quiz grade
        inFile.ignore(1, ' ');     // ignore the space
        inFile >> qz5;             // read in the fifth integer and store
                                   // it in qz5 which is the fifth quiz grade
        inFile.ignore(1, ' ');     // ignore the space
        inFile >> tst1;            // read in the integer and store it in tst1 
                                   // which is the first test grade
        inFile.ignore(1, ' ');     // ignore the space
        inFile >> tst2;            // read in the integer and store it in tst2 
                                   // which is the second test grade
        inFile.ignore(1, ' ');     // ignore the space
        inFile >> exam;            // read in the integer and store it in exam 
                                   // which is the final exam grade
        inFile.ignore(1, '\n');    // read until the new line and throw the 
                                   // character away
        Math *m = new Math(nameLast, nameFirst, qz1, qz2, qz3, qz4, qz5, tst1, 
                           tst2, exam, course);
                                   // dynamically allocate a new object of type 
                                   // math called m
        students[temp] = m;        // store the pointer to that object in position 
                                   // temp of array students
      }
      else if (course == "History")
      {                            // same procedure as above but now it is
                                   // based on data needed for a history 
                                   // student 
        inFile >> termP;
        inFile.ignore(1, ' ');
        inFile >> midt;
        inFile.ignore(1, ' ');
        inFile >> exam;
        inFile.ignore(1, '\n');
        History *h = new History(nameLast, nameFirst, termP, midt, exam, course);
        students[temp] = h;
      }
      else
      {                            // if the course is english
                                   // same procedure as above but now it is     
                                   // based on data needed for an english 
                                   // student
        inFile >> a;
        inFile.ignore(1, ' ');
        inFile >> p;
        inFile.ignore(1, ' ');
        inFile >> midt;
        inFile.ignore(1, ' ');
        inFile >> exam;
        inFile.ignore(1, '\n');
        English *e = new English(nameLast, nameFirst, a, p, midt, exam, course);
        students[temp] = e;
      }
     temp++;                       
  } 
  inFile.close();                  // close the file
  return true;
}

bool StudentList::CreateReportFile(const char* filename)
{

 // ****** REMEMBER TO CHANGE COUT TO outFile !!!!!!!!!!!!!! **********************************************

  string courseN;
  int numOfA = 0; 
  int numOfB = 0;
  int numOfC = 0;
  int numOfD = 0;
  int numOfF = 0; 
  int nameLen = 0;

  ofstream outFile;
  outFile.open(filename, ios::app); 
                                  // makes it so the data 
                                  // is always added on to the
                                  // file if it is a valid file
  if (!outFile)
  {                               // if it is not a valid file
                                  // and does not open, it will
                                  // return false
    return false;
  }

  outFile << "Student Grade Summary \n";
  outFile << "--------------------- \n";


  // ---- prints based on english student ----
  outFile << "\n" << "\nENGLISH CLASS\n";

  outFile << "\n" << setw(45) << left << "Student " << setw(4) << left << " Final " << "Final " << "  Letter";
  outFile << "\n" << setw(45) << left << "Name " << setw(4) << left << " Exam " << " Avg " << "    Grade \n";
  outFile << "-------------------------------------------------------------------------\n";

  for (int i = 0; i < size; i++)
  {
    courseN = students[i]->GetCourseName();
    if (courseN == "English")
    {                              // checks to see if the student is an english 
                                   // student
      outFile << students[i]->GetFirstName() << ' ';
                                   // prints first name and then a space
 
     // used for formatting purposes
      nameLen = ((students[i]->GetFirstName()).length());
      outFile << left << setw(45 - nameLen);

      outFile << students[i]->GetLastName();
                                   // prints out last name
      outFile << students[i]->GetFinalExamScore();
                                   // prints out final exam score
      outFile << setprecision(2) << fixed << "    " << students[i]->Average(); 
      outFile << left << setw(3);
      outFile << "   " << students[i]->LetterGrade() << "\n";
    }
  }

  // -- prints based on history student ---
  // same procedure as english student
  outFile << "\n" << "\nHISTORY CLASS\n";

  outFile << "\n" << setw(45) << left << "Student " << setw(4) << left << " Final " << "Final " << "  Letter";
  outFile << "\n" << setw(45) << left << "Name " << setw(4) << left << " Exam " << " Avg " << "    Grade \n";
  outFile << "-------------------------------------------------------------------------\n";

  for (int i = 0; i < size; i++)
  {
    courseN = students[i]->GetCourseName();
    if (courseN == "History")
    {
      outFile << students[i]->GetFirstName() << ' ';
      nameLen = ((students[i]->GetFirstName()).length());
      outFile << left << setw(45 - nameLen); 
      outFile << students[i]->GetLastName();
      outFile << students[i]->GetFinalExamScore();
      outFile << setprecision(2) << fixed << "    " << students[i]->Average();
      outFile << left << setw(3);
      outFile << "   " << students[i]->LetterGrade() << "\n";
    }
  }


  // ---- prints based on math student ----
  // same procedure as above
  outFile << "\n" << "\nMATH CLASS\n";

  outFile << "\n" << setw(45) << left << "Student " << setw(4) << left << " Final " << "Final " << "  Letter";
  outFile << "\n" << setw(45) << left << "Name " << setw(4) << left << " Exam " << " Avg " << "    Grade \n";
  outFile << "-------------------------------------------------------------------------\n";

  for (int i = 0; i < size; i++)
  {
    courseN = students[i]->GetCourseName();
    if (courseN == "Math")
    {
      outFile << students[i]->GetFirstName() << ' ';
      nameLen = ((students[i]->GetFirstName()).length());
      outFile << left << setw(45 - nameLen); 
      outFile << students[i]->GetLastName();
      outFile << students[i]->GetFinalExamScore();
      outFile << setprecision(2) << fixed << "    " << students[i]->Average();
      outFile << left << setw(3);
      outFile << "   " << students[i]->LetterGrade() << "\n";
    }
  }

  // counts how many A's, B's, C's, D's, and F's there are
  for (int i = 0; i < size; i++)
  {
    if (students[i]->LetterGrade() == 'A')
    {
      numOfA++;   
    }                  
    else if (students[i]->LetterGrade() == 'B')
    {
      numOfB++;
    }
    else if (students[i]->LetterGrade() == 'C')
    {
      numOfC++;
    }
    else if (students[i]->LetterGrade() == 'D')
    {
      numOfD++;
    }
    else
    {
      numOfF++;   
    }   
  }

  outFile << "\n" << "\nOVERALL GRADE DISTRIBUTION\n";
  outFile << "\nA:   " << numOfA << "\n";
  outFile << "B:   " << numOfB << "\n";
  outFile << "C:   " << numOfC << "\n";
  outFile << "D:   " << numOfD << "\n";
  outFile << "F:   " << numOfF << "\n";

  return true;
}

void StudentList::ShowList() const       
{                                  // prints last name, first name, and course name
  cout << setw(31) << left << "Last" << setw(31) << left << "First" << "Course \n"; 
  cout << "\n";
  for (int i = 0; i < size; i++)
  {
     students[i]->ListPrint();
  }
}

void StudentList::Sort ()
{                                 // sorts the list alphabetically by last name
                                  // if the last names are the same, it checks the
                                  // first names
//  cout << "\n -- RUNNING SORT -- \n";
  int j = 0;
  int d = 0;
  bool swap = true;
  Student* temp;                  // creates a temp variable that stores a 
                                  // pointer to type Student
  while (swap == true)
  {                               // while things are bing swapped
    swap = false;
    j++;
    for (int i = 0; i < size - j; i++)
    {

      // creating character arrays to store the last name so that can change
      // the last name to all uppercase to compare the last names 
      // alphabetically and NOT lexicographically

      char lName [31];            // creates a character array that to store
                                  // the last name of index i in all uppercase
      for (int k = 0; k < (students[i]->GetLastName()).length(); k++)
      {
        lName[k] = toupper((students[i]->GetLastName())[k]);
        lName[k + 1] = '\0';
      } 

      char LNAME [31];            // creates a character array that to store 
                                  // the last name of index i + 1 in all 
                                  // uppercase
      for (int m = 0; m < (students[i + 1]->GetLastName()).length(); m++)
      {
        LNAME[m] = toupper((students[i + 1]->GetLastName())[m]);
        LNAME[m + 1] = '\0';  
      }

      char fName [31];            // creates a character array that to store 
                                  // the first name of index i in all uppercase
      for (int n = 0; n < (students[i]->GetFirstName()).length(); n++)
      {
        fName[n] = toupper((students[i]->GetFirstName())[n]);
        fName[n + 1] = '\0';
      }

      char FNAME [31];            // creates a character array that to store 
                                  // the first name of index i + 1 in all 
                                  // uppercase
      for (int lcv = 0; lcv < (students[i + 1]->GetFirstName()).length(); lcv++)
      {            
        FNAME[lcv] = toupper((students[i + 1]->GetFirstName())[lcv]);
        FNAME[lcv + 1] = '\0';
      }

      if (strcmp(lName, LNAME) > 0)
      {                           // if the last name in index i is greater
                                  // than the last name in index i + 1,
                                  // it will swap the 2 names

        temp = students[i];
        students[i] = students[i + 1];
        students[i + 1] = temp;

        swap = true;
      }
      else if (strcmp(lName, LNAME) == 0)
      {                          // if the last name in index i and
                                 // index i + 1 are both equal, it will
                                 // move on to check the first names
        if (strcmp(fName, FNAME) > 0)
        {                        // if the first name in index i is 
                                 // greater than in index i + 1, it will
                                 // swap the 2 items
          temp = students[i];
          students[i] = students[i + 1];
          students[i + 1] = temp;

          swap = true;
        }
      }
    }
  }
}

void StudentList::Grow(int increase)
{                                // grows the array the number of times
                                 // passed into the array as a parameter
  size += increase;
  Student** newStudents = new Student*[size];
  for (int i = 0; i < size; i++)
  {
    newStudents[i] = students[i];
  }
  delete [] students;
  students = newStudents;
}

