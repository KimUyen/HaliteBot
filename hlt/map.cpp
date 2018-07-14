#include "map.hpp"

namespace hlt {
    Map::Map(const int width, const int height) : map_width(width), map_height(height) {
    }
	
	int Map::FindNearestPlanetCanDockFrom(hlt::Ship ship) const 
	{
		int id = -1;
		int distanceMin = -1;
		for (const hlt::Planet& planet : planets)
		{
			if (planet.owned && planet.owner_id == ship.owner_id) 
			{
                continue;
            }
			if (ship.can_dock(planet))
			{
				int distance = ship.location.get_distance_to(planet.location);
				if (distanceMin == -1 || distance < distanceMin)
				{
					distanceMin = distance;
					id = (int)planet.entity_id;
				}
			}
		}
		return id;
	}
}
