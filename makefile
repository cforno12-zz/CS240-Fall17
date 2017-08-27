#
# Specifiy the target
all:	Hello

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Hello:	Hello.o
	g++  Hello.o  -o Hello.exe

# Specify how the object files should be created from source files
Hello.o:	Hello.cpp
	g++ -c Hello.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Hello.exe

