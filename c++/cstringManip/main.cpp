//strlen, sizeof
//std::string - don't need to care about null char

#include <iostream>
#include <cstring>
#include <string>

int main() {
    const char message1[] = {"The sky is blue."};
    const char* message2 = {"The sky is blue."};    //just a pointer

    //strlenn ignores null character
    std::cout << "strlen(message1)" << std::strlen(message1) << std::endl;

    //size of includes null char
    std::cout << "sizeof(message1)" << sizeof(message1) << std::endl;

    //strlen still works with decayed arrays
    std::cout << "strlen(message2)" << std::strlen(message2) << std::endl;

    //prints size of pointer
    std::cout << "sizeof(message2)" << sizeof(message2) << std::endl;

    //std::string 
    std::string my_str = "Hi Rita!";
    std::cout << my_str <<std::endl;

    return 0;
}