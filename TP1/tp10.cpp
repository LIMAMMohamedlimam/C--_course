#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    
    unsigned long long fact = 1;
    for(int i = 2; i <= n; i++) {
        fact *= i;
    }
    
    return fact;
}

int main() {
    int n;
    
    cout << "Enter the upper limit: ";
    cin >> n;
    
    cout << "Factorials up to " << n << ":" << endl;
    
    for(int i = 0; i <= n; i++) {
        cout << i << "! = " << factorial(i) << endl;
    }
    
    return 0;
}
