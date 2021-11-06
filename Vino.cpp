#include <iostream>
#include "vino.h"
#include <string.h>
using namespace std;

Vino* crearVino(long id,char* etiqueta,char* bodega,char* segmentoDelVino,char* varietal,int anioCosecha,char* terroir){
    Vino* v = (Vino*)malloc(sizeof(Vino));
    v->id=id;
    v->anioCosecha=anioCosecha;
    strcpy(v->etiqueta,etiqueta);
    strcpy(v->bodega,bodega);
    strcpy(v->segmentoDelVino,segmentoDelVino);
    strcpy(v->varietal,varietal);
    strcpy(v->terroir,terroir);
    v->nulo = true;
    v->veceSeleccionado = 0;
    return v;
}

//Getters
long getIdV(Vino* v){
    return v->id;
}
char* getEtiqueta(Vino* v){
    return v->etiqueta;
}
char* getBodega(Vino* v){
    return v->bodega;
}
char* getSegmentoDelVino(Vino* v){
    return v->segmentoDelVino;
}
char* getVarietal(Vino* v){
    return v->varietal;
}
int getAnioCosecha(Vino* v){
    return v->anioCosecha;
}
char* getTerroir(Vino* v){
    return v->terroir;
}
bool esNulo(Vino* v){
    return v->nulo;
}
int getveceSeleccionado(Vino* v){
    return v->veceSeleccionado;
}
//Setters
void setIdV(Vino* v,long id){
    v->id = id;
}
void setEtiqueta(Vino* v,char* etiqueta){
    strcpy(v->etiqueta,etiqueta);
}
void setBodega(Vino* v,char* bodega){
    strcpy(v->bodega,bodega);
}
void setSegmentoDelVino(Vino* v,char* segmentoDelVino){
    strcpy(v->segmentoDelVino,segmentoDelVino);
}
void getVarietal(Vino* v,char* varietal){
    strcpy(v->varietal,varietal);
}
void setAnioCosecha(Vino* v,int anioCosecha){
    v->anioCosecha = anioCosecha;
}
void setTerroir(Vino* v,char* terroir){
    strcpy(v->terroir,terroir);
}
void setVecesSeleccionado(Vino* v, int n){
    v->veceSeleccionado = n;
}
void mostrarVino(Vino* v){
    cout<<"--------------------------"<<endl;
    cout<<"Id: "<<v->id<<endl;
    cout<<"Etiqueta: "<<v->etiqueta<<endl;
    cout<<"Bodega: "<<v->bodega<<endl;
    cout<<"Segmento del Vino: "<<v->segmentoDelVino<<endl;
    cout<<"Varietal: "<<v->varietal<<endl;
    cout<<"Anio de Cosecha: "<<v->anioCosecha<<endl;
    cout<<"Terroir: "<<v->terroir<<endl;
    cout<<"Las veces que se eligio este vino fue: " << v->veceSeleccionado<<endl;
}
