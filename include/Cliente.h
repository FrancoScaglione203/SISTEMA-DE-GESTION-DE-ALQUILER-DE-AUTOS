#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <string.h>


class Cliente
{
    private:
        int _nroCliente;
        int _nroCliente1;
        int _dni;
        char _nombre[30];
        char _apellido[30];
        bool _socio;
        bool _bajaLogica;


    public:

        int getNroCliente1();
        int getDni();
        const char* getNombre();
        const char* getApellido();
        bool getSocio();
        bool getBajaLogica();

        void setNroCliente1(int a);
        void setDni(int a);
        void setNombre(const char *nom);
        void setApellido(const char *ape);
        void setSocio(bool a);
        void setBajaLogica(bool a);

        void Nuevo();
        void Mostrar();
        void Baja();

        bool grabarEnDisco();
        bool leerDeDisco(int pos);
        bool modificarArchivo(Cliente a, int pos);

        int numero_cliente();
        void ListadoClientes();

        void buscarDNI();
        bool comprobarDNI(int dni);
        int seleccionarDNI();

        void AltaBajaSocio();
        void ListadoSocios();




};

#endif // CLIENTE_H
