# Panda Platformer Game

## Overview
Panda Platformer is a 2D platformer game themed around pandas. Players will navigate through various levels, overcoming obstacles and collecting items while enjoying a vibrant panda-themed environment.

## Features
- Engaging gameplay with smooth controls.
- Beautifully designed panda-themed sprites and environments.
- Multiple levels with increasing difficulty.
- Sound effects and background music to enhance the gaming experience.

## Project Structure
```
panda-platformer
├── src
│   ├── main.cpp          # Entry point of the game
│   ├── game              # Game logic and mechanics
│   │   ├── Game.cpp      # Implementation of the Game class
│   │   ├── Game.h        # Declaration of the Game class
│   │   ├── Player.cpp     # Implementation of the Player class
│   │   ├── Player.h      # Declaration of the Player class
│   │   ├── Level.cpp     # Implementation of the Level class
│   │   └── Level.h       # Declaration of the Level class
│   ├── graphics          # Rendering and graphics management
│   │   ├── Renderer.cpp   # Implementation of the Renderer class
│   │   ├── Renderer.h     # Declaration of the Renderer class
│   │   ├── Texture.cpp    # Implementation of the Texture class
│   │   └── Texture.h      # Declaration of the Texture class
│   ├── input             # Input handling
│   │   ├── InputManager.cpp # Implementation of the InputManager class
│   │   └── InputManager.h   # Declaration of the InputManager class
│   └── utils             # Utility classes and constants
│       ├── Vector2.h      # 2D vector operations
│       └── Constants.h     # Game constants
├── assets
│   ├── sprites           # Sprite images for characters and environments
│   └── sounds            # Sound files for music and effects
├── CMakeLists.txt       # Build configuration for CMake
└── README.md             # Project documentation
```

## Setup Instructions
1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Use CMake to configure and generate the build files:
   ```
   mkdir build
   cd build
   cmake ..
   ```
4. Build the project:
   ```
   cmake --build .
   ```
5. Run the game executable.

## Gameplay
- Control the panda character using keyboard inputs.
- Jump over obstacles and collect items to score points.
- Explore different levels filled with challenges and surprises.

## Contributing
Contributions are welcome! Please feel free to submit a pull request or open an issue for any suggestions or improvements.