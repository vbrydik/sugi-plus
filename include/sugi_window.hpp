#ifndef __SUGI_WINDOW_H_
#define __SUGI_WINDOW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/glew.h>

namespace sugi{

    class Window
    {
        private:
            void _init_sdl();
            void _init_gl();
            SDL_Window *m_window;
            SDL_GLContext m_context;
        public:
            void init();
            SDL_Window * get_window();
            SDL_GLContext * get_context();
            Window();
            ~Window();
    };

};

#endif // __SUGI_WINDOW_H_
