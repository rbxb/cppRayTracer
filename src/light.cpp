#include "light.h"

pointLight::pointLight()
{
	orig = v3{ 0,0,0 };
	color = v3{ 1,1,1 };
}

pointLight::pointLight(v3 orig_, v3 color_)
{
	orig = orig_;
	color = color_;
}

v3 pointLight::dir(v3 p)
{
	return normalize(orig - p);
}

float pointLight::d(v3 p)
{
	return mag(orig - p);
}

v3 pointLight::getColor()
{
	return color;
}

directionalLight::directionalLight()
{
	dir_ = v3{ 0,-1,0 };
	color = v3{ 1,1,1 };
}

directionalLight::directionalLight(v3 dir__, v3 color_)
{
	dir_ = normalize(dir__);
	color = color_;
}

v3 directionalLight::dir(v3 p)
{
	return dir_;
}

float directionalLight::d(v3 p)
{
	return -1;
}

v3 directionalLight::getColor()
{
	return color;
}
