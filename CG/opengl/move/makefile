LDFLAGS=-lopengl32 -lglu32 -lglut32
test: test.c
	g++ -g -o test test.c -framework OpenGL -framework GLUT

clean:
	rm *.o test

run:
	./test
