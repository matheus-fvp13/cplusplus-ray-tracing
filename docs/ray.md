# Ray Class Documentation

The `ray` class represents a ray in 3D space, commonly used in ray tracing and rendering applications.

## Constructors

### `ray()`
- Default constructor for creating an uninitialized ray.

### `ray(const point3& origin, const vec3& direction)`
- Parameterized constructor that takes the origin (`point3`) and direction (`vec3`) to initialize a ray.

## Member Functions

### `point3 origin() const`
- Getter function to retrieve the origin point of the ray.

### `vec3 direction() const`
- Getter function to retrieve the direction of the ray.

### `point3 at(double t) const`
- Calculates and returns the point along the ray at a given parameter value 't' using the formula `origin + t * direction`.