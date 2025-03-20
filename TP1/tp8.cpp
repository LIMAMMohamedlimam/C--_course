#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if(n <= 1) return false;
    
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    
    return true;
}

int main() {
    int n;
    
    cout << "Enter the upper limit: ";
    cin >> n;
    
    cout << "Prime numbers up to " << n << " are: ";
    
    for(int i = 2; i <= n; i++) {
        if(isPrime(i)) {
            cout << i << " ";
        }
    }
    
    cout << endl;
    return 0;
}
