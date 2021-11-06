#ifndef VINO_H_INCLUDED
#define VINO_H_INCLUDED
#include <string>
using namespace std;

typedef struct{
    long id;
    char etiqueta[50];
    char bodega[50];
    char segmentoDelVino[50];
    char varietal[15];
    int anioCosecha;
    char terroir[50];
    bool nulo;
    int veceSeleccionado ;

}Vino;

Vino* crearVino(long id,char* etiqueta,char* bodega,char* segmentoDelVino,char* varietal,int anioCosecha,char* terroir);
//Getters
long getIdV(Vino* v);
char* getEtiqueta(Vino* v);
char* getBodega(Vino* v);
char* getSegmentoDelVino(Vino* v);
char* getVarietal(Vino* v);
int getAnioCosecha(Vino* v);
char* getTerroir(Vino* v);
int getveceSeleccionado(Vino* v);
//Setters
void setIdV(Vino* v,long id);
void setEtiqueta(Vino* v,char* etiqueta);
void setBodega(Vino* v,char* bodega);
void setSegmentoDelVino(Vino* v,char* segmentoDelVino);
void getVarietal(Vino* v,char* varietal);
void setAnioCosecha(Vino* v,int anioCosecha);
void setTerroir(Vino* v,char* terroir);
void setVecesSeleccionado(Vino* v, int n);
//Funciones
void mostrarVino(Vino* v);



#endif // VINO_H_INCLUDED
