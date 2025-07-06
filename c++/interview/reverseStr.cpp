/*
INTERVIEW PRACTICE PROGRAM #1: String Reversal with Edge Cases
Time Limit: 60 minutes
Difficulty: Easy (15-20 min)

TASK: Write a function that reverses a string, handling various edge cases.

Requirements:
1. Reverse a string completely
2. Handle empty strings
3. Handle single characters
4. Handle special characters
5. Handle Unicode characters
6. Handle spaces and punctuation
7. Bonus: Do it in-place without extra memory

Example:
Input: "Hello, World! 123"
Output: "321 !dlroW ,olleH"

Input: ""
Output: ""

Input: "A"
Output: "A"

Input: "你好世界"
Output: "界世好你"

Test your function with various inputs and edge cases.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//pass by value. creates a copy, returns a new string.
//two pointers approach - O(n) time, no extra memory
//check if the str is empty
//create two vars to track the values from the start and from the end
//while left < right, traverse and swap values in the array(str - array of chars)
//increment and decrement
//return str
string reverseString(string str) {
    if (str.empty()) return str;
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
      swap(str[left], str[right]);
      left++;
      right--;
    }
    return str;
}

// pass by reference. no extra memory. returns nothing
void reverseStringInPlace(string& str) {
   if (str.empty()) return;
   int left = 0;
   int right = str.length() - 1;
   while (left < right) {
     swap(str[left], str[right]);
     left++;
     right--;
   }
}

// Test function
void testReverseString() {
    cout << "=== String Reversal Tests ===" << endl;

    // Test cases
    string testCases[] = {
        "Hello, World! 123",
        "",
        "A",
        "你好世界",
        "racecar",
        "   spaces   ",
        "!@#$%^&*()",
        "1234567890",
        "a",
        "AB"
    };

    for (string test : testCases) {
        cout << "Input: \"" << test << "\"" << endl;
        cout << "Output: \"" << reverseString(test) << "\"" << endl;
        cout << "---" << endl;
    }

    // Test in-place reversal
    cout << "\n=== In-Place Reversal Tests ===" << endl;
    for (string test : testCases) {
        string copy = test;
        reverseStringInPlace(copy);
        cout << "Input: \"" << test << "\"" << endl;
        cout << "Output: \"" << copy << "\"" << endl;
        cout << "---" << endl;
    }
}

int main() {
    cout << "String Reversal Practice Program" << endl;
    cout << "Time yourself: 60 minutes maximum!" << endl;
    cout << "=====================================" << endl;

    // Run your tests here
    testReverseString();

    return 0;
}