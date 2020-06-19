#include "Post.h"

Post::Post(string titulo, string contenido)
{
	this->titulo=titulo;
	this->contenido=contenido;
	this->cantLikes=cantLikes;
	this->cantHates=cantHates;
}

string Post::getTitulo(){
	return titulo;
}
string Post::getContenido(){
	return contenido;
}
int Post::getCantLikes(){
	return cantLikes;
}
int Post::getCantHates(){
	return cantHates;
}
void Post::aumentarLikes(){
	cantLikes++;
}
void Post::aumentarHates(){
	cantHates++;
}
vector<Comentario*> Post::getComentarios(){
	return vectorComentarios;
}
void Post::agregarComentario(Comentario* comentario){
	vectorComentarios.push_back(comentario);
}

Post::~Post()
{
}
