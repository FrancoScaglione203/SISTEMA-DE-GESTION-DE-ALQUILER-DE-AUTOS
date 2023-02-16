#ifndef ALQUILER_H
#define ALQUILER_H
#include <iostream>
#include <Fecha.h>
#include <Auto.h>
#include "Cliente.h"


class Alquiler
{
    private:
        int _nroAlquiler;
        Fecha _fechaInicio;
        int _dias;
        int _nroAuto;
        int _nroCliente;
        bool _activo;
        bool _bajaLogica;

    public:
        int getNroAlquiler();
        Fecha getFechaInicio();
        int getDias();
        int getNroAuto();
        int getNroCliente();
        bool getActivo();
        bool getBajaLogica();

        void setNroAlquiler(int a);
        void setFechaInicio(Fecha a);
        void setDias(int a);
        void setNroAuto(int a);
        void setNroCliente(int a);
        void setActivo(bool a);
        void setBajaLogica(bool a);

        void mostrarFechaInicio();
        void mostrar();

        void Nuevo();
        void Baja();
        void Finalizar();

        bool grabarEnDisco();
        bool leerDeDisco(int pos);
        bool modificarArchivo(Alquiler a, int pos);

        int numero_alquiler();
        int seleccion_auto();
        int seleccion_cliente(int a);
        void AlquileresActivos();
        void AlquileresFinalizados();

        bool CeroAutos();
        bool CeroClientes();


};

#endif // ALQUILER_H
