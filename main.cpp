#include "lutil.h"

// This file constains the driver source code
// that puts everything together for us.

// Function used to render 60 frames per second
void runMainLoop(int val);

int main(int argc, char **args)
{
	// Init FreeGLUT
	glutInit(&argc, args);

	// Create OpenGL v2.1 context (a container of sorts)
	glutInitContextVersion(2, 1);

	// Create the double buffered window
	glutInitDisplayMode(GLUT_DOUBLE);

	// Window dimensions
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	
	// Window titlebar text
	glutCreateWindow("OpenGL");

	// Post context creation initialization
	if (!initGL())
	{
		printf("Unable to initialize graphics library!\n");
		return 1;
	}
	
	// Whenever FreeGLUT needs to update the screen, call our render() function
	glutDisplayFunc(render);
	
	// After 1000/SCREEN_FPS ms, runMainLoop() will be called
	glutTimerFunc(1000 / SCREEN_FPS, runMainLoop, 0);

	// Start FreeGLUT main loop
	glutMainLoop();

	return 0;
}

void runMainLoop(int val)
{
	// Frame logic
	update();
	render();

	// Run frame one more time (Callback to run itself again)
	glutTimerFunc(1000 / SCREEN_FPS, runMainLoop, val);
}
