#pragma once
#pragma once
#ifndef NodoCuboLista_H
#define NodoCuboLista_H
#include <iostream>
#include <string>
#include "Cubopx.h"
#include <vector>
class NodoCuboLista
{
public:
	Cubopx* imagen;
	vector<vector<string>> capa;
	string nombre;
	NodoCuboLista* sig=NULL;
	NodoCuboLista* ant=NULL;

	NodoCuboLista();
	NodoCuboLista(string,vector<vector<string>>,Cubopx*);
	~NodoCuboLista();
};
#endif //NodoCuboLista_H

