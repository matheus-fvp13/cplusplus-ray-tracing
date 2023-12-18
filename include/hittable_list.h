#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

//It's a container class for managing a list of hittable objects. It inherits from the `hittable` class, indicating its capability to be used in ray-tracing scenarios.
class hittable_list : public hittable {
  public:
    std::vector<shared_ptr<hittable>> objects; // Vector to store shared pointers to hittable objects

    hittable_list() {}
    hittable_list(shared_ptr<hittable> object) { add(object); }

    // Clears the list, removing all hittable objects
    void clear() { objects.clear(); }

    // Adds a hittable object to the list
    void add(shared_ptr<hittable> object) {
        objects.push_back(object);
    }

    // Overrides the base class function to check for ray-object intersections within the list
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        hit_record temp_rec;
        bool hit_anything = false;
        auto closest_so_far = ray_t.max;

        // Iterate over the list of hittable objects
        for (const auto& object : objects) {
            // Check for intersection with the current object
            if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec; // Update the hit record with the closest intersection
            }
        }

        return hit_anything;
    }
};

#endif