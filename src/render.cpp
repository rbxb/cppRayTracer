#include "render.h"
#include <math.h>

void render(scene * sn, canvas * cvs, const char bounceCount)
{
	view v = sn->getView();
	v3 orig = v3{ 0,0,0 };
	float cw, ch, vw, vh, d, x, y, z;
	cw = float(cvs->getWidth());
	ch = float(cvs->getHeight());
	vw = v.width;
	vh = vw / cw * ch;
	d = (vw / 2) / tanf(v.fov / 2);
	z = d;
	for (size_t cy = 0; cy < cvs->getHeight(); cy++) {
		y = -(cy / ch * vh - (vw / 2));
		for (size_t cx = 0; cx < cvs->getWidth(); cx++) {
			x = cx / cw * vw - (vw / 2);
			v3 dir = normalize(v3{ x,y,z });
			v3 clr = sn->cast(orig, dir, bounceCount, 1);
			cvs->set(cx, cy, color::toColor(clr));
		}
	}
}
