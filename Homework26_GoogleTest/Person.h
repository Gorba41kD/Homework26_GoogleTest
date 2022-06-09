#pragma once
#include"pch.h"
#include<string>
class Person_interface
{
public:
	virtual ~Person_interface() {}
	virtual void Set_salary(double salary) = 0;
	virtual double Get_salary() const = 0;
	virtual void Set_surname(std::string surname) = 0;
	virtual std::string Get_surname() const = 0;
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
	double Get_salary() const override
	{
		return m_salary;
	}
	void Set_surname(std::string surname) override
	{
		m_surname = surname;
	}
	std::string Get_surname() const  override
	{
		return m_surname;
	}
};

