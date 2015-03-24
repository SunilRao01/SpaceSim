#include "solarsystem.h"

void solarsystem::renderSolarSystem()
{
	if (!changingParameters)
	{
		// Render sun
		sun.renderPlanet();
	
		// Render planet
		for (int i = 0; i < numPlanets; i++)
		{
			// Rotate planets
			glRotatef(planets[i].angle, 0.0f, 0.0f, 1.0f);
		
			if (i == 0)
			{
				planets[i].renderPlanet(0, -60);
			}
			else
			{
				planets[i].renderPlanet(0, (i+1) * (-60));
			}
		}
	}

}

void solarsystem::rotatePlanets()
{
	if (!changingParameters)
	{
		for(int i = 0; i < numPlanets; i++)
		{
			planets[i].angle += (360.0f / 60) * (getRotationSpeed());

			// Cap angle
			if (planets[i].angle >= 360.0f)
			{
				planets[i].angle -= 360.0f;
			}
		}
	}
}

void solarsystem::shuffle()
{
	changingParameters = true;
	free(planets);

	numPlanets = rand() % maxNumPlanets + minNumPlanets;
	planets = (planet *) malloc(1024);
	
	rotationSpeed = 0.05f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.5f-0.05f)));
	
	for (int i = 0; i < numPlanets; i++)
	{
		planet tempPlanet(5, 15);

		planets[i] = tempPlanet;
	}

	changingParameters = false;
}

float solarsystem::getRotationSpeed()
{
	return rotationSpeed;
}
