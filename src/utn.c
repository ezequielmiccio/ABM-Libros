/*
 * utn.c
 *
 *  Created on: 9 sep. 2022
 *      Author: Ezequiel Miccio
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"

int getInt(int *pResultado); // Pide un texto al usuario, lo almacena como cadena, valida y convierte el texto
							 // a numero y lo devuelve como int
int esNumerica(char* cadena);// Recibe una cadena de caracteres y devuelve 1 en el caso de que el texto
                             // este compuesto solo por números.
int lastChar(char* cadena, int len); // para quitar el \n en caso de que haya

int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{

	float numeroIngresado;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL){

		do{

			printf("%s", mensaje);

			if(getFloat(&numeroIngresado) == 1){

				if(numeroIngresado >= minimo && numeroIngresado <= maximo){
					*pResultado = numeroIngresado;
					retorno = 1;
					break;
				}
			}

			fflush(stdin);
			printf("%s", mensajeError);

		}while(retorno == -1);

	}

	return retorno;
}

int utn_getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{

	int numeroIngresado;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL){

		do{

			printf("%s", mensaje);

			if(getInt(&numeroIngresado) == 1){

				if(numeroIngresado >= minimo && numeroIngresado <= maximo){
					*pResultado = numeroIngresado;
					retorno = 1;
					break;
				}
			}

			fflush(stdin);
			printf("%s", mensajeError);


		}while(retorno == -1);

	}

	return retorno;
}

int getInt(int* pResultado){

	int retorno = -1;
	char buffer[1024];

	if(pResultado != NULL){

		if(lastChar(buffer, sizeof(buffer))== 1 && esNumerica(buffer)==1){

			*pResultado = atoi(buffer);
			retorno = 1;
		}

	}

	return retorno;
}

int getFloat(float* pResultado){

	int retorno = -1;
	char buffer[1024];

	if(pResultado != NULL){

		if(lastChar(buffer, sizeof(buffer))== 1 && esNumerica(buffer)==1){

			*pResultado = atof(buffer);
			retorno = 1;
		}

	}

	return retorno;
}

int esNumerica(char* cadena){

	int i = 0;
	int retorno = 1;

	if(cadena[0] == '-'){
		i = 1;
	}

	for( ; cadena[i] != '\0' ; i++){

		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = -1;
			break;
		}
	}

	return retorno;

}

int lastChar(char* cadena, int len){

	if(cadena != NULL && len > 0 && fgets(cadena, len, stdin) == cadena){

		fflush(stdin);

		if(cadena[strlen(cadena) - 1] == '\n'){

			cadena[strlen(cadena) - 1] = '\0';
		}

		return 1;
	}

	return -1;
}

int validarCadena(char* pCadena, char* pMensaje, char* pMensajeError){

	char cadena[51];
	int retorno = 0;
	int j;
	j = strlen(cadena);

	if(pMensaje != NULL && pMensajeError != NULL){

		do
		{
			printf("%s", pMensaje);
			fgets(cadena, sizeof(cadena), stdin);
			cadena[strlen(cadena)-1] = '\0';

			if(j > 51){
				printf("%s", pMensajeError);

			}else{
				strcpy(pCadena, cadena);
				retorno = 1;
			}

		}while(retorno == 0);
	}

	return retorno;
}

int confirmar(char* pRespuesta, char* pMensaje, char* mensajeError){

	int retorno = 0;
	char respuesta;

	if(pMensaje != NULL && mensajeError != NULL){
		printf("%s", pMensaje);
		fflush(stdin);
		scanf("%c", &respuesta);

		while(respuesta != 's' && respuesta != 'n'){
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%c", &respuesta);
		}

		*pRespuesta = respuesta;
		retorno = 1;

	}

	return retorno;
}

char salir(char* pMensaje, char* mensajeError){

	char respuesta;

	if(pMensaje != NULL && mensajeError != NULL){
		printf("%s", pMensaje);
		fflush(stdin);
		scanf("%c", &respuesta);

		while(respuesta != 's' && respuesta != 'n'){
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%c", &respuesta);
		}

	}

	return respuesta;
}

