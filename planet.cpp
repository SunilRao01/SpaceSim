#include "planet.h"

void planet::renderPlanet()
{
	int num_segments = 8;

	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
				
		float x = radius * cosf(theta);//calculate the x component 
		float y = radius * sinf(theta);//calculate the y component 
				
		vertexArray[vertexArrayCount] = x;
		vertexArrayCount++;
		vertexArray[vertexArrayCount] = y;
		vertexArrayCount++;
		
	} 
	
	// VAO rendering
	glEnableClientState(GL_VERTEX_ARRAY);
	{
		glVertexPointer(2, GL_FLOAT, 0, &vertexArray);
		glDrawArrays(GL_LINE_LOOP, 0, vertexArrayCount/2);
	}
	glDisableClientState(GL_VERTEX_ARRAY);
	

	vertexArrayCount = 0;
}

// Render planet to an x and y offset from the center
void planet::renderPlanet(int xOffset, int yOffset)
{
	int num_segments = 8;
	
	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
				
		float x = radius * cosf(theta);//calculate the x component 
		float y = radius * sinf(theta);//calculate the y component 
				
		vertexArray[vertexArrayCount] = x + xOffset;
		vertexArrayCount++;
		vertexArray[vertexArrayCount] = y + yOffset;
		vertexArrayCount++;
	} 
	
	
	// VAO rendering
	glEnableClientState(GL_VERTEX_ARRAY);
	{
		glVertexPointer(2, GL_FLOAT, 0, &vertexArray);
		glDrawArrays(GL_LINE_LOOP, 0, vertexArrayCount/2);
	}
	glDisableClientState(GL_VERTEX_ARRAY);
	

	vertexArrayCount = 0;
}

int planet::getPlanetRadius()
{
	return radius;
}

