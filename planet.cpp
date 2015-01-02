#include "planet.h"

planet::~planet()
{
	glDeleteBuffers(1, &vertexVBOID);
	glDeleteBuffers(1, &indexVBOID);
}

void planet::renderPlanet()
{
	glDrawElements(GL_LINES, 8, GL_UNSIGNED_SHORT, BUFFER_OFFSET(0));	
}

// Render planet to an x and y offset from the center
void planet::renderPlanet(int xOffset, int yOffset)
{
	
}

int planet::getPlanetRadius()
{
	return radius;
}

