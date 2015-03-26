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
			float minRotationSpeed = 0.05f;
			float maxRotationSpeed = 0.5f;

			radius = rand() % maxRadius + minRadius;

			vertexArrayCount = 0;
		}

		float angle;

		int getPlanetRadius();

		void renderPlanet();
		void renderPlanet(int xOffset, int yOffset);
	private:
		int radius;

		// TODO: Reimplement VBO object from youtube tutorial (https://www.youtube.com/watch?v=KIeExgOcmv0)
		float vertexArray[20];
		int vertexArrayCount;
};

#endif
