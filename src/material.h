#pragma once

#include "geometry.h"
#include "canvas.h"
#include "hit.h"

class material {
public:
	virtual hit at(v2 uv) = 0;
};

class solidMaterial : public material {
public:
	solidMaterial();
	solidMaterial(v3 c_, float albedo_, float opacity_, float refraction_);
	hit at(v2 uv) override;
private:
	v3 c;
	float albedo, opacity, refraction;
};