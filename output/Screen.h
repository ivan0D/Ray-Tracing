#pragma once

struct Pixel{
    int r;
    int g;
    int b;
};

class Screen{

public:

    Screen(int width, int height){
        this->width = width;
        this->height = height;
        this->frame = new Pixel[width * height];
    }

    void Draw(int x, int y, Pixel pixel){
        int index = y * width + x;
        frame[index] = pixel;
    }

    virtual void Output() = 0;

protected:

    Pixel* frame;
    int width;
    int height;

};