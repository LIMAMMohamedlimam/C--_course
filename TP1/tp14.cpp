#include <iostream>
using namespace std;

// Optimized Bubble Sort function
void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        
        // If no swapping occurred in this pass, array is sorted
        if (!swapped) {
            cout << "Early termination after " << i + 1 << " passes" << endl;
            break;
        }
    }
}

int main() {
    int n;
    
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
    
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    bubbleSort(arr, n);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;
    return 0;
}
