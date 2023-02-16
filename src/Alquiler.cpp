#include "Alquiler.h"



///GETS
int Alquiler::getNroAlquiler(){return _nroAlquiler;}
Fecha Alquiler::getFechaInicio(){return _fechaInicio;}
int Alquiler::getDias(){return _dias;}
int Alquiler::getNroAuto(){return _nroAuto;}
int Alquiler::getNroCliente(){return _nroCliente;}
bool Alquiler::getActivo(){return _activo;}
bool Alquiler::getBajaLogica(){return _bajaLogica;}


///SETS
void Alquiler::setNroAlquiler(int a){_nroAlquiler=a;}
void Alquiler::setFechaInicio(Fecha a){
    _fechaInicio.setDia(a.getDia());
    _fechaInicio.setMes(a.getMes());
    _fechaInicio.setAnio(a.getAnio());
}
void Alquiler::setDias(int a){_dias=a;}
void Alquiler::setNroAuto(int a){_nroAuto=a;}
void Alquiler::setNroCliente(int a){_nroCliente=a;}
void Alquiler::setActivo(bool a){_activo=a;}
void Alquiler::setBajaLogica(bool a){_bajaLogica = a;}



bool Alquiler::grabarEnDisco(){
    FILE *p;
    p=fopen("alquileres.dat","ab");
    if(p==NULL) return false;
    bool escribio=fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return escribio;
}


bool Alquiler::leerDeDisco(int pos){
    FILE *p;
    p=fopen("alquileres.dat","rb");
    if(p==NULL) return false;
    fseek(p,pos*sizeof *this, 0);
    bool leyo=fread(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}


bool Alquiler::modificarArchivo(Alquiler a, int pos){
    FILE *p;
    bool escribio;
    p=fopen("alquileres.dat", "rb+");
    if(p==NULL) return false;
    fseek(p,sizeof(Alquiler)*pos,0);
    escribio = fwrite(&a, sizeof a, 1, p);
    fclose(p);
    return escribio;
}


void Alquiler::mostrarFechaInicio(){  ///FUNCION QUE MUESTRA LA FECHA DE INICIO DEL ALQUILER
    _fechaInicio.Mostrar();
}


void Alquiler::mostrar(){  ///FUNCION QUE MUESTRA LOS DATOS DE UN ALQUILER
    std::cout<<"ALQUILER NRO: "<<_nroAlquiler<<std::endl;
    std::cout<<"FECHA INICIO: "<<_fechaInicio.getDia()<<"/"<<_fechaInicio.getMes()<<"/"<<_fechaInicio.getAnio()<<std::endl;
    std::cout<<"DIAS DE ALQUILER: "<<_dias<<std::endl;
    std::cout<<"AUTO NRO: "<<_nroAuto<<std::endl;
    std::cout<<"CLIENTE NRO: "<<_nroCliente<<std::endl;
    if(_activo){std::cout<<"ACTIVO: Si";}
    else{std::cout<<"ACTIVO: No";}
    std::cout<<std::endl<<std::endl;
}


void Alquiler::Nuevo(){  ///FUNCION QUE DA DE ALTA UN ALQUILER NUEVO
    int nc;
    int op;
    int na = (this->numero_alquiler()+1);
    this->setNroAlquiler(na);
    this->grabarEnDisco();
    std::cout<<"ALQUILER NRO: ";
    std::cout<<_nroAlquiler;
    std::cout<<std::endl;
    _fechaInicio.Cargar();
    std::cout<<"CANTIDAD DIAS DE ALQUILER: ";
    std::cin>>_dias;
    std::cout<<"CLIENTE: "<<std::endl;
    std::cout<<"0.Cliente Nuevo"<<std::endl;
    std::cout<<"1.Cliente Viejo"<<std::endl;
    do{
        std::cout<<std::endl<<"Opcion: ";
        std::cin>>op;
        if(op>1 || op<0){
            std::cout<<"Opcion incorrecta, ingresar nuevamente."<<std::endl;
        }
    }while(op>1 || op<0);

    nc=this->seleccion_cliente(op);

    if(nc==0){
        _bajaLogica=false;
        return;
    }
    else{
        this->setNroCliente(nc);
        _activo=true;
        _bajaLogica=true;
        std::cout<<"AUTO: "<<std::endl;
        this->setNroAuto(this->seleccion_auto());
    }
}


int Alquiler::seleccion_cliente(int a){  ///FUNCION QUE RECIBE CERO PARA CREAR UN CLIENTE NUEVO O UNO PARA SELECCIONAR UN CLIENTE VIEJO
    Cliente b;

    if(a==0){
        std::cout<<std::endl;
        std::cout<<"--INGRESO DE CLIENTE NUEVO PARA ALQUILER--";
        b.Nuevo();
        b.grabarEnDisco();
        return b.getNroCliente1();
    }
    if(a==1){

        int dni;
        dni = b.seleccionarDNI();
        if(dni==0){
            return 0;
        }
        else{
            b.leerDeDisco(dni-1);
            return b.getNroCliente1();
        }
    }
}


bool Alquiler::CeroClientes(){  ///FUNCION QUE DEVUELVE CERO SI NO HAY CLIENTES REGISTRADOS EN EL ARCHIVO O UNO SI HAY
    Cliente a;
    int pos=0;
    int contador=0;

    while(a.leerDeDisco(pos)){
        if(a.getBajaLogica()){
            contador++;
        }
        pos++;
    }

    if(a.numero_cliente()==0 || contador==0){
        return false;
    }
    else{
        return true;
    }
}


int Alquiler::numero_alquiler(){ ///DEVUELVE LA CANTIDAD DE ALQUILERES QUE HAY EN EL ARCHIVO PARA DESPUES SUMARLE UNO Y ASIGNARLE AL ALQUILER NUEVO A CARGAR
  FILE* p = fopen("alquileres.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof *this;
  fclose(p);
  return cant;
}


int Alquiler::seleccion_auto(){  ///MUESTRA LOS AUTOS HABILITADOS Y DESPUES SELECCIONA EL AUTO PARA EL ALQUILER
    Auto a;
    int na;
    a.MostrarHabilit();
    na=a.Seleccion();
    return na;
}


void Alquiler::AlquileresActivos(){ ///MUESTRA LOS ALQUILERES ACTIVOS
    int pos=0;
    std::cout<<"--ALQUILERES ACTIVOS--"<<std::endl;
    while(this->leerDeDisco(pos)){
        if(this->getBajaLogica()==1 && this->getActivo()==1){
            std::cout<<"------"<<std::endl;
            this->mostrar();
        }
        pos++;
    }
;}


void Alquiler::AlquileresFinalizados(){  ///MUESTRA LOS ALQUILERES FINALIZADOS
    int pos=0;
    std::cout<<"--ALQUILERES FINALIZADOS--"<<std::endl;
    while(this->leerDeDisco(pos)){
        if(this->getBajaLogica()==1 && this->getActivo()==0){
            std::cout<<"------"<<std::endl;
            this->mostrar();
        }
        pos++;
    }
;}


void Alquiler::Baja(){  ///FUNCION PARA DAR DE BAJA LOGICA
    int pos=0;
    while(this->leerDeDisco(pos)){
        if(this->getBajaLogica()){
            this->mostrar();
        }
        pos++;
    }

    bool encontro=true;
    while(encontro==true){
        int pos1=0;
        int na;
        std::cout<<"NRO. DE ALQUILER A DAR DE BAJA: ";
        std::cin>>na;
        while(this->leerDeDisco(pos1)){
            if(pos1+1==na){
                if(this->getBajaLogica()){
                    this->setBajaLogica(false);
                    encontro=false;
                }
                this->modificarArchivo(*this ,na-1);
            }
            pos1++;
        }
        if(this->leerDeDisco(pos1)==0 && encontro==1){
            std::cout<<"NRO. DE ALQUILER INEXISTENTE"<<std::endl;
            encontro=false;
        }
    }
}


void Alquiler::Finalizar(){  ///FUNCION PARA FINALIZAR EL ALQUILER CAMBIANDO EL VALOR DEL BOOLEANO "ACTIVO" Y EL BOOLEANO "HABILITADO" DEL AUTO QUE SE ASIGNO
    Auto b;
    int pos=0;
    std::cout<<"--ALQUILERES ACTIVOS--"<<std::endl;
    while(this->leerDeDisco(pos)){
        if(this->getBajaLogica()){
            if(this->getActivo()){
                this->mostrar();
            }
        }
        pos++;
    }

    bool encontro=true;
    while(encontro==true){
        int pos1=0;
        int na;
        std::cout<<"NRO. DE ALQUILER A FINALIZAR: ";
        std::cin>>na;
        while(this->leerDeDisco(pos1)){
            if(pos1+1==na){
                if(this->getBajaLogica()){
                    this->setActivo(false);
                    b.leerDeDisco(this->getNroAuto()-1);
                    b.setHabilitado(true);
                    b.modificarArchivo(b ,this->getNroAuto()-1);

                    encontro=false;
                }
                this->modificarArchivo(*this ,na-1);
            }
            pos1++;
        }
        if(this->leerDeDisco(pos1)==0 && encontro==1){
            std::cout<<"NRO. DE ALQUILER INEXISTENTE"<<std::endl;
            encontro=false;
        }
    }
}


bool Alquiler::CeroAutos(){  ///FUNCION QUE DEVUELVE CERO SI NO HAY AUTOS REGISTRADOS EN EL ARCHIVO O UNO SI HAY
    Auto a;
    int pos=0;
    int contador=0;

    while(a.leerDeDisco(pos)){
        if(a.getHabilitado()==1 && a.getBajaLogica()==1){
            contador++;
        }
        pos++;
    }

    if(a.numero_auto()==0 || contador==0){
        return false;
    }
    else{
        return true;
    }
}




