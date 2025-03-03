#include <GL/glut.h>
//##include <windows..h>>  only for Windows system

int init(void) {

    glClearColor(1.0, 1.0, 1.0, 1.0); // set background color to white
    glMatrixMode(GL_PROJECTION); // set projection parameters
    gluOrtho2D(-100.0, 100.0f, -100.0f, 100.0f); // set 2D orthographic projection
    return 0;
}
void drawObject() {
    glBegin(GL_TRIANGLES); // draw primitive
    glVertex2i(50.0, -50.0); // draw point
    glVertex2i(0.0, 50.0); // draw point
    glVertex2i(-50.0, -50.0); // draw point
    glEnd(); // end drawing points

    glBegin(GL_LINE_LOOP);
    glVertex2f(-99.0, -99.0f);
    glVertex2f(99.0, -99.0f);
    glVertex2f(99.0, 99.0f);
    glVertex2f(-99.0, 99.0f);
    glEnd();
 
   
}

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT); // clear display window
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glColor3f(0.0, 0.3, 0.5); // set color to black
    //glPointSize(10.0); // set point size

    glViewport(10, 10, 200, 200);
    glColor3f(1, 0, 0);
    drawObject();
    
    glViewport(310, 10, 100, 100);
    glColor3f(0, 1, 0);
    glRotatef(90, 0, 0, 1);
    drawObject();
    glFlush(); // force execution of OpenGL commands in finite time
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // start glut
    glutInitDisplayMode(GLUT_SINGLE); // set display mode - single buffer, RGB  color
    glutInitWindowSize(500, 275); // set window size
    glutInitWindowPosition(400, 400); // set window position

    //Create the window        
    glutCreateWindow("Hello World - my first window"); // create window

    init(); // initialize
    glutDisplayFunc(display); // set display callback
    glutMainLoop(); // enter event loop


    return 0;
}