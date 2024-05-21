#pragma once
#include "User.h"

class Employees : public User
{

protected:
	string employeeType;

public:
	Employees(string username, string email, string password, string employeeType) : User(username, email, password, "Employee"),
		employeeType(employeeType) {}
	~Employees(){}

	string getCustomerType() {
		return this->employeeType;
	}

};


