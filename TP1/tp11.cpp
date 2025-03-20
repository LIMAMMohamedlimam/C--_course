#include <iostream>
using namespace std;

int main() {
    int num1, num2, gcd;
    
    cout << "Enter two positive integers: ";
    cin >> num1 >> num2;
    
    // Ensure positive numbers
    num1 = abs(num1);
    num2 = abs(num2);
    
    // Euclidean algorithm for GCD
    int a = num1;
    int b = num2;
    
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    gcd = a;
    
    cout << "GCD of " << num1 << " and " << num2 << " is " << gcd << endl;
    
    return 0;
}
