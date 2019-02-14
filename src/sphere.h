#pragma once

#include "geometry.h"
#include "object.h"
#include "material.h"

class sphere : public object {
public:
	sphere();
	sphere(v3 a_, float radius_, material * mat_);
	float intersect(v3 orig, v3 dir) override;
	hit at(v3 orig) override;
private:
	v3 a;
	float radius;
	material * mat;
};