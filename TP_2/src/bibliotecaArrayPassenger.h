/*
 * bibliotecaArrayPassenger.h
 *
 *  Created on: 13 may 2022
 *      Author: ludmi
 */

#ifndef BIBLIOTECAARRAYPASSENGER_H_
#define BIBLIOTECAARRAYPASSENGER_H_
#define NAME_LEN 51
#define LASTNAME_LEN 51

struct
{
int id;
char name[51] ;
char lastName[51];
float price;
char flycode[10];
int  typePassenger;
int isEmpty;
int type;
}typedef Passenger;


int removePassenger(Passenger* list, int len, int id);
int findPassengerById(Passenger* list, int len,int id);
int initPassengers(Passenger* list, int len);
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[],float price,int typePassenger,char flycode[]);
int  getEmptyIndex(Passenger* list, int len);
int incrementarId();


#endif /* BIBLIOTECAARRAYPASSENGER_H_ */