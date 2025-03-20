#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "Enter the upper limit: ";
    cin >> n;
    
    cout << "Odd numbers up to " << n << " are: ";
    
    for(int i = 1; i <= n; i += 2) {
        cout << i << " ";
    }
    
    cout << endl;
    return 0;
}
