#include "lutil.h"
#include <GL/freeglut.h>

// Camera position
GLfloat gCameraX = 0.0f, gCameraY = 0.0f;

// Solar System
solarsystem ss(1, 3);

// Fot font rendering
unsigned char image[SCREEN_WIDTH][SCREEN_HEIGHT];

bool initGL()
{
	// Set the view port
	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);

	// Initialize projection matrix
	glMatrixMode(GL_PROJECTION);

	// Loads identity matrix into current matrix
	glLoadIdentity();

	// Multiplies the current matrix against an ortho perspectice matrix
	// with the left, right, bottom, top, near, and far values in the arguments.
	glOrtho(0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 1.0f, -1.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Save the default modelview matrix
	glPushMatrix();

	// Set color when 'glClear()' is called (Uses RGBA format, currently black)
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Check for any OpenGL errors that may occur during initialization
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		printf("Error initializing OpenGL! %s\n", gluErrorString(error));
		return false;
	}

	

	return true;
}

// Return true if successful, false otherwise
bool loadMedia()
{
	return true;
}

void update()
{
	ss.rotatePlanets();
}

void render()
{
	// Clear the color buffer (pixels on the screen)
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	// Pop default matrix onto current matrix
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	// Save default matrix again
	glPushMatrix();

	// Move projection view to center of screen
	glTranslatef(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f);

	// Text
	glRasterPos2i(-300, -200);
	const unsigned char *c;
	std::string text = "Basic Solar System Simulation";
	for (int i = 0; i < text.size(); ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);
	}

	// Render solar system
	ss.renderSolarSystem();

	// Update GLUT buffer (our second buffer)
	glutSwapBuffers();

}

void handleKeys(unsigned char key, int x, int y)
{
	
	/*
	// Handle camera movement
	if (key == 'w')
	{
		gCameraY -= 16.0f;
	}
	else if (key == 's')
	{
		gCameraY += 16.0f;
	}
	else if (key == 'a')
	{
		gCameraX -= 16.0f;
	}
	else if (key == 'd')
	{
		gCameraX += 16.0f;
	}
	*/

	if (key == ' ')
	{
		ss.shuffle();
	}
	// Take saved matrix off the stack and reset it
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glLoadIdentity();
	
	// Move camera to position
	glTranslatef(gCameraX, gCameraY, 0.0f);

	// Save default matrix again with camera translation
	glPushMatrix();
	
}








