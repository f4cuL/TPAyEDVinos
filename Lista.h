#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "usuario.h"
#include "vino.h"
#include "beneficio.h"
using namespace std;
typedef struct Nodo{
    Vino* v;
    Usuario* u;
    Beneficio* b;
    struct Nodo* Siguiente;
}Nodo;

typedef struct Lista{
    Nodo* Primero;
    int Cantidad;
}Lista;

Lista* CrearLista();

//USUARIOS
Nodo* CrearNodoUsuario(Usuario* u);
void DestruirNodo(Nodo* nodo);
void InsertarPrimeroUsuario(Lista* lista ,Usuario* u);
void InsertarUltimo(Lista* lista , Usuario* u);
void InsertarDespues(int n , Lista* lista , Usuario* u);
Usuario* ObtenerUsuario(int n ,Lista* lista );
bool ElUsuarioExiste(long ID , Lista* lista);
void MostrarListaUsuarios(Lista* l1);

//VINOS
Nodo* CrearNodoVino(Vino* v,Nodo* prox);
void DestruirNodoVino(Nodo* nodo);
void InsertarPrimeroVino(Lista* lista ,Vino* v);
void InsertarUltimoVino(Lista* lista , Vino* v);
void InsertarDespuesVino(int n , Lista* lista , Vino* v);
Vino* ObtenerVino(int n ,Lista* lista);
bool ElVinoExiste(long IDV , Lista* lista);
void MostrarListaVino(Lista* l1);
void ranking_de_vinos(long IDV , Lista* lista);
void ordenamientoRanking(Lista* lista);

//BENEFICIOS
Nodo* CrearNodoBeneficio(Beneficio* b);
void DestruirNodo(Nodo* nodo);
void InsertarPrimeroBeneficio(Lista* lista ,Beneficio* b);
void InsertarUltimoBeneficio(Lista* lista , Beneficio* b);
void InsertarDespuesBeneficio(int n , Lista* lista , Beneficio* b);
Beneficio* ObtenerBeneficio(int n ,Lista* lista );
bool ElBeneficioExiste(long ID , Beneficio* b);
void MostrarListaBeneficios(Lista* l1);

//METODOS GENERALES
int ObtenerLongitud(Lista* lista);

void ElimarPrimero(Lista* lista);

void EliminarUltimo(Lista* lista);

void ELiminarElemento(int n , Lista* lista);

void Cambiador(Vino* v1 , Vino* v2);



#endif // LISTA_H_INCLUDED
