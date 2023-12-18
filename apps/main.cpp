#include "rtweekend.h"

#include "camera.h"
#include "face.h"
#include "hittable.h"
#include "hittable_list.h"
#include "obj_loader.h"
#include "ray.h"
#include "sphere.h"
#include "triangle.h"
#include "vec3.h"

#include <iostream>
#include "Magick++.h"

int main() {

    ObjLoader objLoader;
    std::vector<triangle> triangles = objLoader.readObj("./assets/objects/read/seahorse.obj", vec3(0, 0, 0));

    // World

    hittable_list world;
    for(auto& t: triangles) {
        world.add(make_shared<triangle>(t));
    }

    // Camera

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth         = 50;

    Magick::Image image = cam.render(world);
    image.write("./assets/images/seahorse-diffuse.png");

    return 0;
}