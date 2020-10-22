#ifndef __SUGI_ENGINE_H_
#define __SUGI_ENGINE_H_

#include "sugi_window.hpp"

namespace sugi
{
    class Engine
    {
        private:
            sugi::Window m_window;
            // sugi::EventProcessor m_event_proc;
            SDL_Event m_event;
            bool m_quit;
        public:
            Engine();
            ~Engine();
            void init();
            void run();
    };
};

#endif // __SUGI_ENGINE_H_
