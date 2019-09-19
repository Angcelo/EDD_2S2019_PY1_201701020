#pragma once
#ifndef ArbolImagen_H
#define ArbolImagen_H
#include <iostream>
#include <string>
#include "NodoCubo.h"	
class ArbolImagen
{
public:
	NodoCubo *Padre;
	ArbolImagen();
	~ArbolImagen();
	void Insertar(string);
	void insertarhoja(NodoCubo*, NodoCubo*);
	void MostrarInorder(NodoCubo *);
	int valorar(char letra);
};
#endif // !ArbolImagen_H

