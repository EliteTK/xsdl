#include "xsdl.h"
#include <unistd.h>

const unsigned width = 100;
const unsigned height = 100;

int main(void)
{
	xsdl_init(width, height, "Example!");

	for (unsigned y = 0; y < height; y++)
		for (unsigned x = 0; x < width; x++)
			xsdl_buffer[x + width * y] = argb8888(255, x, y, 100);

	xsdl_draw();

	sleep(2);

	xsdl_cleanup();

	return 0;
}
