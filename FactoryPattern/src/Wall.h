//
// Created by Tunahan Catak on 26/11/2024.
//

#ifndef COMPOSITEBUILDER_WALL_H
#define COMPOSITEBUILDER_WALL_H
#include <iostream>

enum class Material {
    brick,
    aerated_concrete,
    drywall,
};

class Point2D{
public:
    double x, y;
    Point2D() : x{0}, y{0} {}
    Point2D(double x, double y) : x{x}, y{y} {}
};

class Wall{
    friend class WallFactory;

public:
    Point2D start, end;
    int elevation, height;

    Wall(Point2D start, Point2D end, int elevation, int height) : start{start}, end{end}, elevation{elevation}, height{height} {}

    virtual ~Wall() = default; // Add a virtual destructor
};

// Overload for Wall class
std::ostream& operator<<(std::ostream& os, const Wall& wall) {
    os << "Wall [Start: (" << wall.start.x << ", " << wall.start.y << "), "
       << "End: (" << wall.end.x << ", " << wall.end.y << "), "
       << "Elevation: " << wall.elevation << ", "
       << "Height: " << wall.height << "]";
    return os;
}

#endif //COMPOSITEBUILDER_WALL_H
