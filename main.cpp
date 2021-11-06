#include<locale.h>
#include <wchar.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "string.h"
#include "Lista.h"
#include "usuario.h"
#include "vino.h"
#include "beneficio.h"
using namespace std;
void ingresarUsuarios(Lista* l);
void ingresarVinos(Lista* l);
void ingresarBeneficios(Lista* l);

int main()
{
    setlocale(LC_ALL, "");
    bool menu=true;
    int opcion;
    Lista* lu = CrearLista();
    Lista* lv = CrearLista();
    Lista* lb = CrearLista();
    cout<<"BIENVENIDO AL SISTEMA DE USURIOS , VINOS Y BENEFICIOS"<<endl;
    system("pause");
    system("cls");
    while(menu)
    {
        cout<<"Opcion 1- Cargar usuarios desde archivo\nOpcion 2- Mostrar usuarios\nOpcion 3- Cargar vinos desde archivos\nOpcion 4- Mostrar vinos\nOpcion 5- Cargar beneficios\nOpcion 6- Mostrar beneficios\nOpcion 7- Realizar ranking\nOpcion 8- Mostrar Ranking ordenado\nOpcion 9- Ordenamiento por bodega\nOpcion 0- Salir" <<endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            {
                if (ObtenerLongitud(lu)==0)
                {
                    system("cls");
                    ingresarUsuarios(lu);
                    cout<<"Los Usuarios fueron cargados correctamente"<<endl;
                    system("pause");
                    system("cls");

                }else{
                    cout << "Ya esta cargada la lista" <<endl;
                }
            }
        break;
        case 2:
        {
            if (ObtenerLongitud(lu)>0)
            {
                system("cls");
                MostrarListaUsuarios(lu);
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                cout << "No hay usuarios en la lista"<<endl;
                system("pause");
                system("cls");
            }
        }
        break;
        case 3:
            {
                if(ObtenerLongitud(lv)==0){
                    system("cls");
                    ingresarVinos(lv);
                    cout<<"Los Vinos fueron cargados correctamente"<<endl;
                    system("pause");
                    system("cls");

                }else{
                    system("cls");
                    cout << "La Lista no esta cargada" <<endl;
                    system("pause");
                    system("cls");
                }
            }
        break;
        case 4:
            {
                if (ObtenerLongitud(lv)>0){
                    system("cls");
                    MostrarListaVino(lv);
                    system("pause");
                    system("cls");


                }else{

                    system("cls");
                    cout <<"No hay Vinos en la lista"<<endl;
                    system("pause");
                    system("cls");

                }
            }
        break;
        case 5:
            {
                if(ObtenerLongitud(lb)==0){
                    system("cls");
                    ingresarBeneficios(lb);
                    cout<<"Los Beneficios fueron cargados correctamente"<<endl;
                    system("pause");
                    system("cls");

                }else{
                    system("cls");
                    cout << "La Lista no esta cargada" <<endl;
                    system("pause");
                    system("cls");
                }
            }
        break;
        case 6:
            {
                if (ObtenerLongitud(lb)>0){
                    system("cls");
                    MostrarListaBeneficios(lb);
                    system("pause");
                    system("cls");


                }else{

                    system("cls");
                    cout <<"No hay beneficios en la lista"<<endl;
                    system("pause");
                    system("cls");

                }
            }
        break;
        case 7:
            {
                if (ObtenerLongitud(lv)>0){
                    Limpiar_Vinos_seleccionados(lv);
                    if(ObtenerLongitud(lu)>0){
                        if(ObtenerLongitud(lb)>0){
                            system("cls");
                            Nodo* puntero = lb->Primero;
                            Nodo* puntero2 = lv->Primero;
                            while(puntero->Siguiente != NULL){

                                for(int i = 0; i < 6 ; i++){
                                    long aux = getSeleccionVinos(puntero->b)[i];
                                    ranking_de_vinos(aux,lv);
                                }
                                puntero = puntero->Siguiente;

                            }
                            cout<<"Se realizo el ranking corectamente"<<endl;
                            system("pause");
                            system("cls");

                        }else{

                            system("cls");
                            cout <<"No hay beneficios en la lista beneficios"<<endl;
                            system("pause");
                            system("cls");

                        }

                    }else{

                        system("cls");
                        cout <<"No hay Usuarios en la lista de usuarios"<<endl;
                        system("pause");
                        system("cls");

                        }

                }else{

                    system("cls");
                    cout <<"No hay Vinos en la lista vinos "<<endl;
                    system("pause");
                    system("cls");

                }
            }
        break;
        case 8:
            {
                if (ObtenerLongitud(lv)>0){
                    system("cls");
                    ordenamientoRanking(lv);
                    MostrarListaVino(lv);

                    system("pause");
                    system("cls");

                }else{

                    system("cls");
                    cout <<"No hay Vinos en la lista"<<endl;
                    system("pause");
                    system("cls");
                }
            }
        break;
        case 9:
            {

                if (ObtenerLongitud(lv)>0){
                    Limpiar_Vinos_seleccionados(lv);
                    if(ObtenerLongitud(lu)>0){
                        if(ObtenerLongitud(lb)>0){
                            system("cls");
                            Nodo* puntero = lb->Primero;
                            Nodo* puntero2 = lv->Primero;
                            while(puntero->Siguiente != NULL){
                                for(int i = 0; i < 6 ; i++){
                                    long aux = getSeleccionVinos(puntero->b)[i];
                                    rankingBodega(aux , lv);
                                }
                                puntero = puntero->Siguiente;

                            }
                            cout<<"Se realizo el ranking corectamente"<<endl;
                            system("pause");
                            system("cls");

                        }else{

                            system("cls");
                            cout <<"No hay beneficios en la lista beneficios"<<endl;
                            system("pause");
                            system("cls");

                        }

                    }else{

                        system("cls");
                        cout <<"No hay Usuarios en la lista de usuarios"<<endl;
                        system("pause");
                        system("cls");

                        }

                }else{

                    system("cls");
                    cout <<"No hay Vinos en la lista vinos "<<endl;
                    system("pause");
                    system("cls");

                }
            }
        break;
        case 0:
            system("cls");
            cout<<"Adios y tenga un buen dia"<<endl;
            menu=false;
            break;
        }

    }

    return 0;
}

void ingresarUsuarios(Lista* l1){
    string id;
    string nombre;
    string localidad;
    string edad;
    int idaux , edadux;


    int iterador = 1;
    int contador = 0;
    int auxcont = 0;


    ifstream input;
    input.open("usuarios_test.txt");
    char character;
    input.get(character);
    while(!input.eof()){
            if(character != '-' && auxcont == 0){
                id += character;

            }else if(character == '-' && auxcont == 0){
                auxcont++;
                input.get(character);
            }
            if(character != '-' && auxcont == 1){
                nombre += character;

            }else if(character == '-' && auxcont == 1){
                auxcont++;

                input.get(character);
            }
            if(character != '-' && auxcont == 2){
               localidad += character;

            }else if(character == '-' && auxcont == 2){
                auxcont++;
                input.get(character);
            }
            if(character != '-' && auxcont == 3){
                edad += character;
            }if(character == ';' && auxcont == 3){
                auxcont = 0;
                input.get(character);
                contador++;

                idaux = stoi(id);
                edadux = stoi(edad);

                char nombreaux[nombre.length() + 1];
                char localidadAux[localidad.length() +1];
                strcpy(nombreaux, nombre.c_str());
                strcpy(localidadAux, localidad.c_str());


                Usuario* Uaux = crearUsuario(idaux,nombreaux,localidadAux,edadux);
                InsertarUltimo(l1,Uaux);
                id = "";
                nombre = "";
                nombreaux;
                localidad="";
                localidadAux;
                edad = "";
                Uaux = NULL;
            }
    input.get(character);
    }
    input.close();
}

void ingresarVinos(Lista* l){

    string id;
    string etiqueta;
    string bodega;
    string segmentoDelVino;
    string varietal;
    string anioCosecha;
    string terroir;
    long idaux;
    int anioCosechaAux ;


    int iterador = 1;
    int contador = 0;
    int auxcont = 0;


    ifstream input;
    input.open("catalos_test.txt");
    char character;
    input.get(character);
    while(!input.eof()){
            // carga el ID del vino
            if(character != '-' && auxcont == 0){

                id += character;

            }else if(character == '-' && auxcont == 0){
                auxcont++;
                input.get(character);
            }
            // carga la Etiqueta del vino
            if(character != '-' && auxcont == 1){

                etiqueta += character;

            }else if(character == '-' && auxcont == 1){
                auxcont++;
                input.get(character);
            }
            // carga la Bodega del vino
            if(character != '-' && auxcont == 2){
               bodega += character;

            }else if(character == '-' && auxcont == 2){
                auxcont++;
                input.get(character);
            }
            // carga el Segmento del Vino del vino
            if(character != '-' && auxcont == 3){
                segmentoDelVino += character;

            }else if(character == '-' && auxcont == 3){
                auxcont++;
                input.get(character);
            }
            // carga el varietal del vino
            if(character != '-' && auxcont == 4){
                varietal += character;

            }else if(character == '-' && auxcont == 4){
                auxcont++;
                input.get(character);
            }
            // carga el añio de la cosecha del vino
            if(character != '-' && auxcont == 5){
                anioCosecha += character;

            }else if(character == '-' && auxcont == 5){
                auxcont++;
                input.get(character);
            }
            // carga el Terroir del vino
            if(character != '-' && auxcont == 6){
                terroir += character;

            }
            //carga en el igresar vino y resetea los parametros
            if(character == ';' && auxcont == 6){
                auxcont = 0;
                input.get(character);
                contador++;

                idaux = stoi(id);
                anioCosechaAux = stoi(anioCosecha);


                char etiquetAux[etiqueta.length() + 1];
                char bodegaAux[bodega.length() +1];
                char segmentoDelVinoAux[segmentoDelVino.length() +1];
                char varietalAux[varietal.length() + 1];
                char terroiraux[terroir.length() + 1];


                strcpy(etiquetAux, etiqueta.c_str());
                strcpy(bodegaAux, bodega.c_str());
                strcpy(segmentoDelVinoAux, segmentoDelVino.c_str());
                strcpy(varietalAux, varietal.c_str());
                strcpy(terroiraux, terroir.c_str());

                Vino* Vaux = crearVino(idaux , etiquetAux , bodegaAux , segmentoDelVinoAux , varietalAux , anioCosechaAux , terroiraux);
                InsertarUltimoVino(l , Vaux);

                id = "";

                etiqueta = "";
                etiquetAux;

                bodega="";


                segmentoDelVino = "";


                varietal = "";


                terroir = "";


                anioCosecha = "";

            }
    input.get(character);
    }
    input.close();
}

void ingresarBeneficios(Lista* l){
    string id;
    string mesSeleccion;
    string anioSeleccion;
    string IDVino;
    string vectorDeIDS[6];
    int  mesSeleccionAux , anioSeleccionAux , IDVinoAux ;
    int vectorAux[6];
    int aux , i = 0;
    long idaux;

    int iterador = 1;
    int contador = 0;
    int auxcont = 0;


    ifstream input;
    input.open("elecion_test.txt");
    char character;
    input.get(character);
    while(!input.eof()){
            if(character != '-' && auxcont == 0){
                id += character;
            }else if(character == '-' && auxcont == 0){
                auxcont++;
                input.get(character);
            }
            if(character != '-' && auxcont == 1){
                mesSeleccion += character;

            }else if(character == '-' && auxcont == 1){
                auxcont++;

                input.get(character);
            }
            if(character != '-' && auxcont == 2){
               anioSeleccion += character;

            }else if(character == '-' && auxcont == 2){
                auxcont++;
                input.get(character);
            }


            if(character != '-' && auxcont == 3 && character != ';'){
                IDVino += character;

            }
             if(character == '-'&& auxcont == 3){
                vectorDeIDS[i]=IDVino;
                i++;
                IDVino="";

            }
            if(character == ';'){
                auxcont=0;
                vectorDeIDS[i] = IDVino;
                for (int j=0;j<=i;j++){
                    vectorAux[j] = stoi(vectorDeIDS[j]);
                }

                idaux = stoi(id);
                mesSeleccionAux = stoi(mesSeleccion);
                anioSeleccionAux = stoi(anioSeleccion);

                Beneficio* Baux = crearBeneficio(idaux , mesSeleccionAux , anioSeleccionAux , vectorAux);
                InsertarUltimoBeneficio(l , Baux);

                id = "";

                mesSeleccion = "";

                anioSeleccion="";

                IDVino="";
                i=0;

            }

    input.get(character);
    }
    input.close();
}
