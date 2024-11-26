//
// Created by Tunahan Catak on 26/11/2024.
//

#ifndef NESTEDFACTORY_WALLFACTORY_H
#define NESTEDFACTORY_WALLFACTORY_H

#include "Wall.h"
#include "SolidWall.h"
#include <memory>

/*
 * Ownership semantic of the make_shared is different from the new keyword.
 * std::make_shared creates a shared pointer that directly owns the object it constructs.
 * This means the type of the object it constructs and the type of the std::shared_ptr it creates must be the same
 * In your case, SolidWall is derived from Wall, and when calling std::make_shared<SolidWall>(), it constructs an
 * object of type SolidWall. However, the create_wall function returns a std::shared_ptr<Wall>, requiring a conversion
 * from std::shared_ptr<SolidWall> to std::shared_ptr<Wall>.
 * This conversion is not supported directly by std::make_shared because it returns a std::shared_ptr
 * tightly bound to the type of the object it allocates.
 *
 * For Details: look at why std::make_shared cannot be used with polymorphic types.md file.
 * */

class WallFactory {
public:
    static std::shared_ptr<Wall> create_wall(WallType wallType, Point2D start, Point2D end, int elevation, int height){
        switch (wallType){
            case WallType::basic:
                return std::make_shared<Wall>(start, end, elevation, height);
            case WallType::main:
                //return std::make_shared<SolidWall>(start, end, elevation, height, 20, Material::aerated_concrete);
                return std::shared_ptr<SolidWall>{new SolidWall(start, end, elevation, height, 20, Material::aerated_concrete)};
            case WallType::partition:
                //return std::make_shared<SolidWall>(start, end, elevation, height, 5, Material::drywall);
                return std::shared_ptr<SolidWall>{new SolidWall(start, end, elevation, height, 5, Material::drywall)};
        }
    }
};

#endif //NESTEDFACTORY_WALLFACTORY_H
