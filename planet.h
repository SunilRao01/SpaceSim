#ifndef PLANET_H
#define PLANET_H

#include "lopengl.h"
#include <stdio.h>
#include <string>
#include <math.h>

// Use system clock for random seed
#include <time.h>
#include <stdlib.h>

#define BUFFER_OFFSET(i) ((void*)(i))

struct mVertex
{
	float x, y, z;
	float nx, ny, nz;
	float t0, t1;
};

class planet
{
	public:
		planet(int minRadius, int maxRadius) 
		{
			float minRotationSpeed = 0.05f;
			float maxRotationSpeed = 0.5f;

			radius = rand() % maxRadius + minRadius;
			/*
			int num_segments = 8;
	
			for(int ii = 0; ii < num_segments; ii++) 
			{ 
				float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
				
				float x = radius * cosf(theta);//calculate the x component 
				float y = radius * sinf(theta);//calculate the y component 
				
				//glVertex2f(x + 0, y + 0);//output vertex 
				vertexData[ii]->x = x;
				vertexData[ii]->y = y;
				vertexData[ii]->z = 0;
				vertexData[ii]->nx = 0.0;
				vertexData[ii]->ny = 0.0;
				vertexData[ii]->nz = 1.0;
				vertexData[ii]->t0 = 0.0;
				vertexData[ii]->t1 = 0.0;
			}

			// Use buffers to create VBO
			glGenBuffers(1, &vertexVBOID);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBOID);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mVertex) * 3, &vertexData[0]->x, GL_STATIC_DRAW);

			ushort pindices[8];
			for (int i = 0; i < 8; i++)
			{
				pindices[i] = i;
			}

			glGenBuffers(1, &indexVBOID);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBOID);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(ushort) * 3, pindices, GL_STATIC_DRAW);

			glBindBuffer(GL_ARRAY_BUFFER, vertexVBOID);
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(3, GL_FLOAT, sizeof(mVertex), BUFFER_OFFSET(0)); // Starting point for the VBO for vertices (vertexData)
			glEnableClientState(GL_NORMAL_ARRAY);
			glNormalPointer(GL_FLOAT, sizeof(mVertex), BUFFER_OFFSET(12));
			glClientActiveTexture(GL_TEXTURE0);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glTexCoordPointer(2, GL_FLOAT, sizeof(mVertex), BUFFER_OFFSET(24));

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBOID);
			*/



		}
		//~planet();


		float angle;

		int getPlanetRadius();

		void renderPlanet();
		void renderPlanet(int xOffset, int yOffset);

		// Vertex data

	private:
		int radius;
		GLuint vertexVBOID;
		GLuint indexVBOID;
		mVertex *vertexData[8];
};

#endif
