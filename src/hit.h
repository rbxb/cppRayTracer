#pragma once

#include "geometry.h"

struct hit {
	v3 surfacen, mappedn, c;
	float albedo, opacity, refraction;
};