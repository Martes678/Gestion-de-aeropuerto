#ifndef DELETE_H
#define DELETE_H
#include "Airport.h"
void destroyAirport(Airport* airport);
void deletePlane(Plane* plane);
void deleteBoardingQueue(BoardingQueue* queue);
void removePassengers(Passenger* passenger);
void deleteLuggage(Luggage* luggage);
#endif//DELETE_H
