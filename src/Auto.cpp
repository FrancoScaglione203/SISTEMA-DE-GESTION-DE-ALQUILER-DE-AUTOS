#include "Auto.h"

///GETS
int Auto::getCapacidad(){return _capacidad;}
const char* Auto::getModelo(){return _modelo;}
const char* Auto::getPatente(){return _patente;}
bool Auto::getHabilitado(){return _habilitado;}
bool Auto::getBajaLogica(){return _bajaLogica;}
int Auto::getTipoAuto(){return _tipoAuto;}
int Auto::getNroAuto(){return _nroAuto;}

///SETS
void Auto::setCapacidad(int a){_capacidad = a;}
void Auto::setModelo(const char *mod){strcpy(_modelo,mod);}
void Auto::setPatente(const char *pat){strcpy(_patente,pat);}
void Auto::setHabilitado(bool a){_habilitado = a;}
void Auto::setBajaLogica(bool a){_bajaLogica = a;}
void Auto::setTipoAuto(int a){_tipoAuto = a;}
void Auto::setNroAuto(int a){_nroAuto = a;}


bool Auto::grabarEnDisco(){
    FILE *p;
    p=fopen("autos.dat","ab");
    if(p==NULL) return false;
    bool escribio=fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return escribio;
}


bool Auto::leerDeDisco(int pos){
    FILE *p;
    p=fopen("autos.dat","rb");
    if(p==NULL) return false;
    fseek(p,pos*sizeof *this, 0);
    bool leyo=fread(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}


bool Auto::modificarArchivo(Auto a, int pos){
    FILE *p;
    bool escribio;
    p=fopen("autos.dat", "rb+");
    if(p==NULL) return false;
    fseek(p,sizeof(Auto)*pos,0);
    escribio = fwrite(&a, sizeof a, 1, p);
    fclose(p);
    return escribio;
}


void Auto::Nuevo(){  ///FUNCION QUE DA DE ALTA UN AUTO NUEVO
    _nroAuto=this->numero_auto()+1;
    std::cout<<"AUTO NUMERO: "<<_nroAuto<<std::endl;
    std::cout<<"MODELO: ";
    std::cin.ignore();
    std::cin.getline(_modelo, 30);
    std::cout<<"1=Auto tres puertas"<<std::endl<<
    "2=Auto cinco puertas"<<std::endl<<
    "3=camioneta s/caja"<<std::endl<<
    "4=camioneta c/caja"<<std::endl;
    do{
        std::cout<<"TIPO DE AUTO: ";
        std::cin>>_tipoAuto;
        if(_tipoAuto>4){
            std::cout<<"Opcion incorrecta, ingresar nuevamente."<<std::endl;
        }
    }
    while(_tipoAuto>4);
    std::cin.ignore();
    std::cout<<"PATENTE: ";
    std::cin.getline(_patente, 30);
    std::cout<<"CAPACIDAD: ";
    std::cin>>_capacidad;
    int hab;
    do{
        std::cout<<"HABILITADO(1=Si,0=No): ";
        std::cin>>hab;
        if(hab>1 || hab<0){
            std::cout<<"Opcion incorrecta, ingresar nuevamente."<<std::endl;
        }
    }while(hab>1 || hab<0);
    this->setHabilitado(hab);
    _bajaLogica=true;
    std::cout<<std::endl;
    system("pause");
}


void Auto::Mostrar(){  ///FUNCION QUE MUESTRA LOS DATOS DE UN AUTO
    std::cout<<"AUTO NUMERO: "<<_nroAuto<<std::endl;
    std::cout<<"MODELO: "<<this->getModelo()<<std::endl;
    std::cout<<"TIPO DE AUTO: ";
    if(_tipoAuto == 1){std::cout<<"Auto 3 puertas";}
    if(_tipoAuto == 2){std::cout<<"Auto 5 puertas";}
    if(_tipoAuto == 3){std::cout<<"Camioneta s/caja";}
    if(_tipoAuto == 4){std::cout<<"Camioneta c/caja";}
    std::cout<<std::endl;
    std::cout<<"PATENTE: "<<_patente<<std::endl;
    std::cout<<"CAPACIDAD: "<<_capacidad<<std::endl;
    std::cout<<"HABILITADO: ";
    if(_habilitado){std::cout<<"si"<<std::endl;}
    else{std::cout<<"No"<<std::endl;}
    std::cout<<std::endl;
;}


int Auto::numero_auto(){  ///DEVUELVE LA CANTIDAD DE AUTOS QUE HAY EN EL ARCHIVO PARA DESPUES SUMARLE UNO Y ASIGNARLE AL AUTO NUEVO A CARGAR
  FILE* p = fopen("autos.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof *this;
  fclose(p);
  return cant;
}


void Auto::Habilitacion(){   ///FUNCION PARA CAMBIAR EL VALOR DEL BOOLEANO "HABILITACION"
    int pos=0;
    std::cout<<"--LISTA DE AUTOS--"<<std::endl<<std::endl;
    while(this->leerDeDisco(pos)){
        if(this->getBajaLogica()){
            std::cout<<"------"<<std::endl;
            this->Mostrar();
        }
        pos++;
    }

    bool encontro=true;
    while(encontro==true){
        int pos1=0;
        int na;
        std::cout<<"NRO. DE AUTO PARA HABILITAR/INHABILITAR: ";
        std::cin>>na;
        while(this->leerDeDisco(pos1)){
            if(this->getNroAuto()==na){
                if(this->getHabilitado()){
                    this->setHabilitado(false);
                    encontro=false;
                }
                else{
                    this->setHabilitado(true);
                    encontro=false;
                }
                this->modificarArchivo(*this ,na-1);
            }
            pos1++;
        }
        if(this->leerDeDisco(pos1)==0 && encontro==1){
            std::cout<<"NRO. DE AUTO INEXISTENTE"<<std::endl;
            encontro=false;
        }
    }
}


int Auto::Seleccion(){  ///FUNCION PARA SELECCIONAR AUTO PARA UN ALQUILER,
    int na;
    bool encontro=true;
    while(encontro==true){
        int pos1=0;
        std::cout<<"NRO. DE AUTO PARA EL ALQUILER: ";
        std::cin>>na;
        std::cout<<std::endl;
        while(this->leerDeDisco(pos1)){
            if(this->getNroAuto()==na){
                if(this->getHabilitado()){
                    this->setHabilitado(false);
                    encontro=false;
                    this->modificarArchivo(*this ,na-1);
                }

            }
            pos1++;
        }
        if(this->leerDeDisco(pos1)==0 && encontro==1){
            std::cout<<"NRO. DE AUTO INEXISTENTE, ingrese nuevamente"<<std::endl;
        }
    }
    return na;
}


void Auto::Baja(){   ///FUNCION PARA DAR LA BAJA LOGICA
    int pos=0;
    while(this->leerDeDisco(pos)){
        if(this->getBajaLogica()){
            this->Mostrar();
        }
        pos++;
    }

    bool encontro=true;
    while(encontro==true){
        int pos1=0;
        int na;
        std::cout<<"NRO. DE AUTO A DAR DE BAJA: ";
        std::cin>>na;
        while(this->leerDeDisco(pos1)){
            if(this->getNroAuto()==na){
                if(this->getBajaLogica()){
                    this->setBajaLogica(false);
                    encontro=false;
                }
                this->modificarArchivo(*this ,na-1);
            }
            pos1++;
        }
        if(this->leerDeDisco(pos1)==0 && encontro==1){
            std::cout<<"NRO. DE AUTO INEXISTENTE"<<std::endl;
            encontro=false;
        }
    }
}


void Auto::MostrarHabilit(){  ///MUESTRA EL LISTADO DE LOS AUTOS HABILITADOS
    int pos=0;
    std::cout<<"--LISTA DE AUTOS HABILITADOS--"<<std::endl<<std::endl;
    while(this->leerDeDisco(pos)){
        if(this->getHabilitado()==1 && this->getBajaLogica()==1){
            std::cout<<"------"<<std::endl;
            this->Mostrar();
        }
        pos++;
    }
    std::cout<<"-----------------------------"<<std::endl<<std::endl;
;}


void Auto::MostrarInhabilit(){  ///MUESTRA EL LISTADO DE LOS AUTOS INHABILITADOS
    int pos=0;
    std::cout<<"--LISTA DE AUTOS INHABILITADOS--"<<std::endl<<std::endl;
    while(this->leerDeDisco(pos)){
        if(this->getHabilitado()==0 && this->getBajaLogica()==1){
            std::cout<<"------"<<std::endl;
            this->Mostrar();
        }
        pos++;
    }

;}
