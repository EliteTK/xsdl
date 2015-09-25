/* The MIT License (MIT)
 *
 * Copyright (c) 2015 Tomasz Kramkowski <tk@the-tk.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "xsdl.h"
#include <SDL2/SDL.h>
#include <stdbool.h>

static SDL_Window *window;
static SDL_Renderer *renderer;
static SDL_Texture *screen;

xsdl_colour_t *xsdl_buffer;
static unsigned bwidth, bheight;
static bool initialised = false;

void xsdl_init(unsigned width, unsigned height, const char *title)
{
	if (initialised)
		return;
	initialised = true;

	SDL_Init(SDL_INIT_VIDEO);
	atexit(xsdl_cleanup);

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
				  SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	screen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
				   SDL_TEXTUREACCESS_STREAMING, width, height);
	xsdl_buffer = malloc(sizeof *xsdl_buffer * width * height);

	bwidth = width;
	bheight = height;
}

void xsdl_cleanup(void)
{
	if (!initialised)
		return;
	initialised = false;

	free(xsdl_buffer);
	SDL_Quit();
}

void xsdl_draw(void)
{
	SDL_UpdateTexture(screen, NULL, xsdl_buffer,
			  bwidth * sizeof *xsdl_buffer);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, screen, NULL, NULL);
	SDL_RenderPresent(renderer);
}
