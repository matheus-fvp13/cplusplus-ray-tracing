#ifndef INTERVAL_H
#define INTERVAL_H

// Represents a one-dimensional interval [min, max]
class interval {
  public:
    double min, max; // Minimum and maximum bounds of the interval

    interval() : min(+infinity), max(-infinity) {} // Default interval is empty

    interval(double _min, double _max) : min(_min), max(_max) {}

    // Checks if the interval contains a given value
    bool contains(double x) const {
        return min <= x && x <= max;
    }

    // Checks if the interval surrounds a given value (excluding endpoints)
    bool surrounds(double x) const {
        return min < x && x < max;
    }

    // Clamps a value to the interval bounds
    double clamp(double x) const {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }

    static const interval empty, universe;
};

const static interval empty   (+infinity, -infinity);
const static interval universe(-infinity, +infinity);

#endif