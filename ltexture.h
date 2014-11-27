#ifndef LTEXTURE_H
#define LTEXTURE_H

#include "lopengl.h"
#include <stdio.h>

class ltexture
{
	public:
		ltexture();
		~ltexture();

		// Load texture file
		bool loadTextureFromPixels32(GLuint *pixels, GLuint width, GLuint height);

		// Clear texture if it exists
		void freeTexture();
	
		// Translates to a given position and renders textured quad
		void render(GLfloat x, GLfloat y);

		GLuint getTextureID();

		GLuint textureWidth();

		GLuint textureHeight();
	
	private:
		// Texture name
		GLuint mTextureID;

		// Texture dimentions
		GLuint mTextureWidth;
		GLuint mTextureHeight;
}
