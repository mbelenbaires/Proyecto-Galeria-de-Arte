#ifndef CLIENTE_H
#define CLIENTE_H


class Cliente{
protected:
    char nombre[20],apellido[20],mail[30],dir[40];
    int dni;
public:
    char *getnombre(){return nombre;}
    char *getapellido(){return apellido;}
    char *getmail(){return mail;}
    char *getdir(){return dir;}
    int getdni(){return dni;}

    void mostrar();
    void guardarDisco();
    bool leerDisco(int);
    void generarCliente(char*n, char*a, char*m, char*d,int dn);

};





#endif // CLIENTE_H
