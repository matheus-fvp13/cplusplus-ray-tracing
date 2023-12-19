# RTWeekend Header Documentation

The `rtweekend` header provides utility functions, constants, and common headers for a Ray Tracing application.

## Constants

- `infinity`: Represents positive infinity, a value larger than any representable floating-point number.
- `pi`: Represents the mathematical constant π (pi).

## Utility Functions

### `double degrees_to_radians(double degrees)`

Converts degrees to radians.

### `double random_double()`

Generates a random real number in the range [0,1).

### `double random_double(double min, double max)`

Generates a random real number in the specified range [min, max).

## Common Headers

- `interval.h`: Header for the interval class.
- `ray.h`: Header for the ray class.
- `vec3.h`: Header for the vec3 class.