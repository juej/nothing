#pragma once
class CPerson
{
private:
	char* m_pSurName;		// фамилия
	char m_name[20];		// имя
	int m_year;				// год рождения		
public:
	// конструктор по умолчанию
	CPerson();
	// конструктор с параметрами
	CPerson(char*, char*, int);
	// конструктор копирования
	CPerson(CPerson&);
	// деструктор
	~CPerson();
	// методы установки значений атрибутов
	void setSurName(char*);
	void setName(char*);
	void setYear(int);
	// методы возврата значений атрибутов
	char* getSurName();
	char* getName();
	int getYear();
};