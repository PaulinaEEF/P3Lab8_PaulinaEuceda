#include "Comentario.h"

Comentario::Comentario(string username, string contenido)
{
	this->username=username;
	this->contenido=contenido;
}

string Comentario::getUsername(){
	return username;
}
string Comentario::getContenido(){
	return contenido;
}

Comentario::~Comentario()
{
}
