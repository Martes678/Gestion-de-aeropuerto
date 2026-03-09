#include "Airport.h"

int main(void) {
    Airport* airport = createAirport();

    checkInPassenger(airport, "Pedro", "123123123-H", "IB203", ECONOMY);
    checkInPassenger(airport, "Elisa", "321321321-D", "RY405", TURISTA);
    checkInPassenger(airport, "Carolina", "17799874-X", "IB203", PREFERENTE);
    checkInPassenger(airport, "Marcos", "22669988-D", "IB203", PREFERENTE);
    checkInPassenger(airport, "Pepe", "56895674-G", "RY405", ECONOMY);
    checkInPassenger(airport, "Valeria", "68742532-P", "RY405", PREFERENTE);

    processCheckIn(airport);
    processCheckIn(airport);
    processCheckIn(airport);

    boardPassenger(airport, "IB203");
    processCheckIn(airport);
    boardPassenger(airport, "IB203");

    printAirportStatus(airport);

    processCheckIn(airport);
    boardPassenger(airport, "RY405");
    processCheckIn(airport);
    boardPassenger(airport, "RY405");
    boardPassenger(airport, "RY405");

    closeBoarding(airport);
    printAirportStatus(airport);

    destroyAirport(airport);

    return 0;
}