#pragma once
#ifndef Cubopx_H
#define Cubopx_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Nodopx.h"
class Cubopx
{
public:

	Nodopx* Raiz;
	int tamaño;
	Cubopx();


	Nodopx* BuscarCol(int);
	Nodopx* BuscarFila(int);
	Nodopx* BuscarCapa(int);

	Nodopx* CrearCol(int);
	Nodopx* CrearFila(int);
	Nodopx* CrearCapa(int);

	Nodopx* InsertarCol(Nodopx*, Nodopx*);
	Nodopx* InsertarFila(Nodopx*, Nodopx*);
	Nodopx* InsertarCapa(Nodopx*, Nodopx*);

	void insertar(int, int, int, string);

	Nodopx* BuscarNodoxyz(int, int, int);

	Nodopx* InsertarColores(Nodopx* nuevo, string pixel);
	
	void dibujar_capa(int, string);

	void HTMLCapa(string);
};
#endif // !Cubopx_h