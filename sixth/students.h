#pragma once
#include "person.h"

class CStudents : public CPerson
{
public:

	CStudents();
	CStudents(char*, char*, char*, char*, int, int, int);
	~CStudents();
	virtual void show();
	void correctStatus(int);

	void setAverage(int);
	int getAverage();
	void setAdmission(int);
	int getAdmission();

private:
	int m_average;
	int m_admission;
};