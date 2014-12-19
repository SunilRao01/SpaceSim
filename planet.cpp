#include "planet.h"

void planet::renderPlanet()
{
	int num_segments = 8;
	
	glBegin(GL_LINE_LOOP); 
	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
				
		float x = radius * cosf(theta);//calculate the x component 
		float y = radius * sinf(theta);//calculate the y component 
				
		glVertex2f(x + 0, y + 0);//output vertex 
	} 
	glEnd();
}

// Render planet to an x and y offset from the center
void planet::renderPlanet(int xOffset, int yOffset)
{
	int num_segments = 8;
	
	glBegin(GL_LINE_LOOP); 
	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
				
		float x = radius * cosf(theta);//calculate the x component 
		float y = radius * sinf(theta);//calculate the y component 
				
		glVertex2f(x + xOffset, y + yOffset);//output vertex 
	} 
	glEnd();
}

int planet::getPlanetRadius()
{
	return radius;
}

float planet::getRotationSpeed()
{
	return rotationSpeed;
}
