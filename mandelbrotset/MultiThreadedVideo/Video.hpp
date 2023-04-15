//
//  VideoRender.hpp
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
    double minX;
    double maxX;
    double minY;
    double maxY;
};

struct Vector2{
    double x;
    double y;
};

class VideoRender{
private:
    double iterations = 4000;
    double scale;
    std::complex<double> num;
    windowSize size;
    Vector2 center;
    sf::Vector2u screenSize;
    sf::Image *window;
    int escapeTime();
    void setWindow();
    void incrementNum();
    void updateSize();
    int loadingDisplay(int,int);
    sf::Color getColor(int);
    
public:
    VideoRender(sf::Image&,const double&);
    void start();
};

#endif /* Mandelbrot_hpp */
