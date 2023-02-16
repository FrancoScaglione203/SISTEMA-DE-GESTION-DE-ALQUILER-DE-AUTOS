#include "Cliente.h"



///GETS
int Cliente::getNroCliente1(){return _nroCliente1;}
int Cliente::getDni(){return _dni;}
const char* Cliente::getNombre(){return _nombre;}
const char* Cliente::getApellido(){return _apellido;}
bool Cliente::getSocio(){return _socio;}
bool Cliente::getBajaLogica(){return _bajaLogica;}

///SETS
void Cliente::setNroCliente1(int a){_nroCliente1=a;}
void Cliente::setDni(int a){_dni=a;}
void Cliente::setNombre(const char *nom){strcpy(_nombre,nom);}
void Cliente::setApellido(const char *ape){strcpy(_apellido,ape);}
void Cliente::setSocio(bool a){_socio=a;}
void Cliente::setBajaLogica(bool a){_bajaLogica = a;}






bool Cliente::grabarEnDisco(){
    FILE *p;
    p=fopen("clientes.dat","ab");
    if(p==NULL) return false;
    bool escribio=fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return escribio;
}


bool Cliente::leerDeDisco(int pos){
    FILE *p;
    p=fopen("clientes.dat","rb");
    if(p==NULL) return false;
    fseek(p,pos*sizeof *this, 0);
    bool leyo=fread(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}


bool Cliente::modificarArchivo(Cliente a, int pos){
    FILE *p;
    bool escribio;
    p=fopen("clientes.dat", "rb+");
    if(p==NULL) return false;
    fseek(p,sizeof(Cliente)*pos,0);
    escribio = fwrite(&a, sizeof a, 1, p);
    fclose(p);
    return escribio;
}


int Cliente::numero_cliente(){  ///DEVUELVE LA CANTIDAD DE CLIENTES QUE HAY EN EL ARCHIVO PARA DESPUES SUMARLE UNO Y ASIGNARLE AL CLIENTE NUEVO A CARGAR
  FILE* p = fopen("clientes.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof *this;
  fclose(p);
  return cant;
}


void Cliente::ListadoClientes(){  ///MUESTRA EL LISTADO DE CLIENTES
    int pos=0;
    std::cout<<"--LISTA DE CLIENTES--"<<std::endl<<std::endl;
    while(this->leerDeDisco(pos)){
        if(this->getBajaLogica()){
            std::cout<<"------"<<std::endl;
            this->Mostrar();
        }
        pos++;
    }
;}


void Cliente::Baja(){ ///FUNCION PARA DAR LA BAJA LOGICA
    int pos=0;
    while(this->leerDeDisco(pos)){
        if(this->getBajaLogica()){
            std::cout<<"CLIENTE NUMERO: "<<pos+1<<std::endl;
            this->Mostrar();
        }
        pos++;
    }

    bool encontro=true;
    while(encontro==true){
        int pos1=0;
        int nc;
        std::cout<<"NRO. DE CLIENTE A DAR DE BAJA: ";
        std::cin>>nc;
        while(this->leerDeDisco(pos1)){
            if(pos1+1==nc){
                if(this->getBajaLogica()){
                    this->setBajaLogica(false);
                    encontro=false;
                }
                this->modificarArchivo(*this ,nc-1);
            }
            pos1++;
        }
        if(this->leerDeDisco(pos1)==0 && encontro==1){
            std::cout<<"NRO. DE CLIENTE INEXISTENTE";
            encontro=false;
        }
    }
}


void Cliente::buscarDNI(){  ///FUNCION PARA BUSCAR CLIENTE POR DNI Y MOSTRARLO
    bool encontro=true;
    while(encontro==true){
        int pos1=0;
        int dni;
        std::cout<<"INGRESE DNI A BUSCAR: ";
        std::cin>>dni;
        while(this->leerDeDisco(pos1)){
            if(this->getDni()==dni && this->getBajaLogica()==1){
                    this->Mostrar();
                    encontro=false;
            }
            pos1++;
        }
        if(this->leerDeDisco(pos1)==0 && encontro==1){
            std::cout<<"NO SE ENCONTRO NINGUN CLIENTE CON ESE NUMERO DE DNI";
            encontro=false;
        }
    }

}


int Cliente::seleccionarDNI(){  ///FUNCION PARA BUSCAR CLIENTE POR DNI, DEVUELVE EL NRO DE CLIENTE SI LO ENCUENTTRA O CERO SI NO LO ENCUENTRA
    bool encontro=true;
    while(encontro==true){
        int pos1=0;
        int dni;
        std::cout<<"INGRESE DNI DE CLIENTE A BUSCAR: ";
        std::cin>>dni;
        while(this->leerDeDisco(pos1)){
            if(this->getDni()==dni && this->getBajaLogica()==1){
                    encontro=false;
                    return this->getNroCliente1();
            }
            pos1++;
        }
        if(this->leerDeDisco(pos1)==0 && encontro==1){
            std::cout<<"NO SE ENCONTRO NINGUN CLIENTE CON ESE NUMERO DE DNI"<<std::endl;
            encontro=false;
            return 0;
        }
    }

}


bool Cliente::comprobarDNI(int dni){  ///FUNCION PARA COMPROBAR SI YA EXISTE UN CLIENTE CON ESE DNI, DEVUELVE CERO SI NO EXISTE O UNO SI YA EXISTE
        int pos1=0;
        while(this->leerDeDisco(pos1)){
            if(this->getDni()==dni && this->getBajaLogica()==1){
                    std::cout<<"Ya existe un cliente con ese numero de dni"<<std::endl;;
                    return true;
            }

            pos1++;
        }
        return false;


}


void Cliente::Nuevo(){  ///FUNCION QUE DA DE ALTA UN CLIENTE NUEVO
    int ind;
    int nc = (this->numero_cliente()+1);
    this->setNroCliente1(nc);
    this->grabarEnDisco();
    std::cout<<_nroCliente1<<std::endl;
    std::cout<<"CLIENTE NUMERO: "<<_nroCliente1<<std::endl;
    std::cout<<"DNI: ";
    std::cin>>ind;
    if(this->comprobarDNI(ind)){
        system("pause");
        return;
    }
    this->setDni(ind);
    std::cout<<"NOMBRE: ";
    std::cin.ignore(256,'\n');
    std::cin.getline(_nombre, 30);
    std::cout<<"APELLIDO: ";
    std::cin.getline(_apellido, 30);
    int soc;
    do{
        std::cout<<"SOCIO(1=Si,0=No): ";
        std::cin>>soc;
        if(soc>1 || soc<0){
            std::cout<<"Opcion incorrecta, ingresar nuevamente."<<std::endl;
        }
    }while(soc>1 || soc<0);
    this->setSocio(soc);
    _bajaLogica=true;
    std::cout<<std::endl;
}


void Cliente::Mostrar(){   ///FUNCION QUE MUESTRA LOS DATOS DE UN CLIENTE
        std::cout<<"NUMERO CLIENTE: ";
        std::cout<<this->getNroCliente1()<<std::endl;
        std::cout<<"DNI: ";
        std::cout<<_dni<<std::endl;
        std::cout<<"NOMBRE: ";
        std::cout<<_nombre<<std::endl;
        std::cout<<"APELLIDO: ";
        std::cout<<_apellido<<std::endl;
        std::cout<<"SOCIO: ";
        if(_socio){std::cout<<"Si";}
        else{std::cout<<"No";}
        std::cout<<std::endl<<std::endl;
}


void Cliente::AltaBajaSocio(){  ///FUNCION PARA CAMBIAR EL VALOR DEL BOOLEANO "SOCIO"
    int pos=0;
    std::cout<<"--LISTADO DE SOCIOS--"<<std::endl;
    while(this->leerDeDisco(pos)){
        if(this->getBajaLogica()){
            this->Mostrar();
        }
        pos++;
    }

    bool encontro=true;
    while(encontro==true){
        int pos1=0;
        int nc;
        std::cout<<"NRO. DE CLIENTE A DAR DE ALTA/BAJA COMO SOCIO: ";
        std::cin>>nc;
        while(this->leerDeDisco(pos1)){
            if(pos1+1==nc){
                if(this->getBajaLogica()){
                    if(getSocio()){
                        this->setSocio(false);
                        encontro=false;
                    }
                    else{
                        this->setSocio(true);
                        encontro=false;
                    }
                }
                this->modificarArchivo(*this ,nc-1);
            }
            pos1++;
        }
        if(this->leerDeDisco(pos1)==0 && encontro==1){
            std::cout<<"NRO. DE CLIENTE INEXISTENTE";
            encontro=false;
            std::cout<<std::endl;
        }
    }
}


void Cliente::ListadoSocios(){  ///MUESTRA EL LISTADO DE SOCIOS
    int pos=0;
    std::cout<<"--LISTADO DE SOCIOS--"<<std::endl;
    while(this->leerDeDisco(pos)){
        if(this->getBajaLogica()){
            if(this->getSocio()){
                std::cout<<"------"<<std::endl;
                this->Mostrar();
            }
        }
        pos++;
    }
;}
