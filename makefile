#
# Created by gmakemake (Ubuntu Jul 25 2014) on Tue Sep 19 18:10:10 2017
#

#
# Definitions
#

.SUFFIXES:
.SUFFIXES:	.a .o .c .C .cpp .s .S
.c.o:
		$(COMPILE.c) $<
.C.o:
		$(COMPILE.cc) $<
.cpp.o:
		$(COMPILE.cc) $<
.S.s:
		$(CPP) -o $*.s $<
.s.o:
		$(COMPILE.cc) $<
.c.a:
		$(COMPILE.c) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.C.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.cpp.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%

CC =		gcc
CXX =		g++

RM = rm -f
AR = ar
LINK.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
LINK.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) -c
CPP = $(CPP) $(CPPFLAGS)
########## Default flags (redefine these with a header.mak file if desired)
CXXFLAGS =	-ggdb -std=c++11 -Wall -Wextra
CFLAGS =	-ggdb
CLIBFLAGS =	-lm
CCLIBFLAGS =	
########## End of default flags

CPP_FILES =	Edge.cpp Maze.cpp MinHeapNode.cpp Minimum_Spanning_Tree.cpp Node.cpp test_edge.cpp test_node.cpp
C_FILES =	
PS_FILES =	
S_FILES =	
H_FILES =	Edge.h Maze.h MinHeapNode.h Node.h
SOURCEFILES =	$(H_FILES) $(CPP_FILES) $(C_FILES) $(S_FILES)
.PRECIOUS:	$(SOURCEFILES)
OBJFILES =	Edge.o Maze.o MinHeapNode.o Node.o 

#
# Main targets
#

all:	Minimum_Spanning_Tree test_edge test_node test_maze

Minimum_Spanning_Tree:	Minimum_Spanning_Tree.o $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o MST Minimum_Spanning_Tree.o $(OBJFILES) $(CCLIBFLAGS)

test_edge:	test_edge.o $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o test_edge test_edge.o $(OBJFILES) $(CCLIBFLAGS)

test_node:	test_node.o $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o test_node test_node.o $(OBJFILES) $(CCLIBFLAGS)

test_maze:	test_maze.o $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o test_maze test_maze.o $(OBJFILES) $(CCLIBFLAGS)


#
# Dependencies
#

Edge.o:	Edge.h
Maze.o:	Edge.h Maze.h Node.h
MinHeapNode.o:	MinHeapNode.h Node.h
Minimum_Spanning_Tree.o:	Edge.h Maze.h MinHeapNode.h Node.h
Node.o:	Node.h
test_edge.o:	Edge.h
test_node.o:	Node.h
test_maze.o:	Maze.h

#
# Housekeeping
#

Archive:	archive.tgz

archive.tgz:	$(SOURCEFILES) Makefile
	tar cf - $(SOURCEFILES) Makefile | gzip > archive.tgz

clean:
	-/bin/rm -f $(OBJFILES) Minimum_Spanning_Tree.o test_edge.o test_node.o test_maze.o

realclean:        clean
	-/bin/rm -f Minimum_Spanning_Tree test_edge test_node 
