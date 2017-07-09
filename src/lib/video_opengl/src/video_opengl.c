/**
 * OpenGL module driver for HAP.
 */

#include <hap.h>

#ifdef OS_Windows
#elif OS_Linux
#include "x11.h"
#endif

#include <stdlib.h>
#include <stdio.h>

#include "window_management.h"


void* create(HAPEngine *engine) {
	(void)engine; // Mark variable as used to avoid compiler warnings

	void *window = window_create(640, 480);

	if (window == NULL) {
		fprintf(stderr, "Could not create a window.\n");
		return NULL;
	}

	return window;
}

void load(HAPEngine *engine, void *state, char *identifier) {
	(void)engine;      // Mark variable as used to avoid compiler warnings
	(void)state;       // Mark variable as used to avoid compiler warnings
	(void)identifier;  // Mark variable as used to avoid compiler warnings
}

HAPTime update(HAPEngine *engine, void *state) {
	if (window_update(state) < 0) return -1;

	window_render(state);
	return 0;
}

void unload(HAPEngine *engine, void *state) {
	(void)engine;      // Mark variable as used to avoid compiler warnings
	(void)state;       // Mark variable as used to avoid compiler warnings
}

void destroy(HAPEngine *engine, void *state) {
	(void)engine;      // Mark variable as used to avoid compiler warnings

	window_close(state);
}
