#ifndef AIRPORT_H
#define AIRPORT_H
#include "Structures.h"
#include "Print.h"
#include "Delete.h"
Airport* createAirport();
Plane* findOrCreatePlane(Airport* airport, const char* flightNumber);
void checkInPassenger(Airport* airport, const char* name, const char* dni, const char* flightNumber, TicketClass ticketClass);
void processCheckIn(const Airport* airport);
void boardPassenger(const Airport* airport, const char* flightNumber);
void closeBoarding(const Airport* airport);
void pushLuggage(Passenger* passenger, const char* ownerDNI);
#endif//AIRPORT_H