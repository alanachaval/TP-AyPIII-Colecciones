#include "Coleccion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Coleccion* coleccion_inicializar(Coleccion* this, void* valores, unsigned tam_tipo, unsigned cantidad){
	void** actual;
	this->coleccion = malloc(sizeof(void*) * cantidad);
	actual = this->coleccion;
	this->tam_tipo = tam_tipo;
	this->elementos = cantidad;
	this->espacio = cantidad;
	while(cantidad--){
		*actual = malloc(this->tam_tipo);
		memcpy(*actual, valores, this->tam_tipo);
		actual++;
		valores += this->tam_tipo;
	}
	return this;
}

Coleccion* coleccion_redimensionar(Coleccion* this){
	this->espacio = this->espacio * 2;
	this->coleccion = realloc(this->coleccion, this->espacio * sizeof(void*));
	return this;
}

Coleccion* coleccion_agregar(Coleccion* this, void* valor){
	if(this->elementos == this->espacio){
		coleccion_redimensionar(this);
	}
	*(this->coleccion + this->elementos) = malloc(this->tam_tipo);
	memcpy(*(this->coleccion + this->elementos), valor, this->tam_tipo);
	this->elementos += 1;
	return this;
}

/*
 * Remueve la primer aparicion de un elemento de la coleccion,
 * devuelve la posicion donde se encontraba o -1 si no pertenecia a la coleccion
 */
int coleccion_remover(Coleccion* this, void* valor){
	int posicion = this->elementos;
	void** actual = this->coleccion;
	while((--posicion != -1) & memcmp(*actual, valor, this->tam_tipo)){
		actual++;
	}
	if(posicion != -1){
		free(*actual);
		this->elementos--;
		coleccion_reorganizar(this, this->elementos - posicion);
	}
	return posicion;
}

/**
 * Luego de eliminar un elemento reorganiza los elementos siguientes para ocupar el espacio vacio
 */
Coleccion* coleccion_reorganizar(Coleccion* this, unsigned posicion_inicial){
	void** actual = this->coleccion + posicion_inicial;
	unsigned movimientos = this->elementos - posicion_inicial;
	while(movimientos--){
		*actual = *(actual + 1);
		actual += 1;
	}
	return this;
}

Coleccion* coleccion_liberar(Coleccion* this){
	void** actual = this->coleccion;
	while(this->elementos--){
		free(*actual);
		actual++;
	}
	free(this->coleccion);
	this->coleccion = 0x0;
	this->tam_tipo = 0x0;
	this->espacio = 0x0;
	return this;
}

