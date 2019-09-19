#include "pch.h"
#include "ArbolImagen.h"


ArbolImagen::ArbolImagen()
{
	Padre = NULL;
}


ArbolImagen::~ArbolImagen()
{
}

void ArbolImagen::Insertar(string nombre)
{
	NodoCubo *nuevo = new NodoCubo(nombre);
	if (Padre==NULL)
	{
		Padre = nuevo;
	}
	else
	{

	}
}
