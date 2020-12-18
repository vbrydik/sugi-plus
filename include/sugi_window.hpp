#pragma once
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>

namespace sugi{

    class Window
    {
        private:
            void _init_sdl();
            void _init_gl();
            SDL_Window *m_window;
            SDL_GLContext m_context;
        public:
            void init(int, int, std::string);
            SDL_Window * get_window();
            SDL_GLContext * get_context();
            Window();
            ~Window();
    };

};
