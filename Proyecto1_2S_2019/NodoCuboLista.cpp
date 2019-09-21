#include "NodoCuboLista.h"

NodoCuboLista::NodoCuboLista()
{
	this->nombre = "";
	this->imagen = new Cubopx();
	sig = NULL;
	ant = NULL;
}

NodoCuboLista::NodoCuboLista(string nombre,vector<vector<string>> capas,Cubopx* imagen)
{

	this->nombre = nombre;
	this->capa = capas;
	this->imagen = imagen;
	sig = NULL;
	ant = NULL;
}

NodoCuboLista::~NodoCuboLista()
{
}
