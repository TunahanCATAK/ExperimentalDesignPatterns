//
// Created by Tunahan Catak on 26/11/2024.
//

#ifndef COMPOSITEBUILDER_SOLIDWALL_H
#define COMPOSITEBUILDER_SOLIDWALL_H

#include "Wall.h"
#include <memory>
#include <iostream>

enum class WallType{
    basic,
    main,
    partition
};

class SolidWall : public Wall{
    friend class WallFactory;
public:
    int width;
    Material material;

protected:
    SolidWall(Point2D start, Point2D end, int elevation, int height, int width, Material material)
                : Wall{start, end, elevation, height}, width{width}, material{material} {}

public:

};

// Overload for SolidWall class
std::ostream& operator<<(std::ostream& os, const SolidWall& wall) {
    os << static_cast<const Wall&>(wall) << ", "
       << "Width: " << wall.width << ", "
       << "Material: " << static_cast<int>(wall.material) << "]";
    return os;
}

#endif //COMPOSITEBUILDER_SOLIDWALL_H
