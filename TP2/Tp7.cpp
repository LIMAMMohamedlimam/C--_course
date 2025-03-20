#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Surcharge de fonction pour la réservation de billets
void bookTicket(string departure) {
    cout << "Booked one-way ticket. Departure Flight: " << departure << endl;
}

void bookTicket(string departure, string returnFlight) {
    cout << "Booked round-trip ticket. Departure Flight: " << departure << ", Return Flight: " << returnFlight << endl;
}

void bookTicket(vector<string> flights) {
    cout << "Booked multi-city ticket. Flights: ";
    for (size_t i = 0; i < flights.size(); i++) {
        cout << flights[i];
        if (i < flights.size() - 1) cout << " -> ";
    }
    cout << endl;
}

// Surcharge de fonction pour les notifications de statut de vol
void flightStatus(string flightNumber, string status) {
    cout << "Flight " << flightNumber << " status: " << status << endl;
}

void flightStatus(string flightNumber, string status, int delayTime) {
    cout << "Flight " << flightNumber << " status: " << status << ", Delayed by: " << delayTime << " minutes" << endl;
}

void flightStatus(string flightNumber, string status, string newGate) {
    cout << "Flight " << flightNumber << " status: " << status << ", New Gate: " << newGate << endl;
}

int main() {
    // Exemple de réservations de billets
    bookTicket("AA123");
    bookTicket("AA123", "AA456");
    bookTicket({"AA123", "AA789", "AA456"});

    // Exemple de notifications de statut de vol
    flightStatus("AA123", "On Time");
    flightStatus("AA123", "Delayed", 30);
    flightStatus("AA123", "Boarding", "Gate B12");

    return 0;
}
