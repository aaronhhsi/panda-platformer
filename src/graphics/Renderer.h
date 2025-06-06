#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include <SDL.h>

class Renderer {
private:
    int m_screenWidth;
    int m_screenHeight;
    bool m_initialized;
    SDL_Window* window;
    SDL_Renderer* renderer;
    
public:
    Renderer();
    ~Renderer();
    
    bool Initialize(int width, int height, const std::string& title);
    void Clear();
    void Present();
    void Cleanup();
    
    // Basic drawing functions for our simple panda platformer
    void DrawRectangle(float x, float y, float width, float height, 
                      int r, int g, int b, int a = 255);
    void DrawPixel(int x, int y, int r, int g, int b);
    
    int GetScreenWidth() const { return m_screenWidth; }
    int GetScreenHeight() const { return m_screenHeight; }
};

#endif