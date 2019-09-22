#include "Cubopx.h"

Cubopx::Cubopx()
{
	Raiz = new Nodopx(-1, -1, -1, "Root");
	tamaño = 0;
}

Nodopx* Cubopx::BuscarCol(int x)
{
	Nodopx* temp = Raiz;
	while (temp != NULL)
	{
		if (temp->x == x)
		{
			return temp;
		}
		temp = temp->sig;
	}
	return nullptr;
}

Nodopx* Cubopx::BuscarFila(int y)
{
	Nodopx* temp = Raiz;
	while (temp != NULL)
	{
		if (temp->y == y)
		{
			return temp;
		}
		temp = temp->arriba;
	}
	return nullptr;
}

Nodopx* Cubopx::BuscarCapa(int z)
{
	Nodopx* temp = Raiz;
	while (temp != NULL)
	{
		if (temp->z == z)
		{
			return temp;
		}
		temp = temp->sup;
	}
	return nullptr;
}

Nodopx* Cubopx::CrearCol(int x)
{
	Nodopx* cabezaCol = Raiz;
	Nodopx* columna = InsertarCol(new Nodopx(x, -1, -1, "Col"+to_string(x)), cabezaCol);
	return columna;
}

Nodopx* Cubopx::CrearFila(int y)
{
	Nodopx* cabezaFila = Raiz;
	Nodopx* fila = InsertarFila(new Nodopx(-1, y, -1, "Fila"+to_string(y)), cabezaFila);
	return fila;
}

Nodopx* Cubopx::CrearCapa(int z)
{
	Nodopx* cabezaCapa = Raiz;
	Nodopx* capa = InsertarCapa(new Nodopx(-1, -1, z, "Capa"+to_string(z)), cabezaCapa);
	return capa;
}

Nodopx* Cubopx::InsertarCol(Nodopx* nuevo, Nodopx* cabezaCol)
{
	Nodopx* temp = cabezaCol;
	bool bandera = false;
	while (true)
	{
		if (temp->x == nuevo->x) {
			temp->y = nuevo->y;
			temp->z = nuevo->z;
			temp->px = nuevo->px;
			return temp;
		}
		else if (temp->x > nuevo->x) {
			bandera = true;
			break;
		}
		if (temp->sig != NULL) {
			temp = temp->sig;
		}
		else {
			break;
		}
	}
	if (bandera) {
		nuevo->sig = temp;
		temp->ant->sig = nuevo;
		nuevo->ant = temp->ant;
		temp->ant = nuevo;
	}
	else {
		temp->sig = nuevo;
		nuevo->ant = temp;
	}
	return nuevo;
}

Nodopx* Cubopx::InsertarFila(Nodopx* nuevo, Nodopx* cabezaFila)
{
	Nodopx* temp = cabezaFila;
	bool bandera = false;
	while (true)
	{
		if (temp->y == nuevo->y) {
			temp->x = nuevo->x;
			temp->z = nuevo->z;
			temp->px = nuevo->px;
			return temp;
		}
		else if (temp->y > nuevo->y) {
			bandera = true;
			break;
		}
		if (temp->arriba != NULL) {
			temp = temp->arriba;
		}
		else {
			break;
		}
	}
	if (bandera) {
		nuevo->arriba = temp;
		temp->abajo->arriba = nuevo;
		nuevo->abajo = temp->abajo;
		temp->abajo = nuevo;
	}
	else {
		temp->arriba = nuevo;
		nuevo->abajo = temp;
	}
	return nuevo;
}

Nodopx* Cubopx::InsertarCapa(Nodopx* nuevo, Nodopx* cabezaCapa)
{
	Nodopx* temp = cabezaCapa;
	bool bandera = false;
	while (true)
	{
		if (temp->z == nuevo->z) {
			temp->x = nuevo->x;
			temp->y = nuevo->y;
			temp->px = nuevo->px;
			return temp;
		}
		else if (temp->z > nuevo->z) {
			bandera = true;
			break;
		}
		if (temp->sup != NULL) {
			temp = temp->sup;
		}
		else {
			break;
		}
	}
	if (bandera) {
		nuevo->sup = temp;
		temp->inf->sup = nuevo;
		nuevo->inf = temp->inf;
		temp->inf = nuevo;
	}
	else {
		temp->sup = nuevo;
		nuevo->inf = temp;
	}
	return nuevo;
}

void Cubopx::insertar(int x, int y, int z, string px)
{
	Nodopx* nuevo = new Nodopx(x, y, z, px);
	Nodopx* NodoCol = BuscarCol(x);
	Nodopx* NodoFila = BuscarFila(y);
	Nodopx* NodoCapa = BuscarCapa(z);
	Nodopx* Interseccionxy = new Nodopx(x, y, -1, "Int-xy"+to_string(x)+to_string(y));
	Nodopx* Interseccionxz = new Nodopx(x, -1, z, "Int-xz" + to_string(x) + to_string(z));
	Nodopx* Interseccionyz = new Nodopx(-1, y, z, "Int-yz" + to_string(y) + to_string(z));
	//1)Col no, Fila no, Capa no
	if (NodoCol == NULL && NodoFila == NULL && NodoCapa == NULL) {
		cout << "Caso1";
		NodoCol = CrearCol(x);
		NodoFila = CrearFila(y);
		NodoCapa = CrearCapa(z);
	}
	//2)Col no, Fila no, Capa si
	else if (NodoCol == NULL && NodoFila == NULL && NodoCapa != NULL) {
		cout << "Caso2";
		NodoCol = CrearCol(x);
		NodoFila = CrearFila(y);
	}
	//3)Col no, Fila si, Capa no
	else if (NodoCol == NULL && NodoFila != NULL && NodoCapa == NULL) {
		cout << "Caso3";
		NodoCol = CrearCol(x);
		NodoCapa = CrearCapa(z);
	}
	//4)Col no, Fila si, Capa si
	else if (NodoCol == NULL && NodoFila != NULL && NodoCapa != NULL) {
		cout << "Caso4";
		NodoCol = CrearCol(x);
	}
	//5)Col si, Fila no, Capa no
	else if (NodoCol != NULL && NodoFila == NULL && NodoCapa == NULL) {
		cout << "Caso5";
		NodoFila = CrearFila(y);
		NodoCapa = CrearCapa(z);
	}
	//6)Col si, Fila no, Capa si
	else if (NodoCol != NULL && NodoFila == NULL && NodoCapa != NULL) {
		cout << "Caso6";
		NodoFila = CrearFila(y);
	}
	//7)Col si, Fila si, Capa no
	else if (NodoCol != NULL && NodoFila != NULL && NodoCapa == NULL) {
		cout << "Caso7";
		NodoCapa = CrearCapa(z);
	}
	//8)Col si, Fila si, Capa si
	else if (NodoCol != NULL && NodoFila != NULL && NodoCapa != NULL) {
		cout << "Caso8";
	}

	Interseccionxy = InsertarCol(Interseccionxy, NodoFila);
	Interseccionxy = InsertarFila(Interseccionxy, NodoCol);

	Interseccionxz = InsertarCol(Interseccionxz, NodoCapa);
	Interseccionxz = InsertarCapa(Interseccionxz, NodoCol);

	Interseccionyz = InsertarFila(Interseccionyz, NodoCapa);
	Interseccionyz = InsertarCapa(Interseccionyz, NodoFila);

	nuevo = InsertarCol(nuevo, Interseccionyz);
	nuevo = InsertarFila(nuevo, Interseccionxz);
	nuevo = InsertarCapa(nuevo, Interseccionxy);
	nuevo = InsertarColores(nuevo, nuevo->px);
	cout << nuevo->x << nuevo->y << nuevo->z<<"px: " << nuevo->px << " Insertado\n";
	tamaño++;
}

Nodopx* Cubopx::BuscarNodoxyz(int x, int y, int z)
{
	Nodopx* temp = Raiz;
	while (temp != NULL)
	{
		if (temp->x == x) {
			while (temp != NULL)
			{
				if (temp->y == y)
				{
					while (temp != NULL) {
						if (temp->z == z)
						{
							cout << "encontrado" << "\n";
							return temp;
						}
						temp = temp->sup;
					}
					break;
				}
				temp = temp->arriba;
			}
			break;
		}
		temp = temp->sig;
	}
	cout << "Nodo no encontrado" << "\n";
	return nullptr;
}

Nodopx* Cubopx::InsertarColores(Nodopx* nuevo, string pixel)
{
	int iteracion=0;
	if (strcmp(pixel.c_str(),"x")==0|| strcmp(pixel.c_str(), "X")==0)
	{
		nuevo->A = 0;
		cout << " Transparente \n";
		return nuevo;
	}
	size_t pos1 = 0;
	size_t pos2 = 0;
	while (pos2 != pixel.npos)
	{
		pos2 = pixel.find("-", pos1);
		if (pos2 != pixel.npos + 1)
		{
			if (pos2 >= pos1) {
				string px=(pixel.substr(pos1, pos2 - pos1));
				int pxi= atoi(px.c_str());
				pos1 = pos2 + 1;
				switch (iteracion)
				{
				case 0:
					nuevo->R = pxi;
					cout << "	Color Rojo " << nuevo->R;
					break;
				case 1:
					nuevo->G = pxi;
					cout << "	Color Verde " << nuevo->G;
					break;
				case 2:
					nuevo->B = pxi;
					cout << "	Color Azul " << nuevo->B << "\n";
				default:
					break;
				}
				iteracion++;
			}	
		}
	}
	return nuevo;
}

void Cubopx::dibujar_capa(int z, string nombre){
	int valor=-1;
	int valinicial=0;
	Nodopx* cabeza = BuscarNodoxyz(-1, -1, z);
	Nodopx* tempy = cabeza;
	ofstream file;
	string direccion = "C:/Imagenes/"+nombre+"Capa" + to_string(z);
	direccion = direccion + ".dot";
	file.open(direccion);
	file << "digraph html { \n";
	file<<"abc[shape = none, margin = 0, label = < \n";
	file << "<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\" CELLPADDING=\"4\"> \n";
	if (tempy!=NULL)
	{
		Nodopx* tempx = tempy;
		file << "<TH>\n";
		valinicial = tempx->sig->x;
		valor = valinicial;
		while (tempx != NULL)
		{
			file << "<TD>";
			file << tempx->px;
			file << "</TD>\n";
			tempx = tempx->sig;
			valor++;
		}
		file << "</TH>\n";
	}
	tempy = tempy->arriba;
	while(tempy != NULL)
	{
		int toca = valinicial;
		Nodopx* tempx = tempy;
		file << "<TR>\n";
		while (tempx!=NULL)
		{
			while (tempx->x >toca )
			{
				file << "<TD>";
				file << "</TD>\n";
				toca++;
			}
			file << "<TD>";
			file << tempx->px;
			file << "</TD>\n";
			tempx = tempx->sig;
			toca++;
		}
		while (toca<valor)
		{
			file << "<TD>";
			file << "</TD>\n";
			toca++;
		}
		file<< "</TR>";
		tempy = tempy->arriba;
	}
	file << "</TABLE>>];";
	file << "}";
	file.close();
	string dot = "dot -Tjpg C:/Imagenes/" + nombre + "Capa" + to_string(z) + ".dot -o C:/Imagenes/"+nombre+"imgcapa" + to_string(z) + ".jpg";
	system(dot.c_str());
	dot = "C:/Imagenes/" + nombre + "imgcapa" + to_string(z) + ".jpg";
	system(dot.c_str());


	string direccion2 = "C:/Imagenes/" + nombre + "Capa" + to_string(z);
	direccion2 = direccion2 + "-2.dot";
	file.open(direccion2);
	tempy = cabeza;
	if (tempy != NULL)
	{
		file << "digraph G { \n";
		while (tempy != NULL)
		{
			Nodopx* tempx = tempy;
			file << "{rank = same;";
			while (tempx != NULL) {
				string xgruop;
				if (tempx->x >= 0 && tempx->y >= 0 && tempx->z >= 0)
				{
					xgruop = to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z);
					xgruop = xgruop + "[group=\"g" + to_string(tempx->x+1) + "\" label=\"" + tempx->px + "\"];";
					file << xgruop;
				}
				else {
					if (tempx->x < 0 and tempx->y < 0) {
						xgruop = "Z" + to_string(tempx->z);
						xgruop = xgruop + "[group=\"g0\"" + " label=\"" + tempx->px + "\"];";
					}
					else if (tempx->x<0)
					{
						xgruop = "Y" + to_string(tempx->y);
						xgruop = xgruop + "[group=\"g0\"" + " label=\"" + tempx->px + "\"];";
					}else{
						xgruop = "X" + to_string(tempx->x);
						xgruop = xgruop + "[group=\"g" + to_string(tempx->x) + "\" label=\"" + tempx->px + "\"];";
					}
					file << xgruop;
				}
				tempx = tempx->sig;
			}
			file << "}\n";
			tempy = tempy->arriba;
		}
	}
	tempy = cabeza;
	while (tempy != NULL)
	{
		Nodopx* tempx = tempy;
		while (tempx != NULL) {
			if (tempx->x >= 0 && tempx->y >= 0 && tempx->z >= 0)
			{
				if (tempx->sig != NULL && tempx->sig->x >= 0 && tempx->sig->y >= 0 && tempx->sig->z >= 0)
				{
					string xgruop = to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z);
					xgruop = xgruop + "->";
					xgruop = xgruop + to_string(tempx->sig->x) + to_string(tempx->sig->y) + to_string(tempx->sig->z);
					xgruop = xgruop + ";\n";
					file << xgruop;
				}
				else if(tempx->sig!=NULL){
					if (tempx->sig->x < 0 and tempx->sig->y < 0) { 
						string xgruop = to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z);
						xgruop = xgruop + "->";
						xgruop = xgruop + "Z" + to_string(tempx->sig->z);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else if (tempx->sig->x < 0)
					{
						string xgruop = to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z);
						xgruop = xgruop + "->";
						xgruop = xgruop + "Y" + to_string(tempx->sig->y);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else {
						string xgruop = to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z);
						xgruop = xgruop + "->";
						xgruop = xgruop + "X" + to_string(tempx->sig->x);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
				}
				if (tempx->ant != NULL && tempx->ant->x >= 0 && tempx->ant->y >= 0 && tempx->ant->z >= 0)
				{
					string xgruop = to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z);
					xgruop = xgruop + "->";
					xgruop = xgruop + to_string(tempx->ant->x) + to_string(tempx->ant->y) + to_string(tempx->ant->z);
					xgruop = xgruop + ";\n";
					file << xgruop;
				}
				else if (tempx->ant != NULL) {
					if (tempx->ant->x < 0 and tempx->ant->y < 0) {
						string xgruop = to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z);
						xgruop = xgruop + "->";
						xgruop = xgruop + "Z" + to_string(tempx->ant->z);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else if (tempx->ant->x < 0)
					{
						string xgruop = to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z);
						xgruop = xgruop + "->";
						xgruop = xgruop + "Y" + to_string(tempx->ant->y);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else {
						string xgruop = to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z);
						xgruop = xgruop + "->";
						xgruop = xgruop + "X" + to_string(tempx->ant->x);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
				}
				if (tempx->arriba != NULL && tempx->arriba->x >= 0 && tempx->arriba->y >= 0 && tempx->arriba->z >= 0)
				{
					string xgruop = to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z);
					xgruop = xgruop + "->";
					xgruop = xgruop + to_string(tempx->arriba->x) + to_string(tempx->arriba->y) + to_string(tempx->arriba->z);
					xgruop = xgruop + ";\n";
					file << xgruop;
				}
				else if (tempx->arriba != NULL) {
					if (tempx->arriba->x < 0 and tempx->arriba->y < 0) {
						string xgruop = to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z);
						xgruop = xgruop + "->";
						xgruop = xgruop + "Z" + to_string(tempx->arriba->z);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else if (tempx->arriba->x < 0)
					{
						string xgruop = to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z);
						xgruop = xgruop + "->";
						xgruop = xgruop + "Y" + to_string(tempx->arriba->y);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else {
						string xgruop = to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z);
						xgruop = xgruop + "->";
						xgruop = xgruop + "X" + to_string(tempx->arriba->x);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
				}
				if (tempx->abajo != NULL && tempx->abajo->x >= 0 && tempx->abajo->y >= 0 && tempx->abajo->z >= 0)
				{
					string xgruop = to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z);
					xgruop = xgruop + "->";
					xgruop = xgruop + to_string(tempx->abajo->x) + to_string(tempx->abajo->y) + to_string(tempx->abajo->z);
					xgruop = xgruop + ";\n";
					file << xgruop;
				}
				else if (tempx->abajo != NULL) {
					if (tempx->abajo->x < 0 and tempx->abajo->y < 0) {
						string xgruop = to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z);
						xgruop = xgruop + "->";
						xgruop = xgruop + "Z" + to_string(tempx->abajo->z);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else if (tempx->abajo->x < 0)
					{
						string xgruop = to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z);
						xgruop = xgruop + "->";
						xgruop = xgruop + "Y" + to_string(tempx->abajo->y);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else {
						string xgruop = to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z);
						xgruop = xgruop + "->";
						xgruop = xgruop + "X" + to_string(tempx->abajo->x);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
				}
			}
			else {
				if (tempx->x < 0 and tempx->y < 0) {
					if (tempx->sig != NULL && tempx->sig->x >= 0 && tempx->sig->y >= 0 && tempx->sig->z >= 0)
					{
						string xgruop = "Z" + to_string(tempx->z);
						xgruop = xgruop + "->";
						xgruop = xgruop + to_string(tempx->sig->x) + to_string(tempx->sig->y) + to_string(tempx->sig->z);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else if (tempx->sig != NULL) {
						if (tempx->sig->x < 0 and tempx->sig->y < 0) {
							string xgruop = "Z" + to_string(tempx->z);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Z" + to_string(tempx->sig->z);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else if (tempx->sig->x < 0)
						{
							string xgruop = "Z" + to_string(tempx->z);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Y" + to_string(tempx->sig->y);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else {
							string xgruop = "Z" + to_string(tempx->z);
							xgruop = xgruop + "->";
							xgruop = xgruop + "X" + to_string(tempx->sig->x);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
					}
					if (tempx->ant != NULL && tempx->ant->x >= 0 && tempx->ant->y >= 0 && tempx->ant->z >= 0)
					{
						string xgruop = "Z" + to_string(tempx->z);
						xgruop = xgruop + "->";
						xgruop = xgruop + to_string(tempx->ant->x) + to_string(tempx->ant->y) + to_string(tempx->ant->z);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else if (tempx->ant != NULL) {
						if (tempx->ant->x < 0 and tempx->ant->y < 0) {
							string xgruop = "Z" + to_string(tempx->z);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Z" + to_string(tempx->ant->z);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else if (tempx->ant->x < 0)
						{
							string xgruop = "Z" + to_string(tempx->z);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Y" + to_string(tempx->ant->y);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else {
							string xgruop = "Z" + to_string(tempx->z);
							xgruop = xgruop + "->";
							xgruop = xgruop + "X" + to_string(tempx->ant->x);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
					}
					if (tempx->arriba != NULL && tempx->arriba->x >= 0 && tempx->arriba->y >= 0 && tempx->arriba->z >= 0)
					{
						string xgruop = "Z" + to_string(tempx->z);
						xgruop = xgruop + "->";
						xgruop = xgruop + to_string(tempx->arriba->x) + to_string(tempx->arriba->y) + to_string(tempx->arriba->z);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else if (tempx->arriba != NULL) {
						if (tempx->arriba->x < 0 and tempx->arriba->y < 0) {
							string xgruop = "Z" + to_string(tempx->z);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Z" + to_string(tempx->arriba->z);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else if (tempx->arriba->x < 0)
						{
							string xgruop = "Z" + to_string(tempx->z);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Y" + to_string(tempx->arriba->y);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else {
							string xgruop = "Z" + to_string(tempx->z);
							xgruop = xgruop + "->";
							xgruop = xgruop + "X" + to_string(tempx->arriba->x);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
					}
					if (tempx->abajo != NULL && tempx->abajo->x >= 0 && tempx->abajo->y >= 0 && tempx->abajo->z >= 0)
					{
						string xgruop = "Z" + to_string(tempx->z);
						xgruop = xgruop + "->";
						xgruop = xgruop + to_string(tempx->abajo->x) + to_string(tempx->abajo->y) + to_string(tempx->abajo->z);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else if (tempx->abajo != NULL) {
						if (tempx->abajo->x < 0 and tempx->abajo->y < 0) {
							string xgruop = "Z" + to_string(tempx->z);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Z" + to_string(tempx->abajo->z);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else if (tempx->abajo->x < 0)
						{
							string xgruop = "Z" + to_string(tempx->z);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Y" + to_string(tempx->abajo->y);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else {
							string xgruop = "Z" + to_string(tempx->z);
							xgruop = xgruop + "->";
							xgruop = xgruop + "X" + to_string(tempx->abajo->x);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
					}
				}
				else if (tempx->x < 0)
				{
					if (tempx->sig != NULL && tempx->sig->x >= 0 && tempx->sig->y >= 0 && tempx->sig->z >= 0)
					{
						string xgruop = "Y" + to_string(tempx->y);
						xgruop = xgruop + "->";
						xgruop = xgruop + to_string(tempx->sig->x) + to_string(tempx->sig->y) + to_string(tempx->sig->z);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else if (tempx->sig != NULL) 
					{
						if (tempx->sig->x < 0 and tempx->sig->y < 0) 
						{
							string xgruop = "Y" + to_string(tempx->y);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Z" + to_string(tempx->sig->z);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else if (tempx->sig->x < 0)
						{
							string xgruop = "Y" + to_string(tempx->y);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Y" + to_string(tempx->sig->y);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else {
							string xgruop = "Y" + to_string(tempx->y);
							xgruop = xgruop + "->";
							xgruop = xgruop + "X" + to_string(tempx->sig->x);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
					}
					if (tempx->ant != NULL && tempx->ant->x >= 0 && tempx->ant->y >= 0 && tempx->ant->z >= 0)
					{
						string xgruop = "Y" + to_string(tempx->y);
						xgruop = xgruop + "->";
						xgruop = xgruop + to_string(tempx->ant->x) + to_string(tempx->ant->y) + to_string(tempx->ant->z);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else if (tempx->ant != NULL) {
						if (tempx->ant->x < 0 and tempx->ant->y < 0) {
							string xgruop = "Y" + to_string(tempx->y);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Z" + to_string(tempx->ant->z);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else if (tempx->ant->x < 0)
						{
							string xgruop = "Y" + to_string(tempx->y);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Y" + to_string(tempx->ant->y);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else {
							string xgruop = "Y" + to_string(tempx->y);
							xgruop = xgruop + "->";
							xgruop = xgruop + "X" + to_string(tempx->ant->x);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
					}
					if (tempx->arriba != NULL && tempx->arriba->x >= 0 && tempx->arriba->y >= 0 && tempx->arriba->z >= 0)
					{
						string xgruop = "Y" + to_string(tempx->y);
						xgruop = xgruop + "->";
						xgruop = xgruop + to_string(tempx->arriba->x) + to_string(tempx->arriba->y) + to_string(tempx->arriba->z);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else if (tempx->arriba != NULL) {
						if (tempx->arriba->x < 0 and tempx->arriba->y < 0) {
							string xgruop = "Y" + to_string(tempx->y);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Z" + to_string(tempx->arriba->z);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else if (tempx->arriba->x < 0)
						{
							string xgruop = "Y" + to_string(tempx->y);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Y" + to_string(tempx->arriba->y);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else {
							string xgruop = "Y" + to_string(tempx->y);
							xgruop = xgruop + "->";
							xgruop = xgruop + "X" + to_string(tempx->arriba->x);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
					}
					if (tempx->abajo != NULL && tempx->abajo->x >= 0 && tempx->abajo->y >= 0 && tempx->abajo->z >= 0)
					{
						string xgruop = "Y" + to_string(tempx->y);
						xgruop = xgruop + "->";
						xgruop = xgruop + to_string(tempx->abajo->x) + to_string(tempx->abajo->y) + to_string(tempx->abajo->z);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else if (tempx->abajo != NULL) {
						if (tempx->abajo->x < 0 and tempx->abajo->y < 0) {
							string xgruop = "Y" + to_string(tempx->y);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Z" + to_string(tempx->abajo->z);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else if (tempx->abajo->x < 0)
						{
							string xgruop = "Y" + to_string(tempx->y);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Y" + to_string(tempx->abajo->y);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else {
							string xgruop = "Y" + to_string(tempx->y);
							xgruop = xgruop + "->";
							xgruop = xgruop + "X" + to_string(tempx->abajo->x);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
					}
				}
				else {
					if (tempx->sig != NULL && tempx->sig->x >= 0 && tempx->sig->y >= 0 && tempx->sig->z >= 0)
					{
						string xgruop = "X" + to_string(tempx->x);
						xgruop = xgruop + "->";
						xgruop = xgruop + to_string(tempx->sig->x) + to_string(tempx->sig->y) + to_string(tempx->sig->z);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else if (tempx->sig != NULL) {
						if (tempx->sig->x < 0 and tempx->sig->y < 0) {
							string xgruop = "X" + to_string(tempx->x);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Z" + to_string(tempx->sig->z);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else if (tempx->sig->x < 0)
						{
							string xgruop = "X" + to_string(tempx->x);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Y" + to_string(tempx->sig->y);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else {
							string xgruop = "X" + to_string(tempx->x);
							xgruop = xgruop + "->";
							xgruop = xgruop + "X" + to_string(tempx->sig->x);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
					}
					if (tempx->ant != NULL && tempx->ant->x >= 0 && tempx->ant->y >= 0 && tempx->ant->z >= 0)
					{
						string xgruop = "X" + to_string(tempx->x);
						xgruop = xgruop + "->";
						xgruop = xgruop + to_string(tempx->ant->x) + to_string(tempx->ant->y) + to_string(tempx->ant->z);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else if (tempx->ant != NULL) {
						if (tempx->ant->x < 0 and tempx->ant->y < 0) {
							string xgruop = "X" + to_string(tempx->x);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Z" + to_string(tempx->ant->z);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else if (tempx->ant->x < 0)
						{
							string xgruop = "X" + to_string(tempx->x);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Y" + to_string(tempx->ant->y);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else {
							string xgruop = "X" + to_string(tempx->x);
							xgruop = xgruop + "->";
							xgruop = xgruop + "X" + to_string(tempx->ant->x);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
					}
					if (tempx->arriba != NULL && tempx->arriba->x >= 0 && tempx->arriba->y >= 0 && tempx->arriba->z >= 0)
					{
						string xgruop = "X" + to_string(tempx->x);
						xgruop = xgruop + "->";
						xgruop = xgruop + to_string(tempx->arriba->x) + to_string(tempx->arriba->y) + to_string(tempx->arriba->z);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else if (tempx->arriba != NULL) {
						if (tempx->arriba->x < 0 and tempx->arriba->y < 0) {
							string xgruop = "X" + to_string(tempx->x);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Z" + to_string(tempx->arriba->z);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else if (tempx->arriba->x < 0)
						{
							string xgruop = "X" + to_string(tempx->x);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Y" + to_string(tempx->arriba->y);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else {
							string xgruop = "X" + to_string(tempx->x);
							xgruop = xgruop + "->";
							xgruop = xgruop + "X" + to_string(tempx->arriba->x);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
					}
					if (tempx->abajo != NULL && tempx->abajo->x >= 0 && tempx->abajo->y >= 0 && tempx->abajo->z >= 0)
					{
						string xgruop = "X" + to_string(tempx->x);
						xgruop = xgruop + "->";
						xgruop = xgruop + to_string(tempx->abajo->x) + to_string(tempx->abajo->y) + to_string(tempx->abajo->z);
						xgruop = xgruop + ";\n";
						file << xgruop;
					}
					else if (tempx->abajo != NULL) {
						if (tempx->abajo->x < 0 and tempx->abajo->y < 0) {
							string xgruop = "X" + to_string(tempx->x);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Z" + to_string(tempx->abajo->z);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else if (tempx->abajo->x < 0)
						{
							string xgruop = "X" + to_string(tempx->x);
							xgruop = xgruop + "->";
							xgruop = xgruop + "Y" + to_string(tempx->abajo->y);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
						else {
							string xgruop = "X" + to_string(tempx->x);
							xgruop = xgruop + "->";
							xgruop = xgruop + "X" + to_string(tempx->abajo->x);
							xgruop = xgruop + ";\n";
							file << xgruop;
						}
					}
				}
			}
			tempx = tempx->sig;
		}
		tempy = tempy->arriba;
	}
	file << "}";
	file.close();
	string dot2 = "dot -Tjpg C:/Imagenes/"+nombre+"Capa" + to_string(z) + "-2.dot -o C:/Imagenes/" + nombre + "imgcapa" + to_string(z) + "-2.jpg";
	system(dot2.c_str());
	dot2 = "C:/Imagenes/" + nombre + "imgcapa" + to_string(z) + "-2.jpg";
	system(dot2.c_str());
}

void Cubopx::HTMLCapa(string nombre)
{
	Nodopx* tempz = BuscarNodoxyz(0, 0, 0);
	Nodopx* tempy = tempz;
	int yi = 0;
	int xi = 0;
	int yp = 0;
	int xp = 0;
	ofstream file;
	string direccion = "C:/Imagenes/Export/" + nombre;
	direccion = direccion + ".html";
	file.open(direccion);
	file << "<!DOCTYPE html>\n";
	file << "<html>\n";
	file << "<head>\n";
	file << "<link rel = \"stylesheet\" href = \"" + nombre + ".css\">\n";
	file << "</head>\n";
	file << "<body>\n";
	while (tempy!=NULL)
	{
		if (strcmp(tempy->px.c_str(), "image_width") == 0)
		{
			xi = atoi(tempy->sig->px.c_str());
		}
		else if(strcmp(tempy->px.c_str(),"image_height")==0)
		{
			yi= atoi(tempy->sig->px.c_str());
		}
		else if(strcmp(tempy->px.c_str(), "pixel_width") == 0)
		{
			xp= atoi(tempy->sig->px.c_str());
		}
		else if(strcmp(tempy->px.c_str(), "pixel_height") == 0)
		{
			yp= atoi(tempy->sig->px.c_str());
		}
		tempy = tempy->arriba;
	}
	cout << xi << "x" << yi << "=" << xi * yi;
	cout << "\n" << "px en x: " << xp << "px en y:" << yp;
	file << "<div class = \"canvas\">\n";
	for (int i = 0; i < xi*yi; i++)
	{
		file << "<div class=\"pixel\"></div>\n";
	}
	file << "</div>";
	file << "</body>\n";
	file << "</html>\n";
	file.close();

	direccion = "C:/Imagenes/Export/" + nombre;
	direccion = direccion + ".css";
	file.open(direccion);
	file << "body{ \n"
		"background: #333333; \n"      
		"height: 100vh; \n"            
		"display: flex; \n"            
		"justify - content: center; \n"  
		"align - items: center; \n"     
		"}\n";
	file << ".canvas{\n"
		"width: "+to_string(xp*xi)+"px;\n"
		"height: "+to_string(yp*yi)+"px;\n"
		"}\n";
	file << ".pixel{\n"
		"width: "+to_string(xp)+"px;\n"    /* Width of each pixel */
		"height: "+to_string(yp)+"px;\n"   /* Height of each pixel */
		"float: left;\n"    /* Everytime it fills the canvas div it will begin a new line */
  /*box-shadow: 0px 0px 1px #fff;*/  /* Leave commented, showing the pixel boxes */
		"}\n";
	tempz = BuscarNodoxyz(-1, -1, 1);
	int valory = 0;
	int valorR = 0;
	while (tempz!=NULL)
	{
		Nodopx* tempy = tempz;
		tempy = tempy->arriba;
		while (tempy!=NULL)
		{
			valory = xi * tempy->y;
			Nodopx* tempx = tempy;
			tempx = tempx->sig;
			while (tempx!=NULL)
			{
				valorR = valory + tempx->x;
				file << ".pixel:nth-child(" + to_string(valorR) + ")"
					"{"
					"background: rgb("+to_string(tempx->R)+","+ to_string(tempx->G)+","+ to_string(tempx->B)+");"
					"}\n";
				tempx = tempx->sig;
			}
			tempy = tempy->arriba;
		}
		tempz = tempz->sup;
	}
	file.close();
	direccion = "C:/Imagenes/Export/" + nombre;
	direccion = direccion + ".html";
	system(direccion.c_str());
}

void Cubopx::LinealizacionFila(int z, string nombre,int tipo)
{
	ofstream file;
	string direccion2 = "C:/Imagenes/" + nombre+to_string(tipo) + "Capa" + to_string(z);
	direccion2 = direccion2 + ".dot";
	file.open(direccion2);
	file << "digraph G { \n"
		"rankdir=LR;\n"
		"node[shape = record, style = filled, fillcolor = gray95];\n";
	Nodopx* tempz = BuscarNodoxyz(-1, -1, z);
	Nodopx* tempy = tempz;
	tempy = tempy->arriba;
	while (tempy!=NULL)
	{
		Nodopx* tempx=tempy;
		tempx = tempx->sig;
		while (tempx!=NULL)
		{
			file << to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z) +
				"[label=\"{x:" + to_string(tempx->x) + "|y:" + to_string(tempx->y) + "|z:" + to_string(tempx->z) + "|px:" + tempx->px + "}\"]\n";
			tempx = tempx->sig;
		}
		tempy = tempy->arriba;
	}
	tempy = tempz;
	tempy = tempy->arriba;
	while (tempy != NULL)
	{
		Nodopx* tempx = tempy;
		tempx = tempx->sig;
		while (tempx != NULL)
		{
			if (tempx->sig==NULL && tempy->arriba==NULL)
			{
				file << to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z);
			}
			else
			{
				file << to_string(tempx->x) + to_string(tempx->y) + to_string(tempx->z) + "->";
			}
			tempx = tempx->sig;
		}
		tempy = tempy->arriba;
	}
	file << "}";
	file.close();
	string dot= "dot -Tjpg C:/Imagenes/" + nombre + to_string(tipo) + "Capa" + to_string(z)+".dot -o C:/Imagenes/img"+ nombre + to_string(tipo) + "Capa" + to_string(z)+".jpg";
	system(dot.c_str());
	dot = "C:/Imagenes/img" + nombre + to_string(tipo) + "Capa" + to_string(z) + ".jpg";
	system(dot.c_str());
}

void Cubopx::LinealizacionColumna(int z, string nombre, int tipo)
{
	ofstream file;
	string direccion2 = "C:/Imagenes/" + nombre + to_string(tipo) + "Capa" + to_string(z);
	direccion2 = direccion2 + ".dot";
	file.open(direccion2);
	file << "digraph G { \n"
		"rankdir=LR;\n"
		"node[shape = record, style = filled, fillcolor = gray95];\n";
	Nodopx* tempz = BuscarNodoxyz(-1, -1, z);
	Nodopx* tempx = tempz;
	tempx = tempx->sig;
	while (tempx != NULL)
	{
		Nodopx* tempy = tempx;
		tempy = tempy->arriba;
		while (tempy != NULL)
		{
			file << to_string(tempy->x) + to_string(tempy->y) + to_string(tempy->z) +
				"[label=\"{x:" + to_string(tempy->x) + "|y:" + to_string(tempy->y) + "|z:" + to_string(tempy->z) + "|px:" + tempy->px + "}\"]\n";
			tempy = tempy->arriba;
		}
		tempx = tempx->sig;
	}
	tempx = tempz;
	tempx = tempx->sig;
	while (tempx != NULL)
	{
		Nodopx* tempy = tempx;
		tempy = tempy->arriba;
		while (tempy != NULL)
		{
			if (tempy->arriba==NULL and tempx->sig==NULL)
			{
				file << to_string(tempy->x) + to_string(tempy->y) + to_string(tempy->z);
			}
			else 
			{
				file << to_string(tempy->x) + to_string(tempy->y) + to_string(tempy->z) + "->";
			}
			tempy = tempy->arriba;
		}
		tempx = tempx->sig;
	}
	file << "}";
	file.close();
	string dot = "dot -Tjpg C:/Imagenes/" + nombre + to_string(tipo) + "Capa" + to_string(z) + ".dot -o C:/Imagenes/img" + nombre + to_string(tipo) + "Capa" + to_string(z) + ".jpg";
	system(dot.c_str());
	dot = "C:/Imagenes/img" + nombre + to_string(tipo) + "Capa" + to_string(z) + ".jpg";
	system(dot.c_str());
}


