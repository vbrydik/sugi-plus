#include <string>
#include <iostream>
#include "sugi_engine.hpp"


int main(int argc, char *argv[])
{
    sugi::Engine e = sugi::Engine();
    
    e.init();
    e.run();

    return 0;
}
