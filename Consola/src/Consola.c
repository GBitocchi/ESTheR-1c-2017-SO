/*
 ============================================================================
 Name        : Consola.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "funcionesGenericas.h"

typedef struct
{
	char *numero;
}ip;

typedef struct
{
	ip ip_Kernel;
	int puerto_kernel;
}consola;


consola consola_crear(t_config* configuracion)
{
	consola consola_auxiliar;
	consola_auxiliar.ip_Kernel.numero=config_get_string_value(configuracion,"IP_KERNEL");
	consola_auxiliar.puerto_kernel=config_get_int_value(configuracion,"PUERTO_KERNEL");
	return consola_auxiliar;

}

consola iniciarConsola(char *path)
{
	t_config *configuracion = malloc(sizeof(t_config));
	*configuracion = *config_create(path);
	consola nueva_consola=consola_crear(configuracion);
	free(configuracion);
	return nueva_consola;
}
void mostrar_consola(consola aMostrar)
{
	printf("IP=%s\n",aMostrar.ip_Kernel.numero);
	printf("Puerto=%i\n",aMostrar.puerto_kernel);
	system("pause");
}
int main(int argc,char *argv[])
{
	consola nuevaConsola=iniciarConsola(*argv);
	mostrar_consola(nuevaConsola);

	return EXIT_SUCCESS;

}
