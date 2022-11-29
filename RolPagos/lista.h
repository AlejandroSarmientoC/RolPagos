#pragma once

#include "empleado.h"
#include "empleado.cpp"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include "validate.h"

using namespace std;

void ingresarEmpleado(vector<empleado> &empleados) {
    int numeroEmpleados;
    int cedula;
    string nombre;
    string apellido;
    string direccion;
    string salario;
    double salarioNumerico;
    double aporteIess;

    cout << "Ingrese el numero de empleados: ";
    cin >> numeroEmpleados;
    for(int i = 0; i < numeroEmpleados; i++) {
        cout << "Ingrese la cedula del empleado: ";
        cin >> cedula;
        //validar cedula
        while(!validateCI(cedula, empleados)) {
            cout << "Cedula invalida, ingrese una cedula valida: ";
            cin >> cedula;
        }
        cout << "Ingrese el nombre del empleado: ";
        cin >> nombre;
        //validar nombre
        while(!validateString(nombre)) {
            cout << "Nombre invalido, ingrese un nombre valido: ";
            cin >> nombre;
        }
        cout << "Ingrese el apellido del empleado: ";
        cin >> apellido;
        //validar apellido
        while(!validateString(apellido)) {
            cout << "Apellido invalido, ingrese un apellido valido: ";
            cin >> apellido;
        }
        cout << "Ingrese la direccion del empleado: ";
        cin >> direccion;
        //validar direccion
        while(!validateString(direccion)) {
            cout << "Direccion invalida, ingrese una direccion valida: ";
            cin >> direccion;
        }
        cout << "Ingrese el salario del empleado: ";
        cin >> salario;
        //validar salario
        while(!validateDouble(salario)) {
            cout << "Salario invalido, ingrese un salario valido: ";
            cin >> salario;
        }
        salarioNumerico = stringToDouble(salario);

        aporteIess = salarioNumerico * 0.0945;
        empleado empleado(cedula, nombre, apellido, direccion, salario, aporteIess);
        empleados.push_back(empleado);
    }
}


void showEmpleados(vector<empleado> &empleados) {
    for (int i = 0; i < empleados.size(); i++) {
        cout << "Cedula: " << empleados[i].getCedula() << endl;
        cout << "Nombre: " << empleados[i].getNombre() << endl;
        cout << "Apellido: " << empleados[i].getApellido() << endl;
        cout << "Direccion: " << empleados[i].getDireccion() << endl;
        cout << "Salario: " << empleados[i].getSalario() << endl;
        cout << "Aporte Iess: " << empleados[i].getAporteIess() << endl;
        cout << endl;
    }
}

void editEmpleados(vector<empleado> &empleados) {
    int cedula;
    int opcion;
    string nombre;
    string apellido;
    string direccion;
    string salario;
    double aporteIess;

    cout << "Ingrese la cedula del empleado que desea editar: ";
    cin >> cedula;

    for (int i = 0; i < empleados.size(); i++) {
        if (empleados[i].getCedula() == cedula) {
            cout << "1. Editar nombre" << endl;
            cout << "2. Editar apellido" << endl;
            cout << "3. Editar direccion" << endl;
            cout << "4. Editar salario" << endl;
            cout << "Ingrese la opcion que desea editar: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    cout << "Ingrese el nuevo nombre: ";
                    cin >> nombre;
                    empleados[i].setNombre(nombre);
                    break;
                case 2:
                    cout << "Ingrese el nuevo apellido: ";
                    cin >> apellido;
                    empleados[i].setApellido(apellido);
                    break;
                case 3:
                    cout << "Ingrese la nueva direccion: ";
                    cin >> direccion;
                    empleados[i].setDireccion(direccion);
                    break;
                case 4:
                    cout << "Ingrese el nuevo salario: ";
                    cin >> salario;
                    empleados[i].setSalario(salario);
                    break;
                default:
                    cout << "Opcion no valida" << endl;
                    break;
            }
        }
    }
}

void searchEmpleado(vector<empleado> &empleados) {
    int cedula;
    cout << "Ingrese la cedula del empleado que desea buscar: ";
    cin >> cedula;

    for (int i = 0; i < empleados.size(); i++) {
        if (empleados[i].getCedula() == cedula) {
            cout << "Cedula: " << empleados[i].getCedula() << endl;
            cout << "Nombre: " << empleados[i].getNombre() << endl;
            cout << "Apellido: " << empleados[i].getApellido() << endl;
            cout << "Direccion: " << empleados[i].getDireccion() << endl;
            cout << "Salario: " << empleados[i].getSalario() << endl;
            cout << "Aporte Iess: " << empleados[i].getAporteIess() << endl;
            cout << endl;
        }
    }
}

//Generar el rol de pagos en un HTML
void generarRolPagos(vector<empleado> &empleados) {
    ofstream archivo;
    archivo.open("rolPagos.html");
    archivo << "<!DOCTYPE html>" << endl;
    archivo << "<html>" << endl;
    archivo << "<head>" << endl;
    archivo << "<title>Rol de Pagos</title>" << endl;
    archivo << "<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\" integrity=\"sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u\" crossorigin=\"anonymous\">" << endl;
    archivo << "</head>" << endl;
    archivo << "<body>" << endl;
    archivo << "<div class=\"container\">" << endl;
    archivo << "<h1 class`=\"text-center\">Rol de Pagos</h1>" << endl;
    archivo << "<br><br>" << endl;
    archivo << "<h2>Nombre Integrantes: </h2>" << endl;
    archivo << "<p>Quintana Wendy</p>" << endl;
    archivo << "<p>Cambiar por el nombre del Otro Integrante</p>" << endl;
    archivo << "<br><br>" << endl;
    archivo << "<h5 class=\"text-center\">Nomina Empleados: " "</h5>" << endl;
    archivo << "<br>" << endl;
    archivo << "<table class=\"table table-striped\">" << endl;
    archivo << "<tr>" << endl;
    archivo << "<th>Cedula</th>" << endl;
    archivo << "<th>Nombre</th>" << endl;
    archivo << "<th>Apellido</th>" << endl;
    archivo << "<th>Direccion</th>" << endl;
    archivo << "<th>Salario</th>" << endl;
    archivo << "<th>Aporte Iess</th>" << endl;
    archivo << "</tr>" << endl;
    for (int i = 0; i < empleados.size(); i++) {
        archivo << "<tr>" << endl;
        archivo << "<td>" << empleados[i].getCedula() << "</td>" << endl;
        archivo << "<td>" << empleados[i].getNombre() << "</td>" << endl;
        archivo << "<td>" << empleados[i].getApellido() << "</td>" << endl;
        archivo << "<td>" << empleados[i].getDireccion() << "</td>" << endl;
        archivo << "<td>" << empleados[i].getSalario() << "</td>" << endl;
        archivo << "<td>" << empleados[i].getAporteIess() << "</td>" << endl;
        archivo << "</tr>" << endl;
    }
    archivo << "</table>" << endl;
    archivo << "</body>" << endl;
    archivo << "</html>" << endl;
    archivo.close();
}


void rolPagos() {
    int opcion;
    vector<empleado> empleados;
    do{
        cout << "ROL DE PAGOS" << endl;
        cout << "1. Ingresar Empleado" << endl;
        cout << "2. Mostrar Empleados" << endl;
        cout << "3. Editar Empleado" << endl;
        cout << "4. Buscar Empleado" << endl;
        cout << "5. Generar Rol de Pagos" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch(opcion) {
            case 1: {
                ingresarEmpleado(empleados);
                system("pause");
                break;
            }
            case 2: {
                showEmpleados(empleados);
                system("pause");
                break;
            }
            case 3: {
                editEmpleados(empleados);
                system("pause");
                break;
            }
            case 4: {
                searchEmpleado(empleados);
                system("pause");
                break;
            }
            case 5: {
                generarRolPagos(empleados);
                system("pause");
                break;
            }
            case 6: {
                cout << "Saliendo..." << endl;
                break;
            }
            default: {
                cout << "Opcion no valida" << endl;
                system("pause");
                break;
            }
        }
        system("cls");
    }while(opcion != 6);
}
