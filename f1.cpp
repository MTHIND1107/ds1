/*
 * FILE:f1.cpp
 * PROJECT:DS1
 * PROGRAMMER:MANREET THIND (Student ID:8982315)
 * FIRSTVERSION:17/5/24
 * DESCRIPTION :
 * The functions in this file takes in information about flights and stores the destination and date in an array of structs to be displayed.
 * Dynamic memory allocation is used to store the strings in the struct.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct to store flight information
struct FlightInfo
{
	char* destination;
	char* date;
};
/* 
Function: fillFlightInfo() 
Parameter: 
struct FlightInfo* flight: pointer to a struct FlightInfo where the flight information will be stored.
const char* destination: pointer to a C-style string containing the destination of the flight.
const char* date: pointer to a C-style string containing the date of the flight.
Return Value: void
Description: This function fills in the fields of a FlightInfo struct with the provided destination and date information.
Memory is dynamically allocated to store the destination and date strings.
*/
void fillFlightInfo(struct FlightInfo* flight, const char* destination, const char* date)
{
	//Memory allocation for destination string
	flight->destination = (char *)malloc((strlen(destination) + 1) * sizeof(char));
	//copy content using strcpy_s
	strcpy_s(flight->destination, strlen(destination) + 1, destination);

	//Memory allocation for date string
	flight->date = (char *)malloc((strlen(date) + 1) * sizeof(char));
	//copy content using strcpy_s
	strcpy_s(flight->date, strlen(date) + 1, date);
}

/*
Function: printFlightInfo()
Parameter:
struct FlightInfo* flights: pointer to an array of FlightInfo structs containing flight information.
Return Value: void
Description: This function prints the flight information stored in an array of FlightInfo structs.
Each flight's destination and date are displayed in a formatted manner, one flight per line.
*/
void printFlightInfo(struct FlightInfo* flights)
{
	for (int i = 0; i < 10; ++i)
	{
		//Printing destination and dat with formatting
		printf("%-35s%-35s\n", flights[i].destination, flights[i].date);
	}
}

int main(void)
{
	//Array to store flight information
	struct FlightInfo flights[10];

	for (int i = 0; i < 10; ++i)
	{
		char destination[30];
		char date[30];

		//Prompt user to input estination
		printf("Enter destination for flight %d:", i + 1);
		fgets(destination, sizeof(destination), stdin);
		destination[strcspn(destination, "\n")] = '\0';

		//Prompt user to input date
		printf("Enter date for flight %d:", i + 1);
		fgets(date, sizeof(date), stdin);
		date[strcspn(date, "\n")] = '\0';

		fillFlightInfo(&flights[i], destination, date);
	}

	//print flight information
	printFlightInfo(flights);


	for (int i = 0; i < 10; ++i)
	{
		//free dynamically allocated memory
		free(flights[i].destination);
		free(flights[i].date);
	}
	return 0;
}
