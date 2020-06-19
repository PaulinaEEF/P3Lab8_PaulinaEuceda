#ifndef ADMINPOST_H
#define ADMINPOST_H
#include"Post.h"
#include<iostream>
#include <string>
#include<sstream>
#include <fstream>
#include<vector>

using namespace std;


class AdminPost
{
	public:
		AdminPost(string);
		bool guardarPost(Post* post);
		bool cerrarEscritura();
		bool escribir(int);
		
		bool leerArchivo();
		void leerPost(vector<Post*>&);
		vector<Post*> cargarArchivoPost();
		
		~AdminPost();
	protected:
		string fileName;
		ofstream outputFile;
		ifstream archivoPost;
		int modoEscritura;
};

#endif
