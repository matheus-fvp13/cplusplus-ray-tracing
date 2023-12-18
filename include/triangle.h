#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "ray.h"
#include "vec3.h"

//Class with represents a triangle in #D space
class triangle : public hittable
{

public:
    vec3 v0, v1, v2; // Triangle vertices
    vec3 n0, n1, n2; // Normals at each vertex

    triangle(const vec3& v0, const vec3& v1, const vec3& v2): v0(v0), v1(v1), v2(v2) {}

    // Override hit function to check for ray-triangle intersection
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        // Compute edges and necessary vectors
        vec3 edge1 = v1 - v0;
        vec3 edge2 = v2 - v0;
        vec3 h = cross(r.direction(), edge2);
        double a = dot(edge1, h);

        // Check if the ray is parallel or nearly parallel to the triangle
        if(a > -1e-6 && a < 1e-6) {
            return false;
        }

        double f = 1.0 / a;
        vec3 s = r.origin() - v0;
        double u = f * dot(s, h);

        // Check if the intersection point is outside the triangle
        if(u < 0.0 || u > 1.0) {
            return false;
        }

        vec3 q = cross(s, edge1);
        double v = f * dot(r.direction(), q);

        // Check if the intersection point is outside the triangle
        if(v < 0.0 || u + v > 1.0) {
            return false;
        }

        // Calculate the intersection point
        double t = f * dot(edge2, q);
        if(ray_t.contains(t) && t > 1e-6) {
            rec.t = t;
            rec.p = r.at(t);
            // Calculate barycentric coordinates
            vec3 barycentric = toBarycentricCoordinates(rec.p);
            // Interpolate the normal using barycentric coordinates
            vec3 interpolated_normal = unit_vector(barycentric[0] * n0 + barycentric[1] * n1 + barycentric[2] * n2);
            // Set face normal based on the interpolated normal
            rec.set_face_normal(r, interpolated_normal);
            return true;
        }
        return false;

    }

    // Function to calculate barycentric coordinates for a given point within the triangle
    vec3 toBarycentricCoordinates(const point3& point) const {
        vec3 edge1 = v1 - v0;
        vec3 edge2 = v2 - v0;
        vec3 v2 = point - v0;

        double d00 = dot(edge1, edge1);
        double d01 = dot(edge1, edge2);
        double d11 = dot(edge2, edge2);

        double d20 = dot(v2, edge1);
        double d21 = dot(v2, edge2);

        double denominator = d00 * d11 - d01 * d01;

        double v = (d11 * d20 - d01 * d21) / denominator;
        double w = (d00 * d21 - d01 * d20) / denominator;
        double u = 1.0 - v - w;

        return vec3(u, v, w);
    } 

};


#endif