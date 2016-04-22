#include <string>
#include "person.h"

// конструктор по умолчанию
CPerson::CPerson()
: m_pSurName(new char[1])
, m_name(new char[1])
, m_patronymic(new char[1])
, m_country(new char[1])
, m_year(0)
{
	*m_pSurName = '\0';
	*m_name = '\0';
	*m_patronymic = '\0';
	*m_country = '\0';
}

// конструктор с параметрами
CPerson::CPerson(char* s, char* n, char* k, char* d, int y)
: m_pSurName(new char[strlen(s) + 1])
, m_name(new char[strlen(n) + 1])
, m_patronymic(new char[strlen(k) + 1])
, m_country(new char[strlen(d) + 1])
, m_year(y)
{	// копирование параметров в члены-данные
	strcpy_s(m_pSurName, strlen(s) + 1, s);
	strcpy_s(m_name, strlen(n) + 1, n);
	strcpy_s(m_patronymic, strlen(k) + 1, k);
	strcpy_s(m_country, strlen(d) + 1, d);
}

// конструктор копирования
CPerson::CPerson(CPerson& r)
: m_pSurName(new char[strlen(r.m_pSurName) + 1])
, m_name(new char[strlen(r.m_name) + 1])
, m_patronymic(new char[strlen(r.m_patronymic) + 1])
, m_country(new char[strlen(r.m_country) + 1])
, m_year(r.m_year)
{	// копирование параметров в члены-данные
	strcpy_s(m_pSurName, strlen(r.m_pSurName) + 1, r.m_pSurName);
	strcpy_s(m_name, strlen(r.m_name) + 1, r.m_name);
	strcpy_s(m_patronymic, strlen(r.m_patronymic) + 1, r.m_patronymic);
	strcpy_s(m_country, strlen(r.m_country) + 1, r.m_country);
}

// деструктор
// освобождает память, выделенную конструктором
CPerson :: ~CPerson()
{
	delete[] m_pSurName;
	delete[] m_name;
	delete[] m_patronymic;
	delete[] m_country;
}

// методы установки значений атрибутов
// требуют параметров такого же типа,  как и у членов-данных
void CPerson::setSurName(char* s)
{
	delete[] m_pSurName;
	m_pSurName = new char[strlen(s) + 1];
	strcpy_s(m_pSurName, strlen(s) + 1, s);
}
void CPerson::setName(char* n)
{
	delete[] m_name;
	m_name = new char[strlen(n) + 1];
	strcpy_s(m_name, strlen(n) + 1, n);
}
void CPerson::setPatronymic(char* k)
{
	delete[] m_patronymic;
	m_patronymic = new char[strlen(k) + 1];
	strcpy_s(m_patronymic, strlen(k) + 1, k);
}
void CPerson::setCountry(char* d)
{
	delete[] m_country;
	m_country = new char[strlen(d) + 1];
	strcpy_s(m_country, strlen(d) + 1, d);
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
char* CPerson::getPatronymic()
{
	return m_patronymic;
}
char* CPerson::getCountry()
{
	return m_country;
}
int CPerson::getYear()
{
	return m_year;
}