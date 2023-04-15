//
//  Mandelbrot.cpp
//  mandelbrotset
//
//  Aidan Jerdee
//  
//

#include "Mandelbrot.hpp"
#include <iostream>
#include <math.h>
#include <vector>

//rainbow
sf::Color Mandelbrot::getColor(int n){
    double x = n;
    const double stretchFactorBlue = 3.1415 / 50;
    const double stretchFactorRed = 3.1415 / 50;
    const double stretchFactorGreen = 3.1415 / 50;
    
    
    double blue = 50 * cos(stretchFactorBlue * x) + 205;
    double red = 50 * cos(stretchFactorRed * (x-33)) + 205;
    double green = 50 * cos(stretchFactorGreen * (x-66)) + 205;
  
    blue = std::min(std::max(blue,0.0),255.0);
    red = std::min(std::max(red,0.0),255.0);
    green = std::min(std::max(green,0.0),255.0);
    
    return sf::Color(red,green,blue);
}



//Black and white coloring
/*sf::Color Mandelbrot::getColor(int num){
    int value = 255*(1-(num/iterations)) - 1;
    int colorValue = std::max(0,value);
    return sf::Color(colorValue,colorValue,colorValue);
}*/


//Discrete coloring
/*sf::Color Mandelbrot::getColor(int num){
    int i = (num) % 16;
       sf::Color mapping[16];
       mapping[0]=sf::Color(66, 30, 15);
       mapping[1]=sf::Color(25, 7, 26);
       mapping[2]=sf::Color(9, 1, 47);
       mapping[3]=sf::Color(4, 4, 73);
       mapping[4]=sf::Color(0, 7, 100);
       mapping[5]=sf::Color(12, 44, 138);
       mapping[6]=sf::Color(24, 82, 177);
       mapping[7]=sf::Color(57, 125, 209);
       mapping[8]=sf::Color(134, 181, 229);
       mapping[9]=sf::Color(211, 236, 248);
       mapping[10]=sf::Color(241, 233, 191);
       mapping[11]=sf::Color(248, 201, 95);
       mapping[12]=sf::Color(255, 170, 0);
       mapping[13]=sf::Color(204, 128, 0);
       mapping[14]=sf::Color(153, 87, 0);
       mapping[15]=sf::Color(106, 52, 3);
       return mapping[i];
}*/

int Mandelbrot::converges(){
    std::complex<double> iter = {0,0};
    for (int i = 0; i < iterations; i++){
        iter = pow(iter,2) + num;
        if (std::abs(iter) > 2){
            return i;
        }
    }
    return -1;
}

int Mandelbrot::loadingDisplay(const int counter,const int prevLoadStatus){
    double loading = double(counter) / (screenSize.x * screenSize.y);
    if (int(loading * 100) % 5 == 0){
        if (prevLoadStatus != (int(loading * 100))){
            std::cout << int(loading * 100) << "%" << std::endl;
            return int(loading * 100);
        }
    }
    return prevLoadStatus;
}

void Mandelbrot::incrementNum(){
    sf::Color color;
    int iterationCount;
    
    int counter = 0;
    int prevLoadStatus = 0;
    int loadStatus = 0;
    
    
    for (double i = size.minX; i < size.maxX; i += 1/scale){
        for (double j = size.minY; j < size.maxY; j += 1/scale){
            counter++;
            
            
            loadStatus = loadingDisplay(counter,prevLoadStatus);
            prevLoadStatus = loadStatus;
            
            num = {i,j};
            iterationCount = converges();
            if (iterationCount >= 0){
                if (((i-center.x)*scale + screenSize.x/2 < screenSize.x)&&((i-center.x)*scale + screenSize.x/2 > 0)&&((j-center.y)*scale + screenSize.y/2 > 0)&&((j-center.y)*scale + screenSize.y/2 < screenSize.y)){
                        color = getColor(iterationCount);
                        window->setPixel((i-center.x)*scale + screenSize.x/2,(j-center.y)*scale + screenSize.y/2,color);
                }
            }
        }
    }
}

void Mandelbrot::setWindow(){
    screenSize = window->getSize();
   // scale = 2880;
    scale = screenSize.y / (size.maxY - size.minY);
    center.x = (size.maxX + size.minX)/2;
    center.y = (size.maxY + size.minY)/2;
}

Mandelbrot::Mandelbrot(sf::Image &inputWindow){
    window = &inputWindow;
};

void Mandelbrot::start(){
    setWindow();
    incrementNum();
}
