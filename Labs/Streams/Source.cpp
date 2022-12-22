#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdio>

using namespace std;

struct student
{
	string firstname;
	int fname;
	string lastname;
	int lname;
	int student_ID;
	double labs;
	double a1;
	double a2;
	double a3;
	double a4;
	double a5;
	double tt;
	double mid;
	double fina;
	double total;
	string grade;
};

string getLetterGrade(double total)
{
	if (total >= 90)
		return "A+";
	if (total >= 85 && total < 90)
		return "A ";
	if (total >= 80 && total < 85)
		return "A-";
	if (total >= 75 && total < 80)
		return "B+";
	if (total >= 70 && total < 75)
		return "B ";
	if (total >= 65 && total < 70)
		return "C+";
	if (total >= 60 && total < 65)
		return "C ";
	if (total >= 55 && total < 60)
		return "D+";
	if (total >= 50 && total < 55)
		return "D ";
	if (total >= 40 && total < 50)
		return "E ";
	if (total < 40)
		return "F ";

}

int main()
{
	fstream fin("CSI2372.info", ios::binary | ios::in);

	if (!fin.is_open())
	{
		cout << "File not found" << endl;
		return 0;
	}
	string s;
	double tempTotal = 0.0;
	student st;

	fstream frw("CSI2372_Final.info", ios::binary | ios::out); //opening a file for reading and writing

	if (!frw.is_open())
	{
		cout << "File not found" << endl;
		return 0;
	}

	while (!fin.eof())
	{
		getline(fin, s, ';');
		st.firstname = s;
		st.fname = st.firstname.size();
		frw.write((char*)&st.fname, sizeof(int));
		frw.write(st.firstname.c_str(), st.firstname.size());
		
		getline(fin, s, ';');
		st.lastname = s;
		st.lname = st.lastname.size();
		frw.write((char*)&st.lname, sizeof(int));
		frw.write(st.lastname.c_str(), st.lastname.size());
		
		fin.read((char*)&st.student_ID, sizeof(int));
		frw.write((char*)&st.student_ID, sizeof(int));

		fin.read((char*)&st.labs, sizeof(double));
		st.labs = st.labs;
		tempTotal = tempTotal - tempTotal + st.labs;
		frw.write((char*)&st.labs, sizeof(double));

		fin.read((char*)&st.a1, sizeof(double));
		st.a1 = st.a1 / 5;
		tempTotal = tempTotal + st.a1;
		frw.write((char*)&st.a1, sizeof(double));

		fin.read((char*)&st.a2, sizeof(double));
		st.a2 = st.a2 / 5;
		tempTotal = tempTotal + st.a2;
		frw.write((char*)&st.a2, sizeof(double));

		fin.read((char*)&st.a3, sizeof(double));
		st.a3 = st.a3 / 5;
		tempTotal = tempTotal + st.a3;
		frw.write((char*)&st.a3, sizeof(double));

		fin.read((char*)&st.a4, sizeof(double));
		st.a4 = st.a4 / 5;
		tempTotal = tempTotal + st.a4;
		frw.write((char*)&st.a4, sizeof(double));

		fin.read((char*)&st.a5, sizeof(double));
		st.a5 = st.a5 / 5;
		tempTotal = tempTotal + st.a5;
		frw.write((char*)&st.a5, sizeof(double));

		fin.read((char*)&st.tt, sizeof(double));
		frw.write((char*)&st.tt, sizeof(double));
		tempTotal = tempTotal + st.tt;

		fin.read((char*)&st.mid, sizeof(double));
		frw.write((char*)&st.mid, sizeof(double));
		tempTotal = tempTotal + st.mid;

		fin.read((char*)&st.fina, sizeof(double));
		frw.write((char*)&st.fina, sizeof(double));
		tempTotal = tempTotal + st.fina;

		st.total = tempTotal;
		frw.write((char*)&st.total, sizeof(double));
		
		st.grade = getLetterGrade(st.total);
		frw.write(st.grade.c_str(), st.grade.size());

	}

	fin.close();
	frw.close();

	fstream frr("CSI2372_Final.info", ios::binary | ios::in); //opening a file for reading and writing

	if (!frr.is_open())
	{
		cout << "File not found" << endl;
		return 0;
	}

	student strec;
	char temp[100];

	while (!frr.eof())
	{
		frr.read((char*)&st.fname, sizeof(int));
		frr.read(temp, st.fname);
		temp[st.fname] = 0;
		strec.firstname = temp;
		cout << "Firstname = " << strec.firstname << endl;

		frr.read((char*)&st.lname, sizeof(int));
		frr.read(temp, st.lname);
		temp[st.lname] = 0;
		strec.lastname = temp;
		cout << "Lastname = " << strec.lastname << endl;

		frr.read((char*)&strec.student_ID, sizeof(int));
		cout << "Student ID = " << strec.student_ID << endl;

		frr.read((char*)&strec.labs, sizeof(double));
		cout << "Labs = " << strec.labs << endl;
		
		frr.read((char*)&strec.a1, sizeof(double));
		cout << "Assignment 1= " << strec.a1 << endl;
	
		frr.read((char*)&strec.a2, sizeof(double));
		cout << "Assignment 2= " << strec.a2 << endl;
		
		frr.read((char*)&strec.a3, sizeof(double));
		cout << "Assignment 3= " << strec.a3 << endl;
		
		frr.read((char*)&strec.a4, sizeof(double));
		cout << "Assignment 4= " << strec.a4 << endl;
		
		frr.read((char*)&strec.a5, sizeof(double));
		cout << "Assignment 5= " << strec.a5 << endl;
		
		frr.read((char*)&strec.tt, sizeof(double));
		cout << "Term test = " << strec.tt << endl;
		
		frr.read((char*)&strec.mid, sizeof(double));
		cout << "Midterm = " << strec.mid << endl;

		frr.read((char*)&strec.fina, sizeof(double));
		cout << "Final = " << strec.fina << endl;

		frr.read((char*)&strec.total, sizeof(double));
		cout << "Total mark out of 100 = " << strec.total << endl;

		frr.read(temp, 2);
		temp[2] = 0;
		strec.grade = temp;
		cout << "Letter grade= " << strec.grade << endl;
	}
	frr.close();
	return 0;
}