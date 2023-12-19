# Material Class

The `material` class is an abstract base class representing a generic material in a ray tracing system. It provides a virtual function for material scattering that needs to be implemented by its derived classes.

## Derived Classes

### 1. Lambertian Class
#### Description
The `lambertian` class is derived from the `material` class and represents a Lambertian (diffuse) material. It scatters rays in random directions on the hemisphere.

#### Constructor
- **Parameters:**
  - `albedo`: The color of the material.

#### Member Function
- `bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override`
  - Description: Implements Lambertian scattering.
  - Parameters:
    - `r_in`: Incoming ray.
    - `rec`: Hit record information.
    - `attenuation`: Color attenuation after scattering.
    - `scattered`: Scattered ray.

### 2. Metal Class
#### Description
The `metal` class is derived from the `material` class and represents a metal material. It reflects rays in a specular manner with optional fuzziness.

#### Constructor
- **Parameters:**
  - `albedo`: The color of the material.
  - `fuzz`: The fuzziness factor (0 for perfect reflection, 1 for maximum fuzziness).

#### Member Function
- `bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override`
  - Description: Implements metal material scattering.
  - Parameters:
    - `r_in`: Incoming ray.
    - `rec`: Hit record information.
    - `attenuation`: Color attenuation after scattering.
    - `scattered`: Scattered ray.

### 3. Dielectric Class
#### Description
The `dielectric` class is derived from the `material` class and represents a dielectric (transparent) material. It handles both reflection and refraction.

#### Constructor
- **Parameters:**
  - `index_of_refraction`: The refractive index of the material.

#### Member Function
- `bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override`
  - Description: Implements dielectric material scattering.
  - Parameters:
    - `r_in`: Incoming ray.
    - `rec`: Hit record information.
    - `attenuation`: Color attenuation after scattering.
    - `scattered`: Scattered ray.

  - Private Static Function:
    - `static double reflectance(double cosine, double ref_idx)`
      - Description: Calculates the reflectance using Schlick's approximation.