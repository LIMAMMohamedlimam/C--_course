#include <iostream>
using namespace std;

// Function to rotate array to the right by K positions
void rotateArray(int arr[], int n, int k) {
    // Handle case when k > n
    k = k % n;
    
    if (k == 0) return; // No rotation needed
    
    // Reverse the entire array
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    // Reverse the first k elements
    for (int i = 0, j = k - 1; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    // Reverse the remaining n-k elements
    for (int i = k, j = n - 1; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int n, k;
    
    cout << "Enter the size of the array: ";
    cin >> n;
    
    if (cin.fail() || n <= 0) {
        cout << "Error: Please enter a positive integer for array size." << endl;
        return 1;
    }
    
    int* arr = new int[n];
    
    cout << "Enter " << n << " elements for the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (cin.fail()) {
            cout << "Error: Please enter valid integers." << endl;
            delete[] arr;
            return 1;
        }
    }
    
    cout << "Enter the rotation amount (K): ";
    cin >> k;
    
    if (cin.fail() || k < 0) {
        cout << "Error: Please enter a non-negative integer for rotation." << endl;
        delete[] arr;
        return 1;
    }
    
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    rotateArray(arr, n, k);
    
    cout << "Array after rotating " << k << " positions to the right: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;
    return 0;
}
