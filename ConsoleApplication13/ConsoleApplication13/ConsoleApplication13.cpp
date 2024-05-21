#include <iostream>
#include <conio.h>
#include "string"
#include "List.h"
#include "Person.h"
#include "Company.h"
#include "Driver.h"
#include "Ticket.h"

dby::List<User*>* usersList = new dby::List<User*>;
dby::List<Order*>* ordersList = new dby::List<Order*>;
dby::List<Product*>* productsList = new dby::List<Product*>;

dby::List<Person*>* personsList = new dby::List<Person*>;
dby::List<Company*>* companiesList = new dby::List<Company*>;
dby::List<Driver*>* driversList = new dby::List<Driver*>;


void executeMenuForCustomers(int option, int idCustomer) {

    string origin, destination;
    double distance;
    int n;

    string nameProduct;
    float width, height, weight, value;
    int id;
    int integer = 0;

    switch (option) {
    case 1:
        id = 0;
        system("cls");
        cout << "Pedido " << integer + 1 << ": " << endl; 
        
        cout << "Ingresa el lugar de recojo: ";
        cin >> origin;
        cout << "Ingresa el lugar de entrega: ";
        cin >> destination;
        cout << "Ingresa la distancia entre el punto de origen y el destino en km: ";
        cin >> distance;
       
        Route* route = new Route(origin, destination, distance);

        cout << "Ingresa la cantidad de productos a transportar: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            id = i + 1;
            cout << "Ingresa el nombre del producto " << i + 1 << ": ";
            cin >> nameProduct;
            cout << "Ingresa la altura del producto " << i + 1 << " en centimetros: ";
            cin >> height;
            cout << "Ingresa el ancho del producto " << i + 1 << " en centimetros: ";
            cin >> width;
            cout << "Ingresa el peso del producto " << i + 1 << " en kilogramos: ";
            cin >> weight;
            cout << "Ingresa el valor (S/.) del producto " << i + 1 << " en soles: S/.";
            cin >> value;
            cout << "Producto registrado exitosamente!" << endl;
            cout << "Presiona cualquier tecla para continuar..." << endl;

            productsList->push_back(new Product(nameProduct, width, height, weight, value, i + 1));
            _getch();
            
        }
        Order* order = new Order(productsList, route);
        ordersList->push_back(order);
        Ticket* ticket = new Ticket(order, usersList->at(idCustomer)->getName(), integer + 1);
        integer++;

        system("cls");
        ticket->printTicket();
        _getch();


       
        
    }
}







int showMenuForCustomers() {
    cout << "==================== MENU DE CLIENTES ==================" << endl << endl;
    cout << "1. Hacer pedido" << endl;
    cout << "2. Mostrar boletas" << endl;
    cout << "3. Ver estado de mi pedido" << endl;
    cout << "4. Modificar pedido" << endl;
    cout << "5. Cerrar sesión" << endl;
    int option;
    do
    {
        cin >> option;
        if (option < 1 || option>5)
            cout << "Ingrese una opcion valida... ";
    } while (option < 1 || option>5);

    return option;
}

int showMenuForEmployees() {
    cout << "=====================MENU DE EMPLEADOS==================" << endl << endl;
    cout << "1. Mostrar lista pedidos (seleccionar pedido a realizar)" << endl;
    cout << "2. Cerrar sesion" << endl;
    int option;
    do
    {
        cin >> option;
        if (option < 1 || option>2)
            cout << "Ingrese una opcion valida... ";
    } while (option < 1 || option>2);

    return option;
}

void registerUser() {

    string username, email, password;
    string dni;
    string ruc;
    string licenseNumber, vehicleModel;


 //USUARIO (USER):
    system("cls");
    cout << "Ingrese:" << endl;
    cout << "1. Customer -> Si desea usar nuestro servicio" << endl;
    cout << "2. Employee -> Si desea trabajar para nosotros" << endl;
    cout << " --- --- --- --- --- --- --- --- --- --- --- ---" << endl;
    int userType;
    do {
        cin >> userType;
        if (userType < 1 || userType>2) cout << "Ingrese opcion valida... ";
    } while (userType < 1 || userType > 2);
    cout << endl;

        //CLIENTE (CUSTOMER):
    if (userType == 1) {



        cout << "Ingrese: " << endl;
        cout << "1. Person -> Si es persona" << endl;
        cout << "2. Company -> Si es compania/empresa" << endl;
        cout << " --- --- --- --- --- --- --- --- --- ---" << endl;

        int customerType;

        do {
            cin >> customerType;
            if (customerType < 1 || customerType>2) cout << "Ingrese opcion valida... ";
        } while (customerType < 1 || customerType > 2);
        switch (customerType) {

                       //PERSONA (PERSON):
        case 1:


            system("cls");
            cout << "REGISTRANDO CLIENTE PERSONA..." << endl;
            cout << "Ingresa tu nombre y apellido: ";
            cin.ignore();
            getline(cin, username);
            cout << "Ingresa tu correo electronico: ";
            cin >> email;
            cout << "Crea tu contrasenia: ";
            cin >> password;
            cout << "Ingrese tu numero de DNI: ";
            cin >> dni;

            usersList->push_back(new Person(username, email, password, dni));
            break;

                       //COMPAÑIA/EMPRESA (COMPANY):
        case 2:


            system("cls");
            cout << "REGISTRANDO CLIENTE EMPRESA..." << endl;
            cout << "Ingresa el nombre de tu empresa: ";
            cin.ignore();
            getline(cin, username);
            cout << "Ingresa tu correo electronico: ";
            cin >> email;
            cout << "Crea tu contrasenia: ";
            cin >> password;
            cout << "Ingrese tu numero de RUC: ";
            cin >> ruc;

           
            usersList->push_back(new Company(username, email, password, ruc));
            break;

        }

    }
        //EMPLEADO (EMPLOYEE):
    
                        //CONDUCTOR (DRIVER):
    else if (userType == 2) {
        system("cls");
        cout << "REGISTRANDO EMPLEADO CONDUCTOR..." << endl;
        cout << "Ingresa tu nombre y apellido: ";
        cin.ignore();
        getline(cin, username);
        cout << "Ingresa tu correo electronico: ";
        cin >> email;
        cout << "Crea tu contrasenia: ";
        cin >> password;
        cout << "Ingrese tu numero de licencia de conducir: ";
        cin >> licenseNumber;
        cout << "Ingrese el modelo de tu vehiculo: ";
        cin >> vehicleModel;

        driversList->push_back(new Driver(username, email, password, licenseNumber, vehicleModel));
        usersList->push_back(new Driver(username, email, password, licenseNumber, vehicleModel));
    }
    cout << "\nUuario registrado exitosamente..." << endl;

}
    

void LogIn() {

    string email, password;
    bool correctPassword = false;
    bool accountFound = false;
    int optionForCustomers, optionForEmployees;
    system("cls");
    cout << "Ingresa tu correo electronico: ";
    cin >> email;

    for (int i = 0; i < usersList->size(); i++) {
        if (email == usersList->at(i)->getEmail()) {
            accountFound = true;
            cout << "Cuenta encontrada!\n";
            cout << "Ingresa tu contrasenia: ";
            cin >> password;
            if (password == usersList->at(i)->getPassword()) {
                correctPassword = true;
                system("cls");
                cout << "Bienvenido de vuelta " << usersList->at(i)->getName() << endl << endl;
                if (usersList->at(i)->getUserType() == "Customer") {
                    optionForCustomers = showMenuForCustomers();
                    executeMenuForCustomers(optionForCustomers, i);
                }
                else if (usersList->at(i)->getUserType() == "Employee") {
                    optionForEmployees = showMenuForEmployees();

                }
            }
        }

    }

    if (!accountFound) cout << "No hay ninguna cuenta registrada con este correo electronico..." << endl;



}

int showMenu() {


    cout << "          _    _ _           _     ___" << std::endl;
    cout << "         | |  | | |         | |   |_  |" << std::endl;
    cout << "         | |  | | |__   __ _| |_    | | ___  _   _ _ __ _ __   ___ _   _" << std::endl;
    cout << "         | |\\/| | '_ \\ / _` | __|   | |/ _ \\| | | | '__| '_ \\ / _ \\ | | |" << std::endl;
    cout << "         \\  /\\  / | | | (_| | |_/\\__/ / (_) | |_| | |  | | | |  __/ |_| |" << std::endl;
    cout << "          \\/  \\/|_| |_|\\__,_|\\__|\\____/\\___/ \\__,_|_|  |_| |_|\\___|\\__, |" << std::endl;

    cout << "  |'''''||'''''||'''''||'''''||'''''||'''''||'''''||'''''||'''''||'__/  |'''''|| '''''| " << endl;
    cout << "  '-0-0-''-0-0-''-0-0-''-0-0-''-0-0-''-0-0-''-0-0-''-0-0-''-0-0-''-|___/ -0-0-''`-0-0-'" << endl;

    cout << " ------------------------------------------------------------" << endl;
    cout << "|                                                            |" << endl;
    cout << " ------------------------------------------------------------" << endl;
    cout << "|   1   |           Registrar usuario                        |" << endl;
    cout << " ------------------------------------------------------------" << endl;
    cout << "|   2   |           Iniciar sesion                           |" << endl;
    cout << " ------------------------------------------------------------" << endl;
    cout << "|   3   |           Mostrar usuarios                         |" << endl;
    cout << " ------------------------------------------------------------" << endl;
    cout << "|   4   |           Salir                                    |" << endl;
    cout << " ------------------------------------------------------------" << endl;

    int opcion;
    do
    {
        cin >> opcion;
        if (opcion < 1 || opcion>4)
            cout << "Ingrese una opcion valida... ";
    } while (opcion < 1 || opcion>4);

    return opcion;
}

int main()
{
    int option = 1;
    

    while (option != 4) {
        system("cls");
        option = showMenu();

        switch (option) {
        case 1:
            registerUser();
            break;

        case 2:
            LogIn();
            break;

        case 3:
            system("cls");

            if (usersList->size() == 0) { cout << "Aun no se ha registro ningun usuario..." << endl; }
            else {
                for (int i = 0; i < usersList->size(); i++) {
                    cout << "Usuario " << i + 1 << ": " << usersList->at(i)->getUserType() << endl;


                }
            }
            cout << "hhh";
            _getch();
            break;
        }
        
       
    }

    
}

