#pragma once
#include "sugi_window.hpp"

namespace sugi
{
    class Engine
    {
        private:
            bool m_quit;
            SDL_Event m_event;
            sugi::Window m_window;
        public:
            Engine();
            ~Engine();
            void init();
            void run();
            void poll(SDL_Event *e);
    };
};
