#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

class Texture {
public:
    Texture();
    ~Texture();

    bool loadFromFile(const std::string& filePath);
    void bind() const;
    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:
    unsigned int textureID;  // Changed from GLuint
    int width;
    int height;
};

#endif // TEXTURE_H