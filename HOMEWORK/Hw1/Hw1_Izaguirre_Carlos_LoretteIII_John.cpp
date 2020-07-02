/*------------------------------------------------------------------------------------
 * Author:        Carlos Izaguirre and John Lorette III
 * Date:          6/19/2020
 * Trace Folder:  HOMEWORK\Hw1\
 * File Name:     Hw1_Izaguirre_Carlos_LoretteIII_John.cpp
 * Description:   C++ Program that determines a student's final grade based on their
 *                performance on three exams, weekly quizzes, homework assignments,
 *                and lab activities. This information is found in two text files 
 *                "grades.txt" and "numbersActivities.txt": The program then outputs 
 *                to the screen the final grade of each 'Student' structure.
 ------------------------------------------------------------------------------------*/
#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>//Needed for istringstream
#include<fstream>
#include<cassert>//Needed for assert
#include<memory>
using namespace std;

//Structure for storing a Student's data
struct Student
{
  string name;
  double *exams = nullptr;
  double *quizzes = nullptr;
  double *hw = nullptr;
  double *labs = nullptr;
};
//Function prototypes
Student *readStudentsData(int, int, int, int, int);//Reads students records from input file
double *getArray(string, int);//Tokenizes a string into an array of doubles; similar to Python's split function
double calculateScore(double *, int); //Returns the score out of 100 or 10. Function removes lowest grade and scales the score
double findGrade(Student &, int, int, int, int);//Calculates the grade out of 100 for the 'Student s'
void displayArray(double *, int);//Display an array to the screen

/*************************************************************************************
 *                 The programs main method, or control function                     *
 *************************************************************************************/
int main(){
  //Structure pointer to store the base address of a dynamic array of 'Student' structures
  Student* data;
  ifstream fin;//File input stream object
  //Variable(s) for the #-values for each 'Student' structure
  int numStudents, numExams, numQuizzes, numHW, numLabs;

  //Read the number of students, exams, quizzes, homeworks, and labs from a file
  fin.open("numbersActivities2.txt");
  assert(fin); //make sure that file was opened successfully; otherwise, terminate program with an error message
  //Read the number of students from the file
  fin >> numStudents;
  cout << "Number of Students: " << numStudents << endl << endl;
  //Read number of exams, quizzes, hw's, and labs from the file
  fin >> numExams >> numQuizzes >> numHW >> numLabs;
  fin.close();
  //Load the 'Student' structure 'data' dynamic array by calling 'readStudentsData()' with the # of students and their data read from the file
  data = new Student[numStudents];
  data = readStudentsData(numStudents, numExams, numQuizzes, numHW, numLabs);
  //Find the grade for each student from the 'data' structure array
  for (int i = 0; i < numStudents; i++) {
    Student s = *(data + i); //'Student s' object takes a structure of the current student's record
    double grade = findGrade(data[i], numExams, numQuizzes, numHW, numLabs);//Calculate the total grade for the i'th 'Student' from their data
    cout << fixed << showpoint << setprecision(2); //Format output to show two digits after decimal point
    cout <<"Grade for " << data[i].name << " is: " << grade << "%" << endl;
  }

  //Release dynamically allocated data
  delete [] data -> exams;
  data->exams = nullptr;
  delete [] data -> quizzes;
  data->quizzes = nullptr;
  delete [] data -> hw;
  data->hw = nullptr;
  delete [] data -> labs;
  data->labs = nullptr;
  delete [] data;
  data = nullptr;
  
  //Exit the main function, with 0 indicating success
  return 0;
}
/**
   Function "readStudentsData()" reads students records from the input file 'grades.txt' and 
   stores the results in a dynamic array of 'Student' struct's. Then it returns that array.
   
   @param numStudents -- number of students
   @param numExams -- number of exams
   @param numQuizzes -- number of quizzes
   @param numHW -- number of homework assignments
   @param numLabs -- number of lab activities
   @return studentsData -- structure that holds student's data read from the file
*/
Student *readStudentsData(int numStudents, int numExams, int numQuizzes, int numHW, int numLabs) {
  //Pointer to base address of dynamically allocated array of 'Student' structures that stores data read from the file
  Student *studentsData;
  ifstream fin;//File input stream object
  string line;//String for reading line by line in a text file

  fin.open("gradesTest.txt");
  assert(fin);//IF the file failed to open, terminate program with an error message
  //Allocate memory for the dynamic array of structures 'studentsData'
  studentsData = new Student[numStudents];
  //Read through the text file "grades.txt" line by line "i" times (i.e. # of students)
  for (int i = 0; i < numStudents; i++) {
      //Read the student's name first
      getline(fin, line);
      studentsData[i].name = line;
      //Call the 'getArray()' function on each string line read of a student's data from the file into each 'Student' structure
      getline(fin, line);
      studentsData[i].exams = getArray(line, numExams);
      getline(fin, line);
      studentsData[i].quizzes = getArray(line, numQuizzes);
      getline(fin, line);
      studentsData[i].hw = getArray(line, numHW);
      getline(fin, line);
      studentsData[i].labs = getArray(line, numLabs);
  }
 
  //Close the file input stream and Return the 'studentsData' structure
  fin.close();
  return studentsData;
  //Release the memory used for 'studentsData'
  delete[] studentsData;
}
/**
   Function "getArray()" uses an istringstream object to read the different grades from a string as tokens.
   Then it builds and returns a pointer array with the grades.
   
   @param line -- string with the different grades
   @param numValues -- number of grades, which is the same as size of array
   @return lst -- (a pointer array with grade strings)
*/
double *getArray(string line, int numValues) {
  //Variable(s) for reading the different grades from a string as tokens
  double *lst = new double[numValues];//Dynamic array of double values
  istringstream instream(line);//Initialize the istringstream constructor/object with 'line'
  double grade = 0.0;
  
  //Loop for reading the grades from istringstream
  for (int i = 0; i < numValues; i++) {
    instream >> grade;//Read each grade from istringstream
    *(lst + i) = grade;
  }
  
  //Return the array with the read grades
  return lst;
  delete[] lst;//Release memory used for '*lst'
}
/**
   Function "calculateScore()" accepts an array representing an activity --such as quizzes, hws, or labs-- containing
   the different scores for that activity. Then it takes care of removing the lowest grade from the calculations. Then
   return the total grade out of 100, in the case of homework (or 10 in case of quizzes and labs) for the specified activity.
   
   @param *activityArray -- activity pointer array
   @param num -- number of elements of the activity specified in the pointer array (i.e. number of quizzes)
   @return sum -- a calculated sum of a 'Student s' graded activity
*/
double calculateScore(double *activityArray, int num) {
    //Variable(s) for caculating the sum of grades (i.e. total score)
    double sum = 0.0, minScore = *(activityArray);//Variable for accessing array elements to find the lowest score

    //Loop through the pointer array to sum all scores
    for (int i = 0; i < num; i++) {
        sum += *(activityArray + i);
        //Find the lowest value among all the scores
        if (minScore > *(activityArray + i)) { //Use Linear Search...O(1)? or O(n)?
            minScore = *(activityArray + i);
        }
    }
    //Remove from the sum the lowest graded activity
    sum -= minScore;
    //Take the average of the sum of activities with the lowest grade dropped
    //Scale the grade to make it out of 100 (or 10) IF the activity is graded out of 100 (or 10)
    sum /= (static_cast<double>(num) - 1);//Type cast the number of values 'int num' to type double

    //Return the calculated score sum
    return sum;
}
/**
   The function "findGrade()" calculates the final grade out of 100 for the 'Student s'. The grade is calculated
   based on the following scale: exams count for 45% of the grade, quizzes count for 10%, homework assignments 
   count for 30%, and lab activities count for 15%. One homework assignment, one quiz, and one lab with the lowest 
   grade among that type of activity are removed for each student.
   
   @param s -- a student structure needed for calculating the total grade
   @param numExams -- number of exams
   @param numQuizzes -- number of quizzes
   @param numHW -- number of homework assignments
   @param numLabs -- number of lab activities/assignments
   @return score -- the score for the total/final grade for a 'Student s'
*/
double findGrade(Student &s, int numExams, int numQuizzes, int numHW, int numLabs) {
  //Variable(s) for calculating the final grade for a 'Student s' structure object
  double exams_score = (s.exams[0] + s.exams[1] + s.exams[2]) / 3.0;//Calculate the score for all 3 exams
  double quizzes_score = calculateScore(s.quizzes,  numQuizzes);//Calculate the score for all quizzes
  quizzes_score *= 10;//Quizzes are graded out of 10 points, scale the grade to be out of 100
  double homework_score = calculateScore(s.hw, numHW);
  double labs_score = calculateScore(s.labs, numLabs);
  labs_score *= 10;//Labs are graded out of 10 points, scale the grade to be out of 100
  //Calculate the 'Student s' final grade out of 100%
  double score = (exams_score * 0.45) + (quizzes_score * 0.1) + (homework_score * 0.3) + (labs_score * 0.15);

  //Return the total final grade for a 'Student s'
  return score;
}
/**
   Function "displayArray()" prints out the values in the pointer array 'lst' 
   on one line where each value in the array is separated by a space.
   
   @param *lst -- pointer array (array to be print tested)
   @param arraySize -- size of the pointer array
   @return -- void
*/
void displayArray(double *lst, int arraySize)
{
  //Loop through the pointer array to display it's contents
  for (int i = 0; i < arraySize; i++) {
      cout << *(lst + i) << " ";
  }
  cout << endl;
}

