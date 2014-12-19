#include "lutil.h"
// Camera position
GLfloat gCameraX = 0.0f, gCameraY = 0.0f;


// Planets
planet sun(15, 20);
planet *planets;
int numPlanets;


// Angle of polygon
float gAngle = 0.0f;

bool initGL()
{
/*	NOTES
	 *
	 * The projection and model view matrices are both matrices
	 * that geometry data is multiplied against before rendering.
	 *
	 * By setting them both to the identity matrix,
	 * what every geometry is sent through is what is 
	 * rendered since the identity matrix simply returns
	 * the same vector back when you multiply against it.
	 *
	 * */
	
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

	// Solar system
	
	// Create a random numer of planets

	// Check for any OpenGL errors that may occur during initialization
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		printf("Error initializing OpenGL! %s\n", gluErrorString(error));
		return false;
	}

	// Generate a random number of planets
	srand(time(0));
	int num = rand() % maxNumPlanets + minNumPlanets;

	numPlanets = num;
	planets = (planet *) malloc(numPlanets);

	for (int i = 0; i < numPlanets; i++)
	{
		planet tempPlanet(5, 15);

		planets[i] = tempPlanet;
	}

	

	return true;
}

void rotatePlanets()
{
	for (int i = 0; i < numPlanets; i++)
	{
		planets[i].angle += (360.0f / SCREEN_FPS) * (0.1f);

		// Cap angle
		if (planets[i].angle > 360.0f)
		{
			planets[i].angle -= 360.0f;
		}
	}


}

void update()
{
	rotatePlanets();
}

void render()
{
	// Clear the color buffer (pixels on the screen)
	glClear(GL_COLOR_BUFFER_BIT);

	// Pop default matrix onto current matrix
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	// Save default matrix again
	glPushMatrix();

	// Move projection view to center of screen
	glTranslatef(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f);

	/*
	 * NOTES
	 *
	 * VERTEX ORDER MATTERS
	 * You can either go in a clockwise or counterclock wise direction.
	 * For this, I go counterclockwise.
	 *
	 * This is because each vertex correlates with a face of the quad.
	 * The first and second points are one side, second and third another,
	 * third and fourth another, and fourth and first another, making
	 * 4 sides.
	 * */
	
	// Render predefined sun at center
	sun.renderPlanet();
	


	// Render surrounding planets
	for (int i = 0; i < numPlanets; i++)
	{
		// Rotate planet
		glRotatef(planets[i].angle, 0.0f, 0.0f, 1.0f);
		
		// Render planet
		if (i == 0)
		{
			planets[i].renderPlanet(0, -60);
		}
		else
		{
			planets[i].renderPlanet(0, (i+1) * (-60));
		}
	}
	
	

	/*
	 * NOTES
	 * 
	 * This program uses a double buffered window. 
	 *
	 * There are two buffers: front buffer and back buffer
	 * The front buffer is what the user sees and the back
	 * buffer is in memory.
	 *
	 * For a double buffered window:
	 * When we make render calls, all of that is rendered in the back buffer.
	 * After we're done rendering what we want to show the user, we 
	 * swap the front and back buffer. 
	 * 
	 * When there is a single window buffer,
	 * the user will see geometry as it's being rendered. 
	 * This may cause unfinished rendering and tearing.
	 *
	 * Holy fuck, I had no clue!
	 * */

	// Update GLUT buffer (our second buffer)
	glutSwapBuffers();

}

void handleKeys(unsigned char key, int x, int y)
{
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

	// Take saved matrix off the stack and reset it
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glLoadIdentity();
	
	// Move camera to position
	glTranslatef(gCameraX, gCameraY, 0.0f);

	// Save default matrix again with camera translation
	glPushMatrix();
}








