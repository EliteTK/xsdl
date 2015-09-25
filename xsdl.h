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

#ifndef _XSDL_H
#define _XSDL_H

#include <stdint.h>

typedef uint8_t xsdl_channel_t;
typedef uint32_t xsdl_colour_t;

static inline xsdl_colour_t argb8888(xsdl_channel_t a, xsdl_channel_t r,
				xsdl_channel_t g, xsdl_channel_t b)
{
	return a << 24 | r << 16 | g << 8 | b;
}

extern xsdl_colour_t *xsdl_buffer;

void xsdl_init(unsigned width, unsigned height, const char *title);
void xsdl_cleanup(void);
void xsdl_draw(void);

#endif /* _SDL_H */
