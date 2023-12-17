#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "ray.h"
#include "vec3.h"

class triangle
{

public:
    vec3 v0, v1, v2;

    triangle(const vec3& v0, const vec3& v1, const vec3& v2): v0(v0), v1(v1), v2(v2) {}

    bool hit(const ray& ray) const {
        vec3 edge1 = v1 - v0;
        vec3 edge2 = v2 - v0;
        vec3 h = cross(ray.direction(), edge2);
        double a = dot(edge1, h);

        if(a > -1e-6 && a < 1e-6) {
            return false;
        }

        double f = 1.0 / a;
        vec3 s = ray.origin() - v0;
        double u = f * dot(s, h);

        if(u < 0.0 || u > 1.0) {
            return false;
        }

        vec3 q = cross(s, edge1);
        double v = f * dot(ray.direction(), q);

        if(v < 0.0 || u + v > 1.0) {
            return false;
        }

        double t = f * dot(edge2, q);
        return t > 1e-6;

    }
    

};



#endif