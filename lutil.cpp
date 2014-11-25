#include "lutil.h"

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

	// Render a simple quad
	glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);
	glEnd();

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



