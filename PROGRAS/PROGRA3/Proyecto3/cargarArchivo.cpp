

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <math.h>
#include "cargarArchivo.h"
#include "RNRest.h"
#include "AAMenu.h"

using namespace std;

/*
class cargarArchivo { 
   public:
    cargarArchivo() {
	listaPais = new BinarioPais() ;
	listaCliente = new ArbolB();
	listaFila = new listaDFila();
	RestMasBuscados = new ArbolRN();
	MenuMasBuscados = new ArbolA();
	 }
    ~cargarArchivo();
    void Menu();
    void cargaInicial();
    void buscarMenuMasBuscado();

    void MostrarTodo();

    void SubMenu1();
	void SubMenu2();
	void SubMenu21();
	void SubMenu22();
	void SubMenu23();
	void SubMenu24();
	void SubMenu25();
	void SubMenu26();
	void SubMenu3();
	void SubMenu31();
	void SubMenu32();
	void SubMenu33();
	void SubMenu34();
	void SubMenu35();
	void SubMenu36();
	void SubMenu4();
	void SubMenu41();
    void SubMenu42();
    void SubMenu43();
    void SubMenu44();
    void SubMenu45();
    void SubMenu46();
	void SubMenu5();
	void SubMenu51();
    void SubMenu52();
    void SubMenu53();
    void SubMenu54();
    void SubMenu55();
    void SubMenu56();
	void SubMenu57();
	void SubMenu571(pnodoComp Prod);
	void SubMenu6();
	void SubMenu61();
    void SubMenu62();
    void SubMenu63();
    void SubMenu64();
    void SubMenu65();
    void SubMenu66();
    void SubMenu67();
    void SubMenu68();
	void SubMenu7();
	void SubMenu71();
	void SubMenu72();
	void SubMenu73();
	void SubMenu74();
	void SubMenu75();
	void SubMenu76();
	void SubMenu77();
	void SubMenu8();
	void SubMenu81(int cedula);
	void SubMenu82(int cedula);
	
//	private:
    BinarioPais *listaPais;
    ArbolB *listaCliente;
    listaDFila *listaFila;
	ArbolRN *RestMasBuscados;
	ArbolA *MenuMasBuscados;
	pnodoFila FacturaGrande = NULL;
	pnodoFila FacturaPequena = NULL;
 //   friend MainMenu();
  
};*/

   cargarArchivo::cargarArchivo() {
	listaPais = new BinarioPais() ;
	listaCliente = new ArbolB();
	listaAdmin = new ArbolB();
	listaFila = new listaDFila();
	RestMasBuscados = new RNRest();
	MenuMasBuscados = new AAMenu();
	listaPaisEliminado = new ArbolB();
	listaCiudadEliminada = new ArbolB();
	listaRestauranteEliminado = new ArbolB();
	listaMenuEliminado = new ArbolB();
	listaProductoEliminado = new ArbolB();

	 }

cargarArchivo::~cargarArchivo()
{
listaPais = NULL;
}


void cargarArchivo::cargaInicial(){
	BinarioPais *aux = listaPais;
//	ArbolB *auxClientes = listaCliente;
	ifstream archivo;

try{
	
	archivo.open("Archivos/Administradores.txt");
	cout << "\t .:CARGANDO ADMINISTRADORES:." << endl << endl;
	while (!archivo.eof()) {
		string cedula;
		string nombre;
		getline(archivo, cedula, ';');
		getline(archivo, nombre);
		int temp = stoi(cedula);
		if (!cedula.empty()) {
			listaAdmin->InsertarClave(temp, nombre, listaAdmin->raiz);
		}
	}
	archivo.close();
	cout << endl << "*********************************************************************************" << endl << endl;


	archivo.open("Archivos/Clientes.txt");
	cout<<"\t .:CARGANDO CLIENTES:."<<endl<<endl;
	while(!archivo.eof()){
		string cedula;
		string nombre;
		getline(archivo, cedula, ';');
		getline(archivo, nombre);
		int temp = stoi(cedula);
		if(!cedula.empty()){
			listaCliente->InsertarClave(temp,nombre,listaCliente->raiz);
		}
	}
	archivo.close();
	cout<<endl<<"*********************************************************************************"<<endl<<endl;

	archivo.open("Archivos/Paises.txt");
	cout<<"\t .:CARGANDO PAISES:."<<endl<<endl;
	while(!archivo.eof()){
		string codigo;
		string pais;
		getline(archivo,codigo, ';');
		getline(archivo, pais);
		if(!codigo.empty()){
			aux->InsertaNodoPais(stoi(codigo),pais);
		}	

	}
	archivo.close();
	cout<<endl<<"*********************************************************************************"<<endl<<endl;

	archivo.open("Archivos/Ciudades.txt");
	cout<<"\t .:CARGANDO CIUDADES:."<<endl<<endl;
	while(!archivo.eof()){
		string codpais;
		string codigo;
		string ciudad ;
		getline(archivo, codpais, ';');
		getline(archivo, codigo, ';');
		getline(archivo, ciudad);
		int temp = stoi(codpais);
		int temp2 = stoi(codigo);

   		NodoBinarioPais *q = aux->raiz;
    	while(q != NULL){
        if(temp < q->valor){
            q = q->Hizq;
        }
        if(temp > q->valor){
        	q = q->Hder;
        }
        else if(temp == q->valor){
        	q->ArbolCiudad.InsertarBalanceadoCiudad(q->ArbolCiudad.raiz, q->ArbolCiudad.Hh, temp2, ciudad);
			break;
			}
        }
        if(q == NULL){
        	cout <<"El pais: "<<temp<<" no se encuentra"<<endl;
    	}
}
	archivo.close();
	cout<<endl<<"*********************************************************************************"<<endl<<endl;			


 	archivo.open("Archivos/Restaurantes.txt");
 	cout<<"\t .:CARGANDO RESTAURANTES:."<<endl<<endl;
	while(!archivo.eof()){
		string codpais;
		string codCiudad;
		string numRest;
		string nombre;
		getline(archivo, codpais, ';');
		getline(archivo, codCiudad, ';');
		getline(archivo, numRest, ';');
		getline(archivo, nombre);
		NodoBinarioPais *q = aux->raiz;
		int temp = stoi(codpais);
		int temp2 = stoi(codCiudad);
		int temp3 = stoi(numRest);
		while(q != NULL){
        if(temp < q->valor){
            q = q->Hizq;
        }
        if(temp > q->valor){
        	q = q->Hder;
        }
        else if(temp == q->valor){
			NodoBinarioCiudad *b = q->ArbolCiudad.BuscarCiudad(q->ArbolCiudad.raiz,temp2); 
        	while(b != NULL){
        		if(temp2 < b->valor){
					b = b->Hizq;	
        		}
        		if(temp2 > b->valor){
        			b = b->Hder;
        		}
        		else if(temp2 == b->valor){
        		b->ArbolRest.insertar(temp3,nombre);
				break;
				}
        	}
        	if(b == NULL){
        		cout <<"Restaurante: "<<numRest<<":"<<nombre<<" no fue agregado"<<endl;
    		}
    		break;
			}
        }
        if(q == NULL){
        	cout <<"Restaurante: "<<numRest<<":"<<nombre<<" no fue agregado"<<endl;
    	}
}
	
	archivo.close();	
	cout<<endl<<"*********************************************************************************"<<endl<<endl;


 	archivo.open("Archivos/Menu.txt");
 	cout<<"\t .:CARGANDO MENUS:."<<endl<<endl;
 		while(!archivo.eof()){
		string codPais;
		string codCiudad;
		string codRest;
		string codMenu;
		string nombre;
		
		getline(archivo, codPais, ';');
		getline(archivo, codCiudad, ';');
		getline(archivo, codRest, ';');
		getline(archivo, codMenu, ';');
		getline(archivo, nombre);
		int temp = stoi(codPais);
		int temp2 = stoi(codCiudad);
		int temp3 = stoi(codRest);
		int temp4 = stoi(codMenu);
		NodoBinarioPais *q = aux->raiz;
		while(q != NULL){
        if(temp < q->valor){
            q = q->Hizq;
        }
        if(temp > q->valor){
        	q = q->Hder;
        }
        else if(temp == q->valor){
			NodoBinarioCiudad *b = q->ArbolCiudad.BuscarCiudad(q->ArbolCiudad.raiz,temp2); 
        	while(b != NULL){
        		if(temp2 < b->valor){
					b = b->Hizq;	
        		}
        		if(temp2 > b->valor){
        			b = b->Hder;
        		}
        		else if(temp2 == b->valor){
        		Nodo *c = b->ArbolRest.Busqueda(b->ArbolRest.Raiz, temp3);
        		if(c != NULL)
				c->listaMenu.insertar(temp4, nombre);
				break;
				}
        	}
        	if(b == NULL){
        		cout <<"Menu: "<<codMenu<<":"<<nombre<<" no fue agregado"<<endl;
    		}
    		break;
			}
        }
        if(q == NULL){
        	cout <<"Menu: "<<codMenu<<":"<<nombre<<" no fue agregado"<<endl;
    	}
 }
 	archivo.close();
	cout<<endl<<"*********************************************************************************"<<endl<<endl;

 	archivo.open("Archivos/Productos.txt");
 		cout<<"\t .:CARGANDO PRODUCTOS:."<<endl<<endl;
 		while(!archivo.eof()){
		string codPais;
		string codCiudad;
		string codRest;
		string codMenu;
		string codProd;
		string nombre;
		string kcal;
		string precio;
		string cantProd;
		 
		getline(archivo, codPais, ';');
		getline(archivo, codCiudad, ';');
		getline(archivo, codRest, ';');
		getline(archivo, codMenu, ';');
		getline(archivo, codProd, ';');
		getline(archivo, nombre, ';');
		getline(archivo, kcal, ';');
		getline(archivo, precio, ';');
		getline(archivo, cantProd);
		
		int temp = stoi(codPais);
		int temp2 = stoi(codCiudad);
		int temp3 = stoi(codRest);
		int temp4 = stoi(codMenu);
		int temp5 = stoi(codProd);
		int temp6 = stoi(kcal);
		int temp7 = stoi(precio);
		int temp8 = stoi(cantProd);
		
		NodoBinarioPais *q = aux->raiz;
		while(q != NULL){
        if(temp < q->valor){
            q = q->Hizq;
        }
        if(temp > q->valor){
        	q = q->Hder;
        }
        else if(temp == q->valor){
			NodoBinarioCiudad *b = q->ArbolCiudad.BuscarCiudad(q->ArbolCiudad.raiz,temp2); 
        	while(b != NULL){
        		if(temp2 < b->valor){
					b = b->Hizq;	
        		}
        		if(temp2 > b->valor){
        			b = b->Hder;
        		}
        		else if(temp2 == b->valor){
        		Nodo *c = b->ArbolRest.Busqueda(b->ArbolRest.Raiz, temp3);
        			if(c !=NULL){
        				NodoM *d = c->listaMenu.BusquedaM(temp4);
        					if(d != NULL)
        						d->listaProducto.InsertaNodoProducto( temp5,  nombre, temp6, temp7, temp8);
        					break;
					}
				break;
				}
        	}
        	if(b == NULL){
        		cout <<"Producto: "<<codProd<<":"<<nombre<<" no fue agregado"<<endl;
    		}
    		break;
			}
        }
        if(q == NULL){
        	cout <<"Producto: "<<codProd<<":"<<nombre<<" no fue agregado"<<endl;
    	}
	}
 	archivo.close();
	cout<<endl<<"*********************************************************************************"<<endl<<endl;
	

} catch(const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return ; // Salir del programa con c�digo de error
    }
}
/*
void cargarArchivo::buscarMenuMasBuscado() {
	int contTop = 0;
    string codPaisTop = "";
    string codCiudadTop = "";
    string codRestTop = "";
    int codMenuTop = 0;
    string MenuTop = "";

	pnodoPais aux = listaPais->primero;
		while(aux!=NULL){
				if(aux->listaCiudad->primero != NULL){
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
						if(aux2->listaRestaurante != NULL){
						pnodoRest aux3 = aux2->listaRestaurante->primero;
						cout<< aux3->rest;
						int largoRest = 5;
							while(largoRest > 0){
								pnodoMenu aux4 = aux2->listaRestaurante->primero->buscarMayor();
								if(aux4->counter >= contTop){
									contTop = aux4->counter;
									codPaisTop = aux->pais;
									codCiudadTop = aux2->ciudad;
								//	codRestTop = aux3->rest;
									codMenuTop = aux4->cod;
									MenuTop = aux4->nomMenu;
								//	aux3 = aux3->siguiente;
									cout<<"1";
								}
							//	aux3 = aux3->siguiente;
								largoRest--;
								cout<<"2";						
							}
					aux2= aux2->siguiente;
				//	cout << aux2->ciudad;
					cout<<"3";
				}
				}
			}
		aux=aux->siguiente;
		cout<<"4";
		}
    if (contTop == 0) {
        cout << "\n***AUN NO SE HA BUSCADO NINGUN MENU***" << endl << endl;
    }
    
    else {
        cout << "\nSe esta generando el archivo Reporte_Menu_Mas_Buscado.txt\n.\n.\n.\n" << endl;
        ofstream archivoSalida("Reporte_Menu_Mas_Buscado.txt");
        if (!archivoSalida.is_open()) {
            cerr << "No se pudo abrir el archivo." << endl;
        }
        else {
            archivoSalida << "REPORTE MENU MAS BUSCADO " << endl << endl << endl;
            archivoSalida << "Pais: "<<codPaisTop << "\nCiudad: " << codCiudadTop << "\nRestaurante: " << codRestTop << "\nMenu: " << codMenuTop<<":"<<MenuTop << endl;
            archivoSalida << "Menu buscado : " << contTop <<" veces." <<endl;
            cout << endl;
            archivoSalida.close();
            cout << "Reporte generado";
        }
    }
}


*/

void cargarArchivo::SubMenu1(){
		cout << endl << "----------------------------" << endl;
        cout << endl << "      1. Leer Archivos   " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Cargar Archivos"<<endl;
		cout << "2. Volver"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: ";		
		char opt;
		cin >> opt;
		
	switch(opt) {
		case '1':{
			cout<<"Cargando archivos... "<<endl<<endl;
			cargaInicial();
			cout<<"."<<endl;
			cout<<"."<<endl;
			cout<<"."<<endl;
			cout<<"Se cargo archivos y lista de clientes"<<endl;
			break;
		}
		case '2':{
			cout<<"Volviendo a Main Menu"<<endl;
			break;	
		}
	default:
		cout<<"!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
		SubMenu1();
	}
}


// Insertar 
void cargarArchivo::SubMenu2(){
		cout << endl << "----------------------------" << endl;
        cout << endl << "      2. Insertar   " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Pais"<<endl;
		cout << "2. Ciudad"<<endl;
		cout << "3. Restaurante"<<endl;
		cout << "4. Menu"<<endl;
		cout << "5. Producto"<<endl;
		cout << "6. Cliente"<<endl;
		cout << "7. Volver"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: ";		
		char opt;
		cin >> opt;
		
	switch(opt) {
		case '1':
			cout<<"2.1 Insertar Pais"<<endl;
			SubMenu21();
			break;
		case '2':
			cout<<"2.2 Insertar Ciudad"<<endl;
			SubMenu22();
			break;
		case '3':
			cout<<"2.3 Insertar Restaurante"<<endl;
			SubMenu23();
			break;	
		case '4':
			cout<<"2.4 Insertar Menu"<<endl;
			SubMenu24();
			break;
		case '5':
			cout<<"2.5 Insertar Producto"<<endl;
			SubMenu25();
			break;	
		case '6':
			cout<<"2.6 Insertar Cliente"<<endl;
			SubMenu26();
			break;
		case '7':
			cout<<"Volviendo a Main Menu"<<endl;
			break;	
	default:
		cout<<"!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
		SubMenu2();
	}
}

void cargarArchivo::SubMenu21(){
	string cod;
	string nombre;
	cout<< "Ingrese el codigo de pais: ";
	cin >> cod;
	cin.ignore();
	cout<< "\nIngrese el Nombre de pais: ";
	getline(cin,nombre);
	listaPais->raiz->InsertaBinarioPais(stoi(cod), nombre);
	
}

void cargarArchivo::SubMenu22(){
	string codPais;
	string codCiudad;
	string ciudad;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	cout<< "\nIngrese el codigo de ciudad: ";
	cin >> codCiudad;
	cin.ignore();
	cout<< "\nIngrese el Nombre de la ciudad: ";
	getline(cin,ciudad);
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	NodoBinarioPais *aux = listaPais->BuscarPais(listaPais->raiz,temp);
	if(aux != NULL){
		NodoBinarioCiudad *aux2 = aux->ArbolCiudad.raiz; 
		aux->ArbolCiudad.InsertarBalanceadoCiudad(aux->ArbolCiudad.raiz, aux->ArbolCiudad.Hh,temp2,ciudad);
	}else{
		cout<<"No se agrego la ciudad, valores incorrectos";
	}
}

void cargarArchivo::SubMenu23(){
	string codPais;
	string codCiudad;
	string codRest;
	string rest;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	cout<< "\nIngrese el codigo de ciudad: ";
	cin >> codCiudad;
	cout<< "\nIngrese el codigo de restaurante: ";
	cin >> codRest;
	cin.ignore();
	cout<< "\nIngrese el Nombre de restaurante: ";
	getline(cin,rest);
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	NodoBinarioPais *aux = listaPais->BuscarPais(listaPais->raiz,temp);
	if(aux != NULL){
		NodoBinarioCiudad *aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz,temp2); 
		if(aux2 != NULL){
		aux2->ArbolRest.insertar(temp3,rest);
		}else{
		cout<<"No se agrego el restaurante, valores incorrectos";
	}
	}else{
		cout<<"No se agrego el restaurante, valores incorrectos";
	}
}


void cargarArchivo::SubMenu24(){
	string codPais;
	string codCiudad;
	string codRest;
	string codMenu;
	string menu;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	cout<< "\nIngrese el codigo de ciudad: ";
	cin >> codCiudad;
	cout<< "\nIngrese el codigo de restaurante: ";
	cin >> codRest;
	cout<< "\nIngrese el codigo de menu: ";
	cin >> codMenu;
	cin.ignore();
	cout<< "\nIngrese el Nombre de menu: ";
	getline(cin,menu);
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);

	NodoBinarioPais *q = listaPais->BuscarPais(listaPais->raiz,temp);
	while(q != NULL){
        if(temp < q->valor){
            q = q->Hizq;
        }
        if(temp > q->valor){
        	q = q->Hder;
        }
        else if(temp == q->valor){
			NodoBinarioCiudad *b = q->ArbolCiudad.BuscarCiudad(q->ArbolCiudad.raiz,temp2); 
        	while(b != NULL){
        		if(temp2 < b->valor){
					b = b->Hizq;	
        		}
        		if(temp2 > b->valor){
        			b = b->Hder;
        		}
        		else if(temp2 == b->valor){
        			Nodo *c = b->ArbolRest.Busqueda(b->ArbolRest.Raiz, temp3);
        			if(c != NULL)
					c->listaMenu.insertar(temp4, menu);
				break;
				}
        	}
        	if(b == NULL){
        		cout <<"Menu: "<<codMenu<<":"<<menu<<" no fue agregado"<<endl;
    		}
    		break;
			}
        }
        if(q == NULL){
        	cout <<"Menu: "<<codMenu<<":"<<menu<<" no fue agregado"<<endl;
    	}
}				


void cargarArchivo::SubMenu25(){
		string codPais;
		string codCiudad;
		string codRest;
		string codMenu;
		string codProd;
		string nombre;
		string kcal;
		string precio;
		string cantProd;
		cin.ignore();	
	cout<< "Ingrese el codigo de pais: ";
		getline(cin, codPais);
	cout<< "\nIngrese el codigo de ciudad: ";
		getline(cin, codCiudad);
	cout<< "\nIngrese el codigo de restaurante: ";
		getline(cin, codRest);
	cout<< "\nIngrese el codigo de menu: ";
		getline(cin, codMenu);
	cout<< "\nIngrese el codigo de producto: ";
		getline(cin, codProd);
	cout<< "\nIngrese el nombre de producto: ";
		getline(cin, nombre);
	cout<< "\nIngrese cantidad de Kcal: ";
		getline(cin, kcal);
	cout<< "\nIngrese el precio de producto: ";
		getline(cin, precio);
	cout<< "\nIngrese la cantidad de producto: ";
		getline(cin, cantProd);
	
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);
	int temp5 = stoi(codProd);
	int temp6 = stoi(kcal);
	int temp7 = stoi(precio);
	int temp8 = stoi(cantProd);
		
		NodoBinarioPais *q = listaPais->BuscarPais(listaPais->raiz,temp);
		while(q != NULL){
        if(temp < q->valor){
            q = q->Hizq;
        }
        if(temp > q->valor){
        	q = q->Hder;
        }
        else if(temp == q->valor){
			NodoBinarioCiudad *b = q->ArbolCiudad.BuscarCiudad(q->ArbolCiudad.raiz,temp2); 
        	while(b != NULL){
        		if(temp2 < b->valor){
					b = b->Hizq;	
        		}
        		if(temp2 > b->valor){
        			b = b->Hder;
        		}
        		else if(temp2 == b->valor){
        		Nodo *c = b->ArbolRest.Busqueda(b->ArbolRest.Raiz, temp3);
        			if(c !=NULL){
        				NodoM *d = c->listaMenu.BusquedaM(temp4);
        					if(d != NULL)
        						d->listaProducto.InsertaNodoProducto( temp5,  nombre, temp6, temp7, temp8);
        					break;
					}
				break;
				}
        	}
        	if(b == NULL){
        		cout <<"Producto: "<<codProd<<":"<<nombre<<" no fue agregado"<<endl;
    		}
    		break;
			}
        }
        if(q == NULL){
        	cout <<"Producto: "<<codProd<<":"<<nombre<<" no fue agregado"<<endl;
    	}
}


void cargarArchivo::SubMenu26(){
	string cedula;
	string nombre;
	cout<< "Ingrese el numero de cedula: \n";
	cin >> cedula;
	cin.ignore();
	cout<< "\nIngrese el nombre del cliente: ";
	getline(cin,nombre);
	listaCliente->InsertarClave(stoi(cedula), nombre, listaCliente->raiz);
}



// Eliminar
/*
void cargarArchivo::SubMenu3(){
		cout << endl << "----------------------------" << endl;
  		cout << endl << "      3. Eliminar   " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Pais"<<endl;
		cout << "2. Ciudad"<<endl;
		cout << "3. Restaurante"<<endl;
		cout << "4. Menu"<<endl;
		cout << "5. Producto"<<endl;
		cout << "6. Cliente"<<endl;
		cout << "7. Volver"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: "<<endl;		
		char opt;
		cin >> opt;
	switch(opt){
		case '1':{
			cout<< "3.1 Eliminar Pais"<<endl;
			SubMenu31();
			break;
		}
		case '2':{
			cout<< "3.2 Eliminar Ciudad"<<endl;
			SubMenu32();			
			break;
		}
		case '3':{
			cout<< "3.3 Eliminar Restaurante"<<endl;
			SubMenu33();
			break;
		}
		case '4':{
			cout<< "3.4 Eliminar Menu"<<endl;
			SubMenu34();
			break;
		}
		case '5':{
			cout<< "3.5 Eliminar Producto"<<endl;
			SubMenu35();
			break;
		}
		case '6':{
			cout<< "3.6 Eliminar Cliente"<<endl;
			SubMenu36();
			break;
		}
		case '7':{
			cout<<"Volviendo a Main Menu"<<endl;			
			break;
		}
		default :{
			cout<< "!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
			SubMenu3();
			break;
		}
	}
}

void cargarArchivo::SubMenu31(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	listaPais->EliminarPais(listaPais->raiz,stoi(codPais));
}

void cargarArchivo::SubMenu32(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo ciudad: ";
	cin >> codCiudad;
	NodoBinarioPais* aux = listaPais->BuscarPais(listaPais->raiz, stoi(codPais));
	if(aux != NULL){
		aux->ArbolCiudad.BorrarBalanceadoCiudad(aux->ArbolCiudad.raiz,aux->ArbolCiudad.Hh,stoi(codCiudad));
	}else{
		cout<<"El codigo de Pais "<<codPais<<" no se encuentra."<<endl; 
	}
}

void cargarArchivo::SubMenu33(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo restaurante: ";
	cin >> codRest;
	pnodoPais aux = listaPais->GetPrimero();
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->cod == temp){
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
					if(aux2->cod == temp2){
						aux2->listaRestaurante->BorrarPosicion(aux2->listaRestaurante->buscarPos(temp3));
						return;
					}
					aux2= aux2->siguiente;
				}
				cout<<"NO SE ELIMINO RESTAURANTE, CODIGOS INCORRECTOS";
				return;	
			}
		aux=aux->siguiente;
		}	
	cout<<"NO SE ELIMINO RESTAURANTE, CODIGOS INCORRECTOS";
	}
}


void cargarArchivo::SubMenu34(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo restaurante: ";
	cin >> codRest;
	string codMenu;
	cout<< "Ingrese el codigo menu: ";
	cin >> codMenu;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);
	pnodoPais aux = listaPais->primero;
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->cod == temp){
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
					if(aux2->cod == temp2){
						pnodoRest aux3 = aux2->listaRestaurante->primero;
						pnodoRest head = aux2->listaRestaurante->primero;
							while(aux3->siguiente!=head && aux3->cod!=temp3)
								aux3=aux3->siguiente;
							if(aux3->cod == temp3){
							aux3->listaMenu->BorrarPosicion(aux3->listaMenu->buscarPos(temp4));
							return;
							}
							cout<<"NO SE ELIMINO MENU, CODIGOS INCORRECTOS";	
							return;
					}
					aux2= aux2->siguiente;
				}
			cout<<"NO SE ELIMINO MENU, CODIGOS INCORRECTOS";
			return;
			}
		aux=aux->siguiente;
		}
	}
	cout<<"NO SE ELIMINO MENU, CODIGOS INCORRECTOS";
}

void cargarArchivo::SubMenu35(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo de ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo de restaurante: ";
	cin >> codRest;
	string codMenu;
	cout<< "Ingrese el codigo de menu: ";
	cin >> codMenu;
	string codProd;
	cout<< "Ingrese el codigo de producto: ";
	cin >> codProd;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);
	int temp5 = stoi(codProd);
	pnodoPais aux = listaPais->primero;
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->cod == temp){
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
					if(aux2->cod == temp2){
						pnodoRest aux3 = aux2->listaRestaurante->primero;
						pnodoRest head = aux2->listaRestaurante->primero;
							while(aux3->siguiente!=head && aux3->cod!=temp3)
								aux3=aux3->siguiente;
							if(aux3->cod==temp3){
								pnodoMenu aux4 = aux3->listaMenu->primero;
								while(aux4!=NULL){
									if(aux4->cod == temp4){
										aux4->listaProd->BorrarPosicion(aux4->listaProd->buscarPos(temp5));
										return;
									}
								aux4= aux4->siguiente;
								}
								cout<<"NO SE ELIMINO PRODUCTO, CODIGOS INCORRECTOS"<<endl;
								return;
							}else{
								cout<<"NO SE ELIMINO PRODUCTO, CODIGOS INCORRECTOS"<<endl;
								return;
							}
						}
				aux2= aux2->siguiente;
				}
				cout<<"NO SE ELIMINO PRODUCTO, CODIGOS INCORRECTOS"<<endl;
				return;
			}
		aux=aux->siguiente;
		}		
	}
	cout<<"NO SE ELIMINO PRODUCTO, CODIGOS INCORRECTOS"<<endl;
	return;
}

void cargarArchivo::SubMenu36(){
	string cedula;
	cout<< "Ingrese el numero de cedula que desea eliminar: ";
	cin >> cedula;
	
	listaCliente->borrarPosicion(listaCliente->buscarPos(stoi(cedula)));
}
*/
//Buscar

void cargarArchivo::SubMenu4(){
		cout << endl << "----------------------------" << endl;
  		cout << endl << "      4. Buscar   " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Pais"<<endl;
		cout << "2. Ciudad"<<endl;
		cout << "3. Restaurante"<<endl;
		cout << "4. Menu"<<endl;
		cout << "5. Producto"<<endl;
		cout << "6. Cliente"<<endl;
		cout << "7. Volver"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: "<<endl;		
		char opt;
		cin >> opt;
	switch(opt){
		case '1':{
			cout<< "4.1 Buscar Pais"<<endl;
			SubMenu41();
			break;
		}
		case '2':{
			cout<< "4.2 Buscar Ciudad"<<endl;
			SubMenu42();			
			break;
		}
		case '3':{
			cout<< "4.3 Buscar Restaurante"<<endl;
			SubMenu43();
			break;
		}
		case '4':{
			cout<< "4.4 Buscar Menu"<<endl;
			SubMenu44();
			break;
		}
		case '5':{
			cout<< "4.5 Buscar Producto"<<endl;
			SubMenu45();
			break;
		}
		case '6':{
			cout<< "4.6 Buscar Cliente"<<endl;
			SubMenu46();
			break;
		}
		case '7':{
			cout<<"Volviendo a Main Menu"<<endl;			
			break;
		}
		default :{
			cout<< "!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
			SubMenu4();
			break;
		}
	}
}

void cargarArchivo::SubMenu41(){
	string cod;
	cout<< "Ingrese el codigo de pais: ";
	cin >> cod;
	NodoBinarioPais* aux = listaPais->BuscarPais(listaPais->raiz, stoi(cod));
	if(aux != NULL){
		cout<<"\n.:Pais encontrado:.\nCodigo: "<<aux->valor<<"\nNombre: "<<aux->pais<<endl;
	}else{
		cout<<"El pais "<<cod<<" no se encuentra"<<endl;
	}
/*	listaPais->MostrarPosicion(listaPais->buscarPos(stoi(cod)));*/
}

void cargarArchivo::SubMenu42(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo ciudad: ";
	cin >> codCiudad;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	NodoBinarioPais* aux = listaPais->BuscarPais(listaPais->raiz, temp);
	if(aux != NULL){
		NodoBinarioCiudad* aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz,temp2);
		if(aux2 != NULL){
			cout<<"\n.:Ciudad encontrada:.\nCodigo Pais: "<<aux->valor<<"\nCodigo Ciudad: "<<aux2->valor<<"\nNombre: "<<aux2->ciudad<<endl;
		}else{
			cout<<"La ciudad "<<temp2<< " no se encuentra"<<endl;
		}	
	}else{
		cout<<"La ciudad "<<temp2<< " no se encuentra"<<endl;
	}
}

void cargarArchivo::SubMenu43(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo restaurante: ";
	cin >> codRest;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	NodoBinarioPais* aux = listaPais->BuscarPais(listaPais->raiz, temp);
	if(aux != NULL){
		NodoBinarioCiudad* aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz,temp2);
		if(aux2 != NULL){
			NodoPtr aux3 = aux2->ArbolRest.BuscarNodo(temp3);
			RestMasBuscados->insertarBus(temp3, aux3->nombreRest);
			RestMasBuscados->BuscarNodoBus(temp3);			
		}else{
			cout<<"El restaurante "<<temp3<< " no se encuentra"<<endl;
		}	
	}else{
		cout<<"El restaurante "<<temp3<< " no se encuentra"<<endl;
	}
}

void cargarArchivo::SubMenu44(){
	string codPais;
	string codCiudad;
	string codRest;
	string codMenu;
	string menu;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	cout<< "\nIngrese el codigo de ciudad: ";
	cin >> codCiudad;
	cout<< "\nIngrese el codigo de restaurante: ";
	cin >> codRest;
	cout<< "\nIngrese el codigo de menu: ";
	cin >> codMenu;

	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);

	NodoBinarioPais* aux = listaPais->BuscarPais(listaPais->raiz, temp);
	if(aux != NULL){
		NodoBinarioCiudad* aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz,temp2);
		if(aux2 != NULL){
			NodoPtr aux3 = aux2->ArbolRest.BusquedaMRest(temp3);
				aux3->listaMenu.BuscarNodoMenu(temp4);
				NodoMPtr aux4 = aux3->listaMenu.BuscarNodoMenu1(temp4);
				if(aux4 !=NULL){
					MenuMasBuscados->insertarBus(aux4->codMenu,aux4->nombreMenu);
					MenuMasBuscados->BuscarNodoMenu2(temp4);
				}
		}else{
			cout<<"El Menu "<<temp4<< " no se encuentra"<<endl;
		}	
	}else{
		cout<<"El Menu "<<temp4<< " no se encuentra"<<endl;
	}
}				

void cargarArchivo::SubMenu45(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo de ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo de restaurante: ";
	cin >> codRest;
	string codMenu;
	cout<< "Ingrese el codigo de menu: ";
	cin >> codMenu;
	string codProd;
	cout<< "Ingrese el codigo de producto: ";
	cin >> codProd;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);
	int temp5 = stoi(codProd);

	NodoBinarioPais* aux = listaPais->BuscarPais(listaPais->raiz, temp);
	if(aux != NULL){
		NodoBinarioCiudad* aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz,temp2);
		if(aux2 != NULL){
			NodoPtr aux3 = aux2->ArbolRest.BusquedaMRest(temp3);
				if(aux3 != NULL){
					NodoMPtr aux4 = aux3->listaMenu.BusquedaM(temp4);
					aux4->listaProducto.BuscarProductoBool(aux4->listaProducto.raiz, temp5);
				}
		}else{
			cout<<"El Producto "<<temp5<< " no se encuentra"<<endl;
		}	
	}else{
		cout<<"El Producto "<<temp5<< " no se encuentra"<<endl;
	}
}

void cargarArchivo::SubMenu46(){
	string cedula;
	cout<< "Ingrese el numero de cedula que desea encontrar: ";
	cin >> cedula;
	
	listaCliente->Search(stoi(cedula), listaCliente->raiz);
}

//Modificar

void cargarArchivo::SubMenu5(){
		cout << endl << "----------------------------" << endl;
  		cout << endl << "      5. Modificar   " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Pais"<<endl;
		cout << "2. Ciudad"<<endl;
		cout << "3. Restaurante"<<endl;
		cout << "4. Menu"<<endl;
		cout << "5. Producto"<<endl;
		cout << "6. Cliente"<<endl;
		cout << "7. Compras"<<endl;
		cout << "8. Volver"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: "<<endl;		
		char opt;
		cin >> opt;
	switch(opt){
		case '1':{
			cout<< "5.1 Modificar Pais"<<endl;
			SubMenu51();
			break;
		}
		case '2':{
			cout<< "5.2 Modificar Ciudad"<<endl;
			SubMenu52();			
			break;
		}
		case '3':{
			cout<< "5.3 Modificar Restaurante"<<endl;
			SubMenu53();
			break;
		}
		case '4':{
			cout<< "5.4 Modificar Menu"<<endl;
			SubMenu54();
			break;
		}
		case '5':{
			cout<< "5.5 Modificar Producto"<<endl;
			SubMenu55();
			break;
		}
		case '6':{
			cout<< "5.6 Modificar Cliente"<<endl;
			SubMenu56();
			break;
		}
		case '7':{
			cout<<"5.7 Modificar Compras"<<endl;	
			SubMenu57();	
			break;
		}
		case '8':{
			cout<<"Volviendo a Main Menu"<<endl;			
			break;
		}
		default :{
			cout<< "!!!Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
			SubMenu5();
			break;
		}
	}
}

void cargarArchivo::SubMenu51(){
	string cod;
	cout<< "Ingrese el codigo de pais: ";
	cin >> cod;
	string nom;
	cout<< "Ingrese el nuevo nombre de pais: ";
	cin >> nom;
	NodoBinarioPais* aux = listaPais->BuscarPais(listaPais->raiz, stoi(cod));
	if(aux != NULL){
		cout<<"Anterior: "<<aux->valor<<":"<<aux->pais<<endl;
		cout<<"El pais fue modificado"<<endl;
		aux->pais = nom;
		cout<<"Nuevo: "<<aux->valor<<":"<<aux->pais<<endl;
	}else{
		cout<<"El pais "<<cod<<" no se encuentra"<<endl;
	}
/*	listaPais->MostrarPosicion(listaPais->buscarPos(stoi(cod)));*/
}

void cargarArchivo::SubMenu52(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo ciudad: ";
	cin >> codCiudad;
	string nom;
	cout<< "Ingrese el Nombre de ciudad: ";
	cin >> nom;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	NodoBinarioPais* aux = listaPais->BuscarPais(listaPais->raiz, temp);
	if(aux != NULL){
		NodoBinarioCiudad* aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz,temp2);
		if(aux2 != NULL){
			cout<<"La ciudad fue modificada"<<endl;
			cout<<"Anterior: "<<aux2->valor<<":"<<aux2->ciudad<<endl;
			aux2->ciudad = nom;
			cout<<"Nuevo: "<<aux2->valor<<":"<<aux2->ciudad<<endl;
		}else{
			cout<<"La ciudad "<<temp2<< " no se encuentra"<<endl;
		}	
	}else{
		cout<<"La ciudad "<<temp2<< " no se encuentra"<<endl;
	}
}

void cargarArchivo::SubMenu53(){
	string codPais;
	string nom;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo restaurante: ";
	cin >> codRest;
	string nomRest;
	cout<< "Ingrese el nombre del restaurante: ";
	cin >> nomRest;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	NodoBinarioPais* aux = listaPais->BuscarPais(listaPais->raiz, temp);
	if(aux != NULL){
		NodoBinarioCiudad* aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz,temp2);
		if(aux2 != NULL){
			aux2->ArbolRest.ModificarNodo(temp3,nomRest);
		}else{
			cout<<"El restaurante "<<temp3<< " no se encuentra"<<endl;
		}	
	}else{
		cout<<"El restaurante "<<temp3<< " no se encuentra"<<endl;
	}
}

void cargarArchivo::SubMenu54(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo de ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo de restaurante: ";
	cin >> codRest;
	string codMenu;
	cout<< "Ingrese el codigo de menu: ";
	cin >> codMenu;
	string nomMenu;
	cin.ignore();
	cout<< "Ingrese el Nombre del Menu: ";
	getline(cin,nomMenu);
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);

	NodoBinarioPais* aux = listaPais->BuscarPais(listaPais->raiz, temp);
	if(aux != NULL){
		NodoBinarioCiudad* aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz,temp2);
		if(aux2 != NULL){
			NodoPtr aux3 = aux2->ArbolRest.BusquedaMRest(temp3);
				if(aux3 != NULL){
					NodoMPtr aux4 = aux3->listaMenu.BuscarNodoMenu1(temp4);
					if(aux4 != NULL){
					cout<<"Producto fue modificado"<<endl;
					cout<<"Anterior: "<<endl;
					cout<<"- Codigo: "<<aux4->codMenu<<endl;
					cout<<"- Nombre: "<<aux4->nombreMenu<<endl;
					aux4->nombreMenu = nomMenu;
					cout<<"Nuevo: "<<endl;
					cout<<"- Codigo: "<<aux4->codMenu<<endl;
					cout<<"- Nombre: "<<aux4->nombreMenu<<endl;
					}else{
								cout<<"menu0 "<<temp4<< " no se encuentra"<<endl;
	
					}
				}
		}else{
			cout<<"menu1 "<<temp4<< " no se encuentra"<<endl;
		}	
	}else{
		cout<<"menu2 "<<temp4<< " no se encuentra"<<endl;
	}
}

void cargarArchivo::SubMenu55(){
		string codPais;
		string codCiudad;
		string codRest;
		string codMenu;
		string codProd;
		string nombre;
		string kcal;
		string precio;
		string cantProd;
		cin.ignore();	
	cout<< "Ingrese el codigo de pais: ";
		getline(cin, codPais);
	cout<< "\nIngrese el codigo de ciudad: ";
		getline(cin, codCiudad);
	cout<< "\nIngrese el codigo de restaurante: ";
		getline(cin, codRest);
	cout<< "\nIngrese el codigo de menu: ";
		getline(cin, codMenu);
	cout<< "\nIngrese el codigo de producto: ";
		getline(cin, codProd);
	cout<< "\nIngrese el nombre de producto: ";
		getline(cin, nombre);
	cout<< "\nIngrese cantidad de Kcal: ";
		getline(cin, kcal);
	cout<< "\nIngrese el precio de producto: ";
		getline(cin, precio);
	cout<< "\nIngrese la cantidad de producto: ";
		getline(cin, cantProd);
	
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);
	int temp5 = stoi(codProd);
	int temp6 = stoi(kcal);
	int temp7 = stoi(precio);
	int temp8 = stoi(cantProd);

	NodoBinarioPais* aux = listaPais->BuscarPais(listaPais->raiz, temp);
	if(aux != NULL){
		NodoBinarioCiudad* aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz,temp2);
		if(aux2 != NULL){
			NodoPtr aux3 = aux2->ArbolRest.BusquedaMRest(temp3);
				if(aux3 != NULL){
					NodoMPtr aux4 = aux3->listaMenu.BusquedaM(temp4);
					if(aux4 != NULL){
						NodoBinarioProducto* aux5 = aux4->listaProducto.BuscarProducto(aux4->listaProducto.raiz, temp5);
						cout<<"Producto fue modificado"<<endl;
						cout<<"Anterior: "<<endl;
						cout<<"- Codigo: "<<aux5->valor<<endl;
						cout<<"- Nombre: "<<aux5->Producto<<endl;
						cout<<"- Kcal: "<<aux5->Kcal<<endl;
						cout<<"- Precio: "<<aux5->Precio<<endl;
						cout<<"- Cantidad: "<<aux5->Cantidad<<endl;
						aux5->valor = temp5;
						aux5->Producto = nombre;
						aux5->Kcal = temp6;
						aux5->Precio = temp7;
						aux5->Cantidad = temp8;
						cout<<"Nuevo: "<<endl;
						cout<<"- Codigo: "<<aux5->valor<<endl;
						cout<<"- Nombre: "<<aux5->Producto<<endl;
						cout<<"- Kcal: "<<aux5->Kcal<<endl;
						cout<<"- Precio: "<<aux5->Precio<<endl;
						cout<<"- Cantidad: "<<aux5->Cantidad<<endl;
					}else{
					cout<<"PRODUCTO1 "<<temp2<< " no se encuentra"<<endl;
					}	
				}else{
					cout<<"PRODUCTO2 "<<temp2<< " no se encuentra"<<endl;
				}		
		}
	}else{
		cout<<"El Producto3 "<<temp5<< " no se encuentra"<<endl;
	}	
}

void cargarArchivo::SubMenu56(){
	string cedula;
	string nom;
	cout<< "Ingrese el numero de cedula que desea modificar: ";
	cin >> cedula;
	cin.ignore();
	int temp = stoi(cedula);
	cout<< "Ingrese el nombre del cliente: ";
	getline(cin, nom);
	listaCliente->Modificar(stoi(cedula), nom, listaCliente->raiz);
}

void cargarArchivo::SubMenu57(){
	if(listaFila->ListaVacia() == true) {
		cout<< "No hay compras en progreso ";
		return;
	}
	else {
		string cedula;
		string codProducto;
		string cantidadMod;
		char opt;
		cout << "Ingrese el numero de cedula del cliente: ";
		cin >> cedula;
		cout << "Ingrese el codigo del producto: ";
		cin >> codProducto;
		int temp = stoi(cedula);
		int temp2 = stoi(codProducto);
		pnodoFila aux = listaFila->GetPrimero();
		if (listaCliente->SearchC(temp, listaCliente->raiz)) {
			while (aux != NULL) {
				if (aux->valor == temp) {
					pnodoComp aux2 = aux->listaComp->GetPrimero();
					while (aux2 != NULL) {
						if (aux2->cod == temp2) {
							cout << "Desea cambiar 1.codigo o 2.cantidad:" << endl;
							cin >> opt;
							switch (opt) {
							case '1': {
								SubMenu571(aux2);
								break;
							}
							case '2': {
								cout << "Inserte nueva cantidad:" << endl;
								cin >> cantidadMod;
								int temp3 = stoi(cantidadMod);
								aux2->cantidad = temp3;
								cout << "Cantidad modificada en producto " + codProducto + " a: " + cantidadMod;
								break;
							}

									return;
							}
							aux2 = aux2->siguiente;
						}
					}
					aux = aux->siguiente;
				}else{
				cout << "Producto no existe" << endl;
				return;
				}
			}

		}else{
		cout << "Cedula no existe" << endl;
		return;
		}
	}
}



void cargarArchivo::SubMenu571(pnodoComp Prod){
	string codPais;
		string codCiudad;
		string codRest;
		string codMenu;
		string codProd;
		string nombre;
		string kcal;
		string precio;
		string cantProd;
		cin.ignore();	
	cout<< "Ingrese el codigo de pais: ";
		getline(cin, codPais);
	cout<< "\nIngrese el codigo de ciudad: ";
		getline(cin, codCiudad);
	cout<< "\nIngrese el codigo de restaurante: ";
		getline(cin, codRest);
	cout<< "\nIngrese el codigo de menu: ";
		getline(cin, codMenu);
	cout<< "\nIngrese el codigo de producto: ";
		getline(cin, codProd);
	cout<< "\nIngrese la cantidad de producto: ";
		getline(cin, cantProd);
	
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);
	int temp5 = stoi(codProd);
	int temp8 = stoi(cantProd);

	NodoBinarioPais* aux = listaPais->BuscarPais(listaPais->raiz, temp);
	if(aux != NULL){
		NodoBinarioCiudad* aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz,temp2);
		if(aux2 != NULL){
			NodoPtr aux3 = aux2->ArbolRest.BusquedaMRest(temp3);
				if(aux3 != NULL){
					NodoMPtr aux4 = aux3->listaMenu.BusquedaM(temp4);
					if(aux4 != NULL){
						NodoBinarioProducto* aux5 = aux4->listaProducto.BuscarProducto(aux4->listaProducto.raiz, temp5);
						if (aux5->Cantidad < temp8 || aux5->Cantidad ==0){
    						cout << "No se tiene suficiente producto en existencia" << endl;
						} else {
						aux4->listaProducto.Reducir(aux5, temp8);
						cout<<"Producto fue a�adido"<<endl;
						cout<<"- Codigo: "<<aux5->valor<<endl;
						cout<<"- Nombre: "<<aux5->Producto<<endl;
						cout<<"- Kcal: "<<aux5->Kcal<<endl;
						cout<<"- Precio: "<<aux5->Precio<<endl;
						cout<<"- Cantidad: "<<temp8<<endl;
						
						}
						
					}else{
					cout<<"PRODUCTO1 "<<temp2<< " no se encuentra"<<endl;
					}	
				}else{
					cout<<"PRODUCTO2 "<<temp2<< " no se encuentra"<<endl;
				}		
		}
	}else{
		cout<<"El Producto3 "<<temp5<< " no se encuentra"<<endl;
	}	
}



void cargarArchivo::SubMenu6(){
		cout << endl << "----------------------------" << endl;
  		cout << endl << "      6. Reportes   " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Lista de Paises"<<endl;
		cout << "2. Lista de Ciudades por Pais"<<endl;
		cout << "3. Lista de Restaurantes por Ciudad"<<endl;
		cout << "4. Lista de Clientes"<<endl;
		cout << "5. Restaurante MAS buscado"<<endl;
		cout << "6. Menu de Restaurante"<<endl;
		cout << "7. Productos en Menu"<<endl;
		cout << "8. Menu mas buscado"<<endl;
		cout << "9. Volver"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: "<<endl;		
		char opt;
		cin >> opt;
	switch(opt){
		case '1':{
			cout<< "6.1 Lista de Paises"<<endl;
			SubMenu61();
			break;
		}
		case '2':{
			cout<< "6.2 Lista de Ciudades por Pais"<<endl;
			SubMenu62();			
			break;
		}
		case '3':{
			cout<< "6.3 Lista de Restaurantes por Ciudad"<<endl;
			SubMenu63();
			break;
		}
		case '4':{
			cout<< "6.4 Lista de Clientes"<<endl;
			SubMenu64();
			break;
		}
		case '5':{
			cout<< "6.5 Restaurante MAS buscado"<<endl;
			SubMenu65();
			break;
		}
		case '6':{
			cout<< "6.6 Menu de Restaurante"<<endl;
			SubMenu66();
			break;
		}
		case '7':{
			cout<< "6.7 Productos en Menu"<<endl;
			SubMenu67();
			break;
		}
		case '8':{
			cout<< "6.8 Menu mas buscado"<<endl;
			SubMenu68();
			break;
		}
		case '9':{
			cout<< "6.9 Volver"<<endl;
			break;
		}
		default :{
			cout<< "!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
			SubMenu6();
			break;
		}
	}
}

//Reporte de Paises
void cargarArchivo::SubMenu61(){
	cout<< "\nSe esta generando el archivo Reporte_Paises.txt\n.\n.\n.\n";
	listaPais->reportePaises();
}

//Reporte de Ciudades por pais
void cargarArchivo::SubMenu62(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	int temp = stoi(codPais);
	pnodoPais aux = listaPais->BuscarPais(listaPais->raiz, temp);
	if(aux != NULL){
		cout<< "\nSe esta generando el archivo Reporte_Ciudades_"+aux->pais+".txt\n.\n.\n.\n"<<endl;
		aux->ArbolCiudad.reporteCiudad("Reporte_Ciudades_"+aux->pais);
		return;
	}
	cout<<"El pais ingresado no existe";
}

//Reporte de Restaurantes por Ciudad
void cargarArchivo::SubMenu63(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo ciudad: ";
	cin >> codCiudad;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	pnodoPais aux = listaPais->BuscarPais(listaPais->raiz, temp);
	if(aux != NULL){
		pnodoCiudad aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz, temp2);
		if(aux2 != NULL){
			cout<< "\nSe esta generando el archivo Reporte_Restaurante_"+aux2->ciudad+".txt\n.\n.\n.\n"<<endl;
			aux2->ArbolRest.MostrarRN3(aux2->ciudad);
			aux2->ArbolRest.MostrarRN();
		}else{
			cout<<"Datos incorrectos, por favor intente de nuevo.";
		}
	}else{
		cout<<"Datos incorrectos, por favor intente de nuevo.";
	}
}

//Reporte de Clientes
void cargarArchivo::SubMenu64(){
	cout<< "\nSe esta generando el archivo Reporte_Clientes.txt\n.\n.\n.\n"<<endl;

	listaCliente->saveToFile("Reporte_Clientes.txt");
}
/*
//Reporte Restaurante mas buscado 
void cargarArchivo::SubMenu65() {
	int contTop = 0;
    int codPaisTop = 0;
    int codCiudadTop = 0;
    int codRestTop = 0;
    string restTop = "";
    
	pnodoPais aux = listaPais->GetPrimero();
		while(aux!=NULL){
			pnodoCiudad aux2 = aux->listaCiudad->primero;
			while(aux2!=NULL){
				pnodoRest aux3 = aux2->listaRestaurante->buscarMayor();
				if(aux3 == NULL){
				}else{
					if(aux3->counter > contTop){
					contTop = aux3->counter;
					codPaisTop = aux->cod;
					codCiudadTop = aux2->cod;
					codRestTop = aux3->cod;
					restTop = aux3->rest;
					}
				}
			aux2= aux2->siguiente;
			}
		aux=aux->siguiente;	
		}
    if (contTop == 0) {
        cout << "\n***AUN NO SE HA BUSCADO NINGUN RESTAURANTE***" << endl << endl;
    }
    
    else {
        cout << "\nSe esta generando el archivo Reporte_Restaurante_Mas_Buscado.txt\n.\n.\n.\n" << endl;
        ofstream archivoSalida("Reporte_Restaurante_Mas_Buscado.txt");
        if (!archivoSalida.is_open()) {
            cerr << "No se pudo abrir el archivo." << endl;
        }
        else {
            archivoSalida << "REPORTE RESTAURANTE MAS BUSCADO " << endl << endl << endl;
            archivoSalida << codPaisTop << ":" << codCiudadTop << ":" << codRestTop << ":" << restTop << endl;
            archivoSalida << "Restaurante buscado : " << contTop <<" veces." <<endl;
            cout << endl;
            archivoSalida.close();
            cout << "Reporte generado";
        }
    }
}
*/
// Restaurante mas buscado
void cargarArchivo::SubMenu65(){
	RestMasBuscados->FindNodeWithHighestContador(RestMasBuscados->Raiz);
	cout<< "\nSe esta generando el archivo Reporte_Restaurante_Mas_Buscado.txt\n.\n.\n.\n"<<endl;
    cout << "Reporte generado";
}


void cargarArchivo::SubMenu66(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo de Restaurante: ";
	cin >> codRest;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	pnodoPais aux = listaPais->BuscarPais(listaPais->raiz, temp);
	if(aux != NULL){
		pnodoCiudad aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz, temp2);
		if(aux2 != NULL){
			NodoPtr aux3 = aux2->ArbolRest.BusquedaMRest(temp3);
			cout<< "\nSe esta generando el archivo Reporte_Menu_"+aux3->nombreRest+".txt\n.\n.\n.\n"<<endl;
			aux3->listaMenu.generateReport(aux3->listaMenu.Raiz, aux3->nombreRest);
			cout << "Reporte generado";
		}else{
			cout<<"Datos incorrectos, por favor intente de nuevo.";
		}
	}else{
		cout<<"Datos incorrectos, por favor intente de nuevo.";
	}
}


void cargarArchivo::SubMenu67(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo de Restaurante: ";
	cin >> codRest;
	string codMenu;
	cout<< "Ingrese el codigo de Menu: ";
	cin >> codMenu;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);
	pnodoPais aux = listaPais->BuscarPais(listaPais->raiz, temp);
	if(aux != NULL){
		pnodoCiudad aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz, temp2);
		if(aux2 != NULL){
			NodoPtr aux3 = aux2->ArbolRest.Busqueda(aux2->ArbolRest.Raiz, temp3);
			if(aux3 != NULL){
				NodoMPtr aux4 = aux3->listaMenu.BuscarNodoMenu1(temp4);
				aux4->listaProducto.reporteProducto(aux4->nombreMenu);
				cout<< "\nSe esta generando el archivo Reporte_Productos_"+aux4->nombreMenu+".txt\n.\n.\n.\n"<<endl;
				cout << "Reporte generado";
			}

		}else{
			cout<<"Datos incorrectos, por favor intente de nuevo.";
		}
	}else{
		cout<<"Datos incorrectos, por favor intente de nuevo.";
	}
}


void cargarArchivo::SubMenu68(){
	MenuMasBuscados->findMaxContador(MenuMasBuscados->Raiz);
	cout<< "\nSe esta generando el archivo Reporte_Menu_Mas_Buscado.txt\n.\n.\n.\n"<<endl;
    cout << "Reporte generado";
}



void cargarArchivo::SubMenu7(){
		cout << endl << "----------------------------" << endl;
  		cout << endl << "      7. Reportes2   " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Compras de Cliente"<<endl;
		cout << "2. Producto mas comprado"<<endl;
		cout << "3. Factura Mayor monto"<<endl;
		cout << "4. Factura Menor monto"<<endl;
		cout << "5. Descuento aplicado tarjeta"<<endl;
		cout << "6. Consultar precio de producto"<<endl;
		cout << "7. Consultar cantidad de producto disponible"<<endl;
		cout << "8. Volver"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: "<<endl;		
		char opt;
		cin >> opt;
	switch(opt){
		case '1':{
			cout<< "7.1 Compras de Cliente"<<endl;
			SubMenu71();
			break;
		}
		case '2':{
			cout<< "7.2 Producto mas comprado"<<endl;
			SubMenu72();			
			break;
		}
		case '3':{
			cout<< "7.3 Factura Mayor monto"<<endl;
			SubMenu73();
			break;
		}
		case '4':{
			cout<< "7.4 Factura Menor monto"<<endl;
			SubMenu74();
			break;
		}
		case '5':{
			cout<< "7.5 Descuento aplicado tarjeta"<<endl;
			SubMenu75();
			break;
		}
		case '6':{
			cout<< "7.6 Consultar precio de producto"<<endl;
			SubMenu76();
			break;
		}
		case '7':{
			cout<< "7.7 Consultar cantidad de producto disponible"<<endl;
			SubMenu77();
			break;
		}
		case '8':{
			cout<< "7.8 Volver"<<endl;
			break;
		}
		default :{
			cout<< "!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
			SubMenu7();
			break;
		}
	}
}

void cargarArchivo::SubMenu71(){//Consultar precio de producto.
		string cedula;
	cout << "Ingrese la cedula del usuario" << endl;
	cin >> cedula;
	int temp = stoi(cedula);
	
	listaCliente->CompraDeCliente(temp, listaCliente->raiz);
}

void cargarArchivo::SubMenu72(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo de ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo de restaurante: ";
	cin >> codRest;
	string codMenu;
	cout<< "Ingrese el codigo de menu: ";
	cin >> codMenu;
	string codProd;
	
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);

	NodoBinarioPais* aux = listaPais->BuscarPais(listaPais->raiz, temp);
	if(aux != NULL){
		NodoBinarioCiudad* aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz,temp2);
		if(aux2 != NULL){
			NodoPtr aux3 = aux2->ArbolRest.BusquedaMRest(temp3);
				if(aux3 != NULL){
					cout<< "\nSe esta generando el archivo Reporte_Compras_.txt\n.\n.\n.\n"<<endl;
					cout << "Reporte generado";
					NodoMPtr aux4 = aux3->listaMenu.BusquedaM(temp4);
					NodoBinarioProducto* aux5 = aux4->listaProducto.ProductoMasComprado(aux4->listaProducto.raiz);
					int codBusq = aux5->valor;
					aux4->listaProducto.BuscarProductoCantidadCompra(aux4->listaProducto.raiz,codBusq);
				}
		}else{
			cout<<"Error en productos"<<endl;
		}	
	}else{
		cout<<"Error en productos"<<endl;
	}
}



void cargarArchivo::SubMenu73(){
	ofstream archivo_salida("Factura grande.txt"); 
    				if (!archivo_salida.is_open()) { 
        				cerr << "Error generando el archivo." <<endl; 
    				} 
    				archivo_salida << "\t.:Factura_grande:."<<endl<<endl<<endl;
    				archivo_salida <<"Cedula: "<<FacturaGrande->valor <<"\n"<<FacturaGrande->listaComp->Mostrar()<<"\n Total: "<<FacturaGrande->listaComp->CalcularPrecio()<<"\n"<<endl<<endl; 
					cout<<"Generado contenido"<<endl;
    				archivo_salida.close(); 
					cout << "Reporte generado";
}

void cargarArchivo::SubMenu74(){
	ofstream archivo_salida("Factura_Pequena.txt"); 
    				if (!archivo_salida.is_open()) { 
        				cerr << "Error generando el archivo." <<endl; 
    				} 
					archivo_salida << "\t.:Factura_peque�a:."<<endl<<endl<<endl;
    				archivo_salida <<"Cedula: "<<FacturaPequena->valor <<"\n"<<FacturaPequena->listaComp->Mostrar()<<"\n Total: "<<FacturaPequena->listaComp->CalcularPrecio()<<"\n"<<endl<<endl; 
					cout<<"Generado contenido"<<endl;
    				archivo_salida.close(); 
					cout << "Reporte generado";
}

void cargarArchivo::SubMenu75(){
	cout << "Inserte la cedula del usuario" << endl;
		string cedula;
		cin >> cedula;
		int temp = stoi(cedula);
		pnodoFila aux = listaFila->Buscador(temp);
		if(listaCliente->Search(temp,listaCliente->raiz)) {
		
				cout<<"Productos comprados: "<<endl;
    			aux->listaComp->Mostrar();
    			cout<<"Descuento obtenido: "<<endl;
    			int precioFin = aux->listaComp->CalcularPrecio();
    			precioFin = ((precioFin/100)*3);
    			cout<<precioFin<<endl;	
	} else {
		cout << "Cedula invalida" << endl;
	}
}

void cargarArchivo::SubMenu76(){//Consultar precio de producto.
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo de ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo de restaurante: ";
	cin >> codRest;
	string codMenu;
	cout<< "Ingrese el codigo de menu: ";
	cin >> codMenu;
	string codProd;
	cout<< "Ingrese el codigo de producto: ";
	cin >> codProd;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);
	int temp5 = stoi(codProd);

	NodoBinarioPais* aux = listaPais->BuscarPais(listaPais->raiz, temp);
	if(aux != NULL){
		NodoBinarioCiudad* aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz,temp2);
		if(aux2 != NULL){
			NodoPtr aux3 = aux2->ArbolRest.BusquedaMRest(temp3);
				if(aux3 != NULL){
					cout<< "\nSe esta generando el archivo Reporte_Precio_"+to_string(temp5)+".txt\n.\n.\n.\n"<<endl;
					cout << "Reporte generado";
					NodoMPtr aux4 = aux3->listaMenu.BusquedaM(temp4);
					aux4->listaProducto.BuscarProductoPrecio(aux4->listaProducto.raiz, temp5);
				}
		}else{
			cout<<"El Producto "<<temp5<< " no se encuentra"<<endl;
		}	
	}else{
		cout<<"El Producto "<<temp5<< " no se encuentra"<<endl;
	}
}

void cargarArchivo::SubMenu77(){//Consultar cantidad de producto.
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo de ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo de restaurante: ";
	cin >> codRest;
	string codMenu;
	cout<< "Ingrese el codigo de menu: ";
	cin >> codMenu;
	string codProd;
	cout<< "Ingrese el codigo de producto: ";
	cin >> codProd;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);
	int temp5 = stoi(codProd);

	NodoBinarioPais* aux = listaPais->BuscarPais(listaPais->raiz, temp);
	if(aux != NULL){
		NodoBinarioCiudad* aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz,temp2);
		if(aux2 != NULL){
			NodoPtr aux3 = aux2->ArbolRest.BusquedaMRest(temp3);
				if(aux3 != NULL){
					cout<< "\nSe esta generando el archivo Reporte_Cantidad_"+to_string(temp5)+".txt\n.\n.\n.\n"<<endl;
					cout << "Reporte generado";
					NodoMPtr aux4 = aux3->listaMenu.BusquedaM(temp4);
					aux4->listaProducto.BuscarProductoCantidad(aux4->listaProducto.raiz, temp5);
				}
		}else{
			cout<<"El Producto "<<temp5<< " no se encuentra"<<endl;
		}	
	}else{
		cout<<"El Producto "<<temp5<< " no se encuentra"<<endl;
	}
}

//Comprar

void cargarArchivo::SubMenu8(){
		cout << "Ingrese la cedula del usuario" << endl;
		string cedula;
		cin >> cedula;
		int temp = stoi(cedula);
		if(listaCliente->SearchC(temp,listaCliente->raiz)) {
		string nombre = listaCliente->SearchContador(temp,listaCliente->raiz);
		cout << endl << "----------------------------" << endl;
  		cout << endl << "      8. Comprar   " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. A�adir"<<endl;
		cout << "2. Pagar"<<endl;
		cout << "3. Salir"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: ";
		char opt;
		cin >> opt;
		switch(opt) {
    	case '1' :
			SubMenu81(temp);
			Menu();
			break; 
		case '2':
			cout<<"Entrando a pagar ...\n"<<endl;
			SubMenu82(temp);
			Menu();
    		break;
    	case '3':
    		{cout<<"Volviendo a Main Menu"<<endl;
    		Menu();
    		break;
    	}
    	default:
		{ 
    		cout<<"!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
    		Menu();
			break;
			}
    		
	}
		}else{
		cout << "Cedula invalida" << endl;
		}
}

void cargarArchivo::SubMenu81(int cedula){
	string nombre = listaCliente->SearchNodo(cedula,listaCliente->raiz);
	string codPais;
		string codCiudad;
		string codRest;
		string codMenu;
		string codProd;
		string kcal;
		string precio;
		string cantProd;
		cin.ignore();	
	cout<< "Ingrese el codigo de pais: ";
		getline(cin, codPais);
	cout<< "\nIngrese el codigo de ciudad: ";
		getline(cin, codCiudad);
	cout<< "\nIngrese el codigo de restaurante: ";
		getline(cin, codRest);
	cout<< "\nIngrese el codigo de menu: ";
		getline(cin, codMenu);
	cout<< "\nIngrese el codigo de producto: ";
		getline(cin, codProd);
	cout<< "\nIngrese la cantidad de producto: ";
		getline(cin, cantProd);
	
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);
	int temp5 = stoi(codProd);
	int temp8 = stoi(cantProd);

	NodoBinarioPais* aux = listaPais->BuscarPais(listaPais->raiz, temp);
	if(aux != NULL){
		NodoBinarioCiudad* aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz,temp2);
		if(aux2 != NULL){
			NodoPtr aux3 = aux2->ArbolRest.BusquedaMRest(temp3);
				if(aux3 != NULL){
					NodoMPtr aux4 = aux3->listaMenu.BusquedaM(temp4);
					if(aux4 != NULL){
						NodoBinarioProducto* aux5 = aux4->listaProducto.BuscarProducto(aux4->listaProducto.raiz, temp5);
						if (aux5->Cantidad < temp8 || aux5->Cantidad ==0){
    						cout << "No se tiene suficiente producto en existencia" << endl;
						} else {
						aux4->listaProducto.Reducir(aux5, temp8);
						cout<<"Producto fue a�adido"<<endl;
						cout<<"- Codigo: "<<aux5->valor<<endl;
						cout<<"- Nombre: "<<aux5->Producto<<endl;
						cout<<"- Kcal: "<<aux5->Kcal<<endl;
						cout<<"- Precio: "<<aux5->Precio<<endl;
						cout<<"- Cantidad: "<<temp8<<endl;
						listaFila->Comprar(cedula,nombre,aux5->valor,aux5->Producto,aux5->Kcal,aux5->Precio,temp8);
						}
						
					}else{
					cout<<"El Producto "<<temp5<< " no se encuentra"<<endl;
					}	
				}else{
					cout<<"El Producto "<<temp5<< " no se encuentra"<<endl;
				}		
		}
	}else{
		cout<<"El Producto "<<temp5<< " no se encuentra"<<endl;
	}	
}

void cargarArchivo::SubMenu82(int cedula){
	pnodoFila aux = listaFila->GetPrimero();
	if (aux->valor == cedula){
		cout<<"1.Comer en local (1% desc)"<<endl<<"2.Llevar (3% desc)"<<endl;
		char opt;
		cin >> opt;
		switch(opt) {
    	case '1' :
    		{
    			cout<<"Productos comprados: "<<endl;
    			aux->listaComp->Mostrar();
    			cout<<"Precio (Sin desc): "<<endl;
    			cout<<aux->listaComp->CalcularPrecio()<<endl;
    			cout<<"Precio (Con desc): "<<endl;
    			int precioFin = aux->listaComp->CalcularPrecio();
    			precioFin = precioFin - ((precioFin/100)*1);
    			cout<<precioFin<<endl;
    			ofstream archivo_salida("Fact"+to_string(cedula)+".txt"); 
    				if (!archivo_salida.is_open()) { 
        				cerr << "Error generando el archivo." <<endl; 
    				} 
    				archivo_salida << "\t.:Factura del cliente:."<<endl<<endl<<endl;
    				archivo_salida <<"Cedula: "<<cedula <<"\n"<<aux->listaComp->Mostrar()<<"\n Total: "<<precioFin<<"\n"<<endl<<endl; 

    				archivo_salida.close(); 
					cout << "Factura generada";
				/*	int FactAct = aux->listaComp->CalcularPrecio();
					int FactGra = FacturaGrande->listaComp->CalcularPrecio();
					int FactPeq = FacturaPequena->listaComp->CalcularPrecio();
					if (FacturaGrande == NULL || FacturaPequena == NULL){
						FacturaGrande = aux;
						FacturaPequena = aux;
						FacturaGrande->valor = cedula;
						FacturaPequena->valor = cedula;
					} else {
						if (aux->listaComp->CalcularPrecio() > FacturaGrande->listaComp->CalcularPrecio()){
							FacturaGrande = aux;
							FacturaGrande->valor = cedula;
						}
						if (aux->listaComp->CalcularPrecio() < FacturaPequena->listaComp->CalcularPrecio()){
							FacturaPequena = aux;
							FacturaPequena->valor = cedula;
						}
					}*/
				
					listaFila->BorrarInicio();
						Menu();
			}
    	case '2' :
    		{
    			cout<<"Productos comprados: "<<endl;
    			aux->listaComp->Mostrar();
    			cout<<"Precio (Sin desc): "<<endl;
    			cout<<aux->listaComp->CalcularPrecio()<<endl;
    			cout<<"Precio (Con desc): "<<endl;
    			int precioFin = aux->listaComp->CalcularPrecio();
    			precioFin = precioFin - ((precioFin/100)*3);
    			cout<<precioFin<<endl;
    			ofstream archivo_salida("Fact"+to_string(cedula)+".txt"); 
    				if (!archivo_salida.is_open()) { 
        				cerr << "Error generando el archivo." <<endl; 
    				} 
    				archivo_salida << "\t.:Factura del cliente:."<<endl<<endl<<endl;
    				archivo_salida <<"Cedula: "<<aux->valor <<"\n"<<aux->listaComp->Mostrar()<<"\n Total: "<<precioFin<<"\n"<<endl<<endl; 

    				archivo_salida.close(); 
					cout << "Factura generada";
					//int FactAct = aux->listaComp->CalcularPrecio();
					//int FactGra = FacturaGrande->listaComp->CalcularPrecio();
					//int FactPeq = FacturaPequena->listaComp->CalcularPrecio();
					//if (FacturaGrande == NULL || FacturaPequena == NULL){
					//	FacturaGrande = aux;
					//	FacturaPequena = aux;
					//} else {
					//	if (FactAct > FactGra){
					//		FacturaGrande = aux;
					//	} else {
					//		
					//	}
					//	if (FactAct < FactPeq){
					//		FacturaPequena = aux;
					//	} else{
					//		
					//	}
					//}
				
					listaFila->BorrarInicio();
						Menu();
			}
    	default:
			{ 
    		cout<<"!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
    		Menu();
			break;
			}
	}
}
}


void cargarArchivo::Menu(){
	while(true){
	    cout << endl << "----------------------------" << endl;
        cout << endl << "      Menu Principal  " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Leer Archivos"<<endl;
		cout << "2. Insertar"<<endl;
		cout << "3. Eliminar"<<endl;
		cout << "4. Buscar"<<endl;
		cout << "5. Modificar"<<endl;
		cout << "6. Reportes1"<<endl;
		cout << "7. Reportes2"<<endl;
		cout << "8. Comprar"<<endl;
		cout << "9. Salir"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: ";
		
		char opt;
		cin >> opt;
    
    switch(opt) {
    	case '1' : 
			SubMenu1();
			Menu();
			break;
    	case '2':
    		SubMenu2();
    		Menu();
    		break;
    	case '3':
    		//SubMenu3();
    		cout<<"\n\t .:FUNCION ELIMINAR NO INCLUIDA EN LA PROGRA:."<<endl<<endl<<endl;
    		Menu();
			break;
    	case '4':
    		SubMenu4();
    		Menu();
    		break;
    	case '5':
    		SubMenu5();
    		Menu();
			break;
		case '6':
    		SubMenu6();
    		Menu();
			break;
		case '7':	
			SubMenu7();
			Menu();
			break;
		case '8':	
			SubMenu8();
			Menu();
			break;
		case '9':
    		cout<<endl<<endl<<endl<<"##################      Good Bye!!     ####################"<<endl;
    		exit(1337);
			break;		
    default: 
    cout<<"!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
	Menu();
	}
	break;
	}


}

//int main(){
//	cout<<"*************PROGRA #2************************"<<endl;
//	cout<<"\nIntegrantes:\nGustavo Vargas Ramirez   --- 200409141 \nGabriel Campos Gutierrez --- 2023093692"<<endl;
//	cout<<endl<<"*********************************************************************************"<<endl<<endl;	
//	cargarArchivo Inicio;
//	Inicio.cargaInicial();
//	Inicio.listaCliente->ImprimirArbol(Inicio.listaCliente->raiz);
//	Inicio.Menu();
//
// 
//    cout<<"###########################################################"<<endl;
//	cout<<"################## PROGRAMA FINALIZADO ####################"<<endl;
//	cout<<"###########################################################"<<endl;
//
//	return 0;
//}
