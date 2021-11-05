#include <iostream>
#include <string.h>
#include <string>
#include "Lista.h"
#include "beneficio.h"

using namespace std;

Beneficio* crearBeneficio(long idUsuario, int mesSeleccion, int anioSeleccion, int seleccionVinos[6]){
    Beneficio* b = (Beneficio*)malloc(sizeof(*b));
    setIdUsuario(b,idUsuario);
    setMesSeleccion(b , mesSeleccion);
    setAnioSeleccion(b , anioSeleccion);

    for(int i = 0; i<6 ; i++){
        b->seleccionVinos[i] = seleccionVinos[i];
    }
    return b;
}
//GETTERS
long getIdUsuario(Beneficio* b){
    return b->idUsuario;
}

int getMesSeleccion(Beneficio* b){
    return b->mesSeleccion;
}

int getAnioSeleccion(Beneficio* b){
    return b->anioSeleccion;
}

int* getSeleccionVinos(Beneficio* b){
    return b->seleccionVinos;
}

//SETTERS
void setIdUsuario(Beneficio* b, long nuevoIdUsuario){
    b->idUsuario = nuevoIdUsuario;
}

void setMesSeleccion(Beneficio* b, int nuevoMesSeleccion){
    b->mesSeleccion=nuevoMesSeleccion;
}

void setAnioSeleccion(Beneficio* b, int nuevoAnioSeleccion){
    b->anioSeleccion=nuevoAnioSeleccion;
}

//ELIMINAR
void eliminarBeneficio(Beneficio* b){
    delete b;
}

void mostrarBeneficio(Beneficio* b){
    cout << "-----BENEFICIO DE VINOS-----" <<endl;
    cout << "ID Usuario: " << b->idUsuario << endl;
    cout << "Mes de seleccion: " << b->mesSeleccion << endl;
    cout << "Anio de seleccion: " << b->anioSeleccion << endl;
    cout << "IDs de vinos seleccionados: " << endl;
    for(int i=0; i<6; i++){
        cout << b->seleccionVinos[i] << " - " << endl;
    }
    cout << endl;

}
