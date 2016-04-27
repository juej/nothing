#pragma once
class CPerson
{
protected:
	char* m_pSurName;		// фамилия
	char* m_name;			// имя
	char* m_patronymic;		// отчество
	char* m_country;		// страна
	int m_year;				// год рождения	
public:
	// конструктор по умолчанию
	CPerson();
	// конструктор с параметрами
	CPerson(char*, char*, char*, char*, int);

	// виртуальный деструктор
	virtual ~CPerson();

	// виртуальная функция просмотра состояния
	virtual void show();

	//чистая виртульная функция
	virtual void correctStatus(int) = 0;

	// методы установки значений атрибутов
	void setSurName(char*);
	void setName(char*);
	void setPatronymic(char*);
	void setCountry(char*);
	void setYear(int);
	// методы возврата значений атрибутов
	char* getSurName();
	char* getName();
	char* getPatronymic();
	char* getCountry();
	int getYear();
};