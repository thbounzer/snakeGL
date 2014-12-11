#include <GLFW/glfw3.h>
#include <math.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "shaderLoader.h"

int main(void)
{
    char *linuxpath = "/home/carlo/Documents/Sources/Various/snakeGL/vertex.shader";
    char *macosxpath = "/Users/thbounzer/Documents/Sources/c/snakeGL/vertex.shader";
    GLchar *shader = loadShader(macosxpath);
    if (shader){
        puts(shader);
        free(shader);
    }else{
        char *error = strerror(errno);
        puts(error);
    }
}
