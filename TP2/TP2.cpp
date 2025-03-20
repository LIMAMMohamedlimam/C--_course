#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

// Function to assign a player by name and position
void assignPosition(const string& playerName, const string& position) {
    cout << playerName << " is playing as " << position << "." << endl;
}

// Function to assign a player by jersey number and position
void assignPosition(int jerseyNumber, const string& position) {
    cout << "Player #" << jerseyNumber << " is playing as " << position << "." << endl;
}

// Function to assign a player by name, jersey number, and position
void assignPosition(const string& playerName, int jerseyNumber, const string& position) {
    cout << playerName << " (Jersey #" << jerseyNumber << ") is playing as " << position << "." << endl;
}

// Function to assign a player with a specific team side
void assignPosition(const string& playerName, int jerseyNumber, const string& position, const string& side) {
    cout << playerName << " (Jersey #" << jerseyNumber << ") is playing as " << position << " on the " << side << " side." << endl;
}

// Function to assign a captain
void assignCaptain(const string& playerName, int jerseyNumber, const string& position) {
    cout << playerName << " (Jersey #" << jerseyNumber << ") is playing as " << position << " (Captain)." << endl;
}

// Function to assign a substitute
void assignSubstitute(const string& playerName, int jerseyNumber, const string& position) {
    cout << playerName << " (Jersey #" << jerseyNumber << ") is playing as " << position << " (Substitute)." << endl;
}

// Function to get a random position
string getRandomPosition() {
    vector<string> positions = {"Attacker", "Midfielder", "Defender", "Goalkeeper", "Winger", "Striker", "Sweeper"};
    int randomIndex = rand() % positions.size();
    return positions[randomIndex];
}

// Function to assign random positions to players
void assignRandomPositions(map<string, int>& players) {
    cout << "Random Player Assignments:" << endl;
    for (auto const& [playerName, jerseyNumber] : players) {
        assignPosition(playerName, jerseyNumber, getRandomPosition());
    }
}

// Function to display team formation
void displayTeamFormation(int defenders, int midfielders, int attackers) {
    cout << "Team is playing in a " << defenders << "-" << midfielders << "-" << attackers << " formation." << endl;
}

int main() {
    // Seed for random number generation
    srand(time(0));

    // Demonstrate overloaded functions
    cout << "--- Player Assignments ---" << endl;
    assignPosition("Ronaldo", "Attacker");
    assignPosition(10, "Midfielder");
    assignPosition("Messi", 30, "Midfielder");
    assignPosition("Van Dijk", 4, "Defender", "left");
    assignPosition("Alisson", 1, "Goalkeeper");
    assignCaptain("Kane", 9, "Striker");
    assignSubstitute("Hazard", 7, "Winger");
    cout << endl;

    // Display team formation
    displayTeamFormation(4, 4, 2);
    cout << endl;

    // Demonstrate random player assignments
    map<string, int> randomPlayers = {
        {"De Bruyne", 17},
        {"Mbappe", 7},
        {"Salah", 11}
    };
    assignRandomPositions(randomPlayers);
    cout << endl;

    // Demonstrate user input for player assignment
    string playerName, position;
    int jerseyNumber;

    cout << "--- User Input ---" << endl;
    cout << "Enter player name: ";
    cin >> playerName;
    cout << "Enter player number: ";
    cin >> jerseyNumber;
    cout << "Enter position: ";
    cin >> position;

    assignPosition(playerName, jerseyNumber, position);
    cout << endl;

    return 0;
}
