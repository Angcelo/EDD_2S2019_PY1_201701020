#pragma once
#ifndef ArbolImagen_H
#define ArbolImagen_H
#include <iostream>
#include <string>
#include <fstream>
#include <dirent.h>
#include <Windows.h>
#include "NodoCubo.h"	
using namespace std;;
class ArbolImagen
{
public:
	NodoCubo *Padre;
	ArbolImagen();
	~ArbolImagen();
	void Insertar(string);
	void insertarhoja(NodoCubo*, NodoCubo*);
	int MostrarInorder(NodoCubo *,int);
	void CrearGrafico();
	string AgregarNodoGrafico(string ,NodoCubo *);
	int valorar(char letra);
	void InsertarImagen(char url[]);
};
#endif // !ArbolImagen_H

