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
		NodoCubo *temp = Padre;
		cout << nuevo->nombre[0] << "--" << temp->nombre[0];
		if (valorar(nuevo->nombre[0])<=valorar(temp->nombre[0]))
		{
			if (temp->izq==NULL)
			{
				temp->izq = nuevo;
				cout << "Insertado a la izquierda";
			}
			else
			{
				temp = temp->izq;
				insertarhoja(nuevo, temp);
			}
		}
		else
		{
			if (temp->der==NULL)
			{
				temp->der = nuevo;
				cout << "Insertado a la derecha";
			}
			else
			{
				temp = temp->der;
				insertarhoja(nuevo, temp);
			}
		}
	}
}

void ArbolImagen::insertarhoja(NodoCubo *nuevo, NodoCubo *temp)
{
	if (valorar(nuevo->nombre[0]) <= valorar(temp->nombre[0]))
	{
		if (temp->izq == NULL)
		{
			temp->izq = nuevo;
			cout << "Insertado a la izquierda";
		}
		else
		{
			temp = temp->izq;
			insertarhoja(nuevo, temp);
		}
	}
	else
	{
		if (temp->der == NULL)
		{
			temp->der = nuevo;
			cout << "Insertado a la derecha";
		}
		else
		{
			temp = temp->der;
			insertarhoja(nuevo, temp);
		}
	}
}

void ArbolImagen::MostrarInorder(NodoCubo* padre)
{
	if (padre->izq!=NULL)
	{
		MostrarInorder(padre->izq);
	}

	cout << padre->nombre << "\n";

	if(padre->der!=NULL)
	{
		MostrarInorder(padre->der);
	}
}

int ArbolImagen::valorar(char letra) {
	letra=tolower(letra);
	switch (letra)
	{
	case 'a':
		return 1;
	case 'b':
		return 2;
	case 'c':
		return 3;
	case 'd':
		return 4;
	case 'e':
		return 5;
	case 'f':
		return 6;
	case 'g':
		return 7;
	case 'h':
		return 8;
	case 'i':
		return 9;
	case 'j':
		return 10;
	case 'k':
		return 11;
	case 'l':
		return 12;
	case 'm':
		return 13;
	case 'n':
		return 14;
	case 'o':
		return 15;
	case 'p':
		return 16;
	case 'q':
		return 17;
	case 'r':
		return 18;
	case 's':
		return 19;
	case 't':
		return 20;
	case 'u':
		return 21;
	case 'v':
		return 22;
	case 'w':
		return 23;
	case 'x':
		return 24;
	case 'y':
		return 25;
	case 'z':
		return 26;
	default:
		return 27;
	}
	return 0;
}

