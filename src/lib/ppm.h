/*
	ppm.h - A simple library to make creating ppm images easier in C.

	Copyright (C) 2025  Madison Hanberry

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <stdio.h>

// Creates a new ppm file with the given attributes
// returns: a pointer to the created file
FILE *ppm_new (
	char* filename,	// what to name the file
	int width,		// with of the image
	int height,		// height of the image
	int color_depth	// max color value
) {
	FILE *file = fopen(filename, "w");

	fprintf(
		file,
		"P6 %d %d %d\n",
		width,
		height,
		color_depth
	);

	return file;
}

// Draws a new pixel to the give ppm file
void ppm_pixel (
	FILE *file,	// a ppm file descriptor
	char red,	// byte representation for red value
	char green,	// byte representation for green value
	char blue	// byte representation for blue value
) {
	fputc(red, file);
	fputc(green, file);
	fputc(blue, file);
}

// Closes the given ppm file (just an alias for fclose)
void ppm_close (
	FILE *file	// a ppm file descriptor
) {
	fclose(file);
}
