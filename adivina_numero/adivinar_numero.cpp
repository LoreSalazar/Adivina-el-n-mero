#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main() {

	int opcion = 0, rangom = 0, rangoM = 0, n_intentos = 0, intervalo = 0, flag_win = 0;
	int flag_intervalo = 0, r = 0;
	char ref;

	cout << "Bienvenido al juego\n";
	cout << "\n1)Jugar\n2)Salir \n\nPor favor selecciona una opcion para continuar: ";
	cin >> opcion;

	do {
		cout << "\nExcelente comencemos...";
		cout << "\nEscribe el numero menor del rango para adivinar: ";
		cin >> rangom;
		cout << "Ahora, escribe el numero del rango mayor a adivinar : ";
		cin >> rangoM;

		n_intentos = rangoM - rangom + 1;
		n_intentos = log2(n_intentos);

		cout << "\nExcelente, voy a adivinar tu numero en no mas de " << n_intentos << " intentos";

		cout << "\n\nAhora indicame si tu numero es mayor, menor o igual con los siguientes simbolos SIN HACER TRAMPA:";
		cout << "\n< Si tu numero es menor al que te muestro \n> Si tu numero es mayor al que te muestro \n= Si he adivinado tu numero";

		r = rangoM - rangom;
		r = r / 2;
		//r = ceil(r);
		cout << "\n¿Tu numero es: " << r << "?";
		cin >> ref;

		while (flag_win != 1) {

			switch (ref) {
			case '<':
				rangoM = r;
				r = (rangoM + rangom) / 2;
				//r = ceil(r);
				cout << "\n¿Tu numero es: " << r << "?";
				cin >> ref;
				break;
			case '>':
				rangom = r;
				r = (rangoM + rangom) / 2;
				//r = ceil(r);
				cout << "\n¿Tu numero es: " << r << "?";
				cin >> ref;
				break;
			case '=':
				cout << "EXCELENTE EH ADIVINADO, TU NUMERO ES: " << r;
				flag_win = 1;
				break;
			default:
				cout << "CARACTER INCORRCTO, EL JUEGO SE REINICIARA...";
				break;
			}
		}

		cout << "\n1)Jugar\n2)Salir \n\nPor favor selecciona una opcion para continuar: ";
		cin >> opcion;
		flag_win = 0;

	} while (opcion == 1);
}