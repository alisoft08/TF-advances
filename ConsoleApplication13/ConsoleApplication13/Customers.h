#pragma once
#include "User.h"

class Customers : public User
{

protected:
	string customerType;

public:
	Customers(string username, string email, string password, string customerType) : User(username,email,password, "Customer"), 
		customerType(customerType){}
	~Customers(){}

	string getCustomerType() {
		return this->customerType;
	}

	



};



