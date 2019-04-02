#include <math.h>
#include <GL/glew.h>
#include <iostream>
#include "mesh.h"
#include "general_declarations.h"

void m_drawCircle(circleStruct inputCircle)
{
    int numberOfVerts = 32;
    const float pi = 3.141592653;

    Vertex vertices[numberOfVerts];

    long double theta = 360/numberOfVerts * pi/180;

    for(int i = 0; i < numberOfVerts; i++) {
        GLdouble rcos = inputCircle.centre.X + (inputCircle.radius * cos(theta * i));
        GLdouble rsin = inputCircle.centre.Y + (inputCircle.radius * sin(theta * i));
        vertices[i] = Vertex(glm::vec3(rcos, rsin, 0));
    }

    //remove for final release
    /*
    for(int i = 0; i < numberOfVerts; i++) {
        vertices[i].print();
    }
    */

    Mesh mesh(vertices, numberOfVerts);

    mesh.draw();
}
