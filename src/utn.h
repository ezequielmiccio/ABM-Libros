/*
 * utn.h
 *
 *  Ezequiel Miccio
 *
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);
int getFloat(float* pResultado);
int validarCadena(char* pCadena, char* pMensaje, char* pMensajeError);
int confirmar(char* pRespuesta, char* pMensaje, char* mensajeError);
char salir(char* pMensaje, char* mensajeError);
#endif /* UTN_H_ */
