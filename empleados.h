#pragma once
#include "persona.h"
#include<iostream>
#include<mysql.h>
#include "ConexionBD.h"
#include <string>
#include "persona.h"
using namespace std;


class empleados : persona {



public:
	empleados() {

	}
	empleados(string nom, string ape, string dir, int tel, int DPI, int g, string fn, int ip, string fil, string fi) : persona(nom, ape, dir, DPI, tel, fn, ip, fil, fi, g) {


	}


	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setDPI(int dpi) { DPI = dpi; }
	void setgenero(int g) { genero = g; }
	void setFecha_Nacimiento(string fn) { fecha_nacimiento = fn; }
	void setid_puesto(int ip) { id_puesto = ip; }
	void setFecha_ingreso_laboral(string fil) { fecha_inicio_laboral = fil; }
	void setfecha_ingreso(string fi) { fecha_ingreso = fi; }



	//get (mostrar)

	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	int getDPI() { return DPI; }
	int  getGenero() { return genero; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }
	int getId_puesto() { return id_puesto; }
	string getFecha_ingreso_laboral() { return fecha_inicio_laboral; }
	string getFecha_ingreso() { return fecha_ingreso; }



	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string d = to_string(DPI);
			string ip = to_string(id_puesto);
			string g = to_string(genero);
			string insertar = "INSERT INTO empleados(nombres,apellidos,direccion,telefono,dpi,genero,fecha_nacimiento,id_puesto,fecha_inicio_laboral,fecha_ingreso) VALUES (' " + nombres + " ',' " + apellidos + " ',' " + direccion + " ', " + t + " , " + d + " , " + g + " ,' " + fecha_nacimiento + " ',' " + ip + " ', ' " + fecha_inicio_laboral + " ',' " + fecha_ingreso + " ')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}

		}
		else {
			cout << "---Error en la conexion---" << endl;
		}
		cn.cerra_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "Select * from empleados ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "---------------------Mostrar personas---------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8] << "," << fila[8] << "," << fila[10] << endl;
				}
			}
			else {
				cout << "Error al ingresar datos" << endl;
			}
		}
		else {
			cout << "----Error en la conexion---" << endl;
		}

		cn.cerra_conexion();
	}
	void  modificar_empleado(int emp) {

		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string id = to_string(emp);
			string t = to_string(telefono);
			string d = to_string(DPI);
			string ip = to_string(id_puesto);
			string g = to_string(genero);

		


			string consulta = "select * from empleados where id_empleado= " + id + "";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "id empleado: " << fila[0] << endl;
					cout << "nombres: " << fila[1] << endl;
					cout << "apellidos: " << fila[2] << endl;
					cout << "Direccion: " << fila[3] << endl;
					cout << "telefono: " << fila[4] << endl;
					cout << "DPI: " << fila[5] << endl;
					cout << "Genero " << fila[6] << endl;
					cout << "Fecha nacimiento: " << fila[7] << endl;
					cout << "id puesto: " << fila[8] << endl;
					cout << "Fecha inicio laboral: " << fila[9] << endl;
					cout << "Fecha ingreso: " << fila[10] << endl;

					cout << ("\n\nNuevo Nombres: ") << fila[1] << endl;
					cin >> nombres;

					cout << ("\n\n Nuevos apellidos: ") << fila[2] << endl;
					cin >> apellidos;

					cout << ("\n\nNueva Direccion: ") << fila[3] << endl;
					cin >> direccion;

					cout << ("\n\nNuevo Telefono: ") << fila[4] << endl;
					cin >> telefono;

					cout << ("\n\nNuevo DPI: ") << fila[5] << endl;
					cin >> DPI;

					cout << ("\n\nNuevo Fecha de nacimiento: ") << fila[6] << endl;
					cin >> fecha_nacimiento;

					cout << ("\n\nNuevo id puesto: ") << fila[7] << endl;
					cin >> ip;

					cout << ("\n\nFecha inicio laboral ") << fila[8] << endl;
					cin >> fecha_inicio_laboral;

					cout << ("\n\nFecha Ingreso ") << fila[8] << endl;
					cin >> fecha_ingreso;


					string t = to_string(telefono);
					string d = to_string(DPI);
					string ip = to_string(id_puesto);
					string g = to_string(genero);


					string consulta = "UPDATE examen SET id_empleado = ,nombres = ,apellidos =,direccion = ,telefono = ,DPI = ,Genero = ,Fecha_nacimiento = ,id_puesto = ,Fecha_inicio_laboral = Fecha_ingreso WHERE id_empleado = ";
					const char* c = consulta.c_str();
					q_estado = mysql_query(cn.getConectar(), c);

				}

			}
			else {
				cout << "\n\n--------- Error al modificar  ---------" << endl;
			}

		}
		else {
			cout << " \n\n---------  Error en la Conexion ---------" << endl;
		}
		cn.cerra_conexion();
	}
	void eliminar_producto(int emp) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		char m;
		if (cn.getConectar()) {
			string id = to_string(emp);

			string consulta = "select * from empleados where id_empleado= " + id + "";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "id empleado: " << fila[0] << endl;
					cout << "nombres: " << fila[1] << endl;
					cout << "apellidos: " << fila[2] << endl;
					cout << "Direccion: " << fila[3] << endl;
					cout << "telefono: " << fila[4] << endl;
					cout << "DPI: " << fila[5] << endl;
					cout << "Genero " << fila[6] << endl;
					cout << "Fecha nacimiento: " << fila[7] << endl;
					cout << "id puesto: " << fila[8] << endl;
					cout << "Fecha inicio laboral: " << fila[9] << endl;
					cout << "Fecha ingreso: " << fila[10] << endl;
					cin >> m;
					if (m == 's') {
						string consulta = "delete from empleados where id_empleado =" + id + "";
						const char* c = consulta.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
						cout << ("\n\nDatos Eliminados correctamente");
					}
				}

			}
			else {
				cout << "\n\n--------- Error al modificar  ---------" << endl;
			}

		}
		else {
			cout << " \n\n---------  Error en la Conexion ---------" << endl;
		}
		cn.cerra_conexion();

	}


};
