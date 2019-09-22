#include "ArbolImagen.h"

ArbolImagen::ArbolImagen()
{
	Padre = NULL;
}

ArbolImagen::~ArbolImagen()
{
}

NodoCubo* ArbolImagen::Insertar(string nombre)
{
	NodoCubo* nuevo = new NodoCubo(nombre);
	if (Padre == NULL)
	{
		Padre = nuevo;
	}
	else
	{
		NodoCubo* temp = Padre;
		if (valorar(nuevo->nombre[0]) <= valorar(temp->nombre[0]))
		{
			if (temp->izq == NULL)
			{
				temp->izq = nuevo;
			}
			else
			{
				temp = temp->izq;
				nuevo=insertarhoja(nuevo, temp);
			}
		}
		else
		{
			if (temp->der == NULL)
			{
				temp->der = nuevo;
			}
			else
			{
				temp = temp->der;
				nuevo=insertarhoja(nuevo, temp);
			}
		}
	}
	return nuevo;
}

NodoCubo* ArbolImagen::insertarhoja(NodoCubo* nuevo, NodoCubo* temp)
{
	if (valorar(nuevo->nombre[0]) <= valorar(temp->nombre[0]))
	{
		if (temp->izq == NULL)
		{
			temp->izq = nuevo;
		}
		else
		{
			temp = temp->izq;
			nuevo=insertarhoja(nuevo, temp);
		}
	}
	else
	{
		if (temp->der == NULL)
		{
			temp->der = nuevo;
		}
		else
		{
			temp = temp->der;
			nuevo=insertarhoja(nuevo, temp);
		}
	}
	return nuevo;
}

int ArbolImagen::MostrarInorder(NodoCubo* padre, int valor)
{
	if (padre->izq != NULL)
	{
		valor = MostrarInorder(padre->izq, valor);
	}
	padre->posicion = valor;
	cout << padre->posicion << ": " << padre->nombre << "\n";
	valor++;
	if (padre->der != NULL)
	{
		valor = MostrarInorder(padre->der, valor);
	}
	return valor;
}

void ArbolImagen::InicioGrafica(int seleccion) {
	ofstream file;
	file.open("C:/Imagenes/arbol"+to_string(seleccion)+".dot");
	file << "digraph G { \n"
		"rankdir=LR;\n";
	string valor = "";
	switch (seleccion)
	{
	case 1:
		file << GraficarInorder(Padre, valor);
		file << "NULL";
		break;
	case 2:
		file << GraficarPreorder(Padre, valor);
		file << "NULL";
		break;
	case 3:
		file << GraficarPostorder(Padre, valor);
		file << "NULL";
		break;
	default:
		break;
	}
	file << "}";
	file.close();
	string dot = "dot -Tjpg C:/Imagenes/arbol" + to_string(seleccion) + ".dot -o C:/Imagenes/imgarbol"+to_string(seleccion)+".jpg";
	system(dot.c_str());
	dot="C:/Imagenes/imgarbol" + to_string(seleccion) + ".jpg"; 
	system(dot.c_str());
}

string ArbolImagen::GraficarInorder(NodoCubo* padre, string valor)
{
	if (padre->izq != NULL)
	{
		valor = GraficarInorder(padre->izq, valor);
	}
	valor += padre->nombre+ "->";
	if (padre->der!=NULL)
	{
		valor = GraficarInorder(padre->der, valor);
	}
	return valor;
}

string ArbolImagen::GraficarPreorder(NodoCubo* padre, string valor)
{
	valor += padre->nombre + "->";
	if (padre->izq != NULL)
	{
		valor = GraficarPreorder(padre->izq, valor);
	}
	if (padre->der != NULL)
	{
		valor = GraficarPreorder(padre->der, valor);
	}
	return valor;
}

string ArbolImagen::GraficarPostorder(NodoCubo* padre, string valor)
{
	if (padre->izq != NULL)
	{
		valor = GraficarPostorder(padre->izq, valor);
	}
	if (padre->der != NULL)
	{
		valor = GraficarPostorder(padre->der, valor);
	}
	valor += padre->nombre + "->";
	return valor;
}

NodoCubo* ArbolImagen::Seleccionar(NodoCubo* padre,int ingreso)
{
	if (padre->posicion==ingreso)
	{
		cout << "imagen seleccionada: " << padre->nombre;
		return padre;
	}
	if (padre->izq!=NULL)
	{
		Seleccionar(padre->izq, ingreso);
	}
	if (padre->der!=NULL)
	{
		Seleccionar(padre->der, ingreso);
	}
	cout << "No existe imagen";
	return nullptr;
}

void ArbolImagen::CrearGrafico()
{
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	string direccionactual = string(buffer).substr(0, pos);
	ofstream file;
	file.open("C:/Imagenes/arbol.dot");
	file << "digraph G { \n"
		"size = \"5,5\""
		"node[shape = record, style = filled, fillcolor = gray95];";
	NodoCubo* temp = Padre;
	string valor = "";
	valor = AgregarLabel(valor, temp);
	valor = AgregarNodoGrafico(valor, temp);
	file << valor;
	file << "}";
	file.close();
	system("dot -Tjpg C:/Imagenes/arbol.dot -o C:/Imagenes/imgarbol.jpg");
	system("C:/Imagenes/imgarbol.jpg");
}

string ArbolImagen::AgregarNodoGrafico(string valor, NodoCubo* temp)
{
	if (temp->izq != NULL)
	{
		valor += temp->nombre + "->" + temp->izq->nombre + " \n";
		valor = AgregarNodoGrafico(valor, temp->izq);
	}
	if (temp->der != NULL)
	{
		valor += temp->nombre + "->" + temp->der->nombre + " \n";
		valor = AgregarNodoGrafico(valor, temp->der);
	}
	if (temp->izq==NULL && temp->der==NULL)
	{
		valor += temp->nombre+" \n";
	}
	return valor;
}

string ArbolImagen::AgregarLabel(string valor, NodoCubo* temp)
{
	valor += temp->nombre + "[label = \"{" + temp->nombre;
	Nodopx* buscar = temp->imagen->BuscarNodoxyz(0, 0, 0);
	while (buscar != NULL)
	{
		if (strcmp(buscar->px.c_str(), "image_width") == 0)
		{
			valor += "|Ancho Imagen: " + buscar->sig->px;
		}
		else if (strcmp(buscar->px.c_str(), "image_height") == 0)
		{
			valor += "|Alto Imagen: " + buscar->sig->px;
		}
		else if (strcmp(buscar->px.c_str(), "pixel_width") == 0)
		{
			valor += "|Ancho Pixel: " + buscar->sig->px;
		}
		else if (strcmp(buscar->px.c_str(), "pixel_height") == 0)
		{
			valor += "|Alto Pixel: " + buscar->sig->px;
		}
		buscar = buscar->arriba;
	}
	valor += "}\"]\n";
	if (temp->izq != NULL)
	{
		AgregarLabel(valor, temp->izq);
	}

	if (temp->der != NULL)
	{
		AgregarLabel(valor, temp->der);
	}
	return valor;
}



int ArbolImagen::valorar(char letra) {
	letra = tolower(letra);
	switch (letra)
	{
	case 'a':
		return 1;
	case 'b':
		return 2;
	case 'c':
		return 3;
	case 'd':
		return 4;
	case 'e':
		return 5;
	case 'f':
		return 6;
	case 'g':
		return 7;
	case 'h':
		return 8;
	case 'i':
		return 9;
	case 'j':
		return 10;
	case 'k':
		return 11;
	case 'l':
		return 12;
	case 'm':
		return 13;
	case 'n':
		return 14;
	case 'o':
		return 15;
	case 'p':
		return 16;
	case 'q':
		return 17;
	case 'r':
		return 18;
	case 's':
		return 19;
	case 't':
		return 20;
	case 'u':
		return 21;
	case 'v':
		return 22;
	case 'w':
		return 23;
	case 'x':
		return 24;
	case 'y':
		return 25;
	case 'z':
		return 26;
	default:
		return 27;
	}
	return 0;
}

void ArbolImagen::InsertarImagen(const char url[])
{
	vector<vector<string>> capa;
	if (DIR * dir = opendir(url))
	{
		while (dirent * ent = readdir(dir))
		{
			if (strcmp(ent->d_name, "inicial.csv") == 0)
			{
				string url1 = url;
				string name = ent->d_name;
				string urlname = url1 + "/inicial.csv";
				ifstream lectura;
				lectura.open(urlname);
				for (string linea; getline(lectura, linea);)
				{
					vector<string> temp;
					size_t pos1 = 0;
					size_t pos2 = 0;
					while (pos2!=linea.npos)
					{
						pos2 = linea.find(",", pos1);
						if (pos2!=linea.npos+1)
						{
							if (pos2 > pos1) {
								temp.push_back(linea.substr(pos1,pos2-pos1));
								pos1 = pos2 + 1;
							}
						}
					}
					temp.push_back(linea.substr(pos1, linea.length() - pos1));
					capa.push_back(temp);
				}
				break;
			}
		}
	}
	if (DIR * dir = opendir(url))
	{
		string::size_type inicio = string(url).find_last_of("\\/");
		string nombre = string(url).substr(inicio+1, sizeof(url));
		cout << "Nombre archivo: " << nombre << "\n";
		NodoCubo* seleccionactual = Insertar(nombre);
		seleccionactual->capas = capa;
		while (dirent * ent = readdir(dir))
		{
			cout << "_________________________________\n";
			cout << ent->d_name << "\n";
			cout << "---------------------------------\n";
			string url1 = url;
			string name = ent->d_name;
			for (size_t i = 0; i < capa.size(); i++)
			{
				char Comparar[128];
				for (size_t m = 0; m < 128; m++)
				{
					Comparar[m] = NULL;
				}
				for (size_t n = 0; n < capa[i][1].length(); n++)
				{
					Comparar[n] = capa[i][1][n];
				}
				if (strcmp(Comparar, ent->d_name) == 0) {
					string urlname = url1 + "/" + name;
					ifstream lectura;
					lectura.open(urlname);
					int x = 0; 
					int y = 0; 
					int z = stoi(capa[i][0]);
					for (string linea; getline(lectura, linea);)
					{
						size_t pos1 = 0;
						size_t pos2 = 0;
						while (pos2 != linea.npos)
						{
							pos2 = linea.find(",", pos1);
							if (pos2 != linea.npos+1)
							{
								string px=(linea.substr(pos1, pos2 - pos1));
								if (strcmp(px.c_str(),"x")==0)
								{

								}
								else {
									seleccionactual->imagen->insertar(x, y, z, px);
								}
								pos1 = pos2 + 1;
							}
							x++;
						}
						y++;
						x = 0;
					}
					break;
				}
			}
		}
	}
}

void ArbolImagen::mostrarCapa(NodoCubo* temporal)
{
	for (size_t i = 1; i < temporal->capas.size(); i++)
	{
		cout << "Capa: " <<temporal->capas[i][0]<<" Nombre: "<< temporal->capas[i][1] <<"\n";
	}
}
