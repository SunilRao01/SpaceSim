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
			srand(time(0));

			planetWidth = rand() % (maxWidth - minWidth + 1) + maxWidth;
			planetHeight = rand() % (maxHeight - minHeight + 1) + maxHeight;
		}

		int getPlanetWidth();
		int getPlanetHeight();

		void renderPlanet();
	private:
		int planetWidth;
		int planetHeight;
};

#endif
