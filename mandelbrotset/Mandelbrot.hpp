//
//  Mandelbrot.hpp
//  mandelbrotset
//
//  Aidan Jerdee
//
//

#ifndef Mandelbrot_hpp
#define Mandelbrot_hpp
#include <stdio.h>
#include <complex>
#include <SFML/Graphics.hpp>
struct windowSize{
        double distance = .0000000001;
    double centerY = -0.641313061064803;
        double minY = centerY - distance/2;
        double maxY = centerY + distance/2;
        double centerX = 0.360240443437614;
        double minX = centerX - ((maxY - minY)*16/9)/2;
        double maxX = centerX + ((maxY - minY)*16/9)/2;
    
    
    //SPIRAL
   /* double distance = .0001;
       double centerY = -.208305;
       double minY = centerY - distance/2;
       double maxY = centerY + distance/2;
       double centerX = -.73746;
       double minX = centerX - ((maxY - minY)*16/9)/2;
       double maxX = centerX + ((maxY - minY)*16/9)/2;*/
    
 /*   double distance = .0001;
    double centerY = -.637685;
    double minY = centerY - distance/2;
    double maxY = centerY + distance/2;
    double centerX = .361653;
    double minX = centerX - ((maxY - minY)*16/9)/2;
    double maxX = centerX + ((maxY - minY)*16/9)/2;*/
    
     //full mandelbrot
/*     double minY = -1.2;
    double maxY = 1.2;
    double minX = -2.1333;
    double maxX = 2.1333;*/
    
    //Minibrot
 /*   double distance = .01;
    double centerY = -.645;
    double minY = centerY - distance/2;
    double maxY = centerY + distance/2;
    double centerX = .36;
    double minX = centerX - ((maxY - minY)*16/9)/2;
    double maxX = centerX + ((maxY - minY)*16/9)/2;*/
 
    
   /* double minX = -.9112;
    double maxX = -.7335;
    double minY = -.25;
    double maxY = -.15;*/
};

struct Vector2{
    double x;
    double y;
};

class Mandelbrot{
private:
    const double iterations = 2000;

    double scale;
    std::complex<double> num;
    windowSize size;
    Vector2 center;
    sf::Vector2u screenSize;
    sf::Image *window;
    int converges();
    void setWindow();
    void incrementNum();
    int loadingDisplay(int,int);
    sf::Color getColor(int);
public:
    Mandelbrot(sf::Image&);
    void start();
};

#endif /* Mandelbrot_hpp */
