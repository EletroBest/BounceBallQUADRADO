#pragma once
#include "SDL.hpp"

class RendererWindow
{
    public:

        void Clear();
        void Render();
        void Render(SDL_Rect* rect, SDL_Color* color);
        void Display();


        static RendererWindow& GetInstance(){static RendererWindow window; return window;}

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;

        RendererWindow();
        RendererWindow(RendererWindow&);
        RendererWindow operator=(RendererWindow&);
        ~RendererWindow();
};