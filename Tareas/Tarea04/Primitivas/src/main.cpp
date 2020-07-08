// TAREA 04

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
// glm
#include <glm/vec3.hpp>
GLuint renderingProgram;

GLfloat* m_Vertices;
GLuint m_VBO;
GLuint m_VAO;

using namespace std;


void printShaderLog(GLuint shader) {
    int len = 0;
    int chWrittn = 0;
    char* log;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
    if (len > 0) {
        log = (char*)malloc(len);
        glGetShaderInfoLog(shader, len, &chWrittn, log);
        cout << "Shader Info Log: " << log << endl;
        free(log);
    }
}

void printProgramLog(int prog) {
    int len = 0;
    int chWrittn = 0;
    char* log;
    glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
    if (len > 0) {
        log = (char*)malloc(len);
        glGetProgramInfoLog(prog, len, &chWrittn, log);
        cout << "Program Info Log: " << log << endl;
        free(log);
    }
}

bool checkOpenGLError() {
    bool foundError = false;
    int glErr = glGetError();
    while (glErr != GL_NO_ERROR) {
        cout << "glError: " << glErr << endl;
        foundError = true;
        glErr = glGetError();
    }
    return foundError;
}

string readShaderSource(const char *filePath) {
    string content = "";
    ifstream fileStream(filePath, ios::in);

    string line = "";
    while (!fileStream.eof()) {
        getline(fileStream, line);
        content.append(line + "\n");
    }
    fileStream.close();
    return content;
}

GLuint createShaderProgram() {
    GLint vertCompiled;
    GLint fragCompiled;
    GLint linked;

    string vertShaderStr = readShaderSource("src/vertShader.glsl");
    string fragShaderStr = readShaderSource("src/fragShader.glsl");

    const char* vertShaderSrc = vertShaderStr.c_str();
    const char* fragShaderSrc = fragShaderStr.c_str();

    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vShader, 1, &vertShaderSrc, NULL);
    glShaderSource(fShader, 1, &fragShaderSrc, NULL);

    glCompileShader(vShader);
    checkOpenGLError();
    glGetShaderiv(vShader, GL_COMPILE_STATUS, &vertCompiled);
    if (vertCompiled != 1) {
        cout << "vertex compilation failed" << endl;
        printShaderLog(vShader);
    }

    glCompileShader(fShader);
    checkOpenGLError();
    glGetShaderiv(fShader, GL_COMPILE_STATUS, &fragCompiled);
    if (fragCompiled != 1) {
        cout << "fragment compilation failed" << endl;
        printShaderLog(fShader);
    }

    GLuint vfProgram = glCreateProgram();
    glAttachShader(vfProgram, vShader);
    glAttachShader(vfProgram, fShader);

    glLinkProgram(vfProgram);
    checkOpenGLError();
    glGetProgramiv(vfProgram, GL_LINK_STATUS, &linked);
    if (linked != 1) {
        cout << "linking failed" << endl;
        printProgramLog(vfProgram);
    }

    return vfProgram;
}


void init (GLFWwindow* ventana) {
    renderingProgram = createShaderProgram();
    //PARAMETRO
          glm::vec3 t(1.5);

          //PUNTO P0
          glm::vec3 p0(0.4,0.6,0.0);
          //ECUACIONES
          glm::vec3 p01 = p0 + t* glm::vec3(-0.1,-0.3,0.0); // directriz1 = (-0.3,-0.5,0.0)
          glm::vec3 p02 = p0 + t* glm::vec3(0.3,-0.3,0.0);  // directriz2 = (0.3,-0.3,0.0)
          //COLOR
          glm::vec3 c0(0.5,0.0,0.8);

          //PUNTO P1
          glm::vec3 p1(-0.8,0.6,0.0);
          //ECUACIONES
          glm::vec3 p11 = p1 + t* glm::vec3(0.0,-0.3,0.0); // directriz1 = (0.0,-0.3,0.0)
          glm::vec3 p12 = p1 + t* glm::vec3(0.3,-0.3,0.0);  // directriz2 = (0.3,-0.3,0.0)
          //COLOR
          glm::vec3 c1(0.0,0.5,0.8);

          //PUNTO P2
          glm::vec3 p2(-0.65,-0.2,0.0);
          //ECUACIONES
          glm::vec3 p21 = p2 + t* glm::vec3(-0.15,-0.35,0.0); // directriz1 = (-0.15,-0.35,0.0)
          glm::vec3 p22 = p2 + t* glm::vec3(0.15,-0.35,0.0);  // directriz2 = (0.15,-0.35,0.0)
          //COLOR
          glm::vec3 c2(0.3,0.7,0.0);

          //PUNTO P3
          glm::vec3 p3(0.2,-0.2,0.0);
          glm::vec3 p31 = p3 + t* glm::vec3(0.5,0.0,0.0);  // directriz1 = (0.5,0.0,0.0)
          glm::vec3 p32 = p3 + t* glm::vec3(0.5,-0.35,0.0);  // directriz2 = (0.5,-0.35,0.0)

          glm::vec3 p33 = p3 + t* glm::vec3(0.0,-0.35,0.0);  // directriz3 = (0.0,-0.35,0.0)
          glm::vec3 p34 = p3;
          glm::vec3 p35 = p32;
          //COLOR
          glm::vec3 c3(1.0,0.35,1.0);


          //ARREGLO DE VERTICES
          glm::vec3 m_Vertices [90] = {
              		p0,c0,
          			p01,c0,
          			p02,c0,

      				p1,c1,
      				p11,c1,
      				p12,c1,

      				p2,c2,
      				p21,c2,
      				p22,c2,

      				p3,c3,
      				p31,c3,
      				p32,c3,

      				p33,c3,
      				p34,c3,
      				p35,c3,
          	};



	glGenBuffers(1, &m_VBO);
	glGenVertexArrays(1, &m_VAO);

	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	glBufferData(
			GL_ARRAY_BUFFER,
			90 * sizeof(GLfloat),
			m_Vertices,
			GL_STATIC_DRAW
		);


	glVertexAttribPointer(
			0,
			3,
			GL_FLOAT,
			GL_FALSE,
			6 * sizeof(GLfloat),
			(GLvoid*) 0
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

void display(GLFWwindow* ventana, double currentTime) {
    glUseProgram(renderingProgram);

	glBindVertexArray(m_VAO);
	// PARA DIBUJAR LAS FIGURAS
		int j=-3;
		for(int i=0;i<=4;i++){
			j=j+3;
			glDrawArrays(GL_TRIANGLES,j, 3);

		}

	glBindVertexArray(0);

	glBindVertexArray(0);

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

    GLFWwindow* ventana = glfwCreateWindow(800, 800, "Gomez Cavero Mishell", NULL, NULL);
    glfwMakeContextCurrent(ventana);
    if (glewInit() != GLEW_OK) {
    	exit(EXIT_FAILURE);
    }
    glfwSwapInterval(1);

    init(ventana);

    while (!glfwWindowShouldClose(ventana)) {
        display(ventana, glfwGetTime());
        glfwSwapBuffers(ventana);
        glfwPollEvents();
    }

    glfwDestroyWindow(ventana);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
