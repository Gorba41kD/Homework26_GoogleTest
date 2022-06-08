#pragma once
#include"pch.h"
#include<string>
class Person_interface
{
public:
	virtual ~Person_interface() {}
	virtual void Set_salary(double salary) = 0;
	virtual double Get_salary() = 0;
	virtual void Set_surname(std::string surname) = 0;
	virtual std::string Get_surname() = 0;
};
class Person : public Person_interface
{
private:
	std::string m_surname;
	double m_salary;
public:
	~Person() override = default;
	void Set_salary(double salary) override
	{
		m_salary = salary;
	}
	double Get_salary() override
	{
		return m_salary;
	}
	void Set_surname(std::string surname) override
	{
		m_surname = surname;
	}
	std::string Get_surname() override
	{
		return m_surname;
	}
};
class Person_mock : public Person_interface
{
public:
	~Person_mock() override = default;
	MOCK_METHOD(void, Set_salary, (double salary), (override));
	MOCK_METHOD(double, Get_salary, (), (override));
	MOCK_METHOD(void, Set_surname, (std::string surname), (override));
	MOCK_METHOD(std::string,Get_surname, (), (override));
};

