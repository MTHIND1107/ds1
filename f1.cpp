#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FlightInfo
{
	char* destination;
	char* date;
};

void fillFlightInfo(struct FlightInfo* flight, const char* destination, const char* date)
{
	flight->destination = (char *)malloc((strlen(destination) + 1) * sizeof(char));
	strcpy_s(flight->destination, strlen(destination) + 1, destination);

	flight->date = (char *)malloc((strlen(date) + 1) * sizeof(char));
	strcpy_s(flight->date, strlen(date) + 1, date);
}

void printFlightInfo(struct FlightInfo* flights)
{
	for (int i = 0; i < 10; ++i)
	{
		printf("%-35s%-35s\n", flights[i].destination, flights[i].date);
	}
}

int main(void)
{
	struct FlightInfo flights[10];

	for (int i = 0; i < 10; ++i)
	{
		char destination[30];
		char date[30];

		printf("Enter destination for flight %d:", i + 1);
		fgets(destination, sizeof(destination), stdin);
		destination[strcspn(destination, "\n")] = '\0';

		printf("Enter date for flight %d:", i + 1);
		fgets(date, sizeof(date), stdin);
		date[strcspn(date, "\n")] = '\0';

		fillFlightInfo(&flights[i], destination, date);
	}

	printFlightInfo(flights);

	for (int i = 0; i < 10; ++i)
	{
		free(flights[i].destination);
		free(flights[i].date);
	}
	return 0;
}