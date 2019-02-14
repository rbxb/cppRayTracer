#include "plane.h"

plane::plane()
{
	a = v3{ 0,0,0 };
	n = v3{ 0,1,0 };
}

plane::plane(v3 a_, v3 n_)
{
	a = a_;
	n = n_;
}

float plane::intersect(v3 orig, v3 dir)
{
	float denom = dir * -n;
	if (denom > 0.001) {
		v3 pRel = a - orig;
		float d = pRel * -n / denom;
		if (d >= 0) {
			return d;
		}
	}
	return -1;
}

v2 plane::uvAt(v3 orig)
{
	v3 b = perpendicular(n);
	v3 c = cross(n, b);
	return uv(n, a, b, c, orig);
}

infinitePlane::infinitePlane()
{
	p = plane();
	mat = new solidMaterial();
}

infinitePlane::infinitePlane(v3 a, v3 n, material * mat_)
{
	p = plane(a, n);
	mat = mat_;
}

float infinitePlane::intersect(v3 orig, v3 dir)
{
	return p.intersect(orig, dir);
}

hit infinitePlane::at(v3 orig)
{
	hit h = mat->at(p.uvAt(orig));
	h.surfacen = p.n;
	h.mappedn = displace(h.mappedn, h.surfacen);
	return h;
}