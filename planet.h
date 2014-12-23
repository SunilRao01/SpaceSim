#ifndef PLANET_H
#define PLANET_H

#include "lopengl.h"
#include <stdio.h>
#include <string>
#include <math.h>

// Use system clock for random seed
#include <time.h>
#include <stdlib.h>

class planet
{
	public:
		planet(int minRadius, int maxRadius) 
		{
			srand(time(NULL));

			float minRotationSpeed = 0.05f;
			float maxRotationSpeed = 0.5f;

			radius = rand() % maxRadius + minRadius;
			rotationSpeed = minRotationSpeed + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(maxRotationSpeed-minRotationSpeed)));
		}

		float angle;

		int getPlanetRadius();
		float getRotationSpeed();

		void renderPlanet();
		void renderPlanet(int xOffset, int yOffset);
	private:
		int radius;
		float rotationSpeed;
};

#endif
