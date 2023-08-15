// Task-2  Simple calculator
#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char operation;

    // Input the two numbers and the operation to perform
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;

    // Perform the selected operation and display the result
    if (operation == '+') {
        cout << "Result: " << num1 + num2 << endl;
    } else if (operation == '-') {
        cout << "Result: " << num1 - num2 << endl;
    } else if (operation == '*') {
        cout << "Result: " << num1 * num2 << endl;
    } else if (operation == '/') {
        if (num2 == 0) {
            cout << "Error: Division by zero is not allowed." << endl;
        } else {
            cout << "Result: " << num1 / num2 << endl;
        }
    } else {
        cout << "Invalid operation. Please enter +, -, *, or /." << endl;
    }

    return 0;
}
