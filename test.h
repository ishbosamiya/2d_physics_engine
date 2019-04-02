#include <math.h>
#include <GL/glew.h>
#include <iostream>
#include "mesh.h"

struct point
{
	float X;
	float Y;
};

struct circleStruct
{
	float radius;
	point centre;
};

void m_drawCircle(circleStruct inputCircle)
{
    int numberOfVerts = 5;
    const float pi = 3.141592653;

    Vertex vertices[] = {Vertex(glm::vec3(-0.5, -0.5, 0)),
                         Vertex(glm::vec3(0, 0.5, 0)),
                         Vertex(glm::vec3(0.5, -0.5, 0)),
                         Vertex(glm::vec3(0.5, -0.5, 0)),
                         Vertex(glm::vec3(0.5, -0.5, 0)),};

    float theta = 360/numberOfVerts * pi/180;

    for(int i = 0; i < numberOfVerts; i++) {
        std::cout << "this is a test 3" << std::endl;
        GLfloat rcos = inputCircle.centre.X + (inputCircle.radius * cos(theta * i));
        GLfloat rsin = inputCircle.centre.Y + (inputCircle.radius * sin(theta * i));
        vertices[i] = Vertex(glm::vec3(rcos, rsin, 0));
    }

    for(int i = 0; i < numberOfVerts; i++) {
        vertices[i].print();
    }

    Mesh mesh(vertices, numberOfVerts);

    mesh.draw();

    /*

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, allCircleVerts);
    glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVerts);
    glDisableClientState(GL_VERTEX_ARRAY);

    */
}

