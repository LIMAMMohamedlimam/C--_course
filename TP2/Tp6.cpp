#include <iostream>

using namespace std;

// Surcharge pour la fabrication d'un avion (modèle seul)
void manufactureAircraft(string model) {
    cout << "Manufactured basic aircraft. Model: " << model << endl;
}

// Surcharge pour la fabrication d'un avion (modèle + type de moteur)
void manufactureAircraft(string model, string engineType) {
    cout << "Manufactured aircraft. Model: " << model << ", Engine Type: " << engineType << endl;
}

// Surcharge pour la fabrication d'un avion (modèle + type de moteur + capacité)
void manufactureAircraft(string model, string engineType, int seatingCapacity) {
    cout << "Manufactured aircraft. Model: " << model << ", Engine Type: " 
         << engineType << ", Seating Capacity: " << seatingCapacity << endl;
}

// Surcharge pour la planification de maintenance (ID avion + type de maintenance)
void scheduleMaintenance(string aircraftID, string maintenanceType) {
    cout << "Scheduled maintenance for Aircraft " << aircraftID << ". Type: " << maintenanceType << endl;
}

// Surcharge pour la planification de maintenance (ID avion + type de maintenance + durée)
void scheduleMaintenance(string aircraftID, string maintenanceType, int duration) {
    cout << "Scheduled maintenance for Aircraft " << aircraftID << ". Type: " 
         << maintenanceType << ", Duration: " << duration << " hours" << endl;
}

// Surcharge pour la planification de maintenance (ID avion + type de maintenance + technicien)
void scheduleMaintenance(string aircraftID, string maintenanceType, string technician) {
    cout << "Scheduled maintenance for Aircraft " << aircraftID << ". Type: " 
         << maintenanceType << ", Technician: " << technician << endl;
}

int main() {
    // Fabrication des aéronefs
    manufactureAircraft("Airbus A380");
    manufactureAircraft("Airbus A380", "Rolls-Royce Trent 900");
    manufactureAircraft("Airbus A380", "Rolls-Royce Trent 900", 850);

    // Planification de la maintenance
    scheduleMaintenance("N12345", "Routine Check");
    scheduleMaintenance("N12345", "Engine Overhaul", 8);
    scheduleMaintenance("N12345", "Avionics Repair", "John Doe");

    return 0;
}
