# Triangle Class Documentation

The `triangle` class inherits from the `hittable` class and represents a triangle in 3D space. It includes functionality for checking ray-triangle intersections.

## Constructors

### `triangle(const vec3& v0, const vec3& v1, const vec3& v2)`
- Initializes the triangle with three vertices `v0`, `v1`, and `v2`.

## Members

- `vec3 v0, v1, v2`: Triangle vertices.
- `vec3 n0, n1, n2`: Normals at each vertex.

## Member Functions

### `bool hit(const ray& r, interval ray_t, hit_record& rec) const override`
- Overrides the base class function to check for ray-triangle intersections.
- Parameters:
  - `r`: The ray to check for intersection.
  - `ray_t`: The valid range of t values for the intersection.
  - `rec`: Reference to a `hit_record` object where information about the intersection will be stored.
- Returns `true` if there is an intersection, `false` otherwise.

### `vec3 toBarycentricCoordinates(const point3& point) const`
- Calculates the barycentric coordinates for a given point within the triangle.
- Parameters:
  - `point`: The point within the triangle for which to calculate the barycentric coordinates.
- Returns a `vec3` containing the barycentric coordinates (u, v, w).

## Intersection Algorithm

The class uses the Möller–Trumbore intersection algorithm to efficiently check for ray-triangle intersections.

