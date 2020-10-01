CXX = g++
FLAGS = -lSDL2 -lGLEW -lGLU -lGL
OBJECTS = main.o display.o mesh.o shader.o

physics_engine: ${OBJECTS}
	${CXX} ${OBJECTS} -o $@ ${FLAGS}
	-rm ${OBJECTS}

main.o:
	${CXX} -c main.cpp -o $@ ${FLAGS}
display.o:
	${CXX} -c display.cpp -o $@ ${FLAGS}
mesh.o:
	${CXX} -c mesh.cpp -o $@ ${FLAGS}
shader.o:
	${CXX} -c shader.cpp -o $@ ${FLAGS}

.PHONEY: clean clean_emacs_files clean_all
clean:
	-rm ${OBJECTS}
clean_emacs_files:
	-rm *~
clean_all: clean clean_emacs_files
	-rm physics_engine
