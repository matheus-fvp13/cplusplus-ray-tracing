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
    std::vector<triangle> seahorse = objLoader.readObj("./assets/objects/read/seahorse.obj", point3(-1.0 , 0, -1.0));
    std::vector<triangle> cube = objLoader.readObj("./assets/objects/read/cube.obj", point3(1.0 , 0, -1.0));
    hittable_list world;


    auto R = cos(pi/4);

    for(auto& t: seahorse) {
       world.add(make_shared<triangle>(t));
    }

    for(auto& t: cube) {
       world.add(make_shared<triangle>(t));
    }

    world.add(make_shared<sphere>(point3( 0.0, 0.0, -1.0),   0.5));
    

    camera cam;
    camera cam2;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth         = 50;

    cam.vfov     = 90;
    cam.lookfrom = point3(-2,2,1);
    cam.lookat   = point3(0,0,-1);
    cam.vup      = vec3(0,1,0);

    cam2.aspect_ratio      = 16.0 / 9.0;
    cam2.image_width       = 400;
    cam2.samples_per_pixel = 100;
    cam2.max_depth         = 50;

    cam2.vfov     = 45;
    cam2.lookfrom = point3(2,2,1);
    cam2.lookat   = point3(0,0,-1);
    cam2.vup      = vec3(0,1,0);
    
    Magick::Image image = cam.render(world);
    image.write("./assets/images/activity05-viewpoint1.png");

    Magick::Image image2 = cam2.render(world);
    image2.write("./assets/images/activity05-viewpoints2.png");

    return 0;
}