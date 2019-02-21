#pragma once

struct Rect{
    int x;
    int y;
    int w;
    int h;
    Rect(){
        x=y=w=h=0;
    }
    Rect(int x_, int y_, int w_, int h_){
        x =x_;
        y =y_;
        w =w_;
        h =h_;
    }
};

struct Point{
    int x;
    int y;
    Point(){
        x=0;y=0;
    }
    Point(int x_, int y_){
        x = x_;
        y = y_;
    }
};

struct Color{
    short r,g,b,a;
    Color(){
        r=g=b=a=0xff;
    }
    Color(short r, short g, short b, short a){
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }
};

void DrawPoint(const Point& p, const Color& c );
void DrawRect(const Rect &r, const Color &c, bool filled= false);
void DrawLine(const Point& p1, const Point& p2, const Color& color);
void DrawTriangle(const Point& p1, const Point& p2,  const Point& p3,const Color& color);