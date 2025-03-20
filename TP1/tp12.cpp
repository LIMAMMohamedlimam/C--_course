#include <iostream>
#include <cmath>
using namespace std;

// TP1: Function to get odd numbers in a range
void getOddNumbers(int limit, int result[], int &size) {
    size = 0;
    for(int i = 1; i <= limit; i += 2) {
        result[size++] = i;
    }
}

// TP2: Function to get even numbers in a range
void getEvenNumbers(int limit, int result[], int &size) {
    size = 0;
    for(int i = 2; i <= limit; i += 2) {
        result[size++] = i;
    }
}

// TP3: Function to generate arithmetic series
void generateArithmeticSeries(int first, int diff, int terms, int result[], int &size) {
    size = terms;
    int term = first;
    for(int i = 0; i < terms; i++) {
        result[i] = term;
        term += diff;
    }
}

// TP4: Function to check if a number is odd or even
bool isEven(int num) {
    return num % 2 == 0;
}

// TP5: Function to generate Fibonacci series
void generateFibonacci(int terms, int result[], int &size) {
    if (terms <= 0) {
        size = 0;
        return;
    }
    
    size = terms;
    if (terms >= 1) result[0] = 0;
    if (terms >= 2) result[1] = 1;
    
    for(int i = 2; i < terms; i++) {
        result[i] = result[i-1] + result[i-2];
    }
}

// TP6: Function to calculate factorial
unsigned long long calculateFactorial(int n) {
    if(n < 0) return 0; // Error indicator
    
    unsigned long long factorial = 1;
    for(int i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

// TP7: Function to check if a number is prime
bool isPrime(int n) {
    if(n <= 1) return false;
    
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    
    return true;
}

// TP8: Function to get all prime numbers in a range
void getPrimeNumbers(int limit, int result[], int &size) {
    size = 0;
    for(int i = 2; i <= limit; i++) {
        if(isPrime(i)) {
            result[size++] = i;
        }
    }
}

// TP9: Function to calculate power
long long calculatePower(int base, int exponent) {
    if(exponent < 0) return -1; // Error indicator
    
    long long result = 1;
    for(int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// TP10: Function to get factorials of numbers in a range
void getFactorials(int limit, unsigned long long result[], int &size) {
    size = limit + 1;
    for(int i = 0; i <= limit; i++) {
        result[i] = calculateFactorial(i);
    }
}

// TP11: Function to calculate GCD
int calculateGCD(int a, int b) {
    a = abs(a);
    b = abs(b);
    
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

int main() {
    int choice;
    
    cout << "Choose a function (1-11):" << endl;
    cout << "1. Program that prints odd numbers up to a given range." << endl;
    cout << "2. Program that prints even numbers up to a given range." << endl;
    cout << "3. Program that prints an arithmetic series based on a given common difference and range." << endl;
    cout << "4. Program to check whether a given input is an odd or even number." << endl;
    cout << "5. Program to generate the Fibonacci Series up to the nth term." << endl;
    cout << "6. Program that calculates the factorial of a given positive integer. The program also checks whether the given input is a positive integer. Do not forget that 0! = 1." << endl;
    cout << "7. Program to check if a given number is prime or not." << endl;
    cout << "8. Program to print only prime numbers up to a given range." << endl;
    cout << "9. Program that inputs the base and power from the user and computes the result using a for loop." << endl;
    cout << "10. Program that prints the factorial of each number up to a given range." << endl;
    cout << "11. Find the GCD (Greatest Common Divisor) of two given numbers." << endl;
    
    cout << "Choose a function (1-11): ";
    cin >> choice;
    
    if(cin.fail() || choice < 1 || choice > 11) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid choice. Please enter a number between 1 and 11." << endl;
        return 1;
    }
    
    switch(choice) {
        case 1: {
            int limit;
            cout << "Enter the upper limit for odd numbers: ";
            cin >> limit;
            
            if(cin.fail() || limit < 0) {
                cout << "Error: Please enter a non-negative integer." << endl;
                return 1;
            }
            
            int result[1000];
            int size;
            getOddNumbers(limit, result, size);
            
            cout << "Odd numbers up to " << limit << " are: ";
            for(int i = 0; i < size; i++) {
                cout << result[i] << " ";
            }
            cout << endl;
            break;
        }
        case 2: {
            int limit;
            cout << "Enter the upper limit for even numbers: ";
            cin >> limit;
            
            if(cin.fail() || limit < 0) {
                cout << "Error: Please enter a non-negative integer." << endl;
                return 1;
            }
            
            int result[1000];
            int size;
            getEvenNumbers(limit, result, size);
            
            cout << "Even numbers up to " << limit << " are: ";
            for(int i = 0; i < size; i++) {
                cout << result[i] << " ";
            }
            cout << endl;
            break;
        }
        case 3: {
            int first, diff, terms;
            cout << "Enter the first term: ";
            cin >> first;
            cout << "Enter the common difference: ";
            cin >> diff;
            cout << "Enter the number of terms: ";
            cin >> terms;
            
            if(cin.fail() || terms < 0) {
                cout << "Error: Please enter valid numbers with a non-negative term count." << endl;
                return 1;
            }
            
            int result[1000];
            int size;
            generateArithmeticSeries(first, diff, terms, result, size);
            
            cout << "Arithmetic series: ";
            for(int i = 0; i < size; i++) {
                cout << result[i] << " ";
            }
            cout << endl;
            break;
        }
        case 4: {
            int num;
            cout << "Enter a number: ";
            cin >> num;
            
            if(cin.fail()) {
                cout << "Error: Please enter a valid integer." << endl;
                return 1;
            }
            
            if(isEven(num)) {
                cout << num << " is an even number." << endl;
            } else {
                cout << num << " is an odd number." << endl;
            }
            break;
        }
        case 5: {
            int terms;
            cout << "Enter the number of terms: ";
            cin >> terms;
            
            if(cin.fail() || terms < 0) {
                cout << "Error: Please enter a non-negative integer." << endl;
                return 1;
            }
            
            int result[1000];
            int size;
            generateFibonacci(terms, result, size);
            
            cout << "Fibonacci Series up to " << terms << " terms: ";
            for(int i = 0; i < size; i++) {
                cout << result[i] << " ";
            }
            cout << endl;
            break;
        }
        case 6: {
            int n;
            cout << "Enter a positive integer: ";
            cin >> n;
            
            if(cin.fail()) {
                cout << "Error: Please enter a valid integer." << endl;
                return 1;
            }
            
            if(n < 0) {
                cout << "Error: Factorial is not defined for negative numbers." << endl;
                return 1;
            }
            
            unsigned long long factorial = calculateFactorial(n);
            cout << "Factorial of " << n << " = " << factorial << endl;
            break;
        }
        case 7: {
            int n;
            cout << "Enter a positive integer: ";
            cin >> n;
            
            if(cin.fail()) {
                cout << "Error: Please enter a valid integer." << endl;
                return 1;
            }
            
            if(isPrime(n)) {
                cout << n << " is a prime number." << endl;
            } else {
                cout << n << " is not a prime number." << endl;
            }
            break;
        }
        case 8: {
            int limit;
            cout << "Enter the upper limit: ";
            cin >> limit;
            
            if(cin.fail() || limit < 0) {
                cout << "Error: Please enter a non-negative integer." << endl;
                return 1;
            }
            
            int result[1000];
            int size;
            getPrimeNumbers(limit, result, size);
            
            cout << "Prime numbers up to " << limit << " are: ";
            for(int i = 0; i < size; i++) {
                cout << result[i] << " ";
            }
            cout << endl;
            break;
        }
        case 9: {
            int base, exponent;
            cout << "Enter the base number: ";
            cin >> base;
            cout << "Enter the exponent: ";
            cin >> exponent;
            
            if(cin.fail()) {
                cout << "Error: Please enter valid integers." << endl;
                return 1;
            }
            
            if(exponent < 0) {
                cout << "Error: This program does not support negative exponents." << endl;
                return 1;
            }
            
            long long result = calculatePower(base, exponent);
            cout << base << " raised to the power " << exponent << " = " << result << endl;
            break;
        }
        case 10: {
            int limit;
            cout << "Enter the upper limit: ";
            cin >> limit;
            
            if(cin.fail() || limit < 0) {
                cout << "Error: Please enter a non-negative integer." << endl;
                return 1;
            }
            
            unsigned long long result[100];
            int size;
            getFactorials(limit, result, size);
            
            cout << "Factorials up to " << limit << ":" << endl;
            for(int i = 0; i < size; i++) {
                cout << i << "! = " << result[i] << endl;
            }
            break;
        }
        case 11: {
            int num1, num2;
            cout << "Enter two positive integers: ";
            cin >> num1 >> num2;
            
            if(cin.fail()) {
                cout << "Error: Please enter valid integers." << endl;
                return 1;
            }
            
            int gcd = calculateGCD(num1, num2);
            cout << "GCD of " << num1 << " and " << num2 << " is " << gcd << endl;
            break;
        }
    }
    
    return 0;
}
