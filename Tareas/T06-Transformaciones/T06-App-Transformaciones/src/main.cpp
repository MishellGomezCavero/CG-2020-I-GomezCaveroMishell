//============================================================================
// Name        : T06-App-Transformaciones
// Alumna	   : Mishell Gomez Cavero
// Version     :
// Description :
//============================================================================

//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>
#include <glm/vec3.hpp>
#include "Utils.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

const float toRadians = 3.14159265f / 180.0f;

GLuint renderingProgram;

GLfloat* m_Vertices;
GLuint n_Vertices;
GLuint m_VBO;
GLuint m_VAO;


int dimVertices;
int numberOfVertices;
int numberOfVerticesXCircle;
int numberOfSides;

float curAngle = 0.0f;

void init (GLFWwindow* window) {


	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

	renderingProgram = Utils::createShaderProgram("src/vertShader.glsl", "src/fragShader.glsl");

// GENERACION DE PUNTOS
	GLfloat radius = 1;

	numberOfSides = 50;
	numberOfVertices = numberOfSides+2;
	GLfloat twicePi = 2.0f * M_PI;
	GLfloat onePi = 1.0f * M_PI;
	//ARREGLO DE VERTICES
	GLfloat verticesX1[numberOfVertices];
	GLfloat verticesY1[numberOfVertices];
	GLfloat verticesZ1[numberOfVertices];

	GLfloat verticesX2[numberOfVertices];
	GLfloat verticesY2[numberOfVertices];
	GLfloat verticesZ2[numberOfVertices];

	GLfloat verticesX3[numberOfVertices];
	GLfloat verticesY3[numberOfVertices];
	GLfloat verticesZ3[numberOfVertices];

	GLfloat verticesX4[numberOfVertices];
	GLfloat verticesY4[numberOfVertices];
	GLfloat verticesZ4[numberOfVertices];

	GLfloat verticesX5[numberOfVertices];
	GLfloat verticesY5[numberOfVertices];
	GLfloat verticesZ5[numberOfVertices];

	GLfloat verticesX6[numberOfVertices];
	GLfloat verticesY6[numberOfVertices];
	GLfloat verticesZ6[numberOfVertices];

	GLfloat verticesX7[numberOfVertices];
	GLfloat verticesY7[numberOfVertices];
	GLfloat verticesZ7[numberOfVertices];


	//ARREGLO DE COLOR
	GLfloat colorX1[numberOfVertices];
	GLfloat colorY1[numberOfVertices];
	GLfloat colorZ1[numberOfVertices];

	GLfloat colorX2[numberOfVertices];
	GLfloat colorY2[numberOfVertices];
	GLfloat colorZ2[numberOfVertices];

	GLfloat colorX3[numberOfVertices];
	GLfloat colorY3[numberOfVertices];
	GLfloat colorZ3[numberOfVertices];

	GLfloat colorX4[numberOfVertices];
	GLfloat colorY4[numberOfVertices];
	GLfloat colorZ4[numberOfVertices];

	GLfloat colorX5[numberOfVertices];
	GLfloat colorY5[numberOfVertices];
	GLfloat colorZ5[numberOfVertices];

	GLfloat colorX6[numberOfVertices];
	GLfloat colorY6[numberOfVertices];
	GLfloat colorZ6[numberOfVertices];

	GLfloat colorX7[numberOfVertices];
	GLfloat colorY7[numberOfVertices];
	GLfloat colorZ7[numberOfVertices];


	//PUNTO CENTRO DE LOS CIRCULOS
	GLfloat x = 0;
	GLfloat y = 0;
	GLfloat z = 0;

	//INICIALIZANDO EL PUNTO CENTRO DE LOS CIRCULOS
	verticesX1[0] = x;
	verticesY1[0] = y;
	verticesZ1[0] = z;

	verticesX2[0] = x;
	verticesY2[0] = y;
	verticesZ2[0] = z;

	verticesX3[0] = x;
	verticesY3[0] = y;
	verticesZ3[0] = z;

	verticesX4[0] = x;
	verticesY4[0] = y;
	verticesZ4[0] = z;

	verticesX5[0] = x;
	verticesY5[0] = y;
	verticesZ5[0] = z;

	verticesX6[0] = x;
	verticesY6[0] = y;
	verticesZ6[0] = z;

	verticesX7[0] = x;
	verticesY7[0] = y;
	verticesZ7[0] = z;


	numberOfVerticesXCircle = numberOfVertices*2*3;
	dimVertices =numberOfVerticesXCircle*7; // 7 CIRCULOS GENERADOS
	GLfloat m_Vertices[dimVertices];



				// BORDE DEL CIRCULO
				for (int i = 1; i < numberOfVertices; i++) {
					verticesX1[i] = x + (radius * cos(i * twicePi / numberOfSides));
					verticesY1[i] = y + (radius * sin(i * twicePi / numberOfSides));
					verticesZ1[i] = z;
					colorX1[i]=0.0f;
					colorY1[i]=0.0f;
					colorZ1[i]=0.0f;
				}


				for (int i = 0; i < numberOfVertices; i++) {
					m_Vertices[i * 6] = verticesX1[i];
					m_Vertices[i * 6 + 1] = verticesY1[i];
					m_Vertices[i * 6 + 2] = verticesZ1[i];
					m_Vertices[i * 6 + 3] = colorX1[i];
					m_Vertices[i * 6 + 4] = colorY1[i];
					m_Vertices[i * 6 + 5] = colorZ1[i];
				}

				// CIRCULO BASE BLANCO
				for (int i = 51; i < numberOfVertices+52; i++) {
					verticesX2[i] = x + ((radius-0.02) * cos(i * twicePi / numberOfSides));
					verticesY2[i] = y + ((radius-0.02) * sin(i * twicePi / numberOfSides));
					verticesZ2[i] = z;
					colorX2[i]=1.0f;
					colorY2[i]=1.0f;
					colorZ2[i]=1.0f;
				}

				for (int i = 50; i < numberOfVertices+52; i++) {
					m_Vertices[i * 6] = verticesX2[i];
					m_Vertices[i * 6 + 1] = verticesY2[i];
					m_Vertices[i * 6 + 2] = verticesZ2[i];
					m_Vertices[i * 6 + 3] = colorX2[i];
					m_Vertices[i * 6 + 4] = colorY2[i];
					m_Vertices[i * 6 + 5] = colorZ2[i];
				}

				// SEMI - CIRCULO BASE NEGRO
				for (int i = 102; i < numberOfVertices+104; i++) {
					verticesX3[i] = x + ((radius-0.02) * cos(i * onePi / (numberOfSides)));
					verticesY3[i] = y + ((radius-0.02) * sin(i * onePi / (numberOfSides)));
					verticesZ3[i] = z;
					colorX3[i]=0.0f;
					colorY3[i]=0.0f;
					colorZ3[i]=0.0f;
				}

				for (int i = 102; i < numberOfVertices+104; i++) {
					m_Vertices[i * 6] = verticesX3[i];
					m_Vertices[i * 6 + 1] = verticesY3[i];
					m_Vertices[i * 6 + 2] = verticesZ3[i];
					m_Vertices[i * 6 + 3] = colorX3[i];
					m_Vertices[i * 6 + 4] = colorY3[i];
					m_Vertices[i * 6 + 5] = colorZ3[i];
				}

				// SEMI - CIRCULO  NEGRO
				for (int i = 154; i < numberOfVertices+156; i++) {
					verticesX4[i] = 0.472 + x + ((radius-0.56 + 0.05) * cos(i * twicePi / numberOfSides));
					verticesY4[i] = 0.150 + y + ((radius-0.56 + 0.05) * sin(i * twicePi / numberOfSides));
					verticesZ4[i] = z;
					colorX4[i]=0.0f;
					colorY4[i]=0.0f;
					colorZ4[i]=0.0f;
				}

				for (int i = 154; i < numberOfVertices+156; i++) {
					m_Vertices[i * 6] = verticesX4[i];
					m_Vertices[i * 6 + 1] = verticesY4[i];
					m_Vertices[i * 6 + 2] = verticesZ4[i];

					m_Vertices[i * 6 + 3] = colorX4[i];
					m_Vertices[i * 6 + 4] = colorY4[i];
					m_Vertices[i * 6 + 5] = colorZ4[i];
				}

				//SEMI - CIRCULO BLANCO
				for (int i = 206; i < numberOfVertices+208; i++) {
					verticesX5[i] = -0.472 + x + ((radius-0.56 + 0.05) * cos(i * twicePi / (numberOfSides)));
					verticesY5[i] = -0.11 + y + ((radius-0.56 + 0.05) * sin(i * twicePi / (numberOfSides)));
					verticesZ5[i] = z;
					colorX5[i]=1.0f;
					colorY5[i]=1.0f;
					colorZ5[i]=1.0f;
				}

				for (int i = 206; i < numberOfVertices+208; i++) {
					m_Vertices[i * 6] = verticesX5[i];
					m_Vertices[i * 6 + 1] = verticesY5[i];
					m_Vertices[i * 6 + 2] = verticesZ5[i];
					m_Vertices[i * 6 + 3] = colorX5[i];
					m_Vertices[i * 6 + 4] = colorY5[i];
					m_Vertices[i * 6 + 5] = colorZ5[i];
				}
				//CIRCULO PEQUEÑO NEGRO
				for (int i = 258; i < numberOfVertices+260; i++) {
						verticesX6[i] = -0.44 + x + ((radius-0.88) * cos(i * twicePi / numberOfSides));
						verticesY6[i] = -0.08+ y + ((radius-0.88) * sin(i * twicePi / numberOfSides));
						verticesZ6[i] = z;
						colorX6[i]=0.0f;
						colorY6[i]=0.0f;
						colorZ6[i]=0.0f;
				}

				for (int i = 258; i < numberOfVertices+260; i++) {
						m_Vertices[i * 6] = verticesX6[i];
						m_Vertices[i * 6 + 1] = verticesY6[i];
						m_Vertices[i * 6 + 2] = verticesZ6[i];
						m_Vertices[i * 6 + 3] = colorX6[i];
						m_Vertices[i * 6 + 4] = colorY6[i];
						m_Vertices[i * 6 + 5] = colorZ6[i];
				}

				//CIRCULO PEQUEÑO  BLANCO
				for (int i = 310; i < numberOfVertices+312; i++) {
							verticesX7[i] = 0.48 + ((radius-0.88) * cos(i * twicePi / (numberOfSides)));
							verticesY7[i] = 0.13 + ((radius-0.88) * sin(i * twicePi / (numberOfSides)));
							verticesZ7[i] = z;
							colorX7[i]=1.0f;
							colorY7[i]=1.0f;
							colorZ7[i]=1.0f;
				}

				for (int i = 310; i < numberOfVertices+312; i++) {
							m_Vertices[i * 6] = verticesX7[i];
							m_Vertices[i * 6 + 1] = verticesY7[i];
							m_Vertices[i * 6 + 2] = verticesZ7[i];
							m_Vertices[i * 6 + 3] = colorX7[i];
							m_Vertices[i * 6 + 4] = colorY7[i];
							m_Vertices[i * 6 + 5] = colorZ7[i];
				}



	glGenBuffers(1,&m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(
			GL_ARRAY_BUFFER,
			dimVertices * sizeof(GLfloat),
			m_Vertices,
			GL_STATIC_DRAW
		);

	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		6 * sizeof(GLfloat),
		(void*) 0
	);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
				1,
				3,
				GL_FLOAT,
				GL_FALSE,
				6 * sizeof(GLfloat),
				(GLvoid*) (3 * sizeof(GLfloat))
			);

	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

void display(GLFWwindow* window, double currentTime) {
	glClear(GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(renderingProgram);

	GLuint uniformModel = glGetUniformLocation(renderingProgram, "model");

	curAngle += 3.5f; //VELOCIDAD DE 3.5 mms
	if (curAngle >= 360)
	{
		curAngle -= 360;
	}

	glm::mat4 model(1.0f);
	//GIRO HORARIO
	model = glm::rotate(model, curAngle * toRadians, glm::vec3(0.0f, 0.0f, -1.0f));

	glUniformMatrix4fv(uniformModel,1, GL_FALSE, glm::value_ptr(model));

	glBindVertexArray(m_VAO);

	int j=0;
			for(int i=0;i<7;i++){

				if(i == 0){
					glDrawArrays(GL_TRIANGLE_FAN,1, numberOfSides);
				}
				else{
					glDrawArrays(GL_TRIANGLE_FAN,j, numberOfSides);
				}
				j=j+52;
			}

	glBindVertexArray(0);
	glUseProgram(0);
}

int main(void) {
    if (!glfwInit()) {
    	exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(800, 800, "Gomez Cavero Mishell", NULL, NULL);
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {
    	exit(EXIT_FAILURE);
    }
    glfwSwapInterval(1);

    init(window);

    while (!glfwWindowShouldClose(window)) {
        display(window, glfwGetTime());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
