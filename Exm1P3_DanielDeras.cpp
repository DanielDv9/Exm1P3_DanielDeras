#include <iostream>
using namespace std;
int** reservarEspacioDelTriangulo(int tamanio) {
	int** matriz = new int* [tamanio];
	for (int i = 0; i < tamanio; i++) {
		matriz[i] = new int[tamanio];
	}
	return matriz;
}
int pascal(int fila, int columna) {
	if (columna == 0 || columna == fila) {
		return 1;
	}
	else {
		return (pascal(fila - 1, columna - 1) + pascal(fila - 1, columna));
	}
}
int** generartriangulopascal(int tamanio, int** matriz) {
	for (int i = 0; i < tamanio; i++) {
		for (int j = 0; j <= i; j++) {
			matriz[i][j] = pascal(i, j);
		}
	}
	return matriz;
}
void imprimirTrianguloPascal(int** triangulo, int tamanio) {
	for (int i = 0; i < tamanio; i++){
		for (int k = 0; k < tamanio - i; k++) {
			cout << " ";
		}
		for (int j = 0; j <= i; j++) {
			cout << triangulo[i][j] << " ";
		}
		cout << endl;
	}
}
void liberarMemoria(int** triangulo, int tamanio) {
	for (int i = 0; i < tamanio; i++) {
		delete[] triangulo[i];
	}
	delete[] triangulo;
}
int main() {
	int respuesta;
	int** matriz;
	int tamano;
	do {
		cout << "--MENU--\n";
		cout << "1. Triangulo Pascal\n";
		cout << "2. Estacionamiento\n";
		cin >> respuesta;
		switch (respuesta) {
		case 1:
			do {
				cout << "Ingrese el numero de filas del Triangulo de Pascal: \n";
				cin >> tamano;
			} while (tamano < 3 || tamano > 5);
			matriz = reservarEspacioDelTriangulo(tamano);
			matriz = generartriangulopascal(tamano, matriz);
			imprimirTrianguloPascal(matriz, tamano);
			liberarMemoria(matriz, tamano);
			break;
		case 2:
			break;
		default:
			break;
		}
	} while (respuesta);
}
