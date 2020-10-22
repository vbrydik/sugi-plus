#include <iostream>
#include "sugi_engine.hpp"


int main(int argc, char *argv[])
{
    std::cout << "Hello, sugi++" << std::endl;
    sugi::Engine e = sugi::Engine();

    e.init();
    e.run();

    std::cout << "Quit" << std::endl;
    return 0;
}
