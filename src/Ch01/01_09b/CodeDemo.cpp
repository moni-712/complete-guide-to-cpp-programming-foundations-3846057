// Complete Guide to C++ Programming Foundations
// Challenge 01_09
// Terminal Interaction, by Monika Phipps

#include <iostream>
#include <string>

int main(){
    std::string name;
    std::cout << "Enter your name: " << std::flush;
    std::cin >> name;
    std::cout << "Nice to meet you, " << name << "!" << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}