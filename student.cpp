#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "student.h"

Student::Student(string lastN, string firstN, int final, string c)
{
   lastName = lastN;
   firstName = firstN;
   finalExam = final;
   courseName = c;
}

string Student::GetCourseName () const 
{
  return courseName;
}

string Student::GetFirstName () const
{
  return firstName;
}

string Student::GetLastName () const
{
  return lastName;
}

int Student::GetFinalExamScore () const
{
  return finalExam;
}

char Student::LetterGrade () 
{
  if (average >= 90)
  {
    grade = 'A';
  } 
  else if (average >= 80)
  {
    grade = 'B';
  }
  else if (average >= 70)
  {
    grade = 'C';
  }
  else if (average >= 60)
  {
    grade = 'D';
  }
  else
  {
    grade = 'F';
  }
  return grade;
}

void Student::ListPrint() const
{
   cout << setw(31) << left << lastName << setw(31) << left << firstName << courseName << "\n";
}

English::English (string lastN, string firstN, int atten, int proj, int midtrm, int final, string c)
                 : Student (lastN, firstN, final, c)
{
  attendance = atten;
  project = proj;
  midterm = midtrm;
}

double English::Average () 
{
  const double attenPerc = 0.10;
  const double projPerc = 0.30;
  const double midtermPerc = 0.30;
  const double examPerc = 0.30;

  // stores values after percentages taken
  double atten;
  double proj;
  double mt;
  double exam;
  
  atten = attendance * attenPerc;      
  proj = project * projPerc;
  mt = midterm * midtermPerc;
  exam = finalExam * examPerc;
  average = atten + proj + mt + exam;
  return average;
}

History::History(string lastN, string firstN, int paper, int midtrm, int final, string c)
                : Student (lastN, firstN, final, c) 
{
  termPaper = paper;
  midterm = midtrm;
}

double History::Average () 
{
  const double termPerc = 0.25;
  const double midtermPerc = 0.35;
  const double examPerc = 0.40;

  // stores values after percentages taken
  double term;
  double mt;
  double exam;

  term = termPaper * termPerc;
  mt = midterm * midtermPerc;
  exam = finalExam * examPerc;
  average = term + mt + exam;
  return average;
}

Math::Math (string lastN, string firstN, int q1, int q2, int q3, int q4, int q5, int t1, int t2, int final, string c)
            : Student(lastN, firstN, final, c)
{
  quiz1 = q1;
  quiz2 = q2;
  quiz3 = q3;
  quiz4 = q4;
  quiz5 = q5;
  test1 = t1;
  test2 = t2;
}

double Math::Average () 
{
  const double qPerc = 0.15; // percentage of grade made up of quizzes     
  const double firstTestPerc = 0.25;
  const double secTestPerc = 0.25;
  const double examPerc = 0.35;
  double fiveQuizAvg;

  // stores values after percentages taken
  double overallQuizAvg;
  double testF;              // test 1 grade after percentage
  double testS;              // test 2 grade after percentage 
  double exam;

  fiveQuizAvg = ((quiz1 + quiz2 + quiz3 + quiz4 + quiz5) / 5.0); 
                             // divided by 5.0 to make sure the answer is a double and not int
  overallQuizAvg = fiveQuizAvg * qPerc;
  testF = test1 * firstTestPerc;
  testS = test2 * secTestPerc;
  exam = finalExam * examPerc;
  average = overallQuizAvg + testF + testS + exam;
  return average;
}
