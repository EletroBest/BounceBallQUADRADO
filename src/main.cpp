#include <iostream>
#include "InputManager.hpp"
#include "RendererWindow.hpp"
#include "Rectangle.hpp"

using namespace std;

void loop()
{
    int Running = true;
    SDL_Event event;

    Rectangle rec(new Vector2{WINDOW_WIDHT/2,WINDOW_HEIGHT/2},new Vector2{50,50});

    while(Running)
    {
        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                Running = false;
                break;
            
            default:
                break;
            }
        }

        InputManager::GetInstance().PrevUpdate();

        RendererWindow::GetInstance().Clear();
        rec.Render();
        RendererWindow::GetInstance().Render();
        RendererWindow::GetInstance().Display();

        if(InputManager::GetInstance().IsMouseButtonPressed(LEFT_BUTTON)) std::cout << "Hello World!";

        InputManager::GetInstance().Update();
    }
}

int main(int argc, char** argv)
{
    
    std::cout << "Hello World!";

    SDL_Init(SDL_INIT_VIDEO);
    RendererWindow::GetInstance();
    loop();
    SDL_Quit();

    return 0;
}