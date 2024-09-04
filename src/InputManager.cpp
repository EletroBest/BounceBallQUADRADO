#include "InputManager.hpp"

InputManager::InputManager()
{
    MouseState = new Uint32;
    PrevMouseState = new Uint32;

    MousePosition = new Vector2;
}

void InputManager::Update()
{
    *MouseState = SDL_GetMouseState(&MousePosition->x,&MousePosition->y);
}

void InputManager::PrevUpdate()
{
    *PrevMouseState = SDL_GetMouseState(NULL,NULL);
}

bool InputManager::IsMouseButtonPressed(MouseButtons button)
{
    return *MouseState && !*PrevMouseState;
}

bool InputManager::IsMouseButtonOut(MouseButtons button)
{
    return !*MouseState && *PrevMouseState;
}

bool InputManager::IsMouseInBounds(SDL_Rect* rect)
{
    if(MousePosition->x < rect->x || MousePosition->x > (rect->x + rect->w)) return false;
    if(MousePosition->y < rect->y || MousePosition->y > (rect->y + rect->h)) return false;

    return true;
}