#include "students.h"
#include <iostream>
using namespace std;

CStudents::CStudents()
:CPerson()
, m_average(0)
, m_admission(0){}

CStudents::CStudents(char* s, char* n, char* k, char* d, int y, int b, int z)
: CPerson(s, n, k, d, y)
, m_average(b)
, m_admission(z){}

CStudents::~CStudents(){}

void CStudents::show()
{
	CPerson::show();
	cout << "Average ball: " << m_average << endl;
	cout << "Year of admission: " << m_admission << endl << endl;
}

void CStudents::correctStatus(int n)
{
	if (m_admission == 2015) 
		m_average -= 1;
	else 
		m_average += 1;
}

void CStudents::setAverage(int b)
{
	m_average = b;
}

int CStudents::getAverage()
{
	return m_average;
}
void CStudents::setAdmission(int b)
{
	m_admission = b;
}

int CStudents::getAdmission()
{
	return m_admission;
}