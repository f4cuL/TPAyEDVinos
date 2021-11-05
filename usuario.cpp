#include <iostream>
#include <string.h>
#include <string>
#include "usuario.h"
using namespace std;

Usuario* crearUsuario(long id,char* nombre,char* direccion,int edad){
    Usuario* u = (Usuario*)malloc(sizeof(*u));
    u->id = id;
    strcpy(u->nombre,nombre);
    strcpy(u->direccion,direccion);
    u->edad = edad;
    return u;
}
long getId(Usuario* u){
    return u->id;
}
char* getNombre(Usuario* u){
    return u->nombre;
}
char* getDireccion(Usuario* u){
    return u->direccion;
}
int getEdad(Usuario* u){
    return u->edad;
}
void setId(Usuario* u,long id){
    u->id = id;
}
void setNombre(Usuario* u,char* nombre){
    strcpy(u->nombre,nombre);
}
void setDireccion(Usuario* u, char* direccion){
    strcpy(u->direccion,direccion);
}
void setEdad(Usuario* u, int edad){
    u->edad = edad;
}

void MostraUsuario(Usuario* u){
    cout<<"-----------------------------------"<<endl;
    cout<<"el id del usuario es: "<<u->id<<endl;
    cout<<"el nombre del usuario es: "<<u->nombre<<endl;
    cout<<"La direccion del usuario es: "<<u->direccion<<endl;
    cout<<"la edad del usuario es: "<<u->edad<<endl;
}
