#pragma once

#include <iostream>
#include "empleado.h"

using namespace std;

empleado::empleado(int cedula, string nombre, string apellido, string direccion, string salario, double aporteIess) {
    this->cedula = cedula;
    this->nombre = nombre;
    this->apellido = apellido;
    this->direccion = direccion;
    this->salario = salario;
    this->aporteIess = aporteIess;
}

int empleado::getCedula() {
    return cedula;
}

string empleado::getNombre() {
    return nombre;
}

string empleado::getApellido() {
    return apellido;
}

string empleado::getDireccion() {
    return direccion;
}

string empleado::getSalario() {
    return salario;
}

double empleado::getAporteIess() {
    return aporteIess;
}

void empleado::setCedula(int cedula) {
    this->cedula = cedula;
}

void empleado::setNombre(string nombre) {
    this->nombre = nombre;
}

void empleado::setApellido(string apellido) {
    this->apellido = apellido;
}

void empleado::setDireccion(string direccion) {
    this->direccion = direccion;
}

void empleado::setSalario(string salario) {
    this->salario = salario;
}

void empleado::setAporteIess(double aporteIess) {
    this->aporteIess = aporteIess;
}
