#pragma once
#include "Arreglo.h"
#include <string>
#include "Deporte.h"
#include "Atleta.h"
#include "Medicamento.h"
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;

class Interfaz
{
private:
	Arreglo<Deporte> _deportes;
	Arreglo<Atleta> _atletas;
	Arreglo<Medicamento> _medicamentos;

public:
	Interfaz(void);

	void NuevoDeporte(TextBox^ TB_Nombre);
	void CargarDeportes(DataGridView^ tabla);

	void NuevoAtleta(TextBox^ TB_Nombre, TextBox^ TB_Codigo);
	void CargarAtletas(DataGridView^ tabla);

	void NuevoMedicamento(TextBox^ TB_Nombre, TextBox^ TB_Codigo, TextBox^ TB_Descripcion, CheckBox^ CB_Nocivo);
	void CargarMedicamentos(DataGridView^ tabla);
};

Interfaz::Interfaz() {

	_atletas.Tamano(0);
}

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

void Interfaz::NuevoAtleta(TextBox^ TB_Nombre, TextBox^ TB_Codigo)
{
	string nombre = msclr::interop::marshal_as<std::string>(TB_Nombre->Text);
	string codigo = msclr::interop::marshal_as<std::string>(TB_Codigo->Text);
	int posNuevoAtleta = _atletas.Tamano();
	Atleta aux;
	aux.Nombre(nombre);
	aux.Codigo(codigo);
	_atletas.Datos(posNuevoAtleta,  aux);
	_atletas.Tamano(posNuevoAtleta + 1);
}

void Interfaz::CargarAtletas(DataGridView^ tabla)
{
	tabla->ColumnCount = 2;
	tabla->Columns[0]->Name = "Codigo";
	tabla->Columns[1]->Name = "Nombre";
	tabla->RowCount = _atletas.Tamano();
	for(int i = 0; i < _atletas.Tamano(); ++i)
	{
		string auxCodigo = _atletas.Datos(i).Codigo();
		string auxNombre = _atletas.Datos(i).Nombre();
		tabla->Rows[i]->Cells[0]->Value = gcnew String(auxCodigo.c_str());
		tabla->Rows[i]->Cells[1]->Value = gcnew String(auxNombre.c_str());
	}
}

void Interfaz::NuevoMedicamento(TextBox^ TB_Nombre, TextBox^ TB_Codigo, TextBox^ TB_Descripcion, CheckBox^ CB_Nocivo)
{
	string nombre = msclr::interop::marshal_as<std::string>(TB_Nombre->Text);
	string codigo = msclr::interop::marshal_as<std::string>(TB_Codigo->Text);
	string descripcion = msclr::interop::marshal_as<std::string>(TB_Descripcion->Text);
	bool nocivo = CB_Nocivo->Checked;
	int posNuevoMedicamento = _medicamentos.Tamano();
	Medicamento aux;
	aux.Nombre(nombre);
	aux.Codigo(codigo);
	aux.Descripcion(descripcion);
	aux.Nocivo(nocivo);
	_medicamentos.Datos(posNuevoMedicamento,  aux);
	_medicamentos.Tamano(posNuevoMedicamento + 1);
}

void Interfaz::CargarMedicamentos(DataGridView^ tabla)
{
	tabla->ColumnCount = 4;
	tabla->Columns[0]->Name = "Codigo";
	tabla->Columns[1]->Name = "Nombre";
	tabla->Columns[2]->Name = "Descripción";
	tabla->Columns[3]->Name = "Nocivo";
	tabla->RowCount = _atletas.Tamano();
	for(int i = 0; i < _atletas.Tamano(); ++i)
	{
		string auxCodigo = _atletas.Datos(i).Codigo();
		string auxNombre = _atletas.Datos(i).Nombre();
		tabla->Rows[i]->Cells[0]->Value = gcnew String(auxCodigo.c_str());
		tabla->Rows[i]->Cells[1]->Value = gcnew String(auxNombre.c_str());
	}
}
