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

GLfloat  step = 0.01; // Incremental
GLuint  locTheta;
enum { CW = 0, CCW = 1};
int direction = CW;  // Direction

void _round(float & f)
{
  if(f >1)
    {
      f = -1;
    }
}

//move use the key: w s a d
void triangle_move(void)
{
    _round(thetax);
    _round(thetay);
    _round(thetaz);
    
    pretime = curtime;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);

    CxPoint p1(0,0,0);
    CxPoint p2(0,0.5,0);
    CxPoint p3(0.5,0.5,0);
    CxVector move = CxVector(thetax,thetay,thetaz);

    // move execute herea
    p1 = p1 + move;
    p2 = p2 + move;
    p3 = p3 + move;
    
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    glVertex3f(p1.x, p1.y,p1.z);
    glVertex3f(p2.x,p2.y,p2.z);
    glVertex3f(p3.x, p3.y,p3.z);
    glEnd();

    glutPostRedisplay();
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
      thetay+=0.1;
      break;
    case 's':
      thetay -=0.1;
      break;
    case 'a':
      thetax -=0.1;
      break;
    case 'd':
      thetax +=0.1;
      break;

      //reset pos key
    case 'r':
      thetax = 0;thetay = 0;thetaz = 0;
      break;
    }

   
}

//----------------------------------------------------------------------------

void mouse( int button, int state, int x, int y )
{
    if ( state == GLUT_DOWN ) {
        switch( button )
        {
        case GLUT_LEFT_BUTTON:
            direction = CCW;
	    thetay += 0.1;
            break;
        case GLUT_RIGHT_BUTTON:
            direction = CW;
	    thetay -= 0.1;
            break;
        }
    }
}


void idle( void )
{
    // Animate the rotation
  // if (direction == CW)
      // theta += step;
  // else
      //theta -= step;

    if ( theta > 360.0 ) {
      //theta -= 360.0;
    }

    glutPostRedisplay();
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
    glutDisplayFunc(triangle_move);

    glutKeyboardFunc( keyboard );
    glutMouseFunc( mouse );
    glutIdleFunc( idle );
    glutMainLoop();
 
  return 0;
}
