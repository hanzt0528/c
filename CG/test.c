#include <stdio.h>
#include "inc/gObject.h"
#include "inc/gAgorithm.h"


int main()
{
  
  CxPoint p1 = CxPoint(1,2);
  CxVector v = CxVector(1,2);

  printf("v lenght = %f\n",v.length());
  //CxPoint p2 = p1 + v;
  //printf("hello c++!\n");
  //printf("p2 = p1 + v,p2 = (%f,%f,%f)\n",p2.x,p2.y,p2.z);

  //CxLine line(p1,p2);
  //float length =xLength(line);

  //printf("length = %f",length);
  
  
  //test write file
  // FILE *pf = fopen("/users/hanzhongtao/testw.txt","w");
  //fwrite("test",1,4,pf);
  //fclose(pf);
  //printf("Hello,Cmake!!\n");
  return 0;
}
