#pragma once

#include <iostream>

using namespace std;
class Hora
{
private:
	int _horas, _minutos, _segundos;

public:
	Hora()
	{
		_horas = _minutos = _segundos = 0;
	}

	Hora(int hora, int minuto, int segundo)
	{
		_horas = _minutos = _segundos = 0;
		Horas(hora);
		Minutos(minuto);
		Segundos(segundo);
	}
	
	// get-set
	int Horas() { return _horas; }
	void Horas(int val) { _horas = val; }

	int Minutos() { return _minutos; }
	void Minutos(int val) 
	{ 
		if (val >= 60)
		{
			int horasRestantes = val/60;
			_horas += horasRestantes;
			_minutos = val%60;
		}
		else _minutos = val; 
		
	}

	int Segundos() { return _segundos; }
	void Segundos(int val) 
	{ 
		if (val >= 60)
		{
			int minutosRestantes = val/60 + _minutos;
			Minutos(minutosRestantes);
			_segundos = val%60;
		}
		else _segundos = val; 
	}

	// Sumar y restar
	
	void Sumar(Hora val)
	{
		_horas += val.Horas();
		Minutos(_minutos + val.Minutos());
		Segundos(_segundos + val.Segundos());
	}

	// horainicial(3,15,10);
	// horafinal(1,30,12);
	// horainicial.Sumar(horafinal)
	// horainicial = (4, 20, 22);
	
	void Restar(Hora val)
	{
		throw 1;
		int auxH = _horas - val.Horas();
		int auxM, auxS;
		if (val.Minutos() > _minutos)
		{
			auxM = _minutos + 60 - val.Minutos();
			auxH--;
		}
		else auxM = _minutos - val.Minutos();
		if (val.Segundos() > _segundos)
		{
			auxS = _segundos + 60 - val.Segundos();
			auxM--;
		}
		else auxS = _segundos - val.Segundos();

		if (auxH < 0)
		{
			string exMessage = "No es posible realizar esta operacion, la cantidad de horas es menor a cero.";
			throw exMessage;
		}
		else
		{
			_horas = auxH;
			_minutos = auxM;
			_segundos = auxS;
		}
	}

	void Objeto(Hora val) { *this = val; }
	Hora Objeto() { return *this; }

	void Mostrar()
	{
		cout << _horas << ":"	<< _minutos << ":" << _segundos << endl;
	}
		
	// 
};

#pragma once
#include "Hora.h"
#include <iostream>
using namespace std;
class Fecha : public Hora
{
private:
	int _dia, _mes, _anho;

public:
	Fecha()
	{
		_dia = _mes = _anho = 0;
		Horas(0);
		Minutos(0);
		Segundos(0);
	}

	Fecha(int dia, int mes, int anho, Hora horaActual)
	{
		_dia = dia;
		_mes = mes;
		_anho = anho;
		Hora::Objeto(horaActual);
	}

	void Dia(int val) { _dia = val; }
	int Dia() { return _dia; }

	void Mes(int val) { _mes = val; }
	int Mes() { return _mes; }

	void Anho(int val) { _anho = val; }
	int Anho() { return _anho; }

	void Sumar(Fecha val)
	{
		if (val.Dia() + _dia > 30)
		{
			_mes += (val.Dia() + _dia) / 30;
			_dia = (val.Dia() + _dia) % 30;
		}
		else _dia += val.Dia();
		if (val.Mes() + _mes > 12)
		{
			_anho += (val.Mes() + _mes) / 12;
			_mes = (val.Mes() + _mes) % 12;
		}
		else _mes += val.Mes();
		_anho += val.Anho();
	}

	void Restar(Fecha val)
	{
		if (val.Dia() + _dia > 30)
		{
			_mes += (val.Dia() + _dia) / 30;
			_dia = (val.Dia() + _dia) % 30;
		}
		else _dia += val.Dia();
		if (val.Mes() + _mes > 12)
		{
			_anho += (val.Mes() + _mes) / 12;
			_mes = (val.Mes() + _mes) % 12;
		}
		else _mes += val.Mes();
		_anho += val.Anho();
	}

	void Mostrar()
	{
		cout << _dia << "/" << _mes << "/" << _anho << " - " << Horas() << ":" << Minutos() << ":" << Segundos() << endl;
	}

	void Objeto(Fecha val) { *this = val; }
	Fecha Objeto() { return *this; }

};

// Problemas.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <iostream>
#include "Hora.h"
#include <string>
#include "Fecha.h"
using namespace std;

int main()
{
	Hora *horaInicial = new Hora(1,59,70);
	Fecha *fechaInicial = new Fecha(8, 12, 2000, *horaInicial);

	fechaInicial->Mostrar();



    system("PAUSE");
    return 0;
}

