#ifndef AUTORNEGOCIO_H_INCLUDED
#define AUTORNEGOCIO_H_INCLUDED
using namespace std;

void Autor::generarAutor(char*n, char*a ,char*p){
    strcpy(nombre,n);
    strcpy(apellido,a);
    strcpy(pais,p);
    guardarDisco();
}

void Autor::guardarDisco(){
FILE *p;
p = fopen("autores.dat", "ab");
  if (p==NULL){cout<<"Error de grabación."; exit (1);}

if (fwrite(this, sizeof(Autor), 1, p)==1); cout<<"Autor guardado."<<endl; fclose(p);
}

bool Autor::leerDisco(int pos){
FILE *p;
  p = fopen("autores.dat", "rb");
  if (p==NULL) {cout<<"No se encontraron autores."<<endl;}
  bool TodoOK;
  fseek(p, pos * sizeof(Autor), 0);
  TodoOK=fread(this, sizeof(Autor), 1, p);
  fclose(p);
  return TodoOK;
}

void Autor::mostrar(){
cout << "Nombre: "<<nombre<<endl;
cout << "Apellido: "<<apellido<<endl;
cout << "País de origen: "<<pais<<endl;
cout<<endl;
}

bool stockAutor2(char *n, char*a){
Obra reg;
int pos=0,c=0;

    while (reg.leerDisco(pos)){

        if ((stricmp(n,reg.getnombrea())==0) && (stricmp(a,reg.getapellidoa())==0) && (reg.getstock()))

            {
                c++; return true;
            }
        pos++;
        }  if (c==0){return false;}
}

void listarAutoresDisponibles(){
Autor reg;
int pos=0;
while (reg.leerDisco(pos++)){
        if (stockAutor2(reg.getnombre(), reg.getapellido()))
{reg.mostrar();
}}}

void listarAutores(){
Autor reg;
int pos=0;
while (reg.leerDisco(pos++)){
reg.mostrar();
}}

bool buscarAutor(char*n, char*a){
Autor reg;
int pos=0;

    while (reg.leerDisco(pos++)){
    if ( (stricmp(n, reg.getnombre())==0) && (stricmp(a, reg.getapellido())==0)    ){
    cout<<"El autor ya existe."<<endl;
    return false;
    }}
    return true;
}



#endif // AUTORNEGOCIO_H_INCLUDED
