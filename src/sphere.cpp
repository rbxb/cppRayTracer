#include "sphere.h"
#include <math.h>

sphere::sphere()
{
	a = v3{ 0,0,0 };
	radius = 20;
	mat = new solidMaterial();
}

sphere::sphere(v3 a_, float radius_, material * mat_)
{
	a = a_;
	radius = radius_;
	mat = mat_;
}

float sphere::intersect(v3 orig, v3 dir)
{
	v3 l = a - orig;
	float tca = l * dir;
	float d2 = l * l - tca * tca;
	if (d2 > radius * radius) return -1;
	float thc = sqrtf(radius * radius - d2);
	float d = tca - thc;
	float t1 = tca + thc;
	if (d < 0) d = t1;
	if (d < 0) return -1;
	return d;
}

hit sphere::at(v3 orig)
{
	hit h = mat->at(v2());
	h.surfacen = normalize(orig - a);
	h.mappedn = displace(h.mappedn, h.surfacen);
	return h;
}