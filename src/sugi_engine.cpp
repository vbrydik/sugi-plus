#include "sugi_engine.hpp"

sugi::Engine::Engine() {}
sugi::Engine::~Engine() {}


void (SDL_Event *e)
{
    switch (e->type)
    {
        case SDL_QUIT:

            break;
    }
}


void sugi::Engine::init()
{
    m_quit = false;

    m_window = sugi::Window();
    m_window.init();

    m_event_processor.set_poll_event_fn(my_poll_fn, this);
}

void sugi::Engine::run()
{
    while (!this->m_quit)
    {
        // TODO: Move this while loop in the separate event processor
        /*
        while (SDL_PollEvent(&this->m_event))
        {
            switch (this->m_event.type)
            {
                case SDL_QUIT:
                    this->m_quit = true;
                    break;
                default:
                    break;
            }
        }
        */
        m_event_processor.poll();
    }
}
