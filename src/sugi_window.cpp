#include <iostream>
#include "sugi_window.hpp"


sugi::Window::Window(){}
sugi::Window::~Window(){}

void sugi::Window::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL initialisation failed! " << SDL_GetError() << std::endl;
        return;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    m_window = SDL_CreateWindow(
        "sugi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
    );
    m_context = SDL_GL_CreateContext(m_window);
    SDL_GL_SetSwapInterval(1);

    if (glewInit() != GLEW_OK)
    {
        std::cout << "GLEW init failed!" << std::endl;
        return;
    }

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    SDL_SetWindowSize(m_window, 640, 480);

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    SDL_GL_SwapWindow(m_window);
    SDL_ShowCursor(0); // TODO: make it a separate function in engine utils
}

SDL_Window * sugi::Window::get_window()
{
    return m_window;
}

SDL_GLContext * sugi::Window::get_context()
{
    return &m_context;
}
