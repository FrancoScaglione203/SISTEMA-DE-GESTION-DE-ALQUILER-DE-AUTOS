#include <iostream>
#include "Auto.h"
#include "Cliente.h"
#include "Fecha.h"
#include "Alquiler.h"
#include "Menu.h"




///




int main()
{



//Alquiler a;

//std::cout<<a.seleccion_cliente(1);



  /*  int pos=0;
    int contador=0;



    a.MostrarHabilit();


    while(a.leerDeDisco(pos)){
        if(a.getHabilitado()==1 && a.getBajaLogica()==1){
            contador++;

            std::cout<<"jajaj"<<std::endl;
        }
        pos++;
    }
*/


Menu a;

a.menu_principal();


//Alquiler b;



//std::cout<<b.CeroClientes();

    /*
        int pos1=0;
        int dni;
        std::cout<<"INGRESE DNI A BUSCAR: ";
        std::cin>>dni;
        while(a.leerDeDisco(pos1)){
            if(a.getDni()==dni && a.getBajaLogica()==1){
                    std::cout<<"Mogolico";
                    return true;
            }

            pos1++;
        }
        return false;   */














/*
    bool encontro=true;
    while(encontro){

        int pos1=0;



        std::cout<<"NRO. DE AUTO A INHABILITAR: ";
        std::cin>>na;
        while(a.leerDeDisco(pos1)){
            if(a.getNroAuto()==na){
                a.setHabilitado(true);
                a.modificarArchivo(a,na-1);
                encontro=false;
            }

            pos1++;
        }

    }

*/

/*
    a.nuevo();

    a.grabarEnDisco();

    a.nuevo();

    a.grabarEnDisco();

    system("PAUSE()");
    system("CLS()");
*/



/*

    int d=30, m=4, a=8;

	if(a<=0){return false;}
	if(m>12 || m<1){return false;}
    if(d<1){return false;}
    if(esBisiesto(a)==1 && m==2 && d>29){return false;}
	if(esBisiesto(a)==0 && m==2 && d>28){return false;}
	if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
            if(d>31){return false;}
    }
	if(m==4 || m==6 || m==9 || m==11){
            if(d>30){return false;}
    }

	return true;

*/

/*
    Auto a;

    for(int x=0;x<2;x++){
        a.leerDeDisco(x);
        a.Mostrar();
    }

*/


 /*   Auto a;

    a.Cargar();
    a.grabarEnDisco();

    int pos=0;

    while(a.leerDeDisco(pos)){
      std::cout<<std::endl;
      a.leerDeDisco(pos);
      a.Mostrar();
      pos++;
    }

*/



    /*
    char palabra[20];

    std::cin.getline(palabra, 20);

    std::cout << palabra;

    */

    return 0;
}
