all: install

clean:
	$(RM) *~ *.o;

install:
	cp matrix_algorithm.h $(HOME)/include/matrix_algorithm.h

uninstall:
	rm $(HOME)/include/matrix_algorithm.h


