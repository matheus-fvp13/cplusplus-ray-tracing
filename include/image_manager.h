#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include <iostream>

class ImageManager {

public:
    ImageManager();

    void saveSquareImage(const std::string& fileName, int width, int height, const std::string& backgroundColor, const std::string& squareColor);

    void saveDegradeImage(const std::string& fileName, int width, int height, const std::string& color1,  const std::string& color2);

    void saveCircleImage(const std::string& fileName, int width, int height, const std::string& backgroundColor, const std::string& circleColor);

};

#endif //IMAGEMANAGER_H