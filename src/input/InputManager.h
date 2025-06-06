#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <windows.h>

class InputManager {
private:
    bool m_keyStates[256];
    bool m_previousKeyStates[256];
    
public:
    InputManager();
    
    void Update();
    bool IsKeyPressed(int keyCode) const;
    bool IsKeyJustPressed(int keyCode) const;
    bool IsKeyReleased(int keyCode) const;
};

#endif