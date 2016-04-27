#pragma once
#include "person.h"

class CProfessor : public CPerson
{
public:

	CProfessor();
	CProfessor(char*, char*, char*, char*, int, int, char*);
	~CProfessor();

	virtual void show();
	void correctStatus(int);

	void setRank(char*);
	char* getRank();
	void setPublication(int);
	int getPublication();

private:
	int m_publication;
	char* m_rank;
};