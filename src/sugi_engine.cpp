#include "sugi_engine.hpp"

sugi::Engine::Engine() {}
sugi::Engine::~Engine() {}

void sugi::Engine::init()
{
    this->m_quit = false;
    this->m_window = sugi::Window();
    this->m_window.init();
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
