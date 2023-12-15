#include <Magick++.h>
#include <iostream>

#include "image_manager.h"

using namespace Magick;
using namespace std;

ImageManager::ImageManager() {
    InitializeMagick("");
}

void ImageManager::saveSquareImage(const string& fileName, int width, int height, const string& backgroundColor, const string& squareColor) {
    try {

        //define the degrade with the color1 and color2
        Image squareImage(Geometry(width, height), Color(backgroundColor));

        //object that is used to create a square
        DrawableRectangle rectangle = DrawableRectangle(40, 40, width - 40, height - 40);

        squareImage.fillColor(squareColor);
        squareImage.draw(rectangle);
        std::cout << "OI" << std::endl;

        squareImage.write(fileName);

    }catch(Exception& ex) {
        cerr << "Error to save the square image: " << ex.what() << endl;
    }
} 

void ImageManager::saveDegradeImage(const string& fileName, int width, int height, const string& color1,  const string& color2) {
    try {

        //define the degrade with the color1 and color2
        string degradeColor = "gradient:" + color1 + "-" + color2;

        //Create a image with the degrade 
        Image degradeImage(Geometry(width, height), "white");
        degradeImage.read(degradeColor);

        // Save the image in the file
        degradeImage.write(fileName);
    }
    catch (Exception& ex) {
        cerr << "Error to save the degrade image: " << ex.what() << endl;
    }
}

void ImageManager::saveCircleImage(const string& fileName, int width, int height, const string& backgroundColor, const string& circleColor) {
    try {
        // Create a blank image 
        Image circleImage(Geometry(width, height), backgroundColor);

        // Draw a circle in the image
        circleImage.fillColor(circleColor);
        circleImage.draw(DrawableCircle(width / 2, height / 2, width / 2 + 20 , 100));

        // Save the image in the file
        circleImage.write(fileName);
    }
    catch (Magick::Exception& ex) {
        std::cerr << "Error to save the circle image: " << ex.what() << std::endl;
    }

}
