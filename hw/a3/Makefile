#----------------------------------------------------

SOURCE=FBLUser.h FBLUser.cpp FBLUserNode.h FBLUserNode.cpp FBLUserLL.h FBLUserLL.cpp FBLPost.h FBLPost.cpp FBLPostNode.h FBLPostNode.cpp FBLPostLL.h FBLPostLL.cpp FBLComment.h FBLComment.cpp FBLCommentNode.h FBLCommentNode.cpp FBLCommentLL.h FBLCommentLL.cpp CA3.cpp
OBJECT=FBLUser.o FBLUserNode.o FBLUserLL.o FBLPost.o FBLPostNode.o FBLPostLL.o FBLComment.o FBLCommentNode.o FBLCommentLL.o CA3.cpp
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
	$(CXX) $(CXXFLAGS) FBLComment.cpp
	$(CXX) $(CXXFLAGS) FBLCommentNode.cpp
	$(CXX) $(CXXFLAGS) FBLCommentLL.cpp
	$(CXX) $(CXXFLAGS) CA3.cpp

clean:
	rm -f *.o FBL_Forno.exe

compress: clean
	tar -cvvf Forno_Cristobal_cforno1_CA3-3.tar *.* Makefile
	gzip Forno_Cristobal_cforno1_CA3-3.tar
