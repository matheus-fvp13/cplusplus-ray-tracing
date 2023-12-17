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



/*Magick::ColorRGB ray_color(const ray& r, triangle& t) {
    if (t.hit(r)) {
        return Magick::ColorRGB(1, 0, 0);
    }

    return background_color(r);
}*/


int main() {

    // World

    hittable_list world;

    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    // Camera

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 400;

    cam.render(world);

    return 0;
}