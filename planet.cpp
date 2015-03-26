#include "planet.h"

void planet::renderPlanet()
{
	int num_segments = 8;

	// Immediate mode rendering
	//glBegin(GL_LINE_LOOP); 
	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
				
		float x = radius * cosf(theta);//calculate the x component 
		float y = radius * sinf(theta);//calculate the y component 
				
		glVertex2f(x, y);//output vertex 
		
		vertexArray[vertexArrayCount] = x;
		vertexArrayCount++;
		vertexArray[vertexArrayCount] = y;
		vertexArrayCount++;
		
	} 
	//glEnd();
	
	
	// VBO rendering
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
	
	//glBegin(GL_LINE_LOOP); 
	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
				
		float x = radius * cosf(theta);//calculate the x component 
		float y = radius * sinf(theta);//calculate the y component 
				
		glVertex2f(x + xOffset, y + yOffset);//output vertex 
		// TODO: Reason for seg fault is because you keep 
		// appending vertexArrayCount a bajillion times maybe?
		
		vertexArray[vertexArrayCount] = x + xOffset;
		vertexArrayCount++;
		vertexArray[vertexArrayCount] = y + yOffset;
		vertexArrayCount++;
		
	} 
	//glEnd();
	
	
	// VBO rendering
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

