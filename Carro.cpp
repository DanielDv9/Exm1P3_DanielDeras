#include "Carro.h"
Carro::Carro(string _tipo_vehiculo, string _color, float _saldo, int _x, int _y, bool _pagado) {
	tipo_vehiculo = _tipo_vehiculo;
	color = _color;
	saldo = _saldo;
	x = _x;
	y = _y;
	pagado = _pagado;
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
char Carro::representacion(string _nombre) {
	return _nombre[0];
}
void Carro::ingresar_carro() {

}
