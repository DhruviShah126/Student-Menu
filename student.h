#include <string>
using namespace std;

class Student
{
public:
   Student(string lastN, string firstN, int final, string c);
                                   // constructor that sets the last name, 
                                   // first name, final exam grade, and 
                                   // course name
   string GetCourseName () const;  // returns course name
   string GetFirstName () const;   // returns first name
   string GetLastName () const;    // returns last name
   char LetterGrade ();            // returns the letter grade 
   int GetFinalExamScore () const; // returns the final exam score
   void ListPrint() const;         // prints info for showing student list

   virtual double Average () = 0;  // makes class abstract -- only here so 
                                   // program can compile 
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
   English(string lastN, string firstN, int atten, int proj, int midtrm, 
           int final, string c);
                                   // constructor that sets the last name,
                                   // first name, attendance grade, 
                                   // project grade, final exam grade, 
                                   // and course name
   double Average ();

private:
   int attendance, project, midterm;
};

class History : public Student 
// derived from Student 
{
public:
   History(string firstN, string lastN, int paper, int midtrm, int final, 
           string c);
                                   // constructor that sets the last name,
                                   // first name, term papaer grade, midterm
                                   // grade, final exam grade, and course name
   double Average ();

private:
   int termPaper, midterm;
};

class Math : public Student
// dereived from Student 
{
public:
   Math(string lastN, string firstN, int q1, int q2, int q3, int q4, int q5, 
        int t1, int t2, int final, string c);
                                   // constructor that sets the last name,
                                   // first name, quiz 1 grade, guiz 2 grade,
                                   // quiz 3 grade, quiz 4 grade, quiz 5 grade,
                                   // test 1 grade, test 2 grade, final exam 
                                   // grade, and course name
   double Average ();

private:
   int quiz1, quiz2, quiz3, quiz4, quiz5, test1, test2;
};
