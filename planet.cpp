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

// Render planet to an x and y offset from the center
void planet::renderPlanet(int xOffset, int yOffset)
{

	glTranslatef(xOffset, yOffset, 0);
	
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

float planet::getRotationSpeed()
{
	return rotationSpeed;
}
