module;

#include <iostream>
#include <print>

export module derp;
int hidden()
{
    return 42;
}

export void printHidden()
{
    std::cout << "The hidden " << hidden() << '\n';
    std::println("This is a print test: You have C+23, yay!");
}
