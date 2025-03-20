#include <iostream>
using namespace std;

int main() {
    int base, exponent;
    long long result = 1;
    
    cout << "Enter the base number: ";
    cin >> base;
    
    cout << "Enter the exponent: ";
    cin >> exponent;
    
    // Handle negative exponents
    if(exponent < 0) {
        cout << "This program does not support negative exponents." << endl;
        return 0;
    }
    
    for(int i = 0; i < exponent; i++) {
        result *= base;
    }
    
    cout << base << " raised to the power " << exponent << " = " << result << endl;
    
    return 0;
}
