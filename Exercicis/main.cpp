#include <GL/glut.h>

int init(void) {

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
	return 0; 
}

void drawObject() {
	glBegin(GL_POLYGON);
	glVertex2f(110, 50);
	glVertex2f(110, 70);
	glVertex2f(100, 80);
	glVertex2f(90, 70);
	glVertex2f(90, 50);
	glEnd();
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); //Aixi la imatge es queda quieta

	//Transformations
	glRotatef(45, 0, 0, 1); //(4)
	glTranslatef(110, 50, 0); //(3)
	glScalef(2, 2, 1); //(2)
	glTranslatef(-110, -50, 0); //VA DE BAIX CAP A DALT (1)
	drawObject();
	
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(400, 400);

	glutCreateWindow("Transformations 2D");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}