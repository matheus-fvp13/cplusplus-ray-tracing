#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

//Class with represents a sphere in a 3D space
class sphere : public hittable {
  public:
    // Constructor to initialize the sphere with a center and radius
    sphere(point3 _center, double _radius) : center(_center), radius(_radius) {}

    // Overrides the base class function to check for ray-sphere intersections
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        vec3 oc = r.origin() - center;
        auto a = r.direction().length_squared();
        auto half_b = dot(oc, r.direction());
        auto c = oc.length_squared() - radius*radius;

        auto discriminant = half_b*half_b - a*c;
        // Check if the ray intersects the sphere
        if (discriminant < 0) return false;
        auto sqrtd = sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        auto root = (-half_b - sqrtd) / a;
        if (!ray_t.surrounds(root)) {
            root = (-half_b + sqrtd) / a;
            if (!ray_t.surrounds(root))
                return false;
        }

        // Record the intersection details
        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);

        return true;
    }

  private:
    point3 center;
    double radius;
};

#endif