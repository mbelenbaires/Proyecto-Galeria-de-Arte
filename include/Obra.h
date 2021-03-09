#ifndef OBRA_H
#define OBRA_H


class Obra{
  protected:
    char titulo[50], color[15], nombrea[20], apellidoa[20], pais[20], medio[20];
    float precio;
    float ancho;
    float alto;
    int anio, anioventa, codigo;
    bool stock;

  public:
    void setstock(bool _stock){stock=_stock;}

    char *gettitulo(){return titulo;};
    char *getcolor(){return color;}
    char *getnombrea(){return nombrea;}
    char *getapellidoa(){return apellidoa;}
    char *getpais(){return pais;}
    float getprecio(){return precio;}
    float getancho(){return ancho;}
    float getalto(){return alto;}
    int getanio(){return anio;}
    int getanioventa(){return anioventa;}
    bool getstock(){return stock;}
    char *getmedio(){return medio;}
    int getcodigo(){return codigo;}

    void cargar();
    void alta();
    void mostrar();
    void guardarDisco();
    bool leerDisco(int pos);
    void comprar();

};

#endif // OBRA_H
