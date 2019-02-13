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
