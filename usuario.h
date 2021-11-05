#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <string>
using namespace std;
struct Usuario{
    long id;
    char nombre[50];
    char direccion[50];
    int edad;
};

Usuario* crearUsuario(long id,char* nombre,char* direccion,int edad);
//Getters
long getId(Usuario* u);
char* getNombre(Usuario* u);
char* getDireccion(Usuario* u);
int getEdad(Usuario* u);
//Setters
void setId(Usuario* u,long id);
void setNombre(Usuario* u,char* nombre);
void setDireccion(Usuario* u, char* direccion);
void setEdad(Usuario* u, int edad);

void MostraUsuario(Usuario* u);

#endif // USUARIO_H_INCLUDED
