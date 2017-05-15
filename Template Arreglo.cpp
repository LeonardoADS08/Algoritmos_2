#pragma once

const int MAXN = 100;

template<class T> class Arreglo
{
private:
	T _datos[MAXN];
	int _tam;
public:
	Arreglo(void);

	void Datos(int pos, T dato);
	T Datos(int pos);

	void Objeto(Arreglo<T> obj);
	Arreglo<T> Objeto();
};

template<class T>
Arreglo<T>::Arreglo()
{
	_tam = 0;
}

template<class T>
void Arreglo<T>::Datos(int pos, T dato)
{
	_datos[pos] = dato;
}

template<class T>
T Arreglo<T>::Datos(int pos)
{
	return _datos[T];
}

template<class T>
void Arreglo<T>::Objeto(Arreglo<T> obj)
{
	*this = obj;
}

template<class T>
Arreglo<T> Arreglo<T>::Objeto()
{
	return *this;
}
