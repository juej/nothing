#include <string>
#include "person.h"

// конструктор по умолчанию
CPerson::CPerson() 
: m_pSurName(new char[1])
, m_year(0)
// для фамилии нужно выделить один байт
{
	*m_pSurName = '\0'; m_name[0] = '\0';
}

// конструктор с параметрами
CPerson::CPerson(char* s, char* n, int y) 
: m_pSurName(new char[strlen(s) + 1])
, m_year(y)
// для фамилии нужно выделить столько байтов,  сколько занимает параметр s,
// и прибавить 1 для символа завершения строки '\0'
{	// копирование параметров в члены-данные
	strcpy_s(m_pSurName, strlen(s) + 1, s);
	strcpy_s(m_name, n);
}

// конструктор копирования
CPerson::CPerson(CPerson& r) 
: m_pSurName(new char[strlen(r.m_pSurName) + 1])
, m_year(r.m_year)
// для фамилии нужно выделить столько байтов,  сколько занимает член-данное
// m_pSurName объекта r,  и прибавить 1 для символа завершения строки '\0'
{	// копирование параметров в члены-данные
	strcpy_s(m_pSurName, strlen(r.m_pSurName) + 1, r.m_pSurName);
	strcpy_s(m_name, r.m_name);
}

// деструктор
// освобождает память, выделенную конструктором
CPerson :: ~CPerson()
{
	delete[] m_pSurName;
}

// методы установки значений атрибутов
// требуют параметров такого же типа,  как и у членов-данных
void CPerson::setSurName(char* s)
{	// сначала освободить память
	delete[] m_pSurName;
	// выделить столько байтов,  сколько занимает параметр s,
	// и прибавить 1 для символа завершения строки '\0'
	m_pSurName = new char[strlen(s) + 1];
	// наконец, скопировать значение полученного параметра s
	strcpy_s(m_pSurName, strlen(s) + 1, s);
}
void CPerson::setName(char* s)
{
	strcpy_s(m_name, s);
}
void CPerson::setYear(int y)
{
	m_year = y;
}

// методы возврата значений атрибутов  не требуют параметров;
// возвращают значения такого же типа,  как и у членов-данных
char* CPerson::getSurName()
{
	return m_pSurName;
}
char* CPerson::getName()
{
	return m_name;
}
int CPerson::getYear()
{
	return m_year;
}
