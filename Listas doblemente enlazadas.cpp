// Listas doblemente enlazadas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> //libreria para entrada y salida de datos

using namespace std; //espacio de nombres estandar

struct nododoble {     //estructura para el nodo de la lista doblemente enlazada
	int dato;
	nododoble* siguiente; //puntero al siguiente nodo
	nododoble* anterior;  //puntero al nodo anterior
};

class listadoble {      //clase para la lista doblemente enlazada
private:
	nododoble* cabeza;   //puntero a la cabeza de la lista
public:
	listadoble() : cabeza(nullptr) {}   //constructor para inicializar la cabeza en null

	// insertar un nuevo nodo al inicio de la lista

	void insertarinicio(int valor) { 
		nododoble* nuevo = new nododoble;  //crear un nuevo nodo
		nuevo->dato = valor;              //asignar el valor al nodo
		nuevo->siguiente = cabeza;      //el siguiente nodo es la cabeza actual
		nuevo->anterior = nullptr;    //el nodo anterior es null
		if (cabeza != nullptr) {         //si la cabeza no es null
			cabeza->anterior = nuevo;    //asignar el nodo anterior de la cabeza al nuevo nodo
		}
		cabeza = nuevo;    //asignar la cabeza al nuevo nodo
	}

	//imprimer la lista de principio a fin 
	void imprimiradelante() {        //funcion par apoder imprim la lista
		nododoble* actual = cabeza;     //puntero para recorrer la lista
		cout << "lista (adelante): ";      
		while (actual != nullptr) {
			cout << actual->dato << "<->"; //imprimir el dato del nodo
			actual = actual->siguiente;  //mover al siguiente nodo
		}
		cout << "NULL" << endl;    //imprimir null al final de la lista
	}
	
	//imprime la lusta de fin a pricipio 
	void imprimiratras() {
		nododoble* actual = cabeza;  //puntero para recorrer la lista
		if (actual == nullptr) return; //si la lista esta vacia no hacer nada 
		//llegar al ultimo nodo 
		while (actual->siguiente != nullptr) {   //bucle para llegar al ultimo nodo
			actual = actual->siguiente;
		}
		cout << "lista (atras): ";  //imprimir el encabezado
		while (actual != nullptr) {
			cout << actual->dato << "<->";  //imprimir el dato del nodo
			actual = actual->anterior;    //mover al nodo anterior
		}
		cout << "NULL" << endl;   //imprimir null al final de la lista
	}
	//elimina el primer nodo que contenga el valor dado
	void eliminar(int valor) {
		nododoble* actual = cabeza;   //puntero para recorrer la lista
		while (actual != nullptr && actual->dato != valor) {      //bucle para buscar el nodo
			actual = actual->siguiente;   //mover al siguiente nodo
		}
		if (actual == nullptr) {       //si no se encuentra el nodo
			cout << "valor no encontrado" << endl;   //imprimir mensaje
			return;
		}
		if (actual->anterior != nullptr) {     //si no es el primer nodo
			actual->anterior->siguiente = actual->siguiente;    //asignar el siguiente nodo al nodo anterior
		}
		else {
			//se elimina la cabeza
			cabeza = actual->siguiente;  //asignar la cabeza al siguiente nodo
		}
		if (actual->siguiente != nullptr) {    //	si no es el ultimo nodo
			actual->siguiente->anterior = actual->anterior;    //asignar el nodo anterior al siguiente nodo
		}
		delete actual;
		cout << "valor eliminado" << endl;      //imprimir mensaje
	}
	//destructor para liberar la memoria de la lista
	~listadoble() {
		nododoble* actual = cabeza;    //puntero para recorrer la lista
		while (actual != nullptr) {    //bucle para recorrer la lista
			nododoble* siguiente = actual->siguiente;  //guardar el siguiente nodo
			delete actual;   //eliminar el nodo actual
			actual = siguiente;    //mover al siguiente nodo
		}
	
	}
};

int main()    //Funcion principal
{
	listadoble lista;      //crear un objeto de la clase listadoble
	lista.insertarinicio(20);   //insertar un nodo al inicio de la lista
	lista.insertarinicio(30);   //insertar un nodo al inicio de la lista
	lista.insertarinicio(40);   //insertar un nodo al inicio de la lista
	cout << "Lista doblemente encadenada: " << endl;    //imprimir la lista
	lista.imprimiradelante();    //imprimir la lista de adelante hacia atras
	lista.imprimiratras();      //imprimir la lista de atras hacia adelante

	lista.eliminar(30);        //eliminar el nodo con el valor 30
	cout << "Despues de eliminar 30: " << endl;  //imprimir la lista
	lista.imprimiradelante();    //imprimir la lista de adelante hacia atras
	lista.imprimiratras();  //imprimir la lista de atras hacia adelante

	return 0;  //retornar 0 para indicar que el programa se ejecuto correctamente
}
