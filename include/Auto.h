#ifndef AUTO_H
#define AUTO_H
#include <iostream>
#include <string.h>



class Auto
{
    private:
        int _capacidad;
        char _modelo[30];
        char _patente[30];
        bool _habilitado;
        bool _bajaLogica;
        int _tipoAuto;
        int _nroAuto;

    public:
        int getCapacidad();
        const char* getModelo();
        const char* getPatente();
        bool getHabilitado();
        bool getBajaLogica();
        int getTipoAuto();
        int getNroAuto();

        void setCapacidad(int a);
        void setModelo(const char *mod);
        void setPatente(const char *pat);
        void setHabilitado(bool a);
        void setBajaLogica(bool a);
        void setTipoAuto(int a);
        void setNroAuto(int a);

        void Nuevo();
        void Mostrar();
        void Habilitacion();
        void Baja();

        bool grabarEnDisco();
        bool leerDeDisco(int pos);
        bool modificarArchivo(Auto a, int pos);

        int numero_auto();

        void MostrarHabilit();
        void MostrarInhabilit();
        int Seleccion();






};

#endif // AUTO_H
