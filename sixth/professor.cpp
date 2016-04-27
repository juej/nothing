#include "professor.h"
#include <iostream>
using namespace std;

CProfessor::CProfessor()
:CPerson()
, m_rank(new char[1])
, m_publication(0)
{
	*m_rank = '\0';
}

CProfessor::CProfessor(char* s, char* n, char* k, char* d, int y, int z, char* b)
: CPerson(s, n, k, d, y)
, m_rank(new char[strlen(b) + 1])
, m_publication(z)
{
	strcpy_s(m_rank, strlen(b) + 1, b);
}

CProfessor::~CProfessor()
{
	delete[] m_rank;
}

void CProfessor::show()
{
	CPerson::show();
	cout << "Rank: " << m_rank << endl;
	cout << "Publications: " << m_publication << endl << endl;
}

void CProfessor::correctStatus(int n)
{
	if (m_publication == 10)
		m_rank = "Professor";
	else
		m_rank = "Newbie";
}

void CProfessor::setRank(char* b)
{
	delete[] m_rank;
	m_rank = new char[strlen(b) + 1];
	strcpy_s(m_rank, strlen(b) + 1, b);
}

char* CProfessor::getRank()
{
	return m_rank;
}
void CProfessor::setPublication(int b)
{
	m_publication = b;
}

int CProfessor::getPublication()
{
	return m_publication;
}