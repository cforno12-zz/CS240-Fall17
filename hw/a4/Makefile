SOURCE=CA4.cpp DISH.cpp DISH.h string_obj.h string_obj.cpp
OBJECT=DISH.o CA4.o string_obj.o
CXX:= g++
CXXFLAGS:= -c -Wall -I=.

#---------------------------------

all: link

link: compile $(SOURCE) $(OBJECT)
	g++ -o run $(OBJECT)

compile: $(SOURCE)
	$(CXX) $(CXXFLAGS) DISH.cpp
	$(CXX) $(CXXFLAGS) CA4.cpp
	$(CXX) $(CXXFLAGS) string_obj.cpp

clean:
	rm -f *.o run

compress: clean
	tar -cvvf Forno_Cristobal_cforno1_CA4.tar *.* Makefile
	gzip Forno_Cristobal_cforno_CA4.tar
