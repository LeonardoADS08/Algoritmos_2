#pragma once

#include <iostream>

using namespace std;

class Deporte
{
private:
	string _nombre;

public:
	Deporte(void);

	void Nombre(string nuevoNombre);
	string Nombre();
};

Deporte::Deporte()
{
	_nombre = "";
}

void Deporte::Nombre(string nuevoNombre)
{
	_nombre = nuevoNombre;
}

string Deporte::Nombre()
{
	return _nombre;
}

