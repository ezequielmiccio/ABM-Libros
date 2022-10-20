/*
 ============================================================================
 Name        : PARCIAL_1.c
 Author      : Ezequiel Miccio
 Version     : PARCIAL 1
 Description : Primera parte
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libro.h"
#include "utn.h"

#define TAM 12
#define TAMP 5
#define TAME 5
#define TAMA 10
#define TAMT 2

int main(void) {

	setbuf(stdout, NULL);

	char salir = 'n';
	int idLibro = 1;
	int idPais = 1;
	int idEditorial = 1;
	int idAutor = 1;
	int idTipo = 1;
	int contador = 0;
	int contadorLibroMenor = 0;
	int contadorFecha = 0;
	float totalImporte = 0;
	float promedioImporte;
	eLibro libros[TAM];
	ePais paises[TAMP];
	eEditorial editoriales[TAME];
	eAutor autores[TAMA];
	eTipo tipos[TAMT];

	hardcodearPaises(paises, TAMP, &idPais);
	hardcodearEditoriales(editoriales, TAME, &idEditorial);
	hardcodearAutores(autores, TAMA, &idAutor);
	hardcodearTipo(tipos, TAMT, &idTipo);

	inicializarLibro(libros, TAM);

	do{

		switch(menu()){
		case 1:
			altaLibro(libros, TAM, &idLibro, editoriales, TAME, autores, TAMA, paises, TAMP, tipos, TAMT);
			break;
		case 2:
			modificarLibro(libros, TAM, autores, editoriales, paises, TAMA, TAME, tipos, TAMT);
			break;
		case 3:
			bajaLibro(libros, TAM, editoriales, autores, tipos);
			break;
		case 4:
				totalImporte = importeTotal(libros, TAM);
				contador = contadorLibros(libros, TAM);
				promedioImporte = totalImporte / contador;
				contadorLibroMenor = contadorLibrosPromedio(libros, TAM, &promedioImporte);
				contadorFecha = contadorLibrosFecha(libros, TAM);

			if(contador >= 1){
				printf("A. El importe total de los libros cargados es de: $%.2f. Quedando un promedio de $%.2f por libro.\n%d libros no superan este promedio\n", totalImporte, promedioImporte, contadorLibroMenor);
				printf("B. La cantidad de libros con fecha posterior al 31/12/1999 son %d\n", contadorFecha);
			}else{
				printf("No hay libros cargados en el sistema\n");
			}
			break;
		case 5:
			listarInformes(libros, TAM, editoriales, TAME, autores, TAMA, paises, TAMP, tipos, TAMT);
			break;
		case 6:
			if(confirmar(&salir, "Seguro desea salir? s/n \n", "Error: Reingrese una opcion valida: s/n \n")){

				printf("\n*** ¡Gracias por visitarnos! ***\n");

			}else{

				fflush(stdin);
				printf("¡Ha sido de vuelto al menu principal!\n\n");
			}
			break;
		}

	}while(salir != 's');


	return EXIT_SUCCESS;

}
