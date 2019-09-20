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
		if (valorar(nuevo->nombre[0])<=valorar(temp->nombre[0]))
		{
			if (temp->izq==NULL)
			{
				temp->izq = nuevo;
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
		}
		else
		{
			temp = temp->der;
			insertarhoja(nuevo, temp);
		}
	}
}

int ArbolImagen::MostrarInorder(NodoCubo* padre, int valor)
{
	if (padre->izq != NULL)
	{
		valor = MostrarInorder(padre->izq, valor);
	}
	cout << valor << ": " << padre->nombre << "\n";
	valor++;
	if (padre->der != NULL)
	{
		valor = MostrarInorder(padre->der, valor);
	}
	return valor;
}

void ArbolImagen::CrearGrafico()
{
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	string direccionactual= string(buffer).substr(0, pos);
	ofstream file;
	file.open("C:/Imagenes/arbol.dot");
	file << "digraph G { \n";
	NodoCubo *temp = Padre;
	string valor = "";
	valor = AgregarNodoGrafico(valor, temp);
	file << valor;
	file << "}";
	file.close();
	system("dot -Tjpg C:/Imagenes/arbol.dot -o C:/Imagenes/imgarbol.jpg");
	system("C:/Imagenes/imgarbol.jpg");
}

string ArbolImagen::AgregarNodoGrafico(string valor,NodoCubo *temp)
{
	if (temp->izq!=NULL)
	{
		valor += temp->nombre + "->" + temp->izq->nombre+"\n";
		valor = AgregarNodoGrafico(valor, temp->izq);
	}
	if (temp->der!=NULL)
	{
		valor += temp->nombre + "->" + temp->der->nombre+"\n";
		valor = AgregarNodoGrafico(valor, temp->der);
	}
	return valor;
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

