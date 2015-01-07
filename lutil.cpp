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
	renderText(-300, -200, "Basic Solar System Simulation");
	renderText(-300, -180, "Press Spacebar to randomize parameters");
	
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


	// Render solar system
	ss.renderSolarSystem();

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

	// Render text
	//glColor3f(0, 0.5f, 0.5f);
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, 'H');

	// Update GLUT buffer (our second buffer)
	glutSwapBuffers();

}

void renderText(int xPos, int yPos, std::string inputText)
{
	// Position text (0, 0) = Center of screen
	glRasterPos2i(xPos, yPos);

	const unsigned char *c;
	for (int i = 0; i < inputText.size(); ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, inputText[i]);
	}
}

void handleKeys(unsigned char key, int x, int y)
{
	if (key == ' ')
	{
		ss.shuffle();
	}
}








