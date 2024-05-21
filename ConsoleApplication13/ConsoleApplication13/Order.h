#pragma once
#include "List.h"
#include "Product.h"
#include "Route.h"



class Order
{
private:
	dby::List<Product*>* productsList = new dby::List<Product*>;
	Route* route;

public:
	Order(dby::List<Product*>* productsList, Route* route) : productsList(productsList), route(route) {}

	double getDistance() {
		return route->getDistance();
	}


	double getTotalWeight() {

		double totalWeight = 0.0;
		for (int i = 0; i < productsList->size(); i++) {
			totalWeight += productsList->at(i)->getWeight();
		}
		return totalWeight;
	}

	void showProducts() {
		cout << "   Producto/s:" << endl;
		for (int i = 0; i < productsList->size(); i++) {
			cout << "   " << "[" << productsList->at(i)->getId() << "]" << " " << productsList->at(i)->getNameProduct() << endl;
		}

	}

	~Order(){}
};


