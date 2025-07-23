//how to use dynamic memory(Heap)
//nullptr check
//array dynamic allocation

#include <iostream>

int main() {

    int* ptr = new int(10);
    std::cout << *ptr << std::endl;
    delete ptr;
    ptr = nullptr;              //reset the memory to nullptr

    int* ptr2 = nullptr;
    ptr2 = new int(20);
    std::cout << *ptr2 <<std::endl;
    delete ptr2;                //return memory to OS
    ptr2 = nullptr;

     //we can reuse a pointer with a new memory
	 ptr = new int(30);
	 std::cout << *ptr <<std::endl;
	 delete ptr;
	 ptr = nullptr;

     //nullptr check
     if (ptr) {
        std::cout << "ptr points to a valid address: "<< ptr <<std::endl;
     } else {
        std::cout << "ptr points to an INVALID address."<<std::endl;
     }

     size_t size = 10;
     int* p_students = new(std::nothrow) int[size]();   //all values are initialized to 0's
     delete[] p_students;
     p_students = nullptr;

    return 0;
}
