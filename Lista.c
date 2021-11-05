#include "Lista.h"
#include <stdlib.h>
#include <string.h>


Lista CrearLista(Lista l1){
    l1 = new Lista();
    l1->Primero = NULL;
    l1->Cantidad = 0;
    return l1;
}

Nodo* CrearNodo(Usuario* u){
    //creamos un nodo , y le reservamos la memoria con el malloc
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    //rellenamos el nodo creado con los atributos del usuario que recibimos por parametro.
    nodo->u.id = u->id;
    nodo->u.edad = u->edad;
    strcpy(nodo->u.direccion , u->direccion );
    //seteamos el siguiente como null
    nodo->Siguiente = NULL;
    return nodo;
}

void DestruirNodo(Nodo* nodo){
    //liberamos memoria destruyendo el nodo pasado por parametro
    free(nodo);
}
void InsertarPrimero(Lista* lista ,Usuario* u){
    Nodo* nodo = CrearNodo(u);
    nodo->Siguiente = lista->Primero;
    lista->Primero = nodo;
    lista->Cantidad++;
}

void InsertarUltimo(Lista* lista , Usuario* u){
    Nodo* nodo = CrearNodo(u);
    Nodo* puntero = lista->Primero;
    if(lista->Primero == NULL){
        lista->Primero = nodo;
    }else{
        while(puntero->Siguiente){
            puntero = puntero->Siguiente;
        }
        puntero->Siguiente = nodo;
    }
    lista->Cantidad++;
}

void InsertarDespues(int i , Lista* lista , Usuario* u){
    Nodo* nodo = CrearNodo(u);
    if(lista->Primero = NULL){
        lista->Primero = nodo;
    }else{
        Nodo* puntero = lista->Primero;
        int posicion = 0;
        while(posicion < i && puntero->Siguiente){
            puntero = puntero->Siguiente;
            posicion++;
        }
        nodo->Siguiente = puntero->Siguiente;
        puntero->Siguiente = nodo;

    }
    lista->Cantidad++;
}

Usuario* ObtenerUsuario(int n ,Lista* lista , Usuario* u){
    if(lista->Primero = NULL){
        return NULL;
    }else{
        Nodo* puntero = lista->Primero;
        int posicion = 0;
        while(posicion < n &&  puntero->Siguiente){
            puntero = puntero->Siguiente;
            posicion++;
        }
        if(posicion != n){
            return NULL;
        }else{
            return &puntero->u;
        }
    }
}

int ObtenerLongitud(Lista* lista){
    return lista->Cantidad;
}

void ElimarPrimero(Lista* lista){
    if(lista->Primero){
        Nodo* eliminar = lista->Primero;
        lista->Primero = lista->Primero->Siguiente;
        DestruirNodo(eliminar);
        lista->Cantidad--;
    }
}

void EliminarUltimo(Lista* lista){
    if(lista->Primero){
        if(lista->Primero->Siguiente){
            Nodo* puntero = lista->Primero;
            while(puntero->Siguiente->Siguiente){
                puntero = puntero->Siguiente;
            }
            Nodo* eliminar = puntero->Siguiente;
            puntero->Siguiente = NULL;
            DestruirNodo(eliminar);
            lista->Cantidad--;
        }else{
            Nodo* eliminar = lista->Primero;
            lista->Primero = NULL;
            DestruirNodo(eliminar);
            lista->Cantidad--;
        }
    }
}

void ELiminarElemento(int n , Lista* lista){
    if(lista->Primero){
        if(n == 0){
            Nodo* eliminar = lista->Primero;
            lista->Primero = NULL;
            DestruirNodo(eliminar);
            lista->Cantidad--;
        }else if(n < lista->Cantidad){
            Nodo* puntero = lista->Primero;
            int posicion = 0;
            while(posicion < (n - 1)){
                puntero = puntero->Siguiente;
                posicion++;
            }
            Nodo* eliminar = puntero->Siguiente;
            puntero->Siguiente = eliminar->Siguiente;
            DestruirNodo(eliminar);
            lista->Cantidad--;
        }
    }
}
