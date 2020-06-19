#ifndef COMENTARIO_H
#define COMENTARIO_H

#include<string>

using std::string;

class Comentario
{
	public:
		Comentario(string, string);
		
		string getUsername();
		string getContenido();
		
		~Comentario();
	protected:
		string username, contenido;
		
		
};

#endif
