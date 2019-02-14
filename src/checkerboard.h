#pragma once

#include "geometry.h"
#include "material.h"

class checkerboardMaterial : public material {
public:
	checkerboardMaterial();
	checkerboardMaterial(float side_, v3 c1_, v3 c2_, float albedo_, float opacity_, float refraction_);
	hit at(v2 uv) override;
private:
	float side, albedo, opacity, refraction;
	v3 c1, c2;
};