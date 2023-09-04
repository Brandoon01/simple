#include <iostream>

using namespace std;

// Definición de la estructura Nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Función para insertar un elemento al final de la lista
void insertar(Nodo*& cabeza, int valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;

    if (cabeza == NULL) {
        cabeza = nuevoNodo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

// Función para imprimir la lista
void imprimir(Nodo* cabeza) {
    Nodo* actual = cabeza;
    int posicion = 0;

    while (actual != NULL) {
        cout << "Posicion " << posicion << ": " << actual->dato << endl;
        actual = actual->siguiente;
        posicion++;
    }
}

// Función para buscar un elemento en la lista
int buscar(Nodo* cabeza, int valor) {
    Nodo* actual = cabeza;
    int posicion = 0;

    while (actual != NULL) {
        if (actual->dato == valor) {
            return posicion;
        }
        actual = actual->siguiente;
        posicion++;
    }

    return -1; // Si el elemento no se encuentra en la lista
}

// Función para eliminar un elemento de la lista
void eliminar(Nodo*& cabeza, int valor) {
    if (cabeza == NULL) {
        return; // La lista está vacía, no se puede eliminar nada
    }

    if (cabeza->dato == valor) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        return;
    }

    Nodo* actual = cabeza;
    while (actual->siguiente != NULL && actual->siguiente->dato != valor) {
        actual = actual->siguiente;
    }

    if (actual->siguiente != NULL) {
        Nodo* temp = actual->siguiente;
        actual->siguiente = actual->siguiente->siguiente;
        delete temp;
    }
}

// Función para buscar y cambiar un elemento en la lista
void buscarYCambiar(Nodo* cabeza, int valorBuscado, int nuevoValor) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        if (actual->dato == valorBuscado) {
            actual->dato = nuevoValor;
        }
        actual = actual->siguiente;
    }
}

int main() {
    Nodo* cabeza = NULL;
    int opcion;

    do {
        cout << "Menu:" << endl;
        cout << "1. Insertar elemento" << endl;
        cout << "2. Imprimir lista" << endl;
        cout << "3. Buscar elemento" << endl;
        cout << "4. Eliminar elemento" << endl;
        cout << "5. Buscar y cambiar elemento" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int valor;
                cout << "Ingrese el valor a insertar: ";
                cin >> valor;
                insertar(cabeza, valor);
                break;
            }
            case 2: {
                cout << "Lista:" << endl;
                imprimir(cabeza);
                break;
            }
            case 3: {
                int valor;
                cout << "Ingrese el valor a buscar: ";
                cin >> valor;
                int posicion = buscar(cabeza, valor);
                if (posicion != -1) {
                    cout << "El elemento " << valor << " se encuentra en la posicion " << posicion << endl;
                } else {
                    cout << "El elemento no se encuentra en la lista." << endl;
                }
                break;
            }
            case 4: {
                int valor;
                cout << "Ingrese el valor a eliminar: ";
                cin >> valor;
                eliminar(cabeza, valor);
                break;
            }
            case 5: {
                int valorBuscado, nuevoValor;
                cout << "Ingrese el valor a buscar: ";
                cin >> valorBuscado;
                cout << "Ingrese el nuevo valor: ";
                cin >> nuevoValor;
                buscarYCambiar(cabeza, valorBuscado, nuevoValor);
                break;
            }
            case 6:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 0);

    // Liberar la memoria de la lista al salir del programa
    while (cabeza != NULL) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }

    return 0;
}
