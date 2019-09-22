// Proyecto1_2S_2019.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>
#include "ArbolImagen.h"
#include "Cubopx.h"
#include "NodoCuboLista.h"

int main()
{
	ArbolImagen* aimg=new ArbolImagen();
	NodoCubo* seleccion=nullptr;
	NodoCuboLista* seleccion2 = nullptr;
	bool continuar = true;
	do
	{
		system("CLS");
		int a = 0;
		cout << "Insert Image --------- 1\n";
		cout << "Select Image --------- 2\n";
		cout << "Apply Filters -------- 3\n";
		cout << "Manual Editing ------- 4\n";
		cout << "Export Image --------- 5\n";
		cout << "Reports -------------- 6\n";
		cin >> a;
		switch (a)
		{
		case 1:
			char b[MAX_PATH];
			for (size_t i = 0; i < sizeof(b); i++)
			{
				b[i] = NULL;
			}
			system("CLS");
			cout << "Ingrese URL de imagen a ingresar\n";
			cin >> b;
			aimg->InsertarImagen(b);
			_getch();
			break;
		case 2:
			int c;
			system("CLS");
			aimg->MostrarInorder(aimg->Padre, 0);
			cin >> c;
			seleccion = aimg->Seleccionar(aimg->Padre, c);
			_getch();
			break;
		case 3:
			system("CLS");
			if (seleccion!=NULL)
			{
				int elegirmod;
				seleccion->filtros->Mostrar();
				cin >> elegirmod;
				seleccion2 = seleccion->filtros->Seleccion(elegirmod);
				_getch;
			}
			break;
		case 4:
			int edicion;
			cout << "Filtros------------1\n";
			cout << "Edicion Manual-----2\n";
			cin >> edicion;
			if (seleccion != NULL)
			{
				if (seleccion2 == NULL)
				{
					if (seleccion->filtros->ingresado == FALSE) {
						seleccion->filtros->copiar(seleccion->imagen, seleccion->capas, seleccion->nombre);
						seleccion2 = seleccion->filtros->inicio;
					}
					else {
						seleccion2 = seleccion->filtros->inicio;
					}
				}
				switch (edicion)
				{
				case 1:
					int e;
					system("CLS");
					cout << "NEGATIVE ---------- 1\n";
					cout << "GRAYSCALE---------- 2\n";
					cout << "MIRROR ------------ 3\n";
					cout << "COLLAGE ----------- 4\n";
					cout << "MOSAIC ------------ 5\n";
					cin >> e;
						switch (e)
						{
						case 1:
							seleccion2->imagen = seleccion->filtros->Negativo(seleccion2->imagen, seleccion2->capa, seleccion2->nombre);
							break;
						case 2:
							seleccion2->imagen = seleccion->filtros->Grises(seleccion2->imagen, seleccion2->capa, seleccion2->nombre);
							break;
						case 3:
							cout << "X mirror -----------1\n";
							cout << "Y mirror -----------2\n";
							cout << "Double mirror ----- 3\n";
							cin >> e;
							switch (e)
							{
							case 1:
								seleccion2->imagen = seleccion->filtros->EspejoX(seleccion2->imagen, seleccion2->capa, seleccion2->nombre, true);
								break;
							case 2:
								seleccion2->imagen = seleccion->filtros->EspejoY(seleccion2->imagen, seleccion2->capa, seleccion2->nombre, true);
								break;
							case 3:
								seleccion2->imagen = seleccion->filtros->EspejoXY(seleccion2->imagen, seleccion2->capa, seleccion2->nombre);
								break;
							default:
								break;
							}
							break;
						case 4:
							int no1, no2;
							cout << "Cantidad en X";
							cin >> no1;
							cout << "Cantidad en Y";
							cin >> no2;
						case 5:
							break;
						default:
							break;
						}
					break;
				case 2:
					int buscax, buscay, buscaz,R,G,B;
					cout << "Inserte direccion en x\n";
					cin >> buscax;
					cout << "Inserte direccion en y\n";
					cin >> buscay;
					cout << "Inserte direccion en z\n";
					cin >> buscaz;
					if (buscax<0 || buscay<0 || buscaz<1)
					{
						cout << "Nodo no modificable";
					}
					else
					{
						system("CLS");
						cout << "Ingrese colo Rojo";
						cin >> R;
						cout << "Ingrese colo Verde";				
						cin >> G;
						cout << "Ingrese colo Azul";
						cin >> B;
						if (buscax<0 || buscay<0 || buscaz<0 || buscax>255||buscay>255 || buscaz>255)
						{
							cout << "No numeros negativos ni mayores a 255";
						}
						else {
							seleccion2->imagen=seleccion->filtros->Modificarpx(seleccion2->imagen, seleccion->capas, seleccion->nombre, R, G, B, buscax, buscay, buscaz);
						}
					}
				default:
					break;
				}
			}
			break;
		case 5:
			if (seleccion!=NULL)
			{
				int html;
				cout << "Imagen Original------------1\n";
				cout << "Imagen Modificada----------2\n";
				cin >> html;
				switch (html)
				{
				case 1:
					if (seleccion != NULL)
					{
						seleccion->imagen->HTMLCapa(seleccion->nombre);
					}
					break;
				case 2:
					if (seleccion2!=NULL)
					{
						seleccion2->imagen->HTMLCapa(seleccion2->nombre);
					}
				default:
					break;
				}
				cout << "Imagen generada";
			}
			break;
		case 6:
			int d;
			d = 0;
			int report;
			cout << "Reporte Imagenes-----------------1\n";
			cout << "Reporte Imagen Seleccionada------2\n";
			cout << "Reporte Modificaciones-----------3\n";
			cin >> report;
			cout<<"\n";
			switch (report)
			{
			case 1:
				aimg->CrearGrafico();
				aimg->InicioGrafica(1);
				aimg->InicioGrafica(2);
				aimg->InicioGrafica(3);
				_getch();
				break;
			case 2:
				if (seleccion!=NULL)
				{
					aimg->mostrarCapa(seleccion);
					cout << "Seleccione capa a dibujar: ";
					cin >> d;
					seleccion->imagen->dibujar_capa(d, seleccion->nombre);
				}
				break;
			case 3:
				if(seleccion!=NULL){
					seleccion->filtros->Dibujar();
				}
				break;
			default:
				break;
			}
			if (seleccion != NULL)
			
			break;
		default:
			continuar = false;
			break;
		}
	} while (continuar);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
