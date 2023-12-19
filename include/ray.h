#ifndef RAY_H
#define RAY_H

#include "vec3.h"

// Class representing a ray in 3D space
class ray {
  public:
    ray() {}

    ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

    point3 origin() const  { return orig; }
    vec3 direction() const { return dir; }

    // Calculates the point along the ray at a given parameter value 't'
    point3 at(double t) const {
        return orig + t*dir;
    }

  private:
    point3 orig; // Origin point of the ray
    vec3 dir; // Direction of the ray
};

#endif