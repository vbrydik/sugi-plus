#include "sugi_event_processor.hpp"


sugi::EventProcessor::EventProcessor() {}
sugi::EventProcessor::~EventProcessor() {}

void sugi::EventProcessor::set_poll_event_fn(void (*f)(SDL_Event*))
{
    m_poll_event_fn = f;
}

void sugi::EventProcessor::poll()
{
    while (SDL_PollEvent(m_event))
    {
        m_poll_event_fn(m_event);
    }
}
