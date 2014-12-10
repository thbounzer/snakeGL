#include <GLFW/glfw3.h>
#include <math.h>
#include <stdio.h>
#include "shaderLoader.h"

int main(void)
{
    GLchar *shader = loadShader("/home/carlo/Documents/Sources/Various/snakeGL/shader.txt");
    puts(shader);
    free(shader);    
}