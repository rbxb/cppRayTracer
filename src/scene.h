#pragma once

#include "geometry.h"
#include "view.h"
#include "object.h"
#include "light.h"
#include <vector>

class scene {
public:
	scene();
	scene(view view_, std::vector<object*> objects_, std::vector<light*> lights_, v3 ambient_, float fogDistance_);
	view getView();
	v3 cast(v3 orig, v3 dir, char count, float retained);
	v3 lighting(v3 orig, v3 dir);
	bool simpleCast(v3 orig, v3 dir);
private:
	view v;
	std::vector<object*> objects;
	std::vector<light*> lights;
	v3 ambient;
	float fogDistance;
};