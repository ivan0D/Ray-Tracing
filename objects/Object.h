#pragma once

#include "../materials/Material.h"
#include "../math/vec3.h"

class Object{

public:

    Object(Material* material){
        this->material = material;
    }

    Material *getMaterial() const {
        return material;
    }

    virtual bool intersect(const vec3<float>& o, const vec3<float>& dir, float& d) = 0;

    virtual vec3<float> GetNormal(vec3<float> point) = 0;

    virtual vec3<float> GetCenter() = 0;

protected:

    Material* material;

};