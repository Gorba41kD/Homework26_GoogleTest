#pragma once
#include"Person.h"
double Tax(Person_interface* person, double tax)
{
	return person->Get_salary()* tax / 100;
}