#pragma once

#include<mysql.h>
#include<iostream>

using namespace std;
class ConexionBD{
private: MYSQL* conectar;
public :
	void abrir_conexion() {
		conectar = mysql_init(0);
		conectar=mysql_real_connect(conectar, "localhost", "usuariop@rc", "p@rcial2", "examen", 3306, NULL, 0);
	}
	void cerra_conexion() {
		mysql_close(conectar);
	}
	MYSQL* getConectar() {
		return conectar;
	}
};

