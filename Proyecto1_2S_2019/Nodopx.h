#pragma once
#ifndef Nodopx_H
#define Nodopx_H
#include <iostream>
#include <string>
using namespace std;
class Nodopx
{
public:
	Nodopx();
	Nodopx(int, int, int);
	Nodopx(int, int, int, string);
	~Nodopx();
	int x, y, z;
	string px;
	int R, G, B, A;
	Nodopx* sig = NULL;
	Nodopx* ant = NULL;
	Nodopx* arriba = NULL;
	Nodopx* abajo = NULL;
	Nodopx* inf = NULL;
	Nodopx* sup = NULL;
};

#endif // !Nodopx