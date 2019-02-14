#pragma once

struct v3 {
	float x, y, z;
};

struct v2 {
	float x, y;
};

v3 operator-(const v3& a);					//inverts the vector
v3 operator+(v3 a, const v3& b);			//adds the vectors
v3 operator-(v3 a, const v3& b);			//subtracts the vectors
v3 operator*(v3 a, const float b);			//multiplies the vector by a float
v3 operator/(v3 a, const float b);			//divides the vector by a float
float operator*(const v3& a, const v3& b);	//dot product
v3 cross(const v3& a, const v3& b);			//cross product
v3 multiply(v3 a, const v3& b);				//multiplies the vectors
v3 divide(v3 a, const v3& b);				//divides the vectors
v3 normalize(const v3& a);					//normalizes the vector
float mag(const v3& a);						//magnitude of the vector
v3 reflect(const v3& a, const v3& b);		//reflects a off b
v3 refract(const v3& a, v3 b, const float& i); //refracts a in the direction of b
v3 min(v3 a, float b);						//keeps the minimum between a.d and b
v3 max(v3 a, float b);						//keeps the maximum between a.d and b
v3 pow(const v3& a, int pow);				//multiplies a to the pow power
v3 normal(v3 a, v3 b, v3 c);				//surface normal
v3 perpendicular(v3 a);						//a vector perpendicular to a
v2 uv(v3 a, v3 b, v3 c, v3 p);				//uv given plane a,b,c
v2 uv(v3 n, v3 a, v3 b, v3 c, v3 p);		//uv given plane a,b,c with normal
float fresnel(v3 dir, v3 bounce);			//returns the fresnel scaler
v3 displace(v3 a, const v3& b);