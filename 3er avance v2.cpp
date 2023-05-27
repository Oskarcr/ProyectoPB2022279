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
	string nombre, descripcion, categoria, caracteristicas, genero, clasificacion, consola;
	float precio = 0;
	int id, anio; //Id es el numero de articulo
	bool eliminado;
};

void alta();
void modificacion();
void baja();
void lista();
void archivos();
void pedir(int i, int opcion);
void filtrar(int opcion, string valor);
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
		//cin.ignore();
		juegos[i].nombre = "prueba";
		juegos[i].descripcion = "prueba2";
		juegos[i].categoria = "prueba9";
		juegos[i].caracteristicas = "prueba3";
		juegos[i].anio = 2000;
		juegos[i].genero = "prueba5";
		juegos[i].clasificacion = "prueba6";
		juegos[i].consola = "prueba7";
		juegos[i].precio = 10;
		//for (int j = 1; j <= 8; j++) pedir(i, j);
		printf("\n");
		juegos[i].id = i + 1;
	}
}

void modificacion() {
	if (t <= 0) {
		printf("No se pueden modificar los registros ya que no ha dado de alta los juegos\n");
		return;
	}
	int opcion = 1;
	printf("Ingrese el numero de articulo que quiere modificar\n");
	Juego juego = encontrarJuego();
	printf("Ingrese que desea modificar:\n1.- Nombre\n2.- Descripcion\n3.- Categoria\n4.- Caracteristicas\n5.- A%co\n6.- Genero\n7.- Clasificacion\n8.- Consola\n9.- Precio\n", 164);
	scanf_s("%d", &opcion);
	while (opcion < 1||opcion > 8) {
		printf("Opcion invalida ingrese otra\n");
		scanf_s("%d", &opcion);
	}
	if(opcion != 5||opcion != 9) cin.ignore();
	pedir(juego.id - 1, opcion);
}

// Pide al usuario segun la opción y index colocados. 
// 1.- Nombre 2.- Descripcion 3.- Caracteristicas 4.- Año 5.- Genero 6.- Clasificacion 7.- Consola 8.- Precio 
void pedir(int i, int opcion) {
	switch (opcion) {
	case 1:
		printf("Ingrese el nombre del articulo\n");
		getline(cin, juegos[i].nombre);
		break;
	case 2:
		printf("Ingrese una descripcion del articulo\n");
		getline(cin, juegos[i].descripcion);
		break;
	case 3: 
		printf("Ingrese la categoria del articulo\n");
		getline(cin, juegos[i].categoria);
		break;
	case 4:
		printf("Ingrese las caracteristicas del articulo\n");
		getline(cin, juegos[i].caracteristicas);
		break;
	case 5:
		printf("Ingrese el a%co de lanzamiento\n", 164);
		scanf_s("%d", &juegos[i].anio);
		while (juegos[i].anio < 1952) { // En 1952 se hizo el primer videojuego
			printf("El a%co es invalido ingrese otro: ", 164);
			scanf_s("%d", &juegos[i].anio);
		}
		cin.ignore();
		break;
	case 6:
		printf("Ingrese el genero del articulo\n");
		getline(cin, juegos[i].genero);
		break;
	case 7:
		printf("Ingrese la clasificacion del articulo\n");
		getline(cin, juegos[i].clasificacion);
		break;
	case 8:
		printf("Ingrese la consola a la que pertenece el articulo\n");
		getline(cin, juegos[i].consola);
		break;
	case 9:
		printf("Ingrese el precio del articulo\n");
		scanf_s("%f", &juegos[i].precio);
		while (juegos[i].precio <= 0) {
			printf("El precio es invalido ingrese otro: ");
			scanf_s("%f", &juegos[i].precio);
		}
		juegos[i].precio = juegos[i].precio * 1.16f;
		cin.ignore();
		break;
	}
	
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
	} //Categoria genero y consola
	int opcion;
	string valor;
	printf("Ingrese por que desea filtrar:\n1.- Categoria\n2.- Genero\n3.- Consola\n");
	scanf_s("%d", &opcion);
	while (opcion < 1 || opcion > 3) {
		printf("Opcion invalida ingrese otra\n");
		scanf_s("%d", &opcion);
	}
	if (opcion == 1) printf("Ingrese la categoria");
	if (opcion == 2) printf("Ingrese el genero");
	if (opcion == 3) printf("Ingrese la consola");
	printf("\n");
	cin.ignore();
	getline(cin, valor);
	filtrar(opcion, valor);
}

// Filtra y muestra un registro segun la opcion elegida. "valor" hace referencia a las coincidencias
// 1.- Categoria\n2.- Genero\n3.- Consola
void filtrar(int opcion, string valor) {
	for (int i = 0; i < t; i++) {
		string valor2;
		if (opcion == 1) valor2 = juegos[i].categoria;
		if (opcion == 2) valor2 = juegos[i].genero;
		if (opcion == 3) valor2 = juegos[i].consola;
		if (valor2 == valor&&juegos[i].eliminado != true) {
			printf("\n\nItem id: %d", i + 1);
			printf("\nNombre: %s\n", juegos[i].nombre.c_str());
			printf("Descripcion: %s\n", juegos[i].descripcion.c_str());
			printf("Categoria: %s\n", juegos[i].categoria.c_str());
			printf("Caracteristicas: %s\n", juegos[i].caracteristicas.c_str());
			printf("A%co de lanzamiento: %d\n", 164, juegos[i].anio);
			printf("Genero: %s\n", juegos[i].genero.c_str());
			printf("Clasificacion: %s\n", juegos[i].clasificacion.c_str());
			printf("Consola: %s\n", juegos[i].consola.c_str());
			printf("Precio: %f\n\n", juegos[i].precio);
		}
	}
}

void archivos() {
	if (t <= 0) return;
	ofstream archivo;
	string nombre = "registro.txt";
	archivo.open(nombre.c_str(), ios::out);
	if (archivo.fail()) {
		printf("Error al crear el archivo\n");
		exit(1);
	}
	
	for (int i = 0; i < t; i++) {
		if (juegos[i].eliminado == true) {
			archivo << "REGISTRO ELIMINADO";
		}
		else {
			archivo << "Item id: " << juegos[i].id;
			archivo << "\nNombre: " << juegos[i].nombre;
			archivo << "\nDescripción: " << juegos[i].descripcion;
			archivo << "\nCategoria: " << juegos[i].categoria;
			archivo << "\nCaracteristicas: " << juegos[i].caracteristicas;
			archivo << "\nAño de lanzamiento: " << juegos[i].anio;
			archivo << "\nGenero: " << juegos[i].genero;
			archivo << "\nClasificacion: " << juegos[i].clasificacion;
			archivo << "\nConsola: " << juegos[i].consola;
			archivo << "\nPrecio: " << juegos[i].precio;
		}
		archivo << "\n\n";
	}
	archivo.close();
}

//Hace un scanf para encontrar por el id el juego indicado.
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