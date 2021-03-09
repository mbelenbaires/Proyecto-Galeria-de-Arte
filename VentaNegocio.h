#ifndef VENTANEGOCIO_H_INCLUDED
#define VENTANEGOCIO_H_INCLUDED
#include "ClienteNegocio.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

float calcularTotal(int *v,int cant){
Obra reg;
int i,pos;
float total=0;
for (i=0;i<cant;i++){
pos=0;
 while (reg.leerDisco(pos)){

        if (reg.getcodigo()==v[i]){
total+=reg.getprecio();
            }
        pos++;
        }
}
cout<<total;
return total;
}

void Venta::generarFactura(int *v, int cant, float tot){
Obra reg;
int i,pos=0;
ofstream archivo;
archivo.open("Factura.txt");
archivo<<"DATOS DEL CLIENTE: "<<endl;
archivo<<"DNI: "<<dni<<endl;
archivo<<"Cliente: "<<nombre<<" "<<apellido<<endl;
archivo<<"E-mail: "<<mail<<endl;
archivo<<"Dirección: "<<dir<<endl<<endl;
archivo<<"DATOS DE LA COMPRA: "<<endl;

 while (reg.leerDisco(pos)){
    for (i=0;i<cant;i++){
        if (reg.getcodigo()==v[i]){
archivo<<"Obra: "<<reg.gettitulo()<<endl;
archivo<<"Autor: "<<reg.getnombrea()<<" "<<reg.getapellidoa()<<endl;
archivo<<"Valor(en miles): $"<<reg.getprecio()<<endl<<endl;
            }
        }
         pos++;
}

archivo<<"Año: "<<anio<<endl;
archivo<<"Total(en miles): $"<<tot;
}

void Venta::generarVenta(int *v, int cant){
Cliente obj;
int i;
    cout<<"DATOS DEL CLIENTE: "<<endl;
    cout<<"DNI: "; cin>>dni;
    if (buscarCliente(dni)){
    cout<<"Nombre: "; cin.ignore(); cin.getline(nombre,20);
    cout<<"Apellido: "; cin.getline(apellido,20);
    cout<<"E-mail: "; cin.getline(mail,30);
    cout<<"Dirección: "; cin.getline(dir,40);
    obj.generarCliente(nombre,apellido,mail,dir,dni);
    } else {setnombre(fnombre(dni)); setapellido(fapellido(dni)); setmail(fmail(dni)); setdir(fdir(dni));}
    cout<<"Año de la venta: "; cin>>anio;

total=calcularTotal(v,cant);
guardarDisco();
generarFactura(v,cant,total);
}



void Venta::guardarDisco(){
  FILE *p;
  p = fopen("ventas.dat", "ab");
  if (p==NULL){cout<<"Error al grabar la venta."; exit (1);}

if (fwrite(this, sizeof(Venta), 1, p)==1); cout<<"Grabado correctamente."<<endl; fclose(p);
}



bool Venta::leerDisco(int pos){
FILE *p;
  p = fopen("ventas.dat", "rb");
  if (p==NULL) {cout<<"No se encontraron ventas."<<endl;}
  bool TodoOK;
  fseek(p, pos * sizeof(Venta), 0);
  TodoOK=fread(this, sizeof(Venta), 1, p);
  fclose(p);
  return TodoOK;
}

int cantidadObras(int *v){
Venta reg;
{
    int byte;
    FILE *p;
    p=fopen("ventas.dat","rb");
    if(p==NULL) {return 0;}
    fseek(p,0,2);
    byte=ftell(p);
    fclose(p);
    return byte/sizeof(reg);
}
}

void Venta::mostrar(){
cout<<"DATOS DEL CLIENTE: "<<endl;
cout<<"Dni: "<<dni<<endl;
cout<<"Cliente: "<<nombre<<" "<<apellido<<endl;
cout<<"E-mail: "<<mail<<endl;
cout<<"Dirección: "<<dir<<endl<<endl;
cout<<"DATOS DE LA COMPRA: "<<endl;
cout<<"Año: "<<anio<<endl;
cout<<"Total(en miles): $"<<total<<endl<<endl<<endl;
}

void listarVentas(){
Venta reg;
int pos=0;
while (reg.leerDisco(pos++)){
    reg.mostrar();
}
}

int cantidadVentas(){
{
Venta reg;
int c=0,pos=0;
    while (reg.leerDisco(pos)){
        c++;
        pos ++;
    }
    return c;
}
}

void recaudacionxAnio(){
Venta reg;
int a, pos=0,c=0;
cout<<"Ingrese el año para obtener la recaudación total: ";
cin>>a;
float totalanio=0;
while (reg.leerDisco(pos++)){
    if (reg.getanio()==a){
        totalanio+=reg.gettotal();
        c++;
    }
}

cout<<"En el año "<<a<<" la recaudación fue de $"<<totalanio<<" mil."<<endl;
}





#endif // VENTANEGOCIO_H_INCLUDED
