#ifndef INITSHADER_H_
#define INITSHADER_H_

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#endif

struct Shader
{
    const char*  filename;
    GLenum       type;
    GLchar*      source;
};

GLuint initShader(const char* vertexShaderFile, const char* fragmentShaderFile);


#endif
