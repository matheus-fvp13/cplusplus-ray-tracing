#include "face.h"
#include "obj_loader.h"
#include "ray.h"
#include "triangle.h"
#include "vec3.h"

#include <iostream>
#include "Magick++.h"

bool hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    return (discriminant >= 0);
}

Magick::ColorRGB ray_color(const ray& r, triangle& t) {
    if (t.hit(r)) {
        return Magick::ColorRGB(1, 0, 0);
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    vec3 v = (1.0-a)*vec3(1.0, 1.0, 1.0) + a*vec3(0.5, 0.7, 1.0);

    return Magick::ColorRGB(v.x(), v.y(), v.z());
}

Magick::ColorRGB ray_color(const ray& r) {
    if (hit_sphere(point3(0,0,-1), 0.5, r)) {
        return Magick::ColorRGB(1, 0, 0);
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    vec3 v = (1.0-a)*vec3(1.0, 1.0, 1.0) + a*vec3(0.5, 0.7, 1.0);

    return Magick::ColorRGB(v.x(), v.y(), v.z());
}

int main() {
    Magick::InitializeMagick("");
    ObjLoader objLoader = ObjLoader();

    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // Calculate the image height, and ensure that it's at least 1.
    int image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    Magick::Image image(Magick::Geometry(image_width, image_height), "white");
    // Camera

    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);
    auto camera_center = point3(0, 0, 0);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // Calculate the location of the upper left pixel.
    auto viewport_upper_left = camera_center
                             - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    std::vector<triangle> triangles = objLoader.readObj("/home/matheus-fvp/Documentos/git/ray-tracing/assets/objects/read/plane.obj", camera_center);
    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            for(auto triangle : triangles) {
                bool is_hit = triangle.hit(r);
                Magick::ColorRGB pixel_color = ray_color(r, triangle);
                image.pixelColor(i, j, pixel_color);
                if(is_hit) break;
            }
        }
    }

    image.write("./assets/images/plane.png");
    return 0;
}