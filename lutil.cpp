#include "lutil.h"
#include <IL/il.h>
#include <IL/ilu.h>
#include <ft2build.h>
#include <string>
#include FT_FREETYPE_H

// Camera position
GLfloat gCameraX = 0.0f, gCameraY = 0.0f;

// Solar System
solarsystem ss(1, 3);

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
	
	// Initialize FreeType lib (For text rendering)
	int fontError;
	FT_Library library;
	if (FT_Init_FreeType(&library))
	{
		printf("Error with FreeType!\n");
		return false;
	}

	FT_Face face;
	fontError = FT_New_Face(library, "dos_font.ttf", 0, &face);
	if (fontError == FT_Err_Unknown_File_Format)
	{
		printf("Unknown file format for font ya goober\n");
	}
	else if (fontError)
	{
		printf("Error opening font!\n");
	}

	// Initialize GLEW
	GLenum glewError = glewInit();
	if (glewError != GLEW_OK)
	{
		printf("Error with GLEW! %s\n", glewGetErrorString(glewError));

		return false;
	}

	// Make sure current GL version (2.1) is supported
	if (!GLEW_VERSION_2_1)
	{
		printf("OpenGL 2.1 is not supported!\n");
		return false;
	}

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

	// Initialize DevIL and DeviILU
	ilInit();
	iluInit();
	ilClearColour(255, 255, 255, 000);

	// Check for DevIL errors
	ILenum ilError = ilGetError();
	if (ilError != IL_NO_ERROR)
	{
		printf("Error initializing DevIL! %s\n", iluErrorString(ilError));

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








