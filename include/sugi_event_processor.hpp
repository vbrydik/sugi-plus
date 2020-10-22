#ifndef __SUGI_EVENT_PROCESSOR_H_
#define __SUGI_EVENT_PROCESSOR_H_

#include <SDL2/SDL.h>

namespace sugi
{
    class EventProcessor
    {
        private:
            SDL_Event *m_event;
            void (*m_poll_event_fn)(SDL_Event*);
        public:
            void poll();
            EventProcessor();
            ~EventProcessor();
    };
};


#endif // __SUGI_EVENT_PROCESSOR_H_
