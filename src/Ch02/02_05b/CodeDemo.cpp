// Complete Guide to C++ Programming Foundations
// Exercise 02_05
// Using Variables, by Monika Phipps

#include <iostream>

int a, b = 5; // Global variables since they are defined outside the main function.

int main(){
    bool my_flag; // Local variable since it's defined within a function
    a = 7;
    my_flag = false;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "flag = " << my_flag << std::endl;

    my_flag = true;
    std::cout << "flag = " << my_flag << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "b - a = " << b - a << std::endl;

    unsigned int positive;
    positive = b - a;
    std::cout << "b - a (unsigned) = " << positive << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}
