#include "solarsystem.h"

void solarsystem::renderSolarSystem()
{
	if (!changingParameters)
	{
		glPushMatrix();
		
		// Center solar system
		glTranslatef(centerX, centerY, 0.0f);
		
		// Render sun
		sun.renderPlanet(0, 0);
	
		// Render planets
		for (int i = 0; i < numPlanets; i++)
		{
			// Rotate planets
			//glTranslatef(centerX, centerY, 0.0f);
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

		glPopMatrix();
	}

}

// TODO: Change rotation so it doesn't always rotate around (0, 0)
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
	planets = (planet *) malloc(numPlanets * 100);
	
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
