#ifndef ADMINUSUARIO_H
#define ADMINUSUARIO_H

#include"Usuario.h"
#include<iostream>
#include <string>
#include<sstream>
#include <fstream>
#include<vector>

using namespace std;

class AdminUsuario
{
	public:
		AdminUsuario(string);
		bool guardarUsuario(Usuario*);
		bool cerrarEscritura();
		bool escribir(int);
		
		bool leerArchivo();
		void leerUsuario(vector<Usuario*>&);
		vector<Usuario*> cargarArchivoUsuario();
		
		~AdminUsuario();
		
	protected:
		string fileName;
		ofstream outputFile;
		ifstream archivoUsuario;
		int modoEscritura;
	
};

#endif
