#include <iostream>
using namespace std;

int main() {
    int first_term, common_diff, n;
    
    cout << "Enter the first term: ";
    cin >> first_term;
    
    cout << "Enter the common difference: ";
    cin >> common_diff;
    
    cout << "Enter the number of terms: ";
    cin >> n;
    
    cout << "Arithmetic series: ";
    
    int term = first_term;
    for(int i = 0; i < n; i++) {
        cout << term << " ";
        term += common_diff;
    }
    
    cout << endl;
    return 0;
}
