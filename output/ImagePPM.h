#pragma once

#include <fstream>
#include <string.h>
#include "Screen.h"

class ImagePPM : public Screen{

public:

    ImagePPM(std::string path, int width, int height) : Screen(width, height){
        this->path = std::move(path);
    }

    void Output(){
        std::ofstream output(this->path);
        output << "P3\n";
        output << std::to_string(width) << ' ' << std::to_string(height) << '\n';
        output << "255\n";
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                output << std::to_string((int)frame[y * width + x].r) << ' '
                       << std::to_string((int)frame[y * width + x].g) << ' '
                       << std::to_string((int)frame[y * width + x].b) << '\n';
            }
        }
        output.close();
    }

private:

    std::string path;

};