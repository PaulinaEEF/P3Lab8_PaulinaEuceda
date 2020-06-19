#ifndef POST_H
#define POST_H

#include"Comentario.h"
#include<string>
#include <vector>

using std::vector;
using std::string;
class Post
{
	public:
		Post(string, string);
		
		string getTitulo();
		string getContenido();
		int getCantLikes();
		int getCantHates();
		void aumentarLikes();
		void aumentarHates();
		vector<Comentario*> getComentarios();
		void agregarComentario(Comentario*);
		
		~Post();
	protected:
		string titulo, contenido;
		int cantLikes, cantHates;
		vector<Comentario*> vectorComentarios;
};

#endif
