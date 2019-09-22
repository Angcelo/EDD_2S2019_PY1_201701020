#pragma once
#include <iostream>
#include <string>
#include "NodoCuboLista.h"
using namespace std;
class ListaFiltros
{
public:
	NodoCuboLista* inicio;
	int tamaño;
	bool ingresado=false;
	ListaFiltros();

	void Mostrar();
	NodoCuboLista* Seleccion(int);
	void insertar(Cubopx* nuevo, vector<vector<string>> capas, string nombre);
	Cubopx* copiar(Cubopx* nuevo, vector<vector<string>> capas, string nombre);
	Cubopx* Negativo(Cubopx* nuevo, vector<vector<string>> capas, string nombre);
	Cubopx* Grises(Cubopx* nuevo, vector<vector<string>> capas, string nombre);
	Cubopx* EspejoX(Cubopx* nuevo, vector<vector<string>> capas, string nombre, bool bandera);
	Cubopx* EspejoY(Cubopx* nuevo, vector<vector<string>> capas, string nombre, bool bandera);
	Cubopx* EspejoXY(Cubopx* nuevo, vector<vector<string>> capas, string nombre);
	Cubopx* Modificarpx(Cubopx* nuevo, vector<vector<string>> capas, string nombre,int R,int G,int B,int x,int y,int z);
	void Dibujar();
};

