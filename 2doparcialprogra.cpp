
#include <windows.h>
#include "empleados.h"
#include <iostream>
#include <string>
using namespace std;
void modificar();
void eliminar();

int main()

{


	while (1)
	{
		int opc;
		cout << "------------------------------CRUD------------------------------" << endl;
		cout << "1 Nuevo Ingreso" << endl;
		cout << "2 Ver registros" << endl;
		cout << "2 Modificar registro" << endl;
		cout << "2 Eliminar registro" << endl;
		cin >> opc;
		cin.ignore();
		system("CLS");


		switch (opc)
		{
		case 1: {
			string nombres, apellidos, direccion, fecha_nacimiento, fecha_inicio_laboral, fecha_ingreso;
			int genero, telefono = 0, DPI = 0, id_puesto = 0;

			cout << "Ingrese sus nombres: ";
			getline(cin, nombres);
			cout << "Ingrese sus apellidos: ";
			getline(cin, apellidos);
			cout << "Ingrese su direccion: ";
			getline(cin, direccion);
			cout << "ingrese su numero de telefono: ";
			cin >> telefono;
			cin.ignore();
			cout << "Ingrese su DPI: ";
			cin >> DPI;
			cin.ignore();
			cout << "ingrese su genero: ";
			cin >> genero;
			cin.ignore();
			cout << "Ingrese su fecha de nacimiento: ";
			getline(cin, fecha_nacimiento);
			cout << "Ingrese el id puesto: ";
			cin >> id_puesto;
			cin.ignore();
			cout << "ingrese su fecha de inicio laboral: ";
			getline(cin, fecha_inicio_laboral);
			cout << "Ingrese su fecha de ingreso: ";
			getline(cin, fecha_ingreso);




			empleados p = empleados(nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, id_puesto, fecha_inicio_laboral, fecha_ingreso);
			p.crear();
			break;

		}
		case 2: {


			break;
		}
		 case 3: {
			int opciones;
			cout << "1) Update empleado" << endl;
			cout << "5) Salir " << endl;
			cin >> opciones;
			cin.ignore();
			switch (opciones) {
			case 1:
			{
				modificar();
				break;
			}
			}
			  
		}
		 case 4: {
			system("cls");
			 eliminar();
			 break;
		 }


			  system("pause");
			  return 0;
		}

		 void modificar(); {
			int emp;
			cout << ("Ingrese Id a modificar: ");
			cin >> emp;
			empleados p = empleados();
			p.modificar_empleado(emp);
			system("pause"); 
		}

	}
	void eliminar(); {
		int emp;
		cout << ("Ingrese Id a eliminar: ");
		cin >> emp;
		empleados p = empleados();
		p.eliminar_producto(emp);
		system("pause");
	}
	};
	

    
   
