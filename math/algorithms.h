#pragma once


#include "vec3.h"

vec3<float> reflect(vec3<float> dir, vec3<float> normal){
    return dir - 2 * (normal * dir) * normal;
}