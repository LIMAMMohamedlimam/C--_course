#include <iostream>
#include <string>
using namespace std;

// Function to authenticate user
bool authenticate(const string& validUsername, const string& validPassword) {
    string username, password;
    bool isAuthenticated = false;
    
    do {
        cout << "Enter username: ";
        cin >> username;
        
        cout << "Enter password: ";
        cin >> password;
        
        if (username == validUsername && password == validPassword) {
            isAuthenticated = true;
            cout << "Authentication successful!" << endl;
        } else {
            cout << "Invalid credentials. Please try again." << endl;
        }
        
    } while (!isAuthenticated);
    
    return true;
}

int main() {
    // Set valid credentials (in a real app, these would be stored securely)
    const string validUsername = "admin";
    const string validPassword = "password123";
    
    cout << "Authentication System" << endl;
    cout << "--------------------" << endl;
    
    authenticate(validUsername, validPassword);
    
    cout << "Welcome to the system!" << endl;
    
    return 0;
}
