/*pointers
- declaration
- initialization
- dereferencing
- initialize with string literal: c-string
- modify the string
*/


#include <iostream> 

int main() {
    //declare(not to declare pointers on the same line) and initialize(always do that)
    int* p_integer = nullptr;
    double* p_fractional = nullptr;     

    //the same size 
    std::cout << "size of int*: " << sizeof(int*) <<std::endl;
    std::cout << "size of double*: " << sizeof(double*) <<std::endl;

    //the same thing:
    //int* p_integer = nullptr;
    //int * p_integer = nullptr;
    //int *p_integer = nullptr;

    //initialize a pointer
    int var = 43;
    int* p_int = &var;      //poiner p contains the address in memory of var
    //can't cross assign between pointers of diff. types
    
    //this is valid dereferencing:
    int* ptr1 = nullptr;
    int data = 56;
    ptr1 = &data;
    std::cout << data <<std::endl;

    //don't dereference(change the address) of nullptr 
    //SEG FAULT: this is not valid:
    //int* ptr2 = nullptr;
    //*ptr2 = 42;

    //c-string(the string literal will be converted to array of chars):
    const char* p_message = "Hello c-string";    //use const to avoid compile error
    std::cout << *p_message <<std::endl;    //print only first char 'H'
    std::cout <<  p_message <<std::endl;    //print the whole string
    //if you want to modify a string inside - use array
    char message[] = "Hello world";
    message[0] = 'B';
    std::cout << message <<std::endl;

    return 0;
}