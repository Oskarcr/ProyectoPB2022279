#include <iostream>
#include <conio.h>
#include <cmath>
#include <string.h>
#include <wchar.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <stdlib.h>  
#include <vector>
#include <fstream>

using namespace std;

struct Juego {
	string nombre, descripcion, resena, genero, clasificacion, consola;
	float precio = 0;
	int id;
	bool eliminado;
};

void alta();
void modificacion();
void baja();
void lista();
void archivos();
void establecerJuego(int i);
Juego encontrarJuego();

// Referente al tamaño del arreglo
int t = 0;

Juego* juegos;

int main() {
	int op = 0;
	do {
		printf("\t~~~*~~~*~* MENU *~*~~~*~~~\n");
		printf("1 - Alta de articulos\n");
		printf("2 - Modificacion de articulos\n");
		printf("3 - Baja de articulos\n");
		printf("4 - Lista de articulos\n");
		printf("5 - Limpiar pantalla\n");
		printf("6 - Salir\n");
		scanf_s("%d", &op);
		switch (op) {
		case 1:
			alta();
			break;
		case 2:
			modificacion();
			break;
		case 3:
			baja();
			break;
		case 4:
			lista();
			break;
		case 5:
			system("cls");
			break;
		case 6:
			archivos();
			exit(1);
			return 0;
			break;
		}
		return main();
	} while (op != 6);

}

void alta() {
	printf("Digite el numero de registros que desea dar de alta\n");
	scanf_s("%d", &t);
	while (t <= 0) {
		printf("Ingrese un numero de registros valido\n");
		scanf_s("%d", &t);
	}
	juegos = new Juego[t];
	for (int i = 0; i < t; i++) {
		establecerJuego(i);
		printf("\n");
		juegos[i].id = i + 1;
	}
}

void modificacion() {
	if (t <= 0) {
		printf("No se pueden modificar los registros ya que no ha dado de alta los juegos");
		return;
	}
	printf("Ingrese el numero de articulo que quiere modificar\n");
	Juego juego = encontrarJuego();
	establecerJuego(juego.id - 1);
}

void baja() {
	if (t <= 0) {
		printf("No se puede dar de baja los registros ya que no ha dado de alta los juegos");
		return;
	}
	printf("Ingrese el numero de articulo que desea dar de baja\n");
	Juego juego = encontrarJuego();
	juegos[juego.id - 1].eliminado = true;
}

void lista() {
	if (t <= 0) {
		printf("No se puede mostrar la lista de registros ya que no ha dado de alta los juegos");
		return;
	}
	for (int i = 0; i < t; i++) {
		if (juegos[i].eliminado == true) {
			printf("%d - REGISTRO ELIMINADO", i + 1);
			continue;
		}
		printf("%d - \n", i + 1);
		printf("\n\nNombre: %s\n", juegos[i].nombre.c_str());
		printf("Descripcion: %s\n", juegos[i].descripcion.c_str());
		printf("Rese%ca: %s\n", 164, juegos[i].resena.c_str());
		printf("Genero: %s\n", juegos[i].genero.c_str());
		printf("Clasificacion: %s\n", juegos[i].clasificacion.c_str());
		printf("Consola: %s\n", juegos[i].consola.c_str());
		printf("Precio: %f\n\n", juegos[i].precio);
	}
}

void archivos() {
	if (t <= 0) return;
	ofstream archivo;                  //NOTA DE CLASE: clase ifstream para leer archivos
	string nombre = "registro.txt";
	archivo.open(nombre.c_str(), ios::out);
	if (archivo.fail()) {
		printf("Error al crear el archivo\n");
		exit(1);
	}
	
	for (int i = 0; i < t; i++) {
		if (juegos[i].eliminado == true) {
			archivo << "REGISTRO ELIMINADO" << "\n";
		}
		else {
			archivo << "Nombre: " << juegos[i].nombre;
			archivo << "\nDescripción: " << juegos[i].descripcion;
			archivo << "\nReseña: " << juegos[i].resena;
			archivo << "\nGenero: " << juegos[i].genero;
			archivo << "\nClasificacion: " << juegos[i].clasificacion;
			archivo << "\nConsola: " << juegos[i].consola;
			archivo << "\nPrecio: " << juegos[i].precio;
		}
		archivo << "\n\n";
	}
	archivo.close();
}

// Hace un scanf para encontrar por el id el juego indicado
Juego encontrarJuego() {
	int aux = 1;
	scanf_s("%d", &aux);
	while (aux > t || aux < 1) {
		printf("Registro inexistente ingrese otro numero de articulo");
		scanf_s("%d", &aux);
	}
	while (juegos[aux - 1].eliminado == true) {
		printf("Registro inexistente ingrese otro numero de articulo");
		return encontrarJuego();
	}
	return juegos[aux - 1];
}

// Establece los datos de un juego tomando en cuenta el index (indice)
void establecerJuego(int i) {
	cin.ignore();
	printf("Ingrese el nombre del articulo\n");
	getline(cin, juegos[i].nombre);
	printf("Ingrese una descripcion del articulo\n");
	getline(cin, juegos[i].descripcion);
	printf("Ingrese la rese%ca del articulo\n", 164);
	getline(cin, juegos[i].resena);
	printf("Ingrese el genero del articulo\n");
	getline(cin, juegos[i].genero);
	printf("Ingrese la clasificacion del articulo\n");
	getline(cin, juegos[i].clasificacion);
	printf("Ingrese la consola a la que pertenece el articulo\n");
	getline(cin, juegos[i].consola);
	printf("Ingrese el precio del articulo\n");
	scanf_s("%f", &juegos[i].precio);
	while (juegos[i].precio <= 0) {
		printf("El precio es invalido");
		scanf_s("%f", &juegos[i].precio);
	}
	juegos[i].precio = juegos[i].precio * 1.16f;
}