#pragma once

#include "geometry.h"
#include "material.h"

class object {
public:
	virtual float intersect(v3 orig, v3 dir) = 0;
	virtual hit at(v3 orig) = 0;
};