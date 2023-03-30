#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	char validacion[100], nombre[100], descripcion[100], resena[100], genero[100], clasificacion[100], consola[100];
	float precio;
	int op;

	cout << "\t~~~*~~~*~* MENU *~*~~~*~~~" << endl;
	cout << "1 - Alta de articulos" << endl;
	cout << "2 - Modificación de articulos" << endl;
	cout << "3 - Baja de articulos" << endl;
	cout << "4 - Lista de articulos" << endl;
	cout << "5 - Limpiar pantalla" << endl;
	cout << "6 - Salir" << endl;

	cin >> op;
	if (op < 1||op > 6) {
		cout << "Opcion invalida regresando al menu..." << endl;
		return main();
	}
	switch (op) {
	case 1:
		cin.ignore();
		cout << "Ingrese el nombre del articulo " << endl;
		cin.getline(nombre, 100, '\n');
		cout << "Ingrese una descripcion del articulo" << endl;
		cin.getline(descripcion, 100, '\n');
		cout << "Ingrese la resena del articulo" << endl;
		cin.getline(resena, 100, '\n');
		cout << "Ingrese el genero del articulo" << endl;
		cin.getline(genero, 100, '\n');
		cout << "Ingrese la clasificacion del articulo" << endl;
		cin.getline(clasificacion, 100, '\n');
		cout << "Ingrese la consola a la que pertenece el articulo" << endl;
		cin.getline(consola, 100, '\n');
		cout << "Ingrese el precio del articulo" << endl;
		cin >> precio;
		cout << endl << "Nombre del articulo " << nombre << endl;
		cout << "Descripcion: " << descripcion << endl;
		cout << "Resena: " << resena << endl;
		cout << "Genero: " << genero << endl;
		cout << "Clasificacion: " << clasificacion << endl;
		cout << "Consola: " << consola << endl;
		cout << "Precio: " << precio << endl;
		cout << endl << "Ingrese 1. para agregar otro articulo; Ingrese cualquier otro para regresar al menu" << endl;
		cin.getline(validacion, 100, '\n');
		if (validacion != "1") {
			return main();
		}
		else {
			return main();
		}
		break;
	case 2:
		return main();
		break;
	case 3:
		return main();
		break;
	case 4:
		return main();
		break;
	case 5: system("cls");
		return main();
		break;
	case 6: exit(1);
		break;
	}
}