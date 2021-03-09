#ifndef CLIENTENEGOCIO_H_INCLUDED
#define CLIENTENEGOCIO_H_INCLUDED
using namespace std;

void Cliente::generarCliente(char*n, char*a ,char*m, char*d, int dn){
    strcpy(nombre,n);
    strcpy(apellido,a);
    strcpy(mail,m);
    strcpy(dir,d);
    dni=dn;

    guardarDisco();
}

void Cliente::guardarDisco(){
FILE *p;
p = fopen("clientes.dat", "ab");
  if (p==NULL){cout<<"Error de grabación."; exit (1);}

if (fwrite(this, sizeof(Cliente), 1, p)==1); cout<<"Cliente guardado."<<endl; fclose(p);
}

bool Cliente::leerDisco(int pos){
FILE *p;
  p = fopen("clientes.dat", "rb");
  if (p==NULL) {cout<<"No se encontraron clientes."<<endl;}
  bool TodoOK;
  fseek(p, pos * sizeof(Cliente), 0);
  TodoOK=fread(this, sizeof(Cliente), 1, p);
  fclose(p);
  return TodoOK;
}

void Cliente::mostrar(){
cout<<"DNI: "<<dni<<endl;
cout << "Nombre: "<<nombre<<endl;
cout << "Apellido: "<<apellido<<endl;
cout << "E-mail: "<<mail<<endl;
cout << "Dirección: "<<dir<<endl;
cout<<endl;
}

void listarClientes(){
Cliente reg;
int pos=0;
while (reg.leerDisco(pos++)){
reg.mostrar();
}}

bool buscarCliente(int d){
Cliente reg;
int pos=0;

    while (reg.leerDisco(pos++)){
    if (reg.getdni()==d){
    cout<<"El cliente ya existe."<<endl;
    return false;
    }}
    return true;
}



char *fnombre(int d){
Cliente reg;
int pos=0;

    while (reg.leerDisco(pos++)){
    if (reg.getdni()==d){
    return (reg.getnombre());
    }}
}

char *fapellido(int d){
Cliente reg;
int pos=0;

    while (reg.leerDisco(pos++)){
    if (reg.getdni()==d){
    return reg.getapellido();
    }}
}

char *fmail(int d){
Cliente reg;
int pos=0;

    while (reg.leerDisco(pos++)){
    if (reg.getdni()==d){
    return reg.getmail();
    }}
}

char *fdir(int d){
Cliente reg;
int pos=0;

    while (reg.leerDisco(pos++)){
    if (reg.getdni()==d){
    return reg.getdir();
    }}
}



#endif // CLIENTENEGOCIO_H_INCLUDED
