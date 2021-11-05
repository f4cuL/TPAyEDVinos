#ifndef USUARIO_HPP_INCLUDED
#define USUARIO_HPP_INCLUDED

typedef struct Usuario{
    long id;
    std::string nombre;
    std::string direccion;
    int edad;
}Usuario;

Usuario* crearUsuario(long id,string nombre,string direccion,int edad);
//Getters
long getId(Usuario* u);
string getNombre(Usuario* u);
string getDireccion(Usuario* u);
int getEdad(Usuario* u);
//Setters
void setId(Usuario* u,long id);
void setNombre(Usuario* u,string nombre);
void setDireccion(Usuario* u, string direccion);
void setEdad(Usuario* u, int edad);

#endif // USUARIO_HPP_INCLUDED
