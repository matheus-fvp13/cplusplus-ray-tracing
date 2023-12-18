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

    //ObjLoader objLoader;
    //std::vector<triangle> triangles = objLoader.readObj("./assets/objects/read/seahorse.obj", vec3(0, 0, 0));
    hittable_list world;


    auto R = cos(pi/4);

    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0));
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.0),   0.5));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),  -0.4));
    world.add(make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5));
    //for(auto& t: triangles) {
    //    world.add(make_shared<triangle>(t));
    //}

    // Camera

    camera cam;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth         = 50;

    cam.vfov     = 20;
    cam.lookfrom = point3(-2,2,1);
    cam.lookat   = point3(0,0,-1);
    cam.vup      = vec3(0,1,0);
    
    Magick::Image image = cam.render(world);
    image.write("./assets/images/teste.png");

    return 0;
}