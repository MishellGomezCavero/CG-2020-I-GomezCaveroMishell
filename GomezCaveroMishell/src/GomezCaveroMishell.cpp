
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>
GLFWwindow* ventana;

using namespace std;

GLuint m_VAO;
GLuint m_VBO;

void init(){

}

void display(double currentTime) {
	glClearColor(0.4f, 0.1f, 0.6f, 0.0f);
	glClear( GL_COLOR_BUFFER_BIT);
}

int main( void ){
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	ventana = glfwCreateWindow(800, 800, "Gomez Cavero Mishell", NULL, NULL);

	glfwMakeContextCurrent(ventana);

	if (glewInit() != GLEW_OK) {
		exit(EXIT_FAILURE);
	}

	glfwSetInputMode(ventana, GLFW_STICKY_KEYS, GL_TRUE);
	init();

	while (!glfwWindowShouldClose(ventana)) {
		display(glfwGetTime());

		glfwSwapBuffers(ventana);
		glfwPollEvents();
	}

	glDeleteBuffers(1, &m_VBO);
	glDeleteVertexArrays(1, &m_VAO);

	glfwTerminate();

	return 0;
}

