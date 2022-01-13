#include "student.h"

class StudentList
{
public:
   StudentList();             // starts out empty
   ~StudentList();            // cleanup (destructor)

   bool ImportFile(const char* filename);
                              // returns true if the file was successfully opened
   bool CreateReportFile(const char* filename);
   void ShowList() const;     // print basic list data
   void Sort();               // sorts the list alphabetically by last name 
   
private:
   Student **students;        // stores a pointer pointing to an array of pointers which store objects of the Student and its derived classes
   int size;                  
   char inputFile [31];       
   void Grow(int increase);   
};
