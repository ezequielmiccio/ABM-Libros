/*
 * libros.h
 *
 *  Created on: 27 sep. 2022
 *      Author: Ezequiel Miccio
 *      Parcial 1
 */

#ifndef LIBROS_H_
#define LIBROS_H_

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	int id;
	char descripcion[21];
}eTipo;

typedef struct{
	int id;
	char descripcion[51];
}ePais;

typedef struct{
	int id;
	char descripcion[51];
}eEditorial;

typedef struct{
	int id;
	char descripcion[51];
	int idPais;
}eAutor;

typedef struct{

	int id;
	char titulo[51];
	eFecha fechaPublicacion;
	float importe;
	int idAutor;
	int idEditorial;
	int idTipo;
	int isEmpty;

}eLibro;

int hardcodearTipo(eTipo tipo[], int tam, int* pNextId);
int listarTipos(eTipo tipo[], int tam);
int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char* descripcion);
int listarTipoPapel(eLibro libro[], int tam);
int listarExtranjeros(eLibro libro[], eAutor autor[], int tam);

/**
 * @fn int menu(void)
 * @brief funcion para desplegar el menu principal de nuestro programa
 * no utiliza parametros ya que es una funcion independiente
 * @return retorna un entero con la opcion elegida por el usuario
 */
int menu(void);

/**
 * @fn int menuLibro(void)
 * @brief funcion para desplegar el menu secundario de nuestro programa. En este caso para la seccion de modificaciones
 * no utiliza parametros ya que es una funcion independiente
 * @return retorna un entero con la opcion elegida por el usuario
 */
int menuLibro(void);

/**
 * @fn int inicializarLibro(eLibro[], int)
 * @brief se utiliza para inicializar los estados de los libros en LIBRE con valor definido en 1 recorriendo la estructura eLibro
 * @param libro: utiliza el tipo de dato eLibro para utilizar la estructura definida
 * @param tam: su tamanio para que la funcion reciba los elementos
 * @return retorna un entero para verificar que su funcion se realizo correctamente
 */
int inicializarLibro(eLibro libro[], int tam);

/**
 * @fn int altaLibro(eLibro[], int, int*, eEditorial[], int, eAutor[], int, ePais[], int)
 * @brief su funcion es realizar el alta de los libros con la informacion que cargue el usuario, una vez confirmada el alta crea el libro con el id que se recibe de la funcion buscarLugar
 *
 * @param libro: utiliza el tipo de dato eLibro para utilizar la estructura definida
 * @param tam: su tamanio para que la funcion reciba los elementos de la estructura
 * @param pNextId: para enviar el id del libro de alta al main a traves de un puntero a int y que desde ahi se pueda ir incrementando
 * @param editorial: para acceder a la estructura definida
 * @param tame: su tamanio para que la funcion reciba los elementos de la estructura
 * @param autor: para acceder a la estructura definida
 * @param tama: su tamanio para que la funcion reciba los elementos de la estructura
 * @param pais: para acceder a la estructura definida
 * @param tamp: su tamanio para que la funcion reciba los elementos de la estructura
 * @return retorna un entero informando si su funcion fue realizada correctamente
 */
int altaLibro(eLibro libro[], int tam, int* pNextId, eEditorial editorial[], int tame, eAutor autor[], int tama, ePais pais[], int tamp, eTipo tipo[], int tamt);

/**
 * @fn int bajaLibro(eLibro[], int, eEditorial[], eAutor[])
 * @brief  su funcion es dar de baja un libro ya creado, se le muestra el libro seleccionado al usuario a traves del id ingresado utilizando la funcion buscarLibro y se le pide confirmar previo a ejecutar la baja
 *
 * @param libro utiliza el tipo de dato eLibro para utilizar la estructura definida
 * @param tam su tamanio para que la funcion reciba los elementos de la estructura
 * @param editorial para acceder a la estructura definida
 * @param autor para acceder a la estructura definida
 * @return retorna un entero informando si su funcion fue realizada correctamente
 */
int bajaLibro(eLibro libro[], int tam, eEditorial editorial[], eAutor autor[], eTipo tipo[]);

/**
 * @fn int buscarLugar(eLibro[], int, int*)
 * @brief su funcion es recorrer el estado de la estructura eLibro para encontrar un espacio libre
 *
 * @param libro para acceder a la estructura libro
 * @param tam para recibir sus elementos
 * @param pIndice para enviar el id del espacio encontrado y trabajar sobre ese mismo indice en otra funcion
 * @return retorna un entero informando si su funcion fue realizada correctamente
 */
int buscarLugar(eLibro libro[], int tam, int* pIndice);

/**
 * @fn int buscarLibro(eLibro[], int, int, int*)
 * @brief su funcion es encontrar el libro seleccionado por el id que ingresa el usuario. Se fija que el estado sea ocupado y que el id coincida con el id de la estructura
 *
 * @param libro para acceder a la estructura libro
 * @param tam para recibir sus elementos
 * @param id para ratificar que el libro fue creado con un numero unico de identificacion
 * @param pIndex para enviar el id encontrado a otra funcion
 * @return retorna un entero informando si su funcion fue realizada correctamente
 */
int buscarLibro(eLibro libro[], int tam, int id, int* pIndex);

/**
 * @fn void mostrarLibro(eLibro, eAutor[], eEditorial[], int)
 * @brief su funcion es mostrar las caracteristicas del libro creado modificando el campo entero de la FK a una cadena de caracteres que seria la descipcion PK que llega a traves de la funcion mostrarLibroFila
 *
 * @param libro para acceder a la estructura libro
 * @param autor para acceder a la estructura autor
 * @param editorial para acceder a la estructura editorial
 * @param tam para acceder a los elementos
 */
void mostrarLibro(eLibro libro, eAutor autor[], eEditorial editorial[], eTipo tipo[], int tam);

/**
 * @fn void mostrarLibroFila(eLibro, eAutor[], eEditorial[], int)
 * @brief su funcion es mostrar las caracteristicas del libro creado modificando el campo entero de la FK a una cadena de caracteres y derivarla a la funcion de listarLibros
 *
 * @param libro para acceder a la estructura libro
 * @param autor para acceder a la estructura autor
 * @param editorial para acceder a la estructura editorial
 * @param tam para acceder a los elementos
 */
void mostrarLibroFila(eLibro libro, eAutor autor[], eEditorial editorial[], eTipo tipo[], int tam);

/**
 * @fn int listarLibros(eLibro[], int, eAutor[], eEditorial[])
 * @brief su funcion es mostrar los libros en fila con la funcion anterior de los libres que tengan un estado OCUPADO
 *
 * @param libro para acceder a la estructura libro
 * @param tam para recibir sus elementos
 * @param autor para acceder a la estructura autor
 * @param editorial para acceder a la estructura editorial
 * @return retorna un entero para informar si se realizo la funcion correctamente o si no hay ningun libro cargado
 */
int listarLibros(eLibro libro[], int tam, eAutor autor[], eEditorial editorial[], eTipo tipo[]);

/**
 * @fn int modificarLibro(eLibro[], int, eAutor[], eEditorial[], ePais[], int, int)
 * @brief su funcion es realizar las modificaciones de datos ya cargados a traves de un id del libro correspondiente, el usuario va a modificar cuantos datos quiera hasta que el mismo elija volver al menu principal
 *
 * @param libro para trabajar con la estructura correspondiente
 * @param tam para trabajar con los elementos de la estructura
 * @param autor para acceder a la estructura autor
 * @param editorial para acceder a la estructura editorial
 * @param pais para acceder a la estructura pais
 * @param tama para trabajar con los elementos de la estructura
 * @param tame para trabajar con los elementos de la estructura
 * @return retorna un entero para informar si se realizo la funcion correctamente
 */
int modificarLibro(eLibro libro[], int tam, eAutor autor[], eEditorial editorial[], ePais pais[], int tama, int tame, eTipo tipo[], int tamt);

/**
 * @fn int hardcodearPaises(ePais[], int, int*)
 * @brief funcion para hardcodear datos de la estructura definida para paises
 *
 * @param pais para trabajar con la estructura correspondiente
 * @param tam para trabajar con los elementos de la estructura
 * @param pNextId para igualar el primer id a este puntero e inicializarlo incrementalmente desde el main
 * @return retorna un entero para informar si se realizo la funcion correctamente
 */
int hardcodearPaises(ePais pais[], int tam, int* pNextId);

/**
 * @fn int listarPaises(ePais[], int)
 * @brief su funcion es recorrer la estructura e ir listando a traves de id ascendiente mostrando la descripcion correspondiente
 *
 * @param pais para trabajar con la estructura correspondiente
 * @param tam para trabajar con los elementos de la estructura
 * @return retorna un entero para informar si se realizo la funcion correctamente
 */
int listarPaises(ePais pais[], int tam);

/**
 * @fn int cargarDescripcionPaises(ePais[], int, int, char*)
 * @brief su funcion es recorrer la estructura para copiar la descripcion de la misma a un puntero a char para enviarla a las funciones de mostrar estructuras para asi poder modificar la descripcion por el FK
 *
 * @param paises para trabajar con la estructura correspondiente
 * @param tam para trabajar con los elementos de la estructura
 * @param id para ratificar que el indice coincida
 * @param descripcion para enviar por puntero a char la descripcion copiada de la estructura
 * @return retorna un entero para informar si se realizo la funcion correctamente
 */
int cargarDescripcionPaises(ePais paises[], int tam, int id, char* descripcion);

/**
 * @fn int hardcodearEditoriales(eEditorial[], int, int*)
 * @brief funcion para hardcodear datos de la estructura definida para editoriales
 *
 * @param editorial para trabajar con la estructura correspondiente
 * @param tam para trabajar con los elementos de la estructura
 * @param pNextId para igualar el primer id a este puntero e inicializarlo incrementalmente desde el main
 * @return retorna un entero para informar si se realizo la funcion correctamente
 */
int hardcodearEditoriales(eEditorial editorial[], int tam, int* pNextId);

/**
 * @fn int listarEditoriales(eEditorial[], int)
 * @brief su funcion es recorrer la estructura e ir listando a traves de id ascendiente mostrando la descripcion correspondiente
 *
 * @param editorial para trabajar con la estructura correspondiente
 * @param tam para trabajar con los elementos de la estructura
 * @return retorna un entero para informar si se realizo la funcion correctamente
 */
int listarEditoriales(eEditorial editorial[], int tam);

/**
 * @fn int cargarDescripcionEditorial(eEditorial[], int, int, char[])
 * @brief su funcion es recorrer la estructura para copiar la descripcion de la misma a un puntero a char para enviarla a las funciones de mostrar estructuras para asi poder modificar la descripcion por el FK
 *
 * @param editorial para trabajar con la estructura correspondiente
 * @param tam para trabajar con los elementos de la estructura
 * @param id para ratificar que el indice coincida
 * @param descripcion para enviar por puntero a char la descripcion copiada de la estructura
 * @return retorna un entero para informar si se realizo la funcion correctamente
 */
int cargarDescripcionEditorial(eEditorial editorial[], int tam, int id, char descripcion[]);

/**
 * @fn int buscarEditorial(eEditorial[], int, int, int*)
 * @brief su funcion es encontrar el editorial correspondiente filtrando por el id
 *
 * @param editorial para trabajar con la estructura correspondiente
 * @param tam para trabajar con los elementos de la estructura
 * @param id para ratificar que el libro fue creado con un numero unico de identificacion
 * @param pIndex para enviar el id encontrado a otra funcion
 * @return retorna un entero informando si su funcion fue realizada correctamente
 */
int buscarEditorial(eEditorial editorial[], int tam, int id, int* pIndex);

/**
 * @fn int validarEditorial(eEditorial[], int, int)
 * @brief su funcion es ratificar que el indice que llega desde la funcion buscarEditorial exista
 *
 * @param editorial para trabajar con la estructura correspondiente
 * @param tam para trabajar con los elementos de la estructura
 * @param id para ratificar que el libro fue creado con un numero unico de identificacion
 * @return retorna un entero informando si su funcion fue realizada correctamente
 */
int validarEditorial(eEditorial editorial[], int tam, int id);

/**
 * @fn int hardcodearAutores(eAutor[], int, int*)
 * @brief funcion para hardcodear datos de la estructura definida para autores
 *
 * @param autor para trabajar con la estructura correspondiente
 * @param tam para trabajar con los elementos de la estructura
 * @param pNextId para igualar el primer id a este puntero e inicializarlo incrementalmente desde el main
 * @return retorna un entero para informar si se realizo la funcion correctamente
 */
int hardcodearAutores(eAutor autor[], int tam, int* pNextId);

/**
 * @fn int listarAutores(eAutor[], ePais[], int)
 * @brief su funcion es recorrer la estructura e ir listando a traves de id ascendiente mostrando la descripcion correspondiente
 *
 * @param autor para trabajar con la estructura correspondiente
 * @param pais para acceder a la descripcion a traves de la FK
 * @param tam para trabajar con los elementos de la estructura
 * @return retorna un entero para informar si se realizo la funcion correctamente
 */
int listarAutores(eAutor autor[], ePais pais[], int tam);

/**
 * @fn int cargarDescripcionAutor(eAutor[], int, int, char[])
 * @brief su funcion es recorrer la estructura para copiar la descripcion de la misma a un puntero a char y asi enviarla a las funciones para poder modificar la descripcion por el FK
 *
 * @param autor para trabajar con la estructura correspondiente
 * @param tam para trabajar con los elementos de la estructura
 * @param id para ratificar que el indice coincida
 * @param descripcion para enviar por puntero a char la descripcion copiada de la estructura
 * @return retorna un entero para informar si se realizo la funcion correctamente
 */
int cargarDescripcionAutor(eAutor autor[], int tam, int id, char descripcion[]);

/**
 * @fn int validarAutor(eAutor[], int, int)
 * @brief su funcion es ratificar que el indice que llega desde la funcion buscarAutor exista
 *
 * @param autor para trabajar con la estructura correspondiente
 * @param tam para trabajar con los elementos de la estructura
 * @param id para ratificar que el libro fue creado con un numero unico de identificacion
 * @return retorna un entero informando si su funcion fue realizada correctamente
 */
int validarAutor(eAutor autor[], int tam, int id);

/**
 * @fn int buscarAutor(eAutor[], int, int, int*)
 * @brief su funcion es encontrar el editorial correspondiente filtrando por el id
 *
 * @param autor para trabajar con la estructura correspondiente
 * @param tam para trabajar con los elementos de la estructura
 * @param id id para ratificar que el libro fue creado con un numero unico de identificacion
 * @param pIndex para enviar el id encontrado a otra funcion
 * @return retorna un entero informando si su funcion fue realizada correctamente
 */
int buscarAutor(eAutor autor[], int tam, int id, int* pIndex);

float importeTotal(eLibro libro[], int tam);
int contadorLibros(eLibro libro[], int tam);
int contadorLibrosPromedio(eLibro libro[], int tam, float* pPromedio);
int contadorLibrosFecha(eLibro libro[], int tam);
int menuLista(void);
int listarInformes(eLibro libro[], int tam, eEditorial editorial[], int tame, eAutor autor[], int tama, ePais pais[], int tamp, eTipo tipo[], int tamt);


#endif /* LIBROS_H_ */
