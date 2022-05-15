/*
 * bibliotecaArrayPassenger.c
 *
 *  Created on: 14 may 2022
 *      Author: ludmi
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecaArrayPassenger.h"


//
///** \brief add in a existing list of passengers the values received as parameters
//* in the first empty position
//* \param list passenger*
//* \param len int
//* \param id int
//* \param name[] char
//* \param lastName[] char
//* \param price float
//* \param typePassenger int
//* \param flycode[] char
//* \return int Return (-1) if Error [Invalid length or NULL pointer or without
//free space] - (0) if Ok*/
//
//
int addPassenger(Passenger* list, int len, int id, char  name[] , char  lastName[],float price,int typePassenger, char flycode[]){
	int retorno;
	Passenger bufferPassenger;
	retorno =-1;


	if(list!=NULL  && len >0 && id>0 && name !=0 && lastName !=0 && price > 0 && typePassenger >0 && flycode!=0){

		bufferPassenger.id = id;
		bufferPassenger.isEmpty = 0;
		list[id] = bufferPassenger;
		(id)++;
		retorno = 0;
		printf("Los datos se cargaron exitosamente");

	 }else{printf("No se pudo cargar los datos");}


return retorno;
}
//
///** \brief find a Passenger by Id en returns the index position in array.
//*
//* \param list Passenger*
//* \param len int
//* \param id int
//* \return Return passenger index position or (-1) if [Invalid length or
//NULL pointer received or passenger not found]
//*
//*/
int findPassengerById(Passenger* list, int len,int id)
{
	int retorno;
	retorno = -1;

	if(list !=NULL && len >0 && id >0){
		for (int i = 0; i < len; i++) {
			if (list[i].id == id && list[i].isEmpty == 0) {
							retorno = i;
							break;
		    }
	     }
	}

	return retorno;
}


/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*
*
*
*
*
*
*/
int removePassenger(Passenger* list, int len, int id)
{
	int retorno;
retorno = 1;
		int index;
		if (list != NULL && len > 0 && id > 0) {
			index =  findPassengerById( list, len, id);
			if (index != -1) {

				list[index].isEmpty = 1;
				retorno = 0;
			}
		}
	return retorno;

}
/**
 * \brief Buscar primer posicion vacia
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int  getEmptyIndex(Passenger* list, int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Passenger buffer;
	if(list != NULL && list > 0 && order>=0)
	{
		do
			{
			 	flagSwap = 0;
				for(i=0;i<len-1;i++) {
					if(list[i].isEmpty || list[i+1].isEmpty)
					{
						continue;
					}
						if(strncmp(list[i].lastName,list[i+1].lastName,NAME_LEN) > 0)
					{
					 	flagSwap = 1;
						buffer = list[i];

						list[i] = list[i+1];
						list[i+1]=buffer;
					}
					else if(strncmp(list[i].lastName,list[i+1].lastName,NAME_LEN) == 0 )
					{
						if(list[i].type < list[i+1].type)
						{
							flagSwap = 1;

							buffer = list[i];

							list[i] = list[i+1];

							list[i+1]=buffer;
						 }

					      }
				        }

			 }while(flagSwap);
		}
		  return respuesta;
	}

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/

	int printPassenger(Passenger length){

	int retorno = -1 ;

	{
		if(length.isEmpty == 0)
		{    retorno = 0;
			printf("%c %c %f %c %d %d %d",length.name,length.lastName,length.price,length.flycode,length.typePassenger,length.typePassenger );
		}
	}
	return retorno;
}



	int sortPassengerss(Passenger* list, int len, int order)
	{
		int respuesta = -1;
		int flagSwap;
		int i;
		Passenger buffer;
		if(list != NULL && list > 0 && order>=0)
		{
			do
				{
				 	flagSwap = 0;
					for(i=0;i<len-1;i++) {
						if(list[i].isEmpty || list[i+1].isEmpty)
						{
							continue;
						}
							if(strncmp(list[i].flycode,list[i+1].flycode,NAME_LEN) > 0)
						{
						 	flagSwap = 1;
							buffer = list[i];

							list[i] = list[i+1];
							list[i+1]=buffer;
						}
						else if(strncmp(list[i].flycode,list[i+1].flycode,NAME_LEN) == 0 )
						{
							if(list[i].type < list[i+1].type)
							{
								flagSwap = 1;

								buffer = list[i];

								list[i] = list[i+1];

								list[i+1]=buffer;
							 }

						      }
					        }

				 }while(flagSwap);
			}
			  return respuesta;
		}
