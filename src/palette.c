/*
 * Copyright 2016 Benjamin Winger
 * Distributed under the GNU General Public License (GPL) v2.
 */

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "image.h"
#include "palette.h"

palette_t *palette;

palette_t* palette_read(FILE *fp) {
	palette_t *palette = malloc(sizeof(struct palette_t));
	char tmp[256], *tmp2;
	palette->num_paints = 0;
	while(!feof(fp)) {
		fgets(tmp, 256, fp);
		if (strlen(tmp) <= 1) continue;
		paint_t *paint = malloc(sizeof(struct paint_t));
		paint->ch = tmp[0];
		tmp2 = strdup(tmp + 2);
		paint->rgb.r = atoi(strtok(tmp2, ","));
		paint->rgb.g = atoi(strtok(NULL, ","));
		paint->rgb.b = atoi(strtok(NULL, ","));
		free(tmp2);
		palette->paints[palette->num_paints] = paint;
		palette->num_paints++;
	}
	return palette;
}

char palette_find_closest(palette_t *palette, rgb_t *rgb) {
	char closest;
	int closest_dist = 256*3;
	for (int i = 0; i < palette->num_paints; i++) {
		paint_t *paint = palette->paints[i];
		int dist = abs(paint->rgb.r - rgb->r) + abs(paint->rgb.g - rgb->g) + abs(paint->rgb.b - rgb->b);
		if (dist < closest_dist) {
			closest_dist = dist;
			closest = paint->ch;
		}
	}
	return closest;
}

void palette_destroy(palette_t *palette) {
	if (palette == NULL) return;
	for (int i = 0; i < palette->num_paints; i++) {
		free(palette->paints[i]);
	}
	free(palette);
}
