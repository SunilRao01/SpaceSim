#include "solarsystem.h"

void solarsystem::renderSolarSystem()
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

void solarsystem::rotatePlanets()
{
	for(int i = 0; i < numPlanets; i++)
	{
		planets[i].angle += (360.0f / 60) * (planets[i].getRotationSpeed());

		// Cap angle
		if (planets[i].angle >= 360.0f)
		{
			planets[i].angle -= 360.0f;
		}
	}
}
