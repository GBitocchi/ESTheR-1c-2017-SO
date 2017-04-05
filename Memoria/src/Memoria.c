/*
 ============================================================================
 Name        : Memoria.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <commons/log.h>
#include <commons/collections/list.h>
#include <commons/collections/dictionary.h>
#include <commons/config.h>
#include <string.h>



typedef struct {
	int puerto;
	int marcos;
	int marco_size;
	int entradas_cache;
	int cache_x_proc;
	int retardo_memoria;
}memoria;



memoria memoriaCrear(t_config *configuracion){
	memoria memoriaAuxiliar;
	memoriaAuxiliar.puerto = config_get_int_value(configuracion, "PUERTO");
	memoriaAuxiliar.marcos = config_get_int_value(configuracion, "MARCOS");
	memoriaAuxiliar.marco_size = config_get_int_value (configuracion, "MARCOS_SIZE");
	memoriaAuxiliar.cache_x_proc = config_get_int_value (configuracion, "CACHE_X_PROC");
	memoriaAuxiliar.retardo_memoria = config_get_int_value(configuracion, "RETARDO_MEMORIA");
	return memoriaAuxiliar;
}

memoria inicializarMemoria(char *path){
	t_config *configuracionMemoria = malloc(sizeof(t_config));
	*configuracionMemoria = *config_create(path);
	memoria memoriaSistema = memoriaCrear(configuracionMemoria);
	return memoriaSistema;
	free(configuracionMemoria);
}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
