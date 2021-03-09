#include <iostream>
#include <cstring>
#include <cstdio>
#include "submenues.h"
using namespace std;


int main(){
  int opc;
  Obra o;

  setlocale(LC_ALL, "Spanish");

   while(true){
    system("cls");
cout << "GALERÍA B.A." << endl;
  cout << "--------------------" << endl;
    cout << "1) INGRESAR PINTURA NUEVA" << endl;
   cout << "2) LISTADOS" << endl;
    cout << "3) CONSULTAS" << endl;
    cout << "4) COMPRAR"  <<endl;
   cout << "-------------------" << endl;
  cout << "0) SALIR DEL PROGRAMA" << endl;
   cout << "OPCIÓN: ";
    cin >> opc;
    system("cls");
    switch(opc){
    case 1:
    o.alta();
    break;
    case 2:
    submenuListados();
    break;
    case 3:
   submenuConsultas();
    break;
    case 4:
    o.comprar();
        break;
    case 0:
       return 0;
       break;
}
  //  system("pause");

}

return 0;
}
