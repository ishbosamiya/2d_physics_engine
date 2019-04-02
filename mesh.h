#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glm/ext.hpp>

class Vertex
{
    public:
        Vertex(const glm::vec3& pos) {
            this->pos = pos;
        }

        Vertex(){
            this->pos = pos;
        }

        void print()
        {
            std::cout<<glm::to_string(pos)<<std::endl;
        }
    protected:
    private:
        glm::vec3 pos;
};

class Mesh
{
    public:
        Mesh(Vertex* vertices, unsigned int numVertices);

        void draw();

        virtual ~Mesh();

    protected:
    private:
        Mesh(const Mesh& other);
        void operator=(const Mesh& other);

        enum
        {
            POSITION_VB,

            NUM_BUFFERS
        };

        GLuint m_vertexArrayObject;
        GLuint m_vertexArrayBuffers[NUM_BUFFERS];
        unsigned int m_drawCount;
};

#endif // MESH_H
