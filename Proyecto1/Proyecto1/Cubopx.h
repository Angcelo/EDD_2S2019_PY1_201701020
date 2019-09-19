#ifndef Cubopx_H
#define Cubopx_H
#include <iostream>
#include <string>
#include "Nodopx.h"

class Cubopx
{
private:
	Nodopx *Raiz;
	int tamaño;

public:
	Cubopx();
	~Cubopx();

	Nodopx *BuscarCol(int);
	Nodopx *BuscarFila(int);
	Nodopx *BuscarCapa(int);

	Nodopx *CrearCol(int);
	Nodopx *CrearFila(int);
	Nodopx *CrearCapa(int);

	Nodopx *InsertarCol(Nodopx *, Nodopx *);
	Nodopx *InsertarFila(Nodopx *, Nodopx *);
	Nodopx *InsertarCapa(Nodopx *, Nodopx *);

	void insertar(int, int, int, string);
};

#endif // !Cubopx_h

