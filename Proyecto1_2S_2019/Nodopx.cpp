#include "Nodopx.h"


Nodopx::Nodopx()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->R = 0;
	this->G = 0;
	this->B = 0;
	this->A = 1;
}

Nodopx::Nodopx(int x, int y, int z)
{
	this->R = 0;
	this->G = 0;
	this->B = 0;
	this->A = 1;
	this->x = x;
	this->y = y;
	this->z = z;
}

Nodopx::Nodopx(int x, int y, int z, string px)
{
	this->R = 0;
	this->G = 0;
	this->B = 0;
	this->A = 1;
	this->x = x;
	this->y = y;
	this->z = z;
	this->px = px;
}


Nodopx::~Nodopx()
{
}
