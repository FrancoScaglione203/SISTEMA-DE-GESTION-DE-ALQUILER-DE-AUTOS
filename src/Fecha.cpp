#include "Fecha.h"

int Fecha::getDia(){return dia;}
int Fecha::getMes(){return mes;}
int Fecha::getAnio(){return anio;}
void Fecha::setDia(int d){dia=d;}
void Fecha::setMes(int m){mes=m;}
void Fecha::setAnio(int a){anio=a;}




bool Fecha::esBisiesto(int a){  ///DEVUELVE UNO SI ES BISIESTO O CERO SI NO LO ES
	if(a%4==0){return true;}
	else{return false;}
}


bool Fecha::esValido(int d, int m, int a){  ///DEVUELVE UNO SI LA FECHA INGRESADA ES VALIDA O CERO SI NO LO ES
	if(a<=0){return false;}
	if(m>12 || m<1){return false;}
    if(d<1){return false;}
    if(this->esBisiesto(a)==1 && m==2 && d>29){return false;}
	if(this->esBisiesto(a)==0 && m==2 && d>28){return false;}
	if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
            if(d>31){return false;}
    }
	if(m==4 || m==6 || m==9 || m==11){
            if(d>30){return false;}
    }

	return true;
}


void Fecha::Cargar(){  ///FUNCION PARA CARGAR FECHA
    do{
        std::cout<<"FECHA INICIO ALQUILER"<<std::endl;
        std::cout<<"DIA: ";
        std::cin>>dia;
        std::cout<<"MES: ";
        std::cin>>mes;
        std::cout<<"ANIO: ";
        std::cin>>anio;
        if(this->esValido(dia,mes,anio)==0){
            std::cout<<"La fecha ingresada no es valida, vuelva a ingresar una nueva"<<std::endl;
            system("PAUSE()");
            system("CLS()");
        }
    }
    while(this->esValido(dia,mes,anio)==0);
}


void Fecha::Mostrar(){  ///FUNCION PARA MOSTRAR FECHA
std::cout<<dia<<"/"<<mes<<"/"<<anio<<std::endl;
}
