#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct estructura{
    int codigo;
    char nombre[10];
    struct estructura *siguiente;
} nodo;

typedef nodo *pNodo;
//typedef nodo *Cola;

nodo* nuevo();
void encolar(pNodo*, pNodo*, int, char*);
void procesar(pNodo*,pNodo*);
void mostrarCola(pNodo*);

void tamanoCola(pNodo*);
void encontrarElemento(pNodo*, int);
bool esVacia(pNodo*);
void empty(pNodo*);


int main()
{

    pNodo primero = NULL;
    pNodo ultimo = NULL;


    encolar(&primero,&ultimo, 20, "Luis1");
    encolar(&primero,&ultimo, 21, "Luis2");
    encolar(&primero,&ultimo, 22, "Luis3");
    encolar(&primero,&ultimo, 23, "Luis4");
    encolar(&primero,&ultimo, 24, "Luis5");
    encolar(&primero,&ultimo, 25, "Luis6");
    encolar(&primero,&ultimo, 26, "Luis7");

    //mostrarCola(&primero);


    char nombre[10];
    int codigo = 0;

    int menu = 0;



    while(menu != 6){


        printf("0) Insertar\n");
        printf("1) Sacar\n");
        printf("2) Vaciar\n");
        printf("3) Mostrar\n");
        printf("4) Tamanyo Cola\n");
        printf("5) Buscar Elemento\n");
        printf("6) Salir\n");
        printf("Que quieres hacer: ");
        scanf("%i", &menu);
        fseek(stdin,0,SEEK_END);
        printf("\n");
        system("cls");

        switch(menu){
            case 0:
                // PEDIR DATOS
                printf("Dime codigo: ");
                scanf("%i", &codigo);
                printf("Dime nombre: ");
                scanf("%s", &nombre);
                fseek(stdin,0,SEEK_END);

                // AÑADIR a COLA
                encolar(&primero,&ultimo, codigo, nombre);

                // MOSTRAR RESULTADO
                mostrarCola(&primero);

                break;
            case 1:
                procesar(&primero,&ultimo);
                mostrarCola(&primero);
                break;
            case 2:
                empty(&primero);
                mostrarCola(&primero);
                break;
            case 3:
                mostrarCola(&primero);
                break;
            case 4:
                tamanoCola(&primero);
                break;
            case 5:
                 // PEDIR DATOS
                printf("Dime codigo: ");
                scanf("%i", &codigo);

                // BUSCAR
                encontrarElemento(&primero, codigo);

                break;
            case 6 :
                printf("Bye :)\n");
                break;
            default:
                printf("\nNo te he entendido.\n\n");

        }
    }

    return 0;
}

nodo* nuevo(){
    nodo *p;
    p = (nodo*) malloc(sizeof(nodo));
    p->siguiente = NULL;
    return(p);
}

bool esVacia(pNodo *primero){
    pNodo miNodo;
    miNodo = *primero;
    return miNodo == NULL;
}

void empty(pNodo *primero){
    pNodo miNodo;
    int next = 0;
    do {
        miNodo = *primero;
        if(miNodo){
            *primero = miNodo->siguiente;

            free(miNodo);
        } else{
            next = 1;
        }
    } while(next == 0);
    //*ultimo = NULL;
}

void encolar(pNodo *primero, pNodo *ultimo, int v, char* n){

    pNodo miNodo; // Variable auxiliar para manipular un nodo
    // Crear un nodo nuevo

    miNodo = nuevo();
    miNodo->codigo = v;
    strcpy (miNodo->nombre, n) ;
    // Este sera el ultimo nodo, no debe tener siguiente
    miNodo->siguiente = NULL;
    // 51 la cola no estaba vacia, affadimos el nuevo a continuacion de ultimo

    if(*ultimo)
    {
        (*ultimo)->siguiente = miNodo;
    }
    // Ahora, el ultimo elemento de la cola es el nuevo nodo

    *ultimo = miNodo;
    //Si primero es NULL, la cola estaba vacia
    //Ahora primero apuntara tambien al nuevo nodo
    if (!*primero)
    {
        *primero = miNodo;
    }


}

void procesar(pNodo *primero, pNodo *ultimo){

    pNodo miNodo;

    miNodo = *primero;
    if (miNodo)
    {
        *primero = miNodo->siguiente;

        printf ("Codigo: %d\t", miNodo->codigo) ;
        printf ("Nombre: %s", miNodo->nombre) ;
        printf ("\n") ;

        free (miNodo) ;

        if ( ! *primero)
        {
            *ultimo = NULL;
        }
    }


}

void mostrarCola(pNodo *primero){
    pNodo miNodo;
    miNodo = *primero;
    printf("\nCOLA: \n");
    while(miNodo != NULL){
        printf("Codigo: %d, Nombre: %s\n", miNodo->codigo, miNodo->nombre);
        miNodo = miNodo->siguiente;
    }
    printf("\n");
}

void encontrarElemento(pNodo *primero, int codigo){
    pNodo miNodo;
    miNodo = *primero;

    if(!esVacia(primero)){
        int indice = 0;
        int timesFound = 0;
        while(miNodo != NULL){
            if(codigo == miNodo->codigo){
                printf("Encontrado en el indice %i.\n",indice);
                timesFound++;
            }
            indice++;
            miNodo = miNodo->siguiente;

        }
        if(timesFound==0){
            printf("No se ha encontrado el elemento...");
        }
    } else {
        printf("La cola esta vacia.\n\n");
    }

    printf("\n\n");


}


void tamanoCola(pNodo *primero){
    pNodo miNodo;
    miNodo = *primero;

    int size = 0;

    if(!esVacia(primero)){
        while(miNodo != NULL){
            size++;
            miNodo = miNodo->siguiente;
        }
        printf("La cola tiene %i elementos.\n\n", size);
    } else {
        printf("La cola esta vacia.\n\n");
    }
}

