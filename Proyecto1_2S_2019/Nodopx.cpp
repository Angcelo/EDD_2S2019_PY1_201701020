#include "Nodopx.h"


Nodopx::Nodopx()
{
	x = 0;
	y = 0;
	z = 0;
}

Nodopx::Nodopx(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Nodopx::Nodopx(int x, int y, int z, string px)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->px = px;
}


Nodopx::~Nodopx()
{
}
