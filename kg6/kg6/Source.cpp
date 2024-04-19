#include <GL/glut.h>
#include <cmath>
#include <math.h>
#include <iostream>

using namespace std;
void init();
void draw();

GLfloat a, X1, X2, Y1, Y2, dx = 0.1, dy, check, dх;
void myReshape(int width, int height)
{
	if (height != 0 && width / height < 1) glViewport(0, 0, width, width);
	else glViewport(0, 0, height, height);
}

//Главная функция
int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	cout << "Введите координаты начальной точки\n";
	cout << "X1: ";
	cin >> X1;
	cout << "Введите коэффициент а\n";
	cout << "а: ";
	cin >> a;
	cout << "Каким способом рисовать(1 или 2)\n";
	cin >> check;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Лаба 6");
	init();
	glutDisplayFunc(draw);
	glutReshapeFunc(myReshape);
	glutMainLoop();
}
//Функция инициализации
void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}
//Функция рисования
void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glViewport(10, 10, 600, 400);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(-100.0, 0.0); glVertex2f(100.0, 0.0);
	glVertex2f(0.0, 100.0); glVertex2f(0.0, -100.0);
	glEnd();
	

	GLfloat NewX = -X1, EndY = a / (2 * X1), Y = a / (2 * NewX), Fxy = 0;
	glColor3f(0, 0, 1);
	glBegin(GL_LINE_STRIP);
	
	if (check == 1)
	{
		int i = 0;
		while (NewX <= X1) {
			glVertex2f(NewX, Y);
			if (NewX > 0 && i == 0)
			{
				Y = -Y;
				i++;
			}
			if (NewX != 0)
				Fxy = Y - a / (2 * NewX);
			if (Fxy > 0) {
				Y -= 1;
			}
			else if (Fxy < 0) {
				NewX += 1;
			}
			else {
				if (NewX > Y) NewX += 1;
				else Y -= 1;
			}
		}

		glEnd();
	}
	else
	{
		Y1 = a / (2 * X1);
		X2 = -X1;
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINE_STRIP);
		glVertex2f(X1, Y1);
		while (X2 < X1) {
			dх = a / (2 * X2 * X2);
			X2 = X2 + dx;
			Y1 = a / (2 * X2);
			glVertex2f(X2, Y1);
		}
		glEnd();
	}
	
	glFlush();
}