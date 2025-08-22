#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class Carro {
	string tipo_vehiculo;
	string color;
	float saldo;
	bool pagado;
	int x;
	int y;
public:
	Carro(string _tipo_vehiculo, string _color, float _saldo, int _x, int _y, bool _pagado);
	~Carro();
	string getTipo();
	string getColor();
	float getSaldo();
	bool getPagado();
	void pagar();
	char representacion(string _nombre);
	void ingresar_carro();
	void retirar_carro();
};

