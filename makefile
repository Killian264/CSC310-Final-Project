INCLUDE_DIRS := ./
CC := g++
CFLAGS := -I$(INCLUDE_DIRS)

excBinaryFile: main.o binaryFile.o customErrorClass.o
	$(CC) -o excBinaryFile main.o binaryFile.o customErrorClass.o  $(CFLAGS)

binaryFile.o: binaryFile.cpp binaryFile.h
	$(CC) -c -o binaryFile.o binaryFile.cpp $(CFLAGS)

customErrorClass.o: customErrorClass.cpp customErrorClass.h
	$(CC) -c -o customErrorClass.o customErrorClass.cpp $(CFLAGS)

.PHONY: clean

clean:
		rm *.o excBinaryFile
