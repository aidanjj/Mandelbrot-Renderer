//
//  VideoRender.cpp
//  mandelbrotset
//
//  Aidan Jerdee
//
//

#include "Video.hpp"
#include <iostream>
#include <math.h>
#include <vector>

//rainbow
sf::Color VideoRender::getColor(int n){
    double x = n;
    const double stretchFactorBlue = 3.1415 / 50;
    const double stretchFactorRed = 3.1415 / 50;
    const double stretchFactorGreen = 3.1415 / 50;
    
    
    double blue = 50 * cos(stretchFactorBlue * x) + 205;
    double red = 50 * cos(stretchFactorRed * (x-33)) + 205;
    double green = 50 * cos(stretchFactorGreen * (x-66)) + 205;
 
    /*blue = std::min(std::max(blue,0.0),255.0);
    red = std::min(std::max(red,0.0),255.0);
    green = std::min(std::max(green,0.0),255.0);*/
    
    return sf::Color(red,green,blue);
}



int VideoRender::escapeTime(){
    std::complex<double> iter = {0,0};
    for (int i = 0; i < iterations; i++){
        iter = pow(iter,2) + num;
        if (std::abs(iter) > 2){
            return i;
        }
    }
    return -1;
}

int VideoRender::loadingDisplay(const int counter,const int prevLoadStatus){
    double loading = double(counter) / (screenSize.x * screenSize.y);
    if (int(loading * 100) % 5 == 0){
        if (prevLoadStatus != (int(loading * 100))){
            std::cout << int(loading * 100) << "%" << std::endl;
            return int(loading * 100);
        }
    }
    return prevLoadStatus;
}

void VideoRender::incrementNum(){
    sf::Color color;
    sf::Color black = sf::Color(0,0,0);
    int iterationCount;
    
    double real;
    double imag;
    
    int counter = 0;
    int prevLoadStatus = 0;
    int loadStatus = 0;
    
    
    for (int i = 0; i < screenSize.x; i += 1){
        int row = i;
        for (int j = 0; j < screenSize.y; j += 1){
           /* if (j % 2 == 0){
                row = i + 1;
            }*/
            
            counter++;
            loadStatus = loadingDisplay(counter,prevLoadStatus);
            prevLoadStatus = loadStatus;
            
            real = (row - screenSize.x/2.0)/scale + center.x;
            imag = (j - screenSize.y/2.0)/scale + center.y;
            num = {real,imag};
            iterationCount = escapeTime();
            if (iterationCount >= 0){
                color = getColor(iterationCount);
                window->setPixel(row,j,color);
            }
        }
    }
 /*  for (int i = 1; i < screenSize.x; i += 2){
        int row = i;
        for (int j = 0; j < screenSize.y; j += 1){
            if (j % 2 == 0){
                row = i - 1;
            }
            counter++;
            loadStatus = loadingDisplay(counter,prevLoadStatus);
            prevLoadStatus = loadStatus;
            
            
            if (!((window->getPixel(row + 1,j+1)==black)&&(window->getPixel(i - 1,j-1)==black)&&(window->getPixel(row-1,j+1)==black)&&(window->getPixel(row+1,j-1)==black))){
                real = (row - screenSize.x/2.0)/scale + center.x;
                imag = (j - screenSize.y/2.0)/scale + center.y;
                num = {real,imag};
                iterationCount = escapeTime();
                if (iterationCount >= 0){
                    color = getColor(iterationCount);
                    window->setPixel(row,j,color);
                }
            }
        }
    }*/
}

void VideoRender::setWindow(){
    screenSize = window->getSize();
    scale = screenSize.y / (size.maxY - size.minY);
    center.x = (size.maxX + size.minX)/2;
    center.y = (size.maxY + size.minY)/2;
}

VideoRender::VideoRender(sf::Image &inputWindow,const double& distance){
    window = &inputWindow;
    
    double centerY = -0.6413130610648031748603750151793020665794949522823052595561775430644485741727536902556370230689681162370740565537072149790106973211105273;
         size.minY = centerY - distance/2;
         size.maxY = centerY + distance/2;
         double centerX = 0.3602404434376143632361252444495453084826078079585857504883758147401953460592181003117529367227734263962337317297249877373200353726832853;
         size.minX = centerX - ((size.maxY - size.minY)*16/9)/2;
         size.maxX = centerX + ((size.maxY - size.minY)*16/9)/2;
         //iterations = -1900*(distance-1.08)+11;
};

void VideoRender::start(){
        setWindow();
        incrementNum();
    
    
}
