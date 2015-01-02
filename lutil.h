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

// Planet information

const float minRotationSpeed = 1.0f;
const float maxRotationSpeed = 0.1f;

// Initialized GLEW, DevIL, textures
bool loadMedia();

// Initializes the graphics library
bool initGL();

// Main logic that will update per frame
void update();

// Renders the scene
void render();

// Function that changes color modes and camera projection with 'q' and 'e'
void handleKeys(unsigned char key, int x, int y);

#endif
