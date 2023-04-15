//
//  Mandelbrot.cpp
//  mandelbrotset
//
//  Aidan Jerdee
//
//


#include <iostream>
#include <complex>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Mandelbrot.hpp"


int main2()
{
    int sizeX = 1920*1;
    int sizeY = 1080*1;
    sf::Image image;
    
    
    
    image.create(sizeX,sizeY, sf::Color(0, 0, 0));
    Mandelbrot fractal(image);
    fractal.start();
    if (image.saveToFile("/Users/aidan/Documents/School/CS2/mandelbrotset/files/fractal.png")){
        std::cout << "Successful" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
    return 0;
}
