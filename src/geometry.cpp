#include "geometry.h"
#include <math.h>
#include <algorithm>

v3 operator-(const v3 & a)
{
	return a * -1.0f;
}

v3 operator+(v3 a, const v3 & b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}

v3 operator-(v3 a, const v3 & b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}

v3 operator*(v3 a, const float b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
	return a;
}

v3 operator/(v3 a, const float b)
{
	a.x /= b;
	a.y /= b;
	a.z /= b;
	return a;
}

float operator*(const v3 & a, const v3 & b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

v3 cross(const v3 & a, const v3 & b)
{
	return v3{
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x,
	};
}

v3 multiply(v3 a, const v3 & b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return a;
}

v3 divide(v3 a, const v3 & b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	return a;
}

v3 normalize(const v3 & a)
{
	return a / mag(a);
}

float mag(const v3 & a)
{
	return sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
}

v3 reflect(const v3 & a, const v3 & b)
{
	return a - b * 2.0f * (a * b);
}

v3 refract(const v3 & a, v3 b, const float & i)
{
	return a;
}

v3 min(v3 a, float b)
{
	a.x = std::min(a.x, b);
	a.y = std::min(a.y, b);
	a.z = std::min(a.z, b);
	return a;
}

v3 max(v3 a, float b)
{
	a.x = std::max(a.x, b);
	a.y = std::max(a.y, b);
	a.z = std::max(a.z, b);
	return a;
}

v3 pow(const v3& a, int pow)
{
	v3 r = a;
	for (; pow > 0; pow--) {
		r = multiply(r, a);
	}
	return r;
}

v3 normal(v3 a, v3 b, v3 c)
{
	v3 ab = b - a;
	v3 ac = c - a;
	return normalize(cross(ab, ac));
}

v3 perpendicular(v3 a)
{
	v3 b = v3{ 1,0,0 };
	if (a * b > 0.99f) {
		b = v3{ 0,1,0 };
	}
	return cross(a, b);
}

v2 uv(v3 a, v3 b, v3 c, v3 p)
{
	v3 n = normal(a, b, c);
	return uv(n, a, b, c, p);
}

v2 uv(v3 n, v3 a, v3 b, v3 c, v3 p)
{
	v3 u = normalize(b - a);
	v3 v = cross(u, n);
	p = p - a;
	return v2{ u * p, v * p};
}

float fresnel(v3 dir, v3 bounce)
{
	return (dir * bounce + 1) / 2;
}

v3 displace(v3 a, const v3 & b)
{
	return b;
}
