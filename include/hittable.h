#ifndef HITTABLE_H
#define HITTABLE_H

#include "rtweekend.h"

class material;

// Class representing information about a ray-object intersection
class hit_record {
  public:
    point3 p; // Point of intersection
    vec3 normal; // Surface normal at the point of intersection
    shared_ptr<material> mat;
    double t; // Parameter value along the ray where the intersection occurs
    bool front_face; // Indicates whether the intersection is from the front face

    // Sets the face normal based on the ray direction and outward normal
    void set_face_normal(const ray& r, const vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

// Abstract base class for hittable objects
class hittable {
  public:
    virtual ~hittable() = default; // Virtual destructor for proper polymorphic destruction

    // function to check for ray-object intersection
    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};

#endif