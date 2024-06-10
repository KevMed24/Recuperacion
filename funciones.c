#include <stdio.h>
#include "funciones.h"
#include <string.h>


void verPersonas(char personas[][4][20]){
    printf("Nombre\t\tApellido\tCedula\t\tEstado Civil\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s\t\t%s\t\t%s\t\t%s\n",personas[i][0],personas[i][1],personas[i][2],personas[i][3]);
    }
    
}

void registrarMatrimonio(char personas[][4][20]) {
    char cedula1[20];
    char cedula2[20];
    printf("Ingrese el numero de cedula de la primera persona: ");
    scanf("%s", cedula1);
    printf("Ingrese el numero de cedula de la segunda persona: ");
    scanf("%s", cedula2);

    int index1 = buscarPersonaXCedula(personas, cedula1);
    int index2 = buscarPersonaXCedula(personas, cedula2);

    if (index1 == -1 || index2 == -1) {
        printf("No se encontraron personas con esas cedulas.\n");
        return;
    }

    strcpy(personas[index1][3], cedula2);
    strcpy(personas[index2][3], cedula1);

    printf("Matrimonio registrado\n");
}

void verificarPersona(char personas[][4][20]) {
    char cedula[20];
    printf("Ingrese el numero de cedula de la persona a verificar: ");
    scanf("%s", cedula);

    int index = buscarPersonaXCedula(personas, cedula);

    if (index == -1) {
        printf("No se encontro persona con esa cedula.\n");
        return;
    }

    printf("%s %s esta casado con %s.\n", personas[index][0], personas[index][1], personas[index][3]);
}

int buscarPersonaXCedula(char personas[][4][20], char cedula[20]) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(personas[i][2], cedula) == 0) {
            return i;
        }
    }
    return -1;
}