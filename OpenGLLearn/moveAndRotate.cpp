//
//  moveAndRotate.cpp
//  OpenGLLearn
//
//  Created by Maksim Grischenko on 02.04.2024.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "display.h"

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

