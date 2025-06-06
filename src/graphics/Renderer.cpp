#include "Renderer.h"
#include <SDL.h>
#include <iostream>

Renderer::Renderer() : m_screenWidth(0), m_screenHeight(0), m_initialized(false) {
}

Renderer::~Renderer() {
    Cleanup();
}

bool Renderer::Initialize(int width, int height, const std::string& title) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_Window* window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        return false;
    }

    m_screenWidth = width;
    m_screenHeight = height;
    m_initialized = true;
    return true;
}

void Renderer::Clear() {
    if (!m_initialized) return;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Renderer::Present() {
    if (!m_initialized) return;
    SDL_RenderPresent(renderer);
}

void Renderer::DrawRectangle(float x, float y, float width, float height, int r, int g, int b, int a) {
    if (!m_initialized) return;
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_Rect rect = {
        static_cast<int>(x),
        static_cast<int>(y),
        static_cast<int>(width),
        static_cast<int>(height)
    };
    SDL_RenderFillRect(renderer, &rect);
}

void Renderer::DrawPixel(int x, int y, int r, int g, int b) {
    if (!m_initialized) return;
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderDrawPoint(renderer, x, y);
}

void Renderer::Cleanup() {
    if (m_initialized) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        m_initialized = false;
    }
}