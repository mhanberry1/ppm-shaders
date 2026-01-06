/*
	checkerboard - A scrolling checkerboard pattern.

	Inspired by Tsoding's "Graphics API is irrelevant" video where he showcases
	the power of the ppm format.

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

#include <ppm.h>
#include <common.h>

// Draws a checkerboard pattern that scrolls upwards and left
void checkerboard(
	FILE *ppm,	// ppm file to write to
	int i,		// current frame number
	int x,		// x value of the current point
	int y		// y value of the current point
) {
	if (((x + i) / 60 + (y + i) / 60) % 2) {
		ppm_pixel(ppm, 0xFF, 0xFF, 0xFF);
	} else {
		ppm_pixel(ppm, 0x00, 0x00, 0x00);
	}
}

int main(int argc, char **argv) {
	int width = 16 * 60;
	int height = 9 * 60;
	int color_depth = 255;
	int num_frames = common_num_frames(argc, argv, 60);

	for (int i = 0; i < num_frames; i++) {
		char filename[MAX_FILENAME_LEN];
		common_filename(filename, i, num_frames);
		FILE *ppm = ppm_new(filename, width, height, color_depth);

		common_draw_frame(ppm, checkerboard, i, width, height);

		ppm_close(ppm);
	}
}
