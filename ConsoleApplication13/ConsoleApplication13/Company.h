#pragma once
#include "Customers.h"

class Company : public Customers
{

private:
	string ruc;

public:
	Company(string username, string email, string password, string ruc) : Customers(username, email, password, "Company"), ruc(ruc) {}
	~Company(){}

    //setters
    void setRuc(string _ruc) {
        ruc = _ruc;
    }

    //getters
    string getRuc() {
        return ruc;
    }

    void showAdditionalInfo() override {
        cout << "RUC: " << ruc << endl;
    }

};


