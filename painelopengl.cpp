#include "painelopengl.h"
#include <cmath>


PainelOpenGl::PainelOpenGl(QWidget *parent):
    QGLWidget(parent)
{
    setFormat(QGL::DoubleBuffer | QGL::DepthBuffer);
}
void PainelOpenGl::initializeGL(){
    glShadeModel(GL_SMOOTH);

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClearDepth(1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
void PainelOpenGl::resizeGL(int width, int height){
    double minX = 0, maxX = 10, minY = 0, maxY = 10;
    glViewport( 0, 0, (GLint)width, (GLint)height );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1,1,-1,1,1,-1);
    if (width > height)
    {
        height = height?height:1;
        double newWidth = (maxX - minX) * width / height;
        double difWidth = newWidth - (maxX - minX);
        minX = 0.0 - difWidth / 2.0;
        maxX = 10 + difWidth / 2.0;
    }
    else
    {
        width = width?width:1;
        double newHeight = (maxY - minY) * height / width;
        double difHeight = newHeight - (maxY - minY);
        minY = 0.0 - difHeight / 2.0;
        maxY = 10 + difHeight / 2.0;
    }
    glOrtho(minX, maxX, minY, maxY,1,-1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void PainelOpenGl::paintGL(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslated(5.0, 5.0, 0.0);

    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.0,5.0);
        glVertex2f(-5.0,-5.0);
        glVertex2f(5.0,-5.0);
    glEnd();
}
