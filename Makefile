CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Isrc -I"C:/SDL2-2.32.8/include/SDL2"
LDFLAGS = -L"C:/SDL2-2.32.8/lib" -lSDL2main -lSDL2
TARGET = panda_platformer.exe
SOURCES = src/main.cpp src/game/Game.cpp src/game/Player.cpp src/game/Level.cpp src/graphics/Renderer.cpp src/input/InputManager.cpp

# Build the panda platformer game
$(TARGET): $(SOURCES)
	@echo "Building panda platformer..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS)
	@echo "Panda platformer built successfully!"

# Clean up compiled panda game files
clean:
	@echo "Cleaning panda game files..."
	@if exist $(TARGET) del $(TARGET)
	@echo "Clean complete!"

# Run the panda platformer game
run: $(TARGET)
    @echo "Starting panda platformer..."
    .\$(TARGET)

# Debug build with extra panda game debugging info
debug: CXXFLAGS += -g -DDEBUG
debug: $(TARGET)
    @echo "Debug build of panda platformer complete!"

# Release build optimized for panda game performance
release: CXXFLAGS += -O2 -DNDEBUG
release: $(TARGET)
    @echo "Release build of panda platformer complete!"

# Show help for panda platformer build commands
help:
    @echo "Panda Platformer Build Commands:"
    @echo "  mingw32-make         - Build the panda game"
    @echo "  mingw32-make run     - Build and run the panda game"
    @echo "  mingw32-make clean   - Remove compiled panda game files"
    @echo "  mingw32-make debug   - Build debug version with panda game info"
    @echo "  mingw32-make release - Build optimized panda game version"
    @echo "  mingw32-make help    - Show this help message"

.PHONY: clean run debug release help