#include "canvas.h"
#include <fstream>
#include <algorithm>

v3 color::toV3(color c)
{
	return v3{
		c.r / 255.0f,
		c.g / 255.0f,
		c.b / 255.0f,
	};
}

color color::toColor(v3 v)
{
	v = v * 255.0f;
	return color{
		char(std::min(int(v.x), 255)),
		char(std::min(int(v.y), 255)),
		char(std::min(int(v.z), 255)),
	};
}

canvas::canvas()
{
	width = 100;
	height = 100;
	data = new char[width * height * 3];
}

canvas::canvas(size_t width_, size_t height_)
{
	width = width_;
	height = height_;
	data = new char[width * height * 3];
}

size_t canvas::getWidth()
{
	return width;
}

size_t canvas::getHeight()
{
	return height;
}

color canvas::get(size_t x, size_t y)
{
	size_t p = (y * width + x) * 3;
	return color{
		data[p + 0],
		data[p + 1],
		data[p + 2],
	};
}

void canvas::set(size_t x, size_t y, color c)
{
	size_t p = (y * width + x) * 3;
	data[p + 0] = c.r;
	data[p + 1] = c.g;
	data[p + 2] = c.b;
}

void canvas::savePPM(char * path)
{
	std::ofstream ofs;
	ofs.open(path, std::ios::binary);
	ofs << "P6\n" << width << " " << height << "\n255\n";
	for (size_t y = 0; y < height; y++) {
		for (size_t x = 0; x < width; x++) {
			color c = get(x, y);
			ofs << c.r << c.g << c.b;
		}
	}
	ofs.close();
}
