/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 ============================================================================
 */
#define CANTIDAD_PASAJEROS 2000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "UTNBibliotecaTomaDeDatos.h"
#include "bibliotecaArrayPassenger.h"

int main(void) {
	setbuf(stdout, NULL);
   Passenger arrayPasajeros [CANTIDAD_PASAJEROS];
   int opcionMenu;
   int bufferIndice;
   int validacionRetorno;
   char bufferName;
   char bufferLastName;
   float bufferprice;
   int buffertype;
   char bufferFlyCode;
   int bufferStatus;
   int bufferid;





     do {
    	 validacionRetorno=utn_getNumero(&opcionMenu,
						 "\t\t\t\t\t MENU \t\t\t\t\t \n\n "
						 "\t 1. ALTAS - Cargar datos de pasajeros\n"
						 "\t 2. MODIFICAR - Modificar un dato ya ingresado \n"
						 "\t 3. BAJA - Dar de baja  \n"
						 "\t 4.INFORMAR -  \n"
						 "\t 5.CARGA FORZADA-\n\n"

						 "\t 6. salir \n\n\n ","No se pudo obtener la opcion",1,6,3);

     if(validacionRetorno==0){
  		  switch(opcionMenu){

  			    case 1:
                bufferIndice = getEmptyIndex(arrayPasajeros,CANTIDAD_PASAJEROS);
                if(bufferIndice >=0){
                	if( utn_getNombre(&bufferName, NAME_LEN,"\t Ingrese su nombre", "Error, no puedo ingresar el dato", 3) ==0 &&
                		utn_getNombre(&bufferLastName, LASTNAME_LEN,"\t Ingrese su apellido", "Error, no puedo ingresar el dato", 3) ==0 &&
						utn_getNumeroFlotante(&bufferprice, "\t Ingrese el precio del pasaje", "Error, no puedo ingresar el dato",0,3829.000,3) ==0 &&
						utn_getNumero(&buffertype,"Ingrese la clase en la que desea viajar\n 1-Primera Clase \n 2-Ejecutivo \n 3-Economico\n ","Error, no puedo ingresar el dato",0,1,2) ==0 &&
						valorAlfanumerico(&bufferFlyCode,"Ingrese su FLyCode") ==0 &&
						utn_getNumero(bufferStatus,"Ingrese el estdo de su vuelo 1-Activo \n 2-Cancelado \n 3-Demorado\n ","Error, no puedo ingresar el dato",0,1,2) ==0)
                	{
                		addPassenger(arrayPasajeros,CANTIDAD_PASAJEROS,bufferid, bufferName, bufferLastName,bufferprice,buffertype,bufferFlyCode);

                	}
                }
                  	break;

  			  case 2:



  				   break;  //baja y modificarmisma estructura
  			  case 3:


//  				   * Se ingresa el numero de id y se hace una baja logica
//  				   * poner mensaje de verificacion antes de la eliminacion

  				  break;
  			  case 4:

  				  break;
  			  case 5:
  				  break;
  			  case 6:
  				  break;

  			  }//cierre switch menu
  			  }//cierre if validacion retorno
                    }while(opcionMenu!= 6);
	return EXIT_SUCCESS;
}
