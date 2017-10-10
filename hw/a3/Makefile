#----------------------------------------------------

SOURCE=FBLUser.h FBLUser.cpp FBLUserNode.h FBLUserNode.cpp FBLUserLL.h FBLUserLL.cpp FBLPost.h FBLPost.cpp FBLPostNode.h FBLPostNode.cpp FBLPostLL.h FBLPostLL.cpp CA3.cpp
OBJECT=FBLUser.o FBLUserNode.o FBLUserLL.o FBLPost.o FBLPostNode.o FBLPostLL.o CA3.cpp
CXX:= g++
CXXFLAGS:= -c -Wall -I=.

#----------------------------------------------------

all: link

link: compile $(SOURCE) $(OBJECT)
	g++ -o FBL_Forno.exe $(OBJECT)

compile: $(SOURCE)
	$(CXX) $(CXXFLAGS) FBLUser.cpp
	$(CXX) $(CXXFLAGS) FBLUserNode.cpp
	$(CXX) $(CXXFLAGS) FBLUserLL.cpp
	$(CXX) $(CXXFLAGS) FBLPost.cpp
	$(CXX) $(CXXFLAGS) FBLPostNode.cpp
	$(CXX) $(CXXFLAGS) FBLPostLL.cpp
	$(CXX) $(CXXFLAGS) CA3.cpp

clean:
	rm -f *.o FBL_Forno.exe

compress: clean
	tar -cvvf Forno_Cristobal_cforno1_CA2.tar *.*
	gzip Forno_Cristobal_cforno1_CA2.tar
