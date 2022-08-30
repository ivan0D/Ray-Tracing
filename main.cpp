
#include <iostream>
#include <vector>
#include <math.h>

#include "objects/Object.h"
#include "objects/Sphere.h"
#include "objects/Camera.h"
#include "output/Screen.h"
#include "output/ImagePPM.h"
#include "math/algorithms.h"
#include "objects/Plane.h"
#include "math/Matrix.h"


const int width = 3840;
const int height = 2160;


bool intersect(const vec3<float>& O, const vec3<float>& dir, const std::vector<Object*> objects, float& distance_, int& index){
    float distance = std::numeric_limits<float>::max();
    float min_distance = std::numeric_limits<float>::max();

    int min_item_index = 0;

    bool is_intersect = false;

    for (int i = 0; i < objects.size(); ++i) {
        if(objects[i]->intersect(O, dir, distance)){
            if(min_distance > distance){
                min_distance = distance;
                min_item_index = i;
                is_intersect = true;
            }
        }
    }

    distance_ = min_distance;
    index = min_item_index;

    return is_intersect;
}

vec3<float> cast_ray(vec3<float> initial_light, const vec3<float>& O, const vec3<float>& dir, const std::vector<Object*> objects, int depth){

    float distance;
    int index;


    if (!intersect(O, dir, objects, distance, index) || !depth) {
        return initial_light;
    }

        Material *material = objects[index]->getMaterial();

        vec3<float> light(initial_light.GetX() * material->getR(),
                          initial_light.GetY() * material->getG(),
                          initial_light.GetZ() * material->getB());

        vec3<float> point_on_obj = dir * distance + O;
        vec3<float> normal = objects[index]->GetNormal(point_on_obj);
        vec3<float> reflected = reflect(dir, normal);

        point_on_obj = point_on_obj + (1e-3 * normal);

        return cast_ray(light, point_on_obj, reflected, objects, depth - 1);

}

void render(Camera camera, const std::vector<Object*>& objects){

    Screen* screen = new ImagePPM("out.ppm", width, height);

    for (int i = 0; i < camera.getHeight(); ++i) {
        for (int j = 0; j < camera.getWidth(); ++j) {
            vec3 O = camera.getPosition();
            vec3 dir = camera.GetDir(j, i);
            dir.normalizes();
            vec3<float> color = cast_ray(vec3<float>(1, 1, 1), O, dir, objects, 256);

            screen->Draw(j, i, Pixel{(int)(color.GetX() / (1/255.)), (int)(color.GetY() / (1/255.)), (int)(color.GetZ() / (1/255.))});

        }
    }

    screen->Output();


}

int main() {

    Camera camera(vec3<float>(-50, 0, 0), vec3<float>(1, 0, 0), vec3<float>(0, 1, 0), vec3<float>(0, 0, 1), M_PI / 3.f, width, height);
    std::vector<Object*> objects;
    objects.push_back(new Sphere(vec3<float>(0, 0, 0), 10, new Material(0.9686, 0.6286, 0.9098)));
    objects.push_back(new Sphere(vec3<float>(0, 21, 18), 10, new Material(0.6118, 0.9804, 0.8039)));
    objects.push_back(new Sphere(vec3<float>(-10, -21, 18), 10, new Material(0.9765, 1, 0.5098)));
    //objects.push_back(new Plane(vec3<float>(0, 1, 0), -50, new Material(0.5, 0.1, 0.8)));

    render(camera, objects);

    return 0;
}
