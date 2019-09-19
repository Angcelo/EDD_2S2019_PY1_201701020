#include "pch.h"
#include "Cubopx.h"
#include <string>;

Cubopx::Cubopx()
{
	Raiz = new Nodopx(-1,-1,-1,"Root");
	tamaño = 0;
}


Cubopx::~Cubopx()
{
}

Nodopx * Cubopx::BuscarCol(int x)
{
	Nodopx *temp = Raiz;
	while (temp!=NULL)
	{
		if (temp->x==x)
		{
			return temp;
		}
		temp = temp->sig;
	}
	return nullptr;
}

Nodopx * Cubopx::BuscarFila(int y)
{
	Nodopx *temp = Raiz;
	while (temp != NULL)
	{
		if (temp->y == y)
		{
			return temp;
		}
		temp = temp->arriba;
	}
	return nullptr;
}

Nodopx * Cubopx::BuscarCapa(int z)
{
	Nodopx *temp = Raiz;
	while (temp != NULL)
	{
		if (temp->x == z)
		{
			return temp;
		}
		temp = temp->sup;
	}
	return nullptr;
}

Nodopx * Cubopx::CrearCol(int x)
{
	Nodopx *cabezaCol = Raiz;
	Nodopx *columna = InsertarCol(new Nodopx(x, -1, -1, "Col"), cabezaCol);
	return columna;
}

Nodopx * Cubopx::CrearFila(int y)
{
	Nodopx *cabezaFila = Raiz;
	Nodopx *fila = InsertarCol(new Nodopx(-1, y, -1, "Fila"), cabezaFila);
	return fila;
}

Nodopx * Cubopx::CrearCapa(int z)
{
	Nodopx *cabezaCapa = Raiz;
	Nodopx *capa = InsertarCol(new Nodopx(-1, -1, z, "Capa"), cabezaCapa);
	return capa;
}

Nodopx * Cubopx::InsertarCol(Nodopx *nuevo, Nodopx *cabezaCol)
{
	Nodopx *temp = cabezaCol;
	bool bandera = false;
	while (true)
	{
		if (temp->x == nuevo->x) {
			temp->y = nuevo->y;
			temp->z = nuevo->z;
			temp->px = nuevo->px;
			return temp;
		}
		else if (temp->x > nuevo->x) {
			bandera = true;
			break;
		}
		if (temp->sig != NULL){
			temp = temp->sig;
		}
		else {
			break;
		}
	}
	if (bandera){
		nuevo->sig = temp;
		temp->ant->sig = nuevo;
		nuevo->ant = temp->ant;
		temp->ant = nuevo;
	}
	else {
		temp->sig = nuevo;
		nuevo->ant = temp;
	}
	return nuevo;
}

Nodopx * Cubopx::InsertarFila(Nodopx *nuevo, Nodopx *cabezaFila)
{
	Nodopx *temp = cabezaFila;
	bool bandera = false;
	while (true)
	{
		if (temp->y == nuevo->y) {
			temp->x = nuevo->x;
			temp->z = nuevo->z;
			temp->px = nuevo->px;
			return temp;
		}
		else if (temp->y > nuevo->y) {
			bandera = true;
			break;
		}
		if (temp->arriba != NULL) {
			temp = temp->arriba;
		}
		else {
			break;
		}
	}
	if (bandera) {
		nuevo->arriba = temp;
		temp->abajo->arriba = nuevo;
		nuevo->abajo = temp->abajo;
		temp->abajo = nuevo;
	}
	else {
		temp->arriba = nuevo;
		nuevo->abajo = temp;
	}
	return nuevo;
}

Nodopx * Cubopx::InsertarCapa(Nodopx *nuevo, Nodopx *cabezaCapa)
{
	Nodopx *temp = cabezaCapa;
	bool bandera = false;
	while (true)
	{
		if (temp->z == nuevo->z) {
			temp->x = nuevo->x;
			temp->y = nuevo->y;
			temp->px = nuevo->px;
			return temp;
		}
		else if (temp->z > nuevo->z) {
			bandera = true;
			break;
		}
		if (temp->sup != NULL) {
			temp = temp->sup;
		}
		else {
			break;
		}
	}
	if (bandera) {
		nuevo->sup = temp;
		temp->inf->sup = nuevo;
		nuevo->inf = temp->inf;
		temp->inf = nuevo;
	}
	else {
		temp->sup = nuevo;
		nuevo->inf = temp;
	}
	return nuevo;
}

void Cubopx::insertar(int x, int y, int z, string px)
{
	Nodopx *nuevo = new Nodopx(x, y, z, px);
	Nodopx *NodoCol=BuscarCol(x);
	Nodopx *NodoFila = BuscarFila(y);
	Nodopx *NodoCapa=BuscarCapa(z);
	Nodopx *Interseccionxy = new Nodopx(x,y,-1,"xy");
	Nodopx *Interseccionxz = new Nodopx(x, -1, z, "xz");
	Nodopx *Interseccionyz = new Nodopx(-1, y, z, "yz");
	//1)Col no, Fila no, Capa no
	if (NodoCol==NULL && NodoFila==NULL && NodoCapa==NULL){
		cout << "Caso1";
		NodoCol = CrearCol(x);
		NodoFila = CrearFila(y);
		NodoCapa = CrearCapa(z);
	}
	//2)Col no, Fila no, Capa si
	else if (NodoCol == NULL && NodoFila == NULL && NodoCapa != NULL) {
		cout << "Caso2";
		NodoCol = CrearCol(x);
		NodoFila = CrearFila(y);
	}
	//3)Col no, Fila si, Capa no
	else if (NodoCol == NULL && NodoFila != NULL && NodoCapa == NULL) {
		cout << "Caso3";
		NodoCol = CrearCol(x);
		NodoCapa = CrearCapa(z);
	}
	//4)Col no, Fila si, Capa si
	else if (NodoCol == NULL && NodoFila != NULL && NodoCapa != NULL) {
		cout << "Caso4";
		NodoCol = CrearCol(x);
	}
	//5)Col si, Fila no, Capa no
	else if (NodoCol != NULL && NodoFila == NULL && NodoCapa == NULL) {
		cout << "Caso5";
		NodoFila = CrearFila(y);
		NodoCapa = CrearCapa(z);
	}
	//6)Col si, Fila no, Capa si
	else if (NodoCol != NULL && NodoFila == NULL && NodoCapa != NULL) {
		cout << "Caso6";
		NodoFila = CrearFila(y);
	}
	//7)Col si, Fila si, Capa no
	else if (NodoCol != NULL && NodoFila != NULL && NodoCapa == NULL) {
		cout << "Caso7";
		NodoCapa = CrearCapa(z);
	}
	//8)Col si, Fila si, Capa si
	else if (NodoCol != NULL && NodoFila != NULL && NodoCapa != NULL) {
		cout << "Caso8";
	}
	Interseccionxy = InsertarCol(Interseccionxy, NodoFila);
	Interseccionxy = InsertarFila(Interseccionxy, NodoCol);

	Interseccionxz = InsertarCol(Interseccionxz, NodoCapa);
	Interseccionxz = InsertarCapa(Interseccionxz, NodoCol);

	Interseccionyz = InsertarFila(Interseccionyz, NodoCapa);
	Interseccionyz = InsertarCapa(Interseccionyz, NodoFila);

	nuevo = InsertarCol(nuevo, Interseccionyz);
	nuevo = InsertarFila(nuevo, Interseccionxz);
	nuevo = InsertarCapa(nuevo, Interseccionxy);
}






