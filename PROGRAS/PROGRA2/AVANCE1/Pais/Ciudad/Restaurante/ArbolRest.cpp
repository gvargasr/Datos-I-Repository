#include <iostream>

using namespace std;

class Nodo {
  int codRest;
  Nodo *padre;
  Nodo *Hizq;
  Nodo *Hder;
  int color;
  string nombreRest;
  
  friend class ArbolRN;
};

typedef Nodo *NodoPtr;

class ArbolRN {
   private:
  NodoPtr Raiz;
  NodoPtr TNULL;

  void initializeNULLNode(NodoPtr nodo, NodoPtr padre) {
    nodo->codRest = 0;
    nodo->padre = padre;
    nodo->Hizq= nullptr;
    nodo->Hder = nullptr;
    nodo->color = 0;
    nodo ->nombreRest = "";
  }
  
  void insertarBalanceado(NodoPtr NodoEva) {
    NodoPtr ucodRest;
    while (NodoEva->padre->color == 1) {
      if (NodoEva->padre == NodoEva->padre->padre->Hder) {
        ucodRest = NodoEva->padre->padre->Hizq;
        if (ucodRest->color == 1) {
          ucodRest->color = 0;
          NodoEva->padre->color = 0;
          NodoEva->padre->padre->color = 1;
          NodoEva = NodoEva->padre->padre;
        } else {
          if (NodoEva == NodoEva->padre->Hizq) {
            NodoEva = NodoEva->padre;
            RotacionDerecha(NodoEva);
          }
          NodoEva->padre->color = 0;
          NodoEva->padre->padre->color = 1;
          RotacionIzquierda(NodoEva->padre->padre);
        }
      } else {
        ucodRest = NodoEva->padre->padre->Hder;

        if (ucodRest->color == 1) {
          ucodRest->color = 0;
          NodoEva->padre->color = 0;
          NodoEva->padre->padre->color = 1;
          NodoEva = NodoEva->padre->padre;
        } else {
          if (NodoEva == NodoEva->padre->Hder) {
            NodoEva = NodoEva->padre;
            RotacionIzquierda(NodoEva);
          }
          NodoEva->padre->color = 0;
          NodoEva->padre->padre->color = 1;
          RotacionDerecha(NodoEva->padre->padre);
        }
      }
      if (NodoEva == Raiz) {
        break;
      }
    }
    Raiz->color = 0;
  }
  
  NodoPtr Busqueda(NodoPtr nodo, int numbuscado) {
    if (nodo == TNULL || numbuscado == nodo->codRest) {
      return nodo;
    }

    if (numbuscado < nodo->codRest) {
      return Busqueda(nodo->Hizq, numbuscado);
    }
    return Busqueda(nodo->Hder, numbuscado);
  }
  
  bool BusquedaBool(NodoPtr nodo, int numbuscado) {
    if (nodo == TNULL || numbuscado == nodo->codRest) {
      return true;
    } else if (nodo->Hizq==nullptr&&nodo->Hder==nullptr&&numbuscado != nodo->codRest){
    	return false;
	}

    if (numbuscado < nodo->codRest) {
      return BusquedaBool(nodo->Hizq, numbuscado);
    }
    return BusquedaBool(nodo->Hder, numbuscado);
  }
  
  void rbModificar(NodoPtr uRaiz, NodoPtr vValor) {
    if (Raiz->padre == nullptr) {
      Raiz = vValor;
    } else if (uRaiz == uRaiz->padre->Hizq) {
      uRaiz->padre->Hizq = vValor;
    } else {
      uRaiz->padre->Hder = vValor;
    }
    vValor->padre = uRaiz->padre;
  }
  
  
  void MostrarRN(NodoPtr raiz, string indent, bool ultimo) {
    if (raiz != TNULL) {
      cout << indent;
      if (ultimo) {
        cout << "Derecha----";
        indent += "   ";
      } else {
        cout << "Izquierda----";
        indent += "|  ";
      }

      string sColor = raiz->color ? "Rojo" : "Negro";
      cout << raiz->codRest << "(" << sColor << ")" << "Nombre:" << raiz->nombreRest << endl;
      MostrarRN(raiz->Hizq, indent, false);
      MostrarRN(raiz->Hder, indent, true);
    }
  }
  
  public:
    ArbolRN() {
    TNULL = new Nodo;
    TNULL->color = 0;
    TNULL->Hizq = nullptr;
    TNULL->Hder = nullptr;
    Raiz = TNULL;
  }
  
  void RotacionIzquierda(NodoPtr nodo) {
    NodoPtr y = nodo->Hder;
    nodo->Hder = y->Hizq;
    if (y->Hizq != TNULL) {
      y->Hizq->padre = nodo;
    }
    y->padre = nodo->padre;
    if (nodo->padre == nullptr) {
      this->Raiz = y;
    } else if (nodo == nodo->padre->Hizq) {
      nodo->padre->Hizq = y;
    } else {
      nodo->padre->Hder = y;
    }
    y->Hizq = nodo;
    nodo->padre = y;
  }

  void RotacionDerecha(NodoPtr nodo) {
    NodoPtr y = nodo->Hizq;
    nodo->Hizq = y->Hder;
    if (y->Hder != TNULL) {
      y->Hder->padre= nodo;
    }
    y->padre = nodo->padre;
    if (nodo->padre == nullptr) {
      this->Raiz = y;
    } else if (nodo == nodo->padre->Hder) {
      nodo->padre->Hder = y;
    } else {
      nodo->padre->Hizq= y;
    }
    y->Hder = nodo;
    nodo->padre = y;
  }

  void insertar(int codRestnuevo, string nombrenuevo) {
  	NodoPtr temp = BusquedaM(codRestnuevo);
  	if (temp->codRest==codRestnuevo){
  		cout<<"Codigo Repetido"<<endl;
	  }
	  else {
	  	NodoPtr nodo = new Nodo;
    nodo->padre = nullptr;
    nodo->codRest = codRestnuevo;
    nodo->Hizq = TNULL;
    nodo->Hder = TNULL;
    nodo->color = 1;
    nodo->nombreRest = nombrenuevo;

    NodoPtr y = nullptr;
    NodoPtr x = this->Raiz;

    while (x != TNULL) {
      y = x;
      if (nodo->codRest < x->codRest) {
        x = x->Hizq;
      } else {
        x = x->Hder;
      }
    }

    nodo->padre = y;
    if (y == nullptr) {
      Raiz = nodo;
    } else if (nodo->codRest< y->codRest) {
      y->Hizq = nodo;
    } else {
      y->Hder = nodo;
    }

    if (nodo->padre== nullptr) {
      nodo->color = 0;
      return;
    }

    if (nodo->padre->padre == nullptr) {
      return;
    }

    insertarBalanceado(nodo);
	  }
  }

  NodoPtr getRaiz() {
    return this->Raiz;
  }
  
  NodoPtr BusquedaM(int numbuscado) {
    return Busqueda(this->Raiz, numbuscado);
  }
  
  void MostrarRN() {
    if (Raiz) {
      MostrarRN(this->Raiz, "", true);
    }
  }
  
  bool BusquedaB(int numbuscado) {
    return BusquedaBool(this->Raiz, numbuscado);
  }
  
  void ModificarNodo(int numbusqueda)
  {
  	NodoPtr aux = BusquedaM(numbusqueda);
  	if (aux->codRest!=numbusqueda){
  		cout<<"Codigo Invalido"<<endl;
	  } else {	
		string nuevonom;
 	 	string tempnom;
		cout<<"Inserte el nombre al cual va a cambiar:";
  		cin>>nuevonom;
  		tempnom = aux->nombreRest;
  		aux->nombreRest = nuevonom;
  		cout<<"Nuevo nombre: "<<nuevonom<<" Nombre antiguo: "<<tempnom<<endl;
	  }
	}
	void BuscarNodo (int numbusqueda){
	NodoPtr aux = BusquedaM(numbusqueda);
  	if (aux->codRest!=numbusqueda){
  		cout<<"Codigo Invalido"<<endl;
	  } else {	
		cout<<"Restaurante:"<<endl;
		cout<<"- Codigo: "<<aux->codRest<<endl;
		cout<<"- Nombre: "<<aux->nombreRest<<endl;
	  }
  	}

};

/*int main() {
  ArbolRN ARN;
  ARN.insertar(50, "Macdonal");
  ARN.insertar(17, "Bk");
  ARN.insertar(9, "Papa Johns");
  ARN.BuscarNodo(50);
  cout << endl;
     
}*/


