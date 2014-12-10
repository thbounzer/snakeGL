#include "shaderLoader.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHARBUFSIZE 250

GLchar *loadShader(char *filename){
    GLchar *charBuf = calloc(CHARBUFSIZE,sizeof(GLchar));
    FILE *shader;
    int defSizeIndex = 0;
    int bufIndex = 0;
    int bufMultiplier = 1;
    int sourceBufSize;
    shader = fopen(filename,"r");
    while(!feof(shader)){    
        charBuf[bufIndex] = (GLchar) fgetc(shader);
        defSizeIndex += 1;
        bufIndex += 1;
        if (defSizeIndex == (CHARBUFSIZE-1)){
            sourceBufSize = CHARBUFSIZE*bufMultiplier;
            bufMultiplier += 1;
            defSizeIndex = 0;
            GLchar *expandedBuffer = calloc(CHARBUFSIZE*bufMultiplier,sizeof(GLchar));
            mempcpy(expandedBuffer,charBuf,sourceBufSize);
            destroyBuffer(charBuf);
            charBuf = expandedBuffer;
        }
    }
    return charBuf;
}

void destroyBuffer(GLchar *buffer){
    free(buffer);
}
