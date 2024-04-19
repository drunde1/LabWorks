#include <GL/glut.h>
#include <glaux.h>
#pragma comment(lib, "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/VS/lib/x64/GLAUX.LIB")
#pragma comment (lib, "legacy_stdio_definitions.lib")
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

GLfloat objAngle, lightAngle = 0;
GLfloat objAngleDiff, lightAngleDiff = 0;
bool oPressed, lPressed = false;
GLuint list = 0, list2 = 0;

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

void init(void)
{
    glClearColor(1, 1, 0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    AUX_RGBImageRec* image = auxDIBImageLoadA("firstback.bmp"); //для загрузки в оперативную память изображения
    AUX_RGBImageRec* image1 = auxDIBImageLoadA("secback.bmp");
    AUX_RGBImageRec* image2 = auxDIBImageLoadA("thirdback.bmp");


    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    list = glGenLists(1); //генерирование одного или более незадействованных индексов. 
    glNewList(list, GL_COMPILE); //Определение дисплейного списка 
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image2->sizeX, image2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image2->data);

    // грань f0 (основание)
    glBegin(GL_POLYGON);
    glNormal3f(0, -1, 0);
    glTexCoord2f(0, 0); glVertex3f(-0.5, 0, 0.25);
    glTexCoord2f(0, 1); glVertex3f(-0.5, 0, -0.25);
    glTexCoord2f(1, 0); glVertex3f(0.5, 0, -0.25);
    glTexCoord2f(1, 1); glVertex3f(0.5, 0, 0.25);
    glEnd();

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image2->sizeX, image2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image2->data);

    // грань f1 (задняя стенка)
    glBegin(GL_POLYGON);
    glNormal3f(0, 1, -0.5);
    glTexCoord2f(0, 0); glVertex3f(0.5, 0.5, 0);
    glTexCoord2f(0, 1); glVertex3f(0.5, 0, -0.25);
    glTexCoord2f(1, 0); glVertex3f(-0.5, 0, -0.25);
    glTexCoord2f(1, 1);  glVertex3f(-0.5, 0.5, 0);
    glEnd();

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->sizeX, image->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image->data);

    // грань f2 (передняя стенка)
    glBegin(GL_POLYGON);
    glNormal3f(0, 1, 0.5);
    glTexCoord2f(0, 0); glVertex3f(-0.5, 0.5, 0);
    glTexCoord2f(0, 1); glVertex3f(-0.5, 0, 0.25);
    glTexCoord2f(1, 0); glVertex3f(0.5, 0, 0.25);
    glTexCoord2f(1, 1); glVertex3f(0.5, 0.5, 0);
    glEnd();

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image1->sizeX, image1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);

    // грань f3 (левая стенка)
    glBegin(GL_TRIANGLES);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0, 1); glVertex3f(-0.5, 0, -0.25);
    glTexCoord2f(0, 0); glVertex3f(-0.5, 0, 0.25);
    glTexCoord2f(1, 0); glVertex3f(-0.5, 0.5, 0);
    glEnd();

    // грань f4 (правая стенка)
    glBegin(GL_TRIANGLES);
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 1); glVertex3f(0.5, 0, -0.25);
    glTexCoord2f(0, 0); glVertex3f(0.5, 0.5, 0);
    glTexCoord2f(1, 0); glVertex3f(0.5, 0, 0.25);
    glEnd();
    glEndList();

    list2 = glGenLists(1); //генерирование одного или более незадействованных индексов. 
    glNewList(list2, GL_COMPILE);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(2, 0, 0);
    glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 2, 0);
    glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 2);
    glEnd();
    glEndList();
}

void myDisplay()
{
    glPushMatrix(); //Сохраняем VM = 1
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //вместе с очисткой буфера цвета предусмотреть очистку буфера глубины
    glEnable(GL_DEPTH_TEST); //включение режима удаления невидимых (проверка глубины)
    gluLookAt(0, 3, 3, 0, 0, 0, 0, 1, 0); // положение наблюдателя
    GLfloat myLightPosition[] = { 1.0, 2.0, 2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition); /*Позиция ис-точника света будет преобразована в CKe*/
    glPushMatrix(); //Сохраняем VM=Fwe
    glRotatef(lightAngle, 0, 1, 0); // вращаем источник света
    glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);

    glBegin(GL_LINES); //    Рисуем направление к источнику света в CKe
    glColor3f(1, 1, 1); glVertex3f(myLightPosition[0], myLightPosition[1], myLightPosition[2]); glVertex3f(0.0, 0.0, 0.0);
    glEnd();


    glPopMatrix(); // Восстанавливаем VM=Fwe
    glEnable(GL_LIGHTING); // Включение расчета освещенности
    glEnable(GL_LIGHT0); // включаем этот конкретный источник
    glPushMatrix(); //Сохраняем VM=Fwe
    glRotatef(objAngle, 0, 1, 0); // VM=Fwe*R


    GLfloat myDiffuse[] = { 0.4, 0.4, 0.4, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, myDiffuse);
    GLfloat myShininess[] = { 76.8 };
    glMaterialfv(GL_FRONT, GL_SHININESS, myShininess);
    GLfloat myAmbient[] = { 0.25, 0.25, 0.25, 1 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, myAmbient);
    GLfloat mySpecular[] = { 0.774597, 0.774597, 0.774597, 1 };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mySpecular);


    glCallList(list); //установка состояния, и команды рисования
    glPopMatrix(); // Восстанавливаем VM=Fwe
    glDisable(GL_LIGHTING); //Выключаем освещение
    glCallList(list2); //установка состояния, и команды рисования
    glPopMatrix();
    glutSwapBuffers();
}


void mouseButton(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL); //объект излучает свет согласно заданной текстуре
    }
    else if (button == GLUT_RIGHT_BUTTON) {
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); //объект излучет свет согласно заданной текстуре
    }
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Лаба 5");
    glutDisplayFunc(myDisplay);
    glutMouseFunc(mouseButton);
    glutKeyboardFunc(keys);
    glutReshapeFunc(myReshape);
    glutIdleFunc(myIdle);
    init();
    glutMainLoop();
}

