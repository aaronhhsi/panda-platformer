#include "Texture.h"
#include <iostream>

Texture::Texture() : textureID(0), width(0), height(0) {
}

Texture::~Texture() {
    // Cleanup if needed
}

bool Texture::loadFromFile(const std::string& filePath) {
    // For now, just simulate loading
    std::cout << "Loading texture: " << filePath << std::endl;
    width = 32;  // Default size
    height = 32;
    textureID = 1;  // Dummy ID
    return true;
}

void Texture::bind() const {
    // For console renderer, this is a no-op
    std::cout << "Binding texture ID: " << textureID << std::endl;
}

void Texture::free() {
    // No-op for console version
}

int Texture::getWidth() const {
    return width;
}

int Texture::getHeight() const {
    return height;
}