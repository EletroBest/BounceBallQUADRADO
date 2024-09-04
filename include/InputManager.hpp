#pragma once

#include "SDL.hpp"

enum MouseButtons
{
    LEFT_BUTTON = 1,
    MIDDLE_BUTTON = 2,
    RIGHT_BUTTON = 4
};

class InputManager
{
    public:

        void Update();
        void PrevUpdate();


        bool IsMouseButtonPressed(MouseButtons button);
        bool IsMouseButtonOut(MouseButtons button);

        bool IsMouseInBounds(SDL_Rect* rect);

        static InputManager& GetInstance(){static InputManager instance; return instance;};

    private:

        Uint32* MouseState;
        Uint32* PrevMouseState;

        Vector2* MousePosition;

        InputManager();
        InputManager(InputManager&);
        InputManager operator=(InputManager&);
};