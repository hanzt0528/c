#pragma once
#include "math.h"
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
  float length()
  {
    float lenght = sqrt(x*x+y*y+z*z);
    return lenght;
  }
	float x;
	float y;
	float z;
};

class CxLine
{
public:
  CxLine() = default;
  CxLine(CxPoint in_p1,CxPoint in_p2){
    p1 = in_p1;
    p2 = in_p2;
  }
  CxPoint p1;
  CxPoint p2;
};

class CxTriangle
{
public:
       CxTriangle() = default;
       CxTriangle(CxPoint in_p1,CxPoint in_p2,CxPoint in_p3)
      {
	p1 = in_p1;
	p2 = in_p2;
	p3 = in_p3;
      }
  CxPoint p1;
  CxPoint p2;
  CxPoint p3;
};
