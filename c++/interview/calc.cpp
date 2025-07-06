/*
INTERVIEW PRACTICE PROGRAM #2: Simple Calculator
Time Limit: 60 minutes
Difficulty: Easy (15-20 min)

TASK: Create a simple calculator that can perform basic arithmetic operations.

Requirements:
1. Support addition, subtraction, multiplication, and division
2. Handle division by zero
3. Support decimal numbers
4. Input validation
5. Clear user interface
6. Error handling

Example:
Input: A (for addition), 5.5, 3.2
Output: 5.5 + 3.2 = 8.7

Input: D (for division), 10, 0
Output: Error: Division by zero
*/

/*
* pseudocode:
* start with runcalculator:
*             - create required variables(num1,num2, operation)
*             - ask user to input
*             - wrap the next section in try, catch block
*             - validate user's input with isValidOperation.
*             - call calculate function
*             - output the result with proper formating
* complete calculate function(switch statement)
 * */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to check if operation is valid
bool isValidOperation(char op) {
    return op == 'A' || op == 'S' || op == 'M' || op == 'D';
}

// Function to perform calculation
double calculate(double a, double b, char operation) {
    switch (operation) {
        case 'A': return a + b;
        case 'S': return a - b;
        case 'M': return a * b;
        case 'D': 
            if (b == 0) {
                throw runtime_error("Division by zero");
            }
            return a / b;
        default: 
            throw runtime_error("Invalid operation");
    }
}

// Function to run the calculator
void runCalculator() {
    cout << "Simple Calculator Practice Program" << endl;
    cout << "Time yourself: 60 minutes maximum!" << endl;
    cout << "===================================" << endl;
    
    char operation;
    double num1, num2;
    
    cout << "Choose an operation to perform: " << endl;
    cout << "A - addition, S - subtraction, D - division, M - multiplication" << endl;
    cout << "Enter two numbers to perform the operation." << endl;
    
    cin >> operation;
    cin >> num1 >> num2;
    
    try {
        if (!isValidOperation(operation)) {
            cout << "Error: Invalid operation" << endl;
            return;
        }
        
        double result = calculate(num1, num2, operation);
        
        cout << fixed << setprecision(2);
        cout << num1 << " ";
        
        switch (operation) {
            case 'A': cout << "+"; break;
            case 'S': cout << "-"; break;
            case 'M': cout << "*"; break;
            case 'D': cout << "/"; break;
        }
        
        cout << " " << num2 << " = " << result << endl;
        
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Test function
void testCalculator() {
    cout << "=== Calculator Tests ===" << endl;
    
    struct TestCase {
        string name;
        double a, b;
        char op;
        string expected;
    };
    
    TestCase tests[] = {
        {"Addition", 5, 3, 'A', "8.00"},
        {"Subtraction", 10, 4, 'S', "6.00"},
        {"Multiplication", 6, 7, 'M', "42.00"},
        {"Division", 15, 3, 'D', "5.00"},
        {"Decimal multiplication", 3.5, 2.5, 'M', "8.75"},
        {"Division by zero", 10, 0, 'D', "Error (Division by zero)"},
        {"Zero divided by number", 0, 5, 'D', "0.00"},
        {"Negative numbers", -5, 3, 'A', "-2.00"},
        {"Large number with decimal", 1234.56, 789.01, 'A', "2023.57"}
    };
    
    for (const TestCase& test : tests) {
        cout << "Test: " << test.name << endl;
        cout << "Input: " << test.a << " " << test.op << " " << test.b << endl;
        cout << "Expected: " << test.expected << endl;
        
        try {
            double result = calculate(test.a, test.b, test.op);
            cout << "Output: " << fixed << setprecision(2) << result << endl;
        } catch (const runtime_error& e) {
            cout << "Output: Error (" << e.what() << ")" << endl;
        }
        cout << "---" << endl;
    }
}

int main() {
    // Uncomment the line below to run the interactive calculator
     runCalculator();
    
    // Run tests
    // testCalculator();
    
    return 0;
} 