/*
* Main.cpp
*
* Version information v0.1
* Author: Dr. Shane Wilson
* Date: 8/10/2017
* Description: Driver to test the student class
* Copyright notice
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Student.h"
#include "Module.h"
#include "Person.h"
#include "Lecturer.h"

using namespace std;
void WriteStudentDetails(std::vector<Student>& data);

int main() {

	//Create a lecturer object
	Lecturer him{ "David Marsh", "dangermouse@io.com", "11009555", "Dangerology" };
	
	//Create a pointer of person class and point it at the Lecturer object
	Person* pPtr = &him;
	
	//Call to String. 
	cout << pPtr->ToString();
	//With virtual functions the version called is based on the type of the object, not the pointer

	//Create a pointer of person class and point it at the student object
	Module OOP ("Object Orientated Programming", "COM326", 100);
	Module VP ("Visual Programming", "COM321", 100);

	Student stu1("Jeni Watt", "B004568656", "BSc Computing", 1);
	Student stu2("Jack Hannaway", "B00708431", "BSc Computing", 2);
	Student stu3("John Doe", "B004568234", "BSc Computing", 4);

	stu1.AddModule(OOP);
	stu1.AddModule(VP);

	stu2.AddModule(OOP);
	stu2.AddModule(VP);

	stu3.AddModule(OOP);
	stu3.AddModule(VP);

	pPtr = &stu1;
	cout << pPtr->ToString();

	//Always set pointers to nullptr when you are finished using them
	pPtr = nullptr;

	vector<Student> Student;
	Student.push_back(stu1);
	Student.push_back(stu2);
	Student.push_back(stu3);

	WriteStudentDetails(Student);

	return 0;
}


void WriteStudentDetails(std::vector<Student>& data)
{
	ofstream outFile{};
	outFile.open("StudentData.txt", ios::app);

	if (!outFile) {
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < data.size(); i++) {
	
		outFile << " Reg: " << data[i].GetRegistrationID() << " Name: " << data[i].GetName() << " Course: " << data[i].GetCourse() << " Year of Study: " << data[i].GetYearofStudy() << endl;
	}

	outFile.close();
}

vector<Student> ReadStudentDetails(string dataFile)
{
	
}
