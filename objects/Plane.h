#pragma once

#include "Object.h"

class Plane : public Object{

public:

    Plane(vec3<float> normal, float d, Material* material) : Object(material){
        this->normal = normal;
        this->normal.normalizes();
        this->d = d;
    }

    const vec3<float> &getNormal() const {
        return normal;
    }

    void setNormal(const vec3<float> &normal) {
        Plane::normal = normal;
    }

    float getD() const {
        return d;
    }

    void setD(float d) {
        Plane::d = d;
    }

    vec3<float> GetNormal(vec3<float> point){
        return this->normal;
    }

    bool intersect(const vec3<float>& o, const vec3<float>& dir, float& d){

        float tmp = dir * this->normal;
        if(tmp){
            d = (-this->d - this->normal * o) / tmp;
            return true;
        }
        return false;
    }

private:

    vec3<float> normal;
    float d;

};