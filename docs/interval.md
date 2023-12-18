# Interval Class Documentation

The `interval` class represents a one-dimensional interval `[min, max]`.

## Constructors

### `interval()`
- Default constructor initializes an empty interval.

### `interval(double _min, double _max)`
- Parameterized constructor to set the interval with specified bounds.

## Members

- `double min, max`: Minimum and maximum bounds of the interval.

## Member Functions

### `bool contains(double x) const`
- Checks if the interval contains a given value `x`.
- Returns `true` if `min <= x <= max`, `false` otherwise.

### `bool surrounds(double x) const`
- Checks if the interval surrounds a given value `x` (excluding endpoints).
- Returns `true` if `min < x < max`, `false` otherwise.

### `double clamp(double x) const`
- Clamps a value `x` to the interval bounds.
- Returns `min` if `x < min`, `max` if `x > max`, otherwise returns `x`.

## Static Constants

- `static const interval empty, universe`: Represents static instances for an empty interval and the entire real number line, respectively.

## Static Instances
- `const static interval empty   (+infinity, -infinity)`;
- `const static interval universe(-infinity, +infinity)`;
