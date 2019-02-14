#include "material.h"

solidMaterial::solidMaterial()
{
	c = v3{ 1,1,1 };
	albedo = 0;
	opacity = 1;
	refraction = 0;
}

solidMaterial::solidMaterial(v3 c_, float albedo_, float opacity_, float refraction_)
{
	c = c_;
	albedo = albedo_;
	opacity = opacity_;
	refraction = refraction_;
}

hit solidMaterial::at(v2 uv)
{
	return hit{
		v3{0,0,0},
		v3{0,0,1},
		c,
		albedo,
		opacity,
		refraction,
	};
}
