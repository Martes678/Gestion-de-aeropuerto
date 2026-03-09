#include "Print.h"
#include <stddef.h>
#include <stdio.h>
void printBoardingQueue(const BoardingQueue* queue) {
    printf("-Cola de embarque:\n");
    if(queue == NULL) {
        printf("No hay pasajeros en la cola de embarque");
        return;
    }
    Passenger* current=queue->preferente;
    while(current != NULL) {
        printf("\t-%s con DNI %s\n", current->name, current->dni);
        current = current->next;
    }
    current = queue->turista;
    while(current != NULL) {
        printf("\t-%s con DNI: %s\n", current->name, current->dni);
        current = current->next;
    }
    current = queue->economy;
    while(current!=NULL) { 
        printf("\t-%s con DNI %s\n", current->name, current->dni);
        current = current->next;
    }
}
void printPassengerList(const Passenger* passengerList) {
    printf("-Pasajeros:\n");
    while(passengerList != NULL) {
        printf("\t-%s con DNI %s\n", passengerList->name, passengerList->dni);
        passengerList = passengerList->next;
    }
}
void printLuggage(const Plane* plane) {
    printf("-Bodega:\n");
    Passenger* passenger = plane->passengerList;
    if(passenger == NULL){
        printf("\tAun no hay maletas en este vuelo.\n");
        return;
    }
    while(passenger != NULL) {
        Luggage* luggage = passenger->luggage;
        if(luggage == NULL) {
            printf("\tAun no hay maletas en este vuelo.\n");
            return;
        }
        while(luggage != NULL) {
            printf("\t-Maleta de %s con DNI %s\n", passenger->name, luggage->ownerDNI);
            luggage = luggage->top;
        }
        passenger = passenger->next;
    }
}
void printFlights(const Plane* plane) {
    if(plane == NULL) {
        printf("El vuelo no existe.\n");
        return;
    }
    printf("Vuelo %s\n", plane->flightNumber);
    printBoardingQueue(plane->boardingQueue);
    printPassengerList(plane->passengerList);
    printLuggage(plane);
}
void printAirportStatus(const Airport* airport) {
    printf("Estado del aeropuerto:\n");
    const Plane* plane = airport->airplanes;
    if(plane == NULL) {
        printf("Aun no hay vuelos programados\n");
        return;
    }
    while(plane != NULL) {
        printFlights(plane);
        plane = plane->next;
    }
}