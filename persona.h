#pragma once
#include<iostream>
using namespace std;
class persona {

protected: string nombres, apellidos, direccion, fecha_nacimiento, fecha_inicio_laboral, fecha_ingreso;
	  int  genero=0,telefono = 0, DPI = 0 , id_puesto = 0;

protected:
	persona() {


	}

	persona(string nom, string ape, string dir, int dpi, int tel, string fn, int ip, string  fil, string fi, int g) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		DPI = dpi;
		fecha_nacimiento = fn;
		id_puesto = ip;
		fecha_inicio_laboral = fil;
		fecha_ingreso = fi;
		genero = g;
	}
};