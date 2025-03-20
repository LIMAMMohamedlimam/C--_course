#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>


using namespace std;

// Function to create a basic car with brand and model
void manufactureCar(const string& brand, const string& model) {
    cout << "Manufacturing Car: " << brand << " " << model << endl;
}

// Function to create a car with brand, model, and engine type
void manufactureCar(const string& brand, const string& model, const string& engineType) {
    cout << "Manufacturing Car: " << brand << " " << model << " with " << engineType << " engine." << endl;
}

// Function to create a car with brand, model, engine type, and transmission type
void manufactureCar(const string& brand, const string& model, const string& engineType, const string& transmissionType) {
    cout << "Manufacturing Car: " << brand << " " << model << " with " << engineType << " engine and " << transmissionType << " transmission." << endl;
}

// Function to create a car with brand, model, engine type, transmission type, and custom features
void manufactureCar(const string& brand, const string& model, const string& engineType, const string& transmissionType, const string& color, int doors, int seating) {
    cout << "Manufacturing Car: " << brand << " " << model << " with " << engineType << " engine, " << transmissionType << " transmission, "
         << color << " color, " << doors << " doors, and seating for " << seating << " people." << endl;
}

// Function to estimate the price of a car based on its features
int estimatePrice(const string& engineType, const string& transmissionType, const string& color = "", int doors = 0, int seating = 0, int basePrice = 0) {
    int price = basePrice;

    if (engineType == "Electric") {
        price += 15000;
    } else if (engineType == "Hybrid") {
        price += 8000;
    } else if (engineType == "Diesel") {
        price += 5000;
    }

    if (transmissionType == "Automatic") {
        price += 3000;
    }

    if (color != "") {
        price += 1000; // Premium for custom color
    }

    if (doors > 4) {
        price += 500;
    }
    if (seating > 5) {
        price += 1000;
    }

    return price;
}

// Function to generate a random car
void generateRandomCar() {
    vector<string> brands = {"Toyota", "Ford", "Honda", "BMW", "Mercedes"};
    vector<string> models = {"F-150", "Camry", "Civic", "X5", "E-Class"};
    vector<string> engineTypes = {"Petrol", "Diesel", "Electric", "Hybrid"};
    vector<string> transmissionTypes = {"Manual", "Automatic"};
    vector<string> colors = {"Red", "Blue", "Black", "White", "Silver"};
    vector<int> doorsOptions = {4, 5};
    vector<int> seatingOptions = {4, 5, 7};

    string brand = brands[rand() % brands.size()];
    string model = models[rand() % models.size()];
    string engineType = engineTypes[rand() % engineTypes.size()];
    string transmissionType = transmissionTypes[rand() % transmissionTypes.size()];
    string color = colors[rand() % colors.size()];
    int doors = doorsOptions[rand() % doorsOptions.size()];
    int seating = seatingOptions[rand() % seatingOptions.size()];
    int basePrice = rand() % 20000 + 10000;

    cout << "Randomly Generated Car:" << endl;
    manufactureCar(brand, model, engineType, transmissionType, color, doors, seating);
    cout << "Estimated Price: $" << estimatePrice(engineType, transmissionType, color, doors, seating, basePrice) << endl;
}

int main() {
    // Seed for random number generation
    srand(time(0));

    // Demonstrate car manufacturing with different specifications
    manufactureCar("Tesla", "Model S");
    manufactureCar("Toyota", "Camry", "Hybrid");
    manufactureCar("Ford", "F-150", "Diesel", "Automatic");
    manufactureCar("BMW", "X5", "Petrol", "Manual", "Black", 5, 5);
    manufactureCar("Mercedes", "E-Class", "Electric", "Automatic", "White", 4, 5);
    cout << "Estimated Price: $" << estimatePrice("Electric", "Automatic", "White", 4, 5, 40000) << endl;
    cout << endl;

    // Generate a random car
    generateRandomCar();
    cout << endl;

    // User input for car customization
    string brand, model, engineType, transmissionType, color;
    int doors, seating, basePrice;
    vector<string> validEngineTypes = {"Petrol", "Diesel", "Electric", "Hybrid"};
    vector<string> validTransmissionTypes = {"Manual", "Automatic"};

    cout << "--- User Input ---" << endl;
    cout << "Enter Car Brand: ";
    cin >> brand;
    cout << "Enter Car Model: ";
    cin >> model;
      // Validate Engine Type
    while (true) {
        cout << "Enter Engine Type (Petrol/Diesel/Electric/Hybrid): ";
        cin >> engineType;
        if (find(validEngineTypes.begin(), validEngineTypes.end(), engineType) != validEngineTypes.end()) {
            break;
        } else {
            cout << "Invalid engine type. Please choose from Petrol, Diesel, Electric, or Hybrid." << endl;
        }
    }

    // Validate Transmission Type
    while (true) {
        cout << "Enter Transmission (Manual/Automatic): ";
        cin >> transmissionType;
        if (find(validTransmissionTypes.begin(), validTransmissionTypes.end(), transmissionType) != validTransmissionTypes.end()) {
            break;
        } else {
            cout << "Invalid transmission type. Please choose from Manual or Automatic." << endl;
        }
    }

    cout << "Enter Color: ";
    cin >> color;

    // Validate Number of Doors
    while (true) {
        cout << "Enter Number of Doors (2-4): ";
        cin >> doors;
        if (doors >= 2 && doors <= 4) {
            break;
        } else {
            cout << "Invalid number of doors. Please enter a value between 2 and 4." << endl;
        }
    }
    cout << "Enter Seating Capacity: ";
    cin >> seating;
    cout << "Enter Base Price: $";
    cin >> basePrice;

    manufactureCar(brand, model, engineType, transmissionType, color, doors, seating);
    cout << "Estimated Price: $" << estimatePrice(engineType, transmissionType, color, doors, seating, basePrice) << endl;

    return 0;
}
