//
//  Mandelbrot.cpp
//  mandelbrotset
//
//  Aidan Jerdee
//
//


#include <iostream>
#include <complex>
#include <thread>
#include <math.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Video.hpp"

void startProgram(long double scale, int curFrame, int numThreads){
    int fps = 30;
    int time = 1800;
    int sizeX = 1920*1.5;
    int sizeY = 1080*1.5;
    
    
    for (; curFrame <= time * fps; curFrame += numThreads){
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
        scale *= pow(0.99,numThreads);
        std::cout << "Scale: " << scale << std::endl;
        std::cout << "Frame: " << curFrame << std::endl << std::endl;
        //std::cout << "test";
    }
}

long double findScale(int n){
    return 3.5 * pow(0.99,n - 1.0);
}

int main()
{
    int iter = 3167;
    std::thread t1(startProgram,findScale(iter),iter,6);
    std::thread t2(startProgram,findScale(iter + 1),iter + 1,6);
    std::thread t3(startProgram,findScale(iter + 2),iter + 2,6);
    std::thread t4(startProgram,findScale(iter + 3),iter + 3,6);
    std::thread t5(startProgram,findScale(iter + 4),iter + 4,6);
    std::thread t6(startProgram,findScale(iter + 5),iter + 5,6);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
}
