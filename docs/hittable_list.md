# Hittable List Class Documentation

The `hittable_list` class is a container class for managing a list of hittable objects. It inherits from the `hittable` class, indicating its capability to be used in ray-tracing scenarios.

## Constructors

### `hittable_list()`
- Default constructor to create an empty list of hittable objects.

### `hittable_list(shared_ptr<hittable> object)`
- Parameterized constructor to create a list with a single hittable object.

## Members

- `std::vector<shared_ptr<hittable>> objects`: A vector to store shared pointers to hittable objects.

## Member Functions

### `void clear()`
- Clears the list, removing all hittable objects.

### `void add(shared_ptr<hittable> object)`
- Adds a hittable object to the list.

### `bool hit(const ray& r, interval ray_t, hit_record& rec) const override`
- Overrides the base class function to check for ray-object intersections within the list.
- Parameters:
  - `r`: The ray to check for intersection.
  - `ray_t`: The valid range of t values for the intersection.
  - `rec`: Reference to a `hit_record` object where information about the intersection will be stored.
- Returns `true` if there is an intersection with any object in the list, `false` otherwise.

## Intersection Algorithm

The class iterates over the list of hittable objects and checks for intersections with each object using the provided `hit` function.
