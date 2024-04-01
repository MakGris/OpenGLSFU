//
//  main.cpp
//  OpenGLLearn
//
//  Created by Maksim Grischenko on 21.03.2024.
//
//#include <AppKit/AppKit.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

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

void MoveAndRotation(GLFWwindow* window) 
{
    int state = glfwGetKey(window, GLFW_KEY_E);
    if (state == GLFW_PRESS)
    {
        glRotatef(1, 1, 0, 0);
        Display();
        DisplayAxis();
    }
    int state2 = glfwGetKey(window, GLFW_KEY_Q);
    if (state2 == GLFW_PRESS)
    {
        glRotatef(-1, 1, 0, 0);
        Display();
        DisplayAxis();
    }
    int state3 = glfwGetKey(window, GLFW_KEY_LEFT);
    if (state3 == GLFW_PRESS)
    {
        glRotatef(-1, 0, 1, 0);
        Display();
        DisplayAxis();
    }
    int state4 = glfwGetKey(window, GLFW_KEY_RIGHT);
    if (state4 == GLFW_PRESS)
    {
        glRotatef(1, 0, 1, 0);
        Display();
        DisplayAxis();
    }
    int state5 = glfwGetKey(window, GLFW_KEY_UP);
    if (state5 == GLFW_PRESS)
    {
        glRotatef(1, 0, 0, 1);
        Display();
        DisplayAxis();
    }
    int state6 = glfwGetKey(window, GLFW_KEY_DOWN);
    if (state6 == GLFW_PRESS)
    {
        glRotatef(-1, 0, 0, 1);
        Display();
        DisplayAxis();
    }
    int state7 = glfwGetKey(window, GLFW_KEY_Z);
    if (state7 == GLFW_PRESS)
    {
        glTranslatef(0, 0.1, 0);
        Display();
        DisplayAxis();
    }
    int state8 = glfwGetKey(window, GLFW_KEY_X);
    if (state8 == GLFW_PRESS)
    {
        glTranslatef(0, -0.1, 0);
        Display();
        DisplayAxis();
    }
    int state9 = glfwGetKey(window, GLFW_KEY_A);
    if (state9 == GLFW_PRESS)
    {
        glTranslatef(0.1, 0, 0);
        Display();
        DisplayAxis();
    }
    int state10 = glfwGetKey(window, GLFW_KEY_S);
    if (state10 == GLFW_PRESS)
    {
        glTranslatef(-0.1, 0, 0);
        Display();
        DisplayAxis();
    }
    int state11 = glfwGetKey(window, GLFW_KEY_C);
    if (state11 == GLFW_PRESS)
    {
        glTranslatef(0, 0, 0.1);
        Display();
        DisplayAxis();
    }
    int state12 = glfwGetKey(window, GLFW_KEY_V);
    if (state12 == GLFW_PRESS)
    {
        glTranslatef(0, 0, -0.1);
        Display();
        DisplayAxis();
    }
}


void Resize(int width, int height)
{
    //определение области вывода
    glViewport(0, 0, width, height);
    //установка пирамиды отсечения
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-2, 2, -1.5, 1.5, 1, 40);
    
    //настройка трансформаций для отображения тетраэдра:
    //сдвиг по оси Z, поворот на 50 градусов по оси X, поворот на 70 градусов по оси Y
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -5);
    glRotatef(10, 1, 0, 0);
    glRotatef(0, 0, 1, 0);
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "MacOS OpenGL", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    Resize(1080 , 960);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
//        Resize(1080 , 960);  закомментировал, чтобы не вызывалась в loop и не сбрасывала перемещение объекта
        Display();
        DisplayAxis();
        MoveAndRotation(window);
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
