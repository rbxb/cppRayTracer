#include "geometry.h"
#include "object.h"
#include "canvas.h"
#include "scene.h"
#include "render.h"
#include "view.h"
#include <vector>
#include "sphere.h"
#include "plane.h"
#include "light.h"
#include "checkerboard.h"

int main() {
	view v = view{
		100,
		70,
	};
	canvas * cvs = new canvas(400, 400);
	v3 ambient = v3{ 0.32f,0.32f,0.4f };

	material * checkerboardMat = new checkerboardMaterial(1, v3{ 0.2f,0.2f,0.3f }, v3{ 1,0.9f,0.7f }, 0, 1, 0);
	material * sphereMat = new solidMaterial(v3{ 0.85f,0.9f,0.95f }, 0.5f, 1, 0);
	
	std::vector<object*> objects = {
		new infinitePlane(v3{ 0,-120,0 }, v3{ 0,1,0 }, checkerboardMat),
		new sphere(v3{ 0,20,400 }, 100, sphereMat),
	};
	std::vector<light*> lights = {
		new directionalLight(v3{0.3f,0.6f,-0.2f}, v3{1,1,1}),
	};

	scene * sn = new scene(v, objects, lights, ambient, 2000);

	render(sn, cvs, 10);

	cvs->savePPM("./ppm/out.ppm");
}