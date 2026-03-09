#include "Delete.h"
#include <stdlib.h>

void deleteLuggage(Luggage* luggage) {
    while (luggage != NULL) {
        Luggage* temp = luggage;
        luggage = luggage->top;
        free(temp);
    }
}

void removePassengers(Passenger* passenger) {
    while (passenger != NULL) {
        Passenger* temp = passenger;
        passenger = passenger->next;
        deleteLuggage(temp->luggage);
        free(temp);
    }
}

void deleteBoardingQueue(BoardingQueue* queue) {
    removePassengers(queue->preferente);
    removePassengers(queue->turista);
    removePassengers(queue->economy);
    free(queue);
}

void deletePlane(Plane* plane) {
    while (plane != NULL) {
        Plane* temp = plane;
        plane = plane->next;
        deleteBoardingQueue(temp->boardingQueue);
        removePassengers(temp->passengerList);
        free(temp);
    }
}

void destroyAirport(Airport* airport) {
    deletePlane(airport->airplanes);
    free(airport->checkInQueue);
    free(airport);
}