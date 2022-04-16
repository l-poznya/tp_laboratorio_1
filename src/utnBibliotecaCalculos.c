/*
 * utnBibliotecaCalculos.c
 *
 *  Created on: 15 abr 2022
 *      Author: ludmi
 */
#include <stdio.h>
#include <stdlib.h>

/// @fn int convertidorAPesos(float*, float, float)
/// @brief  Usa el valor ingresado por el usuario, con el valor monetario de la moneda,
///         hace la convercion mediante una division.
///
/// @param resultado   Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param numeroIngresado  Cantidad que se desea convertir a otra moneda
/// @param  valorMoneda valor monetario de la moneda a la que se desea convertir
/// @return
int convertidorDeMoneda  (float * resultado, float  numeroIngresado,float valorMoneda){
	int retorno;
	retorno = -1;
	float auxNumeroIngresado;
	double auxResultado;


    	 auxNumeroIngresado = numeroIngresado;
    	 auxResultado = *resultado;

    	 auxResultado = auxNumeroIngresado / valorMoneda;
    		numeroIngresado = auxNumeroIngresado;
    		*resultado = auxResultado;
    		retorno = 0;

	return retorno;
}

/// @fn int descuento(float*, float, int)
/// @brief Usa un  valor ingresado por el usuario, cargando un porcentaje da como resultado
/// el descuento
///
/// @param resultado  Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param valorIngresado
/// @param porcentaje descuento que se desea realizar al numero ingresadp
/// @return
int descuento (float * resultado, float  numeroIngresado, int porcentaje){
	int retorno;
	retorno = -1;
	float auxNumeroIngresado;
	double auxResultado;


    	 auxNumeroIngresado = numeroIngresado;
    	 auxResultado = *resultado;

    	 auxResultado = auxNumeroIngresado - (auxNumeroIngresado * porcentaje/100);
    		numeroIngresado = auxNumeroIngresado;
    		*resultado = auxResultado;
    		retorno = 0;

	return retorno;
}

/// @fn int interes(float*, float, int)
/// @brief Usa el valor ingresdo por el usuario, cargando un porcentaje da como resultado el interes
///
/// @param resultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param numeroIngresado
/// @param porcentaje interes que se desea aplicar al numero ingresado
/// @return
int interes (float * resultado, float  numeroIngresado, int porcentaje){
	int retorno;
	retorno = -1;
	float auxNumeroIngresado;
	double auxResultado;


    	 auxNumeroIngresado = numeroIngresado;
    	 auxResultado = *resultado;

    	 auxResultado = auxNumeroIngresado + (auxNumeroIngresado * porcentaje/100);
    		numeroIngresado = auxNumeroIngresado;
    		*resultado = auxResultado;
    		retorno = 0;

	return retorno;
}

