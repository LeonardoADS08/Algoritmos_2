#pragma once
#include "Arreglo.h"
#include <string>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;

class Interfaz
{
private:
	Arreglo<Deporte> _deportes;
	Arreglo<Atleta> _atletas;

public:
	Interfaz(void);

	void NuevoDeporte(TextBox^ nombre);
	void CargarDeportes(DataGridView^ tabla);

};

Interfaz::Interfaz() { }

void Interfaz::NuevoDeporte(TextBox^ TB_Nombre)
{
	string nombre = msclr::interop::marshal_as<std::string>(TB_Nombre->Text);
	int posNuevoDeporte = _deportes.Tamano();
	Deporte aux;
	aux.Nombre(nombre);
	_deportes.Datos(posNuevoDeporte,  aux);
	_deportes.Tamano(posNuevoDeporte + 1);
}

void Interfaz::CargarDeportes(DataGridView^ tabla)
{
	tabla->ColumnCount = 1;
	tabla->Columns[0]->Name = "Nombre del deporte";
	tabla->RowCount = _deportes.Tamano();
	for(int i = 0; i < _deportes.Tamano(); ++i)
	{
		string auxNombre = _deportes.Datos(i).Nombre();
		tabla->Rows[i]->Cells[0]->Value = gcnew String(auxNombre.c_str());
	}
}
