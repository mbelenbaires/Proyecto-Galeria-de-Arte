#ifndef SUBMENUES_H_INCLUDED
#define SUBMENUES_H_INCLUDED
#include "Obra.h"
#include "Cliente.h"
#include "Venta.h"
#include "Autor.h"
#include "ObraNegocio.h"
#include "ClienteNegocio.h"
#include "VentaNegocio.h"
#include "AutorNegocio.h"

void submenuListados(){
    int opc;

while (true){
system("cls");
    cout << "LISTADOS" << endl;
    cout << "--------------------" << endl;
    cout << "1) OBRAS DISPONIBLES" << endl;
    cout<<"2) ARTISTAS EN LA GALER�A"<<endl;
    cout << "3) OBRAS VENDIDAS" << endl;
   cout << "4) RECOMENDACI�N POR FILTRO" << endl;
    cout << "5) CLIENTES" << endl;
    cout << "6) VENTAS" << endl;
    cout << "-------------------" << endl;
    cout << "0) VOLVER AL MEN� PRINCIPAL" << endl;
    cout << "OPCI�N: ";
    cin >> opc;
    system("cls");
    switch(opc){
    case 1:
        listarDisponibles();
        break;
            case 2:
        listarAutoresDisponibles();
        break;
    case 3:
        listarVendidas();
        break;
    case 4:
        filtrar();
        break;
    case 5:
        listarClientes();
        break;
    case 6:
        listarVentas();
        break;

    case 0:
        return;
        break;
    } system("pause");}}

void submenuConsultas(){
    int opc;
while (true){
system("cls");
    cout << "CONSULTAS" << endl;
    cout << "--------------------" << endl;
    cout << "1) STOCK POR T�TULO" << endl;
    cout << "2) STOCK POR C�DIGO" << endl;
    cout << "3) STOCK POR AUTOR" << endl;
    cout << "4) STOCK POR A�O DE PRODUCCI�N" << endl;
    cout << "5) STOCK POR PRECIO" << endl;
    cout << "6) RECAUDACI�N POR A�O" << endl;
    cout << "7) ARTISTAS QUE HAN EXPUESTO EN LA GALER�A" << endl;
    cout << "8) OBRA M�S CARA VENDIDA" << endl;
    cout << "-------------------" << endl;
    cout << "0) VOLVER AL MEN� PRINCIPAL" << endl;
    cout << "OPCI�N: ";
    cin >> opc;
    system("cls");
    switch(opc){
    case 1:
        stockTitulo();
        break;
    case 2:
        stockCodigo();
        break;
    case 3:
        stockAutor();
        break;
    case 4:
        stockAnio();
        break;
        case 5:
        stockPrecio();
        break;
        case 6:
        recaudacionxAnio();
        break;
        case 7:
        listarAutores();
        break;
        case 8:
        maxObra();
        break;
    case 0:
        return;
        break;
    } system("pause");}}


#endif //SUBMENUES_H_INCLUDED
