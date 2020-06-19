#ifndef USUARIO_H
#define USUARIO_H

#include<string>
#include"Post.h"
#include <vector>

using std::vector;
using std::string;

class AdminUsuario;

class Usuario
{
	public:
		Usuario(string, string, string);
		
		string getFullName();
		string getUsername();
		string getPassword();
		
		vector<Usuario*>& getSeguidos();
		void agregarSeguidos(Usuario*);
		void eliminarSeguidos(int);
		vector<Post*>& getPosts();
		void agregarPost(Post*);
		
		~Usuario();
	protected:
		string fullName, username, password;
		vector<Usuario*> listaSeguidos;
		vector<Post*> listaPosts;
		
		friend class AdminUsuario;
		
};

#endif
