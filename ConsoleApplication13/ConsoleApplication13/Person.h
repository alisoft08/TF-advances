#pragma once
#include "Customers.h"

class Person : public Customers
{


private:
	string dni;

public:
	Person(string username, string email, string password, string dni) : Customers(username, email, password, "Person"), dni(dni) {}

	~Person(){}
    //setters
    void setDni(string _dni) {
        dni = _dni;
    }

    //getters
    string getDni() {
        return dni;
    }

    void showAdditionalInfo() override {
        cout << "DNI: " << dni << endl;
    }


};


