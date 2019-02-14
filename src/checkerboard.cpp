#include "checkerboard.h"
#include "plane.h"
#include <math.h>

checkerboardMaterial::checkerboardMaterial()
{
	side = 10;
	c1 = v3{ 0,0,0 };
	c2 = v3{ 1,1,1 };
	albedo = 0;
	opacity = 1;
	refraction = 0;
}

checkerboardMaterial::checkerboardMaterial(float side_, v3 c1_, v3 c2_, float albedo_, float opacity_, float refraction_)
{
	side = side_;
	c1 = c1_;
	c2 = c2_;
	albedo = albedo_;
	opacity = opacity_;
	refraction = refraction_;
}

hit checkerboardMaterial::at(v2 uv)
{
	int ue = abs(int(uv.x / side));
	int ve = abs(int(uv.y / side));
	bool dl = ((ue % 2 == ve % 2)) ^ ((uv.x > 0 && uv.y > 0) || (uv.x < 0 && uv.y < 0));
	return hit{
		v3{0,0,0},
		v3{0,0,1},
		dl ? c1 : c2,
		albedo,
		opacity,
		refraction,
	};
}