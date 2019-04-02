#include <math.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
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

Vertex* drawCircle(circleStruct inputCircle)
{
    int numberOfVerts = 32;

/*

    unsigned int indices[] = {0, 1, 2};

    float circleVertX[numberOfVerts];
    float circleVertY[numberOfVerts];
    float circleVertZ[numberOfVerts];

    for(int i = 0; i < numberOfVerts; i++) {
        double rcos = (inputCircle.radius * cos((360/numberOfVerts) * i) ) + inputCircle.centre.X;
        double rsin = (inputCircle.radius * sin((360/numberOfVerts) * i) ) + inputCircle.centre.Y;

        //Setting position of each vertex
        circleVertX[i] = rcos;
        circleVertY[i] = rsin;
        circleVertZ[i] = 0;
    }

    float allCircleVerts[numberOfVerts * 3];

    for(int i = 0; i < numberOfVerts; i++) {
        allCircleVerts[i * 3] = circleVertX[i];
        allCircleVerts[(i * 3) + 1] = circleVertY[i];
        allCircleVerts[(i * 3) + 2] = circleVertZ[i];
    }
*/
    Vertex circleVert[] = {Vertex(glm::vec3(-0.5, -0.5, 0))};

    for(int i = 0; i < numberOfVerts; i++) {
        double rcos = (inputCircle.radius * cos((360/numberOfVerts) * i) ) + inputCircle.centre.X;
        double rsin = (inputCircle.radius * sin((360/numberOfVerts) * i) ) + inputCircle.centre.Y;

        circleVert[i] = glm::vec3(rcos, rsin, 0);

        //Setting position of each vertex
        //circleVertX[i] = rcos;
        //circleVertY[i] = rsin;
        //circleVertZ[i] = 0;
    }

    return circleVert;

    //return allCircleVerts;
}

/*
    float color_buffer_data[numberOfVerts * 3];

    for(int i = 0; i < numberOfVerts; i++) {
        color_buffer_data[i * 3] = 1.0f;
        color_buffer_data[(i * 3) + 1] = 1.0f;
        color_buffer_data[(i * 3) + 2] = 1.0f;
    }

    GLuint colorbuffer;
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data), color_buffer_data, GL_STATIC_DRAW);


    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, allCircleVerts);
    glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVerts);
    glDisableClientState(GL_VERTEX_ARRAY);
*/

