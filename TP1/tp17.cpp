#include <iostream>
#include <string>
using namespace std;

// Recursive function to authenticate user
bool authenticateRecursive(const string& validUsername, const string& validPassword) {
    string username, password;
    
    cout << "Enter username: ";
    cin >> username;
    
    cout << "Enter password: ";
    cin >> password;
    
    if (username == validUsername && password == validPassword) {
        cout << "Authentication successful!" << endl;
        return true;
    } else {
        cout << "Invalid credentials. Please try again." << endl;
        return authenticateRecursive(validUsername, validPassword);
    }
}

int main() {
    // Set valid credentials (in a real app, these would be stored securely)
    const string validUsername = "admin";
    const string validPassword = "password123";
    
    cout << "Authentication System (Recursive)" << endl;
    cout << "------------------------------" << endl;
    
    authenticateRecursive(validUsername, validPassword);
    
    cout << "Welcome to the system!" << endl;
    
    return 0;
}
