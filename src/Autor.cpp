#include "Autor.h"

Autor::Autor()
{
(char *c=”0000”, char *d=”0000”, float p=0, int s=0){
strcpy(codArt, c);
strcpy(desc, d);
pu=p;
stock=s;
}

Autor::~Autor()
{
    //dtor
}
