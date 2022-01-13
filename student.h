#include <string>
using namespace std;

class Student
{
public:
   Student(string lastN, string firstN, int final, string c);
   string GetCourseName () const;  
   string GetFirstName () const;   
   string GetLastName () const;    
   char LetterGrade ();            
   int GetFinalExamScore () const; 
   void ListPrint() const;         // prints info for showing student list
   virtual double Average () = 0;  // makes class abstract -- only here so program can compile 
   
protected:
   string firstName, lastName, courseName;
   int numOfStudents, finalExam;
   double average;
   char grade;
};

class English : public Student 
// derived from Student
{
public:
   English(string lastN, string firstN, int atten, int proj, int midtrm, int final, string c);
   double Average ();

private:
   int attendance, project, midterm;
};

class History : public Student 
// derived from Student 
{
public:
   History(string firstN, string lastN, int paper, int midtrm, int final, string c);
   double Average ();

private:
   int termPaper, midterm;
};

class Math : public Student
// dereived from Student 
{
public:
   Math(string lastN, string firstN, int q1, int q2, int q3, int q4, int q5, int t1, int t2, int final, string c);
   double Average ();

private:
   int quiz1, quiz2, quiz3, quiz4, quiz5, test1, test2;
};
