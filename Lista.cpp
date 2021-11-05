#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include "Lista.h"
#include "usuario.h"
#include "vino.h"
#include "beneficio.h"
using namespace std;

Lista* CrearLista(){
    Lista* lista = (Lista*)malloc(sizeof(*lista));
    lista->Primero = NULL;
    lista->Cantidad = 0;
    return lista;
}
//a partir de aqui generamos los metodos para los nodos vino y usuario
//creamos el nodo para usuario
Nodo* CrearNodoUsuario(Usuario* u){
    //creamos un nodo , y le reservamos la memoria con el malloc
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    //rellenamos el nodo creado con los atributos del usuario que recibimos por parametro.
    Usuario* aux = crearUsuario(getId(u),getNombre(u),getDireccion(u),getEdad(u));
    nodo->u = aux;
    //seteamos el siguiente como null
    nodo->Siguiente = NULL;
    return nodo;
}

void DestruirNodo(Nodo* nodo){
    //liberamos memoria destruyendo el nodo pasado por parametro
    free(nodo);
}

void InsertarPrimero(Lista* lista ,Usuario* u){
    Nodo* nodo = CrearNodoUsuario(u);
    nodo->Siguiente = lista->Primero;
    lista->Primero = nodo;
    lista->Cantidad++;
}

void InsertarUltimo(Lista* lista , Usuario* u){
    Nodo* nodo = CrearNodoUsuario(u);
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
    Nodo* nodo = CrearNodoUsuario(u);
    if(lista->Primero == NULL){
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

Usuario* ObtenerUsuario(int n ,Lista* lista){
    if(lista->Primero == NULL){
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
            return puntero->u;
        }
    }
}

bool ElUsuarioExiste(long ID , Lista* lista){
    if(lista->Primero == NULL){
        return false;
    }else{
        Nodo* puntero = lista->Primero;
        while(getId(puntero->u)!= ID && puntero->Siguiente != NULL){
            puntero = puntero->Siguiente;
        }
        if(getId(puntero->u) != ID){
            return false;
        }else{
            return true;
        }
    }
}

void MostrarListaUsuarios(Lista* l1){
    Nodo* puntero = l1->Primero;
    while(puntero){
        MostraUsuario(puntero->u);
        puntero = puntero->Siguiente;
    }
}


//-------------------VINOS-----------------

//de aca empeiza vino
Nodo* CrearNodoVino(Vino* v){
    //creamos un nodo , y le reservamos la memoria con el malloc
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    //rellenamos el nodo creado con los atributos del usuario que recibimos por parametro.
    Vino* aux = crearVino(v->id,v->etiqueta,v->bodega,v->segmentoDelVino,v->varietal,v->anioCosecha,v->terroir);
    nodo->v = aux;
    //seteamos el siguiente como null
    nodo->Siguiente = NULL;
    return nodo;
}
void InsertarPrimeroVino(Lista* lista ,Vino* v){
    Nodo* nodo = CrearNodoVino(v);
    nodo->Siguiente = lista->Primero;
    lista->Primero = nodo;
    lista->Cantidad++;
}

void InsertarUltimoVino(Lista* lista , Vino* v){
    Nodo* nodo = CrearNodoVino(v);
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

void InsertarDespuesVino(int i , Lista* lista , Vino* v){
    Nodo* nodo = CrearNodoVino(v);
    if(lista->Primero == NULL){
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

Vino* ObtenerVino(int n ,Lista* lista){
    if(lista->Primero == NULL){
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
            return puntero->v;
        }
    }
}

bool ElVinoExiste(long IDV , Lista* lista){
    if(lista->Primero == NULL){
        return false;
    }else{
        Nodo* puntero = lista->Primero;
        while(getIdV(puntero->v)!= IDV && puntero->Siguiente != NULL){
            puntero = puntero->Siguiente;
        }
        if(getIdV(puntero->v) != IDV){
            return false;
        }else{
            return true;
        }
    }
}

void MostrarListaVino(Lista* l1){
    Nodo* puntero = l1->Primero;
    while(puntero){
        mostrarVino(puntero->v);
        puntero = puntero->Siguiente;
    }
}
//-----------------NUEVO------------
//EL RANKIN_DE_VINOS lo que hace es aumentar la variable "ranking" que esta en la estructura vinos
//siempre y cuando la lista este llena y se el IDV del vector sea igual a de la lista
void ranking_de_vinos(long IDV , Lista* lista){
    if(lista->Primero != NULL){
       Nodo* puntero = lista->Primero;
        while(getIdV(puntero->v)!= IDV && puntero->Siguiente != NULL){
            puntero = puntero->Siguiente;
        }
        if(getIdV(puntero->v)== IDV){
            puntero->v->veceSeleccionado = puntero->v->veceSeleccionado+1;
        }
    }
}


//por ultimo oredenamos con el "orenamiento burbuja" en base al la variable ranking
void ordenamientoRanking(Lista* lista){
    Nodo* nodo = lista->Primero;
    Nodo* nodoProx = nodo->Siguiente;
    int longitud=lista->Cantidad;

    for(int i=0;i<longitud;i++){
        for(int j=0;j<longitud-1;j++){
            if(getveceSeleccionado(nodo->v) < getveceSeleccionado(nodoProx->v)){
                Vino* v = nodo->v;
                nodo->v = nodoProx->v;
                nodoProx->v = v;
            }
            nodo = nodoProx;
            nodoProx = nodoProx->Siguiente;
        }
        nodo=lista->Primero;
        nodoProx = nodo->Siguiente;
    }
}

void Cambiador(Vino* v1 , Vino* v2){
    Vino* aux = v1;
    v1 = v2;
    v2 = aux;
}

//-------------BENEFICIOS--------------------

Nodo* CrearNodoBeneficio(Beneficio* b){
    //creamos un nodo , y le reservamos la memoria con el malloc
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    //rellenamos el nodo creado con los atributos del usuario que recibimos por parametro.
    Beneficio* aux = crearBeneficio(getIdUsuario(b),getMesSeleccion(b),getAnioSeleccion(b),getSeleccionVinos(b));
    nodo->b = aux;
    //seteamos el siguiente como null
    nodo->Siguiente = NULL;
    return nodo;
}

void InsertarPrimero(Lista* lista ,Beneficio* b){
    Nodo* nodo = CrearNodoBeneficio(b);
    nodo->Siguiente = lista->Primero;
    lista->Primero = nodo;
    lista->Cantidad++;
}

void InsertarUltimoBeneficio(Lista* lista , Beneficio* b){
    Nodo* nodo = CrearNodoBeneficio(b);
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


void InsertarDespuesBeneficio(int i , Lista* lista , Beneficio* b){
    Nodo* nodo = CrearNodoBeneficio(b);
    if(lista->Primero == NULL){
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

Beneficio* ObtenerBeneficio(int n ,Lista* lista){
    if(lista->Primero == NULL){
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
            return puntero->b;
        }
    }
}

bool ElBeneficioExiste(long ID , Lista* lista){
    if(lista->Primero == NULL){
        return false;
    }else{
        Nodo* puntero = lista->Primero;
        while(getIdUsuario(puntero->b)!= ID && puntero->Siguiente != NULL){
            puntero = puntero->Siguiente;
        }
        if(getIdUsuario(puntero->b) != ID){
            return false;
        }else{
            return true;
        }
    }
}

void MostrarListaBeneficios(Lista* l1){
    Nodo* puntero = l1->Primero;
    while(puntero){
        mostrarBeneficio(puntero->b);
        puntero = puntero->Siguiente;
    }
}

//--------------METODOS GENERALES------------
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
