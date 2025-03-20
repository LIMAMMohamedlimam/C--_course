#include <iostream>
using namespace std;

// Function to remove duplicates from sorted array
int removeDuplicates(int arr[], int n) {
    if (n <= 1) return n;
    
    int newLength = 1; // Start with the first element
    
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[newLength - 1]) {
            arr[newLength] = arr[i];
            newLength++;
        }
    }
    
    return newLength;
}

int main() {
    int n;
    
    cout << "Enter the size of the sorted array: ";
    cin >> n;
    
    if (cin.fail() || n <= 0) {
        cout << "Error: Please enter a positive integer for array size." << endl;
        return 1;
    }
    
    int* arr = new int[n];
    
    cout << "Enter " << n << " elements for the sorted array (in non-decreasing order):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (cin.fail()) {
            cout << "Error: Please enter valid integers." << endl;
            delete[] arr;
            return 1;
        }
        
        // Check if array is sorted
        if (i > 0 && arr[i] < arr[i-1]) {
            cout << "Error: Array must be sorted in non-decreasing order." << endl;
            delete[] arr;
            return 1;
        }
    }
    
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int newLength = removeDuplicates(arr, n);
    
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "New length of the array: " << newLength << endl;
    
    delete[] arr;
    return 0;
}
