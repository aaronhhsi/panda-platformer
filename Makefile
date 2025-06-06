CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Isrc -I"C:/SDL2-2.32.8/include"
LDFLAGS = -L"C:/SDL2-2.32.8/lib" -lmingw32 -lSDL2main -lSDL2 -mwindows -lgdi32 -lwinmm -lshell32 -lole32 -loleaut32 -luuid -lversion -lsetupapi
TARGET = panda_platformer.exe
SOURCES = src/main.cpp

# Build the panda platformer executable
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET) $(LDFLAGS)

# Clean up compiled files
clean:
	@echo "Cleaning build files..."
	@if exist $(TARGET) del $(TARGET)
	@echo "Clean complete!"

# Run the application
run: $(TARGET)
	@echo "Starting application..."
	.\$(TARGET)

.PHONY: clean run