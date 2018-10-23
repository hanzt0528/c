#pragma once
// 2018.10.17
#include "gObject.h"
#include "math.h"

CxVector  operator+(const CxVector &o1, const CxVector &o2)
{
	CxVector v;

	v.x = o1.x + o2.x;
	v.y = o1.y + o2.y;
	v.z = o1.z + o2.z;

	return v;
}

CxPoint  operator+ (const CxPoint &p, const CxVector &v)
{
	CxPoint pt;
	pt.x = p.x + v.x;
	pt.y = p.y + v.y;
	pt.z = p.z + v.z;
	return pt;
}

CxPoint operator- (const CxPoint &p, const CxVector &v)
{
	CxPoint pt;
	pt.x = p.x - v.x;
	pt.y = p.y - v.y;
	pt.z = p.z - v.z;
	return pt;
}

bool operator==(const CxPoint &o1, const CxPoint &o2)
{
	return ((o1.x == o2.x) && (o1.y == o2.y) && (o1.z == o2.z)) ? true : false;
}

bool operator!=(const CxPoint &o1, const CxPoint &o2)
{
	return (o1 == o2) ? false : true;
}


bool operator==(const CxVector &o1, const CxVector &o2)
{
	return ((o1.x == o2.x) && (o1.y == o2.y) && (o1.z == o2.z)) ? true : false;
}


bool operator!=(const CxVector &o1, const CxVector &o2)
{
	return (o1 == o2) ? false : true;
}

float xLength(CxLine l)
{
 float length = sqrt( (l.p2.x - l.p1.x)*(l.p2.x - l.p1.x) + (l.p2.y - l.p1.y)*(l.p2.y - l.p1.y)+(l.p2.z - l.p1.z)*(l.p2.z - l.p1.z) );
 return length;
}
