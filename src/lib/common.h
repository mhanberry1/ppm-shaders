/*
	common.h - functions that are used throughout the ppm-shaders project.

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

#include <string.h>

#define MAX_FILENAME_LEN 256

typedef void (*draw_func)(FILE *, int, int, int);

// Determines the number of frames to generate based on commandline arguments
// returns: the number of frames
int common_num_frames (
	int argc, 		// the number of commandline arguments
	char **argv,	// commandline arguments
	int num_frames	// the number of frames to generate if generating a video
) {
	if (argc == 1) return 1;
	if (strncmp(argv[1], "--video", 8) != 0) return 1;

	return num_frames;
}

// Creates a filename based on the current frame number
// returns: a filename
char *common_filename (
	char *filename,		// pointer to the filename string
	int i,				// the current frame number
	int num_frames		// the total number of frames
) {
	char *pattern = (num_frames == 1)
		? "output.ppm"
		: "output-%03d.ppm";

	snprintf(filename, MAX_FILENAME_LEN, pattern, i);

	return filename;
}

// Draws a frame to the given ppm file using the given draw function
void common_draw_frame (
	FILE *ppm,		// ppm file to write to
	draw_func draw,	// function used to draw the frame
	int i,			// current frame number
	int width,		// width of the frame
	int height		// height of the frame
) {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < width; y++) {
			draw(ppm, i, x, y);
		}
	}
}
