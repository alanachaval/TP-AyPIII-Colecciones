#include "Coleccion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char** argv){
	{
		Coleccion* coleccion = malloc(sizeof(Coleccion));
		int enteros[] = {1, 2 ,3};
		coleccion_inicializar(coleccion, enteros, sizeof(int), sizeof(enteros)/sizeof(int));
		printf("Elemento 2: %d (Debe ser 2)\n", *(int*)*(coleccion->coleccion + 1));
		free(coleccion_liberar(coleccion));
	}

	{
		Coleccion* coleccion = malloc(sizeof(Coleccion));
		int enteros[] = {1, 2 ,3};
		coleccion_inicializar(coleccion, enteros, sizeof(int), sizeof(enteros)/sizeof(int));
		int nuevo = 5;
		coleccion_agregar(coleccion, &nuevo);
		printf("Elemento 4: %d (Debe ser 5)\n", *(int*)*(coleccion->coleccion + 3));
		free(coleccion_liberar(coleccion));
	}

	{
		Coleccion* coleccion = malloc(sizeof(Coleccion));
		int enteros[] = {1, 2 ,3};
		coleccion_inicializar(coleccion, enteros, sizeof(int), sizeof(enteros)/sizeof(int));
		int nuevo = 5;
		int a_remover = 2;
		coleccion_agregar(coleccion, &nuevo);
		coleccion_remover(coleccion, &a_remover);
		printf("Elemento 2: %d (Debe ser 3)\n", *(int*)*(coleccion->coleccion + 1));
		free(coleccion_liberar(coleccion));
	}
	return 0;
}
