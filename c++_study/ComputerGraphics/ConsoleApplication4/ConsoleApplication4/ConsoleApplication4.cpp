﻿#include <gl/glut.h>  // GLUT, include glu.h and gl.h
#include <windows.h>



// Global variable
GLfloat angle = 0.0f;  // Current rotational angle of the shapes
int refreshMills = 30; // refresh interval in milliseconds

/* Initialize OpenGL Graphics */
void initGL()
{
	// Set "clearing" or background color
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Black and opaque
}


/* Called back when there is no other event to be handled */
void idle()
{
	glutPostRedisplay();   // Post a re-paint request to activate display()
}



/* Called back when timer expired */
void Timer(int value) {
	glutPostRedisplay();      // Post re-paint request to activate display()
	glutTimerFunc(refreshMills, Timer, 0); // next Timer call milliseconds later
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
	glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
	glLoadIdentity();

	// Reset the model-view matrix
	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(-0.5f, 0.4f, 0.0f);     // Translate
	glRotatef(angle, 0.0f, 0.0f, -1.0f); // rotate by angle in degrees
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f); // Green
	glVertex2f(-0.13f, -0.2f);
	glVertex2f(0.13f, -0.2f);
	glVertex2f(0.2f, 0.0f);
	glVertex2f(0.13f, 0.2f);
	glVertex2f(-0.13f, 0.2f);
	glVertex2f(-0.2f, 0.0f);
	glEnd();
	glPopMatrix();


	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(0.5f, 0.4f, 0.0f);     // Translate
	glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f); // Black
	glVertex2f(-0.13f, -0.2f);
	glVertex2f(0.13f, -0.2f);
	glVertex2f(0.2f, 0.0f);
	glVertex2f(0.13f, 0.2f);
	glVertex2f(-0.13f, 0.2f);
	glVertex2f(-0.2f, 0.0f);
	glEnd();
	glPopMatrix();


	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(-0.5f, -0.5f, 0.5f);     // Translate
	glRotatef(angle, 1.0f, 0.0f, 0.0f); // rotate by angle in degrees
	glTranslatef(0.0f, 0.2f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(-0.13f, -0.2f);
	glVertex2f(0.13f, -0.2f);
	glVertex2f(0.2f, 0.0f);
	glVertex2f(0.13f, 0.2f);
	glVertex2f(-0.13f, 0.2f);
	glVertex2f(-0.2f, 0.0f);
	glEnd();
	glPopMatrix();


	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(0.5f, -0.5f, 0.5f);     // Translate
	glRotatef(angle, 1.0f, 1.0f, 1.0f); // rotate by angle in degrees
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex2f(-0.13f, -0.2f);
	glVertex2f(0.13f, -0.2f);
	glVertex2f(0.2f, 0.0f);
	glVertex2f(0.13f, 0.2f);
	glVertex2f(-0.13f, 0.2f);
	glVertex2f(-0.2f, 0.0f);
	glEnd();
	glPopMatrix();                      // Restore the model-view matrix

	glutSwapBuffers();   // Double buffered - swap the front and back buffers

	// Change the rotational angle after each display()
	angle += 3.0f;
}



/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height)
{
	// GLsizei for non-negative integer
	// Compute aspect ratio of the new window
	if (height == 0)
		height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping area to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();
	if (width >= height)
		gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
	else
		gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);          // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE);  // Enable double buffered mode
	glutInitWindowSize(640, 480);   // Set the window's initial width & height - non-square
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutCreateWindow("Hexagons");  // Create window with the given title
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	glutReshapeFunc(reshape);       // Register callback handler for window re-size event
	glutTimerFunc(0, Timer, 0);             // Register callback handler if no other event
	initGL();                       // Our own OpenGL initialization
	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;
}