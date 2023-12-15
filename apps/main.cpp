#include <iostream>

#include "image_manager.h"

int main() {

    ImageManager imageManager = ImageManager();
    imageManager.saveSquareImage("./assets/images/square.png", 640, 480, "green", "red");
    imageManager.saveDegradeImage("./assets/images/gradiente.png", 640, 480, "blue", "orange");
    imageManager.saveCircleImage("./assets/images/circle.png", 640, 480, "blue", "orange");
    return 0;
}