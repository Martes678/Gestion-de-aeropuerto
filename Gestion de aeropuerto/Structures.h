#ifndef STRUCTURES_H
#define STRUCTURES_H
typedef enum{
    PREFERENTE,
    TURISTA,
    ECONOMY
}TicketClass;
typedef struct Luggage{
    char ownerDNI[15];
    struct Luggage* top;
}Luggage;
typedef struct Passenger{
    char name[50];
    char dni[15];
    char flightNumber[5];
    TicketClass ticketClass;
    Luggage* luggage;
    struct Passenger* next;
}Passenger;
typedef struct BoardingQueue{
    Passenger* preferente;
    Passenger* turista;
    Passenger* economy;
}BoardingQueue;
typedef struct Plane{
    char flightNumber[5];
    Passenger* passengerList;
    BoardingQueue* boardingQueue;
    struct Plane* next;
}Plane;
typedef struct CheckInQueue{
    Passenger* front;
    Passenger* rear;
}CheckInQueue;
typedef struct Airport{
    CheckInQueue* checkInQueue;
    Plane* airplanes;
}Airport;
#endif//STRUCTURES_H
