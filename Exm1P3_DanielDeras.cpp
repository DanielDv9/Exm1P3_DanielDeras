#include <iostream>
#include "Carro.h"
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
//Reserva el espacio del triangulo
int** reservarEspacioDelTriangulo(int tamanio) {
	int** matriz = new int* [tamanio];
	for (int i = 0; i < tamanio; i++) {
		matriz[i] = new int[tamanio];
	}
	return matriz;
}
//Metodo recursivo que retorna para obtener el numero pascal
int pascal(int fila, int columna) {
	if (columna == 0 || columna == fila) {
		return 1;
	}
	else {
		return (pascal(fila - 1, columna - 1) + pascal(fila - 1, columna));
	}
}
//Metodoo que asigna al espacio el numero de pascal usando el metodo recursivo
int** generartriangulopascal(int tamanio, int** matriz) {
	for (int i = 0; i < tamanio; i++) {
		for (int j = 0; j <= i; j++) {
			matriz[i][j] = pascal(i, j);
		}
	}
	return matriz;
}
//Imprime el triangulo de PAscal, imprimiendo pirmero los espacion y luego el triangulo 
void imprimirTrianguloPascal(int** triangulo, int tamanio) {
	for (int i = 0; i < tamanio; i++) {
		for (int k = 0; k < tamanio - i; k++) {
			cout << " ";
		}
		for (int j = 0; j <= i; j++) {
			cout << triangulo[i][j] << " ";
		}
		cout << endl;
	}
}
//Libera memoria del triangulo
void liberarMemoria(int** triangulo, int tamanio) {
	for (int i = 0; i < tamanio; i++) {
		delete[] triangulo[i];
	}
	delete[] triangulo;
}
//Imprime los vectores de Carros
void imprimir_vector(vector<Carro*>& carros) {
	for (int i = 0; i < carros.size(); i++) {
		cout << i + 1 << ". " << carros[i]->getTipo() << " - " << "Color: " << carros[i]->getColor() << " - " << "Saldo:" << carros[i]->getSaldo() << " - " << "Pagado: ";
		if (carros[i]->getPagado()) {
			cout << "si\n";
		}
		else {
			cout << "no\n";
		}
		cout << endl;
	}
}
//Reserva memoria del estacionamiento
char** crear_estacionamiento(int tamanio) {
	char** estacionamiento = new char* [tamanio];
	for (int i = 0; i < tamanio; i++) {
		estacionamiento[i] = new char[tamanio];
		for (int j = 0; j < tamanio; j++) {
			estacionamiento[i][j] = '_';
		}
	}
	return estacionamiento;
}
//Metodo que crea el numero de carros con un random y luego los guarda aun vector 
void agregar_carros(int tamanio, vector<Carro*>& carros_ingresados, char** estacionamiento) {
	int cantidad_carros = 5 + rand() % (15 - 5 + 1);
	string tipo_vehiculo;
	string color;
	bool pagado;
	for (int i = 0; i < cantidad_carros; i++) {
		float saldo = rand() % 100;
		int num_random = rand() % 3;
		switch (num_random) {
		case 0:
			tipo_vehiculo = "Sedan";
			break;
		case 1:
			tipo_vehiculo = "SUV";
			break;
		case 2:
			tipo_vehiculo = "Turismo";
			break;
		}
		num_random = rand() % 3;
		switch (num_random) {
		case 0:
			color = "Rojo";
			break;
		case 1:
			color = "Azul";
			break;
		case 2:
			color = "Amarillo";
			break;
		}
		int posicion_x = 0;
		int posicion_y = 0;
		//Valida si esta vacia la posicion
		do {
			posicion_x = rand() % tamanio;
			posicion_y = rand() % tamanio;
		} while (estacionamiento[posicion_x][posicion_y] != '_');
		Carro* carro = new Carro(tipo_vehiculo, color, saldo, posicion_x, posicion_y, false);
		estacionamiento[posicion_x][posicion_y] = carro->representacion(carro->getTipo());
		carros_ingresados.push_back(carro);
	}
}
//Imprime el estacionamiento
void imprimir_esttacionamiento(int tamanio, char** estacionamiento) {
	for (int i = 0; i < tamanio; i++) {
		for (int j = 0; j < tamanio; j++) {
			cout << estacionamiento[i][j] << ' ';
		}
		cout << endl;
	}
}
void ejercicio_1() {
	int tamano;
	int** matriz;
	do {
		cout << "Ingrese el numero de filas del Triangulo de Pascal: \n";
		cin >> tamano;
	} while (tamano < 3 || tamano > 5);
	matriz = reservarEspacioDelTriangulo(tamano);
	matriz = generartriangulopascal(tamano, matriz);
	imprimirTrianguloPascal(matriz, tamano);
	liberarMemoria(matriz, tamano);
}
void ejercicio_2() {
	srand(time(0));
	char** estacionamiento;
	int menu_estacionamiento = 0;
	vector<Carro*> carros;
	vector<Carro*> carros_ingresados;
	int tamanio_estacionamiento;
	//Valida si el nummero es correcto
	do {
		cout << "Ingrese el tamanio del estacionamiento: ";
		cin >> tamanio_estacionamiento;
	} while (tamanio_estacionamiento <= 3);
	estacionamiento = crear_estacionamiento(tamanio_estacionamiento);
	agregar_carros(tamanio_estacionamiento, carros_ingresados, estacionamiento);
	do {
		cout << "---ESTACIONAMIENTO---\n";
		imprimir_esttacionamiento(tamanio_estacionamiento, estacionamiento);
		cout << "\n Opciones \n";
		cout << "1. Nuevo Carro\n";
		cout << "2. Ingresar Carro al estacionamiento\n";
		cout << "3. Sacar Carro del estacionaminto\n";
		cout << "4. Ver Carros creados sin ingresar\n";
		cout << "5. Salir\n";
		cin >> menu_estacionamiento;
		switch (menu_estacionamiento) {
			//Crea un nuevo carro
		case 1: {
			string tipo;
			string color;
			float saldo;
			cout << "Ingrese el tipo de Carro: ";
			cin >> tipo;
			cout << "Ingrese el color de Carro ";
			cin >> color;
			cout << "Ingrese saldo de Carro ";
			cin >> saldo;
			Carro* carro = new Carro(tipo, color, saldo, -1, -1, false);
			carros.push_back(carro);
			cout << "Carro creado y listo para ingresar\n";
		}
			  break;
			  //Agrega uncarro al estacionamiento
		case 2:
			int numero_carro;
			if (carros.size() == 0) {
				cout << "No hay carros creados sin ingresar\n";
			}
			else {
				cout << "Carros disponibles para ingresar: \n";
				imprimir_vector(carros);
				cout << "Seleccione el numero del carro disponible: ";
				cin >> numero_carro;
				carros[numero_carro - 1]->ingresar_carro(estacionamiento, tamanio_estacionamiento);
			}
			break;
		case 4:
			//Impriime todos los carros no ingresado
			if (carros.size() == 0) {
				cout << "No hay carros creados sin ingresar\n";
			}
			else {
				cout << "Carros disponibles para ingresar: \n";
				imprimir_vector(carros);
			}
			break;
		default:
			break;
		}
	} while (menu_estacionamiento != 5);
	//Borra toda la memoria
	for (int i = 0; i < tamanio_estacionamiento; i++) {
		delete[] estacionamiento[i];
	}
	delete[] estacionamiento;
	for (int i = 0; i < carros.size(); i++) {
		delete carros[i];
	}
	for (int i = 0; i < carros_ingresados.size(); i++) {
		delete carros_ingresados[i];
	}
}
void menu() {
	int respuesta;
	do {
		cout << "--MENU--\n";
		cout << "1. Triangulo Pascal\n";
		cout << "2. Estacionamiento\n";
		cout << "0. Salir\n";
		cin >> respuesta;
		switch (respuesta) {
		case 1:
			ejercicio_1();
			break;
		case 2:
			ejercicio_2();
			break;
		default:
			break;
		}
	} while (respuesta);
}
int main() {
	menu();
}
