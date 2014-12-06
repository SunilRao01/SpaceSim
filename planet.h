#ifndef PLANET_H
#define PLANET_H

#include "lopengl.h"
#include <stdio.h>
#include <string>

// Use system clock for random seed
#include <time.h>
#include <stdlib.h>

class planet
{
	public:
		planet(int minWidth, int maxWidth, int minHeight, int maxHeight) 
		{
			//srand(time(0));

			planetWidth = rand() % maxWidth + minWidth;
			planetHeight = rand() % maxHeight + minHeight;
			//rotationSpeed = minRotationSpeed + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(maxRotationSpeed-minRotationSpeed)));
		}

		int getPlanetWidth();
		int getPlanetHeight();
		float getRotationSpeed();

		void renderPlanet();
		void renderPlanet(int xOffset, int yOffset);
	private:
		int planetWidth;
		int planetHeight;
		float rotationSpeed;
};

#endif
