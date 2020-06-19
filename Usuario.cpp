#include "Usuario.h"

Usuario::Usuario(string fullName, string username, string password)
{
	this->fullName=fullName;
	this->username=username;
	this->password=password;
}

string Usuario::getFullName(){
	return fullName;
}
string Usuario::getUsername(){
	return username;
}
string Usuario::getPassword(){
	return password;
}

vector<Usuario*>& Usuario::getSeguidos(){
	return listaSeguidos;
}
void Usuario::agregarSeguidos(Usuario* usuario){
	listaSeguidos.push_back(usuario);
}
vector<Post*>& Usuario::getPosts(){
	return listaPosts;
}
void Usuario::agregarPost(Post* post){
	listaPosts.push_back(post);
}
void Usuario::eliminarSeguidos(int pos){
	listaSeguidos.erase(listaSeguidos.begin()+ pos);
}

Usuario::~Usuario()
{
}
