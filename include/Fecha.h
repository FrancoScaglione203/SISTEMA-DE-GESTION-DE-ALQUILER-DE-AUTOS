#ifndef FECHA_H
#define FECHA_H
#include <iostream>

class Fecha{
    private:
        int dia, mes, anio;
    public:
        int getDia();
        int getMes();
        int getAnio();

        void setDia(int d);
        void setMes(int m);
        void setAnio(int a);

        void Cargar();
        void Mostrar();

        bool esBisiesto(int a);
        bool esValido(int d, int m, int a);
};

#endif // FECHA_H
