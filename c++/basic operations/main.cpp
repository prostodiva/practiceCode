//clang++ main.cpp -o main          - creates executable(binary file)

/*
- basic operations
- steams:
        input/output/cerr/clogs
- store fractional nums
- setprecision
- static_cast
*/

#include <string>                   //alows to use a string class
#include <iostream>                 //the library that allows to print to the console
#include <iomanip>                  //to use precision

int addNums(int param1, int param2) {
    int result = param1 + param2;
    return result;
}

int main() {                        // the entry point of the C++ program(the first thing that will be executed)
    //addition and sub
    int num1 = 11, num2 = 5; 
    int sum = { num1 + num2 };
    int other_sum = num1 + num2 + num1;

    std::cout << "The sum is: " << sum <<std::endl;     //the data("the sum is:") goes to cout, that's why it has <<
    std::cout << "Other sum is: " << other_sum <<std::endl;

    //example with a function
    sum = addNums(25, 7);
    std::cout << "The new sum is: " << sum <<std::endl;
    std::cout << "The new sum is: " << addNums(35,4) <<std::endl;

    //product
    int product = { num1 + num2 };
    int other_product = num1 * num2 * num1;
    std::cout << "The product is: " << product <<std::endl;
    std::cout << "Other product is: " << other_product <<std::endl;

    //division
    int div = { num1 / num2 };
    std::cout << "The div is: " << div <<std::endl;

    //modular(will give a remainder)
    int modular = { num1 % num2 };         
    std::cout << "The modular is: " << modular <<std::endl;

    //examples of streams
    std::cerr << "Something went wrong" << std::endl; //uses output operator <<
    std::clog << "This is a log message" <<std::endl;

    //input
    std::string name;               
    std:: cout << "Enter your name: " <<std::endl;
    std::cin >> name;   //uses extraction operator >>   get data from the user and store in in the variable name
    std::cout << "Nice to meet you, " << name <<std::endl;
    std::cin.ignore();  //clear the buffer for the next input

    //reading data with spaces
    std::string full_name;
    int age;
    std::cout << "Enter your full name and age: ";
    std::getline(std::cin, full_name);
    std::cin >> age;
    std::cout << "Hello "<< full_name << " you are " << age << " years old."<<std::endl;


    //fractional nums
    float a = 1.123456788901f;     
    double b = 1.123456788901;
    long double c = 1.123456788901L;

    std::cout << "size of float: " << sizeof(a) << std::endl;
    std::cout << "size of double: " << sizeof(b) << std::endl;
    std::cout << "size of long double: " << sizeof(c) << std::endl;

    std::cout << std::setprecision(20) << a << std::endl;  // controls the precision from std::cout for float - 7 digits
														   // the rest of it is a garbage
    std::cout << std::setprecision(20) << b << std::endl;  // precision should be around 17 digits
    std::cout << std::setprecision(20) << c << std::endl;  // > double

    //char
    char value = 65;
    std::cout << "Prints ASCII char - A: "<< value <<std::endl;
    std::cout << "value(int): " << static_cast<int>(value) <<std::endl;

    return 0;                       // send a message to OS if the program finished up successfully or it was a problem
}