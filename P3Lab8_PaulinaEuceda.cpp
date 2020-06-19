#include <iostream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include"Usuario.h"
#include"Comentario.h"
#include"Post.h"
#include"AdminUsuario.h"
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::getline;



int main(int argc, char** argv) {
	AdminUsuario* obUser = new AdminUsuario("Amigos.csv");
	vector<Usuario*> listaUsuarios;
	listaUsuarios.push_back(new Usuario("Paulina E. Euceda", "Paw", "123"));
	obUser->escribir(1);
	obUser->guardarUsuario(new Usuario("Paulina E. Euceda", "Paw", "123"));
	obUser->cerrarEscritura();
	listaUsuarios[0]->agregarPost(new Post("Holiwis", "Que dice mi genteee"));
	listaUsuarios[0]->agregarPost(new Post("Pensativa", "Este lab esta bonis"));
	
	
	listaUsuarios.push_back(new Usuario("Steve Rogers", "Capi", "123"));
	obUser->escribir(1);
	obUser->guardarUsuario(new Usuario("Steve Rogers", "Capi", "123"));
	obUser->cerrarEscritura();
	
	listaUsuarios[1]->agregarPost(new Post("Love", "Peggy is the one for me"));
	
	listaUsuarios.push_back(new Usuario("Sam M.", "Samm", "123"));
	obUser->escribir(1);
	obUser->guardarUsuario(new Usuario("Sam M.", "Samm", "123"));
	obUser->cerrarEscritura();
	
	listaUsuarios[2]->agregarPost(new Post("War", "Humans are not trusted"));
	
	listaUsuarios.push_back(new Usuario("Katherine Z. Jones", "Kathy", "123"));
	obUser->escribir(1);
	obUser->guardarUsuario(new Usuario("Katherine Z. Jones", "Kathy", "123"));
	obUser->cerrarEscritura();
	listaUsuarios[3]->agregarPost(new Post("Stop", "No more movies with Adam Sandler"));
	listaUsuarios[0]->agregarSeguidos(listaUsuarios[2]);
	listaUsuarios[0]->agregarSeguidos(listaUsuarios[3]);
	
	bool controladorSalida=true;
	int eleccionMenuPrincipal;
	int posusuarioIngresado;
	
	while(controladorSalida){
		cout<<"1) Registrar Usuarios \n2) Ingresar \n3) Salir \nIngrese la opcion que desea: ";
		cin>>eleccionMenuPrincipal;
		
		switch(eleccionMenuPrincipal){
			case 1:{
				cout<<"---Registro---\n\n->Ingrese su nombre completo: ";
				string fullName;
				getline(cin,fullName);
				getline(cin,fullName);
				
				cout<<"->Ingrese su nombre de usuario: ";
				string username;
				cin>>username;
				
				cout<<"->Ingrese su contrasena: ";
				string password;
				cin>>password;
				
				listaUsuarios.push_back(new Usuario(fullName, username, password));
				obUser->escribir(1);
				obUser->guardarUsuario(new Usuario(fullName, username, password));
				obUser->cerrarEscritura();
				
				cout<<"Guardado exitosamente";
				cout<<endl<<endl;
				break;
			}
			case 2:{
				cout<<"---Login---"<<endl;
				listaUsuarios=obUser->cargarArchivoUsuario();
				cout<<"Ingrese username: ";
				string username;
				cin>>username;
				
				cout<<"Ingrese password: ";
				string password;
				cin>>password;
				bool comprobadorLogin=false;
				for(int i =0; i< listaUsuarios.size(); i++){
					if(listaUsuarios[i]->getUsername()==username && listaUsuarios[i]->getPassword() ==password){
						posusuarioIngresado=i;
						comprobadorLogin=true;
						break;				
					}
				}
				
				if(comprobadorLogin==true){
					cout<<"Bienvenido amiguito "<< listaUsuarios[posusuarioIngresado]->getUsername()<<endl<<endl;
					
					bool controladorSalidaMenuUsuario=true;
					while(controladorSalidaMenuUsuario){
						cout<<"__Posts__"<<endl;
						
						for(int i =0; i< listaUsuarios[posusuarioIngresado]->getSeguidos().size(); i++){
							cout<<"-> Posts de: "<<listaUsuarios[posusuarioIngresado]->getSeguidos()[i]->getUsername()<<endl;
							
							for(int j =0; j< listaUsuarios[posusuarioIngresado]->getSeguidos()[i]->getPosts().size(); j++){
								cout<< "--Titulo--\n"<<listaUsuarios[posusuarioIngresado]->getSeguidos()[i]->getPosts()[j]->getTitulo()<<endl;
								cout<<"'" << listaUsuarios[posusuarioIngresado]->getSeguidos()[i]->getPosts()[j]->getContenido()<<"' \n";
								cout<<"Likes: "<<listaUsuarios[posusuarioIngresado]->getSeguidos()[i]->getPosts()[j]->getCantLikes()<<endl;
								cout<<"Hates: "<<listaUsuarios[posusuarioIngresado]->getSeguidos()[i]->getPosts()[j]->getCantHates()<<endl<<endl;
								
							}
						}
						for(int i =0; i< listaUsuarios[posusuarioIngresado]->getPosts().size(); i++){
							cout<<"-> Posts de: "<<listaUsuarios[posusuarioIngresado]->getUsername()<<endl;
							
							cout<< "--Titulo--\n"<<listaUsuarios[posusuarioIngresado]->getPosts()[i]->getTitulo()<<endl;
							cout<<"'" << listaUsuarios[posusuarioIngresado]->getPosts()[i]->getContenido()<<"' \n";
							cout<<"Likes: "<<listaUsuarios[posusuarioIngresado]->getPosts()[i]->getCantLikes()<<endl;
							cout<<"Hates: "<<listaUsuarios[posusuarioIngresado]->getPosts()[i]->getCantHates()<<endl<<endl;
								
							
						}
						
						
						cout << "__Inicio__"<<endl;
						cout << "1) Crear post \n2) Comentar post \n3) Dar like \n4) Dar hate \n5) Seguir usuario \n6) Dejar de seguir a un usuario \n7) Salida \n->Ingrese la opcion que desea: ";
						int eleccionMenuInicio;
						cin >> eleccionMenuInicio;
						
						switch(eleccionMenuInicio){
							case 1:{//crear post
								cout << "Ingrese el titulo: ";
								string titulo;
								getline(cin,titulo);
								getline(cin,titulo);
								
								cout << "Ingrese el contenido: ";
								string contenido;
								getline(cin,contenido);
								
								listaUsuarios[posusuarioIngresado]->agregarPost(new Post(titulo, contenido));
								cout<<endl;
								break;
							}
							case 2:{//comentar post
								cout<<endl;
								cout<<"0) "<<listaUsuarios[posusuarioIngresado]->getUsername()<<endl;
								
								for(int j =0; j< listaUsuarios[posusuarioIngresado]->getPosts().size(); j++){
									cout<<j<<") Titulo: "<<listaUsuarios[posusuarioIngresado]->getPosts()[j]->getTitulo()<<endl;
									
								}
								cout<<endl;
								for(int i =0; i< listaUsuarios[posusuarioIngresado]->getSeguidos().size(); i++){
									int c=i+1;
									cout<<c<<") "<<listaUsuarios[posusuarioIngresado]->getSeguidos()[i]->getUsername()<<endl;
									
									
									
									for(int j =0; j< listaUsuarios[posusuarioIngresado]->getSeguidos()[i]->getPosts().size(); j++){
										cout<<j<<") Titulo: "<<listaUsuarios[posusuarioIngresado]->getSeguidos()[i]->getPosts()[j]->getTitulo()<<endl<<endl;
										
									}
								}
								
								cout<<"Ingrese la posicion del usuario que quiere comentar: ";
								int posUsuarioaComentar;
								cin>>posUsuarioaComentar;
								//posUsuarioaComentar--;
								
								cout<<"Ingrese la posicion del post que quiere comentar: ";
								int posComentarioaComentar;
								cin>>posComentarioaComentar;
								//posComentarioaComentar--;
								
								cout << "Ingrese el contenido: ";
								string contenido;
								getline(cin,contenido);
								getline(cin,contenido);
								
								string usernameDelQueComenta;
								usernameDelQueComenta=listaUsuarios[posusuarioIngresado]->getUsername();
								
								listaUsuarios[posUsuarioaComentar]->getPosts()[posComentarioaComentar]->agregarComentario(new Comentario(usernameDelQueComenta, contenido));
								cout<<endl;
								break;
							}
							case 3:{//dar like
								cout<<"0) "<<listaUsuarios[posusuarioIngresado]->getUsername()<<endl;
								
								for(int j =0; j< listaUsuarios[posusuarioIngresado]->getPosts().size(); j++){
									cout<<j<<") Titulo: "<<listaUsuarios[posusuarioIngresado]->getPosts()[j]->getTitulo()<<endl;
									
								}
								cout<<endl;
								for(int i =0; i< listaUsuarios[posusuarioIngresado]->getSeguidos().size(); i++){
									int c=i+1;
									cout<<c<<") "<<listaUsuarios[posusuarioIngresado]->getSeguidos()[i]->getUsername()<<endl;
									
									for(int j =0; j< listaUsuarios[posusuarioIngresado]->getSeguidos()[i]->getPosts().size(); j++){
										cout<<j<<") Titulo: "<<listaUsuarios[posusuarioIngresado]->getSeguidos()[i]->getPosts()[j]->getTitulo()<<endl<<endl;
										
									}
								}
								
								cout<<"Ingrese la posicion del usuario que quiere dar like: ";
								int posUsuarioaLikear;
								cin>>posUsuarioaLikear;
								//posUsuarioaComentar--;
								
								cout<<"Ingrese la posicion del post que quiere dar like: ";
								int posComentarioaLikear;
								cin>>posComentarioaLikear;
								//posComentarioaComentar--;
								
								listaUsuarios[posUsuarioaLikear]->getPosts()[posComentarioaLikear]->aumentarLikes();
								
								break;
							}
							case 4:{//dar hate
								cout<<"0) "<<listaUsuarios[posusuarioIngresado]->getUsername()<<endl;
								
								for(int j =0; j< listaUsuarios[posusuarioIngresado]->getPosts().size(); j++){
									cout<<j<<") Titulo: "<<listaUsuarios[posusuarioIngresado]->getPosts()[j]->getTitulo()<<endl;
									
								}
								cout<<endl;
								for(int i =0; i< listaUsuarios[posusuarioIngresado]->getSeguidos().size(); i++){
									int c=i+1;
									cout<<c<<") "<<listaUsuarios[posusuarioIngresado]->getSeguidos()[i]->getUsername()<<endl;
									
									for(int j =0; j< listaUsuarios[posusuarioIngresado]->getSeguidos()[i]->getPosts().size(); j++){
										cout<<j<<") Titulo: "<<listaUsuarios[posusuarioIngresado]->getSeguidos()[i]->getPosts()[j]->getTitulo()<<endl<<endl;
										
									}
								}
								
								cout<<"Ingrese la posicion del usuario que quiere dar hate: ";
								int posUsuarioaHatear;
								cin>>posUsuarioaHatear;
								//posUsuarioaComentar--;
								
								cout<<"Ingrese la posicion del post que quiere dar hate: ";
								int posComentarioaHatear;
								cin>>posComentarioaHatear;
								//posComentarioaComentar--;
								
								listaUsuarios[posUsuarioaHatear]->getPosts()[posComentarioaHatear]->aumentarHates();
								break;
							}
							case 5:{//seguir
								for(int j =0; j< listaUsuarios.size(); j++){
									cout<<j<<") Username: "<<listaUsuarios[j]->getUsername()<<endl;
								}
								
								cout<<"Ingrese la posicion del usuario que quiere seguir: ";
								int posUsuarioaSeguir;
								cin>>posUsuarioaSeguir;
								
								bool yastaba=true;
								for(int i =0; i< listaUsuarios[posusuarioIngresado]->getSeguidos().size(); i++){
									if(listaUsuarios[posusuarioIngresado]->getSeguidos()[i]->getUsername() == listaUsuarios[posUsuarioaSeguir]->getUsername()){
										yastaba=false;
									}
								}
								if(listaUsuarios[posusuarioIngresado]->getUsername()== listaUsuarios[posUsuarioaSeguir]->getUsername()){
									yastaba=false;
								}
								if(yastaba){
									listaUsuarios[posusuarioIngresado]->agregarSeguidos(listaUsuarios[posUsuarioaSeguir]);
								}else{
									cout<<"Ya se seguian o es usted mismo, vuelva a intentarlo"<<endl;
								}
								cout<<endl;
								break;
							}
							case 6:{//dejar de seguir
								for(int i =0; i< listaUsuarios[posusuarioIngresado]->getSeguidos().size(); i++){
									cout<<i<<") "<<listaUsuarios[posusuarioIngresado]->getSeguidos()[i]->getUsername()<<endl;
								}
								cout<<"Ingrese la posicion del usuario que quiere dejar de seguir: ";
								int posUsuarioaNoSeguir;
								cin>>posUsuarioaNoSeguir;
								
								listaUsuarios[posusuarioIngresado]->eliminarSeguidos(posUsuarioaNoSeguir);
								break;
							}
							case 7:{
								controladorSalidaMenuUsuario=false;
								break;
							}
						}
					}
					
				}else{
					cout<<"Intentelo de nuevo :( "<<endl<<endl;
				}
				
				break;
			}
			case 3:{
				controladorSalida=false;
				break;
			}
		}
	}
	
	
	return 0;
}
