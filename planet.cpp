#include "planet.h"

void planet::renderPlanet()
{
	glBegin(GL_QUADS);
		glVertex2f(-(planetWidth/2), -(planetHeight/2));
		glVertex2f((planetWidth/2), -(planetHeight/2));
		glVertex2f((planetWidth/2), (planetHeight/2));
		glVertex2f(-(planetWidth/2), (planetHeight/2));
	glEnd();
}

int planet::getPlanetWidth()
{
	return planetWidth;
}

int planet::getPlanetHeight()
{
	return planetHeight;
}
