//declare
//initialize
//use an original variable
//all the changes will be affected to variables
//comparing pointers vs refs:
//      - Reference is an alias (no separate memory). points to the same memory of the original value
//      - reference can't be nullptr
//      - Reference cannot be reassigned
//      - refs must be initialized at declaration
//      - refs don't usr dereferencing for reading/writing
//      - References are generally safer and cleaner, but pointers give you more control and flexibility
  
#include <iostream>
 
int main() {

    int value = 45;
    int& ref = value;   //assign through initialization
    std::cout << value <<std::endl;
    std::cout << ref <<std::endl;

    std::cout << &ref <<std::endl;
    std::cout << &value <<std::endl;
    std::cout << std::endl;

    //comparing pointers and references:
    //declare pointer and ref:
    double val = 12.3;
    double& ref_val = val;
    double* p_val = &val;

    //reading:
    std::cout << "val: " << val << std::endl;
    std::cout << "ref_val: " << ref_val << std::endl;
    std::cout << "p_val: " << p_val << std::endl;       
    std::cout << "*p_val: " << *p_val << std::endl;

    std::cout << std::endl;
    //writing through pointer:
    *p_val = 15.44;
    std::cout << "val: " << val << std::endl;
    std::cout << "ref_val: " << ref_val << std::endl;
    std::cout << "p_val: " << p_val << std::endl;
    std::cout << "*p_val: " << *p_val << std::endl;

    std::cout << std::endl;
    //writing through reference:
    ref_val = 18.55;
    std::cout << "val: " << val << std::endl;
    std::cout << "ref_val: " << ref_val << std::endl;
    std::cout << "p_val: " << p_val << std::endl;
    std::cout << "*p_val: " << *p_val << std::endl;

    std::cout << std::endl;

    //the dereference example(DONT DO THAT. the address in the memory is the same)
    double other_val = 78.3;
    ref_val = other_val;
    std::cout << "val: " << val << std::endl;
    std::cout << "ref_val: " << ref_val << std::endl;
    std::cout << "p_val: " << p_val << std::endl;
    std::cout << "*p_val: " << *p_val << std::endl;

    std::cout << std::endl;
    //dereference with a pointer (p_val now contains a new address) 
    p_val = &other_val;
    std::cout << "val: " << val << std::endl;
    std::cout << "ref_val: " << ref_val << std::endl;
    std::cout << "&val: "<< &val << std::endl;
    std::cout << "&ref_val: "<< &ref_val << std::endl;
    std::cout << "p_val: " << p_val << std::endl;
    std::cout << "*p_val: " << *p_val << std::endl;

    std::cout << std::endl;
    //two pointers now live in diff memory locations
    *p_val = 55.55;
    std::cout << "val: " << val << std::endl;
    std::cout << "ref_val: " << ref_val << std::endl;
    std::cout << "&val: "<< &val << std::endl;
    std::cout << "&ref_val: "<< &ref_val << std::endl;
    std::cout << "p_val: " << p_val << std::endl;
    std::cout << "*p_val: " << *p_val << std::endl;


    return 0;
}