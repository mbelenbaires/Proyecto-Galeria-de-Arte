#ifndef VENTA_H
#define VENTA_H
#include <iostream>
#include <cstring>
#include <cstdio>


class Venta{
private:
    char nombre[20],apellido[20],mail[30],dir[40];
    int dni;
    int anio;
    float total;
public:
   void setnombre(char *_nombre){strcpy (nombre,_nombre);}
    void setapellido(char *_apellido){strcpy(apellido,_apellido);}
    void setmail(char *_mail){strcpy(mail,_mail);}
    void setdir(char *_dir){strcpy(dir,_dir);}
    int getanio(){return anio;}
    int gettotal(){return total;}
     char *getnombre(){return nombre;}
    char *getapellido(){return apellido;}
    char *getmail(){return mail;}
    char *getdir(){return dir;}
    int getdni(){return dni;}

    void generarVenta(int *v, int cant);
    void generarFactura(int *v, int cant,float tot);
    void mostrar();
    void guardarDisco();
    bool leerDisco(int);

};

#endif // VENTA_H
