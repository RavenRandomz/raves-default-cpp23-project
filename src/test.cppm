module;

#include <iostream>


export module derp;
int hidden()
{
    return 42;
}

export void printHidden()
{
    std::cout << "The hidden " << hidden() << '\n';
}
