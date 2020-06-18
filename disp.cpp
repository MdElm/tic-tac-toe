#include "disp.h"
#include <iostream>
#include <fstream>

void disp::MainMenu()
{
    std::cout << "\n";
    std::cout << "\t1) Play\n";
    std::cout << "\t2) About\n";
    std::cout << "\t3) Quit\n";
    std::cout << "\n";
}

void disp::Title(std::string t)
{
    std::cout << "\n\n";
    std::cout << "    " << t;
    std::cout << "\n\n";
}

void disp::PlayMenu()
{
    std::cout << "\n\n";
    std::cout << "    Take a symbol:\n\n";
    std::cout << "\t1) X\n";
    std::cout << "\t2) O\n";
    std::cout << "\n";
}
