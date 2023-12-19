# Hittable Class Documentation

The `hittable` class is an abstract base class for hittable objects, and the `hit_record` class represents information about a ray-object intersection.

## hit_record class

### Members

- `point3 p`: Point of intersection.
- `vec3 normal`: Surface normal at the point of intersection.
- `double t`: Parameter value along the ray where the intersection occurs.
- `bool front_face`: Indicates whether the intersection is from the front face.

### Methods

#### `void set_face_normal(const ray& r, const vec3& outward_normal)`

- Sets the face normal based on the ray direction and outward normal.

## hittable class

### Destructor

- `virtual ~hittable() = default;`

   Virtual destructor for proper polymorphic destruction.

### Pure Virtual Function

#### `virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;`

- Checks for ray-object intersection.
- Parameters:
  - `r`: The ray to check for intersection.
  - `ray_t`: The interval representing the valid range of t values for the intersection.
  - `rec`: Reference to a `hit_record` object where information about the intersection will be stored.
- Returns `true` if there is an intersection, `false` otherwise.