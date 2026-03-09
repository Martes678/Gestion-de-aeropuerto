#include "Airport.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

Airport* createAirport() {
    Airport* airport = malloc(sizeof(Airport));
    airport->checkInQueue = malloc(sizeof(CheckInQueue));
    airport->checkInQueue->front = NULL;
    airport->checkInQueue->rear = NULL;
    airport->airplanes = NULL;
    return airport;
}

Plane* findOrCreatePlane(Airport* airport, const char* flightNumber) {
    Plane* current = airport->airplanes;
    while (current != NULL) {
        if (strcmp(current->flightNumber, flightNumber) == 0) {
            return current;
        }
        current = current->next;
    }

    Plane* newPlane = malloc(sizeof(Plane));
    strcpy(newPlane->flightNumber, flightNumber);
    newPlane->passengerList = NULL;
    newPlane->boardingQueue = malloc(sizeof(BoardingQueue));
    newPlane->boardingQueue->preferente = NULL;
    newPlane->boardingQueue->turista = NULL;
    newPlane->boardingQueue->economy = NULL;
    newPlane->next = airport->airplanes;
    airport->airplanes = newPlane;
    return newPlane;
}

void pushLuggage(Passenger* passenger, const char* ownerDNI) {
    Luggage* newLuggage = malloc(sizeof(Luggage));
    strcpy(newLuggage->ownerDNI, ownerDNI);
    newLuggage->top = passenger->luggage;
    passenger->luggage = newLuggage;
}

void checkInPassenger(Airport* airport, const char* name, const char* dni, const char* flightNumber, TicketClass pClass) {
    Plane* plane = findOrCreatePlane(airport, flightNumber);
    Passenger* newPassenger = malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    strcpy(newPassenger->dni, dni);
    strcpy(newPassenger->flightNumber, flightNumber);
    newPassenger->ticketClass = pClass;
    newPassenger->luggage = NULL;
    newPassenger->next = NULL;

    if (airport->checkInQueue->rear != NULL) {
        airport->checkInQueue->rear->next = newPassenger;
    } else {
        airport->checkInQueue->front = newPassenger;
    }
    airport->checkInQueue->rear = newPassenger;
}

void processCheckIn(const Airport* airport) {
    if (airport->checkInQueue->front != NULL) {
        Passenger* passenger = airport->checkInQueue->front;
        airport->checkInQueue->front = passenger->next;
        const Plane* plane = airport->airplanes;
        while (plane != NULL) {
            if (strcmp(plane->flightNumber, passenger->flightNumber) == 0) {
                if (passenger->ticketClass == PREFERENTE) {
                    passenger->next = plane->boardingQueue->preferente;
                    plane->boardingQueue->preferente = passenger;
                } else if (passenger->ticketClass == TURISTA) {
                    passenger->next = plane->boardingQueue->turista;
                    plane->boardingQueue->turista = passenger;
                } else {
                    passenger->next = plane->boardingQueue->economy;
                    plane->boardingQueue->economy = passenger;
                }
                break;
            }
            plane = plane->next;
        }
        pushLuggage(passenger, passenger->dni);
    }
}

void boardPassenger(const Airport* airport, const char* flightNumber) {
    Plane* plane = airport->airplanes;
    while (plane != NULL) {
        if (strcmp(plane->flightNumber, flightNumber) == 0) {
            Passenger* passenger = NULL;
            if (plane->boardingQueue->preferente != NULL) {
                passenger = plane->boardingQueue->preferente;
                plane->boardingQueue->preferente = passenger->next;
            } else if (plane->boardingQueue->turista != NULL) {
                passenger = plane->boardingQueue->turista;
                plane->boardingQueue->turista = passenger->next;
            } else if (plane->boardingQueue->economy != NULL) {
                passenger = plane->boardingQueue->economy;
                plane->boardingQueue->economy = passenger->next;
            }
            if (passenger != NULL) {
                passenger->next = NULL;
                if (plane->passengerList == NULL) {
                    plane->passengerList = passenger;
                } else {
                    Passenger* current = plane->passengerList;
                    while (current->next != NULL) {
                        current = current->next;
                    }
                    current->next = passenger;
                }
            }
        }
        plane = plane->next;
    }
}

void closeBoarding(const Airport* airport) {
    const Plane* plane = airport->airplanes;
    while (plane != NULL) {
        const Passenger* currentPassenger = plane->passengerList;
        while (currentPassenger != NULL) {
            const Luggage* currentLuggage = currentPassenger->luggage;
            while (currentLuggage != NULL) {
                currentLuggage = currentLuggage->top;
            }
            currentPassenger = currentPassenger->next;
        }
        plane = plane->next;
    }
}