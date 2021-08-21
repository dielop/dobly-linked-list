#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
     int dato;
     struct nodo *anterior;
     struct nodo *siguiente;
 }lista;

void insertar (lista **i, int d);
void listar (lista **i);
void eliminar (lista **i, int d);

int main (){
 lista *inicio;
 inicio = NULL;

 insertar (&inicio, 5);
 insertar (&inicio, 3);
 insertar (&inicio, 4);
 insertar (&inicio, 10);
 insertar (&inicio, 6);
 insertar (&inicio, 8);
 insertar (&inicio, 1);
 insertar (&inicio, 8);
 insertar (&inicio, 1);

 printf ("Listando elementos:\n");
 listar (&inicio);
 printf ("Fin del listado.\n");

 eliminar(&inicio, 4);
 eliminar(&inicio, 1);
 eliminar(&inicio, 10);
 eliminar(&inicio, 14);

 printf ("Listando elementos:\n");
 listar (&inicio);
 printf ("Fin del listado.\n");

 return 0;
}

void insertar (lista **i, int d){
 if (*i == NULL ){
    printf ("Insertando %d en la lista \n", d);
    *i = (lista *) malloc (sizeof(lista));
    (*i) -> dato = d;
    (*i) -> siguiente = NULL;
 }else{
// cuando va al inicio
   if ((*i) -> dato > d){ 
            printf ("Insertando %d en la lista \n", d);
            lista* nuevo = (lista *) malloc (sizeof(lista));
            nuevo -> dato = d;
            nuevo -> siguiente = *i;
            nuevo -> anterior = NULL;
            *i = nuevo;
   }else if ((*i) -> dato < d && (*i) -> siguiente != NULL && (*i) -> siguiente -> dato > d){
// cuando esta entre dos
            printf ("Insertando %d en la lista \n", d);
            lista * nuevo = ( lista *) malloc ( sizeof ( lista));
            nuevo->dato = d;
            nuevo->siguiente = (*i)->siguiente;
            (*i)->siguiente->anterior = nuevo;
            nuevo->anterior = *i;
            (*i)->siguiente = nuevo;
  }else if ((*i)->dato<d && (*i)->siguiente == NULL){
            printf ("Insertando %d en el final de la lista \n",d);
            lista *nuevo = (lista *)malloc(sizeof(lista));
            nuevo->dato = d;
            nuevo->siguiente = NULL;
            nuevo->anterior = *i;
            (*i)->siguiente = nuevo;
  }else if ((*i) ->dato == d){
            printf ("Ya existe el elemento %d en la lista \n",d);
  }else{
            insertar (&(*i) -> siguiente, d);
       }
  }
}

void listar (lista **i){

 if (*i == NULL ){
    printf ("no hay elementos restantes\n");
    }else{
    printf ("%d -> ", (*i) -> dato); 
    listar (&(*i) -> siguiente);
   }
}

void eliminar (lista **i, int d){

 if (*i == NULL ){
    printf ("No existe el elemento a eliminar\n");
 }else{
 if ((*i) -> dato == d){
 // elimino al primero
    printf ("Elimino %d\n", d);
    lista * aux = (*i);
    (*i) = (*i) -> siguiente;
    free (aux);
 }else if ((*i) -> dato < d && (*i) -> siguiente != NULL && (*i)-> siguiente -> dato == d){
 // elimino al siguiente
    printf ("Elimino %d\n", d);
    lista * aux = (*i) -> siguiente;
    (*i) -> siguiente = (*i) -> siguiente -> siguiente;
    free(aux);
 }else
   eliminar (&(*i) -> siguiente, d);
 }
}