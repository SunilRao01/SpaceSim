#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include "lopengl.h"
#include "planet.h"
#include <stdio.h>
#include <string>
#include <math.h>

// Use system clock for random seed
#include <time.h>
#include <stdlib.h>
#include <iostream>

class solarsystem
{
planet sun;
planet *planets;
int numPlanets;
	
	public:
		solarsystem(int minPlanets, int maxPlanets): sun(15, 20)
		{
			srand(time(NULL));
			numPlanets = rand() % maxPlanets + minPlanets;
			std::cout << "Test";
			planets = (planet *) malloc(numPlanets * 10);

			for (int i = 0; i < numPlanets; i++)
			{
				planet tempPlanet(5, 15);

				planets[i] = tempPlanet;
			}
		}
		~solarsystem()
		{
			free(planets);
		}

		void renderSolarSystem();
		void rotatePlanets();
};

#endif
