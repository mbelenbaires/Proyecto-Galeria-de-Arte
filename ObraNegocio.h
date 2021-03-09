#ifndef OBRANEGOCIO_H_INCLUDED
#define OBRANEGOCIO_H_INCLUDED
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "Obra.h"
#include "VentaNegocio.h"
#include "Autor.h"
#include "AutorNegocio.h"
using namespace std;

int cantidadRegistros(){
Obra reg;
{
    int byte;
    FILE *p;
    p=fopen("pinturas.dat","rb");
    if(p==NULL) {return 0;}
    fseek(p,0,2);
    byte=ftell(p);
    fclose(p);
    return byte/sizeof(reg);
}
}

void Obra::cargar(){
Autor reg;
int c;
c=cantidadRegistros();
cout<<"Código: "<<(c+1);
codigo=c+1; cout<<endl;
cout << "Título: ";
  cin.ignore();
  cin.getline(titulo,50);
  cout << "Nombre del artista: ";
  cin.getline(nombrea,20);
    cout << "Apellido del artista: ";
  cin.getline(apellidoa,20);
   cout << "País de origen: ";
  cin.getline(pais,20);

  if (buscarAutor(nombrea,apellidoa)) {reg.generarAutor(nombrea, apellidoa, pais);}

  cout<<"Año de producción: ";
  cin>>anio;
  cout << "Color predominante: ";
  cin.ignore();
  cin.getline(color, 15);
  cout<<"Medio: ";
  cin.getline(medio,20);
  cout << "Alto (cm): ";
  cin >> alto;
  cout << "Ancho (cm): ";
  cin >> ancho;
  cout<<"Precio (en miles): ";
  cin>>precio;
  stock=true;
}

void Obra::guardarDisco(){
  FILE *p;
  p = fopen("pinturas.dat", "ab");
  if (p==NULL){cout<<"Error de grabación."; exit (1);}

if (fwrite(this, sizeof(Obra), 1, p)==1); cout<<"Grabado correctamente."<<endl; fclose(p);
}



void Obra::alta(){
cargar();
guardarDisco();}

bool Obra::leerDisco(int pos){
  FILE *p;
  p = fopen("pinturas.dat", "rb");
  bool TodoOK;
  fseek(p, pos * sizeof(Obra), 0);
  TodoOK=fread(this, sizeof(Obra), 1, p);
  fclose(p);
  return TodoOK;
}

void stockTitulo(){
char t[50];
Obra reg;
int pos=0,c=0;
cout<<"Ingrese el título a buscar: ";
cin.ignore();
cin.getline(t,50);
cout<<endl;

    while (reg.leerDisco(pos)){

        if ((stricmp(t,reg.gettitulo())==0) && (reg.getstock()))

            {
            reg.mostrar(); c++;
            }
        pos++;
        }  if (c==0){cout<<"No hay obras disponibles con este título."<<endl;}
}

void stockCodigo(){
int pos=0,cod,c=0;
Obra reg;
cout<<"Ingrese código a buscar: ";
cin>>cod;
cout<<endl;

    while (reg.leerDisco(pos)){

        if ((reg.getcodigo()==cod) && (reg.getstock())){
            reg.mostrar(); c++;}
        pos++;
        }  if (c==0){cout<<"La obra no se encuentra disponible."<<endl<<endl;}
}

void stockAutor(){
char n[20],a[20];
Obra reg;
int pos=0,c=0;
cout<<"Ingrese nombre del autor: ";
cin.ignore();
cin.getline(n,20);
cout<<"Ingrese apellido del autor: ";
cin.getline(a,20);
cout<<endl;

    while (reg.leerDisco(pos)){

        if ((((stricmp(n,reg.getnombrea())==0) && ((stricmp(a,reg.getapellidoa())==0) || strlen(a)<1)) || ( ((stricmp(a,reg.getapellidoa())==0) && strlen(n)<1)))&& (reg.getstock()))

            {
            reg.mostrar(); c++;
            }
        pos++;
        }  if (c==0){cout<<"No hay obras disponibles de este autor."<<endl;}
}

void stockAnio(){
int pos=0,c=0,a,b;
Obra reg;
cout<<"Ingrese el rango de años para buscar obras. "<<endl;
cout<<"Desde: "; cin>>a;
cout<<"Hasta: "; cin>>b; cout<<endl;

    while (reg.leerDisco(pos)){

        if (reg.getanio()>=a && reg.getanio()<=b && (reg.getstock()) ){
            reg.mostrar(); c++;}
        pos++;
        }  if (c==0){cout<<"No hay obras disponibles en estos años."<<endl;}
}

void stockPrecio(){
int pos=0,c=0;
float p1,p2;
Obra reg;
cout<<"Ingrese el rango de precios para buscar obras. "<<endl;
cout<<"Mínimo: $"; cin>>p1;
cout<<"Máximo: $"; cin>>p2; cout<<endl;

    while (reg.leerDisco(pos)){

        if (reg.getprecio()>=p1 && reg.getprecio()<=p2 && (reg.getstock())){
            reg.mostrar(); c++;}
        pos++;
        }  if (c==0){cout<<"No hay obras disponibles en este rango de precios."<<endl;}
}

void Obra::mostrar(){
cout<<"Código: "<<codigo<<endl;
cout << "Título: "<<titulo<<endl;
cout << "Nombre del artista: "<<nombrea<<endl;
cout << "Apellido del artista: "<<apellidoa<<endl;
cout << "País de origen: "<<pais<<endl;
cout<<"Año de producción: "<<anio<<endl;
cout << "Color predominante: "<<color<<endl;
cout<<"Medio: "<<medio<<endl;
cout << "Alto (cm): "<<alto<<endl;
cout << "Ancho (cm): "<<ancho<<endl;
cout<<"Precio (en miles): $"<<precio<<endl;
cout<<"Stock: "; if (stock){cout<<"Sí"<<endl<<endl;} else {cout<<"No"<<endl<<endl;}
}

 void modificarStock(int *v, int c){
Obra reg;
int i;
for (i=0;i<c;i++){
        if(v[i]>=0){
FILE *p;
  p = fopen("pinturas.dat", "rb");
  if (p==NULL)exit(1);
fseek(p, v[i] * sizeof(reg), 0);
fread(&reg, sizeof(reg), 1, p);
reg.setstock(false);
fclose(p);


    FILE *a;
    a=fopen("pinturas.dat","rb+");
    if(a==NULL){exit(1); cout<<"roto";}

    fseek(a, sizeof(Obra)*v[i],0);
    if (fwrite(&reg, sizeof(Obra), 1, a)==1) {cout<<"Stock modificado correctamente."<<endl; fclose(a);} else cout<<"Error al grabar."; fclose(a);
}
}
}

void Obra::comprar(){
int pos=0,cod,cant=0,i,c=0;
Venta obj;
int *v,*p;

cout<<"Indique la cantidad de obras a comprar: ";
cin>>cant;

v=(int *)malloc(cant*sizeof(int));
p=(int *)malloc(cant*sizeof(int));

for (i=0;i<cant;i++){
cout<<"Ingrese el código de la obra para comprarla: ";
cin>>cod;
c=0; pos=0;
while (leerDisco(pos)){
    if ((codigo==cod)&& (stock==true)){v[i]=cod; p[i]=pos; c++;}
pos++;

}      if (c==0) {cout<<"Código incorrecto."; cout<<endl; v[i]=0; p[i]=-1;}
}
obj.generarVenta(v,cant); modificarStock(p,cant);
free(v);
free(p);
}



int cantidadDisponibles(){
{
    Obra reg;
    int c=0,pos=0;
    while (reg.leerDisco(pos)){
        if (reg.getstock()) c++;
        pos ++;
    }
    return c;
}
}


void listarDisponibles(){
Obra reg;
int pos=0,c=0;
while (reg.leerDisco(pos++)){
        if (reg.getstock()) {reg.mostrar(); c++;}

}
if (c==0){cout<<"No hay obras disponibles."<<endl;}
}

void listarVendidas(){
Obra reg;
int c=0;
int pos=0;
while (reg.leerDisco(pos++)){
        if (reg.getstock()==false) {reg.mostrar(); c++;}

}
if (c==0){cout<<"No se vendieron obras aún."<<endl;}
}

void filtrar(){
Obra reg;
int pos=0,an,c=0;
char pa[20],col[15],me[20],o1[2],o2[2],o3[2],o4[2],o5[2],o6[2];
float p1=0,p2=0,ancho1=0, ancho2=0, alto1=0, alto2=0;

cout<<"¿Desea filtrar por precio? S/N"<<endl;
cin>>o1;
if (stricmp(o1,"S")==0){
cout<<"PRECIO: Mínimo: $"; cin>>p1; cout<<"Máximo: $"; cin>>p2; cout<<endl;}


cout<<"¿Desea filtrar por tamaño? S/N"<<endl;
cin>>o5;
if (stricmp(o5,"S")==0){
cout<<"ANCHO: Mínimo: "; cin>>ancho1; cout<<"Máximo: "; cin>>ancho2; cout<<endl;
cout<<"ALTO: Mínimo: "; cin>>alto1; cout<<"Máximo: "; cin>>alto2; cout<<endl;}

cout<<"¿Desea filtrar por año de producción? S/N"<<endl;
cin>>o3;
if (stricmp(o3,"S")==0){
cout<<"AÑO: "; cin>>an; cout<<endl;}

cout<<"¿Desea filtrar por país de producción? S/N"<<endl;
cin>>o2;
if (stricmp(o2,"S")==0){
cout<<"PAÍS: "; cin.ignore(); cin.getline(pa,20); cout<<endl;}

cout<<"¿Desea filtrar por color? S/N"<<endl;
cin>>o4;
if (stricmp(o4,"S")==0){
cout<<"COLOR: "; cin.ignore(); cin.getline(col,15); cout<<endl;}

cout<<"¿Desea filtrar por medio? S/N"<<endl;
cin>>o6;
if (stricmp(o6,"S")==0){
cout<<"MEDIO: "; cin.ignore(); cin.getline(me,20); cout<<endl;}



     while (reg.leerDisco(pos++)){

        if (reg.getstock()){
            if (
            (((stricmp(o1,"S")==0) && (reg.getprecio()>=p1) && (reg.getprecio()<=p2)) || (stricmp(o1,"N")==0))
            && (((stricmp(o2,"S")==0) && (stricmp(reg.getpais(),pa)==0)) || (stricmp(o2,"N")==0))
            && (((stricmp(o3,"S")==0) && (reg.getanio()==an)) || (stricmp(o3,"N")==0))
            && (((stricmp(o4,"S")==0) && (stricmp(reg.getcolor(),col)==0)) || (stricmp(o4,"N")==0))
            && (((stricmp(o5,"S")==0) && (reg.getancho()<=ancho2) && (reg.getancho()>=ancho1) && (reg.getalto()<=alto2) && (reg.getalto()>=alto1)) || (stricmp(o5,"N")==0))
            && (((stricmp(o6,"S")==0) && (stricmp(reg.getmedio(),me)==0)) || (stricmp(o6,"N")==0)) )

            {cout<<endl<<"Se encontraron las siguientes obras:"<<endl; reg.mostrar(); c++;}}}
            if(c==0) {cout<<"No hay obras disponibles con estas características."<<endl;
}}

void maxObra(){
Obra reg;
int pos=0, c=0;
float maxx=0;
char t[50];
while (reg.leerDisco(pos++)){
    if ((reg.getstock()!=true) && (reg.getprecio()>maxx)){maxx=reg.getprecio(); strcpy(t,reg.gettitulo()); c++;}
}
if(c==0){cout<<"Todavía no se vendió ninguna obra."<<endl;}
else {cout<<"La obra más cara vendida fue '"<<t<<"' por $"<<maxx<<" mil."<<endl;}

}



#endif // OBRANEGOCIO_H_INCLUDED
