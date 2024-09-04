#pragma once

#include <cstdlib>
#include "SDL.hpp"
#include "InputManager.hpp"
#include "RendererWindow.hpp"

class Rectangle
{
    public:
        Rectangle(Vector2* position, Vector2* size,SDL_Color* color = new SDL_Color{255,255,255,255});
        void CreateNewRectangle();

        void Render();

    private:
        SDL_Rect* Rect;
        SDL_Color* Color;
        Vector2* Position;
        Vector2* Size;
};