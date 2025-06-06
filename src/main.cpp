#include <iostream>
#include <chrono>
#include <thread>
#include "game/Game.h"

int main() {
    Game pandaGame;
    
    if (!pandaGame.Initialize()) {
        std::cerr << "Failed to initialize Panda Platformer!" << std::endl;
        return -1;
    }
    
    std::cout << "Starting Panda Platformer..." << std::endl;
    pandaGame.Run();
    
    return 0;
}