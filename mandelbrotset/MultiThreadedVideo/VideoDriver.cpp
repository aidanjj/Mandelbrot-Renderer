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
#include "Video.hpp"


int main7()
{
  //  double scale = 3.872103E-10;
    double scale = 1.104753E-12;
    //double scale = 1.19219E-40;
    int fps = 30;
    int time = 1800;
    int sizeX = 1920*2;
    int sizeY = 1080*2;
    
    //2865
    for (int curFrame = 4002; curFrame <= time * fps; ++curFrame){
        sf::Image image;
        image.create(sizeX,sizeY, sf::Color(0, 0, 0));
        VideoRender fractal(image,scale);
        fractal.start();
        
        if (image.saveToFile("/Users/aidan/Documents/School/CS2/mandelbrotset/files/video/img" + std::to_string(curFrame) + ".png")){
            //std::cout << "Successful" << std::endl;
            
        }
        else {
            std::cout << "Failed" << std::endl;
        }
        scale *= 0.99;
        std::cout << "Scale: " << scale << std::endl;
        std::cout << "Frame: " << curFrame << std::endl << std::endl;
        //std::cout << "test";
    }
    
    return 0;
}
