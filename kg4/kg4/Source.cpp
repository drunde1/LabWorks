#include <GL/glut.h>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

GLfloat objAngle, lightAngle = 0;
GLfloat objAngleDiff, lightAngleDiff = 0;
bool oPressed, lPressed = false;

void init(void)
{
    glClearColor(1.0, 1.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 10); // установка перспективной проекции с углом 60 градусов
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void myDisplay()
{
    glPushMatrix(); //Сохраняем VM = 1
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    gluLookAt(0, 3, 3, 0, 0, 0, 0, 1, 0); // положение наблюдателя
    GLfloat myLightPosition[] = { 1.0, 2.0, 2.0, 1.0 };

    GLfloat myDiffuse[] = { 0.4, 0.4, 0.4, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, myDiffuse);
    GLfloat myShininess[] = { 76.8 };
    glMaterialfv(GL_FRONT, GL_SHININESS, myShininess);
    GLfloat myAmbient[] = { 0.25, 0.25, 0.25, 1 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, myAmbient);
    GLfloat mySpecular[] = { 0.774597, 0.774597, 0.774597, 1 };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mySpecular);

    glEnable(GL_LIGHTING); // Включение расчета освещенности
    glEnable(GL_LIGHT0); // включаем этот конкретный источник

    glPushMatrix(); //Сохраняем VM=Fwe
    glRotatef(lightAngle, 0, 1, 0);

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(1.0, 2.0, 2.0);
    glVertex3f(0.0, 0.0, 0.0);
    glEnd();

    glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);

    glPopMatrix();


    glPushMatrix();
    glRotatef(objAngle, 0, 1, 0);

    // грань f0 (основание)
    glBegin(GL_POLYGON);
    glNormal3f(0, -1, 0);
    glVertex3f(-0.5, 0, 0.25);
    glVertex3f(-0.5, 0, -0.25);
    glVertex3f(0.5, 0, -0.25);
    glVertex3f(0.5, 0, 0.25);
    glEnd();

    // грань f1 (задняя стенка)
    glBegin(GL_POLYGON);
    glNormal3f(0, 1, -0.5);
    glVertex3f(0.5, 0, -0.25);
    glVertex3f(-0.5, 0, -0.25);
    glVertex3f(-0.5, 0.5, 0);
    glVertex3f(0.5, 0.5, 0);
    glEnd();

    // грань f2 (передняя стенка)
    glBegin(GL_POLYGON);
    glNormal3f(0, 1, 0.5);
    glVertex3f(-0.5, 0, 0.25);
    glVertex3f(0.5, 0, 0.25);
    glVertex3f(0.5, 0.5, 0);
    glVertex3f(-0.5, 0.5, 0);
    glEnd();

    // грань f4 (левая стенка)
    glBegin(GL_TRIANGLES);
    glNormal3f(-1, 0, 0);
    glVertex3f(-0.5, 0, -0.25);
    glVertex3f(-0.5, 0, 0.25);
    glVertex3f(-0.5, 0.5, 0);
    glEnd();

    // грань f5 (правая стенка)
    glBegin(GL_TRIANGLES);
    glNormal3f(1, 0, 0);
    glVertex3f(0.5, 0, -0.25);
    glVertex3f(0.5, 0.5, 0);
    glVertex3f(0.5, 0, 0.25);
    glEnd();

    glPopMatrix(); // Восстанавливаем VM=Fwe
    glDisable(GL_LIGHTING); //Выключаем освещение

    glBegin(GL_LINES); //Рисуем координатные оси разного цвета в CKe
    glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(2, 0, 0);
    glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 2, 0);
    glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 2);
    glEnd();

    glPopMatrix();
    glDisable(GL_LIGHTING);
    glutSwapBuffers();

    Sleep(1.5);
}

void myIdle()
{
    objAngle += objAngleDiff;
    if (objAngle > 360.0) objAngle = 0;

    lightAngle += lightAngleDiff;
    if (lightAngle > 360.0) lightAngle = 0;

    glutPostRedisplay();
}

void keys(unsigned char key, int x, int y) // функция реагирования на нажатие кнопок на клавиатуре
{
    if (key == 'o') {
        if (!oPressed) {
            objAngleDiff = 0.5;
            oPressed = true;
        }
        else {
            oPressed = false;
            objAngleDiff = 0;
        }
    }
    if (key == 'l') {
        if (!lPressed) {
            lightAngleDiff = 0.5;
            lPressed = true;
        }
        else {
            lPressed = false;
            lightAngleDiff = 0;
        }
    }

    if (key == 'f') {
        glCullFace(GL_BACK);
        glEnable(GL_CULL_FACE);
    }
    else if (key == 'b') {
        glCullFace(GL_FRONT);
        glEnable(GL_CULL_FACE);
    }
    else if (key != 'o' && key != 'l') {
        glDisable(GL_CULL_FACE);
    }
}

void myReshape(int width, int height)
{
    if (height != 0 && width / height < 1) glViewport(0, 0, width, width);
    else glViewport(0, 0, height, height);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); // использование RGBA, двойной буферизации и буфера глубины
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("lab 4");
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myReshape);
    glutKeyboardFunc(keys);
    glutIdleFunc(myIdle);
    init();
    glutMainLoop();
}
