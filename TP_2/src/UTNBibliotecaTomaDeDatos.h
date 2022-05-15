/*
 * UTNBibliotecaTomaDeDatos.h
 *
 *  Created on: 13 may 2022
 *      Author: ludmi
 */



#ifndef UTNBIBLIOTECATOMADEDATOS_H_
#define UTNBIBLIOTECATOMADEDATOS_H_




#endif /* UTNBIBLIOTECATOMADEDATOS_H_ */



int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int valorAlfanumerico(char *pArray, char *mensaje);


