# Color Utility Functions Documentation

The `color` is represented as an alias for the `vec3` class, indicating that a color is treated as a three-dimensional vector.

## Function

### `color write_color(color pixel_color, int samples_per_pixel)`

Adjusts and return the adjusted color.

#### Parameters
- `pixel_color`: Represents the accumulated color value for a pixel.
- `samples_per_pixel`: The number of samples per pixel.

#### Return Value
Returns the adjusted color after dividing it by the number of samples and clamping each color component to the range [0.0, 1.0].
