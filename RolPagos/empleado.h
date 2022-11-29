#pragma once

#include <iostream>

using namespace std;

class empleado {
    private:
        int cedula;
        string nombre;
        string apellido;
        string direccion;
        string salario;
        double aporteIess;
    public:
        empleado(int, string, string, string, string, double);
        int getCedula();
        string getNombre();
        string getApellido();
        string getDireccion();
        string getSalario();
        double getAporteIess();
        void setCedula(int);
        void setNombre(string);
        void setApellido(string);
        void setDireccion(string);
        void setSalario(string);
        void setAporteIess(double);
};