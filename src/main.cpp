#include <iostream>
#include <string>
#include "sugi_engine.hpp"
#include "sugi_config.hpp"


int main(int argc, char *argv[])
{
    std::cout << "Hello, sugi++" << std::endl;
    sugi::Engine e = sugi::Engine();

    auto config = read_config("test.conf");
    int window_width = std::stoi(config["WINDOW.width"]);
    int window_height = std::stoi(config["WINDOW.height"]);
    std::string window_name = config["WINDOW.name"];

    std::cout << "Window: " << window_width << "x" << window_height << std::endl;
    std::cout << "Name: " << window_name << std::endl;

    e.init();
    e.run();


    std::cout << "Quit" << std::endl;
    return 0;
}
