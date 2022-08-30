#pragma once

#include "../math/vec3.h"

class Material{

public:
    // сколько процентов каждого канала отражает
    Material(float r, float g , float b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }

    float getR() const {
        return r;
    }

    void setR(float r) {
        Material::r = r;
    }

    float getG() const {
        return g;
    }

    void setG(float g) {
        Material::g = g;
    }

    float getB() const {
        return b;
    }

    void setB(float b) {
        Material::b = b;
    }

private:

    float r;
    float g;
    float b;

};