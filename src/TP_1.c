/*
 ============================================================================
 Name        : TP_1.c
 Author      : Ludmila A. Poznya
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "utnBibliotecaTomaDeDatos.h"
#include "utnBibliotecaCalculos.h"

int main(void) {
	setbuf(stdout, NULL);
	int retornoFuncion;
	int opcionMenu;
    int kmIngresado;

    float precioIngresasdoAerolineas;
    float precioIngresasdoLatam;

    float  precioTarjetaDebitoAerolinas;
    float precioTarjetaDebitoLatam;
    float precioTarjetaCreditoAerolineas;
    float precioTarjetaCreditoLatam;
    float precioBtcAerolineas;
    float precioBtcLatam;
    float precioUnitarioAerolineas;
    float precioUnitarioLatam ;
    float diferenciaPrecioIngresado;

    int  flagIngresoPrecioAerolineas;
    int  flagIngresoPrecioLatam;
    int  flagKmIngresado;
    int  flagCalculoCostos;

    int retornoFuncionCalculoBtc;
    int retornoFuncionDescuento;
    int retornoFuncionInteres;

    int kmCargaForzada;
    float precioAerlineasCargaForzada;
    float precioLatamCargaForzada;
    float  precioTarjetaDebitoAerolinasCargaForzada;
    float precioTarjetaDebitoLatamCargaForzada;
    float precioTarjetaCreditoAerolineasCargaForzada;
    float precioTarjetaCreditoLatamCargaForzada;
    float precioBtcAerolineasCargaForzada;
    float precioBtcLatamCargaForzada;
    float precioUnitarioAerolineasCargaForzada;
    float precioUnitarioLatamCargaForzada ;
    float diferenciaPrecioIngresadoCargaForzada;
    int   retornoCargaForzada;


    diferenciaPrecioIngresado = 0;
    flagIngresoPrecioAerolineas= 0;
    flagIngresoPrecioLatam =0;
    flagKmIngresado = 0;
    flagCalculoCostos = 0 ;

do{
	  printf("\t\t\t\t\t MENU PRINCIPAL \n");
	  printf("\t\t-------------------------------------------------------------- \n");

	  printf("\t\t 1. Ingresar Kilometros\n ");
	  printf("\t\t 2. Ingresar precio de vuelo\n ");
	  printf("\t\t 3. Calcular los costos\n");
	  printf("\t\t 4. Informar Resultados\n ");
	  printf("\t\t 5. Carga forzada de datos\n ");
	  printf("\t\t 6. Salir\n ");

	  retornoFuncion=getInt(&opcionMenu,"----","Ingreso un numero invalido",6,1,3);
	   if(retornoFuncion==0){
			  switch(opcionMenu){
			case 1:
				if (flagKmIngresado == 0){
				retornoFuncion = getInt(&kmIngresado," Ingrese los km que desea viajar :\n"
							,"No ingreso un km valido :\n",1000000,0,3);
				  if (retornoFuncion == 0){
					  flagKmIngresado=1;

				  }//cierre if retorno
				}//cierre if flag km ingresados
         		break;

			case 2:

				if (flagIngresoPrecioAerolineas ==0 ){
                    printf("Ingresar Precio de Vuelos:\n");

                   retornoFuncion= getFloat(&precioIngresasdoAerolineas,"Ingrese el precio de Aerolineas\n",
                		   "No ingreso un valor valido\n",10000000,0,3);
                   flagIngresoPrecioAerolineas = 1;
				}//cierre if flag aerolineas

				if (flagIngresoPrecioLatam==0){
                   retornoFuncion= getFloat(&precioIngresasdoLatam,"Ingrese el precio de Latam\n",
                		   "No ingreso un valor valido\n",10000000,0,3);
                   flagIngresoPrecioLatam = 1;
                   while ( flagIngresoPrecioAerolineas==0 || flagIngresoPrecioLatam ==0){
                	   printf("Ingrese los valores de ambas aerolineas\n");
                   }
				}//cierre if flag latam

				break;
			case 3:

				if ( flagCalculoCostos ==0){
					if (flagIngresoPrecioAerolineas ==1 && flagIngresoPrecioLatam ==1 && flagKmIngresado ==1){

				retornoFuncionDescuento = descuento (&precioTarjetaDebitoAerolinas,precioIngresasdoAerolineas ,10);
				retornoFuncionInteres= interes (&precioTarjetaCreditoAerolineas,precioIngresasdoAerolineas ,25);
				retornoFuncionCalculoBtc = convertidorDeMoneda  (&precioBtcAerolineas,precioIngresasdoAerolineas,4579777.84);
				precioUnitarioAerolineas = precioIngresasdoAerolineas / kmIngresado;


				retornoFuncionDescuento = descuento (&precioTarjetaDebitoLatam,precioIngresasdoLatam ,10);
				retornoFuncionInteres = interes (&precioTarjetaCreditoLatam,precioIngresasdoLatam ,25);
				retornoFuncionCalculoBtc = convertidorDeMoneda  (&precioBtcLatam,precioIngresasdoLatam,4579777.84);
                precioUnitarioLatam = precioIngresasdoLatam / kmIngresado;

				if (precioIngresasdoAerolineas > precioIngresasdoLatam){
					diferenciaPrecioIngresado = precioIngresasdoAerolineas-precioIngresasdoLatam;
				} else if( precioIngresasdoLatam > precioIngresasdoAerolineas){
					diferenciaPrecioIngresado = precioIngresasdoLatam- precioIngresasdoAerolineas;
				}

				if (retornoFuncionCalculoBtc == 0 && retornoFuncionDescuento ==0 && retornoFuncionInteres ==0 ){
								flagCalculoCostos=1;
							}
				}else if (flagIngresoPrecioAerolineas ==0 && flagIngresoPrecioLatam ==0 && flagKmIngresado ==0){
						printf("Debe cargar valores antes de calcular el precio de su viaje\n");

					}
				}//cierre if flag calculo costos
				break;
			case 4:
				if(flagCalculoCostos==1){

			    printf ("Kms Ingresados: %d \n\n", kmIngresado);

                printf("Precio Latam " );
				printf("a)Precio con tarjeta de débito: %.2f \n ",precioTarjetaDebitoLatam );
				printf("b)Precio con tarjeta de crédito: %.2f \n ",precioTarjetaCreditoLatam);
				printf("c)Precio pagando con bitcoin :  %.10f \n ",precioBtcLatam);
				printf("d)El precio unitario es : %.2f \n\n ",precioUnitarioLatam);

                printf("Precio Aerolineas ");
				printf("a)Precio con tarjeta de débito: %.2f \n ",precioTarjetaDebitoAerolinas);
				printf("b)Precio con tarjeta de crédito: %.2f \n ",precioTarjetaCreditoAerolineas);
				printf("c)Precio pagando con bitcoin :  %.10f \n ",precioBtcAerolineas);
				printf("d)El precio unitario es : %.2f \n\n ",precioUnitarioAerolineas);

				printf("La diferencia de precio es :%2.f \n\n",diferenciaPrecioIngresado);
				} else if(flagCalculoCostos==0){
					printf("Debe ingresar valores y calcularlos para mostrar los resultados");
				}

				break;
			case 5:

				kmCargaForzada = 7090;
				precioAerlineasCargaForzada=162965;
				precioLatamCargaForzada= 159339;

				retornoCargaForzada = descuento(&precioTarjetaDebitoAerolinasCargaForzada,precioAerlineasCargaForzada,10);
				retornoCargaForzada= interes (&precioTarjetaCreditoAerolineasCargaForzada,precioAerlineasCargaForzada,25);
				retornoCargaForzada = convertidorDeMoneda (&precioBtcAerolineasCargaForzada,precioAerlineasCargaForzada,4579777.84);
				 precioUnitarioAerolineasCargaForzada = precioAerlineasCargaForzada / kmCargaForzada;

				retornoCargaForzada = descuento(&precioTarjetaDebitoLatamCargaForzada,precioLatamCargaForzada,10);
				retornoCargaForzada= interes (&precioTarjetaCreditoLatamCargaForzada,precioLatamCargaForzada,25);
				retornoCargaForzada = convertidorDeMoneda  (&precioBtcLatamCargaForzada,precioLatamCargaForzada,4579777.84);
				precioUnitarioLatamCargaForzada = 	precioLatamCargaForzada / kmCargaForzada;

				if (precioAerlineasCargaForzada > precioLatamCargaForzada){
					diferenciaPrecioIngresadoCargaForzada =precioAerlineasCargaForzada-precioLatamCargaForzada;
					} else if(precioLatamCargaForzada > precioAerlineasCargaForzada){
						diferenciaPrecioIngresadoCargaForzada = precioLatamCargaForzada- precioAerlineasCargaForzada;
					}
               if (retornoCargaForzada ==0 ){
                   printf("Aerolineas \n");
   				printf("Precio con tarjeta de débito: %.2f \n ",precioTarjetaDebitoAerolinasCargaForzada );
   				printf("Precio con tarjeta de crédito: %.2f \n ",precioTarjetaCreditoAerolineasCargaForzada);
   				printf("Precio pagando con bitcoin :  %.10f \n ",precioBtcAerolineasCargaForzada);
   				printf("El precio unitario es : %.2f \n\n ",precioUnitarioAerolineasCargaForzada);

                   printf("Latam  \n");
   				printf("Precio con tarjeta de débito: %.2f \n ",precioTarjetaDebitoLatamCargaForzada);
   				printf("Precio con tarjeta de crédito: %.2f \n ",precioTarjetaCreditoLatamCargaForzada);
   				printf("Precio pagando con bitcoin :  %.10f \n ",precioBtcLatamCargaForzada);
   				printf("El precio unitario es : %.2f \n\n ",precioUnitarioLatamCargaForzada );

   				printf("La diferencia de precio es :%2.f \n\n",diferenciaPrecioIngresadoCargaForzada);
               }

				break;
			case 6:
                 printf("Gracias!");
				break;


			}//cierre switch principal
	   }//cierre if retorno funcion
}while(opcionMenu!=6);
	return EXIT_SUCCESS;
}//cierre funcion main

