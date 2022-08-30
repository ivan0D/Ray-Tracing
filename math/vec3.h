#pragma once

#include <cmath>
#include "Matrix.h"


template<typename T>
class vec3 {

public:

    vec3(){}

    vec3(T x, T y, T z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    float norm() const {
        return sqrtf(x * x + y * y + z * z);
    }

    vec3 operator+(const vec3& other) const {
        return vec3(x + other.x, y + other.y, z + other.z);
    }

    vec3 operator-(const vec3& other) const {
        return vec3(x - other.x, y - other.y, z - other.z);
    }

    vec3 operator*(float n) const {
        return vec3(x * n, y * n, z * n);
    }

    float operator*(const vec3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    void normalizes(){
        float length = norm();
        x /= length;
        y /= length;
        z /= length;
    }

    void SetX(T x){
        this->x = x;
    }

    void SetY(T y){
        this->y = y;
    }

    void SetZ(T z){
        this->z = z;
    }

    T GetX() const {
        return this->x;
    }

    T GetY() const {
        return this->y;
    }

    T GetZ() const {
        return this->z;
    }

private:

    T x;
    T y;
    T z;

};

// TODO если что, поменять местами аргументы

template <typename T>
vec3<T> operator*(float n, const vec3<T>& v) {
    return vec3(v.GetX() * n, v.GetY() * n, v.GetZ() * n);
}