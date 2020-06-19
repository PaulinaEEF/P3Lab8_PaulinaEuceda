#include "AdminUsuario.h"


AdminUsuario::AdminUsuario(string pFileName)
{
	fileName=pFileName;
}


bool AdminUsuario::guardarUsuario(Usuario* usuario){
	if(outputFile.is_open()){
		outputFile<< usuario->fullName <<','<< usuario->username<<','<< usuario->password<<'\n';
		return true;
	}else{
		return false;
	}
}
bool AdminUsuario::escribir(int modo){
	modoEscritura = modo;
	if(modoEscritura ==1)
		outputFile.open(fileName.c_str(), std::ios::app);
	else
		outputFile.open(fileName.c_str());
		
	return outputFile.is_open();
}

bool AdminUsuario::cerrarEscritura(){
	outputFile.close();
	return !outputFile.is_open();
}

void AdminUsuario::leerUsuario(vector<Usuario*>& usuario){
	archivoUsuario.open("Amigos.csv",ios::in);
	if(archivoUsuario.fail()){
		exit(1);
	}
	
	while(!archivoUsuario.eof()){
		string texto;
		getline(archivoUsuario,texto);
		string token [3];
		int cont=0;
	
			for(int j; j< texto.length(); j++){
				if(texto[j]!= ','){
					token[cont]+=texto[j];
				} else{
					cont++;
				}
			}
		
		usuario.push_back(new Usuario(token[0],token[1],token[2]));
	}
	
	for(int i =0; i< usuario.size(); i++){
		cout<<usuario[i]->getUsername()<<endl;
	}
	
	
}

vector<Usuario*> AdminUsuario::cargarArchivoUsuario(){
	vector<Usuario*> retval;
	archivoUsuario.open("Amigos.csv",ios::in);
	if(archivoUsuario.fail()){
		exit(1);
	}
	while(!archivoUsuario.eof()){
		string fullName,username,password;
		string buffer;
		getline(archivoUsuario,buffer);
		
		stringstream mystream;
		mystream<< buffer;
		
		getline(mystream,fullName,',');
		getline(mystream,username,',');
		getline(mystream,password,',');
		
		retval.push_back(new Usuario(fullName,username,password));
	}
		
	return retval;
	
}



AdminUsuario::~AdminUsuario()
{
}
