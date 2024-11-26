//
// Created by Tunahan Catak on 26/11/2024.
//


#include <iostream>

#include "src/WallFactory.h"

int main() {

    const auto partition = WallFactory::create_wall(WallType::partition, Point2D{0, 0}, Point2D{10, 10}, 0, 3);
    if (partition)
    {
        std::cout << *std::dynamic_pointer_cast<SolidWall>(partition) << std::endl;
        std::cout << *partition << std::endl;
    }
    return 0;
}
