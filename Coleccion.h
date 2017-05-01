#ifndef __Coleccion_H__
#define __Coleccion_H__

/*
 *	Implementacion como Arreglo
 */

typedef struct _Coleccion {
	void** coleccion;
	unsigned espacio;
	unsigned tam_tipo;
	unsigned elementos;
} Coleccion;

/*
 *	Funcionalidades Requeridas
 *
 *	Agregar elemento a la collección (collection_add).
 *	Quitar elemento de la collección  (collection_remove).
 *	Inicializar la colección con un conjunto de valores (collection_init).
 *
 *	Iterar la colección (collection_iterate).
 *	Encontrar un valor dentro de la colección (void* collection_find( Collection* c, void* value,...)).
 *	Seleccionar un conjunto de elementos de la colección (collection_select( Collection* c, Collection* dst, ...)).
 *	Colectar elementos de una colección (void collection_collect( Collection* c, Collection* dst, ...)).
 *	Filtar elementos de una colección (void collection_filter( Collection* c, ...)).
 *	Reducir a derecha una colección (definir).
 *	Reducir a izquierda una colección (definir).
 *	Unir dos colecciones.
 *	Intersección de colecciones.
 */

Coleccion* coleccion_inicializar(Coleccion* this, void* valores, unsigned tam_tipo, unsigned cantidad);

Coleccion* coleccion_agregar(Coleccion* this, void* valor);

int coleccion_remover(Coleccion* this, void* valor);

/*
 * Funcionalidades Agregadas
 *
 * Liberar Memoria (coleccion_liberar)
 * Redimensionar (coleccion_redimensionar)
 * Reorganizar (coleccion_reorganizar)
 */

Coleccion* coleccion_liberar(Coleccion* this);

Coleccion* coleccion_redimensionar(Coleccion* this);

Coleccion* coleccion_reorganizar(Coleccion* this, unsigned posicion_inicial);

#endif //__Coleccion_H__

