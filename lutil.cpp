#include "lutil.h"

// Current color rendering mode
int gColorMode = COLOR_MODE_CYAN;

// The projection scale
GLfloat gProjectionScale = 1.0f;

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
	
	// Initialize projection matrix
	glMatrixMode(GL_PROJECTION);

	// Loads identity matrix into current matrix
	glLoadIdentity();

	// Multiplies the current matrix against an ortho perspectice matrix
	// with the left, right, bottom, top, near, and far values in the arguments.
	glOrtho(0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 1.0f, -1.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

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

void update()
{

}

void render()
{
	// Clear the color buffer (pixels on the screen)
	glClear(GL_COLOR_BUFFER_BIT);

	// Reset modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

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
	
	if (gColorMode == COLOR_MODE_CYAN)
	{
		glBegin(GL_POLYGON);
			glColor3f(0.0f, 1.0f, 1.0f);
			glVertex2f(-50.0f, 0.0f);
			glVertex2f(-25.0f, -50.0f);
			glVertex2f(25.0f, -50.0f);
			glVertex2f(50.0f, 0.0f);
			glVertex2f(25.0f, 50.0f);
			glVertex2f(-25.0f, 50.0f);
		glEnd();
	}
	else
	{
		glBegin(GL_POLYGON);
			glVertex2f(-50.0f, 0.0f); glColor3f(1.0f, 1.0f, 1.0f);
			glVertex2f(-25.0f, -50.0f); glColor3f(0.0f, 0.0f, 1.0f);
			glVertex2f(25.0f, -50.0f); glColor3f(0.0f, 1.0f, 0.0f);
			glVertex2f(50.0f, 0.0f); glColor3f(0.0f, 1.0f, 1.0f);
			glVertex2f(25.0f, 50.0f); glColor3f(1.0f, 0.0f, 0.0f);
			glVertex2f(-25.0f, 50.0f); glColor3f(1.0f, 0.0f, 1.0f);
		glEnd();
	}

	/*
	if (gColorMode == COLOR_MODE_CYAN)
	{
		glBegin(GL_QUADS);
			glColor3f(0.0f, 1.0f, 1.0f);
			glVertex2f(-50.0f, -50.0f);
			glVertex2f(50.0f, -50.0f);
			glVertex2f(50.0f, 50.0f);
			glVertex2f(-50.0f, 50.0f);
		glEnd();
	}
	else
	{
		glBegin(GL_QUADS);
			glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(-50.0f, -50.0f);
			glColor3f(1.0f, 1.0f, 0.0f); glVertex2f(50.0f, -50.0f);
			glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(50.0f, 50.0f);
			glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(-50.0f, 50.0f);
		glEnd();
	}
	*/
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
	if (key == 'q')
	{
		// Toggle color more
		if (gColorMode == COLOR_MODE_CYAN)
		{
			gColorMode = COLOR_MODE_MULTI;
		}
		else
		{
			gColorMode = COLOR_MODE_CYAN;
		}
	}
	else if (key == 'e')
	{
		// Cycle through projection scales
		if (gProjectionScale == 1.0f)
		{
			// Zoom out
			gProjectionScale = 2.0f;
		}
		else if (gProjectionScale == 2.0f)
		{
			// Zoom in
			gProjectionScale = 0.5f;
		}
		else if (gProjectionScale == 0.5f)
		{
			// Regular zoom
			gProjectionScale = 1.0f;
		}

		// Update projection matrix changes
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0f, SCREEN_WIDTH * gProjectionScale, SCREEN_HEIGHT * gProjectionScale, 0.0f, 1.0f, -1.0f);
	}
}








