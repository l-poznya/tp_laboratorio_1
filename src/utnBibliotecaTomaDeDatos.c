/*
 * biblioteca-utn.c
 *
 *  Created on: 11 abr 2022
 *      Author: ludmi
 */
#include <stdio.h>
#include <stdlib.h>
/// @fn int getInt(int*, char*, char*, int, int, int)
/// @brief Solicita un numero  de tipo entero  al usuario, luego de verificarlo devuelve el resultado
///
/// @param pNumeroIngresado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje de Error a ser mostrado
/// @param maximo Es el numero maximo a ser aceptado
/// @param minimo Es el numero maximo a ser aceptado
///
/// @param maximoDeReintentos cantidad maxima de posibilidades antes de mostrar el mensaje error
/// @return
int getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,
		int maximo, int minimo, int maximoDeReintentos){

	int auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%d", &auxNumeroIngresado);
			maximoDeReintentos--;

			if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo){
						*pNumeroIngresado = auxNumeroIngresado;
						retorno = 0;
						break;
			}else{
				printf("%s", mensajeError);
			}

		}while(maximoDeReintentos > 0);
	}

	return retorno;
}
/// @fn int getFloat(float*, char*, char*, float, float, float)
/// @brief Solicita un numero  de tipo flotante al usuario, luego de verificarlo devuelve el resultado
///
/// @param pNumeroIngresado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje de Error a ser mostrado
/// @param maximo Es el numero maximo a ser aceptado
/// @param minimo Es el numero maximo a ser aceptado
///
/// @param maximoDeReintentos cantidad maxima de posibilidades antes de mostrar el mensaje error
/// @return

int getFloat(float* pNumeroIngresado,char * mensaje,char * mensajeError,
		float maximo, float minimo, float maximoDeReintentos){

	float auxNumeroIngresado;
   int  retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%f", &auxNumeroIngresado);
			maximoDeReintentos--;

			if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo){
						*pNumeroIngresado = auxNumeroIngresado;
						retorno = 0;
						break;
			}else{
				printf("%s", mensajeError);
			}

		}while(maximoDeReintentos > 0);
	}

	return retorno;
}

