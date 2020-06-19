#include "AdminPost.h"

AdminPost::AdminPost(string pFileName)
{
	fileName=pFileName;
}

bool AdminPost::guardarPost(Post* post){
	if(outputFile.is_open()){
		outputFile<< post->titulo <<','<< post->contenido<<'\n';
		return true;
	}else{
		return false;
	}
}
bool AdminPost::escribir(int modo){
	modoEscritura = modo;
	if(modoEscritura ==1)
		outputFile.open(fileName.c_str(), std::ios::app);
	else
		outputFile.open(fileName.c_str());
		
	return outputFile.is_open();
}

bool AdminPost::cerrarEscritura(){
	outputFile.close();
	return !outputFile.is_open();
}

void AdminPost::leerPost(vector<Post*>& post){
	archivoPost.open("Posts.csv",ios::in);
	if(archivoPost.fail()){
		exit(1);
	}
	
	while(!archivoPost.eof()){
		string texto;
		getline(archivoPost,texto);
		string token [2];
		int cont=0;
	
			for(int j; j< texto.length(); j++){
				if(texto[j]!= ','){
					token[cont]+=texto[j];
				} else{
					cont++;
				}
			}
		
		post.push_back(new Post(token[0],token[1]));
	}
	
	for(int i =0; i< post.size(); i++){
		cout<<post[i]->getTitulo()<<endl;
	}
	
	
}

vector<Post*> AdminPost::cargarArchivoPost(){
	vector<Post*> retval;
	archivoPost.open("Posts.csv",ios::in);
	if(archivoPost.fail()){
		exit(1);
	}
	while(!archivoPost.eof()){
		string titulo,contenido;
		string buffer;
		getline(archivoPost,buffer);
		
		stringstream mystream;
		mystream<< buffer;
		
		getline(mystream,titulo,',');
		getline(mystream,contenido,',');
		
		retval.push_back(new Post(titulo,contenido));
	}
		
	return retval;
	
}

AdminPost::~AdminPost()
{
}
