#pragma once
#ifndef NodoCubo_H
#define NodoCubo_H
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "Cubopx.h"	
#include "ListaFiltros.h"
class NodoCubo
{
public:
	Cubopx *imagen=new Cubopx();
	ListaFiltros* filtros;
	vector<vector<string>> capas;
	string nombre;
	int posicion = 0;
	NodoCubo* izq = NULL;
	NodoCubo* der = NULL;
	NodoCubo();
	NodoCubo(string);
	~NodoCubo();
};

#endif // !NodoCubo_H