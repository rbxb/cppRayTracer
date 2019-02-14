#pragma once

#include "geometry.h"
#include "object.h"
#include "material.h"

class plane {
public:
	plane();
	plane(v3 a_, v3 n_);
	float intersect(v3 orig, v3 dir);
	v2 uvAt(v3 orig);
	v3 a, n;
};

class infinitePlane : public object {
public:
	infinitePlane();
	infinitePlane(v3 a, v3 n, material * mat_);
	float intersect(v3 orig, v3 dir) override;
	hit at(v3 orig) override;
private:
	plane p;
	material * mat;
};