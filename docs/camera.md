# Camera Class Documentation

The `camera` class represents a virtual camera for rendering scenes. It utilizes the Ray Tracing technique to generate images based on the specified scene and camera parameters.

## Public Members

- `double aspect_ratio`: Ratio of image width over height.
- `int image_width`: Rendered image width in pixel count.
- `int samples_per_pixel`: Count of random samples for each pixel.
- `int max_depth`: Maximum recursion depth for ray tracing.
- `double vfov`: Vertical field of view in degrees.
- `point3 lookfrom`: Point from which the camera is looking.
- `point3 lookat`: Point at which the camera is looking.
- `vec3 vup`: Camera-relative "up" direction.

## Public Methods

### `Magick::Image render(const hittable& world)`

Renders the scene specified by the `world` parameter and returns a Magick++ Image object representing the resulting image.

## Private Members

- `int image_height`: Rendered image height.
- `point3 center`: Camera center.
- `point3 pixel00_loc`: Location of pixel (0, 0).
- `vec3 pixel_delta_u`: Offset to pixel to the right.
- `vec3 pixel_delta_v`: Offset to pixel below.
- `vec3 w, u, v`: Camera frame basic vectors.

## Private Methods

### `void initialize()`

Initializes the camera by calculating various parameters such as image dimensions, viewport dimensions, and camera frame vectors.

### `ray get_ray(int i, int j) const`

Generates a camera ray for the pixel at coordinates (i, j).

### `vec3 pixel_sample_square() const`

Returns a random point in the square surrounding a pixel at the origin.

### `color background_color(const ray& r) const`

Calculates the background color based on the direction of the given ray.

### `color ray_color(const ray& r, int depth, const hittable& world) const`

Calculates the color of a given ray by tracing it through the scene. The `depth` parameter controls recursion depth.