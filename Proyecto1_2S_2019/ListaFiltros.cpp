#include "ListaFiltros.h"

ListaFiltros::ListaFiltros() {
	inicio = NULL;
}



void ListaFiltros::Mostrar()
{
	int iteracion = 0;
	NodoCuboLista* temp = inicio;
	while (temp!=NULL)
	{
		cout << iteracion << " " << temp->nombre<<"\n";
		iteracion++;
		temp = temp->sig;
	}
}

NodoCuboLista* ListaFiltros::Seleccion(int a)
{
	int iteracion = 0;
	NodoCuboLista* temp = inicio;
	while (temp != NULL)
	{
		if (iteracion==a)
		{
			cout << "Modificacion correcta";
			return temp;
		}
		iteracion++;
		temp = temp->sig;
	}
	cout << "Modificacion no encontrada";
	return nullptr;
}

void ListaFiltros::insertar(Cubopx* nuevo, vector<vector<string>> capas, string nombre)
{
	NodoCuboLista *nuevo2 = new NodoCuboLista(nombre, capas, nuevo);
	if (inicio==NULL)
	{
		inicio = nuevo2;
	}
	else
	{
		NodoCuboLista* temp = inicio;
		while (temp->sig!=NULL)
		{
			temp = temp->sig;
		}
		temp->sig = nuevo2;
		nuevo2->ant = temp;
	}
}

Cubopx* ListaFiltros::copiar(Cubopx* nuevo, vector<vector<string>> capas, string nombre)
{
	Cubopx* NuevoL = new Cubopx();
	Nodopx* tempz = nuevo->Raiz;
	tempz = tempz->sup;
	Nodopx* configy = tempz;
	configy = configy->arriba;
	while (configy != NULL)
	{
		Nodopx* configx = configy;
		configx->sig;
		while (configx != NULL)
		{
			NuevoL->insertar(configx->x, configx->y, configx->z, configx->px);
			configx = configx->sig;
		}
		configy = configy->arriba;
	}
	tempz = tempz->sup;
	while (tempz != NULL)
	{
		Nodopx* tempy = tempz;
		tempy = tempy->arriba;
		while (tempy != NULL)
		{
			Nodopx* tempx = tempy;
			tempx = tempx->sig;
			while (tempx != NULL)
			{
				string px;
				int R = tempx->R;
				int G = tempx->G;
				int B = tempx->B;
				px = to_string(R) + "-" + to_string(G) + "-" + to_string(B);
				NuevoL->insertar(tempx->x, tempx->y, tempx->z, px);
				tempx = tempx->sig;
			}
			tempy = tempy->arriba;
		}
		tempz = tempz->sup;
	}
	insertar(NuevoL, capas, nombre + "_original");
	return NuevoL;
}

Cubopx* ListaFiltros::Negativo(Cubopx* nuevo, vector<vector<string>> capas, string nombre)
{
	Cubopx* NuevoL = new Cubopx();
	Nodopx* tempz = nuevo->Raiz;
	tempz = tempz->sup;
	Nodopx* configy = tempz;
	configy = configy->arriba;
	while (configy!=NULL)
	{
		Nodopx* configx = configy;
		configx->sig;
		while (configx!=NULL)
		{
			NuevoL->insertar(configx->x, configx->y, configx->z, configx->px);
			configx = configx->sig;
		}
		configy = configy->arriba;
	}
	tempz = tempz->sup;
	while (tempz != NULL)
	{
		Nodopx* tempy = tempz;
		tempy = tempy->arriba;
		while (tempy != NULL)
		{
			Nodopx* tempx = tempy;
			tempx = tempx->sig;
			while (tempx != NULL)
			{
				string px;
				int R = 255 - tempx->R;
				int G = 255 - tempx->G;
				int B = 255 - tempx->B;
				int A = tempx->A;
				if (A==1)
				{
					px = to_string(R) + "-" + to_string(G) + "-" + to_string(B);	
				}
				else
				{
					px = "x";
				}
				NuevoL->insertar(tempx->x, tempx->y, tempx->z, px);
				tempx = tempx->sig;
			}
			tempy = tempy->arriba;
		}
		tempz = tempz->sup;
	}
	insertar(NuevoL, capas, nombre + "_negativo");
	return NuevoL;
}

Cubopx* ListaFiltros::Grises(Cubopx* nuevo, vector<vector<string>> capas, string nombre)
{
	Cubopx* NuevoL = new Cubopx();
	Nodopx* tempz = nuevo->Raiz;
	tempz = tempz->sup;
	Nodopx* configy = tempz;
	configy = configy->arriba;
	while (configy != NULL)
	{
		Nodopx* configx = configy;
		configx->sig;
		while (configx != NULL)
		{
			NuevoL->insertar(configx->x, configx->y, configx->z, configx->px);
			configx = configx->sig;
		}
		configy = configy->arriba;
	}
	tempz = tempz->sup;
	while (tempz != NULL)
	{
		Nodopx* tempy = tempz;
		tempy = tempy->arriba;
		while (tempy != NULL)
		{
			Nodopx* tempx = tempy;
			tempx = tempx->sig;
			while (tempx != NULL)
			{
				string px;
				int val = 0;
				val = val + tempx->R;
				val = val + tempx->G;
				val = val + tempx->B;
				val = val / 3;
				int A = tempx->A;
				if (A == 1)
				{
					px = to_string(val) + "-" + to_string(val) + "-" + to_string(val);
				}
				else
				{
					px = "x";
				}
				NuevoL->insertar(tempx->x, tempx->y, tempx->z, px);
				tempx = tempx->sig;
			}
			tempy = tempy->arriba;
		}
		tempz = tempz->sup;
	}
	insertar(NuevoL, capas, nombre + "_gris");
	return NuevoL;
}

Cubopx* ListaFiltros::EspejoX(Cubopx* nuevo, vector<vector<string>> capas, string nombre, bool bandera) {
	Cubopx* NuevoL = new Cubopx();
	Nodopx* tempz = nuevo->Raiz;
	tempz = tempz->sup;
	Nodopx* configy = tempz;
	configy = configy->arriba;
	while (configy != NULL)
	{
		Nodopx* configx = configy;
		configx->sig;
		while (configx != NULL)
		{
			NuevoL->insertar(configx->x, configx->y, configx->z, configx->px);
			configx = configx->sig;
		}
		configy = configy->arriba;
	}
	tempz = tempz->sup;
	while (tempz != NULL)
	{
		Nodopx* tempy = tempz;
		tempy = tempy->arriba;
		while (tempy != NULL)
		{
			Nodopx* tempx = tempy;
			Nodopx* temp2x = tempy;
			tempx = tempx->sig;
			while (temp2x->sig!=NULL)
			{
				temp2x = temp2x->sig;
			}
			while (tempx != NULL && temp2x!=NULL)
			{
				int A = temp2x->A;
				string px;
				if (A == 1)
				{
					px = to_string(temp2x->R) + "-" + to_string(temp2x->G) + "-" + to_string(temp2x->B);
				}
				else
				{
					px = "x";
				}
				NuevoL->insertar(tempx->x, tempx->y, tempx->z, px);
				tempx = tempx->sig;
				temp2x = temp2x->ant;
			}
			tempy = tempy->arriba;
		}
		tempz = tempz->sup;
	}
	if (bandera)
	{
		cout << "insertado";
		insertar(NuevoL, capas, nombre + "_MirrorX");
	}
	return NuevoL;
}

Cubopx* ListaFiltros::EspejoY(Cubopx* nuevo, vector<vector<string>> capas, string nombre, bool bandera) {
	Cubopx* NuevoL = new Cubopx();
	Nodopx* tempz = nuevo->Raiz;
	tempz = tempz->sup;
	Nodopx* configy = tempz;
	configy = configy->arriba;
	while (configy != NULL)
	{
		Nodopx* configx = configy;
		configx->sig;
		while (configx != NULL)
		{
			NuevoL->insertar(configx->x, configx->y, configx->z, configx->px);
			configx = configx->sig;
		}
		configy = configy->arriba;
	}
	tempz = tempz->sup;
	while (tempz != NULL)
	{
		Nodopx* tempx = tempz;
		tempx = tempx->sig;
		while (tempx != NULL)
		{
			Nodopx* tempy = tempx;
			Nodopx* temp2y = tempx;
			tempy = tempy->arriba;
			while (temp2y->arriba != NULL)
			{
				temp2y = temp2y->arriba;
			}
			while (tempy != NULL && temp2y != NULL)
			{
				int A = temp2y->A;
				string px;
				if (A == 1)
				{
					px = to_string(temp2y->R) + "-" + to_string(temp2y->G) + "-" + to_string(temp2y->B);
				}
				else
				{
					px = "x";
				}
				NuevoL->insertar(tempy->x, tempy->y, tempy->z, px);
				tempy = tempy->arriba;
				temp2y = temp2y->abajo;
			}
			tempx = tempx->sig;
		}
		tempz = tempz->sup;
	}
	if (bandera)
	{
		insertar(NuevoL, capas, nombre + "_MirrorY");
	}
	return NuevoL;
}

Cubopx* ListaFiltros::EspejoXY(Cubopx* nuevo, vector<vector<string>> capas, string nombre)
{
	Cubopx* NuevoL = nuevo;
	NuevoL = EspejoX(nuevo, capas, nombre, false);
	NuevoL = EspejoY(NuevoL, capas, nombre, false);
	insertar(NuevoL, capas, nombre + "_MirrorXY");
	return NuevoL;
}

Cubopx* ListaFiltros::Modificarpx(Cubopx* nuevo, vector<vector<string>> capas, string nombre, int R, int G, int B,int x,int y,int z)
{
	Cubopx* NuevoL = copiar(nuevo, capas, nombre);
	Nodopx* temo = NuevoL->BuscarNodoxyz(x, y, z);
	if (temo==NULL)
	{
		string px = to_string(R) + "-" + to_string(G) + "-" + to_string(B);
		NuevoL->insertar(x, y, z, px);
	}
	else {
		temo->R = R;
		temo->G = G;
		temo->B = B;
	}
	insertar(NuevoL, capas, nombre + "_" + to_string(x) + to_string(y) + to_string(z));
	return NuevoL;
}
void ListaFiltros::Dibujar()
{
	ofstream file;
	file.open("C:/Imagenes/filtros.dot");
	file << "digraph G { \n";
	file << "rankdir=LR;\n";
	NodoCuboLista* temp = inicio;
	string valor = "";
	while (temp!=NULL)
	{
		if (temp->sig!=NULL)
		{
			file << temp->nombre;
			file << "->";
			file << temp->sig->nombre;
			file << ";\n";
		}
		if (temp->ant!=NULL)
		{
			file << temp->nombre;
			file << "->";
			file << temp->ant->nombre;
			file << ";\n";
		}
		if (temp->sig==NULL and temp->ant==NULL)
		{
			file << temp->nombre;
		}
		temp = temp->sig;
	}
	file << "}";
	file.close();
	system("dot -Tjpg C:/Imagenes/filtros.dot -o C:/Imagenes/imgfiltros.jpg");
	system("C:/Imagenes/imgfiltros.jpg");
}
