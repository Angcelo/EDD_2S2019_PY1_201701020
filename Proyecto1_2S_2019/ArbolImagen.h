#pragma once
#ifndef ArbolImagen_H
#define ArbolImagen_H
#include <iostream>
#include <string>
#include <fstream>
#include <dirent.h>
#include <Windows.h>
#include <cstdlib>
#include <vector>
#include "NodoCubo.h"	
class ArbolImagen
{
public:
	NodoCubo* Padre;
	ArbolImagen();
	~ArbolImagen();
	NodoCubo* Insertar(string);
	NodoCubo* insertarhoja(NodoCubo*, NodoCubo*);
	int MostrarInorder(NodoCubo*, int);
	NodoCubo* Seleccionar(NodoCubo*, int );
	void CrearGrafico();
	string AgregarNodoGrafico(string, NodoCubo*);
	int valorar(char letra);
	void InsertarImagen(const char url[]);
	void mostrarCapa(NodoCubo*);
};
#endif // !ArbolImagen_H
