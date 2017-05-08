#pragma once

#include <iostream>

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
	// horafinal(1,5,12);
	// horainicial.Sumar(horafinal)
	// horainicial = (4, 20, 22);
	
	void Restar(Hora val)
	{
		_horas -= val.Horas();
		Minutos(_minutos - val.Minutos());
		Segundos(_segundos - val.Segundos());
	}

	void Mostrar()
	{
		std::cout << _horas << ":"	<< _minutos << ":" << _segundos << "\n";
	}
};
