#ifndef BENEFICIO_H_INCLUDED
#define BENEFICIO_H_INCLUDED

#include "Lista.h"

struct Beneficio{
    long idUsuario;
    int mesSeleccion;
    int anioSeleccion;
    int seleccionVinos[6];
};


//PRE:
Beneficio* crearBeneficio(long idUsuario, int mesSeleccion, int anioSeleccion, int seleccionVinos[6] );
//POST:
void mostrarBeneficio(Beneficio* b);
//GETTERS
//PRE: Recibe el id del usuario del beneficio creado
long getIdUsuario(Beneficio* b);
//POST: Retorna el id del usuario

//PRE: Recibe el mes del beneficio creado
int getMesSeleccion(Beneficio* b);
//POST: Retorna el mes del beneficio

//PRE: Recibe el año del beneficio creado
int getAnioSeleccion(Beneficio* b);
//POST: Retorna el año del beneficio

//PRE: Recibe los id de vinos seleccionados por el usuario del beneficio creado
int* getSeleccionVinos(Beneficio* b);
//POST: Retorna la lista de vinos

//SETTERS
//PRE: Recibe el id del usuario del beneficio creado y otro id
void setIdUsuario(Beneficio* b, long nuevoIdUsuario);
//POST: Se cambia el id del usuario

//PRE: Recibe el mes del beneficio creado y otro mes distinto
void setMesSeleccion(Beneficio* b, int nuevoMesSeleccion);
//POST: Se cambia el mes de la seleccion

//PRE: Recibe el año del beneficio creado y otro año distinto
void setAnioSeleccion(Beneficio* b, int nuevoAnioSeleccion);
//POST: Se cambia el año del beneficio

//PRE: Recibe la lista de las ID de vinos seleccionados por el usuario y una nueva lista de ID de vinos
void setSeleccionVinos(Beneficio* b, int nuevaSeleccionVinos[6]);
//POST: Se cambia la lista de vinos por una nueva

//PRE: Se pasa por parámetro un beneficio previamente creado
void eliminarBeneficio(Beneficio* b);
//POST: Se elimina el beneficio


#endif // BENEFICIO_H_INCLUDED
