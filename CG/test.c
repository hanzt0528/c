#include <stdio.h>
#include "gObject.h"
#include "gAgorithm.h"


int main()
{
  CxPoint p1 = CxPoint(1,2);
  CxVector v = CxVector(1,2);

  CxPoint p2 = p1 + v;
  printf("hello c++!\n");
  printf("p2 = p1 + v,p2 = (%f,%f,%f)\n",p2.x,p2.y,p2.z);
  return 0;
}
