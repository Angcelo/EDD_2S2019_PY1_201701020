#pragma once
#ifndef NodoCubo_H
#define NodoCubo_H
#include <iostream>
#include <string>
#include "CuboDisperso.h"	
class NodoCubo
{
public:
	CuboDisperso imagen;
	string nombre;
	NodoCubo *izq = NULL;
	NodoCubo *der = NULL;
	NodoCubo();
	NodoCubo(string);
	~NodoCubo();
};

#endif // !NodoCubo_H
