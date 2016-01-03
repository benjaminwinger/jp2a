/*
 * Copyright 2016 Benjamin Winger
 * Distributed under the GNU General Public License (GPL) v2.
 */

// see palette.c
typedef struct paint_t {
	char ch;
	rgb_t rgb;
} paint_t;

#define MAX_PAINTS 256

typedef struct palette_t {
	paint_t * paints[MAX_PAINTS];
	int num_paints;
} palette_t;

extern palette_t *palette;

palette_t* palette_read(FILE *fp);
void palette_destroy(palette_t *palette);
char palette_find_closest(palette_t *palette, rgb_t *rgb);
