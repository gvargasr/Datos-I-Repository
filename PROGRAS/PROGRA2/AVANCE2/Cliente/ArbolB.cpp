#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class Pagina_Cliente {
	public:
		int claves [5];
		string nombre [5];
		int compras[5]; 
		Pagina_Cliente* Ramas[5];
		Pagina_Cliente* rama1; 
		Pagina_Cliente* rama2; 
		Pagina_Cliente* rama3; 
		Pagina_Cliente* rama4; 
		Pagina_Cliente* rama5;
		int Cuenta;
		
	
    Pagina_Cliente() : Cuenta(0) {
        for (int i = 0; i < 5; i++) {
            claves[i] = 0;
			compras[i] = 0; 
            nombre[i] = "";
        }
        rama1 = rama2 = rama3 = rama4 = rama5 = NULL;
        Ramas[0] = rama1;
        Ramas[1] = rama2;
        Ramas[2] = rama3;
        Ramas[3] = rama4;
        Ramas[4] = rama5;
    }

    // Constructor con parámetros
    Pagina_Cliente(int pCedula, string pNombre) : Pagina_Cliente() {
        claves[1] = pCedula;
        nombre[1] = pNombre;
        compras[1] = 0; 
        Cuenta = 1;
    }
    
    int obtenerCuenta() const {
        return Cuenta;
    }

    ~Pagina_Cliente() {
    	        for (int i = 0; i < 5; i++) {
            claves[i] = 0; 
            nombre[i] = "";
            compras[i] = 0; 
        }
        rama1 = rama2 = rama3 = rama4 = rama5 = NULL;
        Ramas[0] = rama1;
        Ramas[1] = rama2;
        Ramas[2] = rama3;
        Ramas[3] = rama4;
        Ramas[4] = rama5;
    }
		
		
};

typedef Pagina_Cliente* puntero_Cliente;

class ArbolB{
	public :
	Pagina_Cliente* raiz;
	
	ArbolB() {
        raiz = new Pagina_Cliente();
    }
	
	void Empujar(int C1, string nombre, Pagina_Cliente*& R, bool& EmpujaArriba, int& Mdna, Pagina_Cliente*& Xr);
    void InsertarClave(int C1, string nombre, Pagina_Cliente*& raiz);
    void BuscarNodo(int Clave, Pagina_Cliente*& P, bool& Encontrado, int& K);
    void ImprimirArbol(Pagina_Cliente*& raiz);
    void MeterHoja(int X, string nombre, Pagina_Cliente*& Xder, Pagina_Cliente*& P, int K);
    void DividirNodo(int X, string nombre, Pagina_Cliente*& Xder, Pagina_Cliente*& P, int& K, int& Mda, Pagina_Cliente*& Mder);
    bool Search(int clave, Pagina_Cliente* raiz);
	void Modificar(int clave, string nombre, Pagina_Cliente* raiz);
	void inOrderTraversal(Pagina_Cliente* raiz, ofstream& outFile);
	void saveToFile(const string& filename);
	string SearchNodo(int clave, Pagina_Cliente* raiz);
	string SearchContador(int clave, Pagina_Cliente* raiz);
    bool CompraDeCliente(int clave, Pagina_Cliente* raiz);
    bool SearchC(int clave, Pagina_Cliente* raiz);


    
    friend Pagina_Cliente;
};

void ArbolB::Modificar(int clave, string nombre, Pagina_Cliente* raiz) {
    if (raiz == NULL) {
        cout<<".:Cliente con cedula "<<clave<<" no se encuentra:."<<endl<<endl;
    //    return raiz;
    return;
    }

    bool Encontrado = false;
    int K = 0;
    BuscarNodo(clave, raiz, Encontrado, K);

    if (Encontrado) {
    	raiz->nombre[K] = nombre;
        cout<<".:Cliente modificado:.\n"<<"Cedula: "<<raiz->claves[K]<<"\nNombre: "<<raiz->nombre[K]<<endl<<endl;
    //    return raiz;
    return;
    } else {
        Modificar(clave, nombre, raiz->Ramas[K]); // Buscar en la rama adecuada
    }
}

bool ArbolB::CompraDeCliente(int clave, Pagina_Cliente* raiz) {
    if (raiz == NULL) {
        cout<<".:Cliente con cedula "<<clave<<" no se encuentra:."<<endl<<endl;
        return false;
    }

    bool Encontrado = false;
    int K = 0;
    BuscarNodo(clave, raiz, Encontrado, K);

    if (Encontrado) {
    	if(raiz->compras[K] != 0){
        cout<<"\n.:Cliente encontrado:.\n"<<"Cedula: "<<raiz->claves[K]<<"\nNombre: "<<raiz->nombre[K]<<"\nHa comprado: "<<raiz->compras[K]<<" veces."<<endl<<endl;
        return true;
        }else{
        	cout<<"Aun no se han realizado compras."<<endl<<endl;
        	return true;
		}
    } else {
        CompraDeCliente(clave, raiz->Ramas[K]); // Buscar en la rama adecuada
    }
}


bool ArbolB::Search(int clave, Pagina_Cliente* raiz) {
    if (raiz == NULL) {
        cout<<".:Cliente con cedula "<<clave<<" no se encuentra:."<<endl<<endl;
        return false;
    }

    bool Encontrado = false;
    int K = 0;
    BuscarNodo(clave, raiz, Encontrado, K);

    if (Encontrado) {
        cout<<"\n.:Cliente encontrado:.\n"<<"Cedula: "<<raiz->claves[K]<<"\nNombre: "<<raiz->nombre[K]<<endl<<endl;
        return true;
    } else {
        Search(clave, raiz->Ramas[K]); // Buscar en la rama adecuada
    }
}

bool ArbolB::SearchC(int clave, Pagina_Cliente* raiz) {
    if (raiz == NULL) {
        cout<<".:Cliente con cedula "<<clave<<" no se encuentra:."<<endl<<endl;
        return false;
    }

    bool Encontrado = false;
    int K = 0;
    BuscarNodo(clave, raiz, Encontrado, K);

    if (Encontrado) {
    	    raiz->compras[K]++;
        cout<<"\n.:Cliente encontrado:.\n"<<"Cedula: "<<raiz->claves[K]<<"\nNombre: "<<raiz->nombre[K]<<endl<<endl;
        return true;
    } else {
        SearchC(clave, raiz->Ramas[K]); // Buscar en la rama adecuada
    }
}

string ArbolB::SearchContador(int clave, Pagina_Cliente* raiz) {
    if (raiz == NULL) {
    //    cout<<".:Cliente con cedula "<<clave<<" no se encuentra:."<<endl<<endl;
        return "";
    }

    bool Encontrado = false;
    int K = 0;
    BuscarNodo(clave, raiz, Encontrado, K);

    if (Encontrado) {
    //    cout<<".:Cliente encontrado:.\n"<<"Cedula: "<<raiz->claves[K]<<"\nNombre: "<<raiz->nombre[K]<<endl<<endl;
        return raiz->nombre[K];
    } else {
        SearchContador(clave, raiz->Ramas[K]); // Buscar en la rama adecuada
    }
}

string ArbolB::SearchNodo(int clave, Pagina_Cliente* raiz) {
    if (raiz == NULL) {
    //    cout<<".:Cliente con cedula "<<clave<<" no se encuentra:."<<endl<<endl;
        return "";
    }

    bool Encontrado = false;
    int K = 0;
    BuscarNodo(clave, raiz, Encontrado, K);

    if (Encontrado) {
    //    cout<<".:Cliente encontrado:.\n"<<"Cedula: "<<raiz->claves[K]<<"\nNombre: "<<raiz->nombre[K]<<endl<<endl;
        return raiz->nombre[K];
    } else {
        SearchNodo(clave, raiz->Ramas[K]); // Buscar en la rama adecuada
    }
}






void ArbolB::BuscarNodo(int Clave, Pagina_Cliente*& P, bool& Encontrado, int& K) {   
	if(Clave < P->claves[1]){
		Encontrado = false;
		K=0;
	}else{
		K = P->Cuenta; 
		while(Clave < P->claves[K] && K > 1){
			K=K-1;
		}
		if(Clave==P->claves[K]){
			Encontrado = true;
		}else{
			Encontrado = false;
		}
	}
}




void ArbolB::InsertarClave(int C1, string nombre, Pagina_Cliente*& raiz) {
	bool EmpujaArriba = false;
    int X = 0;
    Pagina_Cliente* Xr = NULL;
    Pagina_Cliente* P = NULL;
    Empujar(C1, nombre, raiz, EmpujaArriba, X, Xr);
    
    if (EmpujaArriba) {
        Pagina_Cliente* P = new Pagina_Cliente();
        P->Cuenta = 1;
        P->claves[1] = X;
        P->nombre[1] = nombre;
        P->Ramas[0] = raiz;
        P->Ramas[1] = Xr;
        raiz = P;
    }
}

void ArbolB::Empujar(int C1, string nombre, Pagina_Cliente*& R, bool& EmpujaArriba, int& Mdna, Pagina_Cliente*& Xr) { 

    if (R == NULL) {
        EmpujaArriba = true;
        Mdna = C1;
        Xr = NULL;
    } else {
    	bool Esta = false; 
    	int K = 0;
		BuscarNodo(C1, R, Esta, K);   
        if (Esta){
            cout<<"Cliente "<<C1<<":"<<nombre<<" no fue agregado."<<endl;
            EmpujaArriba = false;
            return;
		}else{
			Empujar(C1, nombre, R->Ramas[K], EmpujaArriba, Mdna, Xr);
			  
        	if (EmpujaArriba) {
          		if (R->Cuenta < 4) {
            	//	cout<<"K cuenta NO llena "<<K<<endl;
           		EmpujaArriba = false;
           		MeterHoja(Mdna, nombre, Xr, R, K);
            	}else{
            	//	cout<<"K cuenta llena "<<K<<endl;
            	EmpujaArriba = true;
            	DividirNodo(Mdna, nombre, Xr, R, K, Mdna, Xr);
            	}
        	}
        }
	}        
}


 void ArbolB::inOrderTraversal(Pagina_Cliente* raiz, ofstream& outFile) {
        if (raiz != nullptr) {
            for (int i = 0; i < raiz->Cuenta; i++) {
                inOrderTraversal(raiz->Ramas[i], outFile);
                outFile << raiz->claves[i + 1] << " " << raiz->nombre[i + 1] << endl;
            }
            inOrderTraversal(raiz->Ramas[raiz->Cuenta+1], outFile);
        }
    }

void ArbolB::saveToFile(const string& filename) {
    ofstream outFile(filename);
    outFile << "\t.:REPORTE LISTA CLIENTES:."<<endl<<endl<<endl;
    if (outFile.is_open()) {
        inOrderTraversal(raiz, outFile);
        outFile.close();
        cout << "Reporte generado"<< endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}



void ArbolB::ImprimirArbol(Pagina_Cliente*& raiz) {
    if (raiz != NULL) {
        for (int i = 0; i < raiz->Cuenta; ++i) {
            ImprimirArbol(raiz->Ramas[i]);
            cout << raiz->claves[i + 1] << " " << raiz->nombre[i + 1] << endl;
        }
        ImprimirArbol(raiz->Ramas[raiz->Cuenta]); // Recursive call for the rightmost child
    }
}




void ArbolB::MeterHoja(int X, string nombre, Pagina_Cliente*& Xder, Pagina_Cliente*& P, int K) {
    for (int I = P->Cuenta; I >= K + 1; I--) {
        P->claves[I + 1] = P->claves[I];
        P->nombre[I + 1] = P->nombre[I];
        P->Ramas[I + 1] = P->Ramas[I];
    }

    P->claves[K + 1] = X;
    P->nombre[K + 1] = nombre;
    P->Ramas[K + 1] = Xder;
    P->Cuenta++;
 	cout<<"Cliente "<<X<<":"<<nombre<<" ha sido agregado."<<endl;

}

void ArbolB::DividirNodo(int X, string nombre, Pagina_Cliente*& Xder, Pagina_Cliente*& P, int& K, int& Mda, Pagina_Cliente*& Mder) {
    int Posmda;
    if (K <= 2) {
        Posmda = 2;
    } else {
        Posmda = 3;
    }

    Mder = new Pagina_Cliente();

    for (int I = Posmda + 1; I <= 4; I++) {
        Mder->claves[I - Posmda] = P->claves[I];
        Mder->nombre[I - Posmda] = P->nombre[I];
        Mder->Ramas[I - Posmda] = P->Ramas[I];
    }
	Mder->Cuenta = 4-Posmda;
    P->Cuenta = Posmda-1;

    if (K <= 2) {
        MeterHoja(X, nombre, Xder, P, K);  //inserta a la izq
        P->Cuenta--;
    } else {
        MeterHoja(X, nombre, Xder, Mder, K - Posmda);
    	Mda = P->claves[P->Cuenta];
    	Mder->Ramas[0] = P->Ramas[P->Cuenta];
    	P->Cuenta--;
	}	
		
}

/*

int main() {
    ArbolB* clientes = new ArbolB();
    clientes->InsertarClave(72, "hola1", clientes->raiz);
	clientes->InsertarClave(19, "hola2", clientes->raiz);
    clientes->InsertarClave(67, "hola3", clientes->raiz);
    clientes->InsertarClave(5, "hola4", clientes->raiz);
    clientes->InsertarClave(90, "hola5", clientes->raiz);
    clientes->InsertarClave(56, "hola6", clientes->raiz);
    clientes->InsertarClave(6, "hola7", clientes->raiz);
    clientes->InsertarClave(8, "hola8", clientes->raiz);
    clientes->InsertarClave(90, "hola9", clientes->raiz);
   
    clientes->InsertarClave(5, "hola10", clientes->raiz);
    clientes->InsertarClave(6, "hola11", clientes->raiz);
    clientes->InsertarClave(6, "hola12", clientes->raiz);
    clientes->InsertarClave(7, "hola13", clientes->raiz);

    clientes->InsertarClave(8, "hola", clientes->raiz);
    clientes->InsertarClave(16, "hola", clientes->raiz);
    clientes->InsertarClave(16, "hola", clientes->raiz);
    clientes->InsertarClave(16, "hola", clientes->raiz);
    clientes->InsertarClave(10, "hola", clientes->raiz);
    clientes->InsertarClave(16, "hola", clientes->raiz);
    clientes->InsertarClave(16, "hola", clientes->raiz);
    clientes->InsertarClave(4, "hola", clientes->raiz);
    clientes->InsertarClave(7, "hola", clientes->raiz);
    clientes->InsertarClave(8, "hola", clientes->raiz);
    clientes->InsertarClave(9, "hola", clientes->raiz);
    clientes->InsertarClave(88, "holatavo", clientes->raiz);
    clientes->InsertarClave(88, "holamundo", clientes->raiz);
    clientes->InsertarClave(10, "hola", clientes->raiz);
    clientes->InsertarClave(15, "hola", clientes->raiz);

	clientes->Search(90,clientes->raiz);
	clientes->Search(15,clientes->raiz);
	clientes->Search(6,clientes->raiz);
	clientes->Search(88,clientes->raiz);
	clientes->ImprimirArbol(clientes->raiz);
    delete clientes;
    return 0;
}*/
