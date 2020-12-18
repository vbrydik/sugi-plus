#include "sugi_engine.hpp"
#include "sugi_config.hpp"
#include "config.hpp"


sugi::Engine::Engine() {}
sugi::Engine::~Engine() {}


void sugi::Engine::init()
{
    // read config
    auto config = read_config(CONF_PATH);
    int window_width = std::stoi(config["WINDOW.width"]);
    int window_height = std::stoi(config["WINDOW.height"]);
    std::string window_name = config["WINDOW.name"];

    this->m_quit = false;
    this->m_window = sugi::Window();
    this->m_window.init(window_width, window_height, window_name);
}


void sugi::Engine::run()
{
    while (!this->m_quit)
    {
        this->poll(&this->m_event);
        // this->update_input();
        // this->update_game();
        // this->update_windows();
    }
}


void sugi::Engine::poll(SDL_Event *e)
{
    SDL_PollEvent(&this->m_event);
    switch (this->m_event.type)
    {
        case SDL_QUIT:
            this->m_quit = true;
            break;
    }
}
