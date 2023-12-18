# Sphere Class Documentation

The `sphere` class represents a three-dimensional sphere and inherits from the `hittable` class, making it suitable for use in ray-tracing scenarios.

## Constructor

### `sphere(point3 _center, double _radius)`
- Initializes the sphere with a specified center (`_center`) and radius (`_radius`).

## Member Functions

### `bool hit(const ray& r, interval ray_t, hit_record& rec) const override`
- Overrides the base class function to check for ray-sphere intersections.
- Parameters:
  - `r`: The ray to check for intersection.
  - `ray_t`: The valid range of t values for the intersection.
  - `rec`: Reference to a `hit_record` object where information about the intersection will be stored.
- Returns `true` if there is an intersection with the sphere, `false` otherwise.

## Intersection Algorithm

The `hit` function uses the quadratic equation to determine whether and where a given ray intersects with the sphere. It calculates the intersection point, normal, and updates the `hit_record` object accordingly.