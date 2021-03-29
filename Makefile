CC=g++
LINKFLAGS=-L. -lrandom
DLLFLAGS=-s -shared -mwindows
DLLLIBS=-lbcrypt

all: test_dll.exe clean

test_dll.exe: test_dll.cpp random.dll
	$(CC) $(LINKFLAGS) -o test_dll.exe -s test_dll.cpp

random.dll: random.o
	$(CC) $(DLLFLAGS) -o random.dll random.o $(DLLLIBS)

random.o: random.cpp
	$(CC) -c random.cpp -o random.o -D ADD_EXPORTS

clean:
	del random.o 