#include <iostream>
using namespace std;

int main() {
    int n, first = 0, second = 1, next;
    
    cout << "Enter the number of terms: ";
    cin >> n;
    
    cout << "Fibonacci Series up to " << n << " terms: ";
    
    for(int i = 0; i < n; i++) {
        cout << first << " ";
        next = first + second;
        first = second;
        second = next;
    }
    
    cout << endl;
    return 0;
}
