#include <iostream>
#include <conio.h>
#include <cmath>
#include <string.h>
#include <wchar.h>
#include <stdio.h>
#include <math.h>
#include <string>

using namespace std;

struct Juego {
	string nombre, descripcion, resena, genero, clasificacion, consola;
	float precio = 0;
};

Juego juegos[3];

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
			for (int i = 0; i < 3; i++) {
				cin.ignore();
				printf("Ingrese el nombre del articulo\n");
				getline(cin, juegos[i].nombre);
				printf("Ingrese una descripcion del articulo\n");
				getline(cin, juegos[i].descripcion);
				printf("Ingrese la resena del articulo\n");
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
					printf("Cantidad invalida ingrese otra:\n");
					scanf_s("%f", &juegos[i].precio);
				}
				juegos[i].precio = juegos[i].precio * 1.16f;
			}
			return main();
			break;
		case 2:
			return main();
			break;
		case 3:
			return main();
			break;
		case 4:
			for (int i = 0; i < 3; i++) {
				printf("\n\nNombre: %s\n", juegos[i].nombre.c_str());
				printf("Descripcion: %s\n", juegos[i].descripcion.c_str());
				printf("Resena: %s\n", juegos[i].resena.c_str());
				printf("Genero: %s\n", juegos[i].genero.c_str());
				printf("Clasificacion: %s\n", juegos[i].clasificacion.c_str());
				printf("Consola: %s\n", juegos[i].consola.c_str());
				printf("Precio: %f\n\n", juegos[i].precio);
			}
			return main();
			break;
		case 5:
			system("cls");
			return main();
			break;
		case 6:
			exit(1);
			break;
		}
	} while (op != 6);

}