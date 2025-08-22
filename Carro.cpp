#include "Carro.h"
Carro::Carro(string _tipo_vehiculo, string _color, float _saldo, int _x, int _y, bool _pagado) {
	tipo_vehiculo = _tipo_vehiculo;
	color = _color;
	saldo = _saldo;
	x = _x;
	y = _y;
	pagado = _pagado;
}
Carro::~Carro() {
	
}

string Carro::getTipo() {
	return tipo_vehiculo;
}
string Carro::getColor() {
	return color;
}
float Carro::getSaldo() {
	return saldo;
}
bool Carro::getPagado() {
	return pagado;
}
char Carro::representacion(string _tipo) {
	return _tipo[0];
}
void Carro::ingresar_carro(char** estacionamiento, int tamano) {
	//Metooo que valida la posicione ingresa al estacionamiento
	int posicion_x = 0;
	int posicion_y = 0;
	do {
		posicion_x = rand() % tamano;
		posicion_y = rand() % tamano;
	} while (estacionamiento[posicion_x][posicion_y] != '_' );
	estacionamiento[posicion_x][posicion_y] = representacion(tipo_vehiculo);
	cout << "Carro ingresado en la posicion: (" << posicion_x << "," << posicion_y << ")" << endl;;
	x = posicion_x;
	y = posicion_y;
}
