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
		solarsystem(int minPlanets, int maxPlanets): sun(15, 20), minNumPlanets(minPlanets), maxNumPlanets(maxPlanets)
		{
			srand(time(NULL));
			numPlanets = rand() % maxPlanets + minPlanets;
			planets = (planet *) malloc(numPlanets * 10);

			for (int i = 0; i < numPlanets; i++)
			{
				planet tempPlanet(5, 15);

				planets[i] = tempPlanet;
			}
			
			rotationSpeed = 0.05f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.5f-0.05f)));
		}
		~solarsystem()
		{
			free(planets);
		}
		
		void shuffle();
		void renderSolarSystem();
		void rotatePlanets();

		float getRotationSpeed();

	protected:
		int minNumPlanets;
		int maxNumPlanets;
		float rotationSpeed;
};

#endif
