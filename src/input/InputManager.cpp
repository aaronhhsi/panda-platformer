#include "InputManager.h"
#include <cstring>
#include <windows.h>  // Remove GLFW dependency for now

InputManager::InputManager() {
    memset(m_keyStates, 0, sizeof(m_keyStates));
    memset(m_previousKeyStates, 0, sizeof(m_previousKeyStates));
}

void InputManager::Update() {  // Changed from update() to Update()
    // Store previous frame's key states
    memcpy(m_previousKeyStates, m_keyStates, sizeof(m_keyStates));
    
    // Update current key states using Windows API
    for (int i = 0; i < 256; i++) {
        m_keyStates[i] = (GetAsyncKeyState(i) & 0x8000) != 0;
    }
}

bool InputManager::IsKeyPressed(int key) const {  // Changed from isKeyPressed()
    return m_keyStates[key];
}

bool InputManager::IsKeyJustPressed(int key) const {  // Changed from isKeyJustPressed()
    return m_keyStates[key] && !m_previousKeyStates[key];
}

bool InputManager::IsKeyReleased(int key) const {  // Changed from isKeyReleased()
    return !m_keyStates[key] && m_previousKeyStates[key];
}