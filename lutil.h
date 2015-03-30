/*
 *
 * LUtil will hold the initialization and
 * main loop functions
 *
 * */

#ifndef LUTIL_H
#define LUTIL_H

#include "lopengl.h"
#include "planet.h"
#include "solarsystem.h"

#include <stdio.h>
#include <string>

// Screen constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 60;

// Initialized GLEW, DevIL, textures
bool loadMedia();

// Initializes the graphics library
bool initGL();

// Main logic that will update per frame
void update();

// Renders the scene
void render();

// Renders text to the scene
void renderText(int xPos, int yPos, std::string inputText);

// Function that changes color modes and camera projection with 'q' and 'e'
void handleKeys(unsigned char key, int x, int y);

#endif
