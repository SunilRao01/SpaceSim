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
		// Constructor
		solarsystem(int minPlanets, int maxPlanets, float cenX, float cenY): sun(15, 20), minNumPlanets(minPlanets), maxNumPlanets(maxPlanets)
		{
			changingParameters = false;
			centerX = cenX;
			centerY = cenY;
			
			srand(time(NULL));
			numPlanets = rand() % maxPlanets + minPlanets;
			planets = (planet *) malloc(numPlanets * 100);

			for (int i = 0; i < numPlanets; i++)
			{
				planet tempPlanet(5, 15);

				planets[i] = tempPlanet;
			}
			
			rotationSpeed = 0.05f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.5f-0.05f)));
		}

		// Destructor
		~solarsystem()
		{
			free(planets);
		}
		
		void shuffle();
		void renderSolarSystem();
		void rotatePlanets();

		float getRotationSpeed();

	protected:
		// Planet variables
		int minNumPlanets;
		int maxNumPlanets;
		float rotationSpeed;
		bool changingParameters;

		// Solar system positioning variables
		float centerX;
		float centerY;
};

#endif
