#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;

class CuboDisperso
{
public:
	CuboDisperso();
	~CuboDisperso();


private:
	struct Nodo
	{
		string dato;
		Nodo *sig;
		Nodo *ant;
	};
	Nodo *Inicio;
	int tamaño;
};

