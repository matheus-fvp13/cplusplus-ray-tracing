#include "rtweekend.h"

#include "camera.h"
#include "color.h"
#include "hittable_list.h"
#include "material.h"
#include "obj_loader.h"
#include "sphere.h"
#include "triangle.h"

#include <iostream>
#include "Magick++.h"

int main() {

   ObjLoader objLoader;
   //std::vector<triangle> seahorse = objLoader.readObj("./assets/objects/read/seahorse.obj", point3(0 , 0, -1.0));
   //std::vector<triangle> cube = objLoader.readObj("./assets/objects/read/cube.obj", point3(0 , 0, -1.0));
   hittable_list world;

   auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
   auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
   auto material_left   = make_shared<dielectric>(1.5);
   auto material_right  = make_shared<metal>(color(0.8, 0.6, 0.2), 0.0);

   world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
   world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.0),   0.5, material_center));
   world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_left));
   world.add(make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5, material_right));

   /*for(auto& t: seahorse) {
      t.mat = material_left;
      world.add(make_shared<triangle>(t));
   }*/

   /*for(auto& t: cube) {
      t.mat = material_left;
      world.add(make_shared<triangle>(t));
   }*/

   //world.add(make_shared<sphere>(point3( 0.0, 0.0, -1.0),   0.5));
    

    camera cam;
    camera cam2;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth         = 50;

    cam.vfov     = 90;
    cam.lookfrom = point3(0,0,0);//point3(-2,2,1);
    cam.lookat   = point3(0,0,-1);
    cam.vup      = vec3(0,1,0);

    /*cam2.aspect_ratio      = 16.0 / 9.0;
    cam2.image_width       = 400;
    cam2.samples_per_pixel = 100;
    cam2.max_depth         = 50;

    cam2.vfov     = 45;
    cam2.lookfrom = point3(2,2,1);
    cam2.lookat   = point3(0,0,-1);
    cam2.vup      = vec3(0,1,0);*/
    
    Magick::Image image = cam.render(world);
    image.write("./assets/images/glass-sphere2.png");

    /*Magick::Image image2 = cam2.render(world);
    image2.write("./assets/images/activity05-viewpoints2.png");*/
    return 0;
}