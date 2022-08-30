#pragma once

#include <cmath>

#include "../math/vec3.h"

class Camera{

public:

    Camera(vec3<float> position, vec3<float> x, vec3<float> y, vec3<float> z, float fov, int width, int height){
        this->position = position;
        this->x = x;
        this->y = y;
        this->z = z;
        this->fov = fov;
        this->width = width;
        this->height = height;
    }

    const vec3<float> &getPosition() const {
        return position;
    }

    void setPosition(const vec3<float> &position) {
        Camera::position = position;
    }

    const vec3<float> &getX() const {
        return x;
    }

    void setX(const vec3<float> &x) {
        Camera::x = x;
    }

    const vec3<float> &getY() const {
        return y;
    }

    void setY(const vec3<float> &y) {
        Camera::y = y;
    }

    const vec3<float> &getZ() const {
        return z;
    }

    void setZ(const vec3<float> &z) {
        Camera::z = z;
    }

    float getFov() const {
        return fov;
    }

    void setFov(float fov) {
        Camera::fov = fov;
    }

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

    vec3<float> GetDir(int x, int y){
        vec3 directional = this->x * (this->width / (2.f * tanf(this->fov / 2.f))) +
                            this->y * (this->width / 2.f) + this->z * (this->height / 2.f);

        return directional - x * this->y - y * this->z;

    }

private:

    vec3<float> position;
    vec3<float> x;
    vec3<float> y;
    vec3<float> z;
    float fov;
    int width;
    int height;


};