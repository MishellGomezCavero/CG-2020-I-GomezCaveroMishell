//============================================================================
// Tarea 03 App Puntos
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>
GLFWwindow* ventana;

using namespace std;

GLuint VAO;
GLuint VBO;

int dimVertices;
int numberOfVertices;

void init(){

	numberOfVertices = 13;
	dimVertices = numberOfVertices*3;
	GLfloat m_Vertices[dimVertices] = {
		0.0f, 0.0f, 0.0f,	//P del centro

		0.25f, 0.25f, 0.0f, //P1 del primer cuadrante
		0.75f, 0.25f, 0.0f, //P2 del primer cuadrante
		0.75f, 0.75f, 0.0f, //P3 del primer cuadrante
		0.25f, 0.75f, 0.0f, //P4 del primer cuadrante
		0.5f, 0.5f, 0.0f, //P5 del primer cuadrante

		-0.25f, 0.25f, 0.0f, //P1 del segundo cuadrante
		-0.75f, 0.25f, 0.0f, //P2 del segundo cuadrante
		-0.75f, 0.75f, 0.0f, //P3 del segundo cuadrante

		-0.5f, -0.5f, 0.0f, //P del tercer cuadrante

		0.5f, -0.5f, 0.0f,	//P1 del cuarto cuadrante
		0.55f, -0.45f, 0.0f, //P2 del cuarto cuadrante
		0.6f, -0.4f, 0.0f, //P3 del cuarto cuadrante

	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(
			GL_ARRAY_BUFFER,
			dimVertices * sizeof(GLfloat),
			m_Vertices,
			GL_STATIC_DRAW
		);
}

void display(double currentTime) {

	float m;
		if((int) currentTime % 2 == 0) {
			m = 0.0f;
		} else {
			m =  0.3f;
		}

	glClearColor(0.5f, m , 0.3f, 0.0f);
	glClear( GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(
			0,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			(void*) 0
	);

	glPointSize(20.0f);

	glDrawArrays(GL_POINTS, 0, numberOfVertices);
	glDisableVertexAttribArray(0);
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

	init();

	while (!glfwWindowShouldClose(ventana)) {
		display(glfwGetTime());
		glfwSwapBuffers(ventana);
		glfwPollEvents();
	}

	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);

	glfwTerminate();

	return 0;
}

