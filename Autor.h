#ifndef AUTOR_H_INCLUDED
#define AUTOR_H_INCLUDED
using namespace std;

class Autor{
protected:
    char nombre[20],apellido[20],pais[30];
public:
    char *getnombre(){return nombre;}
    char *getapellido(){return apellido;}
    char *getpais(){return pais;}

    void mostrar();
    void guardarDisco();
    bool leerDisco(int);
    void generarAutor(char*n, char*a, char*p);

};

#endif // AUTOR_H_INCLUDED
