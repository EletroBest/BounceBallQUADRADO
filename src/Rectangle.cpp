#include "Rectangle.hpp"

Rectangle::Rectangle(Vector2* position, Vector2* size,SDL_Color* color)
:Position(position),Size(size),Color(color),Rect(nullptr)
{
    CreateNewRectangle();
}

void Rectangle::CreateNewRectangle()
{
    if(Rect) delete Rect;
    delete Position;
    Position = new Vector2{rand()%WINDOW_WIDHT,rand()%WINDOW_HEIGHT};
    Rect = new SDL_Rect{Position->x,Position->y,Size->x,Size->y};
}

void Rectangle::Render()
{
    if(InputManager::GetInstance().IsMouseInBounds(Rect)){
        if(InputManager::GetInstance().IsMouseButtonPressed(LEFT_BUTTON))
            CreateNewRectangle();
    }

    RendererWindow::GetInstance().Render(Rect,Color);
}