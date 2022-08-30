#pragma once


#include "../objects/Object.h"

class Sphere: public Object {

public:

    Sphere(vec3<float> position, float radius, Material* material): Object(material){
        this->position = std::move(position);
        this->radius = radius;
    }

    /// Проверяем, есть ли пересечение луча со сферой
    /// Предолагается, что dir нормализован
    bool intersect(const vec3<float>& o, const vec3<float>& dir, float& d) { // начало луча, его направление, и если пересечение есть, то оно сохранится в d
        vec3 L = position - o;
        float tmp = L * dir;
        float D_ = L * L - tmp * tmp;
        if(D_ > radius * radius) return false;
        float D = sqrtf(radius * radius - D_);
        d = tmp - D;
        if(d < 0) d = tmp + D;
        if(d < 0) return false;
        return true;
    }

    vec3<float> GetNormal(vec3<float> point){
        vec3 normal = point - this->position;
        normal.normalizes();
        return normal;
    }

    float getRadius() const {
        return radius;
    }

    void setRadius(float radius) {
        Sphere::radius = radius;
    }

    const vec3<float> &getPosition() const {
        return position;
    }

    void setPosition(const vec3<float> &position) {
        Sphere::position = position;
    }


private:

    vec3<float> position;
    float radius;

};