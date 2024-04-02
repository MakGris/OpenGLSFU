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
#include "display.h"
#include "moveAndRotate.h"

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
