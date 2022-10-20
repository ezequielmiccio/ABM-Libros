/*
 * libros.h
 *
 *  Created on: 27 sep. 2022
 *      Author: Ezequiel Miccio
 *      Parcial 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libro.h"
#include "utn.h"

#define TAMP 5
#define TAME 5
#define TAMA 10
#define TAMT 2
#define LIBRE 1
#define OCUPADO 0
#define BAJA -1

int listarExtranjeros(eLibro libro[], eAutor autor[], int tam){

	int retorno = 0;
	int i;

	if(libro != NULL && autor != NULL && tam > 0){

		printf("    ***  Listado de Autores Extranjeros  ***    \n\n");
		printf("\tAutor \t  Nacionalidad\n-----------------------------------------\n\n");

		for(i = 0; i < tam; i++){

			if(!libro[i].isEmpty && autor[i].idPais != 1){

				printf("\t %s \n", autor[i].descripcion);
				break;
			}

		}

		retorno = 1;
	}


	return retorno;

}

int listarTipoPapel(eLibro libro[], int tam){

	int retorno = 1;
	int i;
	int flag = 1;

	if(libro != NULL && tam > 0){

		printf("    ***  Listado de Tipos PAPEL  ***    \n\n");
		printf("\tId \t  Papel\n-----------------------------------------\n\n");

		for(i=0; i < tam; i++){

			if(!libro[i].isEmpty && libro[i].idTipo == 1){

				printf("\t%d \t %s \n", libro[i].id, libro[i].titulo);
				flag = 0;

			}

		}

		if(flag){
			retorno = -1;
		}
	}

	return retorno;

}

int hardcodearTipo(eTipo tipo[], int tam, int* pNextId){

	int retorno = 0;

	eTipo tipos[TAMT] =
	{
		{0, "Papel"},
		{0, "Ebook"}
	};

	if(tipo != NULL && pNextId != NULL && tam > 0 && tam <= 2){

		for(int i = 0; i < tam; i++){
			tipo[i] = tipos[i];
			tipo[i].id = *pNextId;
			(*pNextId)++;
		}
		retorno = 1;
	}

	return retorno;
}

int listarTipos(eTipo tipo[], int tam){

	int retorno = 0;

	if(tipo != NULL && tam > 0){
		printf("    ***  Listado de Tipos de Libro  ***    \n\n");
		printf("\tId \t  Tipo\n-----------------------------------------\n\n");

		for(int i=0; i < tam; i++){
			printf("\t%d \t %s \n", tipo[i].id, tipo[i].descripcion);
		}

		retorno = 1;
	}

	return retorno;
}

int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char* descripcion){

	int retorno = 0;

	if(tipos != NULL && tam > 0 && descripcion != NULL){

		for(int i = 0; i < tam; i++){

			if(tipos[i].id == id){
				strcpy(descripcion, tipos[i].descripcion);
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

int listarInformes(eLibro libro[], int tam, eEditorial editorial[], int tame, eAutor autor[], int tama, ePais pais[], int tamp, eTipo tipo[], int tamt){

	int retorno = 0;
	int respuesta;
	char volver = 'n';

	if(libro != NULL && tam > 0 && editorial != NULL && tame > 0 && autor != NULL && tama > 0 && pais != NULL && tamp > 0 && tipo != NULL && tamt > 0){

		do{

			switch(menuLista()){
				case 1:
					listarEditoriales(editorial, tame);
					break;
				case 2:
					listarPaises(pais, tamp);
					break;
				case 3:
					listarAutores(autor, pais, tama);
					break;
				case 4:
					respuesta = listarLibros(libro, tam, autor, editorial, tipo);
					if(respuesta == -1){
						printf("No hay libros cargados en el sistema.\n");
					}
					break;
				case 5:
					printf("case 5");
					break;
				case 6:
					listarTipos(tipo, tamt);
					break;
				case 7:
					respuesta = listarTipoPapel(libro, tam);
					if(respuesta == -1){
						printf("No hay libros de PAPEL cargados en el sistema.\n");
					}
					break;
				case 8:
					listarExtranjeros(libro, autor, tam);
					break;
				case 9:
					volver = 's';
					break;
				default:
					printf("opcion invalida");
			}

		}while(volver != 's');

		retorno = 1;

	}

	return retorno;
}

int contadorLibrosFecha(eLibro libro[], int tam){

	int i;
	int contador = 0;

	if(libro != NULL && tam > 0){

		for(i = 0; i < tam; i++){

			if(!libro[i].isEmpty && libro[i].fechaPublicacion.anio > 1999){

				contador++;

			}
		}
	}

	return contador;

}

int contadorLibrosPromedio(eLibro libro[], int tam, float* pPromedio){

	int i;
	int contador = 0;

	if(libro != NULL && tam > 0 && pPromedio != NULL){

		for(i = 0; i < tam; i++){

			if(!libro[i].isEmpty && libro[i].importe < *pPromedio){

				contador++;
			}
		}
	}

	return contador;

}


int contadorLibros(eLibro libro[], int tam){

	int i;
	int contador = 0;

	if(libro != NULL && tam > 0){

		for(i = 0; i < tam; i++){

			if(!libro[i].isEmpty){

				contador++;

			}
		}
	}

	return contador;
}

float importeTotal(eLibro libro[], int tam){

	int i;
	float total = 0;

	if(libro != NULL && tam > 0){


		for(i = 0; i < tam; i++){

			if(!libro[i].isEmpty && libro[i].importe > 0){

				total += libro[i].importe;
			}
		}
	}

	return total;

}

int menu(){

	int opcion;

	fflush(stdin);
	printf("\n\n    *****    ABM Libros    *****    \n"
			"-------------------------------------\n\n"
			"Opciones:\n\n"
			"1. Alta Libro\n"
			"2. Modificar Libro\n"
			"3. Baja Libro\n"
			"4. Informar\n"
			"5. Listar\n"
			"6. Salir\n\n");

	utn_getNumber(&opcion, "Ingrese una opcion: ", "Error: Reingrese una opcion valida: \n", 1, 6);

	return opcion;
}

int menuLibro(void){

	int opcion;

	fflush(stdin);
	printf("\n\n   ***** Campo de Modificaciones *****   \n"
			"----------------------------------------\n\n"
			"1. Titulo\n"
			"2. Importe\n"
			"3. Autor\n"
			"4. Editorial\n"
			"5. Fecha de publicacion\n"
			"6. Tipo de Libro\n"
			"7. Volver\n");

	utn_getNumber(&opcion, "Ingrese una opcion: ", "Error, reingrese una opcion valida: \n", 1, 9);

	return opcion;

}

int menuLista(void){

	int opcion;

	fflush(stdin);
	printf("\n\n   ***** Campo de Informes *****   \n"
			"----------------------------------------\n\n"
			"1. Listar Editoriales\n"
			"2. Listar Paises\n"
			"3. Listar Autores\n"
			"4. Listar Libros\n"
			"5. Listado unico:\n"
			"\t Autor (ascendentemente)\n"
			"\t Titulo (ascendientemente)\n"
			"6. Listar Tipos\n"
			"7. Listar Libros de Papel\n"
			"8. Listar Autores Extranjeros\n"
			"9. Volver\n");

	utn_getNumber(&opcion, "Ingrese una opcion: ", "Error, reingrese una opcion valida: \n", 1, 8);

	return opcion;

}

int inicializarLibro(eLibro libro[], int tam){

	int retorno = 0;

	if(libro != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			libro[i].isEmpty = LIBRE;
		}

		retorno = 1;

	}

	return retorno;
}

int buscarLugar(eLibro libro[], int tam, int* pIndice){

	int retorno = 0;
	int i;

	if(libro != NULL && tam > 0 && pIndice != NULL){

		*pIndice = -1;

		for(i = 0; i < tam; i++){

			if(libro[i].isEmpty){
				*pIndice = i;
				break;
			}
		}

		retorno = 1;
	}

	return retorno;
}

int altaLibro(eLibro libro[], int tam, int* pNextId, eEditorial editorial[], int tame, eAutor autor[], int tama, ePais pais[], int tamp, eTipo tipo[], int tamt){

	int retorno = 0;
	int indice;
	char respuesta = 'n';
	int idEditorial;
	int idAutor;
	int idTipo;
	eLibro nuevoLibro;

	if(libro != NULL && tam > 0 && pNextId != NULL && editorial != NULL && tame > 0 && autor != NULL && tama > 0 && tipo != NULL && tamt > 0){

		printf("     ***   Alta Libro   ***     \n\n");

		buscarLugar(libro, tam, &indice);

		if(indice == -1){
			printf("No hay lugar en el sistema\n");

		}else{

			nuevoLibro.id = *pNextId;

			validarCadena(nuevoLibro.titulo, "Ingrese titulo del libro: ", "Error, el titulo sobrepasa limite de caracteres\n");

			while(respuesta != 's'){

				fflush(stdin);
				utn_getNumber(&nuevoLibro.fechaPublicacion.dia, "Ingrese dia de la fecha de publicacion del libro: XX", "Error, ingrese un dia valido\n", 1, 31);
				utn_getNumber(&nuevoLibro.fechaPublicacion.mes, "Ingrese mes de la fecha de publicacion del libro: XX", "Error, ingrese un dia valido\n", 1, 12);
				utn_getNumber(&nuevoLibro.fechaPublicacion.anio, "Ingrese anio de la fecha de publicacion del libro: XXXX", "Error, ingrese un dia valido\n", 1900, 2022);

				printf("Fecha de publicacion: %d/%d/%d\n", nuevoLibro.fechaPublicacion.dia, nuevoLibro.fechaPublicacion.mes, nuevoLibro.fechaPublicacion.anio);
				confirmar(&respuesta, "Por favor, confirme si la fecha ingresada es correcta s/n: ", "Error, reingrese una opcion valida\n");
			}

			fflush(stdin);
			utn_getFloat(&nuevoLibro.importe, "Ingrese importe del libro: ", "Error, ingrese un importe valido\n", 1, 9999999);

			listarAutores(autor, pais, tama);
			utn_getNumber(&idAutor, "Ingrese que ID de autor es el correcto: ", "Ingrese una opcion valida\n", 1, 10);

			nuevoLibro.idAutor = idAutor;

			listarEditoriales(editorial, tame);
			utn_getNumber(&idEditorial, "Ingrese que ID de autor es el correcto: ", "Ingrese una opcion valida\n", 1, 5);

			nuevoLibro.idEditorial = idEditorial;

			listarTipos(tipo, tamt);
			utn_getNumber(&idTipo, "Ingrese que TIPO DE LIBRO es el correcto: ", "Ingrese una opcion valida\n", 1, 2);

			nuevoLibro.idTipo = idTipo;

			mostrarLibro(nuevoLibro, autor, editorial, tipo, tam);

				nuevoLibro.isEmpty = 0;
				libro[indice] = nuevoLibro;
				//*pImporte += nuevoLibro.importe;
				(*pNextId)++;
				retorno = 1;
		}

	}

	return retorno;
}

int bajaLibro(eLibro libro[], int tam, eEditorial editorial[], eAutor autor[], eTipo tipo[]){

	int retorno = 0;
	int indice;
	int id;
	int respuesta;
	char ok;

	if(libro != NULL && tam > 0 && editorial != NULL && autor != NULL){

		respuesta = listarLibros(libro, tam, autor, editorial, tipo);

			if(respuesta == -1){
				printf("No hay libros cargados en el sistema.\n");
			}else{

			printf("\nIngrese ID de libro a eliminar: ");
			scanf("%d", &id);

			if(buscarLibro(libro, tam, id, &indice)){

				if(indice == -1){
					printf("\nNo existen libros con el ID: %d en el sistema\n", id);
				}
				else{
					printf("          *** Libro seleccionado ***          \n");
					mostrarLibroFila(libro[indice], autor, editorial, tipo, tam);
					fflush(stdin);
					if(confirmar(&ok, "Confirma la baja? s/n \n", "Error: Reingrese una opcion valida: s/n \n")){

						if(ok == 's'){

						libro[indice].isEmpty = BAJA;
						printf("¡Baja realizada correctamente!\n");

						}else{
							printf("Baja cancelada por el usuario\n");
						}
					}
				}

				retorno = 1;
			}
		}
	}

	return retorno;

}

void mostrarLibro(eLibro libro, eAutor autor[], eEditorial editorial[], eTipo tipos[], int tam){

	char descripcionA[51];
	char descripcionE[51];
	char descripcionT[21];

	cargarDescripcionAutor(autor, tam, libro.idAutor, descripcionA);
	cargarDescripcionEditorial(editorial, tam, libro.idEditorial, descripcionE);
	cargarDescripcionTipo(tipos, tam, libro.idTipo, descripcionT);

	printf("\n\t\t\t\t¡Nuevo libro creado exitosamente!\n\t\t\t\t----------------------------------\n\n");
	mostrarLibroFila(libro, autor, editorial, tipos, tam);

}

void mostrarLibroFila(eLibro libro, eAutor autor[], eEditorial editorial[], eTipo tipos[], int tam){

	char descripcionA[51];
	char descripcionE[51];
	char descripcionT[21];

	cargarDescripcionAutor(autor, tam, libro.idAutor, descripcionA);
	cargarDescripcionEditorial(editorial, tam, libro.idEditorial, descripcionE);
	cargarDescripcionTipo(tipos, tam, libro.idTipo, descripcionT);

	printf("\t%d     %10s     $%.2f     %10s     %10s     %10s      %d/%d/%d\n",
			libro.id,
			libro.titulo,
			libro.importe,
			descripcionA,
			descripcionE,
			descripcionT,
			libro.fechaPublicacion.dia,
			libro.fechaPublicacion.mes,
			libro.fechaPublicacion.anio);

}

int listarLibros(eLibro libro[], int tam, eAutor autor[], eEditorial editorial[], eTipo tipo[]){

	int retorno = 0;
	int flag = 1;

	if(libro != NULL && tam > 0 && autor != NULL && editorial != NULL){

		printf("          *** Lista de Libros ***          \n");
		printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\tID \tTitulo \t\tImporte \tAutor      \tEditorial    \t Tipo de Libro   \tFecha de Publicacion\n");
		printf("---------------------------------------------------------------------------------------------------------------------------------------------\n\n");

		for(int i = 0; i < tam; i++){

			if(!libro[i].isEmpty){

				mostrarLibroFila(libro[i], autor, editorial, tipo, tam);
				flag = 0;
			}
		}

		retorno = 1;

		if(flag){
			retorno = -1;
		}

	}

	return retorno;

}

int buscarLibro(eLibro libro[], int tam, int id, int* pIndex){

	int retorno = 0;
	int i;

	if(libro != NULL && tam > 0 && pIndex != NULL){

		*pIndex = -1;

		for(i = 0; i < tam; i++){

			if(!libro[i].isEmpty && libro[i].id == id){
				*pIndex = i;
				break;
			}
		}

		retorno = 1;
	}

	return retorno;


}

int modificarLibro(eLibro libro[], int tam, eAutor autor[], eEditorial editorial[], ePais pais[], int tama, int tame, eTipo tipo[], int tamt){

	int retorno = 0;
	int id;
	int indice;
	int respuesta;
	int idAutor;
	int idEditorial;
	int idTipo;
	float importe;
	char volver;
	char auxCad[51];

	if(libro != NULL && tam > 0 && autor != NULL  && editorial != NULL && pais != NULL && tama > 0 && tame > 0 && tipo != NULL && tamt > 0 && tipo != NULL && tamt > 0){

		respuesta = listarLibros(libro, tam, autor, editorial, tipo);

		if(respuesta == -1){
			printf("\n\n*** No hay libros cargados en el sistema ***\n\n");
		}else{
			utn_getNumber(&id, "\nIngrese ID: ", "Error, ingrese un ID valido\n", 1, tam);

			if(buscarLibro(libro, tam, id, &indice)){

				if(indice == -1){
					printf("\nNo existe una bicicleta con ID: %d en el sistema\n", id);

				}else{
					mostrarLibro(libro[indice], autor, editorial, tipo, tam);
					printf("%d", indice);

					do{
						switch(menuLibro()){

						case 1:
							validarCadena(auxCad, "Ingrese nuevo titulo del libro: ", "Error, el titulo sobrepasa limite de caracteres\n");
							strcpy(libro[indice].titulo, auxCad);
							printf("¡Titulo modificado correctamente!\n");
							break;

						case 2:
							printf("El importe del libro '%s' es $%.2f\n", libro[indice].titulo, libro[indice].importe);
							utn_getFloat(&importe, "Ingrese nuevo importe: \n", "Error, ingrese un importe valido\n", 1, 9999999);
							libro[indice].importe = importe;

							printf("¡Importe modificado correctamente!\n");
							break;


						case 3:
							listarAutores(autor, pais, tama);
							printf("Ingrese ID de Autor a modificar: ");
							scanf("%d", &idAutor);

							while(!validarAutor(autor, tama, idAutor)){
								printf("Ingrese un ID de Autor valido: ");
								scanf("%d", &idAutor);
							}

							libro[indice].idAutor = idAutor;
							printf("¡Autor modificado correctamente!\n");
							break;

						case 4:
							listarEditoriales(editorial, tame);
							printf("Ingrese ID de Editorial a modificar: ");
							scanf("%d", &idEditorial);

							while(!validarEditorial(editorial, tame, idEditorial)){
								printf("Ingrese un ID de Editorial valido: ");
								scanf("%d", &idEditorial);
							}

							libro[indice].idEditorial = idEditorial;
							printf("¡Editorial modificado correctamente!\n");
							break;

						case 5:
							printf("La fecha de publicacion es: %d/%d/%d\n",
									libro[indice].fechaPublicacion.dia,
									libro[indice].fechaPublicacion.mes,
									libro[indice].fechaPublicacion.anio);

							while(respuesta != 's'){

								utn_getNumber(&libro[indice].fechaPublicacion.dia, "Ingrese dia de la fecha de publicacion del libro: XX", "Error, ingrese un dia valido", 1, 31);
								utn_getNumber(&libro[indice].fechaPublicacion.mes, "Ingrese mes de la fecha de publicacion del libro: XX", "Error, ingrese un dia valido", 1, 12);
								utn_getNumber(&libro[indice].fechaPublicacion.anio, "Ingrese anio de la fecha de publicacion del libro: XXXX", "Error, ingrese un dia valido", 1900, 2022);

								printf("Fecha de publicacion: %d/%d/%d\n", libro[indice].fechaPublicacion.dia, libro[indice].fechaPublicacion.mes, libro[indice].fechaPublicacion.anio);
								fflush(stdin);
								respuesta = salir("Por favor, confirme si la fecha ingresada es correcta s/n: ", "Error, reingrese una opcion valida\n");

								if(respuesta == 's'){
									printf("¡Fecha de Publicacion modificado correctamente!\n");
								}

							}
							break;

						case 6:
							listarTipos(tipo, tamt);
							utn_getNumber(&idTipo, "Ingrese ID de tipo que desea: ", "Error, reingrese un ID valido\n", 1, 2);
							libro[indice].idTipo = idTipo;
							printf("Tipo de libro modificado correctamente!\n");
							break;

						case 7:
							volver = 's';
							break;

						default:
							printf("Opcion invalida\n");
						}

						fflush(stdin);

					}while(volver != 's');
				}
			}
		}

	}

	retorno = 1;

	return retorno;

}

int hardcodearPaises(ePais pais[], int tam, int* pNextId){

	int retorno = 0;

	ePais paises[TAMP] =
	{
		{0, "Argentina"},
		{0, "Uruguay"},
		{0, "Brasil"},
		{0, "Chile"},
		{0, "Paraguay"}
	};

	if(pais != NULL && pNextId != NULL && tam > 0 && tam <= 5){

		for(int i = 0; i < tam; i++){
			pais[i] = paises[i];
			pais[i].id = *pNextId;
			(*pNextId)++;
		}
		retorno = 1;
	}

	return retorno;
}

int hardcodearEditoriales(eEditorial editorial[], int tam, int* pNextId){

	int retorno = 0;

	eEditorial editoriales[TAME] =
	{
		{0, "Ediciones de la Flor"},
		{0, "Ediciones de Mente"},
		{0, "Ediciones Minotauro"},
		{0, "Editorial Abril"},
		{0, "Ediciones INTA"}
	};

	if(editorial != NULL && pNextId != NULL && tam > 0 && tam <= 5){

		for(int i = 0; i < tam; i++){
			editorial[i] = editoriales[i];
			editorial[i].id = *pNextId;
			(*pNextId)++;
		}
		retorno = 1;
	}

	return retorno;
}

int hardcodearAutores(eAutor autor[], int tam, int* pNextId){

	int retorno = 0;

	eAutor autores[TAMA] =
	{
		{0, "Miguel De Cervantes", 1},
		{0, "Marqués De Sade", 1},
		{0, "Goethe\t\t", 4},
		{0, "Jane Austen\t", 3},
		{0, "Charles Bukowski", 2},
		{0, "Franz Kafka\t", 3},
		{0, "Truman Capote\t", 1},
		{0, "Orson Welles\t", 5},
		{0, "Pier Paolo Pasolini", 3},
		{0, "Patricia Rozema", 2}
	};

	if(autor != NULL && pNextId != NULL && tam > 0 && tam <= 10){

		for(int i = 0; i < tam; i++){
			autor[i] = autores[i];
			autor[i].id = *pNextId;
			(*pNextId)++;
		}

		retorno = 1;
	}

	return retorno;
}

int listarPaises(ePais pais[], int tam){

	int retorno = 0;

	if(pais != NULL && tam > 0){
		printf("    ***  Listado de Paises  ***    \n\n");
		printf("\tId \t  Pais\n-----------------------------------------\n\n");

		for(int i=0; i < tam; i++){
			printf("\t%d \t %s \n", pais[i].id, pais[i].descripcion);
		}

		retorno = 1;
	}

	return retorno;
}

int listarEditoriales(eEditorial editorial[], int tam){

	int retorno = 0;

	if(editorial != NULL && tam > 0){
		printf("\n\n    ***  Listado de Editoriales  ***    \n\n");
		printf("\tId \t  Editorial\n-----------------------------------------\n\n");

		for(int i=0; i < tam; i++){
			printf("\t%d \t %s \n", editorial[i].id, editorial[i].descripcion);
		}

		retorno = 1;
	}

	return retorno;
}

int listarAutores(eAutor autor[], ePais pais[], int tam){

	int retorno = 0;

	if(autor != NULL && pais != NULL && tam > 0){

		printf("\n\n    ***  Listado de Autores  ***    \n\n");
		printf("\tId \t\t Autor \t\t      Nacionalidad \n      -----------------------------------------\n\n");

		for(int i=0; i < tam; i++){ // autor
			for(int j = 0; j < 5; j++){ // pais
				if(autor[i].idPais == pais[j].id){
					printf("\t %d \t %s\t %s \n", autor[i].id, autor[i].descripcion, pais[j].descripcion);
					break;
				}
			}
		}

		retorno = 1;
	}

	return retorno;
}

int cargarDescripcionPaises(ePais paises[], int tam, int id, char* descripcion){

	int retorno = 0;

	if(paises != NULL && tam > 0 && descripcion != NULL){

		for(int i = 0; i < tam; i++){

			if(paises[i].id == id){
				strcpy(descripcion, paises[i].descripcion);
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

int cargarDescripcionAutor(eAutor autor[], int tam, int id, char descripcion[]){

	int retorno = 0;

	if(autor != NULL && tam > 0 && descripcion != NULL){

		for(int i = 0; i < tam; i++){

			if(autor[i].id == id){
				strcpy(descripcion, autor[i].descripcion);
				retorno = 1;
				break;
			}
		}

	}

	return retorno;
}

int cargarDescripcionEditorial(eEditorial editorial[], int tam, int id, char descripcion[]){

	int retorno = 0;

	if(editorial != NULL && tam > 0 && descripcion != NULL){

		for(int i = 0; i < tam; i++){

			if(editorial[i].id == id){
				strcpy(descripcion, editorial[i].descripcion);
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

int buscarAutor(eAutor autor[], int tam, int id, int* pIndex){

	int retorno = 0;

	if(autor != NULL && tam > 0 && pIndex != NULL){

		*pIndex = -1;

		for(int i = 0; i < tam; i++){

			if(autor[i].id == id){
				*pIndex = i;
				break;
			}
		}

		retorno = 1;
	}

	return retorno;

}

int buscarEditorial(eEditorial editorial[], int tam, int id, int* pIndex){

	int retorno = 0;

	if(editorial != NULL && tam > 0 && pIndex != NULL){

		*pIndex = -1;

		for(int i = 0; i < tam; i++){

			if(editorial[i].id == id){
				*pIndex = i;
				break;
			}
		}

		retorno = 1;
	}

	return retorno;

}

int validarAutor(eAutor autor[], int tam, int id){

	int esValido = 0;
	int indice;

	if(buscarAutor(autor, tam, id, &indice)){

		if(indice != -1){
			esValido = 1;
		}
	}

	return esValido;

}

int validarEditorial(eEditorial editorial[], int tam, int id){

	int esValido = 0;
	int indice;

	if(buscarEditorial(editorial, tam, id, &indice)){

		if(indice != -1){
			esValido = 1;
		}
	}

	return esValido;

}
