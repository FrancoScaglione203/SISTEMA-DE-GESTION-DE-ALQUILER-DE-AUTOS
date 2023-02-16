#include "Menu.h"

void Menu::menu_principal()
{
    int op;
    do
    {
        std::cout<<"MENU PRINCIPAL"<<std::endl;

        std::cout<<"1.ALQUILER"<<std::endl;
        std::cout<<"2.AUTOS"<<std::endl;
        std::cout<<"3.SOCIOS"<<std::endl;
        std::cout<<"4.CLIENTES"<<std::endl<<std::endl;
        std::cout<<"0.SALIR"<<std::endl<<std::endl<<std::endl;

        std::cin>>op;
        switch(op)

        {
        case 1:
            system("cls");
            this->menu_alquiler();

            break;
        case 2:
            system("cls");
            this->menu_auto();

            break;
        case 3:
            system("cls");
            this->menu_socio();

            break;
        case 4:
            system("cls");
            this->menu_cliente();
            break;
        case 0:
            break;
        default:
            std::cout<<"Opcion inexistente, vuelva a ingresar la opcion"<<std::endl;
            system("pause");
            system("cls");
            break;
        }
        system("cls");
    }
    while(op!=0);
}


void Menu::menu_alquiler()
{
    int op;
    Alquiler a;


    do
    {
        std::cout<<"ALQUILER"<<std::endl;
        std::cout<<"1.NUEVO"<<std::endl;
        std::cout<<"2.FINALIZAR"<<std::endl;
        std::cout<<"3.BAJA"<<std::endl;
        std::cout<<"4.ALQUILERES ACTIVOS"<<std::endl;
        std::cout<<"5.ALQUILERES FINALIZADOS"<<std::endl<<std::endl;

        std::cout<<"0.VOLVER"<<std::endl<<std::endl;

        std::cin>>op;
        switch(op)

        {
        case 1:
            system("cls");
            if(a.CeroAutos()){

                a.Nuevo();
                a.modificarArchivo(a,a.getNroAlquiler()-1);
                system("pause");
            }
            else{
                std::cout<<"NO HAY AUTOS DISPONIBLES"<<std::endl;
                system("pause");
            }

            break;
        case 2:
            system("cls");
            a.Finalizar();
            system("pause");

            break;
        case 3:
            system("cls");
            a.Baja();
            system("pause");

            break;
        case 4:
            system("cls");
            a.AlquileresActivos();
            system("pause");

            break;
        case 5:
            system("cls");
            a.AlquileresFinalizados();
            system("pause");

            break;
        case 0:
            system("cls");
           // this->menu_principal();
           return;
            break;
        default:
            std::cout<<"Opcion inexistente, vuelva a ingresar la opcion"<<std::endl;
            system("pause");
            system("cls");
            break;
        }
        system("cls");
    }
    while(op!=0);
}


void Menu::menu_auto()
{
    int op;
    Auto a;
    do
    {
        std::cout<<"AUTO"<<std::endl;
        std::cout<<"1.NUEVO"<<std::endl;
        std::cout<<"2.HABILITAR/INHABILITAR"<<std::endl;
        std::cout<<"3.BAJA"<<std::endl;
        std::cout<<"4.AUTOS HABILITADOS"<<std::endl;
        std::cout<<"5.AUTOS INHABILITADOS"<<std::endl<<std::endl;

        std::cout<<"0.VOLVER"<<std::endl<<std::endl;

        std::cin>>op;
        switch(op)

        {
        case 1:
            system("cls");
            a.Nuevo();
            a.grabarEnDisco();
            break;
        case 2:
            system("cls");
            a.Habilitacion();
            system("pause");

            break;
        case 3:
            system("cls");
            a.Baja();
            system("pause");

            break;
        case 4:
            system("cls");
            a.MostrarHabilit();
            system("pause");
            break;
        case 5:
            system("cls");
            a.MostrarInhabilit();
            system("pause");
            break;
        case 0:
            system("cls");
           // this->menu_principal();
            return;
            break;
        default:
            std::cout<<"Opcion inexistente, vuelva a ingresar la opcion"<<std::endl;
            system("pause");
            system("cls");
            break;
        }
        system("cls");
    }
    while(op!=0);
}


void Menu::menu_socio()
{
    int op;
    Cliente a;
    do
    {
        std::cout<<"SOCIOS"<<std::endl;
        std::cout<<"1.ALTA/BAJA"<<std::endl;
        std::cout<<"2.LISTA DE SOCIOS"<<std::endl<<std::endl;

        std::cout<<"0.VOLVER"<<std::endl<<std::endl;

        std::cin>>op;
        switch(op)

        {
        case 1:
            system("cls");
            a.AltaBajaSocio();
            system("pause");

            break;
        case 2:
            system("cls");
            a.ListadoSocios();
            system("pause");

            break;
        case 0:
            system("cls");
            this->menu_principal();
            break;
        default:
            std::cout<<"Opcion inexistente, vuelva a ingresar la opcion"<<std::endl;
            system("pause");
            system("cls");
            break;
        }
        system("cls");
    }
    while(op!=0);
}


void Menu::menu_cliente()
{
    int op;
    Cliente a;
    do
    {
        std::cout<<"CLIENTES"<<std::endl;
        std::cout<<"1.NUEVO"<<std::endl;
        std::cout<<"2.BAJA"<<std::endl;
        std::cout<<"3.BUSCAR POR DNI"<<std::endl;
        std::cout<<"4.LISTADO DE CLIENTES "<<std::endl<<std::endl;

        std::cout<<"0.VOLVER"<<std::endl<<std::endl;

        std::cin>>op;
        switch(op)

        {
        case 1:
            system("cls");
            a.Nuevo();
            a.modificarArchivo(a,a.getNroCliente1()-1);
            break;
        case 2:
            system("cls");
            a.Baja();

            break;
        case 3:
            system("cls");
            a.buscarDNI();
            system("pause");

            break;
        case 4:
            system("cls");
            a.ListadoClientes();
            system("pause");

            break;
        case 0:
            system("cls");
         //   this->menu_principal();
            break;
        default:
            std::cout<<"Opcion inexistente, vuelva a ingresar la opcion"<<std::endl;
            system("pause");
            system("cls");
            break;
        }
        system("cls");
    }
    while(op!=0);
}

