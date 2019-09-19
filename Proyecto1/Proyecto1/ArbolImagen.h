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
};
#endif // !ArbolImagen_H

