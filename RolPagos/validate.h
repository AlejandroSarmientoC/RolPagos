#pragma once

#include <iostream>
#include "lista.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

bool validateCI(int cedula, vector<empleado> &empleados) {
    for (int i = 0; i < empleados.size(); i++) {
        if (empleados[i].getCedula() == cedula) {
            return false;
        }
    }
    return true;
}

//validar si es un String
bool validateString(string cadena) {
    //que no contenga espacios numeros y caracteres especiales
    for (int i = 0; i < cadena.length(); i++) {
        if (cadena[i] == ' ' || isdigit(cadena[i]) || !isalpha(cadena[i])) {
            return false;
        }
    }
    return true;
}

bool validateDouble(string val){
    for (int i = 0; i < val.length(); i++) {
        if (isdigit(val[i]) || val[i] == '.') {
            return true;
        }
    }
    return false;
}

bool isNumber(string val){
    for (int i = 0; i < val.length(); i++) {
        if (isdigit(val[i])) {
            return true;
        }
    }
    return false;
}


//transformar un string a double
double stringToDouble(string val) {
    double num;
    num = atof(val.c_str());
    return num;
}