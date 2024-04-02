//
//  display.cpp
//  OpenGLLearn
//
//  Created by Maksim Grischenko on 02.04.2024.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void Display()
{
    //очистка фреймбуфера
    glClear(GL_COLOR_BUFFER_BIT);

    //прорисовка "пола" в виде сетки
    //glColor3f(1.0, 1.0, 1.0);
    
    //X-axis grid
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    for (GLfloat i = -2.5; i <= 2.5; i += 0.25) {
        glVertex3f(i, 0, 2.5); glVertex3f(i, 0, -2.5);
        glVertex3f(2.5, 0, i); glVertex3f(-2.5, 0, i);
    }
    
    //Y-axis grid
    glColor3f(1.0, 0.0, 0.0);
    for (GLfloat i = 0; i <= 2.5; i += 0.25) {
        glVertex3f(2.5, i, 0); glVertex3f(-2.5, i, 0);
    }
    for (GLfloat i = -2.5; i <= 2.5; i += 0.25) {
        glVertex3f(i, 0, 0); glVertex3f(i, 2.5, 0);
    }
    
    //Z-axis grid
    glColor3f(0.0, 1.0, 0.0);
    for (GLfloat i = 0; i <= 2.5; i += 0.25) {
        glVertex3f(0, i, -2.5); glVertex3f(0, i, 2.5);
    }
    for (GLfloat i = -2.5; i <= 2.5; i += 0.25) {
        glVertex3f(0, 0, i); glVertex3f(0, 2.5, i);
    }
   
    glEnd();

    //прорисовка тетраэдра при помощи ленты из треугольников
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(1, 1, 1); glVertex3f(0, 2, 0);
        glColor3f(1, 0, 0); glVertex3f(-1, 0, 1);
        glColor3f(0, 1, 0); glVertex3f(1, 0, 1);
        glColor3f(0, 0, 1); glVertex3f(0, 0, -1.4);
        glColor3f(1, 1, 1); glVertex3f(0, 2, 0);
        glColor3f(1, 0, 0); glVertex3f(-1, 0, 1);
    glEnd();

    
    //прорисовка всех команд из буфера команд OpenGL
    glFlush();
}

void DisplayAxis()
{
    //X-axis
    glBegin(GL_LINES);
    glColor3f(0, 0, 1.0);
    glVertex3f(0, 0, 0); glVertex3f(5, 0, 0);
    
    //Y-axis
    glColor3f(1.0, 0, 0);
    glVertex3f(0, 0, 0); glVertex3f(0, 5, 0);
    
    //Z-axis
    glColor3f(0, 1.0, 0);
    glVertex3f(0, 0, 0); glVertex3f(0, 0, 5);
    glEnd();
    
    //Axis arrows
    glBegin(GL_TRIANGLES);
    //X-axis arrow
    glColor3f(0, 0, 1);
    glVertex3f(5, 0.1, 0);
    glVertex3f(5, -0.1, 0);
    glVertex3f(5.3, 0, 0);
   
    //Y-axis arrow
    glColor3f(1, 0, 0);
    glVertex3f( 0.1,5, 0);
    glVertex3f(-0.1,5, 0);
    glVertex3f(0.0,5.3,0.0);
    
    //Z-axis arrow
    glColor3f(0, 1, 0);
    glVertex3f( 0,0.1, 5);
    glVertex3f(0,-0.1, 5);
    glVertex3f(0.0,0,5.3);
    glEnd();
}
