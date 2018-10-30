#include <stdio.h>
#include "../../inc/gObject.h"
#include "../../inc/gAgorithm.h"
#include <glut/glut.h>
#include "time.h"
#include <thread>

using namespace std;
time_t pretime = 0;
time_t curtime =0;
float thetax = 0;
float thetay = 0;
float thetaz = 0;
float theta = 0;

CxPoint originPoint = CxPoint(0,0,0);

GLfloat  step = 10.0; // Incremental
GLuint  locTheta;
enum { CW = 0, CCW = 1};
int direction = CW;  // Direction

void _round(float & f)
{
  if(f >360)
    {
      f = -360;
    }
}

//矢量axis必须是已经单位化的且经过原点
CxPoint _sp_rotate(CxPoint src,CxVector axis,float angle)
{
  float x = axis.x;
  float y = axis.y;
  float z = axis.z;
  float c = cos(angle*3.14/180);
  float s = sin(angle*3.14/180);

  float old_x = src.x;
  float old_y = src.y;
  float old_z = src.z;
  
  float new_x = (x*x*(1-c)+c)*old_x + (x*y*(1-c)-z*s) * old_y + (x*z*(1-c)+y*s) * old_z;

  float new_y = (y*x*(1-c)+z*s)*old_x + (y*y*(1-c)+c) * old_y + (y*z*(1-c)-x*s) * old_z;

  float new_z = (x*z*(1-c)-y*s) * old_x + (y*z*(1-c)+x*s) * old_y + (z*z*(1-c)+c) * old_z;

  return CxPoint(new_x,new_y,new_z);
}

//rotate use the key: w s a d
void display(void)
{
  //_round(thetax);
  //_round(thetay);
  //_round(thetaz);
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);

    CxPoint p1(0,0,0);
    CxPoint p2(0,0.5,0);
    CxPoint p3(0.5,0.5,0);

   
    // rotate by z
    //_rotate_by_z_axis(p1,thetax);
    //_rotate_by_z_axis(p2,thetax);
    //_rotate_by_z_axis(p3,thetax);

    //rotate by x
    //_rotate_by_x_axis(p1,thetax);
    //_rotate_by_x_axis(p2,thetax);
    //_rotate_by_x_axis(p3,thetax);


    //rotate by y
    //_rotate_by_y_axis(p1,thetax);
    //_rotate_by_y_axis(p2,thetax);
    //_rotate_by_y_axis(p3,thetax);
    CxVector axis(1,1,1);
    p1 = _sp_rotate(p1,axis,thetax);
    p2 = _sp_rotate(p2,axis,thetax);
    p3 = _sp_rotate(p3,axis,thetax);
   
    //glLoadIdentity();
    //glRotatef(thetax, 1, 1, 1);
    printf("thetax = %f\n",thetax);
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    glVertex3f(p1.x, p1.y,p1.z);
    glVertex3f(p2.x,p2.y,p2.z);
    glVertex3f(p3.x, p3.y,p3.z);
    glEnd();

    glutSwapBuffers();
    glFlush();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

//----------------------------------------------------------------------------

void keyboard( unsigned char key, int x, int y )
{
  //printf("%c",key);
    switch( key ) {
    case 033: // Escape Key
    case 'q': case 'Q':
        exit( EXIT_SUCCESS );
        break;

	// move key
    case 'w':
      thetay+=step;
      break;
    case 's':
      thetay -=step;
      break;
    case 'a':
      thetax +=step;
      break;
    case 'd':
      thetax -=step;
      break;

      //reset pos key
    case 'r':
      thetax = 0;thetay = 0;thetaz = 0;
      break;
    }

   
}

//----------------------------------------------------------------------------




void idle( void )
{


    if ( theta > 360.0 ) {
      theta -= 360.0;
    }

    glutPostRedisplay();
}


int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(400, 400);
    glutCreaeWindow("An Example");
    
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glutDisplayFunc(display);

    glutKeyboardFunc( keyboard );
    glutMouseFunc( mouse );
    glutIdleFunc( idle );
    glutMainLoop();
 
  return 0;
}
