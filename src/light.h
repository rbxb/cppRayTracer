#pragma once

#include "geometry.h"

class light {
public:
	virtual v3 dir(v3 p) = 0;
	virtual v3 getColor() = 0;
};

class pointLight : public light {
public:
	pointLight();
	pointLight(v3 orig_, v3 color_);
	v3 dir(v3 p) override;
	v3 getColor() override;
private:
	v3 orig;
	v3 color;
};

class directionalLight : public light {
public:
	directionalLight();
	directionalLight(v3 dir__, v3 color_);
	v3 dir(v3 p) override;
	v3 getColor() override;
private:
	v3 dir_;
	v3 color;
};