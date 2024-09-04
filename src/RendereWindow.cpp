#include "RendererWindow.hpp"

RendererWindow::RendererWindow()
{
    window = SDL_CreateWindow(WINDOW_NAME,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDHT,WINDOW_HEIGHT,0);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_PRESENTVSYNC);
}

void RendererWindow::Clear()
{
    SDL_RenderClear(renderer);
}

void RendererWindow::Render()
{
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
}

void RendererWindow::Render(SDL_Rect* rect, SDL_Color* color)
{
    SDL_SetRenderDrawColor(renderer,color->r,color->g,color->b,color->a);
    SDL_RenderFillRect(renderer,rect);
}

void RendererWindow::Display()
{
    SDL_RenderPresent(renderer);
}

RendererWindow::~RendererWindow()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}