#include <stdio.h>
#include "../inc/gObject.h"
#include "../inc/gAgorithm.h"
#include <glut/glut.h>
#include "time.h"
#include <thread>

using namespace std;
time_t pretime = 0;
time_t curtime =0;
void lineSegmentOwnTest(void)
{
  std::this_thread.sleep(20);
  static float theta = 1;
  theta -= 0.01;
    pretime = curtime;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    CxPoint p1(0,0,0);
    CxPoint p2(0,0.5+theta,0);
    CxPoint p3(0.5,0.5,0);
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x,p2.y);
    glVertex2f(p3.x, p3.y);
    glEnd();

    glutPostRedisplay();
    glutSwapBuffers();
    glFlush();

    
}
int main(int argc, char * argv[])
{
  
 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("An Example");
    
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glutDisplayFunc(lineSegmentOwnTest);
    glutMainLoop();
 
  return 0;
}