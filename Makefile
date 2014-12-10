CC=clang
CFLAGS=-pedantic -std=c11 -Wall -g -O3
GL_LIBS=-L/usr/local/lib -lglfw3 -lrt -lXrandr -lXi -lGL -lm -ldl -lXrender -ldrm -lXdamage -lX11-xcb -lxcb-glx -lxcb-dri2 -lxcb-dri3 -lxcb-present -lxcb-sync -lxshmfence -lXxf86vm -lXfixes -lXext -lX11 -lpthread -lxcb -lXau -lXdmcp  

snakeGL:
	$(CC) $(CFLAGS) -o bin/snakeGL src/snakeGL.c src/shaderLoader.c $(GL_LIBS)
clean:
	rm -rf bin/*

