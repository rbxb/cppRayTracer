#pragma once

#include "geometry.h"

struct color {
	char r, g, b;
	static v3 toV3(color c);
	static color toColor(v3 v);
};

class canvas {
public:
	canvas();
	canvas(size_t width_, size_t height_);
	size_t getWidth();
	size_t getHeight();
	color get(size_t x, size_t y);
	void set(size_t x, size_t y, color c);
private:
	size_t width;
	size_t height;
	char * data;
};