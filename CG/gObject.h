#pragma once

// 2018.10.17
class CxPoint
{
public:
	CxPoint() = default;
	CxPoint(float in_x, float in_y, float in_z = 0)	{
		x = in_x; y = in_y; z = in_z;
	}
	float x;
	float y;
	float z;
};

class CxVector
{
public:
	CxVector() = default;
	CxVector(float in_x, float in_y, float in_z = 0) {
		x = in_x; y = in_y; z = in_z;
	}
	float x;
	float y;
	float z;
};

