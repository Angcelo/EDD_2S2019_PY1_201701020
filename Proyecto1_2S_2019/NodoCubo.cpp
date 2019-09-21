#include "NodoCubo.h"

NodoCubo::NodoCubo()
{
	filtros = new ListaFiltros();
}

NodoCubo::NodoCubo(string nombre)
{
	filtros = new ListaFiltros();
	this->nombre = nombre;
}


NodoCubo::~NodoCubo()
{
}