/*
 ============================================================================
 Name        : FileSystem.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "funcionesGenericas.h"
#include "socket.h"
//--TYPEDEF--------------------------------------------------------------
typedef struct {
	int puerto;
	char *punto_montaje;
} fileSystem;

//------FUNCIONES FILESYSTEM-----------------------------------------------
fileSystem fileSystemCrear(t_config *configuracion) {
	fileSystem fileSystemAuxiliar;
	verificarParametrosCrear(configuracion,2);
	fileSystemAuxiliar.puerto = config_get_int_value(configuracion, "PUERTO");
	fileSystemAuxiliar.punto_montaje = config_get_string_value(configuracion,"PUNTO_MONTAJE");
	return fileSystemAuxiliar;
}

fileSystem inicializarFileSystem(char *path) {
	t_config *configuracionFileSystem = (t_config*)malloc(sizeof(t_config));
	*configuracionFileSystem = generarT_ConfigParaCargar(path);
	fileSystem fileSystemSistema = fileSystemCrear(configuracionFileSystem);
	return fileSystemSistema;
	free(configuracionFileSystem);
}
void mostrarConfiguracionesFileSystem(fileSystem fileSystem) {
	printf("PUERTO=%d\n", fileSystem.puerto);
	printf("PUNTO_MONTAJE=%s\n", fileSystem.punto_montaje);
}
//-----FUNCIONES ARCHIVOS------------------------------------------------
bool validarArchivo(char* path) {
	FILE* f = fopen(path, " r ");
	if (!f) {
		return true;
	} else {
		return false;
	}
}

void crearArchivo(char* path) {
	if (validarArchivo(path)) {
		FILE* f = fopen(path, "w");
	}
}

void borraArchivo(char* path) {
	remove(path); //Bitmap?
}

int main() {
	char *path="FileSystem/fileSystem.config";
	fileSystem fileSystem = inicializarFileSystem(path);
	mostrarConfiguracionesFileSystem(fileSystem);
	int socketClienteParaKernel, socketEscuchaFS;
	socketEscuchaFS = ponerseAEscucharClientes(fileSystem.puerto, 0);
	socketClienteParaKernel = aceptarConexionDeCliente(socketEscuchaFS);
	recibirMensajeDeKernel(socketClienteParaKernel);
	return EXIT_SUCCESS;
}
