#pragma once

#include <windows.h>

#include "Screen.h"

class Console : public Screen{


public:

    Console(HANDLE out, Pixel* frame, int width, int height) : Screen(frame, width, height){
        this->out = out;
    }

    void Output(){

    }

private:

    HANDLE out;


};