#
# Specifiy the target
all:	Hello

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Hello:	Forno_Cristobal_cforno1_Hello.o Hello_Class.o
	g++  Forno_Cristobal_cforno1_Hello.o Hello_Class.o  -o Forno_Cristobal_cforno1_Hello.exe

# Specify how the object files should be created from source files
Forno_Cristobal_cforno1_Hello.o:	Forno_Cristobal_cforno1_Hello.cpp Hello_Class.cpp
	g++ -c Hello_Class.cpp
	g++ -c Forno_Cristobal_cforno1_Hello.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Forno_Cristobal_cforno1_Hello.exe

