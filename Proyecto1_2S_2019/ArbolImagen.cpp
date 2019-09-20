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
	cout << valor << ": " << padre->nombre << "\n";
	valor++;
	if (padre->der != NULL)
	{
		valor = MostrarInorder(padre->der, valor);
	}
	return valor;
}

void ArbolImagen::CrearGrafico()
{
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	string direccionactual = string(buffer).substr(0, pos);
	ofstream file;
	file.open("C:/Imagenes/arbol.dot");
	file << "digraph G { \n";
	NodoCubo* temp = Padre;
	string valor = "";
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
				string urlname = url1 + "/" + name;
				ifstream lectura;
				lectura.open("C:/Imagenes/Ave/inicial.csv");
				for (string linea; getline(lectura, linea);)
				{
					vector<string> temp;
					size_t pos1 = 0;
					size_t pos2 = 0;
					while (pos2!=linea.npos)
					{
						pos2 = linea.find(",", pos1);
						if (pos2!=linea.npos)
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
		for (size_t i = 0; i < capa.size(); i++)
		{
			for (size_t j = 0; j < capa[i].size(); j++)
			{
				cout << capa[i][j]<<" ";
			}
			cout << "\n";
		}
	}
	if (DIR * dir = opendir(url))
	{
		string::size_type inicio = string(url).find_last_of("\\/");
		string nombre = string(url).substr(inicio+1, sizeof(url));
		cout << "Nombre archivo: " << nombre << "\n";
		NodoCubo* seleccionactual = Insertar(nombre);
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
				cout << Comparar<<" Compara ";
				cout << ent->d_name<<"\n";
				if (strcmp(Comparar, ent->d_name) == 0) {
					cout << Comparar << " en la capa" << capa[i][0]<<"\n";
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
							if (pos2 != linea.npos)
							{
								if (pos2 >= pos1) {
									string px=(linea.substr(pos1, pos2 - pos1));
									seleccionactual->imagen->insertar(x,y,z,px);
									pos1 = pos2 + 1;
								}
							}
							cout << "		" << x << "," << y << "," << z;
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