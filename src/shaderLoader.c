#include "shaderLoader.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHARBUFSIZE 128
#define CHARBUFMAXIDX (CHARBUFSIZE - 1)

GLchar *loadShader(char *filename){
    GLchar *charBuf = calloc(CHARBUFSIZE,sizeof(GLchar));
    FILE *shader;
    int bufIndex = 0;
    int sourceBufSize = CHARBUFSIZE;
    shader = fopen(filename,"r");
    while(!feof(shader)){    
        charBuf[bufIndex] = (GLchar) fgetc(shader);
        bufIndex += 1;
        if ((bufIndex % CHARBUFMAXIDX) == 0){
            duplicateBuffer(charBuf,sourceBufSize);
            sourceBufSize = sourceBufSize*2;
        }
    }
    fclose(shader);
    return charBuf;
}

void destroyBuffer(GLchar *buffer){
    free(buffer);
}


void duplicateBuffer(GLchar *buffer,int currentSize){
    GLchar *expandedBuffer = calloc(currentSize*2,sizeof(GLchar));
    mempcpy(expandedBuffer,buffer,currentSize);
    destroyBuffer(buffer);
    buffer = expandedBuffer;    
}