# Vec3 Class Documentation

The `vec3` class represents a 3D vector or point in space.

## Constructors

### `vec3()`
- Default constructor that initializes the vector to (0, 0, 0).

### `vec3(double e0, double e1, double e2)`
- Parameterized constructor that allows you to specify the vector components.

## Member Functions

### `double x() const`
- Returns the x-component of the vector.

### `double y() const`
- Returns the y-component of the vector.

### `double z() const`
- Returns the z-component of the vector.

### `vec3 operator-() const`
- Unary minus operator overloading to obtain the negation of the vector.

### `double operator[](int i) const`
- Array subscript operator overloading for accessing vector components.

### `double& operator[](int i)`
- Array subscript operator overloading for modifying vector components.

### `vec3& operator+=(const vec3 &v)`
- Compound assignment operator for vector addition.

### `vec3& operator*=(double t)`
- Compound assignment operator for scalar multiplication.

### `vec3& operator/=(double t)`
- Compound assignment operator for scalar division.

### `double length() const`
- Returns the Euclidean length of the vector.

### `double length_squared() const`
- Returns the squared Euclidean length of the vector.

### `static vec3 random()`
- Static method to generate a random vector.

### `static vec3 random(double min, double max)`
- Static method to generate a random vector within a specified range.

## Utility Functions

### `inline std::ostream& operator<<(std::ostream &out, const vec3 &v)`
- Output stream operator overloading for vector.

### `inline vec3 operator+(const vec3 &u, const vec3 &v)`
- Addition operator overloading for vectors.

### `inline vec3 operator-(const vec3 &u, const vec3 &v)`
- Subtraction operator overloading for vectors.

### `inline vec3 operator*(const vec3 &u, const vec3 &v)`
- Element-wise multiplication operator overloading for vectors.

### `inline vec3 operator*(double t, const vec3 &v)`
- Scalar multiplication operator overloading.

### `inline vec3 operator*(const vec3 &v, double t)`
- Scalar multiplication operator overloading.

### `inline vec3 operator/(vec3 v, double t)`
- Scalar division operator overloading.

### `inline double dot(const vec3 &u, const vec3 &v)`
- Dot product calculation between two vectors.

### `inline vec3 cross(const vec3 &u, const vec3 &v)`
- Cross product calculation between two vectors.

### `inline vec3 unit_vector(vec3 v)`
- Function to obtain the unit vector of a given vector.

### `inline vec3 random_in_unit_sphere()`
- Generates a random vector within the unit sphere.

### `inline vec3 random_unit_vector()`
- Generates a random unit vector.

### `inline vec3 random_on_hemisphere(const vec3& normal)`
- Generates a random vector on the hemisphere with a given normal.

### `inline vec3 reflect(const vec3& v, const vec3& n)`
- Calculates the reflection vector of a ray incident on a surface

### `inline vec3 refract(const vec3& uv, const vec3& n, double etai_over_etat)`
- Calculates the refraction vector of a ray incident on a transparent surface.

## Alias

### `using point3 = vec3`
- Alias for geometric clarity, representing a point in space.
