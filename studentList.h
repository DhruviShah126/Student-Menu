#include "student.h"

class StudentList
{
public:
   StudentList();             // starts out empty
   ~StudentList();            // cleanup (destructor)

   bool ImportFile(const char* filename);
                              // takes in the name of a file
                              // to open and read from
                              // returns true if the file was 
                              // successfully opened
   bool CreateReportFile(const char* filename);
   void ShowList() const;     // print basic list data
   void Sort();               // sorts the list alphabetically
                              // by last name 
private:
   Student **students;        // stores a pointer pointing to
                              // an array of pointers which 
                              // store objects of the Student 
                              // and its derived classes
   int size;                  // stores size of the array 
   char inputFile [31];       // stores input file name which 
                              // will be a max of 30 characters
   void Grow(int increase);   // grows the array the number of times
                              // passed in as the parameter 
};
