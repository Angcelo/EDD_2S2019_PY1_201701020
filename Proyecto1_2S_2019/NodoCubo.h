#pragma once
#ifndef NodoCubo_H
#define NodoCubo_H
#include <iostream>
#include <string>
#include <cstring>
#include "Cubopx.h"	
class NodoCubo
{
public:
	Cubopx *imagen=new Cubopx();
	string nombre;
	NodoCubo* izq = NULL;
	NodoCubo* der = NULL;
	NodoCubo();
	NodoCubo(string);
	~NodoCubo();
};

#endif // !NodoCubo_H