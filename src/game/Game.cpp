#include "Game.h"
#include <iostream>
#include <chrono>
#include <thread>

Game::Game() : m_isRunning(false) {
}

Game::~Game() {
    Cleanup();
}

bool Game::Initialize() {
    if (!m_renderer.Initialize(SCREEN_WIDTH, SCREEN_HEIGHT, "Panda Platformer")) {
        std::cerr << "Failed to initialize renderer!" << std::endl;
        return false;
    }

    if (!m_inputManager.Initialize()) {
        std::cerr << "Failed to initialize input manager!" << std::endl;
        return false;
    }

    // Initialize panda player
    m_panda.Initialize(100.0f, 400.0f); // Start position
    
    // Initialize level
    m_currentLevel.LoadLevel1();
    
    m_isRunning = true;
    return true;
}

void Game::Run() {
    const float targetFrameTime = 1.0f / TARGET_FPS;
    float accumulator = 0.0f;
    
    while (m_isRunning) {
        auto frameStart = std::chrono::high_resolution_clock::now();
        
        HandleInput();
        Update(targetFrameTime);
        Render();
        
        auto frameEnd = std::chrono::high_resolution_clock::now();
        float frameTime = std::chrono::duration<float>(frameEnd - frameStart).count();
        
        // Cap the frame rate
        if (frameTime < targetFrameTime) {
            std::this_thread::sleep_for(std::chrono::duration<float>(targetFrameTime - frameTime));
        }
    }
}

void Game::HandleInput() {
    m_inputManager.Update();
    if (m_inputManager.IsKeyPressed(SDLK_ESCAPE)) {
        m_isRunning = false;
    }
    
    // Panda movement controls
    if (m_inputManager.IsKeyPressed('A') || m_inputManager.IsKeyPressed(37)) { // Left arrow
        m_panda.MoveLeft();
    }
    if (m_inputManager.IsKeyPressed('D') || m_inputManager.IsKeyPressed(39)) { // Right arrow
        m_panda.MoveRight();
    }
    if (m_inputManager.IsKeyPressed(' ') || m_inputManager.IsKeyPressed(38)) { // Space or Up arrow
        m_panda.Jump();
    }
}

void Game::Update(float deltaTime) {
    m_panda.Update(deltaTime);
    m_currentLevel.Update(deltaTime);
}

void Game::Render() {
    m_renderer.Clear();
    
    // Draw the level
    m_currentLevel.Render(m_renderer);
    
    // Draw the panda
    m_panda.Render(m_renderer);
    
    m_renderer.Present();
}

void Game::Cleanup() {
    m_renderer.Cleanup();
    m_inputManager.Cleanup();
}